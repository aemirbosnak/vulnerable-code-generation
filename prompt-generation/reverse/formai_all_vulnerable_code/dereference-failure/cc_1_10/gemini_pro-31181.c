//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <pthread.h>

#define MAX_HOSTS 10
#define MAX_RETRIES 3
#define TIMEOUT 1000

struct host_data {
    char hostname[256];
    struct sockaddr_in addr;
    int sockfd;
    int retries;
    time_t last_ping;
    time_t last_response;
};

struct host_data hosts[MAX_HOSTS];
int num_hosts = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void * ping_host(void *arg) {
    struct host_data *host = (struct host_data *)arg;

    while (1) {
        // Check if we need to retry
        if (host->retries > 0) {
            if (time(NULL) - host->last_ping > TIMEOUT) {
                host->retries--;
                host->last_ping = time(NULL);
            } else {
                continue;
            }
        }

        // Create a socket
        host->sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (host->sockfd == -1) {
            perror("socket");
            exit(1);
        }

        // Set a timeout on the socket
        struct timeval tv;
        tv.tv_sec = TIMEOUT / 1000;
        tv.tv_usec = (TIMEOUT % 1000) * 1000;
        if (setsockopt(host->sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv, sizeof(tv)) == -1) {
            perror("setsockopt");
            exit(1);
        }

        // Send a ping request
        char request[1024];
        snprintf(request, sizeof(request), "PING %s", host->hostname);
        if (sendto(host->sockfd, request, strlen(request), 0, (struct sockaddr *)&host->addr, sizeof(host->addr)) == -1) {
            perror("sendto");
            exit(1);
        }

        // Receive a ping response
        char response[1024];
        int len = sizeof(host->addr);
        if (recvfrom(host->sockfd, response, sizeof(response), 0, (struct sockaddr *)&host->addr, &len) <= 0) {
            host->retries++;
            continue;
        }

        // Parse the ping response
        char *start = strstr(response, "PING ");
        if (start == NULL) {
            host->retries++;
            continue;
        }

        char *end = strchr(start, '\n');
        if (end == NULL) {
            host->retries++;
            continue;
        }

        *end = '\0';

        // Update the last response time
        host->last_response = time(NULL);

        // Print the ping response
        printf("%s: %s\n", host->hostname, start);

        // Close the socket
        close(host->sockfd);
    }

    return NULL;
}

int main(int argc, char **argv) {
    // Parse the command line arguments
    if (argc < 2) {
        printf("Usage: %s <hostname> [<hostname> ...]\n", argv[0]);
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        // Resolve the hostname
        struct hostent *hostent = gethostbyname(argv[i]);
        if (hostent == NULL) {
            printf("Error resolving hostname: %s\n", argv[i]);
            continue;
        }

        // Create a host data structure
        struct host_data host;
        strcpy(host.hostname, argv[i]);
        host.addr.sin_family = AF_INET;
        memcpy(&host.addr.sin_addr, hostent->h_addr, hostent->h_length);
        host.addr.sin_port = htons(5001);
        host.sockfd = -1;
        host.retries = MAX_RETRIES;
        host.last_ping = time(NULL);
        host.last_response = 0;

        // Add the host to the list
        hosts[num_hosts++] = host;
    }

    // Create a thread for each host
    pthread_t threads[MAX_HOSTS];
    for (int i = 0; i < num_hosts; i++) {
        if (pthread_create(&threads[i], NULL, ping_host, &hosts[i]) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    // Join the threads
    for (int i = 0; i < num_hosts; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(1);
        }
    }

    return 0;
}