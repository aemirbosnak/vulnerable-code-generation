//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_SIZE 1024

int receive_server_response(int sockfd);
void send_command_to_server(int sockfd, char* command);

int main(int argc, char* argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *server;
    char buffer[MAX_SIZE];

    if (argc != 3) {
        printf("Usage: pop3client hostname port\n");
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Unable to create socket\n");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Unable to resolve host\n");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    memcpy(&servaddr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
        printf("Unable to connect to server\n");
        exit(EXIT_FAILURE);
    }

    receive_server_response(sockfd);
    send_command_to_server(sockfd, "USER john@example.com\r\n");
    receive_server_response(sockfd);
    send_command_to_server(sockfd, "PASS mypassword\r\n");
    receive_server_response(sockfd);
    send_command_to_server(sockfd, "STAT\r\n");
    receive_server_response(sockfd);
    send_command_to_server(sockfd, "LIST\r\n");
    receive_server_response(sockfd);
    send_command_to_server(sockfd, "RETR 1\r\n");
    receive_server_response(sockfd);
    send_command_to_server(sockfd, "QUIT\r\n");
    receive_server_response(sockfd);

    close(sockfd);
    exit(EXIT_SUCCESS);
}

int receive_server_response(int sockfd) {
    char buffer[MAX_SIZE];
    memset(buffer, 0, MAX_SIZE);
    read(sockfd, buffer, MAX_SIZE);
    printf("%s", buffer);
    return strlen(buffer);
}

void send_command_to_server(int sockfd, char* command) {
    write(sockfd, command, strlen(command));
}