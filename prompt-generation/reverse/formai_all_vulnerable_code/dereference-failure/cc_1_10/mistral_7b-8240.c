//MISTRAL-7B DATASET v1.0 Category: Networking ; Style: relaxed
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void error_handling(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char message[BUFFER_SIZE];
    char recv_buf[BUFFER_SIZE];

    if (argc != 3) {
        printf("Usage : %s <IP_ADDRESS> <PORT>\n", argv[0]);
        exit(1);
    }

    // Initialize socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error_handling("Error opening socket");
    }

    // Prepare the sockaddr_in structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error_handling("Error connecting to the server");
    }

    // Send a message to the server
    printf("Enter a message to send to the server : ");
    fgets(message, BUFFER_SIZE, stdin);
    if (send(sockfd, message, strlen(message), 0) < 0) {
        error_handling("Error sending message to the server");
    }

    // Receive a response from the server
    int received_bytes = recv(sockfd, recv_buf, BUFFER_SIZE, 0);
    if (received_bytes < 0) {
        error_handling("Error receiving message from the server");
    }

    // Print the response from the server
    printf("Server response : %s", recv_buf);

    // Close the socket and exit
    close(sockfd);
    return 0;
}