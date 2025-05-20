//MISTRAL-7B DATASET v1.0 Category: Building a FTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define PORT 21
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host is known.\n");
        exit(EXIT_FAILURE);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("ERROR opening socket");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(server->h_addr_list[0]);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        die("ERROR connecting");
    }

    // Greeting
    write(sockfd, "USER anonymous\r\n", strlen("USER anonymous\r\n"));
    write(sockfd, "PASS anonymous\r\n", strlen("PASS anonymous\r\n"));
    write(sockfd, "TYPE A\r\n", strlen("TYPE A\r\n"));

    char cmd[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];

    sprintf(cmd, "RETR %s\r\n", argv[2]);
    write(sockfd, cmd, strlen(cmd));

    while ((n = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
        fwrite(buffer, n, 1, stdout);
    }

    if (n < 0) {
        die("ERROR reading from socket");
    }

    write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
    close(sockfd);

    return EXIT_SUCCESS;
}