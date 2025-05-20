//FormAI DATASET v1.0 Category: Networking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>

#define PORT 8080
#define MAX_PENDING_CONNECTIONS 10

void *handle_client_request(void *arg) {
    int client_sock = *((int *) arg);
    char buffer[1024] = {0};
    char response[1024] = {0};
    int valread = read(client_sock, buffer, 1024);
    sprintf(response, "The square of the number you sent is: %d", atoi(buffer) * atoi(buffer));
    send(client_sock, response, strlen(response), 0);
    close(client_sock);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int address_len = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_PENDING_CONNECTIONS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &address_len)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        printf("Connection accepted from: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        pthread_t tid;
        int *client_sock_ptr = malloc(sizeof(int));
        *client_sock_ptr = new_socket;

        if (pthread_create(&tid, NULL, handle_client_request, client_sock_ptr)) {
            perror("Error in thread creation");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}