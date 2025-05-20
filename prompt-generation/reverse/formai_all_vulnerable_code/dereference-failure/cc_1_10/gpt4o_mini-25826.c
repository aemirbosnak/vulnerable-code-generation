//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CONNECTIONS 5
#define MAX_RECORDS 100

typedef struct {
    int id;
    char data[256];
} Record;

Record database[MAX_RECORDS];
int record_count = 0;

pthread_mutex_t lock;

void *handle_client(void *new_socket) {
    int sock = *(int *)new_socket;
    free(new_socket);
    char buffer[256];
    int n;

    while ((n = recv(sock, buffer, sizeof(buffer)-1, 0)) > 0) {
        buffer[n] = '\0';
        char command[10];
        sscanf(buffer, "%s", command);

        if (strcmp(command, "ADD") == 0) {
            pthread_mutex_lock(&lock);
            if (record_count < MAX_RECORDS) {
                Record new_record;
                sscanf(buffer + 4, "%d %[^\n]", &new_record.id, new_record.data);
                database[record_count++] = new_record;
                sprintf(buffer, "Record added. Current count: %d", record_count);
            } else {
                sprintf(buffer, "Database Full!");
            }
            pthread_mutex_unlock(&lock);
        } else if (strcmp(command, "GET") == 0) {
            int id;
            sscanf(buffer + 4, "%d", &id);
            pthread_mutex_lock(&lock);
            int found = 0;
            for (int i = 0; i < record_count; i++) {
                if (database[i].id == id) {
                    sprintf(buffer, "Record %d: %s", database[i].id, database[i].data);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                sprintf(buffer, "Record not found.");
            }
            pthread_mutex_unlock(&lock);
        } else {
            sprintf(buffer, "Invalid command.");
        }

        send(sock, buffer, strlen(buffer), 0);
    }

    close(sock);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if (pthread_mutex_init(&lock, NULL) != 0) {
        perror("Mutex initialization failed");
        return 1;
    }

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        pthread_t thread_id;
        int *new_sock = malloc(1);
        *new_sock = new_socket;
        pthread_create(&thread_id, NULL, handle_client, (void*)new_sock);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}