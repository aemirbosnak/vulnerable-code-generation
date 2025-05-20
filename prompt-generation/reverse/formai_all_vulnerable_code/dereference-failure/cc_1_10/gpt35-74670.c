//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

// function to check POP3 server response
void check_response(char* response) {
    char* code_str = strtok(response, " ");
    int code = atoi(code_str);
    if(code >= 400) {
        printf("Server Error: %s\n", response);
        exit(1);
    }
}

int main(int argc, char** argv) {
    char* server_ip = argv[1];
    int port = atoi(argv[2]);
    char* username = argv[3];
    char* password = argv[4];

    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // connect to server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if(connect(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    char buf[BUF_SIZE];

    // get server greeting
    recv(sock, buf, BUF_SIZE, 0);
    printf("%s\n", buf);

    // send username
    sprintf(buf, "USER %s\r\n", username);
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUF_SIZE, 0);
    check_response(buf);

    // send password
    sprintf(buf, "PASS %s\r\n", password);
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUF_SIZE, 0);
    check_response(buf);

    // send list command to get number of messages and their sizes
    send(sock, "LIST\r\n", 6, 0);
    recv(sock, buf, BUF_SIZE, 0);
    check_response(buf);

    printf("%s", buf);

    // extract number of messages
    strtok(buf, "\n"); // skip first line
    char* line = strtok(NULL, "\n");
    int num_messages = atoi(strtok(line, " "));

    // print message information
    for(int i = 0; i < num_messages; i++) {
        recv(sock, buf, BUF_SIZE, 0);
        printf("%s", buf);
    }

    close(sock);
    return 0;
}