//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <openssl/ssl.h>

// Define the function for establishing a TCP connection
int establishConnection(char *host, int port) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Initialize socket variables
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Resolve the hostname to an IPv4 address
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    // Assign the IPv4 address to a sockaddr_in structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    // Establish the TCP connection
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    return sockfd;
}

// Define the function for sending IMAP commands
void sendCommand(int sockfd, char *command) {
    int n;

    // Send the IMAP command
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}

// Define the function for receiving IMAP responses
void receiveResponse(int sockfd, char *response) {
    int n;

    // Receive the IMAP response
    n = read(sockfd, response, 2048);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    response[n] = '\0';
}

// Define the main function
int main(int argc, char *argv[]) {
    char *host = argv[1];
    int port = atoi(argv[2]);
    char command[1024];

    // Establish the TCP connection
    int sockfd = establishConnection(host, port);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    // Send the IMAP LOGIN command
    sprintf(command, "LOGIN %s\r\n", "username");
    sendCommand(sockfd, command);

    // Receive the IMAP response
    receiveResponse(sockfd, command);

    // Send the IMAP SELECT command
    sprintf(command, "SELECT INBOX\r\n");
    sendCommand(sockfd, command);

    // Receive the IMAP response
    receiveResponse(sockfd, command);

    // Send the IMAP EXAMINE command
    sprintf(command, "EXAMINE \"%s\"\r\n", "INBOX");
    sendCommand(sockfd, command);

    // Receive the IMAP response
    receiveResponse(sockfd, command);

    // Send the IMAP FETCH command
    sprintf(command, "FETCH 1 BODY[HEADER.FIELDS (FROM TO)]\r\n");
    sendCommand(sockfd, command);

    // Receive the IMAP response
    receiveResponse(sockfd, command);

    close(sockfd);
    return 0;
}