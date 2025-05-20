//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 10

struct client_data {
    int sock;
    char client_ip[INET_ADDRSTRLEN];
};

void handle_connection(int sock) {
    struct client_data *data = malloc(sizeof(struct client_data));
    memset(data, 0, sizeof(struct client_data));
    data->sock = sock;
    inet_pton(AF_INET, "127.0.0.1", &data->client_ip);

    while (1) {
        char buffer[1024];
        int recv_len = recv(sock, buffer, 1024, 0);
        if (recv_len < 0) {
            perror("recv");
            break;
        }
        printf("Client: %s\n", buffer);

        // Check if the client is sending a valid command
        if (strcmp(buffer, "HELLO") == 0) {
            printf("Hello, client!\n");
        } else if (strcmp(buffer, "GOODBYE") == 0) {
            printf("Goodbye, client!\n");
            close(sock);
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    free(data);
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(8080)
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    listen(sock, MAX_CLIENT_CONNECTIONS);

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept");
            break;
        }
        handle_connection(client_sock);
    }

    close(sock);
    return 0;
}