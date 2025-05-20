//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_RESPONSE_SIZE 4096

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){
    int sockfd, portno, n;
    char buffer[MAX_RESPONSE_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    printf("Connected to server. Retrieving messages...\n");

    // Send user info and get response
    bzero(buffer, MAX_RESPONSE_SIZE);
    n = read(sockfd, buffer, MAX_RESPONSE_SIZE);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buffer);

    printf("Enter username: ");
    bzero(buffer, MAX_RESPONSE_SIZE);
    fgets(buffer, MAX_RESPONSE_SIZE-1, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // remove newline character

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    // Send password and get response
    bzero(buffer, MAX_RESPONSE_SIZE);
    n = read(sockfd, buffer, MAX_RESPONSE_SIZE);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buffer);

    printf("Enter password: ");
    bzero(buffer, MAX_RESPONSE_SIZE);
    fgets(buffer, MAX_RESPONSE_SIZE-1, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // remove newline character

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    // Get number of messages and their size
    bzero(buffer, MAX_RESPONSE_SIZE);
    n = read(sockfd, buffer, MAX_RESPONSE_SIZE);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s",buffer);

    // Keep retrieving messages until user types 'quit'
    while(1) {
        printf("Enter message number (type 'quit' to exit): ");
        bzero(buffer, MAX_RESPONSE_SIZE);
        fgets(buffer, MAX_RESPONSE_SIZE-1, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // remove newline character

        if(strcmp(buffer, "quit") == 0) {
            break;
        }

        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0)
            error("ERROR writing to socket");

        bzero(buffer, MAX_RESPONSE_SIZE);
        n = read(sockfd, buffer, MAX_RESPONSE_SIZE);
        if (n < 0)
            error("ERROR reading from socket");
        printf("%s\n",buffer);
    }

    // Quit
    printf("Exiting...\n");
    close(sockfd);
    return 0;
}