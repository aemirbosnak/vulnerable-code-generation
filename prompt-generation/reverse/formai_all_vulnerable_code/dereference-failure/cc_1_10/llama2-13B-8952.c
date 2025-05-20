//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define MAX_CONNS 100
#define PORT 8080

struct conn_data {
    int sock;
    char *client_ip;
    char *client_msg;
};

void handle_connection(int sock) {
    char buffer[1024];
    struct conn_data *data;

    // Parse incoming client message
    recv(sock, buffer, 1024, 0);
    data = (struct conn_data *) malloc(sizeof(struct conn_data));
    sscanf(buffer, "%s %s", data->client_ip, data->client_msg);

    // Check if client is a known evil-doer
    if (strstr(data->client_ip, "192.168.") || strstr(data->client_ip, "10.0.0.")) {
        // Block evil client! 😈
        shutdown(sock, SHUT_RD);
        close(sock);
        printf("BLOCKED: %s\n", data->client_ip);
    } else {
        // Allow good client to proceed! 😊
        printf("ALLOWED: %s\n", data->client_ip);
    }
}

int main() {
    int sock;
    struct conn_data data;

    // Listen for incoming connections
    sock = listen(PORT, MAX_CONNS);
    if (sock < 0) {
        perror("listen failed");
        exit(1);
    }

    // Loop forever, handling connections
    while (1) {
        // Accept incoming connection
        sock = accept(sock, NULL, NULL);
        if (sock < 0) {
            perror("accept failed");
            exit(1);
        }

        // Handle connection
        handle_connection(sock);

        // Close connection
        close(sock);
    }

    return 0;
}