//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_COMMAND_LENGTH 4096
#define MAX_RESPONSE_LENGTH 4096
#define MAX_FILENAME_LENGTH 1024

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Usage: %s <FTP server IP address> <port number>\n", argv[0]);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket() error");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0) {
        perror("inet_pton() error");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("connect() error");
        return 1;
    }

    printf("Connected to FTP server at %s:%s\n\n", argv[1], argv[2]);

    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];

    while (1) {
        printf("Enter FTP command (e.g. GET or PUT): ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        if (strlen(command) > 0 && command[strlen(command)-1] == '\n')
            command[strlen(command)-1] = '\0';

        if (strcmp(command, "quit") == 0) {
            printf("Closing FTP session...\n");
            break;
        }

        if (send(sockfd, command, strlen(command), 0) < 0) {
            perror("send() error");
            return 1;
        }

        if (recv(sockfd, response, MAX_RESPONSE_LENGTH, 0) < 0) {
            perror("recv() error");
            return 1;
        }

        printf("%s\n", response);

        if (strncmp(response, "File found", 10) == 0) {
            printf("Enter filename for download: ");
            char filename[MAX_FILENAME_LENGTH];
            fgets(filename, MAX_FILENAME_LENGTH, stdin);

            if (strlen(filename) > 0 && filename[strlen(filename)-1] == '\n')
                filename[strlen(filename)-1] = '\0';

            FILE *fp = fopen(filename, "wb");

            if (fp == NULL) {
                perror("fopen() error");
                return 1;
            }

            while (1) {
                memset(response, 0, MAX_RESPONSE_LENGTH);
                int bytes_recv = recv(sockfd, response, MAX_RESPONSE_LENGTH, 0);

                if (bytes_recv < 0) {
                    perror("recv() error");
                    return 1;
                }
                
                if (strncmp(response, "ENDOFFILE", 9) == 0) {
                    printf("File transfer completed.\n");
                    break;
                }

                fwrite(response, sizeof(char), bytes_recv, fp);
            }

            fclose(fp);
        }

        if (strncmp(command, "put", 3) == 0) {
            printf("Enter filename for upload: ");

            char filename[MAX_FILENAME_LENGTH];
            fgets(filename, MAX_FILENAME_LENGTH, stdin);

            if (strlen(filename) > 0 && filename[strlen(filename)-1] == '\n')
                filename[strlen(filename)-1] = '\0';

            FILE *fp = fopen(filename, "rb");

            if (fp == NULL) {
                perror("fopen() error");
                return 1;
            }

            int bytes_sent;

            while (1) {
                memset(response, 0, MAX_RESPONSE_LENGTH);
                int bytes_read = fread(response, sizeof(char), MAX_RESPONSE_LENGTH, fp);

                if (bytes_read <= 0) {
                    send(sockfd, "ENDOFFILE", strlen("ENDOFFILE"), 0);
                    printf("File transfer completed.\n");
                    break;
                }

                bytes_sent = send(sockfd, response, bytes_read, 0);

                if (bytes_sent < 0) {
                    perror("send() error");
                    return 1;
                }
            }

            fclose(fp);
        }
    }

    close(sockfd);

    return 0;
}