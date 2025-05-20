//FormAI DATASET v1.0 Category: Chat server ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_PENDING 10
#define MAX_CLIENTS 10

int sock_fd, client_fds[MAX_CLIENTS];
struct sockaddr_in serveraddr, clientaddr;
pthread_t threads[MAX_CLIENTS];

void *handle_client(void *arg) {
    int client_id = *((int*) arg);
    char recv_buf[1024], send_buf[1024];
    while (1) {
        int num_bytes = recv(client_fds[client_id], recv_buf, sizeof(recv_buf), 0);
        if (num_bytes == -1) {
            perror("Error receiving client message");
            break;
        } else if (num_bytes == 0) {
            printf("Client %d closed the connection\n", client_id + 1);
            break;
        }
        printf("Received message from client %d: %s", client_id + 1, recv_buf);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_fds[i] != -1 && i != client_id) {  // Send message to all clients except self
                sprintf(send_buf, "Client %d: %s", client_id + 1, recv_buf);  // Add client ID to message
                send(client_fds[i], send_buf, strlen(send_buf), 0);
            }
        }
    }
    close(client_fds[client_id]);
    client_fds[client_id] = -1;
    pthread_exit(NULL);
}

int main() {
    memset(&serveraddr, 0, sizeof(serveraddr));  // Zero out structure
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(1);
    }

    if (bind(sock_fd, (struct sockaddr*) &serveraddr, sizeof(serveraddr)) == -1) {
        perror("Error binding socket");
        exit(1);
    }

    if (listen(sock_fd, MAX_PENDING) == -1) {
        perror("Error listening for clients");
        exit(1);
    }
    printf("Chat server started on port %d\n", PORT);

    memset(&client_fds, -1, sizeof(client_fds));  // Initialize client FDs to -1 (unused)
    int client_count = 0;

    while (1) {
        socklen_t len = sizeof(clientaddr);
        int client_fd = accept(sock_fd, (struct sockaddr*) &clientaddr, &len);
        if (client_fd == -1) {
            perror("Error accepting client connection");
            continue;
        }
        if (client_count == MAX_CLIENTS) {
            printf("Maximum client limit reached. Closing connection from new client.\n");
            close(client_fd);
            continue;
        }
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_fds[i] == -1) {
                client_fds[i] = client_fd;
                printf("Accepted connection from client %d\n", i + 1);
                int *arg = malloc(sizeof(*arg));  // Pass client ID to thread
                *arg = i;
                pthread_create(&threads[i], NULL, handle_client, arg);
                client_count++;
                break;
            }
        }
    }

    close(sock_fd);
    return 0;
}