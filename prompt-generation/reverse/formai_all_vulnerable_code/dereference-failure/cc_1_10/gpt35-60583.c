//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: mathematical
// Welcome to my POP3 Client program, written in a mathematical style!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    // Declare variables
    int socket_fd, port_num, n;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[BUF_SIZE], username[BUF_SIZE], password[BUF_SIZE], response[BUF_SIZE];

    // Check for correct command line arguments
    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // Get socket file descriptor
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Check for error in creating socket
    if (socket_fd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Get server information
    server = gethostbyname(argv[1]);

    // Check for error in getting host by name
    if (server == NULL) {
        fprintf(stderr,"Error: no such host: %s\n", argv[1]);
        exit(1);
    }

    // Set server address
    bzero((char *) &server_addr, sizeof(server_addr));
    port_num = atoi(argv[2]);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_num);
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);

    // Connect to server
    if (connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Receive server response and print it
    bzero(buffer, BUF_SIZE);
    recv(socket_fd, buffer, BUF_SIZE, 0);
    printf("%s\n", buffer);

    // Send username to server
    printf("Username: ");
    fgets(username, BUF_SIZE, stdin);
    sprintf(buffer, "USER %s", username);
    send(socket_fd, buffer, strlen(buffer), 0);

    // Receive server response and print it
    bzero(buffer, BUF_SIZE);
    recv(socket_fd, buffer, BUF_SIZE, 0);
    printf("%s\n", buffer);

    // Send password to server
    printf("Password: ");
    fgets(password, BUF_SIZE, stdin);
    sprintf(buffer, "PASS %s", password);
    send(socket_fd, buffer, strlen(buffer), 0);

    // Receive server response and print it
    bzero(buffer, BUF_SIZE);
    recv(socket_fd, buffer, BUF_SIZE, 0);
    printf("%s\n", buffer);

    // Send command to retrieve message count
    sprintf(buffer, "STAT");
    send(socket_fd, buffer, strlen(buffer), 0);

    // Receive server response and print it
    bzero(buffer, BUF_SIZE);
    recv(socket_fd, buffer, BUF_SIZE, 0);
    printf("%s\n", buffer);

    // Send command to retrieve message list
    sprintf(buffer, "LIST");
    send(socket_fd, buffer, strlen(buffer), 0);

    // Receive server response and print it
    bzero(buffer, BUF_SIZE);
    recv(socket_fd, buffer, BUF_SIZE, 0);
    printf("%s\n", buffer);

    // Send command to retrieve a specific message
    printf("Enter message number to retrieve: ");
    fgets(response, BUF_SIZE, stdin);
    sprintf(buffer, "RETR %s", response);
    send(socket_fd, buffer, strlen(buffer), 0);

    // Receive server response and print it
    bzero(buffer, BUF_SIZE);
    recv(socket_fd, buffer, BUF_SIZE, 0);
    printf("%s\n", buffer);

    // Close socket
    close(socket_fd);

    // Exit program
    return 0;
}