//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define PORT 21

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char *username = "anonymous";
    char *password = "anonymous@example.com";
    char *command;
    FILE *fp;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Connect to server
    server = gethostbyname("ftp.example.com");
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    portno = PORT;
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Login to server
    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    // Send command to server
    command = "ls";
    send(sockfd, command, strlen(command), 0);

    // Receive response from server
    bzero(buffer, BUFFER_SIZE);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n > 0) {
        printf("Response from server: %s\n", buffer);
    }

    // Close connection
    close(sockfd);

    return 0;
}