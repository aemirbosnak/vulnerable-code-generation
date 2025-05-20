//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define MAX_CONN 1000
#define MAX_PKT 1024

struct conn {
    int sock;
    struct sockaddr_in src, dest;
    uint16_t sport, dport;
    char *req, *res;
    size_t len;
    int active;
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct conn *conns = calloc(MAX_CONN, sizeof(struct conn));
    if (conns == NULL) {
        perror("calloc failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        struct sockaddr_in *client_addr = (struct sockaddr_in *)&client_sock;
        char *client_ip = inet_ntoa(client_addr->sin_addr);
        int client_port = ntohs(client_addr->sin_port);

        // Print the client IP and port
        printf("New client connection from %s:%d\n", client_ip, client_port);

        // Check if the client IP is in the whitelist
        if (strcmp(client_ip, "192.168.1.1") == 0) {
            // Allow the connection
            printf("Allowing connection from %s:%d\n", client_ip, client_port);
            conns[0].sock = client_sock;
            conns[0].src.sin_addr = client_addr->sin_addr;
            conns[0].dest.sin_addr = client_addr->sin_addr;
            conns[0].sport = client_port;
            conns[0].dport = client_port;
            conns[0].req = malloc(MAX_PKT);
            conns[0].res = malloc(MAX_PKT);
            conns[0].len = MAX_PKT;
            conns[0].active = 1;
        } else {
            // Drop the connection
            printf("Dropping connection from %s:%d\n", client_ip, client_port);
            close(client_sock);
        }
    }

    return 0;
}