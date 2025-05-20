//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define AES_KEY_SIZE 16  // AES-128
#define MAX_CLIENTS 100

typedef struct {
    int socket;
    struct sockaddr_in address;
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void handle_client(client_t *client);
void broadcast(const char *message, int sender_socket);
void encrypt(const unsigned char *input, unsigned char *output, const unsigned char *key);
void decrypt(const unsigned char *input, unsigned char *output, const unsigned char *key);

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        // Accepting incoming connections
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        client_t *client = malloc(sizeof(client_t));
        client->socket = new_socket;
        client->address = address;

        pthread_t tid;
        pthread_create(&tid, NULL, (void *)handle_client, (void *)client);
    }

    return 0;
}

void handle_client(client_t *client) {
    unsigned char key[AES_KEY_SIZE] = "secret_key12345";  // Example key
    unsigned char buffer[BUFFER_SIZE];
    int n;

    while ((n = read(client->socket, buffer, sizeof(buffer))) > 0) {
        unsigned char encrypted[BUFFER_SIZE];
        encrypt(buffer, encrypted, key);
        broadcast((char *)encrypted, client->socket);
    }

    close(client->socket);
    free(client);
}

void broadcast(const char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (clients[i] && clients[i]->socket != sender_socket) {
            write(clients[i]->socket, message, strlen(message));
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void encrypt(const unsigned char *input, unsigned char *output, const unsigned char *key) {
    AES_KEY encryptKey;
    AES_set_encrypt_key(key, AES_KEY_SIZE * 8, &encryptKey);
    AES_encrypt(input, output, &encryptKey);
}

void decrypt(const unsigned char *input, unsigned char *output, const unsigned char *key) {
    AES_KEY decryptKey;
    AES_set_decrypt_key(key, AES_KEY_SIZE * 8, &decryptKey);
    AES_decrypt(input, output, &decryptKey);
}