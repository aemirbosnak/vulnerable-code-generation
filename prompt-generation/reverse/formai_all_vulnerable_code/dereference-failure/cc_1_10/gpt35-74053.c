//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1024

// Function to connect to the POP3 server
int connect_to_pop3_server(char *hostname, int port_number) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname(hostname);

    if (server == NULL) {
        fprintf(stderr, "Error: No such host");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port_number);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    return sockfd;
}

// Function to send a command to the POP3 server
void send_command_to_server(int sockfd, char *command) {
    int n;

    if (write(sockfd, command, strlen(command)) < 0) {
        perror("Error writing to socket");
        exit(1);
    }
}

// Function to receive a response from the POP3 server
char *get_response_from_server(int sockfd) {
    char *buffer = malloc(sizeof(char) * MAX_MESSAGE_LENGTH);
    int n;

    if (buffer == NULL) {
        perror("Error allocating memory for buffer");
        exit(1);
    }

    bzero(buffer, MAX_MESSAGE_LENGTH);

    if (read(sockfd, buffer, MAX_MESSAGE_LENGTH - 1) < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    return buffer;
}

int main(int argc, char *argv[]) {
    int sockfd, port_number;
    char *hostname, *response;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port_number", argv[0]);
        exit(0);
    }

    hostname = argv[1];
    port_number = atoi(argv[2]);

    sockfd = connect_to_pop3_server(hostname, port_number);

    response = get_response_from_server(sockfd);
    printf("%s", response);

    // Send the username and password to the server
    send_command_to_server(sockfd, "USER username\n");
    response = get_response_from_server(sockfd);
    printf("%s", response);

    send_command_to_server(sockfd, "PASS password\n");
    response = get_response_from_server(sockfd);
    printf("%s", response);

    // List all emails
    send_command_to_server(sockfd, "LIST\n");
    response = get_response_from_server(sockfd);
    printf("%s", response);

    // Retrieve the first email
    send_command_to_server(sockfd, "RETR 1\n");
    response = get_response_from_server(sockfd);
    printf("%s", response);

    close(sockfd);
    return 0;
}