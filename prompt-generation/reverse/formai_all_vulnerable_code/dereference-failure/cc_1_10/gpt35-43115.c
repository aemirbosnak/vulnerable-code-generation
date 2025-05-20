//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024

// Function for handling error and exiting
void error(const char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    int sockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUF_SIZE];

    // Creating socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // Resolving server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0)
        error("ERROR invalid server address");

    // Connecting to server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting to server");

    printf("FTP Client Connected to Server Successfully!\n");

    while(1) {
        // Clearing buffer
        bzero(buffer,MAX_BUF_SIZE);

        printf("ftp> ");
        // Taking input command from user
        fgets(buffer,MAX_BUF_SIZE,stdin);

        // Sending command to the server
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0)
            error("ERROR writing to socket");

        // Checking if user input is quit command
        if (strncmp(buffer,"quit",4) == 0)
            break;

        // Clearing buffer
        bzero(buffer,MAX_BUF_SIZE);

        // Receiving response from the server
        n = read(sockfd, buffer, MAX_BUF_SIZE);
        if (n < 0)
            error("ERROR reading from socket");

        printf("%s",buffer);
    }

    // Closing socket
    close(sockfd);
    printf("FTP Client Connection Closed.\n");

    return 0;
}