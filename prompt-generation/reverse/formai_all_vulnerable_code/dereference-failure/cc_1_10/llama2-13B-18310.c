//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

void* client_thread(void* arg) {
    int sock = *((int*)arg);

    while (1) {
        char buffer[1024];
        recv(sock, buffer, 1024, 0);
        printf("Received message from server: %s\n", buffer);

        // Send a response back to the server
        char* message = "Hello, server!";
        send(sock, message, strlen(message), 0);

        // Wait for more data to arrive
        printf("Waiting for more data...\n");
        select(sock + 1, NULL, NULL, NULL, NULL);
    }

    return NULL;
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = inet_addr("127.0.0.1")
    };

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        exit(1);
    }

    pthread_t client_thread;
    pthread_create(&client_thread, NULL, client_thread, (void*)&sock);

    char* message = "Hello, server!";
    send(sock, message, strlen(message), 0);

    pthread_join(client_thread, NULL);

    close(sock);
    return 0;
}