//MISTRAL-7B DATASET v1.0 Category: Networking ; Style: puzzling
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct { int a; char b[10]; } puzzle;

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    puzzle p;

    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    read(newsockfd, buffer, 255);

    sscanf(buffer, "%d%s", &p.a, p.b);

    printf("Received: a=%d, b=%s\n", p.a, p.b);

    memset(buffer, 0, 255);

    strcpy(buffer, "I am the server, you are the client!");

    write(newsockfd, buffer, strlen(buffer));

    close(newsockfd);
    close(sockfd);

    return 0;
}