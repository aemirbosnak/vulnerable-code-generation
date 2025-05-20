//FormAI DATASET v1.0 Category: Simple Web Server ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if(argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    char buffer[BUFFER_SIZE] = {0};

    const char *response_body = "<html><body><h1>Hello, World!</h1></body></html>\r\n";

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(server_fd == -1) {
        perror("Error: socket creation failed");
        exit(1);
    }

    memset(&address, '0', sizeof(address));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Error: bind failed");
        exit(1);
    }

    if(listen(server_fd, 3) < 0) {
        perror("Error: listen failed");
        exit(1);
    }

    printf("Server started on port %d\n", port);

    while(1) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);

        if(new_socket < 0) {
            perror("Error: accept failed");
            exit(1);
        }

        int read_size = read(new_socket, buffer, BUFFER_SIZE);

        if(read_size < 0) {
            perror("Error: read failed");
            exit(1);
        }

        printf("Client request:\n%s", buffer);

        char response_header[BUFFER_SIZE] = {0};

        sprintf(response_header, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\n\r\n", strlen(response_body));

        send(new_socket, response_header, strlen(response_header), 0);
        send(new_socket, response_body, strlen(response_body), 0);

        close(new_socket);
    }

    return 0;
}