//Falcon2-11B DATASET v1.0 Category: Networking ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    struct hostent* he;
    struct sockaddr_in serv_addr;
    int sockfd, portno, n;
    char buffer[256];
    char* host;

    host = "www.google.com";
    portno = 80;

    he = gethostbyname(host);
    if (he == NULL) {
        printf("Error, no such host\n");
        exit(0);
    }
    printf("host info: %s\n", he->h_name);
    printf("aliases: ");
    while (he->h_aliases!= NULL) {
        printf("%s ", he->h_aliases[0]);
        he = he->h_aliases;
    }
    printf("\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) he->h_addr, (char *) &serv_addr.sin_addr.s_addr, he->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(0);
    }

    printf("connected to %s\n", he->h_name);

    while (1) {
        bzero(buffer, 256);
        n = read(sockfd, buffer, 255);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(0);
        }
        if (n == 0)
            break;
        printf("%s", buffer);
    }

    bzero(buffer, 256);
    sprintf(buffer, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(0);
    }

    close(sockfd);
    return 0;
}