//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOST_LEN 64
#define MAX_DATA_LEN 64
#define MAX_TRIES 5
#define TIMEOUT_MS 500

struct hostent *gethostbyname(const char *name);

int main(int argc, char *argv[]) {
    char hostname[MAX_HOST_LEN];
    char data[MAX_DATA_LEN];
    int sockfd, retval, i;
    struct sockaddr_in server_addr;
    struct hostent *server;

    if (argc!= 3) {
        printf("Usage:./ping host data\n");
        exit(1);
    }

    strcpy(hostname, argv[1]);
    strcpy(data, argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: socket creation failed\n");
        exit(1);
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error: host not found\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

    retval = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (retval == -1) {
        printf("Error: connection failed\n");
        exit(1);
    }

    for (i = 0; i < MAX_TRIES; i++) {
        send(sockfd, data, strlen(data), 0);
        retval = recv(sockfd, data, MAX_DATA_LEN, 0);
        if (retval <= 0) {
            printf("Error: ping failed (try %d)\n", i+1);
            close(sockfd);
            exit(1);
        }
        printf("Ping successful (try %d)\n", i+1);
        usleep(TIMEOUT_MS*1000);
    }

    close(sockfd);

    return 0;
}