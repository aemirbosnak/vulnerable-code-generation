//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define FILE_BUF_SIZE 4096

void send_file(int client_sockfd, char* file_path){
    FILE* fp = fopen(file_path, "r");
    if(fp == NULL){
        fprintf(stderr, "Cannot open file: %s\n", file_path);
        exit(1);
    }

    char buf[FILE_BUF_SIZE];
    int n_read;

    while((n_read = fread(buf, 1, FILE_BUF_SIZE, fp)) > 0){
        if(send(client_sockfd, buf, n_read, 0) == -1){
            fprintf(stderr, "Failed to send file: %s\n", file_path);
            exit(1);
        }
    }

    fclose(fp);
}

int main(){
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sockfd == -1){
        fprintf(stderr, "Failed to create socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    if(bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1){
        fprintf(stderr, "Failed to bind to port 8080\n");
        exit(1);
    }

    if(listen(server_sockfd, 5) == -1){
        fprintf(stderr, "Failed to listen for incoming connections\n");
        exit(1);
    }

    printf("Server listening on port 8080\n");

    while(1){
        struct sockaddr_in client_addr;
        int client_sockfd;
        socklen_t client_len = sizeof(client_addr);

        client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_addr, &client_len);
        if(client_sockfd == -1){
            fprintf(stderr, "Failed to accept incoming connection\n");
            continue;
        }

        char req_buf[BUF_SIZE];
        int n_recv = recv(client_sockfd, req_buf, BUF_SIZE, 0);
        if(n_recv == -1){
            fprintf(stderr, "Failed to receive request\n");
            close(client_sockfd);
            continue;
        }

        char response[BUF_SIZE];
        memset(response, 0, BUF_SIZE);

        if(strncmp(req_buf, "GET", 3) == 0){
            char* file_path = strtok(req_buf + 4, " \r\n");
            send_file(client_sockfd, file_path);
            printf("Sent file: %s\n", file_path);

            close(client_sockfd);
            continue;
        }

        strcpy(response, "HTTP/1.1 501 Not Implemented\r\n");
        send(client_sockfd, response, strlen(response), 0);
        close(client_sockfd);
    }

    close(server_sockfd);
    return 0;
}