//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>

#define MAX_MESSAGE_SIZE 1024
#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int n;
    char buffer[BUFFER_SIZE];
    char *command = "AUTHENTICATE";
    char *response = "OK";

    if (argc!= 2) {
        fprintf(stderr, "usage: %s <imap_server>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    server = gethostbyname("localhost");

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    memset(buffer, 0, BUFFER_SIZE);
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    if (strcmp(response, buffer)!= 0) {
        fprintf(stderr, "ERROR: %s\n", buffer);
        exit(1);
    }

    close(sockfd);
    return 0;
}