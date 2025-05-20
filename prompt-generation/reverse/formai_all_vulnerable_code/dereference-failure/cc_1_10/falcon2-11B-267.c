//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 25
#define BUFFER_SIZE 1024

void send_mail(char* from_addr, char* to_addr, char* msg_body) {
    int sockfd, send_sockfd, ch;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    char* msg = "FROM: ";
    strcat(msg, from_addr);
    strcat(msg, " \r\n");
    strcat(msg, "TO: ");
    strcat(msg, to_addr);
    strcat(msg, " \r\n");
    strcat(msg, "SUBJECT: \r\n");
    strcat(msg, "This is a test message from C. \r\n\r\n");
    strcat(msg, msg_body);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    if (send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    bzero(buffer, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);
}

int main(int argc, char *argv[]) {
    char* from_addr = "test@example.com";
    char* to_addr = "test@example.com";
    char* msg_body = "This is a test message from C.";

    send_mail(from_addr, to_addr, msg_body);

    return 0;
}