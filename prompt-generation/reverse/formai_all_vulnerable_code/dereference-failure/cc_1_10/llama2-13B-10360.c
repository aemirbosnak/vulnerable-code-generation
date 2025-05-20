//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_LEN 1024
#define MAX_PACKET_LEN 512

struct server_info {
    int sock;
    char buffer[MAX_PACKET_LEN];
};

void handle_client(int sock) {
    char buffer[MAX_PACKET_LEN];
    int recv_len = recv(sock, buffer, MAX_PACKET_LEN, 0);
    if (recv_len < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("Client said: %s\n", buffer);
    send(sock, "Hello, client!", 13, 0);
}

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    if (listen(sock, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("Listening for incoming connections...\n");
    struct server_info *server_info = malloc(sizeof(struct server_info));
    server_info->sock = sock;
    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        handle_client(client_sock);
        close(client_sock);
    }
    return 0;
}