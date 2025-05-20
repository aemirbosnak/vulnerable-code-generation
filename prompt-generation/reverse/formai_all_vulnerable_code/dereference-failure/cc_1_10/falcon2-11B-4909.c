//Falcon2-11B DATASET v1.0 Category: Networking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in servaddr;
    struct hostent *server;
    char message[] = "Hello, World!";

    /* Create socket */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(1);
    }

    /* Get the server's address */
    server = gethostbyname("www.google.com");
    if (server == NULL) {
        fprintf(stderr, "gethostbyname failed\n");
        exit(1);
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(80);

    /* Connect to the server */
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    n = write(sockfd, message, sizeof(message));
    if (n < 0) {
        perror("write failed");
        exit(1);
    }

    bzero(message, sizeof(message));
    n = read(sockfd, message, sizeof(message));
    if (n < 0) {
        perror("read failed");
        exit(1);
    }

    printf("Response: %s\n", message);

    close(sockfd);
    return 0;
}