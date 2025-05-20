//MISTRAL-7B DATASET v1.0 Category: Networking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error_handling(char *message) {
    fputs(message, stderr);
    fputs("\n", stderr);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd;
    int new_sockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len;
    char message[BUFFER_SIZE];
    int read_size;

    if (argc != 2) {
        fprintf(stderr, "Usage : %s <Port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error_handling("Error : Failed to create socket\n");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error_handling("Error : Failed to bind socket\n");
    }

    listen(sockfd, 5);

    cli_len = sizeof(cli_addr);
    new_sockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &cli_len);

    if (new_sockfd < 0) {
        error_handling("Error : Failed to accept connection\n");
    }

    printf("Connected client IP : %s, Port : %d\n",
           inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    while (1) {
        read_size = recv(new_sockfd, message, BUFFER_SIZE, 0);

        if (read_size < 0) {
            error_handling("Error : Failed to receive message\n");
        }

        if (read_size == 0) {
            printf("Client disconnected\n");
            break;
        }

        printf("Received message : %s\n", message);

        memset(message, 0, BUFFER_SIZE);

        fputs("Enter your message : ", stdout);
        fgets(message, BUFFER_SIZE, stdin);

        send(new_sockfd, message, strlen(message), 0);
    }

    close(new_sockfd);
    close(sockfd);

    return 0;
}