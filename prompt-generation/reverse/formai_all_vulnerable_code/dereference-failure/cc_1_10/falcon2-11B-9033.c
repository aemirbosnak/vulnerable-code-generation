//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    
    int port = atoi(argv[1]);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }
    
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
    
    int bind_result = bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (bind_result < 0) {
        perror("bind");
        exit(1);
    }
    
    listen(sock, 5);
    
    int client_sock = accept(sock, NULL, NULL);
    if (client_sock < 0) {
        perror("accept");
        exit(1);
    }
    
    char buffer[1024];
    while (1) {
        int num_read = recv(client_sock, buffer, sizeof(buffer), 0);
        if (num_read <= 0) {
            if (num_read < 0) {
                perror("recv");
                exit(1);
            }
            break;
        }
        
        printf("Received: %s\n", buffer);
        send(client_sock, "HTTP/1.1 200 OK\r\n\r\n", 25, 0);
        
        char *response = "Hello, world!\r\n";
        int num_sent = send(client_sock, response, strlen(response), 0);
        if (num_sent <= 0) {
            if (num_sent < 0) {
                perror("send");
                exit(1);
            }
            break;
        }
    }
    
    close(client_sock);
    close(sock);
    
    return 0;
}