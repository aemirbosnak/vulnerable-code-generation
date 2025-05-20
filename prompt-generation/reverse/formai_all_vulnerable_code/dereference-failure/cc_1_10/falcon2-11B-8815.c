//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080

void* server(void* arg) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation error");
        return NULL;
    }

    struct sockaddr_in server_address;
    bzero((char*) &server_address, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    int result = bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    if (result < 0) {
        perror("Bind failed");
        return NULL;
    }

    listen(server_socket, 3);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        char buffer[1024];
        bzero(buffer, sizeof(buffer));

        while (1) {
            ssize_t read_size = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
            if (read_size < 0) {
                perror("Receive failed");
                close(client_socket);
                break;
            }

            if (read_size == 0) {
                close(client_socket);
                break;
            }

            buffer[read_size] = '\0';
            printf("%s", buffer);
            send(client_socket, buffer, strlen(buffer), 0);
        }

        close(client_socket);
    }

    close(server_socket);
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int server_socket = atoi(argv[1]);
    if (server_socket <= 0 || server_socket > 65535) {
        printf("Invalid port number: %d\n", server_socket);
        return 1;
    }

    pthread_t server_thread;
    if (pthread_create(&server_thread, NULL, server, NULL)) {
        perror("Thread creation failed");
        return 1;
    }

    char buffer[1024];
    bzero(buffer, sizeof(buffer));

    while (1) {
        ssize_t write_size = send(server_socket, buffer, sizeof(buffer) - 1, 0);
        if (write_size < 0) {
            perror("Send failed");
            break;
        }

        if (write_size == 0) {
            break;
        }

        buffer[write_size] = '\0';
        printf("%s", buffer);
    }

    close(server_socket);
    return 0;
}