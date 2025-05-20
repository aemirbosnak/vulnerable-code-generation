//Falcon-180B DATASET v1.0 Category: Password management ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_PASSWORD_LENGTH 20

struct client_data {
    int sock;
    char username[20];
    char password[MAX_PASSWORD_LENGTH];
};

void *handle_client(void *arg) {
    struct client_data *client_data = (struct client_data *) arg;
    char buffer[1024];

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_data->sock, buffer, sizeof(buffer), 0);

        if (bytes_received <= 0) {
            break;
        }

        char *username = strtok(buffer, ":");
        char *password = strtok(NULL, ":");

        if (username == NULL || password == NULL) {
            send(client_data->sock, "Invalid input. Please try again.\n", 37, 0);
            continue;
        }

        strcpy(client_data->username, username);
        strcpy(client_data->password, password);

        break;
    }

    close(client_data->sock);
    free(arg);
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_sock, MAX_CLIENTS);

    pthread_t thread_id[MAX_CLIENTS];
    struct client_data client_data[MAX_CLIENTS];

    for (int i = 0; i < MAX_CLIENTS; i++) {
        client_data[i].sock = accept(server_sock, NULL, NULL);
        pthread_create(&thread_id[i], NULL, handle_client, (void *) &client_data[i]);
    }

    for (int i = 0; i < MAX_CLIENTS; i++) {
        pthread_join(thread_id[i], NULL);
    }

    close(server_sock);

    return 0;
}