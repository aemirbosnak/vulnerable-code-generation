//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define MAX_CONNECTIONS 100
#define PORT 8080

// Structure to hold client information
typedef struct {
    int sock;
    struct sockaddr_in addr;
} ClientInfo;

// Function to log suspicious activity
void log_suspicious_activity(const char *message) {
    FILE *log_file = fopen("intrusion_log.txt", "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        return;
    }

    time_t now;
    time(&now);
    fprintf(log_file, "%s - %s\n", ctime(&now), message);
    fclose(log_file);
}

// Function to handle each client connection
void *handle_client(void *arg) {
    ClientInfo *client = (ClientInfo *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    printf("Client connected: %s:%d\n", inet_ntoa(client->addr.sin_addr), ntohs(client->addr.sin_port));

    // Communication with client
    while ((bytes_received = recv(client->sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the received string
        printf("Received from %s:%d - %s\n", inet_ntoa(client->addr.sin_addr), ntohs(client->addr.sin_port), buffer);

        // Basic IDS - looking for suspicious commands
        if (strstr(buffer, "DROP TABLE") || strstr(buffer, "DELETE") || strstr(buffer, "SHUTDOWN")) {
            log_suspicious_activity(buffer);
            char *warning_message = "Warning! Suspicious activity detected.";
            send(client->sock, warning_message, strlen(warning_message), 0);
        } else {
            char *response = "Message received.";
            send(client->sock, response, strlen(response), 0);
        }
    }

    printf("Client disconnected: %s:%d\n", inet_ntoa(client->addr.sin_addr), ntohs(client->addr.sin_port));
    close(client->sock);
    free(client);
    return NULL;
}

// Main function
int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    
    // Create socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Listen on any interface
    server_addr.sin_port = htons(PORT); // Set port number

    // Bind socket to port
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(server_sock, MAX_CONNECTIONS);
    printf("Intrusion Detection System running on port %d...\n", PORT);

    // Accepting client connections
    while (1) {
        ClientInfo *client = malloc(sizeof(ClientInfo));
        client_sock = accept(server_sock, (struct sockaddr *)&client->addr, &client_addr_len);
        if (client_sock < 0) {
            perror("Error accepting connection");
            free(client);
            continue;
        }
        client->sock = client_sock;

        // Create a new thread for each client
        pthread_t thread;
        if (pthread_create(&thread, NULL, handle_client, client) != 0) {
            perror("Error creating thread");
            close(client_sock);
            free(client);
        }
        pthread_detach(thread);
    }

    // Close the server socket
    close(server_sock);
    return 0;
}