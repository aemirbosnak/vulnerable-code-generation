//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096
#define PORT 21
#define USERNAME "anonymous"
#define PASSWORD "ftp@example.com"

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        error("ERROR sending command");
    }
}

void receive_response(int sockfd, char *response, size_t size) {
    memset(response, 0, size);
    if (recv(sockfd, response, size - 1, 0) < 0) {
        error("ERROR receiving response");
    }
}

void connect_to_server(const char *hostname) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    host = gethostbyname(hostname);
    if (host == NULL) {
        error("ERROR, no such host");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    char response[BUFFER_SIZE];

    receive_response(sockfd, response, sizeof(response));
    printf("Server response: %s", response);

    char cmd[BUFFER_SIZE];

    // Sending USER command
    snprintf(cmd, sizeof(cmd), "USER %s\r\n", USERNAME);
    send_command(sockfd, cmd);
    receive_response(sockfd, response, sizeof(response));
    printf("Server response: %s", response);

    // Sending PASS command
    snprintf(cmd, sizeof(cmd), "PASS %s\r\n", PASSWORD);
    send_command(sockfd, cmd);
    receive_response(sockfd, response, sizeof(response));
    printf("Server response: %s", response);

    // Sending PASV command to enter passive mode
    send_command(sockfd, "PASV\r\n");
    receive_response(sockfd, response, sizeof(response));
    printf("Server response: %s", response);

    // Parsing the IP and port from PASV response
    int p1, p2, p3, p4, p5, p6;
    sscanf(strstr(response, "(") + 1, "%d,%d,%d,%d,%d,%d", &p1, &p2, &p3, &p4, &p5, &p6);
    int data_port = (p5 * 256) + p6;

    // Creating data socket
    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd < 0) {
        error("ERROR opening data socket");
    }

    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_addr.s_addr = inet_addr((char[]){p1, p2, p3, p4});
    data_addr.sin_port = htons(data_port);

    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        error("ERROR connecting to data port");
    }

    // Sending LIST command to list files in the current directory
    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd, response, sizeof(response));
    printf("Server response: %s", response);

    // Receiving file list
    memset(response, 0, sizeof(response));
    while (recv(data_sockfd, response, sizeof(response) - 1, 0) > 0) {
        printf("%s", response);
        memset(response, 0, sizeof(response));
    }

    close(data_sockfd);

    // Sending QUIT command to end session
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd, response, sizeof(response));
    printf("Server response: %s", response);

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    connect_to_server(argv[1]);
    
    return 0;
}