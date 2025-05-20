//FormAI DATASET v1.0 Category: Client Server Application ; Style: Sherlock Holmes
/* 
   "The Adventure of the Missing Client"
   
   This is a C Client-Server program that simulates a game where a server sends a clue to the client based on 
   a story provided by the client. The story is based on Sherlock Holmes Style.
   
   Code by: Sherlock Holmes
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 256

void error(const char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];

    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    // Game Starts Here
    printf("Welcome to Sherlock Holmes-Inspired Game\n");
    printf("Enter Your Name: ");
    bzero(buffer, BUFFER_SIZE);
    fgets(buffer, BUFFER_SIZE-1, stdin);

    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        error("ERROR writing to socket");
    }

    printf("Enter the story of the Missing Client to get started\n");
    bzero(buffer, BUFFER_SIZE);
    fgets(buffer, BUFFER_SIZE-1, stdin);

    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Get Clue from Server
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);

    if (n < 0) {
       error("ERROR reading from socket");
    }

    printf("Here is the clue for you, %s \n", buffer);

    close(sockfd);
    return 0;
}