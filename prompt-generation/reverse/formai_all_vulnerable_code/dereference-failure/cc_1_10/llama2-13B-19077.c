//LLAMA2-13B DATASET v1.0 Category: Weather simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client_data {
    int sock;
    char name[256];
    float temperature;
    float humidity;
};

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    int client_count = 0;

    // Create the server socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the server socket to the address and port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        client_len = sizeof(client_addr);
        if ((sock = accept(sock, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("accept failed");
            continue;
        }

        // Create a new client data structure
        struct client_data *client_data = malloc(sizeof(struct client_data));
        client_data->sock = sock;
        client_data->name[0] = '\0';

        // Read the client's name and temperature/humidity
        read(sock, buffer, BUFFER_SIZE);
        sscanf(buffer, "%s %f %f", client_data->name, &client_data->temperature, &client_data->humidity);

        // Broadcast the client's data to all other clients
        sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));

        // Add the client to the list of connected clients
        client_count++;
        printf("Client %s connected with temperature %f and humidity %f\n", client_data->name, client_data->temperature, client_data->humidity);

        // Handle incoming data from other clients
        while (1) {
            // Receive data from other clients
            char buffer[BUFFER_SIZE];
            recvfrom(sock, buffer, BUFFER_SIZE, 0, NULL, NULL);

            // Parse the received data
            struct client_data *other_client = malloc(sizeof(struct client_data));
            sscanf(buffer, "%s %f %f", other_client->name, &other_client->temperature, &other_client->humidity);

            // Update the client's data based on the received data
            client_data->temperature = other_client->temperature;
            client_data->humidity = other_client->humidity;

            // Free the other client's data structure
            free(other_client);
        }
    }

    // Close the server socket
    close(sock);

    return 0;
}