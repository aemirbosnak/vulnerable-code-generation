//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 80

int main(int argc, char *argv[])
{

    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[2048];

    if(argc < 2) {
        fprintf(stderr,"usage %s hostname\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if(server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    char *message = "GET / HTTP/1.1\r\n\r\n";
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("Error sending message");
        exit(1);
    }

    memset(buffer, 0, 2048);
    while ((n = recv(sockfd, buffer, 2047, 0)) > 0) {
        printf("%s", buffer);
    }

    if (n < 0) {
        perror("Error receiving data");
        exit(1);
    }

    close(sockfd);
    return 0;
}