//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define LOG_FILE "intrusion_log.txt"

typedef struct {
    int client_socket;
    struct sockaddr_in client_addr;
} client_data_t;

void log_event(const char *event) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Could not open log file");
        return;
    }
    time_t now = time(NULL);
    fprintf(log_file, "[%s] %s\n", ctime(&now), event);
    fclose(log_file);
}

void *handle_client(void *data) {
    client_data_t *client_data = (client_data_t *) data;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_data->client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received from %s:%d: %s\n",
            inet_ntoa(client_data->client_addr.sin_addr), ntohs(client_data->client_addr.sin_port), buffer);

        // Logging the event
        log_event(buffer);

        // Check for suspicious activity (simple keyword match)
        if (strstr(buffer, "attack") != NULL || strstr(buffer, "malicious") != NULL) {
            log_event("Suspicious activity detected!");
            char *response = "Warning: Suspicious activity detected!";
            send(client_data->client_socket, response, strlen(response), 0);
        } else {
            char *response = "Data received.";
            send(client_data->client_socket, response, strlen(response), 0);
        }
    }

    close(client_data->client_socket);
    free(client_data);
    return NULL;
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_socket, 5) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Intrusion Detection System running on port %d\n", PORT);

    while (1) {
        client_data_t *client_data = malloc(sizeof(client_data_t));
        socklen_t addr_len = sizeof(client_data->client_addr);
        client_data->client_socket = accept(server_socket, (struct sockaddr *)&client_data->client_addr, &addr_len);

        if (client_data->client_socket < 0) {
            perror("Accept failed");
            free(client_data);
            continue;
        }

        printf("Connection established with %s:%d\n",
            inet_ntoa(client_data->client_addr.sin_addr), ntohs(client_data->client_addr.sin_port));

        pthread_t client_thread;
        pthread_create(&client_thread, NULL, handle_client, (void *)client_data);
        pthread_detach(client_thread);  // Detach the thread to avoid memory leak
    }

    close(server_socket);
    return 0;
}