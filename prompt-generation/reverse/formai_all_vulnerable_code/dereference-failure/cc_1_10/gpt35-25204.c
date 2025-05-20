//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX_BUFFER_SIZE 512

int connect_to_server(char *hostname, char *port) {
    struct addrinfo hints, *res;
    int sockfd;
    
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    
    if (getaddrinfo(hostname, port, &hints, &res) != 0) {
        perror("getaddrinfo");
        exit(1);
    }
    
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }
    
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("connect");
        exit(1);
    }
    
    freeaddrinfo(res);
    return sockfd;
}

void send_command(int sockfd, char *command) {
    int bytes_sent = send(sockfd, command, strlen(command), 0);
    if (bytes_sent == -1) {
        perror("send");
        exit(1);
    }
}

char *receive_response(int sockfd) {
    char recv_buffer[MAX_BUFFER_SIZE];
    int bytes_received = recv(sockfd, recv_buffer, MAX_BUFFER_SIZE - 1, 0);
    if (bytes_received == -1) {
        perror("recv");
        exit(1);
    }
    recv_buffer[bytes_received] = '\0';
    return strdup(recv_buffer);
}

int main(int argc, char **argv) {
    char *hostname = "imap.gmail.com";
    char *port = "993";
    char *username = "example@gmail.com";
    char *password = "examplepassword";
    
    int sockfd = connect_to_server(hostname, port);
    
    printf("Connected to server.\n");
    
    char *response = receive_response(sockfd);
    printf("Server says:\n%s\n", response);
    free(response);
    
    send_command(sockfd, "a001 LOGIN example@gmail.com examplepassword\n");
    
    response = receive_response(sockfd);
    printf("Server says:\n%s\n", response);
    free(response);
    
    send_command(sockfd, "a002 LIST \"\" \"*\"\n");
    
    response = receive_response(sockfd);
    printf("Server says:\n%s\n", response);
    free(response);
    
    send_command(sockfd, "a003 LOGOUT\n");
    
    response = receive_response(sockfd);
    printf("Server says:\n%s\n", response);
    free(response);
    
    close(sockfd);
    
    return 0;
}