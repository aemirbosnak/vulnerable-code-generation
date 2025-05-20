//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_LEN 1024

int main(int argc, char *argv[]) {
    if(argc != 3) {
        fprintf(stderr, "Usage: %s server_address port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Connect to server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));
    int sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }

    // Send IMAP login command
    char buf[BUF_LEN];
    char username[BUF_LEN], password[BUF_LEN];
    printf("Enter username: ");
    fgets(username, BUF_LEN, stdin);
    printf("Enter password: ");
    fgets(password, BUF_LEN, stdin);
    sprintf(buf, "LOGIN %s %s\r\n", username, password);
    ssize_t num_bytes_sent = send(sock_fd, buf, strlen(buf), 0);
    if(num_bytes_sent != strlen(buf)) {
        fprintf(stderr, "send() failed");
        exit(EXIT_FAILURE);
    }

    // Receive response from server
    memset(buf, 0, BUF_LEN);
    ssize_t num_bytes_recv = recv(sock_fd, buf, BUF_LEN, 0);
    if(num_bytes_recv < 0) {
        perror("recv() failed");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Send IMAP list command
    sprintf(buf, "LIST \"\" \"*\"\r\n");
    num_bytes_sent = send(sock_fd, buf, strlen(buf), 0);
    if(num_bytes_sent != strlen(buf)) {
        fprintf(stderr, "send() failed");
        exit(EXIT_FAILURE);
    }

    // Receive response from server
    memset(buf, 0, BUF_LEN);
    num_bytes_recv = recv(sock_fd, buf, BUF_LEN, 0);
    if(num_bytes_recv < 0) {
        perror("recv() failed");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Disconnect from server
    sprintf(buf, "LOGOUT\r\n");
    num_bytes_sent = send(sock_fd, buf, strlen(buf), 0);
    if(num_bytes_sent != strlen(buf)) {
        fprintf(stderr, "send() failed");
        exit(EXIT_FAILURE);
    }
    close(sock_fd);

    return 0;
}