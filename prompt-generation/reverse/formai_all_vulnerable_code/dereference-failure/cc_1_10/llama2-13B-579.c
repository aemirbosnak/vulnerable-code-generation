//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct message {
    char *text;
    int len;
};

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
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
        struct message *message = malloc(sizeof(struct message));
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        char buffer[1024];
        int bytes_read = read(client_sock, buffer, 1024);
        if (bytes_read < 0) {
            perror("read failed");
            exit(EXIT_FAILURE);
        }

        message->text = buffer;
        message->len = bytes_read;

        // Print the message to the console
        printf("Received message from client: %s\n", message->text);

        // Send a response back to the client
        char *response = "Thank you for your message!";
        send(client_sock, response, strlen(response), 0);

        free(message);
    }

    close(sock);
    return 0;
}