//MISTRAL-7B DATASET v1.0 Category: Simple Web Server ; Style: standalone
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

bool init_socket(int *socket_desc) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket failed");
        return false;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        free(sock);
        return false;
    }

    if (listen(sock, 3) < 0) {
        perror("listen");
        free(sock);
        return false;
    }

    *socket_desc = sock;
    return true;
}

void handle_client(int new_socket, char response[]) {
    int read_size;
    char client_message[BUFFER_SIZE];

    send(new_socket, "HTTP/1.1 200 OK\r\n\r\n", 17, 0);

    while ((read_size = recv(new_socket, client_message, BUFFER_SIZE, 0)) > 0) {
        for (int i = 0; i < read_size; ++i) {
            response[i] = client_message[i];
        }

        response[read_size] = '\0';

        for (int i = 0; i < strlen(response); ++i) {
            if (response[i] == '\r') {
                response[i] = '\0';
                send(new_socket, response, i, 0);
                break;
            }
        }

        bzero(client_message, BUFFER_SIZE);
        bzero(response, BUFFER_SIZE);
    }

    if (read_size == 0) {
        puts("Client disconnected");
        fclose(new_socket);
    } else if (read_size == -1) {
        perror("recv failed");
    }
}

int main() {
    int socket_desc, new_socket;

    if (!init_socket(&socket_desc)) {
        printf("Failed to initialize socket\n");
        return -1;
    }

    puts("Waiting for incoming connections...");

    while ((new_socket = accept(socket_desc, NULL, NULL)) < 0) {
        perror("accept failed");
    }

    char response[BUFFER_SIZE];

    handle_client(new_socket, response);

    free(new_socket);
    free(socket_desc);

    return 0;
}