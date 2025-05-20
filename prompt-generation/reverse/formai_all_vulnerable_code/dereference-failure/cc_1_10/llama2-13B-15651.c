//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8025

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

int main() {
    int sock, client_sock;
    struct email email;
    char buffer[1024];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Bind the socket to a specific address and port
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("Listening failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("Accept failed");
            exit(1);
        }

        // Read email from client
        printf("Received email from client...\n");
        fgets(buffer, 1024, stdin);

        // Parse email
        sscanf(buffer, "%s %s %s %s", email.from, email.to, email.subject, email.message);

        // Send email to server
        send(client_sock, email.message, strlen(email.message), 0);

        // Print email to server
        printf("Email received from client: %s %s %s %s\n", email.from, email.to, email.subject, email.message);

        // Close sockets
        close(client_sock);
        close(sock);
    }

    return 0;
}