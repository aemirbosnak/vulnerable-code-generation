//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 100
#define BUFFER_SIZE 1024

struct client_data {
    int sock;
    char name[50];
    char message[50];
};

int main(int argc, char *argv[]) {
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind the listen socket to a specific address and port
    bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Listen for incoming connections
    listen(listen_sock, 3);

    while (1) {
        // Accept an incoming connection
        int client_sock = accept(listen_sock, NULL, NULL);

        // Create a new client data structure
        struct client_data *client_data = malloc(sizeof(struct client_data));
        client_data->sock = client_sock;

        // Receive the client's name and message
        recv(client_sock, client_data->name, 50, 0);
        recv(client_sock, client_data->message, 50, 0);

        // Print the client's name and message
        printf("Client: %s says: %s\n", client_data->name, client_data->message);

        // Send a response back to the client
        char *response = "Hello, client!";
        send(client_sock, response, strlen(response), 0);

        // Free the client data structure
        free(client_data);
    }

    return 0;
}