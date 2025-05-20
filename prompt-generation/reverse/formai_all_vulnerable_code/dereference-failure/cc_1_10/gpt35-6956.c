//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 110 // Port used by POP3 server

void receive(int sockfd, char *response, int size) {
    memset(response, 0, size);
    int bytes_received = recv(sockfd, response, size-1, 0);
    if (bytes_received < 0) {
        perror("Error in receiving data from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error in creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change this IP address to the IP address of the POP3 server

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error in connecting to server");
        exit(EXIT_FAILURE);
    }

    char response[1024];
    receive(sockfd, response, 1024); // Receive server greeting
    printf("Server: %s", response);

    // Send username
    char username[50];
    printf("Enter your username: ");
    fgets(username, 50, stdin);

    char command[50];
    sprintf(command, "USER %s", username);
    send(sockfd, command, strlen(command), 0);
    receive(sockfd, response, 1024);
    printf("Server: %s", response);

    // Send password
    char password[50];
    printf("Enter your password: ");
    fgets(password, 50, stdin);

    sprintf(command, "PASS %s", password);
    send(sockfd, command, strlen(command), 0);
    receive(sockfd, response, 1024);
    printf("Server: %s", response);

    // List messages
    send(sockfd, "LIST", 4, 0);
    receive(sockfd, response, 1024);
    printf("Server: %s", response);

    // Quit
    send(sockfd, "QUIT", 4, 0);
    receive(sockfd, response, 1024);
    printf("Server: %s", response);

    close(sockfd);
    return 0;
}