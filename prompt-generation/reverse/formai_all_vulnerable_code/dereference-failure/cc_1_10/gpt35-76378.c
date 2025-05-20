//FormAI DATASET v1.0 Category: Client Server Application ; Style: careful
// Code for a simple echo client and server
// The client sends a message to the server,
//  which echoes it back to the client

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 512

// error handling function, to print error messages and exit program
void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    // check if user provided command line arguments
    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // fill in server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0)
        error("ERROR invalid address");

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    // read message from user
    printf("Please enter the message: ");
    bzero(buffer, BUFFER_SIZE);
    fgets(buffer, BUFFER_SIZE-1, stdin);

    // send message to server
    int n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    // receive message from server
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0)
        error("ERROR reading from socket");

    // print server's response
    printf("Server replied: %s\n", buffer);

    // close socket
    close(sockfd);

    return 0;
}