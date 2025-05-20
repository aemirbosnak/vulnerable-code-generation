//FormAI DATASET v1.0 Category: Networking ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void send_message(int socket, char* message) {
    if(write(socket, message, strlen(message)) < 0)
        perror("Failed to send message");
}

void connect_to_server(char* server_ip, int port) {
    int socket_desc;
    struct sockaddr_in server;
     
    // create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        perror("Could not create socket");
        return;
    }
     
    // set server address and port
    server.sin_addr.s_addr = inet_addr(server_ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    
    // connect to server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Could not connect to server");
        return;
    }
    
    // send message to server
    send_message(socket_desc, "Hello, server!");
     
    // receive message from server
    char server_reply[2000];
    if(read(socket_desc, server_reply, 2000) < 0) {
        perror("Failed to receive message from server");
        return;
    }
     
    printf("Server replied: %s\n", server_reply);
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Usage: %s <server_ip> <port>\n", argv[0]);
        return 1;
    }
    
    int port = atoi(argv[2]);
    if(port < 1024 || port > 65535) {
        printf("Invalid port number. Enter a value between 1024 and 65535.\n");
        return 1;
    }
    
    connect_to_server(argv[1], port);
    
    return 0;
}