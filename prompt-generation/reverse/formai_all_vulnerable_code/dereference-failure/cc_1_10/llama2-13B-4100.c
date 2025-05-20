//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct server_state {
    int sock;
    struct sockaddr_in client_addr;
};

void handle_request(int sock, struct sockaddr_in *client_addr) {
    char buffer[1024];
    int len = recv(sock, buffer, 1024, 0);
    if (len < 0) {
        perror("recv failed");
        return;
    }

    printf("Received request: %s\n", buffer);

    // Handle the request
    if (strcmp(buffer, "/hello") == 0) {
        char *message = "Hello, world!";
        send(sock, message, strlen(message), 0);
    } else if (strcmp(buffer, "/404") == 0) {
        char *message = "Not found :(";
        send(sock, message, strlen(message), 0);
    } else {
        char *message = "Invalid request :(";
        send(sock, message, strlen(message), 0);
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    struct server_state *state = malloc(sizeof(struct server_state));
    state->sock = sock;

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            continue;
        }

        handle_request(client_sock, &client_addr);
        close(client_sock);
    }

    return 0;
}