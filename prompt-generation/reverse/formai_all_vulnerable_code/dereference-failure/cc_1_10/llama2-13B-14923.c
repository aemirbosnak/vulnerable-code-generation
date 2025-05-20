//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define MAX_CONNECTIONS 10
#define PORT 8080

struct connection {
    int sock;
    char ip[16];
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        return 1;
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        return 1;
    }

    listen(sock, MAX_CONNECTIONS);

    printf("Dragon's Lair listening on port %d...\n", PORT);

    while (1) {
        struct connection *conn = malloc(sizeof(struct connection));
        conn->sock = accept(sock, NULL, NULL);
        if (conn->sock < 0) {
            perror("accept failed");
            free(conn);
            continue;
        }

        // Get the client's IP address
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        getpeername(conn->sock, (struct sockaddr *)&client_addr, &client_len);
        strcpy(conn->ip, inet_ntoa(client_addr.sin_addr));

        // Check if the client is a known dragon
        if (strcmp(conn->ip, "192.168.0.1") == 0) {
            printf("Allowing connection from trusted dragon %s\n", conn->ip);
            // Do something with the connection
        } else {
            printf("Rejecting connection from untrusted dragon %s\n", conn->ip);
            close(conn->sock);
            free(conn);
        }
    }

    return 0;
}