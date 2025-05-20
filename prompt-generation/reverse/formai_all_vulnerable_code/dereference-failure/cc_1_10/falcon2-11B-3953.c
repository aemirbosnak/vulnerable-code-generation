//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256];
    char command[256];
    char response[256];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    // Connect to server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[2], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send command
    sprintf(command, "USER anonymous\r\n");
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    sprintf(command, "PASS %s\r\n", argv[2]);
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    sprintf(command, "PWD\r\n");
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    read(sockfd, response, sizeof(response));
    printf("Response: %s\n", response);

    // Close socket
    close(sockfd);

    return 0;
}