//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define MAX_CLIENT_LENGTH 1024

struct knight {
    char name[50];
    char kingdom[50];
};

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server, client;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    // Server
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(SERVER_PORT);

    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", SERVER_PORT);

    while (1) {
        // Client
        client.sin_family = AF_INET;
        client.sin_addr.s_addr = INADDR_ANY;
        client.sin_port = htons(SERVER_PORT);

        if (connect(sock, (struct sockaddr *)&client, sizeof(client)) < 0) {
            perror("connect failed");
            continue;
        }

        printf("Client connected from IP address %s\n", inet_ntoa(client.sin_addr));

        // Receive knight information from client
        char buffer[MAX_CLIENT_LENGTH];
        printf("Please enter knight information: name and kingdom\n");
        fgets(buffer, MAX_CLIENT_LENGTH, stdin);
        printf("Server received: %s\n", buffer);

        // Send knight information to client
        struct knight *knight = malloc(sizeof(struct knight));
        strcpy(knight->name, buffer);
        strcpy(knight->kingdom, "Kingdom of the Brave");
        send(sock, knight, sizeof(struct knight), 0);

        // Free memory
        free(knight);
    }

    close(sock);
    return 0;
}