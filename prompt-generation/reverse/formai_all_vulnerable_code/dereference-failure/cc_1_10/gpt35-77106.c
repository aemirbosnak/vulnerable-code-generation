//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

void handle_response(char *response) {
    printf("Server response: %s\n", response);
}

int main(int argc, char* argv[]) {
    char* server_address = "mail.example.com";
    int server_port = 143;
    struct sockaddr_in server_addr;
    struct hostent *server_host;
    int sockfd;

    printf("Connecting to %s:%d...\n", server_address, server_port);

    /* Open the TCP socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    /* Resolve the server address */
    server_host = gethostbyname(server_address);
    if(server_host == NULL) {
        fprintf(stderr, "Error resolving server address\n");
        exit(EXIT_FAILURE);
    }

    /* Fill in the server address structure */
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    memcpy(&server_addr.sin_addr, server_host->h_addr, server_host->h_length);

    /* Connect to the server */
    if(connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server!\n");

    /* Send the login command */
    char command[1024], response[1024];
    snprintf(command, sizeof(command), "LOGIN %s %s\r\n", "username", "password");
    printf("Sending command: %s", command);
    write(sockfd, command, strlen(command));

    /* Wait for response */
    memset(response, 0, sizeof(response));
    read(sockfd, response, sizeof(response));
    handle_response(response);
    
    /* Send the list command */
    snprintf(command, sizeof(command), "LIST\r\n");
    printf("Sending command: %s", command);
    write(sockfd, command, strlen(command));

    /* Wait for response */
    memset(response, 0, sizeof(response));
    read(sockfd, response, sizeof(response));
    handle_response(response);

    /* Close the socket */
    close(sockfd);

    return 0;
}