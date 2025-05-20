//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

    int sock;
    struct sockaddr_in server_addr;
    char from[BUF_SIZE], to[BUF_SIZE], user[BUF_SIZE], pass[BUF_SIZE];
    char buffer[BUF_SIZE];
    char *response;
    int bytes, i;

    // Check for correct number of arguments
    if (argc != 3) {
        printf("Usage: %s server_address port_number\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Get welcome message
    response = (char*) malloc(BUF_SIZE*sizeof(char));
    bytes = recv(sock, response, BUF_SIZE, 0);
    if (bytes == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);
    free(response);

    // Send user command
    printf("Username: ");
    scanf("%s", user);
    write(sock, "USER ", 5);
    write(sock, user, strlen(user));
    write(sock, "\r\n", 2);

    // Get response to user command
    response = (char*) malloc(BUF_SIZE*sizeof(char));
    bytes = recv(sock, response, BUF_SIZE, 0);
    if (bytes == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);
    free(response);

    // Send pass command
    printf("Password: ");
    scanf("%s", pass);
    write(sock, "PASS ", 5);
    write(sock, pass, strlen(pass));
    write(sock, "\r\n", 2);

    // Get response to pass command
    response = (char*) malloc(BUF_SIZE*sizeof(char));
    bytes = recv(sock, response, BUF_SIZE, 0);
    if (bytes == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);
    free(response);

    // Send stat command
    write(sock, "STAT\r\n", 6);

    // Get response to stat command
    response = (char*) malloc(BUF_SIZE*sizeof(char));
    bytes = recv(sock, response, BUF_SIZE, 0);
    if (bytes == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);
    free(response);

    // Send list command
    write(sock, "LIST\r\n", 6);

    // Get response to list command
    response = (char*) malloc(BUF_SIZE*sizeof(char));
    bytes = recv(sock, response, BUF_SIZE, 0);
    if (bytes == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);
    free(response);

    // Send retr command
    printf("Which email would you like to read? ");
    scanf("%d", &i);
    sprintf(buffer, "RETR %d\r\n", i);
    write(sock, buffer, strlen(buffer));

    // Get response to retr command
    response = (char*) malloc(BUF_SIZE*sizeof(char));
    bytes = recv(sock, response, BUF_SIZE, 0);
    if (bytes == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    // Quit session
    write(sock, "QUIT\r\n", 6);

    // Close socket
    close(sock);

    return 0;
}