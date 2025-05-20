//FormAI DATASET v1.0 Category: Networking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

void communication(int);

int main(int argc, char *argv[]) {
    int socket_desc, client_sock, c, *new_sock;
    struct sockaddr_in server, client;

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind
    if (bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Bind failed. Error");
        return 1;
    }

    // Listen
    listen(socket_desc, 3);

    // Accept and incoming connection
    printf("Waiting for incoming connections...\n");
    c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(socket_desc, (struct sockaddr *) &client, (socklen_t *) &c))) {
        printf("Connection accepted.\n");

        // Create a new thread for each connected client
        new_sock = malloc(1);
        *new_sock = client_sock;

        if (fork() == 0) {
            close(socket_desc);
            communication(client_sock);
            return 0;
        }
    }

    if (client_sock < 0) {
        perror("Accept failed");
        return 1;
    }

    return 0;
}

void communication(int sock) {
    int read_size;
    char message[2000], client_message[2000];

    while ((read_size = recv(sock, client_message, 2000, 0)) > 0) {
        printf("Client: %s\n", client_message);
        printf("Enter message: ");
        fgets(message, 2000, stdin);

        // Remove trailing newline from fgets
        message[strcspn(message, "\n")] = 0;

        if (strcmp(message, "exit") == 0) {
            printf("Closing connection...\n");
            break;
        }

        // Send the message back to the client
        write(sock, message, strlen(message));
        memset(client_message, 0, 2000);
    }

    if (read_size == 0) {
        printf("Client disconnected.\n");
    } else if(read_size == -1) {
        perror("recv failed");
    }

    close(sock);
}