//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_NODES 5
#define BUFFER_SIZE 1024

typedef struct {
    char name[50];
    int value;
} Record;

typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
} Node;

Record database[MAX_NODES];
int db_count = 0;

void* handle_client(void* arg) {
    Node* node = (Node*)arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_read = read(node->socket, buffer, BUFFER_SIZE);
        if (bytes_read <= 0) {
            printf("Client disconnected.\n");
            close(node->socket);
            free(node);
            return NULL;
        }
        
        // Interpret the message as an instruction
        if (strncmp(buffer, "INSERT", 6) == 0) {
            if (db_count < MAX_NODES) {
                sscanf(buffer + 7, "%s %d", database[db_count].name, &database[db_count].value);
                db_count++;
                write(node->socket, "Record inserted\n", 17);
            } else {
                write(node->socket, "Database full\n", 15);
            }
        } else if (strncmp(buffer, "RETRIEVE", 8) == 0) {
            char name[50];
            sscanf(buffer + 9, "%s", name);
            for (int i = 0; i < db_count; i++) {
                if (strcmp(database[i].name, name) == 0) {
                    sprintf(buffer, "Record found: %s %d\n", database[i].name, database[i].value);
                    write(node->socket, buffer, strlen(buffer));
                    break;
                }
            }
            write(node->socket, "Record not found\n", 17);
        } else {
            write(node->socket, "Unknown command\n", 16);
        }
    }
}

int main() {
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Distributed Database Server running on port %d...\n", PORT);

    while (1) {
        Node* node = malloc(sizeof(Node));
        node->addr_len = sizeof(node->address);
        node->socket = accept(server_fd, (struct sockaddr*)&node->address, (socklen_t*)&node->addr_len);
        if (node->socket < 0) {
            perror("Accept failed");
            free(node);
            continue;
        }

        printf("New connection established...\n");
        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, node);
        pthread_detach(tid);
    }

    close(server_fd);
    return 0;
}