//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in client_addr;
} client_t;

void *handle_client(void *arg);
void log_firewall_event(const char *event, const char *ip);
int is_ip_allowed(const char *ip);

const char *allowed_ips[] = {
    "127.0.0.1", // localhost
    "192.168.1.1" // example allowed IP
};
const int allowed_ips_count = sizeof(allowed_ips) / sizeof(allowed_ips[0]);

int main() {
    int server_fd;
    struct sockaddr_in server_addr;
    client_t *client;

    // Creating socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting up server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, BACKLOG) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Firewall is running and listening on port %d...\n", PORT);

    while (1) {
        client = malloc(sizeof(client_t));
        socklen_t client_addr_len = sizeof(client->client_addr);

        // Accepting the incoming connection
        if ((client->sockfd = accept(server_fd, (struct sockaddr *)&client->client_addr, &client_addr_len)) < 0) {
            perror("Accept failed");
            free(client);
            continue;
        }

        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client->client_addr.sin_addr, client_ip, sizeof(client_ip));
        
        if (is_ip_allowed(client_ip)) {
            log_firewall_event("Accepted connection", client_ip);
            pthread_t client_thread;
            pthread_create(&client_thread, NULL, handle_client, (void *)client);
            pthread_detach(client_thread);
        } else {
            log_firewall_event("Blocked connection", client_ip);
            close(client->sockfd);
            free(client);
        }
    }

    close(server_fd);
    return 0;
}

void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Handling the client request
    while ((bytes_read = read(client->sockfd, buffer, sizeof(buffer)-1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Received from client (%s): %s\n", inet_ntoa(client->client_addr.sin_addr), buffer);
        write(client->sockfd, buffer, bytes_read); // Echo back
    }

    // Closing the client socket
    close(client->sockfd);
    free(client);
    return NULL;
}

void log_firewall_event(const char *event, const char *ip) {
    FILE *log_file = fopen("firewall.log", "a");
    if (log_file) {
        fprintf(log_file, "[%s] %s: %s\n", __TIME__, event, ip);
        fclose(log_file);
    }
}

int is_ip_allowed(const char *ip) {
    for (int i = 0; i < allowed_ips_count; i++) {
        if (strcmp(ip, allowed_ips[i]) == 0) {
            return 1; // IP is allowed
        }
    }
    return 0; // IP is not allowed
}