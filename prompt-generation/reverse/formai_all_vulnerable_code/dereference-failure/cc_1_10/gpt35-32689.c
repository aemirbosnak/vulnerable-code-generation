//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {

    // Ensures correct number of arguments
    if(argc != 3) {
        printf("Usage: %s <IP> <Port>\n", argv[0]);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sockfd < 0) {
        perror("Error: socket creation failed");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error: connection failed");
        exit(1);
    }

    char cmd[BUF_SIZE];
    char response[BUF_SIZE];
    memset(cmd, 0, BUF_SIZE);
    memset(response, 0, BUF_SIZE);

    // Login procedure, expects username and password
    printf("Username: ");
    fgets(cmd, BUF_SIZE, stdin);
    write(sockfd, cmd, strlen(cmd));
    memset(cmd, 0, BUF_SIZE);

    printf("Password: ");
    fgets(cmd, BUF_SIZE, stdin);
    write(sockfd, cmd, strlen(cmd));
    memset(cmd, 0, BUF_SIZE);

    while(1) {
        printf("FTP> ");
        fgets(cmd, BUF_SIZE, stdin);

        // Checking if user wants to quit
        if(strncmp(cmd, "QUIT", 4) == 0) {
            write(sockfd, cmd, strlen(cmd));
            read(sockfd, response, BUF_SIZE);
            printf("%s", response);
            break;
        }

        // Sending command to server
        write(sockfd, cmd, strlen(cmd));
        memset(response, 0, BUF_SIZE);

        // Receiving response from server
        read(sockfd, response, BUF_SIZE);
        printf("%s", response);
    }

    // Closing the socket
    close(sockfd);
    return 0;
}