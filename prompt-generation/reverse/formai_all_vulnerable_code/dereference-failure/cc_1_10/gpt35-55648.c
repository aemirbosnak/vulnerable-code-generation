//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define SERVER_PORT 143

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUF_SIZE];

    if (argc < 3) {
        printf("Usage: %s hostname username\n", argv[0]);
        exit(0);
    }

    portno = SERVER_PORT;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to %s:%d\n", argv[1], portno);

    // Receive initial greeting message from server
    n = read(sockfd, buffer, BUF_SIZE - 1);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    buffer[n] = '\0';
    printf("%s", buffer);

    // Send login command to server
    sprintf(buffer, "a001 LOGIN %s\r\n", argv[2]);
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Receive response from server
    n = read(sockfd, buffer, BUF_SIZE - 1);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    buffer[n] = '\0';
    printf("%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}