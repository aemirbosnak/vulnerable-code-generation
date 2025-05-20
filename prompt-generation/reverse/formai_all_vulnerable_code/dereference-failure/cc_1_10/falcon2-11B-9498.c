//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define POP3_PORT 110

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buf[1024];
    char *user, *password;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP3_PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/port");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    printf("Username: ");
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        perror("Error reading username");
        exit(EXIT_FAILURE);
    }
    user = strtok(buf, "\n");

    printf("Password: ");
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        perror("Error reading password");
        exit(EXIT_FAILURE);
    }
    password = strtok(buf, "\n");

    if (send(sockfd, user, strlen(user), 0) < 0 || send(sockfd, password, strlen(password), 0) < 0) {
        perror("Error sending username/password");
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, buf, sizeof(buf), 0) <= 0) {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buf);

    close(sockfd);
    return 0;
}