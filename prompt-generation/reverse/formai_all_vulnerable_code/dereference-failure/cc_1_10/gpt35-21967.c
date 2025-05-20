//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Romeo and Juliet
/* Romeo and Juliet: A Tale of IMAP Client and Server Communication */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    // Check if the user has provided the necessary command-line arguments
    if (argc != 3) {
        printf("Usage: %s <server_address> <port_number>\n", argv[0]);
        exit(1);
    }

    // Create a TCP socket for communicating with the IMAP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Failed to create socket");
        exit(1);
    }

    // Retrieve the server's IP address from its domain name
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: Failed to retrieve server's IP address\n");
        exit(1);
    }

    // Initialize the server's socket address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = *(unsigned long *) server->h_addr;
    serv_addr.sin_port = htons(atoi(argv[2])) ;

    // Connect to the IMAP server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: Failed to connect to the server");
        exit(1);
    }

    // Send a message to the server to initiate the conversation
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    strcpy(buffer, "HELLO SERVER\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive the server's response and print it to the console
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Juliet: %s", buffer);

    // Initiate the conversation with the server by sending a message
    memset(buffer, 0, BUFFER_SIZE);
    printf("Romeo: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive the server's response and print it to the console
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Juliet: %s", buffer);

    // Close the socket and terminate the program
    close(sockfd);
    return 0;
}