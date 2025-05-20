//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER "ftp.dlptest.com"
#define USERNAME "dlpuser"
#define PASSWORD "rNrKYTX9g7z3RgJRmxWuHRY"
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int ftp_connect(const char *hostname, int port) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("ERROR connecting");

    return sockfd;
}

void ftp_send(int sockfd, const char *msg) {
    write(sockfd, msg, strlen(msg));
    write(sockfd, "\r\n", 2);
}

void ftp_receive(int sockfd, char *buffer, size_t bufsize) {
    bzero(buffer, bufsize);
    read(sockfd, buffer, bufsize - 1);
    printf("%s", buffer);
}

void ftp_login(int sockfd) {
    char buffer[BUFFER_SIZE];

    ftp_receive(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer); // Print server welcome message

    ftp_send(sockfd, "USER " USERNAME);
    ftp_receive(sockfd, buffer, BUFFER_SIZE);

    ftp_send(sockfd, "PASS " PASSWORD);
    ftp_receive(sockfd, buffer, BUFFER_SIZE);
}

void ftp_list(int sockfd) {
    char buffer[BUFFER_SIZE];
    ftp_send(sockfd, "PASV");
    ftp_receive(sockfd, buffer, BUFFER_SIZE);

    char *begin = strchr(buffer, '(');
    char *end = strchr(buffer, ')');
    if (begin && end) {
        int p1, p2;
        sscanf(begin + 1, "%*d,%*d,%*d,%*d,%d,%d", &p1, &p2);
        int data_port = p1 * 256 + p2;

        int data_sockfd = ftp_connect(SERVER, data_port);

        ftp_send(sockfd, "LIST");
        ftp_receive(data_sockfd, buffer, BUFFER_SIZE);
        close(data_sockfd);
    } else {
        fprintf(stderr, "ERROR: could not enter passive mode\n");
    }
}

void ftp_quit(int sockfd) {
    char buffer[BUFFER_SIZE];
    ftp_send(sockfd, "QUIT");
    ftp_receive(sockfd, buffer, BUFFER_SIZE);
    close(sockfd);
}

int main() {
    int sockfd = ftp_connect(SERVER, 21);
    ftp_login(sockfd);
    ftp_list(sockfd);
    ftp_quit(sockfd);

    return 0;
}