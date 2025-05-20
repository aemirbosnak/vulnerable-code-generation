//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <fcntl.h>

#define FTP_PORT 21
#define BUFFER_SIZE 1024

void error(const char* msg) {
    perror(msg);
    exit(1);
}

void ftp_send_command(int sockfd, const char* cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, "\r\n", 2, 0);
}

void ftp_receive_response(int sockfd, char* buffer, size_t size) {
    recv(sockfd, buffer, size, 0);
}

void ftp_login(int sockfd, const char* username, const char* password) {
    char buffer[BUFFER_SIZE];

    ftp_receive_response(sockfd, buffer, BUFFER_SIZE);
    printf("Response: %s", buffer);
  
    char user_cmd[BUFFER_SIZE];
    snprintf(user_cmd, sizeof(user_cmd), "USER %s", username);
    ftp_send_command(sockfd, user_cmd);
    ftp_receive_response(sockfd, buffer, BUFFER_SIZE);
    printf("Response: %s", buffer);
  
    char pass_cmd[BUFFER_SIZE];
    snprintf(pass_cmd, sizeof(pass_cmd), "PASS %s", password);
    ftp_send_command(sockfd, pass_cmd);
    ftp_receive_response(sockfd, buffer, BUFFER_SIZE);
    printf("Response: %s", buffer);
}

void ftp_list_files(int sockfd) {
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "PASV");
    ftp_send_command(sockfd, command);
    ftp_receive_response(sockfd, buffer, BUFFER_SIZE);

    printf("Response: %s", buffer);

    // Parse response to get the data connection parameters
    int p1, p2;
    if (sscanf(buffer, "%*d %*d %*d %*d %d,%d", &p1, &p2) != 2) {
        fprintf(stderr, "Failed to parse PASV response\n");
        return;
    }

    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd < 0) error("Failed to create data socket");

    struct sockaddr_in data_addr;
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(p1 * 256 + p2);
    data_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Assuming localhost for simplicity
  
    if (connect(data_sockfd, (struct sockaddr*)&data_addr, sizeof(data_addr)) < 0) {
        error("Failed to connect data socket");
    }

    ftp_send_command(sockfd, "LIST");
    ftp_receive_response(sockfd, buffer, BUFFER_SIZE);
    printf("Response: %s", buffer);

    // Receive the list of files
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(data_sockfd, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received <= 0) break;
        printf("%s", buffer);
    }

    close(data_sockfd);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return 1;
    }

    const char* hostname = argv[1];
    const char* username = argv[2];
    const char* password = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("Failed to create socket");

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    ftp_receive_response(sockfd, (char*)malloc(BUFFER_SIZE), BUFFER_SIZE);
    ftp_login(sockfd, username, password);
    ftp_list_files(sockfd);

    ftp_send_command(sockfd, "QUIT");
    close(sockfd);
    return 0;
}