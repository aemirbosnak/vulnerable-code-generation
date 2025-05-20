//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUFSIZE 1024

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char **argv) {
    
    // Check command line arguments
    if(argc != 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int portno = atoi(argv[2]);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        error("ERROR opening socket");
    }

    // Get host info
    struct hostent *server = gethostbyname(hostname);
    if(server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    // Set up socket address
    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    char buffer[BUFSIZE];

    // Send username to server
    printf("Username: ");
    bzero(buffer, BUFSIZE);
    fgets(buffer, BUFSIZE-1, stdin);
    int n = write(sockfd, buffer, strlen(buffer));
    if(n < 0) {
        error("ERROR writing to socket");
    }

    // Receive response from server
    bzero(buffer, BUFSIZE);
    n = read(sockfd, buffer, BUFSIZE-1);
    if(n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // Send password to server
    printf("Password: ");
    bzero(buffer, BUFSIZE);
    fgets(buffer, BUFSIZE-1, stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if(n < 0) {
        error("ERROR writing to socket");
    }

    // Receive response from server
    bzero(buffer, BUFSIZE);
    n = read(sockfd, buffer, BUFSIZE-1);
    if(n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // Send command to server
    printf("FTP> ");
    bzero(buffer, BUFSIZE);
    fgets(buffer, BUFSIZE-1, stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if(n < 0) {
        error("ERROR writing to socket");
    }

    // Receive response from server
    bzero(buffer, BUFSIZE);
    n = read(sockfd, buffer, BUFSIZE-1);
    if(n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}