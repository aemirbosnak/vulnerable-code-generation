//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct server_data {
    int sock;
    char buffer[256];
};

void handle_client(int sock) {
    char buffer[256];
    int len = recv(sock, buffer, 256, 0);
    if (len < 0) {
        perror("recv");
        exit(1);
    }
    printf("Client said: %s\n", buffer);
    send(sock, "Hello, client!", 13, 0);
}

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }
    listen(sock, 3);
    printf("Listening for connections...\n");
    int client_sock = accept(sock, NULL, NULL);
    if (client_sock < 0) {
        perror("accept");
        exit(1);
    }
    struct server_data *data = malloc(sizeof(struct server_data));
    data->sock = client_sock;
    handle_client(client_sock);
    free(data);
    close(client_sock);
    close(sock);
    return 0;
}