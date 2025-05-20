//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_MSG_LEN 100

int server_fd, client_fd1, client_fd2;
char message[MAX_MSG_LEN], buffer[MAX_MSG_LEN];

void handle_client(int client_fd) {
    while(1) {
        memset(buffer, '\0', MAX_MSG_LEN);
        memset(message, '\0', MAX_MSG_LEN);
        memset(buffer, '\0', MAX_MSG_LEN);
        
        read(client_fd, buffer, MAX_MSG_LEN);
        
        if(strstr(buffer, "exit")) {
            close(client_fd);
            break;
        }
        
        write(STDOUT_FILENO, buffer, strlen(buffer));
        printf("> ");
        fgets(message, MAX_MSG_LEN, stdin);
        write(client_fd, message, strlen(message));
    }
}

int main(int argc, char *argv[]) {
    int opt;
    int client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (server_fd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));
    
    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    while(1) {
        client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_addr_len);
        
        if (client_fd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        if (fork() == 0) {
            handle_client(client_fd);
            exit(0);
        }
    }
    
    return 0;
}