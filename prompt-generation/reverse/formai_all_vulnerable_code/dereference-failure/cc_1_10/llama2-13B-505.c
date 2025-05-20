//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct server_state {
    int sock;
    char buffer[1024];
    size_t len;
};

void handle_connection(int sock) {
    struct server_state *state = malloc(sizeof(struct server_state));
    state->sock = sock;
    state->buffer[0] = '\0';
    state->len = 0;

    while (1) {
        recv(sock, state->buffer, 1024, 0);
        if (strcmp(state->buffer, "QUIT\n") == 0) {
            break;
        }
        printf("Received message: %s\n", state->buffer);
        send(sock, "Hello, client!", 13, 0);
    }

    free(state);
}

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening for incoming connections...\n");

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);

        handle_connection(client_sock);
    }

    close(sock);
    return 0;
}