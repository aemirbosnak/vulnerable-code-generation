//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define RESPONSE_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int connect_to_ftp(const char *hostname, int port) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *) &serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    return sockfd;
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
}

void receive_response(int sockfd, char *buffer, int buffer_size) {
    memset(buffer, 0, buffer_size);
    recv(sockfd, buffer, buffer_size - 1, 0);
}

void login(int sockfd, const char *username, const char *password) {
    char buffer[RESPONSE_SIZE];

    send_command(sockfd, "USER ");
    send_command(sockfd, username);
    send_command(sockfd, "\r\n");
    receive_response(sockfd, buffer, RESPONSE_SIZE);
    printf("Server response: %s\n", buffer);

    send_command(sockfd, "PASS ");
    send_command(sockfd, password);
    send_command(sockfd, "\r\n");
    receive_response(sockfd, buffer, RESPONSE_SIZE);
    printf("Server response: %s\n", buffer);
}

void list_files(int sockfd) {
    char buffer[RESPONSE_SIZE];

    send_command(sockfd, "PASV\r\n");
    receive_response(sockfd, buffer, RESPONSE_SIZE);
    printf("Server response: %s\n", buffer);

    // Extract port for data connection
    int p1, p2;
    sscanf(strrchr(buffer, ',') + 1, "%d,%d", &p1, &p2);
    int data_port = p1 * 256 + p2;

    // Creating data socket
    int data_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in data_addr;
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_addr.s_addr = INADDR_ANY;
    data_addr.sin_port = htons(data_port);

    if (bind(data_sock, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) 
        error("ERROR binding data socket");

    listen(data_sock, 1);
    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd, buffer, RESPONSE_SIZE);
    printf("Server response: %s\n", buffer);

    // Accepting the data connection
    int new_sock = accept(data_sock, NULL, NULL);
    if (new_sock < 0)
        error("ERROR on accept");

    // Receive file list
    memset(buffer, 0, RESPONSE_SIZE);
    while (recv(new_sock, buffer, RESPONSE_SIZE - 1, 0) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, RESPONSE_SIZE);
    }

    close(new_sock);
    close(data_sock);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    
    int sockfd = connect_to_ftp(hostname, 21);
    char buffer[RESPONSE_SIZE];

    receive_response(sockfd, buffer, RESPONSE_SIZE);
    printf("Server response: %s\n", buffer);

    login(sockfd, username, password);
    list_files(sockfd);

    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd, buffer, RESPONSE_SIZE);
    printf("Server response: %s\n", buffer);

    close(sockfd);
    return 0;
}