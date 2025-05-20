//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

// Function declarations
void error(const char *msg);
void receive(int sockfd, char* response, int size);

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[1024], response[4096];

    // Check for command line arguments
    if (argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }

    // Get port number from command line arguments
    portno = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Check if socket was created successfully
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Get server from command line arguments
    server = gethostbyname(argv[1]);

    // Check if server was found
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    // Set values in server address structure
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    // Receive welcome message from server
    receive(sockfd, response, sizeof(response));
    printf("%s\n", response);

    // Send USER command to server
    printf("User: ");
    scanf("%s", buffer);
    sprintf(buffer, "USER %s\r\n", buffer);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Receive response from server
    receive(sockfd, response, sizeof(response));
    printf("%s\n", response);

    // Send PASS command to server
    printf("Password: ");
    scanf("%s", buffer);
    sprintf(buffer, "PASS %s\r\n", buffer);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Receive response from server
    receive(sockfd, response, sizeof(response));
    printf("%s\n", response);

    // Send LIST command to server
    n = write(sockfd, "LIST\r\n", strlen("LIST\r\n"));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Receive response from server
    receive(sockfd, response, sizeof(response));
    printf("%s\n", response);

    // Send QUIT command to server
    n = write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Close socket
    close(sockfd);

    return 0;
}

// Function to print error message and exit program
void error(const char *msg) {
    perror(msg);
    exit(0);
}

// Function to receive data from the server
void receive(int sockfd, char* response, int size) {
    int n, total = 0;

    // Receive data until end of line is reached
    while (strstr(response, "\r\n") == NULL) {
        n = read(sockfd, response + total, size - total - 1);
        if (n < 0) {
            error("ERROR reading from socket");
        }
        total += n;
    }

    // Ensure response is null terminated
    response[total] = '\0';
}