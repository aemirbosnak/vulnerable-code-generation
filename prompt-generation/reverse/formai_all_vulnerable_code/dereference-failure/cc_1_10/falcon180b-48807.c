//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define MAX_HOSTS 10

typedef struct {
    char *hostname;
    int sock;
} host_t;

void ping_host(host_t *host) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    struct timeval timeout = {.tv_sec = 2,.tv_usec = 0 };

    setsockopt(host->sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
    setsockopt(host->sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    send(host->sock, "PING", strlen("PING"), 0);

    bytes_received = recv(host->sock, buffer, BUFFER_SIZE, 0);

    if (bytes_received < 0) {
        printf("Host %s is down\n", host->hostname);
    } else {
        buffer[bytes_received] = '\0';
        printf("Host %s is up\n", host->hostname);
    }

    close(host->sock);
}

int main() {
    int i;
    struct addrinfo hints, *res;
    host_t hosts[MAX_HOSTS];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    for (i = 0; i < MAX_HOSTS; i++) {
        printf("Enter hostname %d: ", i + 1);
        scanf("%s", hosts[i].hostname);

        if (getaddrinfo(hosts[i].hostname, NULL, &hints, &res)!= 0) {
            printf("Invalid hostname\n");
            return 1;
        }

        hosts[i].sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

        if (hosts[i].sock == -1) {
            printf("Could not create socket\n");
            return 1;
        }
    }

    for (i = 0; i < MAX_HOSTS; i++) {
        ping_host(&hosts[i]);
    }

    return 0;
}