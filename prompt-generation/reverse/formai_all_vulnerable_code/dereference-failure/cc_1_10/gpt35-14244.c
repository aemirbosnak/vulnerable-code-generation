//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd, portno, n;

    char buffer[256];

    if(argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    portno = atoi(argv[2]);
    server = gethostbyname(argv[1]);

    if(server == NULL) {
        printf("Error: no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if(connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        printf("Error connecting\n");
        exit(1);
    }

    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);

    n = write(sockfd, buffer, strlen(buffer));

    if(n < 0) {
        printf("Error writing to socket\n");
        exit(1);
    }

    bzero(buffer,256);
    n = read(sockfd, buffer, 255);

    if(n < 0) {
        printf("Error reading from socket\n");
        exit(1);
    }

    printf("%s\n",buffer);
    close(sockfd);

    return 0;
}