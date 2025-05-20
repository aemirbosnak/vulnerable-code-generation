//FormAI DATASET v1.0 Category: Socket programming ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 256

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];

    if (argc < 2) {
        fprintf(stderr,"Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0) {
        error("Error opening socket.");
    }

    server = gethostbyname(argv[1]);

    if(server == NULL) {
        fprintf(stderr, "Error, no such host.\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        error("Error connecting.");
    }

    printf("Enter message: ");
    bzero(buffer,BUFFER_SIZE);
    fgets(buffer,BUFFER_SIZE,stdin);

    n = write(sockfd,buffer,strlen(buffer));

    if (n < 0) {
         error("Error writing to socket.");
    }

    bzero(buffer,BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE-1);

    if (n < 0) {
         error("Error reading from socket.");
    }

    printf("Server response: %s\n", buffer);

    close(sockfd);

    return 0;
}