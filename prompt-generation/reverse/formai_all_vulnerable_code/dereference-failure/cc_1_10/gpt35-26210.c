//FormAI DATASET v1.0 Category: Simple Web Server ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

void handle_connection(int conn_sock) {
    char buffer[BUFFER_SIZE];
    int n = read(conn_sock, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("read error");
    }
    
    char *response = "HTTP/1.1 200 OK\r\n"
                     "Content-Type: text/plain\r\n"
                     "\r\n"
                     "Hello, World!";
                     
    n = write(conn_sock, response, strlen(response));
    if (n < 0) {
        perror("write error");
    }
    
    close(conn_sock);
}

int main(int argc, char *argv[]) {
    int listen_sock, conn_sock, port;
    socklen_t client_addr_len;
    struct sockaddr_in server_addr, client_addr;
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }
    port = atoi(argv[1]);
    
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("socket error");
        return 1;
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
    
    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind error");
        return 1;
    }
    
    if (listen(listen_sock, 5) < 0) {
        perror("listen error");
        return 1;
    }
    
    while (1) {
        client_addr_len = sizeof(client_addr);
        conn_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &client_addr_len);
        if (conn_sock < 0) {
            perror("accept error");
            continue;
        }
        
        handle_connection(conn_sock);
    }
    
    return 0;
}