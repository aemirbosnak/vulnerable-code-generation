//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

struct client_data {
    int sock;
    char ip[16];
    char message[BUFFER_SIZE];
};

void *handle_client(void *arg) {
    struct client_data *client_data = (struct client_data *) arg;
    char response[BUFFER_SIZE];
    strcpy(response, "Server response: ");
    strcat(response, client_data->message);

    send(client_data->sock, response, strlen(response), 0);
    close(client_data->sock);
    free(client_data);

    return NULL;
}

int main() {
    int listen_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    struct client_data *client_data;

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(listen_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_sock, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        socklen_t client_size = sizeof(client_addr);
        client_sock = accept(listen_sock, (struct sockaddr *) &client_addr, &client_size);

        if (client_sock == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        inet_ntop(AF_INET, &client_addr.sin_addr, client_data->ip, sizeof(client_data->ip));
        strcpy(client_data->message, "Client message: ");

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) client_data);
        pthread_detach(thread_id);
    }

    close(listen_sock);
    return 0;
}