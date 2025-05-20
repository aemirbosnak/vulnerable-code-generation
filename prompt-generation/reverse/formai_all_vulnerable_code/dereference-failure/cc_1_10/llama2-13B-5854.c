//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 10
#define MAX_MESSAGE_LENGTH 1024

struct client_data {
    int sock;
    char name[50];
};

int main(void) {
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(1234),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_sock, MAX_CLIENT_CONNECTIONS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening for connections...\n");

    while (1) {
        struct client_data *client_data = malloc(sizeof(struct client_data));
        int client_sock = accept(listen_sock, NULL, NULL);

        // Get the client's name
        char *name = "Anonymous";
        if (getnameinfo((struct sockaddr *)&client_sock, sizeof(struct sockaddr),
                         name, sizeof(name), NULL, 0, NULL) == 0) {
            strcpy(client_data->name, name);
        }

        // Handle incoming messages
        while (1) {
            char message[MAX_MESSAGE_LENGTH];
            recv(client_sock, message, MAX_MESSAGE_LENGTH, 0);

            // Print the message to all connected clients
            printf("%s says: %s\n", client_data->name, message);

            // Send the message to all connected clients
            send(listen_sock, message, strlen(message), 0);
        }

        // Close the client's socket
        close(client_sock);

        // Free the client data
        free(client_data);
    }

    return 0;
}