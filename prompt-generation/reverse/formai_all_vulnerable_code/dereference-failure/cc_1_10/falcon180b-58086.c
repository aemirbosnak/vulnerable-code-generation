//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char hostname[100];
    char username[100];
    char password[100];
    char command[100];
    struct hostent *host;
    struct sockaddr_in server_addr;
    int sockfd, port;

    // get hostname, username, password and port from command line arguments
    strcpy(hostname, argv[1]);
    strcpy(username, argv[2]);
    strcpy(password, argv[3]);
    port = atoi(argv[4]);

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // get server address
    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // send username and password
    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);
    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);

    // receive server response
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s", buffer);

    // send FTP commands
    sprintf(command, "LIST\r\n");
    send(sockfd, command, strlen(command), 0);

    // receive server response
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s", buffer);

    // close socket
    close(sockfd);

    return 0;
}