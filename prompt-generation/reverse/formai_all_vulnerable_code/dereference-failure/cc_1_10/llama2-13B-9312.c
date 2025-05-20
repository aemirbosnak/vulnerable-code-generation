//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

struct user {
    char name[50];
    char message[50];
};

int main(int argc, char *argv[]) {
    int sock, client_sock;
    struct sockaddr_in server, client;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sock, 5) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        client_sock = accept(sock, (struct sockaddr *)&client, (socklen_t*)&client.sin_addr);
        if (client_sock < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected from IP address %s and port %d...\n",
               inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        // Handle messages from clients
        while (1) {
            char message[BUFFER_SIZE];
            recv(client_sock, message, BUFFER_SIZE, 0);
            if (message[0] == '\0') {
                break;
            }
            printf("Received message from client: %s\n", message);

            // Send a response message to the client
            char* response = "You said: ";
            strncat(response, message, strlen(message));
            send(client_sock, response, strlen(response), 0);
        }

        // Close the client socket
        close(client_sock);
    }

    return 0;
}