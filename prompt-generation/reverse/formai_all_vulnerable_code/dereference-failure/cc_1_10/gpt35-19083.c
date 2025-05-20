//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: happy
// This sample program is a happy POP3 client in C language. It uses standard networking libraries to communicate with a POP3 server and retrieve email messages.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 2048

int main() {
    // Declare variables
    char buffer[MAX_BUFFER_SIZE];
    int sock_fd, port_no, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Prompt user for server information
    printf("Enter POP3 server host name: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    strtok(buffer, "\n"); // remove newline character
    server = gethostbyname(buffer);
    
    printf("Enter POP3 server port number: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    port_no = atoi(buffer);

    // Create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Initialize server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr_list[0], (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port_no);

    // Connect to server
    if (connect(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Receive welcome message from server
    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sock_fd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0) {
        perror("Error reading from server");
        exit(1);
    }
    printf("Server message: %s", buffer);

    // Authenticate user
    printf("Enter user name: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    dprintf(sock_fd, "USER %s", buffer);

    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sock_fd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0) {
        perror("Error reading from server");
        exit(1);
    }
    printf("Server message: %s", buffer);

    printf("Enter password: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    dprintf(sock_fd, "PASS %s", buffer);

    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sock_fd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0) {
        perror("Error reading from server");
        exit(1);
    }
    printf("Server message: %s", buffer);

    // Retrieve message list
    dprintf(sock_fd, "LIST");

    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sock_fd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0) {
        perror("Error reading from server");
        exit(1);
    }
    printf("Server message: %s", buffer);

    // Close socket
    close(sock_fd);

    // Exit program
    return 0;
}