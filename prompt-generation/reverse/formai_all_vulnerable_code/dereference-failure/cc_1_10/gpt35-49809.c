//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int connect_to_server(char* hostname, int port);
void send_command(int sockfd, char* command);
void receive_response(int sockfd, char* buffer);

int main(void) {
    char* hostname = "imap.gmail.com";
    int port = 993;
    int sockfd = connect_to_server(hostname, port);
    
    char buffer[BUFFER_SIZE];
    receive_response(sockfd, buffer);
    printf("%s", buffer);
    
    send_command(sockfd, "a LOGIN username password\n");
    receive_response(sockfd, buffer);
    printf("%s", buffer);
    
    send_command(sockfd, "b SELECT INBOX\n");
    receive_response(sockfd, buffer);
    printf("%s", buffer);
    
    send_command(sockfd, "c FETCH 1 BODY[HEADER]\n");
    receive_response(sockfd, buffer);
    printf("%s", buffer);
    
    send_command(sockfd, "d LOGOUT\n");
    receive_response(sockfd, buffer);
    printf("%s", buffer);
    
    close(sockfd);
    return 0;
}

int connect_to_server(char* hostname, int port) {
    int sockfd;
    struct hostent* server;
    struct sockaddr_in serv_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Failed to create socket\n");
        exit(1);
    }
    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("No such host\n");
        exit(1);
    }
    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);
    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Failed to connect to server\n");
        exit(1);
    }
    return sockfd;
}

void send_command(int sockfd, char* command) {
    int n = write(sockfd, command, strlen(command));
    if (n < 0) {
        printf("Failed to send command\n");
        exit(1);
    }
}

void receive_response(int sockfd, char* buffer) {
    bzero(buffer, BUFFER_SIZE);
    int n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        printf("Failed to receive response\n");
        exit(1);
    }
}