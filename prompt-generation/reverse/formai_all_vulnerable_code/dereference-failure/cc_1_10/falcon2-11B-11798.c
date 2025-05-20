//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

// Function to send email
void sendEmail(int sockfd, char* msg) {
    // Send the email message
    int len = strlen(msg);
    send(sockfd, msg, len, 0);
    printf("Email sent\n");
}

// Function to receive email
char* receiveEmail(int sockfd) {
    // Receive the email message
    char buffer[1024];
    int len = recv(sockfd, buffer, sizeof(buffer), 0);
    if (len <= 0) {
        printf("Error receiving email\n");
        return NULL;
    }
    return buffer;
}

// Main function
int main(int argc, char** argv) {
    // Create socket
    int sockfd;
    struct sockaddr_in serv_addr;
    int opt = 1;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Set up server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8888);

    // Bind socket
    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error binding socket\n");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server started\n");

    // Accept incoming connection
    struct sockaddr_in cli_addr;
    socklen_t len = sizeof(cli_addr);
    int cli_fd = accept(sockfd, (struct sockaddr*)&cli_addr, &len);
    if (cli_fd < 0) {
        printf("Error accepting client connection\n");
        return 1;
    }
    printf("Client connected\n");

    // Receive email from client
    char* email = receiveEmail(cli_fd);
    if (email == NULL) {
        printf("Error receiving email\n");
        close(cli_fd);
        return 1;
    }
    printf("Received email:\n%s\n", email);

    // Send email back to client
    sendEmail(cli_fd, email);
    printf("Email sent back to client\n");

    // Close socket
    close(cli_fd);
    close(sockfd);

    return 0;
}