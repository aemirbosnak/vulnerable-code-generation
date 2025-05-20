//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 10
#define MAX_FILE_SIZE 1024

struct client_data {
    int sock;
    char filename[100];
};

int main(int argc, char *argv[]) {
    int listen_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[256];
    int num_clients = 0;

    // Create the listen socket
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Bind the listen socket to the address and port
    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", server_addr.sin_port);

    while (1) {
        // Accept an incoming connection
        client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            exit(1);
        }

        // Create a new client data structure
        struct client_data *client_data = malloc(sizeof(struct client_data));
        client_data->sock = client_sock;

        // Read the client's filename request
        read(client_sock, buffer, 256);
        printf("Client request: %s\n", buffer);

        // Check if the file exists
        if (access(buffer, F_OK) == 0) {
            // File exists, send it to the client
            send(client_sock, "File exists\n", 10, 0);
        } else {
            // File does not exist, create it and send it to the client
            FILE *file = fopen(buffer, "w");
            if (file == NULL) {
                perror("fopen failed");
                exit(1);
            }
            char data[1024];
            for (int i = 0; i < 1024; i++) {
                data[i] = i % 2 ? 'a' : 'b';
            }
            write(file, data, 1024);
            fclose(file);
            send(client_sock, "File created\n", 12, 0);
        }

        // Wait for the client to finish reading the file
        wait(NULL);

        // Close the client socket and free the client data structure
        close(client_sock);
        free(client_data);
    }

    return 0;
}