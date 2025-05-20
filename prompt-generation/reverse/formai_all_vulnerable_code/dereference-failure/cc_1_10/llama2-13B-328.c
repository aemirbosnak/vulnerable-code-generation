//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct server_data {
    int sock;
    char buffer[1024];
};

void handle_connection(int sock) {
    char buffer[1024];
    int len = recv(sock, buffer, 1024, 0);
    if (len > 0) {
        printf("Client said: %s\n", buffer);
        send(sock, "Hello, client!", 13, 0);
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
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

    printf("Listening for connections...\n");

    struct server_data *server_data = malloc(sizeof(struct server_data));
    server_data->sock = sock;

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        handle_connection(client_sock);
        close(client_sock);
    }

    free(server_data);
    close(sock);
    return 0;
}