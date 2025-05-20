//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct sockaddr_in server_addr;
    struct timeval timeout;
    char buffer[1025];
    int buffer_size = 1024;
    char *message = "PING\n";
    int message_size = strlen(message);

    if (argc!= 3) {
        printf("Usage:./ping <IP address> <port number>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(atoi(argv[2]));

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    while (1) {
        ret = send(sockfd, message, message_size, 0);
        if (ret == -1) {
            printf("Error sending message\n");
            exit(1);
        }

        ret = recv(sockfd, buffer, buffer_size, 0);
        if (ret == -1) {
            printf("Error receiving message\n");
            exit(1);
        }

        if (ret == 0) {
            printf("Connection closed\n");
            exit(1);
        }

        printf("Received message: %s", buffer);
    }

    close(sockfd);
    exit(0);
}