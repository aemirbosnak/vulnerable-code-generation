//FormAI DATASET v1.0 Category: Networking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server-ip> <port>\n", argv[0]);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Could not create socket\n");
        exit(1);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) != 0) {
        printf("Could not connect to server\n");
        exit(1);
    }

    char message[BUFFER_SIZE];
    while (1) {
        memset(message, 0, BUFFER_SIZE);

        printf("Enter message: ");
        fflush(stdout);

        if (fgets(message, BUFFER_SIZE, stdin) == NULL) {
            printf("Could not read input\n");
            break;
        }

        message[strcspn(message, "\n")] = '\0';

        if (strlen(message) == 0) {
            printf("Input cannot be empty\n");
            continue;
        }

        if (send(sockfd, message, strlen(message), 0) == -1) {
            printf("Could not send message\n");
            break;
        }

        if (recv(sockfd, message, BUFFER_SIZE, 0) == -1) {
            printf("Could not receive message\n");
            break;
        }

        printf("Server replied: %s\n", message);
    }

    close(sockfd);

    return 0;
}