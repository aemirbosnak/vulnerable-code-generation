//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 1024

void die(char *error_msg) {
    perror(error_msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        die("Usage: ./ftp_client <server_ip> <port>");
    }
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd == -1) {
        die("Couldn't create socket");
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    if(connect(sock_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        die("Connect request failed");
    }
    printf("Connection established with the server...\n");
    while(1) {
        char message[MAXSIZE];
        printf("Enter message to send: ");
        fgets(message, MAXSIZE, stdin);
        message[strlen(message)-1] = '\0'; // to overwrite the newline character with NULL
        if(send(sock_fd, message, strlen(message), 0) == -1) {
            die("Couldn't send message");
        }
        if(strcmp(message, "quit") == 0) {
            printf("Terminating program...\n");
            break;
        }
        char server_message[MAXSIZE] = {0};
        if(recv(sock_fd, server_message, MAXSIZE, 0) == -1) {
            die("Couldn't receive message from server");
        }
        printf("Server: %s\n", server_message);
    }
    close(sock_fd);
    return 0;
}