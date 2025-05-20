//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct user {
    char name[50];
    char message[100];
};

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sock, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started. Listening for connections...\n");

    while (1) {
        struct user *new_user;
        new_user = malloc(sizeof(struct user));

        if (accept(sock, (struct sockaddr *)NULL, NULL) < 0) {
            perror("Accept failed");
            continue;
        }

        printf("New user connected! Name: %s\n", new_user->name);

        // Brave style: instead of using a boring "Hello, how are you?" message,
        // we'll use a random joke instead.
        sprintf(new_user->message, "Why don't scientists trust atoms? Because they make up everything!");

        // Send the message back to the client.
        send(sock, new_user->message, strlen(new_user->message), 0);

        // Wait for the client to send another message.
        recv(sock, new_user->message, 100, 0);

        // Print the message to the console.
        printf("Client message: %s\n", new_user->message);

        free(new_user);
    }

    close(sock);
    return 0;
}