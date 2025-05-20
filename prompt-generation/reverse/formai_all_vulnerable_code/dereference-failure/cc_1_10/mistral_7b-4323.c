//MISTRAL-7B DATASET v1.0 Category: Email Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define SERVER_PORT 5000
#define MAX_BUFFER_SIZE 1024

typedef struct {
    char sender[100];
    char receiver[100];
    char subject[100];
    char message[500];
} email_t;

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFFER_SIZE];
    email_t email;

    if (argc != 5) {
        fprintf(stderr, "Usage: %s <sender> <receiver> <subject> <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(email.sender, argv[1]);
    strcpy(email.receiver, argv[2]);
    strcpy(email.subject, argv[3]);
    strcpy(email.message, argv[4]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("ERROR converting IPv4 address to bytes");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    sprintf(buffer, "SENDER:%s\nRECEIVER:%s\nSUBJECT:%s\nMESSAGE:%s\n.", email.sender, email.receiver, email.subject, email.message);
    send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, 0, MAX_BUFFER_SIZE);

    int n = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (n > 0) {
        printf("%s\n", buffer);
    } else {
        perror("ERROR reading from socket");
    }

    close(sockfd);
    return EXIT_SUCCESS;
}