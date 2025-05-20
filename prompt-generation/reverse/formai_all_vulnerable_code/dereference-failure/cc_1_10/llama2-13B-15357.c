//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define MAX_CONNECTIONS 10
#define PORT 8080

struct connection {
    int sock;
    struct sockaddr_in client_addr;
    char client_name[50];
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        return 1;
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    listen(sock, MAX_CONNECTIONS);

    while (1) {
        struct connection *new_conn = malloc(sizeof(struct connection));
        new_conn->sock = accept(sock, NULL, NULL);
        if (new_conn->sock < 0) {
            perror("Error accepting connection");
            free(new_conn);
            continue;
        }

        // Get client IP and name
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        getpeername(new_conn->sock, (struct sockaddr *)&client_addr, &client_len);
        new_conn->client_addr = client_addr;
        char client_name[50];
        gethostname(client_name, 50);
        strcpy(new_conn->client_name, client_name);

        // Welcome client
        printf("Welcome, %s! You have connected to my firewall.\n", new_conn->client_name);

        // Handle client requests
        while (1) {
            char buffer[1024];
            int bytes_read = read(new_conn->sock, buffer, 1024);
            if (bytes_read < 0) {
                perror("Error reading from client");
                break;
            }

            // Check if client is sending a "love" message
            if (strstr(buffer, "love") != NULL) {
                printf("You have sent me a love message! 💕\n");
                // Send a "love" message back to the client
                char *message = "I love you too! 💕";
                send(new_conn->sock, message, strlen(message), 0);
            } else {
                // Otherwise, just echo back the message
                send(new_conn->sock, buffer, bytes_read, 0);
            }
        }

        // Close the connection when done
        close(new_conn->sock);
        free(new_conn);
    }

    return 0;
}