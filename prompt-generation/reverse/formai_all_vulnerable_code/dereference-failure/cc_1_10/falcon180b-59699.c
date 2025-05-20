//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME];
    strcpy(hostname, argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        printf("Invalid hostname\n");
        close(sockfd);
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to host\n");
        close(sockfd);
        return 1;
    }

    char data[MAX_DATA];
    memset(data, 0, sizeof(data));
    strcat(data, "PING\r\n");

    send(sockfd, data, strlen(data), 0);

    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(sockfd, &read_fds);

    int retval = select(sockfd + 1, &read_fds, NULL, NULL, &timeout);

    if (retval == 0) {
        printf("Timeout\n");
    } else if (retval == -1) {
        printf("Error with select\n");
    } else {
        char response[MAX_DATA];
        memset(response, 0, sizeof(response));

        int bytes_received = recv(sockfd, response, sizeof(response), 0);
        if (bytes_received <= 0) {
            printf("Error receiving response\n");
        } else {
            printf("Response: %s\n", response);
        }
    }

    close(sockfd);
    return 0;
}