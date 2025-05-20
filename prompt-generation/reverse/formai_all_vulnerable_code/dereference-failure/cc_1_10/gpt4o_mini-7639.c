//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

typedef struct {
    char *hostname;
    int port;
    char *username;
    char *password;
} ftp_config;

void *ftp_command(void *arg);
void error_handling(const char *msg);
void send_command(int sockfd, const char *cmd);
void receive_response(int sockfd);
void list_files(int sockfd);
void download_file(int sockfd, const char *filename);
void upload_file(int sockfd, const char *filename);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <port> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ftp_config cfg;
    cfg.hostname = argv[1];
    cfg.port = atoi(argv[2]);
    cfg.username = argv[3];
    cfg.password = argv[4];

    pthread_t thread;
    if (pthread_create(&thread, NULL, ftp_command, (void *)&cfg) != 0) {
        error_handling("Error creating thread");
    }

    pthread_join(thread, NULL);
    return 0;
}

void *ftp_command(void *arg) {
    ftp_config *cfg = (ftp_config *)arg;
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error_handling("Socket creation failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(cfg->port);
    if (inet_pton(AF_INET, cfg->hostname, &server_addr.sin_addr) <= 0) {
        error_handling("Invalid address/ Address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("Connection Failed");
    }

    receive_response(sockfd);

    char command[100];

    snprintf(command, sizeof(command), "USER %s\r\n", cfg->username);
    send_command(sockfd, command);
    receive_response(sockfd);

    snprintf(command, sizeof(command), "PASS %s\r\n", cfg->password);
    send_command(sockfd, command);
    receive_response(sockfd);

    list_files(sockfd);
    download_file(sockfd, "sample.txt");
    upload_file(sockfd, "upload.txt");

    snprintf(command, sizeof(command), "QUIT\r\n");
    send_command(sockfd, command);
    receive_response(sockfd);

    close(sockfd);
    return NULL;
}

void error_handling(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
}

void receive_response(int sockfd) {
    char response[BUFFER_SIZE];
    int bytes_received;

    bytes_received = recv(sockfd, response, sizeof(response) - 1, 0);
    response[bytes_received] = '\0';
    printf("Response: %s", response);
}

void list_files(int sockfd) {
    send_command(sockfd, "PASV\r\n");
    receive_response(sockfd);

    // Stub for passive mode response handling
    // Logic to handle PASV response would go here

    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd);
}

void download_file(int sockfd, const char *filename) {
    send_command(sockfd, "RETR ");
    send(sockfd, filename, strlen(filename), 0);
    send(sockfd, "\r\n", 2, 0);
    receive_response(sockfd);

    // Stub for file downloading logic
    // Logic to retrieve the file data from server would go here
}

void upload_file(int sockfd, const char *filename) {
    send_command(sockfd, "STOR ");
    send(sockfd, filename, strlen(filename), 0);
    send(sockfd, "\r\n", 2, 0);
    receive_response(sockfd);

    // Stub for file uploading logic
    // Logic to send file data to server would go here
}