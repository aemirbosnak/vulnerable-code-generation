//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define PORT 8080

struct packet {
    char *data;
    int len;
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sock, 3);

    while (1) {
        struct packet *packet;
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept failed");
            continue;
        }

        packet = malloc(1024);
        if (packet == NULL) {
            perror("malloc failed");
            close(client_sock);
            continue;
        }

        // Read data from client
        read(client_sock, packet->data, 1024);

        // Check if the data is a HTTP request
        if (strstr(packet->data, "GET / HTTP/1.1") != NULL) {
            printf("Allowed request: %s\n", packet->data);
        } else {
            printf("Blocked request: %s\n", packet->data);
            close(client_sock);
            free(packet);
            continue;
        }

        // Send response back to client
        char *response = "Hello, client!";
        send(client_sock, response, strlen(response), 0);

        free(packet);
    }

    close(sock);
    return 0;
}