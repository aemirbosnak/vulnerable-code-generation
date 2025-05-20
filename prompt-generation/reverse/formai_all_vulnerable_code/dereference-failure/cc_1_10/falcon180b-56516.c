//Falcon-180B DATASET v1.0 Category: System event logger ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_DATA 1000

typedef struct {
    int sock;
    char ip[16];
    char data[MAX_DATA];
} client_t;

void log_event(char *event) {
    FILE *log_file;
    time_t now = time(NULL);
    char filename[20];

    sprintf(filename, "log_%ld.txt", now);
    log_file = fopen(filename, "a+");

    if (log_file!= NULL) {
        fprintf(log_file, "%s\n", event);
        fclose(log_file);
    }
}

void handle_client(client_t *client) {
    char buffer[MAX_DATA];

    while (1) {
        memset(buffer, 0, MAX_DATA);
        int bytes_received = recv(client->sock, buffer, MAX_DATA, 0);

        if (bytes_received <= 0) {
            close(client->sock);
            free(client);
            break;
        }

        log_event(buffer);
        send(client->sock, buffer, strlen(buffer), 0);
    }
}

int main() {
    int server_sock;
    int opt = 1;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t addr_size;
    int client_sock;
    client_t *client_list[MAX_CLIENTS];
    int num_clients = 0;

    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        addr_size = sizeof(client_addr);
        if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_size)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        inet_ntop(AF_INET, &client_addr.sin_addr, client_list[num_clients]->ip, 16);
        client_list[num_clients]->sock = client_sock;
        num_clients++;

        if (num_clients == MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
        } else {
            printf("New client connected: %s\n", client_list[num_clients - 1]->ip);
        }

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void *)handle_client, (void *)client_list[num_clients - 1]);
    }

    return 0;
}