//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct client_info {
    int sock;
    char name[50];
};

int main(int argc, char *argv[]) {
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(listen_sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        int client_sock = accept(listen_sock, NULL, NULL);
        struct client_info *client = malloc(sizeof(struct client_info));
        client->sock = client_sock;

        printf("New client connected! Name: ");
        fgets(client->name, 50, stdin);
        printf("\n");

        while (1) {
            char buffer[1024];
            int bytes_read = read(client->sock, buffer, 1024);
            if (bytes_read <= 0) {
                break;
            }
            printf("Client message: %s\n", buffer);

            char message[1024];
            printf("Server message: ");
            fgets(message, 1024, stdin);
            printf("\n");
            send(client->sock, message, strlen(message), 0);
        }

        close(client->sock);
        free(client);
    }

    close(listen_sock);
    return 0;
}