//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256];
    struct hostent *server;

    if ( ( sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    portno = htons(80);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server.\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        bzero(buffer,256);
        n = read(sockfd, buffer, 255);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(EXIT_FAILURE);
        }
        buffer[n] = '\0';
        printf("%s", buffer);
        if (strcmp(buffer, "exit") == 0) {
            break;
        }
        send(sockfd, buffer, strlen(buffer), 0);
    }
    close(sockfd);
    return 0;
}