//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

void* handle_client(void* socket_desc) {
    int sock = *(int*)socket_desc;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int read_size = recv(sock, buffer, sizeof(buffer) - 1, 0);
        if (read_size <= 0) {
            perror("Client disconnected");
            break;
        }

        printf("Received request:\n%s\n", buffer);

        char *response_headers = "HTTP/1.1 200 OK\r\n"
                                  "Content-Type: text/html\r\n"
                                  "Connection: close\r\n\r\n";
        
        char *response_body = "<html><body><h1>Hello from C Simple Web Server!</h1></body></html>";
        send(sock, response_headers, strlen(response_headers), 0);
        send(sock, response_body, strlen(response_body), 0);
    }

    close(sock);
    free(socket_desc);
    return NULL;
}

int main(int argc, char* argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    pthread_t thread_id;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server is running on http://127.0.0.1:%d\n", PORT);

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            perror("Accept failed");
            continue;
        }

        printf("New connection accepted\n");

        int* new_sock = malloc(1);
        *new_sock = new_socket;

        if (pthread_create(&thread_id, NULL, handle_client, (void*)new_sock) != 0) {
            perror("Failed to create thread");
            close(new_socket);
            free(new_sock);
        }

        pthread_detach(thread_id);
    }

    close(server_fd);
    return 0;
}