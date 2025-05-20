//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: imaginative
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define COMMAND_SIZE 128

int main(int argc, char const *argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <FTP server IP> <Port number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in ftp_server_address;
    memset(&ftp_server_address, 0, sizeof(ftp_server_address));

    ftp_server_address.sin_family = AF_INET;
    ftp_server_address.sin_addr.s_addr = inet_addr(argv[1]);
    ftp_server_address.sin_port = htons(atoi(argv[2]));

    if (connect(sock_fd, (struct sockaddr *)&ftp_server_address, sizeof(ftp_server_address)) < 0) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }

    char user_command[COMMAND_SIZE];
    char response[BUFFER_SIZE];

    printf("Connected to FTP server\n");

    while (1) {
        printf("ftp> ");
        fgets(user_command, COMMAND_SIZE, stdin);
        user_command[strcspn(user_command, "\n")] = 0; // Remove newline character

        if (send(sock_fd, user_command, strlen(user_command), 0) < 0) {
            perror("send() failed");
            exit(EXIT_FAILURE);
        }

        if (strcmp(user_command, "quit") == 0) {
            break;
        }

        if (recv(sock_fd, response, BUFFER_SIZE, 0) < 0) {
            perror("recv() failed");
            exit(EXIT_FAILURE);
        }

        printf("%s\n", response);
    }

    printf("Disconnected from FTP server\n");

    close(sock_fd);
    return 0;
}