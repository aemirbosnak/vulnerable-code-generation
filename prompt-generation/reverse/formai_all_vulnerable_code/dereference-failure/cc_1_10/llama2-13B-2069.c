//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct server_data {
    int sock;
    struct sockaddr_in server_addr;
};

void handle_client(int sock) {
    char buffer[256];
    printf("Client connected...\n");

    while (1) {
        recv(sock, buffer, 256, 0);
        printf("Client said: %s\n", buffer);

        send(sock, "Hello, client!", 13, 0);
    }
}

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(1);
    }

    if (listen(sock, 3) < 0) {
        perror("Listening failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        struct server_data *data = malloc(sizeof(struct server_data));
        data->sock = accept(sock, NULL, NULL);
        handle_client(data->sock);
        free(data);
    }

    close(sock);
    return 0;
}