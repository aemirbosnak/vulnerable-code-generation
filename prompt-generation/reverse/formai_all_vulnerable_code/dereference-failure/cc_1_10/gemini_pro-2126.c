//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

void err(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];
    clock_t start, end;
    double time_taken;

    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        err("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        err("ERROR connecting");

    start = clock();
    bzero(buffer,1024);
    n = write(sockfd, "GET / HTTP/1.1\nHost: www.example.com\n\n", 48);
    if (n < 0) 
        err("ERROR writing to socket");

    bzero(buffer,1024);
    n = read(sockfd,buffer,1023);
    if (n < 0) 
        err("ERROR reading from socket");

    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The download speed is: %f bytes/second\n", (double)n / time_taken);
    close(sockfd);

    return 0;
}