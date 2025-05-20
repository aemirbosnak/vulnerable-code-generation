//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    int client_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    if (connect(client_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(client_sockfd);
        return EXIT_FAILURE;
    }

    char buf[MAX_BUF_SIZE];
    while (1) {
        memset(buf, 0, MAX_BUF_SIZE);
        printf("Enter command (LIST, RETR, STOR, QUIT): ");
        fgets(buf, MAX_BUF_SIZE, stdin);
        buf[strlen(buf) - 1] = '\0';

        if (strcmp(buf, "QUIT") == 0) {
            break;
        }

        if (send(client_sockfd, buf, strlen(buf), 0) == -1) {
            perror("send");
            close(client_sockfd);
            return EXIT_FAILURE;
        }

        if (strcmp(buf, "LIST") == 0) {
            while (1) {
                memset(buf, 0, MAX_BUF_SIZE);
                if (recv(client_sockfd, buf, MAX_BUF_SIZE, 0) == 0) {
                    break;
                }
                printf("%s\n", buf);
            }
        } else if (strcmp(buf, "RETR") == 0) {
            printf("Enter file name: ");
            fgets(buf, MAX_BUF_SIZE, stdin);
            buf[strlen(buf) - 1] = '\0';

            if (send(client_sockfd, buf, strlen(buf), 0) == -1) {
                perror("send");
                close(client_sockfd);
                return EXIT_FAILURE;
            }

            FILE *fp = fopen(buf, "wb");
            if (fp == NULL) {
                perror("fopen");
                close(client_sockfd);
                return EXIT_FAILURE;
            }

            while (1) {
                memset(buf, 0, MAX_BUF_SIZE);
                if (recv(client_sockfd, buf, MAX_BUF_SIZE, 0) == 0) {
                    break;
                }
                fwrite(buf, 1, strlen(buf), fp);
            }

            fclose(fp);
        } else if (strcmp(buf, "STOR") == 0) {
            printf("Enter file name: ");
            fgets(buf, MAX_BUF_SIZE, stdin);
            buf[strlen(buf) - 1] = '\0';

            if (send(client_sockfd, buf, strlen(buf), 0) == -1) {
                perror("send");
                close(client_sockfd);
                return EXIT_FAILURE;
            }

            FILE *fp = fopen(buf, "rb");
            if (fp == NULL) {
                perror("fopen");
                close(client_sockfd);
                return EXIT_FAILURE;
            }

            while (1) {
                memset(buf, 0, MAX_BUF_SIZE);
                int bytes_read = fread(buf, 1, MAX_BUF_SIZE, fp);
                if (bytes_read <= 0) {
                    break;
                }
                if (send(client_sockfd, buf, bytes_read, 0) == -1) {
                    perror("send");
                    close(client_sockfd);
                    fclose(fp);
                    return EXIT_FAILURE;
                }
            }

            fclose(fp);
        }
    }

    close(client_sockfd);
    return EXIT_SUCCESS;
}