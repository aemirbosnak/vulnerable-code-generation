//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

// Function to print error message and exit the program
void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *port = argv[2];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Get the host information using getaddrinfo()
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(hostname, port, &hints, &res) != 0) {
        error("ERROR getting host information");
    }

    // Connect to the server
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) != 0) {
        error("ERROR connecting to server");
    }

    // Send the USER command
    char send_buffer[BUFFER_SIZE];
    memset(send_buffer, 0, BUFFER_SIZE);
    printf("Enter username: ");
    fgets(send_buffer, BUFFER_SIZE, stdin);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    // Wait for the response
    char recv_buffer[BUFFER_SIZE];
    memset(recv_buffer, 0, BUFFER_SIZE);
    recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    printf("%s", recv_buffer);

    // Send the PASS command
    memset(send_buffer, 0, BUFFER_SIZE);
    printf("Enter password: ");
    fgets(send_buffer, BUFFER_SIZE, stdin);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    // Wait for the response
    memset(recv_buffer, 0, BUFFER_SIZE);
    recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    printf("%s", recv_buffer);

    // Send the LIST command
    memset(send_buffer, 0, BUFFER_SIZE);
    strcpy(send_buffer, "LIST\r\n");
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    // Wait for the response
    memset(recv_buffer, 0, BUFFER_SIZE);
    recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    printf("%s", recv_buffer);

    // Read the messages from the server
    bool end_of_message;
    do {
        memset(recv_buffer, 0, BUFFER_SIZE);
        recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
        printf("%s", recv_buffer);
        end_of_message = (strstr(recv_buffer, ".\r\n") != NULL);   // check if end of message
    } while (!end_of_message);

    // Send the QUIT command
    memset(send_buffer, 0, BUFFER_SIZE);
    strcpy(send_buffer, "QUIT\r\n");
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    // Wait for the response
    memset(recv_buffer, 0, BUFFER_SIZE);
    recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    printf("%s", recv_buffer);

    // Close the socket
    close(sockfd);

    return 0;
}