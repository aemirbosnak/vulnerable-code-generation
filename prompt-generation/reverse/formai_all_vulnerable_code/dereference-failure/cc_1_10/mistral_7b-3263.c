//MISTRAL-7B DATASET v1.0 Category: Building a FTP Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <fcntl.h>

#define PORT 21
#define BUFFER_SIZE 1024
#define USER "anonymous"
#define PASS "mymail@example.com"

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char command[256];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("ftp.example.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Login
    send(sockfd, USER, strlen(USER), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    send(sockfd, PASS, strlen(PASS), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Change to binary mode
    send(sockfd, "TYPE I\r\n", 6, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Set local file type
    sprintf(command, "STOR %s\r\n", argv[1]);
    send(sockfd, command, strlen(command), 0);

    int file = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        write(file, buffer, n);
    }

    close(file);
    close(sockfd);

    return 0;
}