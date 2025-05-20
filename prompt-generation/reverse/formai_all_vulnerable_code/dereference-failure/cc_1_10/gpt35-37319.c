//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_RECV_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int socket_desc;
    struct sockaddr_in server_addr;
    char *server_ip;
    int server_port;
    char *http_req = "GET / HTTP/1.0\r\n\r\n";
    char server_reply[MAX_RECV_BUF_SIZE];
    
    if (argc != 3) {
        printf("Usage: httpclient <server_ip> <server_port>\n");
        return 1;
    }
    
    server_ip = argv[1];
    server_port = atoi(argv[2]);
    
    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc < 0) {
        printf("Could not create socket\n");
        return 1;
    }
    
    // Prepare server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);
    
    // Connect to server
    if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Could not connect to server\n");
        return 1;
    }
    
    // Send HTTP request to server
    if (send(socket_desc, http_req, strlen(http_req), 0) < 0) {
        printf("Could not send HTTP request\n");
        return 1;
    }
    
    // Receive server response
    int recv_size;
    while ((recv_size = recv(socket_desc, server_reply, MAX_RECV_BUF_SIZE, 0)) > 0) {
        server_reply[recv_size] = '\0'; // Null-terminate the received string
        printf("%s", server_reply);
    }
    
    if (recv_size < 0) {
        printf("Error while receiving server response\n");
        return 1;
    }
    
    // Close socket
    close(socket_desc);
    
    return 0;
}