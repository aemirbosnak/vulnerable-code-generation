//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <sys/sendfile.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int socket_fd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname("smtp.example.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(25);

    if (connect(socket_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    if ((n = write(socket_fd, "HELO localhost\r\n", 13)) < 0) {
        error("ERROR writing to socket");
    }

    if ((n = read(socket_fd, "250", 4)) < 0) {
        error("ERROR reading from socket");
    }

    if ((n = write(socket_fd, "MAIL FROM:<sender@example.com>\r\n", 33)) < 0) {
        error("ERROR writing to socket");
    }

    if ((n = read(socket_fd, "250", 4)) < 0) {
        error("ERROR reading from socket");
    }

    if ((n = write(socket_fd, "RCPT TO:<recipient@example.com>\r\n", 26)) < 0) {
        error("ERROR writing to socket");
    }

    if ((n = read(socket_fd, "250", 4)) < 0) {
        error("ERROR reading from socket");
    }

    if ((n = write(socket_fd, "DATA\r\n", 7)) < 0) {
        error("ERROR writing to socket");
    }

    if ((n = read(socket_fd, "354", 4)) < 0) {
        error("ERROR reading from socket");
    }

    if ((n = write(socket_fd, "Subject: test message\r\n", 26)) < 0) {
        error("ERROR writing to socket");
    }

    if ((n = write(socket_fd, "Hello World!\r\n", 13)) < 0) {
        error("ERROR writing to socket");
    }

    if ((n = read(socket_fd, "250", 4)) < 0) {
        error("ERROR reading from socket");
    }

    if ((n = write(socket_fd, "QUIT\r\n", 8)) < 0) {
        error("ERROR writing to socket");
    }

    if ((n = read(socket_fd, "221", 4)) < 0) {
        error("ERROR reading from socket");
    }

    close(socket_fd);

    return 0;
}