//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PORT 110
#define USER "your_username"
#define PASS "your_password"

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    int n;

    if (argc!= 3) {
        printf("Usage:./pop3_client <pop3_server_ip> <pop3_server_port>\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter command: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        n = strlen(buffer);
        if (n > 0 && buffer[n - 1] == '\n') {
            buffer[--n] = '\0';
        }

        if (send(sockfd, buffer, n, 0) < 0) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }

        if (strcmp(buffer, "QUIT") == 0) {
            break;
        }

        memset(buffer, 0, BUFFER_SIZE);
        n = read(sockfd, buffer, BUFFER_SIZE);
        if (n < 0) {
            perror("read failed");
            exit(EXIT_FAILURE);
        }

        printf("Server response: %s", buffer);
    }

    close(sockfd);
    return 0;
}