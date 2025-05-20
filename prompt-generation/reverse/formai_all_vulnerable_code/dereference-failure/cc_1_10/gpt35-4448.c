//FormAI DATASET v1.0 Category: Client Server Application ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    char input[1024], output[1024];
    int server_socket, client_socket, client_length, port;
    struct sockaddr_in server_address, client_address;

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    port = atoi(argv[1]);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        return 1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address))) {
        perror("bind failed");
        return 1;
    }

    if (listen(server_socket, 5)) {
        perror("listen failed");
        return 1;
    }

    printf("Server started on port %d\n", port);

    while (1) {
        client_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_length);

        if (client_socket == -1) {
            perror("accept failed");
            continue;
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        while (1) {
            memset(input, 0, sizeof(input));
            printf("Waiting for client input...\n");
            recv(client_socket, input, sizeof(input), 0);
            printf("Received input: %s", input);

            if (!strcmp(input, "exit\n")) {
                close(client_socket);
                break;
            }

            printf("Enter output to send to client: ");
            fgets(output, sizeof(output), stdin);

            if (send(client_socket, output, strlen(output), 0) == -1) {
                perror("send failed");
                continue;
            }
        }
    }

    return 0;
}