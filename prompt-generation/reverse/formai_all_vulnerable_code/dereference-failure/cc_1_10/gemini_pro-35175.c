//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define BUFSIZE 1024
#define KEY_SIZE 256
#define IV_SIZE 128

// The encryption and decryption keys
unsigned char key[KEY_SIZE];
unsigned char iv[IV_SIZE];

// The input and output buffers
unsigned char input_buffer[BUFSIZE];
unsigned char output_buffer[BUFSIZE];

// A thread-safe queue for holding encryption jobs
pthread_mutex_t queue_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t queue_cond = PTHREAD_COND_INITIALIZER;
struct job {
    int sockfd;
    unsigned char *data;
    size_t data_len;
} queue[100];
int queue_head = 0;
int queue_tail = 0;

// The encryption thread
void *encryption_thread(void *args) {
    while (1) {
        pthread_mutex_lock(&queue_lock);
        while (queue_head == queue_tail) {
            pthread_cond_wait(&queue_cond, &queue_lock);
        }

        struct job job = queue[queue_head];
        queue_head = (queue_head + 1) % 100;
        pthread_mutex_unlock(&queue_lock);

        // Encrypt the data
        EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
        EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
        EVP_EncryptUpdate(ctx, output_buffer, &job.data_len, job.data, job.data_len);
        EVP_EncryptFinal_ex(ctx, output_buffer + job.data_len, &job.data_len);
        EVP_CIPHER_CTX_free(ctx);

        // Send the encrypted data back to the client
        send(job.sockfd, output_buffer, job.data_len, 0);

        // Free the allocated memory
        free(job.data);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <key> <iv>\n", argv[0]);
        return 1;
    }

    // Generate the encryption and decryption keys
    RAND_bytes(key, KEY_SIZE);
    RAND_bytes(iv, IV_SIZE);

    // Create the encryption thread
    pthread_t thread;
    pthread_create(&thread, NULL, encryption_thread, NULL);

    // Create the server socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Bind the server socket to an address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(3000);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        return 1;
    }

    // Accept incoming connections and handle them in a separate thread
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }

        // Read the data from the client
        ssize_t data_len = recv(client_sockfd, input_buffer, BUFSIZE, 0);
        if (data_len == -1) {
            perror("recv");
            close(client_sockfd);
            continue;
        }

        // Create a new job and add it to the queue
        pthread_mutex_lock(&queue_lock);
        queue[queue_tail].sockfd = client_sockfd;
        queue[queue_tail].data = (unsigned char *)malloc(data_len);
        memcpy(queue[queue_tail].data, input_buffer, data_len);
        queue[queue_tail].data_len = data_len;
        queue_tail = (queue_tail + 1) % 100;
        pthread_cond_signal(&queue_cond);
        pthread_mutex_unlock(&queue_lock);
    }

    // Close the server socket
    close(sockfd);

    // Join the encryption thread
    pthread_join(thread, NULL);

    return 0;
}