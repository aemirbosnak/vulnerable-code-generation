//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // Connect to the POP3 server
    int sockfd, connfd;
    struct sockaddr_in server;
    struct hostent *serverhost;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        return 1;
    }

    // Connect to the server
    serverhost = gethostbyname("pop3.example.com");
    server.sin_family = AF_INET;
    server.sin_port = htons(110);
    server.sin_addr = *((struct in_addr *)serverhost->h_addr);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connection failed");
        return 1;
    }

    // Send the username and password
    char username[50];
    char password[50];
    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);

    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    // Receive the welcome message
    char welcome_msg[256];
    if (recv(sockfd, welcome_msg, sizeof(welcome_msg), 0) < 0) {
        perror("recv failed");
        return 1;
    }

    // Print the welcome message
    printf("Welcome, %s!\n", welcome_msg);

    // Select the messages to download
    char msg_ids[256];
    send(sockfd, "LIST\r\n", 8, 0);
    if (recv(sockfd, msg_ids, sizeof(msg_ids), 0) < 0) {
        perror("recv failed");
        return 1;
    }

    // Print the list of messages
    printf("List of messages:\n");
    for (int i = 0; i < strlen(msg_ids); i++) {
        printf(" - %s\n", msg_ids + i);
    }

    // Select and download the messages
    char msg_text[256];
    send(sockfd, "RETR 1\r\n", 9, 0);
    if (recv(sockfd, msg_text, sizeof(msg_text), 0) < 0) {
        perror("recv failed");
        return 1;
    }

    // Print the downloaded message
    printf("Message 1:\n%s", msg_text);

    // Close the connection
    close(sockfd);

    return 0;
}