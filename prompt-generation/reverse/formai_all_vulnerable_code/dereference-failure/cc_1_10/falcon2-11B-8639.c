//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];

    /* Create a socket */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    /* Convert the server name to an address */
    server = gethostbyname("www.example.com");
    if (server == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    /* Connect to the server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    /* Send a request */
    n = sprintf(buffer, "GET / HTTP/1.0\r\n\r\n");
    if (write(sockfd, buffer, n) < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }

    /* Read the response */
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }

    /* Print the response */
    printf("%s", buffer);

    return 0;
}