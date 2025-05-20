//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: dynamic
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

int main() {
    int sock, cli_sock;
    struct sockaddr_in server, cli;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    bind(sock, (struct sockaddr *)&server, sizeof(server));
    listen(sock, 5);

    printf("Chat Server Listening on port %d...\n", PORT);

    while (1) {
        cli_sock = accept(sock, (struct sockaddr *)&cli, (socklen_t*)&cli.sin_addr);
        struct user *user = malloc(sizeof(struct user));
        read(cli_sock, user, sizeof(struct user));

        // Process user message
        char *message = user->message;
        if (strcmp(message, "hello") == 0) {
            printf("Hello, %s! Welcome to the chat server.\n", user->name);
        } else if (strcmp(message, "goodbye") == 0) {
            printf("Goodbye, %s! It was nice chatting with you.\n", user->name);
        } else {
            printf("You said: %s\n", message);
        }

        // Send response back to client
        char *response = "You said: Hello, how are you?";
        write(cli_sock, response, strlen(response));

        free(user);
    }

    close(sock);
    close(cli_sock);
    return 0;
}