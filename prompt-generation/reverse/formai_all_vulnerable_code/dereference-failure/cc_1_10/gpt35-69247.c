//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAXLINE 1024

void ftp_command(int sock_id);
void ftp_put(int data_sock, char* fname);
void ftp_get(int data_sock, char* fname);

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <IP> <Port>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct sockaddr_in servaddr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) != 0) {
        printf("Connection error: [%d] %s\n", errno, strerror(errno));
        exit(1);
    }

    char recvline[MAXLINE + 1];
    if (read(sockfd, recvline, MAXLINE) == 0) {
        printf("Server terminated prematurely\n");
        exit(1);
    }

    printf("Connected to the FTP server\n");

    ftp_command(sockfd);
    close(sockfd);
    return 0;
}

void ftp_command(int sock_id) {
    char sendline[MAXLINE], recvline[MAXLINE];
    int n;

    while (1) {
        printf("ftp> ");
        fgets(sendline, MAXLINE, stdin);

        // Get rid of \n at the end
        int len = strlen(sendline);
        if (sendline[len-1] == '\n') {
            sendline[len-1] = '\0';
        }

        char* token = strtok(sendline, " ");
        if (token == NULL) continue;

        // Convert to lower case
        for (int i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }

        if (strcmp(token, "put") == 0) {
            token = strtok(NULL, " ");
            if (token == NULL) {
                printf("usage: put <filename>\n");
                continue;
            }
            ftp_put(sock_id, token);
        } else if (strcmp(token, "get") == 0) {
            token = strtok(NULL, " ");
            if (token == NULL) {
                printf("usage: get <filename>\n");
                continue;
            }
            ftp_get(sock_id, token);
        } else if (strcmp(token, "quit") == 0) {
            printf("Bye.\n");
            exit(0);
        } else {
            printf("Invalid command\n");
        }
    }
}

void ftp_put(int data_sock, char* fname) {
    FILE *fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", fname);
        return;
    }

    char sendline[MAXLINE];
    sprintf(sendline, "PUT %s", fname);
    if (write(data_sock, sendline, strlen(sendline)) < 0) {
        printf("Error writing to socket\n");
        return;
    }

    char recvline[MAXLINE];
    if (read(data_sock, recvline, MAXLINE) < 0) {
        printf("Error reading from socket\n");
        return;
    }

    if (strncmp(recvline, "READY", 5) != 0) {
        printf("Server not ready for data. Response: %s\n", recvline);
        return;
    }

    // Send file data
    char buffer[MAXLINE];
    bzero(buffer, MAXLINE);
    int length;
    while ((length = fread(buffer, sizeof(char), MAXLINE, fp)) > 0) {
        if (write(data_sock, buffer, length) < 0) {
            printf("Error writing to socket\n");
            break;
        }
        bzero(buffer, MAXLINE);
    }

    fclose(fp);

    // Wait for acknowledgement
    if (read(data_sock, recvline, MAXLINE) < 0) {
        printf("Error reading from socket\n");
        return;
    }

    if (strncmp(recvline, "OK", 2) == 0) {
        printf("File transfer completed\n");
    } else {
        printf("Error receiving acknowledgement\n");
    }
}

void ftp_get(int data_sock, char* fname) {
    char sendline[MAXLINE];
    sprintf(sendline, "GET %s", fname);
    if (write(data_sock, sendline, strlen(sendline)) < 0) {
        printf("Error writing to socket\n");
        return;
    }

    char recvline[MAXLINE];
    if (read(data_sock, recvline, MAXLINE) < 0) {
        printf("Error reading from socket\n");
        return;
    }

    if (strncmp(recvline, "READY", 5) != 0) {
        printf("Server not ready for data. Response: %s\n", recvline);
        return;
    }

    // Receive file data
    char buffer[MAXLINE];
    FILE* fp = fopen(fname, "w");
    if (fp == NULL) {
        printf("Could not create file %s\n", fname);
        return;
    }
    bzero(buffer, MAXLINE);
    int length;
    while ((length = read(data_sock, buffer, MAXLINE)) > 0) {
        fwrite(buffer, sizeof(char), length, fp);
        bzero(buffer, MAXLINE);
    }

    fclose(fp);

    // Send acknowledgement
    sprintf(sendline, "OK");
    if (write(data_sock, sendline, strlen(sendline)) < 0) {
        printf("Error writing to socket\n");
        return;
    }

    printf("File transfer completed\n");
}