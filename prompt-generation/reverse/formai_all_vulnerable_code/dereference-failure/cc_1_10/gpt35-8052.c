//FormAI DATASET v1.0 Category: Networking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[1024];

    if (argc != 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        return 0;
    }

    // Creating a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Configuring server details
    memset(&servaddr, '\0', sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    // Making a connection
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("Connection to server failed");
        return -1;
    }

    printf("Welcome to the Chatroom! Type \"bye\" to exit.\n");

    while (1) {
        printf("You: ");
        scanf("%[^\n]%*c", buffer);

        if (strlen(buffer) > 0) {
            // Sending data to the server
            send(sockfd, buffer, strlen(buffer), 0);

            // If user types "bye", terminate the program
            if (strcmp(buffer, "bye") == 0) {
                printf("Server: Goodbye!\n");
                break;
            }

            // Receiving response from server
            memset(buffer, '\0', sizeof(buffer));
            recv(sockfd, buffer, sizeof(buffer), 0);
            printf("Server: %s\n", buffer);
        }
    }

    // Closing the socket
    close(sockfd);

    return 0;
}