//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_BUF_SIZE 1024

// Client thread function
void *client_thread(void *arg) {
    int sock = *((int *)arg);

    char buf[MAX_BUF_SIZE];
    while (1) {
        // Receive data from server
        int recv_len = recv(sock, buf, MAX_BUF_SIZE, 0);
        if (recv_len == -1) {
            perror("recv");
            break;
        } else if (recv_len == 0) {
            printf("Server closed connection\n");
            break;
        }

        // Print received data
        printf("Received from server: %s\n", buf);

        // Send data to server
        char *msg = "Hello from client";
        int send_len = send(sock, msg, strlen(msg), 0);
        if (send_len == -1) {
            perror("send");
            break;
        }
    }

    // Close client socket
    close(sock);
    free(arg);

    return NULL;
}

// Main function
int main() {
    // Create server socket
    int serv_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set server socket options
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind server socket to address
    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind");
        close(serv_sock);
        return EXIT_FAILURE;
    }

    // Listen for client connections
    if (listen(serv_sock, MAX_CLIENTS) == -1) {
        perror("listen");
        close(serv_sock);
        return EXIT_FAILURE;
    }

    printf("Server listening on port %d\n", PORT);

    // Accept client connections
    int client_socks[MAX_CLIENTS];
    int num_clients = 0;
    while (1) {
        // Accept client connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(serv_sock, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sock == -1) {
            perror("accept");
            continue;
        }

        // Add client socket to array
        client_socks[num_clients] = client_sock;
        num_clients++;

        // Create client thread
        pthread_t client_thread_id;
        int *arg = malloc(sizeof(int));
        *arg = client_sock;
        if (pthread_create(&client_thread_id, NULL, client_thread, (void *)arg) != 0) {
            perror("pthread_create");
            close(client_sock);
            continue;
        }
    }

    // Close server socket
    close(serv_sock);

    return EXIT_SUCCESS;
}