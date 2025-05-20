//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Function to receive data from the server
char* receive_data(int socket) {
    char* buffer = malloc(1024);
    recv(socket, buffer, 1024, 0);
    return buffer;
}

// Function to send data to the server
void send_data(int socket, char* message) {
    send(socket, message, strlen(message), 0);
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char* username = "example@gmail.com";
    char* password = "password";
    char* buffer;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Set server address and port
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("pop.gmail.com");
    servaddr.sin_port = htons(995);

    // Connect to server
    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // Receive welcome message
    buffer = receive_data(sockfd);
    printf("%s\n",buffer);

    // Send username and receive response
    send_data(sockfd, "USER ");
    send_data(sockfd, username);
    send_data(sockfd, "\r\n");
    buffer = receive_data(sockfd);
    printf("%s\n",buffer);

    // Send password and receive response
    send_data(sockfd, "PASS ");
    send_data(sockfd, password);
    send_data(sockfd, "\r\n");
    buffer = receive_data(sockfd);
    printf("%s\n",buffer);

    // Send command to list all emails and receive response
    send_data(sockfd, "LIST\r\n");
    buffer = receive_data(sockfd);
    printf("%s\n",buffer);

    // Send command to quit and receive response
    send_data(sockfd, "QUIT\r\n");
    buffer = receive_data(sockfd);
    printf("%s\n",buffer);

    // Close socket
    close(sockfd);

    return 0;
}