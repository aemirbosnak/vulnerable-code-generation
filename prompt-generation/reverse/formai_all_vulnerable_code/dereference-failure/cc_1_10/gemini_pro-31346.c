//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    int addrlen;
} client_t;

void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;

    // Receive the binary number from the client
    char binary[1024];
    recv(client->sockfd, binary, sizeof(binary), 0);

    // Convert the binary number to decimal
    int decimal = 0;
    int i = 0;
    while (binary[i] != '\0') {
        decimal *= 2;
        if (binary[i] == '1') {
            decimal += 1;
        }
        i++;
    }

    // Send the decimal number back to the client
    char decimal_str[1024];
    sprintf(decimal_str, "%d", decimal);
    send(client->sockfd, decimal_str, strlen(decimal_str), 0);

    // Close the client socket
    close(client->sockfd);

    return NULL;
}

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Bind the socket to an address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for connections
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        return 1;
    }

    // Accept connections and handle them in a thread
    while (1) {
        client_t client;
        client.addrlen = sizeof(client.addr);
        client.sockfd = accept(sockfd, (struct sockaddr *)&client.addr, &client.addrlen);
        if (client.sockfd < 0) {
            perror("accept");
            continue;
        }

        pthread_t thread;
        if (pthread_create(&thread, NULL, handle_client, &client) != 0) {
            perror("pthread_create");
            close(client.sockfd);
            continue;
        }

        pthread_detach(thread);
    }

    // Close the socket
    close(sockfd);

    return 0;
}