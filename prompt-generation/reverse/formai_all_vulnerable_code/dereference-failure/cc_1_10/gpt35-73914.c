//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF_SIZE 2048

void display_prompt();
void parse_command(char *command, char *arg1, char *arg2);
void do_ftp(int sockfd);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./ftpclient <ip_addr> <port_num>\n");
        exit(1);
    }

    int sockfd;
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket creation failed");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("inet_pton error for %s", argv[1]);
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        printf("connect failed");
        exit(1);
    }

    do_ftp(sockfd);
    close(sockfd);
    return 0;
}

void display_prompt() {
    printf("ftp> ");
    fflush(stdout);
}

void parse_command(char *command, char *arg1, char *arg2) {
    char *token = strtok(command, " \n");
    if (token) {
        strncpy(arg1, token, MAX_BUF_SIZE);
        token = strtok(NULL, " \n");
    } else {
        strncpy(arg1, "", MAX_BUF_SIZE);
        return;
    }
    if (token) {
        strncpy(arg2, token, MAX_BUF_SIZE);
    } else {
        strncpy(arg2, "", MAX_BUF_SIZE);
    }
    return;
}

void do_ftp(int sockfd) {
    char command[MAX_BUF_SIZE];
    char arg1[MAX_BUF_SIZE];
    char arg2[MAX_BUF_SIZE];
    char response[MAX_BUF_SIZE];

    while (1) {
        display_prompt();

        if (fgets(command, sizeof(command), stdin) == NULL) {
            printf("\n");
            break;
        }

        parse_command(command, arg1, arg2);

        if (strcmp(arg1, "quit") == 0 || strcmp(arg1, "bye") == 0) {
            break;
        } else if (strcmp(arg1, "get") == 0) {
            // Send get command to server
            write(sockfd, command, strlen(command));
            // Wait for server response
            read(sockfd, response, sizeof(response));
            if (strncmp(response, "error", 5) == 0) {
                printf("Error: %s\n", response + 6);
                continue;
            }
            // Send ACK to server
            write(sockfd, "ACK", 3);
            // Receive file from server
            FILE *fp = fopen(arg2, "wb");
            int bytes_received;
            while ((bytes_received = read(sockfd, response, sizeof(response))) > 0) {
                fwrite(response, bytes_received, 1, fp);
            }
            fclose(fp);
        } else if (strcmp(arg1, "put") == 0) {
            // Check if file exists
            if (access(arg2, F_OK) == -1) {
                printf("Error: %s does not exist\n", arg2);
                continue;
            }
            // Send put command to server
            write(sockfd, command, strlen(command));
            // Wait for server response
            read(sockfd, response, sizeof(response));
            if (strncmp(response, "error", 5) == 0) {
                printf("Error: %s\n", response + 6);
                continue;
            }
            // Send ACK to server
            write(sockfd, "ACK", 3);
            // Send file to server
            FILE *fp = fopen(arg2, "rb");
            int bytes_read;
            while ((bytes_read = fread(response, 1, sizeof(response), fp)) > 0) {
                write(sockfd, response, bytes_read);
            }
            fclose(fp);
        } else if (strcmp(arg1, "ls") == 0) {
            // Send ls command to server
            write(sockfd, command, strlen(command));
            // Wait for server response
            read(sockfd, response, sizeof(response));
            printf("%s", response);
        } else {
            printf("Invalid command\n");
        }
    }
}