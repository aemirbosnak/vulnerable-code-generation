//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE 1024
#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    char *username, *password;
    int n;

    // get username and password from command line arguments
    username = argv[1];
    password = argv[2];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // set up server address structure
    portno = PORT;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(portno);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // send username and password to server
    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    // receive response from server
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        printf("Error receiving response\n");
        exit(1);
    }
    buffer[n] = '\0';
    printf("Server response: %s\n", buffer);

    // close socket
    close(sockfd);
    return 0;
}