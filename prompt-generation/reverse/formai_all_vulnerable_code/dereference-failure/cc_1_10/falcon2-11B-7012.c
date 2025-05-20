//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[100];
    time_t start, end;
    int speed;
    double timeTaken;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Unknown host\n");
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    start = time(NULL);
    speed = 0;

    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        speed += n;
    }

    end = time(NULL);
    timeTaken = difftime(end, start);
    speed = speed / timeTaken;

    printf("Speed: %d bytes/second\n", speed);

    return 0;
}