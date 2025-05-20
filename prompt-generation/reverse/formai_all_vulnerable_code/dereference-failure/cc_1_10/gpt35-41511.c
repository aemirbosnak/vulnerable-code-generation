//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define POP3_PORT 110

int main(int argc , char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUF_SIZE] = {0};

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: cannot resolve hostname %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("[ERROR] Failed to create socket.");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP3_PORT);
    serv_addr.sin_addr = *((struct in_addr *) server->h_addr);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("[ERROR] Connection failed.");
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, buffer, BUF_SIZE, 0) < 0) {
        perror("[ERROR] Failed to read server response.");
        exit(EXIT_FAILURE);
    }

    printf("[INFO] Server Response: %s", buffer);

    // Send POP3 commands
    sprintf(buffer, "USER %s\r\n", argv[2]);
    send(sockfd, buffer, strlen(buffer), 0);
    printf("[INFO] Client: %s", buffer);

    if (recv(sockfd, buffer, BUF_SIZE, 0) < 0) {
        perror("[ERROR] Failed to read server response.");
        exit(EXIT_FAILURE);
    }

    printf("[INFO] Server Response: %s", buffer);

    sprintf(buffer, "PASS %s\r\n", getpass("[INFO] Password: "));
    send(sockfd, buffer, strlen(buffer), 0);
    printf("[INFO] Client: PASS [hidden]\n");

    if (recv(sockfd, buffer, BUF_SIZE, 0) < 0) {
        perror("[ERROR] Failed to read server response.");
        exit(EXIT_FAILURE);
    }

    printf("[INFO] Server Response: %s", buffer);

    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    printf("[INFO] Client: QUIT\n");

    if (recv(sockfd, buffer, BUF_SIZE, 0) < 0) {
        perror("[ERROR] Failed to read server response.");
        exit(EXIT_FAILURE);
    }

    printf("[INFO] Server Response: %s", buffer);

    close(sockfd);
    return 0;
}