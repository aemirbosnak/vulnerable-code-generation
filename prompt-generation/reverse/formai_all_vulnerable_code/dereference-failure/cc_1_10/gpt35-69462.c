//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: asynchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>

#define MAX_SIZE 1024

void handle_command(int sockfd) {
    char cmd[MAX_SIZE], message[MAX_SIZE];
    while (1) {
        printf("Enter command (PUT/GET/QUIT): ");
        scanf("%s", cmd);
        if (strcmp(cmd, "PUT") == 0) {
            memcpy(message, cmd, strlen(cmd) + 1);
            printf("Enter filename: ");
            scanf("%s", message + strlen(cmd) + 1);
            int fd = open(message + strlen(cmd) + 1, O_RDONLY);
            if (fd == -1) {
                printf("Could not open file %s for reading\n", message + strlen(cmd) + 1);
                continue;
            }
            memcpy(message + strlen(cmd) + 1 + strlen(message + strlen(cmd) + 2), message + strlen(cmd) + 1, strlen(message + strlen(cmd) + 2) + 1);
            if (write(sockfd, message, strlen(cmd) + 1 + strlen(message + strlen(cmd) + 2) + 1) == -1) {
                printf("Could not send PUT command to server\n");
                return;
            }
            printf("Sending file %s...\n", message + strlen(cmd) + 1);
            while (1) {
                int nread = read(fd, message, MAX_SIZE);
                if (nread == 0) break;
                if (nread == -1) {
                    printf("Error reading from file %s\n", message + strlen(cmd) + 1);
                    break;
                }
                if (write(sockfd, message, nread) == -1) {
                    printf("Error sending data to server\n");
                    break;
                }
            }
            close(fd);
            printf("File sent successfully\n");
        } else if (strcmp(cmd, "GET") == 0) {
            memcpy(message, cmd, strlen(cmd) + 1);
            printf("Enter filename: ");
            scanf("%s", message + strlen(cmd) + 1);
            if (write(sockfd, message, strlen(cmd) + 1 + strlen(message + strlen(cmd) + 1) + 1) == -1) {
                printf("Could not send GET command to server\n");
                return;
            }
            printf("Receiving file %s...\n", message + strlen(cmd) + 1);
            int fd = open(message + strlen(cmd) + 1, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd == -1) {
                printf("Could not open file %s for writing\n", message + strlen(cmd) + 1);
                continue;
            }
            while (1) {
                int nread = read(sockfd, message, MAX_SIZE);
                if (nread == 0) break;
                if (nread == -1) {
                    printf("Error receiving data from server\n");
                    break;
                }
                if (write(fd, message, nread) == -1) {
                    printf("Error writing to file %s\n", message + strlen(cmd) + 1);
                    break;
                }
            }
            close(fd);
            printf("File received successfully\n");
        } else if (strcmp(cmd, "QUIT") == 0) {
            memcpy(message, cmd, strlen(cmd) + 1);
            if (write(sockfd, message, strlen(cmd) + 1) == -1) {
                printf("Could not send QUIT command to server\n");
                return;
            }
            printf("Quitting...\n");
            close(sockfd);
            exit(0);
        } else {
            printf("Invalid command\n");
        }
    }
}

void handle_server_response(int sockfd) {
    char message[MAX_SIZE];
    while (1) {
        int nread = read(sockfd, message, MAX_SIZE);
        if (nread <= 0) {
            printf("Connection closed by server\n");
            exit(0);
        }
        message[nread] = '\0';
        if (strcmp(message, "ERROR") == 0) {
            printf("Error from server\n");
        }
    }
}

void handle_events(int sockfd) {
    fd_set set;
    FD_ZERO(&set);
    FD_SET(sockfd, &set);
    FD_SET(STDIN_FILENO, &set);

    while (1) {
        if (select(sockfd + 1, &set, NULL, NULL, NULL) > 0) {
            if (FD_ISSET(sockfd, &set)) {
                handle_server_response(sockfd);
                FD_SET(sockfd, &set);
            }
            if (FD_ISSET(STDIN_FILENO, &set)) {
                handle_command(sockfd);
                FD_SET(STDIN_FILENO, &set);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in servaddr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Could not create socket\n");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("Could not connect to server\n");
        return 1;
    }

    printf("Connected to server\n");

    handle_events(sockfd);

    return 0;
}