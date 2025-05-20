//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4200

struct user {
    char *name;
    char *message;
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);

        char *message = malloc(1024);
        read(client_sock, message, 1024);

        printf("Client message: %s\n", message);

        // Process the message and send a response
        char *response = "You said: ";
        strcat(response, message);
        send(client_sock, response, strlen(response), 0);

        free(message);

        close(client_sock);
    }

    close(sock);

    return 0;
}