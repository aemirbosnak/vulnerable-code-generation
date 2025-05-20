//LLAMA2-13B DATASET v1.0 Category: Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>

#define PORT 8080

struct file {
    char *name;
    char *data;
    int size;
};

struct client {
    int sock;
    char *name;
};

int main(int argc, char *argv[]) {
    int sock, client_sock;
    struct sockaddr_in server, client;
    struct file files[10];
    int i, j;

    // Create the server socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the server socket to the address and port
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Binding failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("Listening failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        client_sock = accept(sock, (struct sockaddr *)&client, (socklen_t*)&client.sin_addr);
        if (client_sock < 0) {
            perror("Accept failed");
            exit(1);
        }

        // Create a new file structure
        struct file *file = malloc(sizeof(struct file));
        file->name = malloc(100);
        file->data = malloc(100);
        file->size = 0;

        // Read the file name and data from the client
        read(client_sock, file->name, 100);
        read(client_sock, file->data, 100);
        file->size = strlen(file->data);

        // Add the file to the list of files
        for (i = 0; i < 10; i++) {
            if (strcmp(files[i].name, file->name) != 0) {
                break;
            }
        }
        if (i == 10) {
            printf("Server is full, cannot add more files\n");
            free(file);
            continue;
        }
        files[i] = *file;

        // Send the file list to the client
        for (j = 0; j < 10; j++) {
            send(client_sock, files[j].name, strlen(files[j].name), 0);
            send(client_sock, files[j].data, files[j].size, 0);
        }

        // Close the client socket
        close(client_sock);
    }

    return 0;
}