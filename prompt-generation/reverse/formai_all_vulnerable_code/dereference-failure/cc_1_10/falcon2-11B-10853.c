//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

#define BUF_SIZE 1024

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *client_thread(void *arg) {
    struct sockaddr_in server_addr;
    int sock_fd, port;

    char buffer[BUF_SIZE];
    int n;

    // Create a socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error creating socket");
        return NULL;
    }

    // Create the address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345);

    // Bind the socket to a port
    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding to port");
        return NULL;
    }

    // Listen for incoming connections
    listen(sock_fd, 5);

    printf("Listening for connections...\n");
    while (1) {
        // Accept a connection
        sock_fd = accept(sock_fd, NULL, NULL);
        if (sock_fd < 0) {
            perror("Error accepting connection");
            continue;
        }
        printf("Connected to: %s\n", inet_ntoa(server_addr.sin_addr));

        // Wait for client to send a message
        n = read(sock_fd, buffer, BUF_SIZE);
        if (n < 0) {
            perror("Error reading from socket");
            close(sock_fd);
            continue;
        }

        // Lock the mutex to prevent race conditions
        pthread_mutex_lock(&mutex);
        printf("Received: %s\n", buffer);
        pthread_mutex_unlock(&mutex);

        // Send a response
        n = write(sock_fd, buffer, BUF_SIZE);
        if (n < 0) {
            perror("Error writing to socket");
            close(sock_fd);
            continue;
        }

        // Unlock the mutex
        pthread_mutex_unlock(&mutex);
    }

    close(sock_fd);
    return NULL;
}

void *server_thread(void *arg) {
    struct sockaddr_in server_addr;
    int sock_fd, port;

    char buffer[BUF_SIZE];
    int n;

    // Create a socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error creating socket");
        return NULL;
    }

    // Create the address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345);

    // Bind the socket to a port
    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding to port");
        return NULL;
    }

    // Listen for incoming connections
    listen(sock_fd, 5);

    printf("Listening for connections...\n");
    while (1) {
        // Accept a connection
        sock_fd = accept(sock_fd, NULL, NULL);
        if (sock_fd < 0) {
            perror("Error accepting connection");
            continue;
        }
        printf("Connected to: %s\n", inet_ntoa(server_addr.sin_addr));

        // Wait for client to send a message
        n = read(sock_fd, buffer, BUF_SIZE);
        if (n < 0) {
            perror("Error reading from socket");
            close(sock_fd);
            continue;
        }

        // Lock the mutex to prevent race conditions
        pthread_mutex_lock(&mutex);
        printf("Received: %s\n", buffer);
        pthread_mutex_unlock(&mutex);

        // Send a response
        n = write(sock_fd, buffer, BUF_SIZE);
        if (n < 0) {
            perror("Error writing to socket");
            close(sock_fd);
            continue;
        }

        // Unlock the mutex
        pthread_mutex_unlock(&mutex);
    }

    close(sock_fd);
    return NULL;
}

int main() {
    pthread_t client_thread;
    pthread_t server_thread;

    if (pthread_create(&client_thread, NULL, client_thread, NULL)!= 0) {
        perror("Error creating client thread");
        return 1;
    }
    if (pthread_create(&server_thread, NULL, server_thread, NULL)!= 0) {
        perror("Error creating server thread");
        return 1;
    }

    pthread_join(client_thread, NULL);
    pthread_join(server_thread, NULL);

    return 0;
}