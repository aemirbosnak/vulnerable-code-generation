//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define MAX_LINE 100

// Function to handle socket connection with IMAP server
int handle_socket_connection(char *hostname, char *port) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Creating socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Setting up server details for connection
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(port));
    if (inet_pton(AF_INET, hostname, &servaddr.sin_addr) <= 0) {
        perror("Error: Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connecting to IMAP server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("Error: Could not connect with server");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send commands to IMAP server
void send_command(int sockfd, char *command) {
    char buffer[BUFFER_SIZE];

    // Sending command to server
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("Error: Command could not be sent");
        exit(EXIT_FAILURE);
    }

    // Receiving response from server
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error: Response could not be received from server");
        exit(EXIT_FAILURE);
    }

    // Printing server response
    printf("Server Response: %s", buffer);
}

// Function to handle IMAP client connection with server
void handle_imap_client_connection(int sockfd) {
    char buffer[BUFFER_SIZE], command[MAX_LINE];

    // Receiving server banner
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error: Response could not be received from server");
        exit(EXIT_FAILURE);
    }

    // Printing server banner
    printf("%s", buffer);

    // Sending user name to server
    printf("Enter user name: ");
    fflush(stdout);
    memset(command, 0, MAX_LINE);
    fgets(command, MAX_LINE, stdin);
    sprintf(buffer, "1 LOGIN %s", command);
    send_command(sockfd, buffer);

    // Sending password to server
    printf("Enter password: ");
    fflush(stdout);
    memset(command, 0, MAX_LINE);
    fgets(command, MAX_LINE, stdin);
    sprintf(buffer, "2 LOGIN %s", command);
    send_command(sockfd, buffer);

    // Exiting connection with server
    sprintf(buffer, "3 LOGOUT");
    send_command(sockfd, buffer);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: imap_client <hostname> <port>");
        exit(EXIT_SUCCESS);
    }

    char *hostname = argv[1];
    char *port = argv[2];

    int sockfd = handle_socket_connection(hostname, port);

    handle_imap_client_connection(sockfd);

    close(sockfd);

    return EXIT_SUCCESS;
}