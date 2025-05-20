//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_MSG_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in server_addr;
    char message[MAX_MSG_SIZE];
    char server_response[MAX_MSG_SIZE];
    int n;

    if (argc!= 4) {
        printf("Usage: %s <server_ip> <server_port> <message>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Failed to create socket.\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to server.\n");
        close(sockfd);
        return 1;
    }

    strcpy(message, argv[3]);
    n = send(sockfd, message, strlen(message), 0);
    if (n == -1) {
        printf("Error: Failed to send message.\n");
        close(sockfd);
        return 1;
    }

    n = recv(sockfd, server_response, MAX_MSG_SIZE, 0);
    if (n == -1) {
        printf("Error: Failed to receive response.\n");
        close(sockfd);
        return 1;
    }

    printf("Server response: %s\n", server_response);
    close(sockfd);
    return 0;
}