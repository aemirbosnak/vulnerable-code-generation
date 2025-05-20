//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_LEN 1024
#define MAX_SERVER_LEN 2048

struct server_info {
    int sock;
    struct sockaddr_in server_addr;
};

void handle_client(int sock, struct sockaddr_in *client_addr) {
    char buffer[MAX_CLIENT_LEN];
    int len = recv(sock, buffer, MAX_CLIENT_LEN, 0);
    if (len < 0) {
        perror("recv failed");
        return;
    }
    printf("Received message from client: %s\n", buffer);
    send(sock, "Thank you for connecting!", 13, 0);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr, client_addr;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", server_addr.sin_port);

    while (1) {
        struct server_info *server_info = malloc(sizeof(struct server_info));
        server_info->sock = accept(sock, (struct sockaddr *)&client_addr, NULL);
        handle_client(server_info->sock, &client_addr);
        free(server_info);
    }

    return 0;
}