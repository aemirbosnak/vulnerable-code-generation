//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <pthread.h>

// AES-256-CBC encryption/decryption key
unsigned char key[] = "01234567890123456789012345678901";

// AES-256-CBC encryption/decryption initialization vector
unsigned char iv[] = "00000000000000000000000000000000";

// Client socket descriptor
int client_sock;

// Mutex to protect shared data
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Thread function to handle client requests
void *handle_client(void *arg) {
    // Get client socket descriptor from argument
    int sock = *(int *)arg;

    // Allocate buffer for data
    unsigned char data[1024];

    // Receive data from client
    int len = recv(sock, data, sizeof(data), 0);
    if (len <= 0) {
        perror("Error receiving data");
        pthread_exit(NULL);
    }

    // Decrypt received data
    AES_KEY dec_key;
    AES_set_decrypt_key(key, 256, &dec_key);
    AES_cbc_encrypt(data, data, len, &dec_key, iv, AES_DECRYPT);

    // Lock mutex to protect shared data
    pthread_mutex_lock(&mutex);

    // Send decrypted data back to client
    len = send(sock, data, len, 0);
    if (len < 0) {
        perror("Error sending data");
        pthread_exit(NULL);
    }

    // Unlock mutex
    pthread_mutex_unlock(&mutex);

    // Close client socket
    close(sock);

    // Exit thread
    pthread_exit(NULL);
}

int main() {
    // Create server socket
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("Error creating socket");
        return -1;
    }

    // Set server socket options
    int opt = 1;
    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("Error setting socket options");
        return -1;
    }

    // Bind server socket to address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket");
        return -1;
    }

    // Listen for client connections
    if (listen(server_sock, 5) == -1) {
        perror("Error listening for connections");
        return -1;
    }

    // Accept client connections in a loop
    while (1) {
        // Accept client connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sock == -1) {
            perror("Error accepting connection");
            continue;
        }

        // Create new thread to handle client request
        pthread_t thread;
        int *arg = malloc(sizeof(int));
        *arg = client_sock;
        if (pthread_create(&thread, NULL, handle_client, (void *)arg) != 0) {
            perror("Error creating thread");
            close(client_sock);
            continue;
        }

        // Detach thread so it can run asynchronously
        pthread_detach(thread);
    }

    // Close server socket
    close(server_sock);

    return 0;
}