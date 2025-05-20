//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define MAX_CONNECTIONS 1024
#define MAX_PACKET_SIZE 1024

struct connection {
    int sock;
    struct sockaddr_in client_addr;
    char client_name[50];
};

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sock, 3);

    while (1) {
        struct connection *new_conn;
        socklen_t client_len = sizeof(struct sockaddr_in);
        int client_sock = accept(sock, (struct sockaddr *)&new_conn->client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            exit(1);
        }

        new_conn->sock = client_sock;
        getnameinfo((struct sockaddr *)&new_conn->client_addr, client_len, new_conn->client_name, sizeof(new_conn->client_name), NULL, 0, NULL);

        // Check if the client is a known and allowed connection
        if (strcmp(new_conn->client_name, "trusted_client") != 0) {
            close(new_conn->sock);
            continue;
        }

        // Handle the incoming connection
        char buffer[MAX_PACKET_SIZE];
        int bytes_read = recv(new_conn->sock, buffer, MAX_PACKET_SIZE, 0);
        if (bytes_read < 0) {
            perror("recv failed");
            exit(1);
        }

        // Check if the packet is a valid command
        if (strcmp(buffer, "HELLO") != 0) {
            close(new_conn->sock);
            continue;
        }

        // Send a response back to the client
        char *response = "Hello, client!";
        send(new_conn->sock, response, strlen(response), 0);
    }

    return 0;
}