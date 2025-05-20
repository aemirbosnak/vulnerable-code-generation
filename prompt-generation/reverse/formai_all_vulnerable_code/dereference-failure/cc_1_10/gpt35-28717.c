//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024
#define MAX_ADDR_LEN 256

void handle_error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_msg(int sockfd, char *msg) {
    if (send(sockfd, msg, strlen(msg), 0) != strlen(msg))
        handle_error("Error sending message");
}

void receive_msg(int sockfd, char *buf) {
    ssize_t num_bytes = recv(sockfd, buf, BUF_SIZE - 1, 0);
    if (num_bytes == -1)
        handle_error("Error receiving message");
    buf[num_bytes] = '\0';
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_address> <port_number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char server_addr[MAX_ADDR_LEN];
    int port_num = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        handle_error("Error creating socket");

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port_num);
    if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0)
        handle_error("Invalid address");

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1)
        handle_error("Error connecting to server");

    char buf[BUF_SIZE];
    receive_msg(sockfd, buf); // Greeting message

    while (1) {
        printf("%s", buf);
        fgets(buf, BUF_SIZE, stdin);
        send_msg(sockfd, buf);

        // Parse command
        char cmd[BUF_SIZE];
        char arg[BUF_SIZE];
        sscanf(buf, "%s %s", cmd, arg);

        if (strcmp(cmd, "quit") == 0) {
            receive_msg(sockfd, buf);
            printf("%s", buf);
            break;
        } else if (strcmp(cmd, "get") == 0) {
            receive_msg(sockfd, buf);
            if (strcmp(buf, "NO") == 0) {
                printf("File not found\n");
            } else {
                int file_fd = open(arg, O_WRONLY | O_CREAT | O_TRUNC, 0644);
                if (file_fd == -1)
                    handle_error("Error creating file");

                int num_bytes;
                while ((num_bytes = recv(sockfd, buf, BUF_SIZE, 0)) > 0) {
                    if (write(file_fd, buf, num_bytes) != num_bytes)
                        handle_error("Error writing to file");
                }
                if (num_bytes == -1)
                    handle_error("Error receiving file");

                close(file_fd);
                printf("File received successfully\n");
            }
        } else if (strcmp(cmd, "put") == 0) {
            FILE *file = fopen(arg, "r");
            if (file == NULL) {
                printf("File not found\n");
                send_msg(sockfd, "NO");
            } else {
                send_msg(sockfd, "YES");

                int num_bytes;
                while ((num_bytes = fread(buf, sizeof(char), BUF_SIZE, file)) > 0) {
                    if (send(sockfd, buf, num_bytes, 0) != num_bytes)
                        handle_error("Error sending file");
                }
                if (ferror(file))
                    handle_error("Error reading from file");

                fclose(file);
                printf("File sent successfully\n");
            }
        } else {
            receive_msg(sockfd, buf);
            printf("%s", buf);
        }
    }

    close(sockfd);
    return 0;
}