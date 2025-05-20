//MISTRAL-7B DATASET v1.0 Category: Building a POP3 Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT 110
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("ERROR opening socket");
    }

    server = gethostbyname("mail.example.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        die("ERROR connecting");
    }

    printf("Connected to POP3 server\n");

    // Send USER command
    send(sockfd, "USER username\r\n", strlen("USER username\r\n"), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // Send PASS command
    send(sockfd, "PASS password\r\n", strlen("PASS password\r\n"), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // Fetch and print email headers
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received > 0) {
            printf("%s", buffer);
        } else if (bytes_received == 0) {
            break;
        } else {
            die("ERROR receiving data");
        }
    }

    close(sockfd);
    return EXIT_SUCCESS;
}