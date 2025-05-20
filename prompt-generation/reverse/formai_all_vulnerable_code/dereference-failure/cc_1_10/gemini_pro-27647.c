//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>

// A nickname is stored for each client
typedef struct nickname_t {
    char nickname[16];
} nickname_t;

// Each client gets its own thread
typedef struct client_t {
    int sock;
    nickname_t nickname;
} client_t;

// A linked list of clients
typedef struct client_list_t {
    client_t *client;
    struct client_list_t *next;
} client_list_t;

// The server's socket, port and client list
int server_sock;
int port;
client_list_t *clients = NULL;

// Mutex for the client list
pthread_mutex_t client_list_mutex = PTHREAD_MUTEX_INITIALIZER;

// Create a new client thread
void *client_thread(void *arg) {
    client_t *client = (client_t *) arg;
    char buffer[1024];
    int n;

    // Receive messages from the client
    while ((n = recv(client->sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0';
        printf("%s: %s", client->nickname.nickname, buffer);

        // Broadcast the message to all other clients
        pthread_mutex_lock(&client_list_mutex);
        client_list_t *curr = clients;
        while (curr != NULL) {
            if (curr->client != client) {
                send(curr->client->sock, buffer, n, 0);
            }
            curr = curr->next;
        }
        pthread_mutex_unlock(&client_list_mutex);
    }

    // If the client disconnected, remove it from the list
    pthread_mutex_lock(&client_list_mutex);
    client_list_t *prev = NULL;
    client_list_t *curr = clients;
    while (curr != NULL) {
        if (curr->client == client) {
            if (prev == NULL) {
                clients = clients->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    pthread_mutex_unlock(&client_list_mutex);

    // Close the client's socket and free its memory
    close(client->sock);
    free(client);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Parse the port number
    port = atoi(argv[1]);

    // Create the server socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("socket");
        return 1;
    }

    // Bind the server socket to the port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_sock, 5) < 0) {
        perror("listen");
        return 1;
    }

    // Accept incoming connections and create a thread for each client
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_sock < 0) {
            perror("accept");
            continue;
        }

        // Get the client's nickname
        nickname_t nickname;
        memset(&nickname, 0, sizeof(nickname));
        int n = recv(client_sock, nickname.nickname, sizeof(nickname.nickname), 0);
        if (n <= 0) {
            perror("recv");
            close(client_sock);
            continue;
        }

        // Create a new client thread
        client_t *client = malloc(sizeof(client_t));
        client->sock = client_sock;
        memcpy(&client->nickname, &nickname, sizeof(nickname));
        pthread_t thread;
        pthread_create(&thread, NULL, client_thread, client);

        // Add the client to the client list
        pthread_mutex_lock(&client_list_mutex);
        client_list_t *new_client = malloc(sizeof(client_list_t));
        new_client->client = client;
        new_client->next = clients;
        clients = new_client;
        pthread_mutex_unlock(&client_list_mutex);
    }

    // Close the server socket
    close(server_sock);

    return 0;
}