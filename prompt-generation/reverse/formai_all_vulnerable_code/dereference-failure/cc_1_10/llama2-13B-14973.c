//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: medieval
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

void create_server(int *sock) {
    struct server_data *data = malloc(sizeof(struct server_data));
    data->sock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&data->server_addr, 0, sizeof(struct sockaddr_in));
    data->server_addr.sin_family = AF_INET;
    data->server_addr.sin_addr.s_addr = INADDR_ANY;
    data->server_addr.sin_port = htons(PORT);

    bind(data->sock, (struct sockaddr *)&data->server_addr, sizeof(struct sockaddr_in));
    listen(data->sock, 3);

    *sock = data->sock;
}

void handle_client(int sock) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(struct sockaddr_in);
    char buffer[1024];

    accept(sock, (struct sockaddr *)&client_addr, &client_len);

    printf("Client connected from IP: %s and port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    read(sock, buffer, 1024);
    printf("Client message: %s\n", buffer);

    char *message = "Greetings, brave knight! Welcome to our humble server!";
    send(sock, message, strlen(message), 0);

    close(sock);
}

int main() {
    int sock;
    create_server(&sock);

    while (1) {
        handle_client(sock);
    }

    return 0;
}