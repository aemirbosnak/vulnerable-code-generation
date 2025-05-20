//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {

    // Check arguments 
    if(argc != 4) {
        printf("Usage: %s <Server IP> <Port> <Message>\n", argv[0]);
        return -1;
    }

    char* server_ip = argv[1];
    int port = atoi(argv[2]);
    char* message = argv[3];

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Could not create socket\n");
        return -1;
    }

    // Define server address structure
    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        perror("inet_pton() failed");
        return -1;
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Could not connect to server\n");
        return -1;
    }

    // Send message
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("Could not send message\n");
        return -1;
    }

    printf("Message sent successfully!\n");

    // Close socket
    close(sockfd);

    return 0;
}