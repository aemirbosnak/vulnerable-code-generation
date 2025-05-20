//FormAI DATASET v1.0 Category: Client Server Application ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void error(char* msg){
    perror(msg);
    exit(1);
}

int main(int argc, char** argv){
    if(argc < 2){
        printf("Usage: %s PORT\n", argv[0]);
        exit(1);
    }

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd < 0)
        error("Error creating socket!");

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(atoi(argv[1]));

    if(bind(server_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0)
        error("Error binding the socket!");

    if(listen(server_fd, 5) < 0)
        error("Error listening to the socket!");

    printf("Server started at port %s\n", argv[1]);

    int client_fd;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    while(1){
        client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
        if(client_fd < 0)
            error("Error accepting client connection!");

        printf("Client %s:%d connected\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        char message[1024];
        memset(message, 0, 1024);

        if(read(client_fd, message, 1024) < 0)
            error("Error reading from socket!");

        printf("Received message: %s\n", message);

        char response[1024];
        sprintf(response, "Hello %s:%d!\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        if(write(client_fd, response, strlen(response)) < 0)
            error("Error writing to socket!");

        printf("Sent response: %s", response);

        close(client_fd);
        printf("Client %s:%d disconnected\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    }

    close(server_fd);

    return 0;
}