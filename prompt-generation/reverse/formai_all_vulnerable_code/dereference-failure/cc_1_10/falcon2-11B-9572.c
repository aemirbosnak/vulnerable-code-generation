//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int port;
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sock, 5);

    struct sockaddr_in client;
    socklen_t client_len = sizeof(client);

    int client_sock = accept(sock, (struct sockaddr *)&client, &client_len);
    if (client_sock < 0) {
        perror("accept");
        exit(1);
    }

    printf("Client connected: %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

    char buffer[256];
    int n;

    while ((n = read(client_sock, buffer, sizeof(buffer))) > 0) {
        printf("Received: %s\n", buffer);
    }

    close(client_sock);

    close(sock);

    return 0;
}