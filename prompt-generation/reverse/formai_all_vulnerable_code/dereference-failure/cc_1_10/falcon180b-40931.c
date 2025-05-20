//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_HOST_NAME_LEN 256
#define MAX_QOS_DATA_LEN 1024
#define QOS_DATA_INTERVAL 5 //seconds

struct hostent *get_host_by_name(char *hostname);
int create_socket(char *hostname, int port);
void *monitor_qos(void *args);

int main(int argc, char *argv[]) {
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    int sock = create_socket(hostname, port);

    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, monitor_qos, (void *)sock);

    while (1) {
        sleep(10);
    }

    return 0;
}

struct hostent *get_host_by_name(char *hostname) {
    struct hostent *host = gethostbyname(hostname);

    if (host == NULL) {
        printf("Error resolving hostname\n");
        return NULL;
    }

    return host;
}

int create_socket(char *hostname, int port) {
    struct hostent *host = get_host_by_name(hostname);

    if (host == NULL) {
        return -1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = *(unsigned long *)host->h_addr;

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return -1;
    }

    return sock;
}

void *monitor_qos(void *args) {
    int sock = *(int *)args;

    char buffer[MAX_QOS_DATA_LEN];
    while (1) {
        memset(buffer, 0, MAX_QOS_DATA_LEN);
        int bytes_received = recv(sock, buffer, MAX_QOS_DATA_LEN, 0);

        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            break;
        }

        printf("Received data: %s\n", buffer);
    }

    close(sock);
    return NULL;
}