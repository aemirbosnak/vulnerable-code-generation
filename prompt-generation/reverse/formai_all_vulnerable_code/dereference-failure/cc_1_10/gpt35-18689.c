//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <pthread.h>

#define DEFAULT_TIMEOUT 5000
#define DEFAULT_INTERVAL 5000
#define MAX_HOSTNAME_LEN 100
#define MAX_IP_LEN INET_ADDRSTRLEN

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
    char hostname[MAX_HOSTNAME_LEN];
    char ip[MAX_IP_LEN];
    int port;
    int timeout;
    int interval;
    float last_rtt;
} Host;

void get_ip(const char *hostname, char *ip) {
    struct addrinfo hints, *res;
    struct sockaddr_in *addr;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo(hostname, NULL, &hints, &res);
    addr = (struct sockaddr_in *) res->ai_addr;
    inet_ntop(AF_INET, &addr->sin_addr, ip, INET_ADDRSTRLEN);

    freeaddrinfo(res);
}

void *monitor(void *args) {
    Host *host = args;
    char response[1024];
    struct timeval start, end;
    struct sockaddr_in server_address;
    fd_set fds;

    while (1) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);

        if (sock < 0) {
            fprintf(stderr, "Error: Failed to create socket\n");
            exit(1);
        }

        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(host->port);
        inet_pton(AF_INET, host->ip, &server_address.sin_addr);

        gettimeofday(&start, NULL);

        if ((connect(sock, (struct sockaddr*) &server_address, sizeof(server_address))) < 0) {
            fprintf(stderr, "Error: Failed to connect to %s\n", host->hostname);
            host->last_rtt = -1.0;
        } else {
            gettimeofday(&end, NULL);
            host->last_rtt = (float) ((end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000.0);
            read(sock, response, 1024);
            close(sock);
        }

        printf("[%s] Response time: %.2f ms\n", host->hostname, host->last_rtt);

        usleep(host->interval * 1000);
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <host 1> [<host 2> ... <host n>]\n", argv[0]);
        return 1;
    }

    int num_hosts = argc - 1;
    Host *hosts = malloc(sizeof(Host) * num_hosts);

    for (int i = 0; i < num_hosts; i++) {
        strcpy(hosts[i].hostname, argv[i+1]);
        hosts[i].timeout = DEFAULT_TIMEOUT;
        hosts[i].interval = DEFAULT_INTERVAL;

        get_ip(hosts[i].hostname, hosts[i].ip);

        pthread_t thread;
        pthread_create(&thread, NULL, monitor, &hosts[i]);
        pthread_detach(thread);
    }

    while (1) {
        printf("Enter \"exit\" to quit or \"set <host> <timeout> <interval>\" to adjust settings\n> ");

        char input[256];
        fgets(input, 256, stdin);
        input[strlen(input)-1] = '\0'; // Remove newline character

        if (strcmp(input, "exit") == 0) {
            break;
        } else if (strncmp(input, "set ", 4) == 0) {
            char *token = strtok(input+4, " ");
            char hostname[MAX_HOSTNAME_LEN];
            float timeout, interval;

            strcpy(hostname, token);
            token = strtok(NULL, " ");
            timeout = atof(token);
            token = strtok(NULL, " ");
            interval = atof(token);

            int idx = -1;
            for (int i = 0; i < num_hosts; i++) {
                if (strcmp(hostname, hosts[i].hostname) == 0) {
                    idx = i;
                    break;
                }
            }

            if (idx != -1) {
                pthread_mutex_lock(&mutex);
                hosts[idx].timeout = timeout;
                hosts[idx].interval = interval;
                pthread_mutex_unlock(&mutex);

                printf("Setting for %s adjusted to timeout=%.2fms, interval=%.2fms\n", hostname, timeout, interval);
            } else {
                printf("Error: host %s not found\n", hostname);
            }
        } else {
            printf("Invalid input\n");
        }
    }

    return 0;
}