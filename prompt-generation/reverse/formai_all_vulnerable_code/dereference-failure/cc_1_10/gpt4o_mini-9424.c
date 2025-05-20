//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CONN 10
#define BUFFER_SIZE 1024
#define RULES_COUNT 3

typedef struct {
    const char *ip_rule;
    int action; // 1 for allow, 0 for deny
} firewall_rule_t;

firewall_rule_t rules[RULES_COUNT] = {
    {"192.168.1.10", 1},
    {"192.168.1.20", 1},
    {"192.168.1.30", 0}
};

void *handle_connection(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    getpeername(sock, (struct sockaddr *)&client_addr, &addr_len);
    char *client_ip = inet_ntoa(client_addr.sin_addr);
    
    // Check against firewall rules
    int allowed = 0;
    for (int i = 0; i < RULES_COUNT; i++) {
        if (strcmp(client_ip, rules[i].ip_rule) == 0) {
            allowed = rules[i].action;
            break;
        }
    }

    if (allowed) {
        // Connection allowed
        snprintf(buffer, BUFFER_SIZE, "Connection from %s is allowed.\n", client_ip);
        send(sock, buffer, strlen(buffer), 0);
    } else {
        // Connection denied
        snprintf(buffer, BUFFER_SIZE, "Connection from %s is denied!\n", client_ip);
        send(sock, buffer, strlen(buffer), 0);
        close(sock);
        free(socket_desc);
        pthread_exit(NULL);
    }

    // Handle the connection (this could contain more complex logic)
    snprintf(buffer, BUFFER_SIZE, "Welcome! You are connected to the server.\n");
    send(sock, buffer, strlen(buffer), 0);
    
    // Here we could handle more communication...
    
    close(sock);
    free(socket_desc);
    pthread_exit(NULL);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Set the socket to listen
    if (listen(server_fd, MAX_CONN) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Firewall server is running on port %d...\n", PORT);

    while (1) {
        // Accept incoming connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted from %s\n", inet_ntoa(client_addr.sin_addr));

        // Create new thread for each connection
        pthread_t thread_id;
        int *new_sock = malloc(1);
        *new_sock = new_socket;
        if (pthread_create(&thread_id, NULL, handle_connection, (void*)new_sock) < 0) {
            perror("could not create thread");
            exit(EXIT_FAILURE);
        }

        // Detach thread to allow it to run independently
        pthread_detach(thread_id);
    }

    close(server_fd);
    return 0;
}