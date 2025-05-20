//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Recursive function to send a message to a server and receive the response
void send_receive(int sockfd, char* message, int size) {
    // Send the message to the server
    if (send(sockfd, message, size, 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive the response from the server
    char buffer[1024];
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        exit(1);
    }

    // Print the response from the server
    printf("%s\n", buffer);

    // If the response is not "quit", send another message to the server
    if (strcmp(buffer, "quit") != 0) {
        char* new_message = malloc(sizeof(char) * (size + 1));
        strcpy(new_message, message);
        strcat(new_message, "!");
        send_receive(sockfd, new_message, size + 1);
        free(new_message);
    }
}

// Main function
int main(int argc, char** argv) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to the server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[1]));
    serv_addr.sin_addr.s_addr = inet_addr(argv[2]);
    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send a message to the server
    char* message = "Hello, world!";
    send_receive(sockfd, message, strlen(message) + 1);

    // Close the socket
    close(sockfd);

    return 0;
}