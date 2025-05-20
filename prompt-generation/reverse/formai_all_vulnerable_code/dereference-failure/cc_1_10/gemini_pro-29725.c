//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: energetic
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define MAX_LINE_LENGTH 1024

void send_command(int sockfd, const char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
}

char *recv_line(int sockfd) {
    char *line = malloc(MAX_LINE_LENGTH);
    int line_length = 0;
    while (true) {
        char c;
        if (recv(sockfd, &c, 1, 0) < 0) {
            perror("recv");
            exit(EXIT_FAILURE);
        }
        if (c == '\n') {
            break;
        }
        line[line_length++] = c;
    }
    line[line_length] = '\0';
    return line;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    if (inet_aton(argv[1], &server_addr.sin_addr) == 0) {
        perror("inet_aton");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    char *line = recv_line(sockfd);
    printf("%s", line);
    free(line);

    send_command(sockfd, "USER ");
    send_command(sockfd, argv[2]);
    send_command(sockfd, "\r\n");

    line = recv_line(sockfd);
    printf("%s", line);
    free(line);

    send_command(sockfd, "PASS ");
    char password[100];
    scanf("%s", password);
    send_command(sockfd, password);
    send_command(sockfd, "\r\n");

    line = recv_line(sockfd);
    printf("%s", line);
    free(line);

    send_command(sockfd, "LIST\r\n");

    while (true) {
        line = recv_line(sockfd);
        if (strcmp(line, ".\r\n") == 0) {
            break;
        }
        printf("%s", line);
        free(line);
    }

    send_command(sockfd, "QUIT\r\n");

    close(sockfd);

    return 0;
}