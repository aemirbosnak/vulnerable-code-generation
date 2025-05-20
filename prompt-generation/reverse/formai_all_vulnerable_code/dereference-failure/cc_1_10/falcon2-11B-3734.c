//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buf[100];
    struct hostent *server;

    // Initialize socket and server address
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    portno = htons(atoi(argv[1]));
    server = gethostbyname("www.google.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send message
    sprintf(buf, "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n");
    write(sockfd, buf, strlen(buf));

    // Read response
    bzero(buf, sizeof(buf));
    n = read(sockfd, buf, sizeof(buf));
    printf("%s", buf);

    // Close connection
    close(sockfd);
    return 0;
}