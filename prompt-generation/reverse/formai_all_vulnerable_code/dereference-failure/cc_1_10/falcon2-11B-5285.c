//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024
#define PORT 21
#define HOST "127.0.0.1"

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFSIZE];
    char command[BUFSIZE];
    char response[BUFSIZE];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up server address
    server = gethostbyname(HOST);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send command
    printf("Enter your FTP command: ");
    fgets(command, BUFSIZE, stdin);

    // Send command to server
    sprintf(buffer, "USER anonymous\r\n");
    write(sockfd, buffer, strlen(buffer));
    sprintf(buffer, "PASS %s\r\n", "password");
    write(sockfd, buffer, strlen(buffer));
    sprintf(buffer, "TYPE I\r\n");
    write(sockfd, buffer, strlen(buffer));
    sprintf(buffer, "QUIT\r\n");
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, BUFSIZE);
    if (n == 0) {
        printf("ERROR: %s\n", buffer);
        exit(1);
    }

    // Close socket
    close(sockfd);

    return 0;
}