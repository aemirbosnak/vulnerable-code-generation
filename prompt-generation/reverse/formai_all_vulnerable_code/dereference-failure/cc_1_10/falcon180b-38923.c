//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int listen_fd, client_fd, sock_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[1024];
    int n;
    
    if (argc!= 3) {
        printf("Usage: %s <IP> <Port>\n", argv[0]);
        return -1;
    }
    
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        printf("Error creating socket\n");
        return -1;
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));
    
    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return -1;
    }
    
    if (listen(listen_fd, 5) == -1) {
        printf("Error listening on socket\n");
        return -1;
    }
    
    while (1) {
        addr_size = sizeof(client_addr);
        client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addr_size);
        if (client_fd == -1) {
            printf("Error accepting connection\n");
            continue;
        }
        
        sock_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (sock_fd == -1) {
            printf("Error creating socket\n");
            close(client_fd);
            continue;
        }
        
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        server_addr.sin_port = htons(atoi(argv[2]));
        
        if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            printf("Error connecting to server\n");
            close(client_fd);
            close(sock_fd);
            continue;
        }
        
        while ((n = recv(client_fd, buffer, sizeof(buffer), 0)) > 0) {
            send(sock_fd, buffer, n, 0);
        }
        
        close(client_fd);
        close(sock_fd);
    }
    
    return 0;
}