//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buf[256];
    char filename[256];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(1);
    }

    // Assign the server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "gethostbyname() failed\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(8080);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Send a request to the server
    sprintf(buf, "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n");
    write(sockfd, buf, strlen(buf));

    // Receive response from the server
    bzero(buf, 256);
    n = read(sockfd, buf, 256);
    if (n < 0) {
        perror("read failed");
        exit(1);
    }
    printf("Server response: %s\n", buf);

    // Send a new request to the server
    sprintf(buf, "GET /index.html HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n");
    write(sockfd, buf, strlen(buf));

    // Receive response from the server
    bzero(buf, 256);
    n = read(sockfd, buf, 256);
    if (n < 0) {
        perror("read failed");
        exit(1);
    }
    printf("Server response: %s\n", buf);

    // Close the socket
    close(sockfd);

    return 0;
}