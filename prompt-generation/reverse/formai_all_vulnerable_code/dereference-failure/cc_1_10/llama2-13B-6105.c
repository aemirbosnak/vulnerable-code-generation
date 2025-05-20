//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define MAX_CONN 50
#define PORT 8080

struct conn_data {
    int sock;
    struct sockaddr_in client_addr;
    char client_name[50];
};

int main() {
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up listening
    struct sockaddr_in listen_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };
    if (bind(listen_sock, (struct sockaddr*) &listen_addr, sizeof(listen_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(listen_sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Listening on port %d...\n", PORT);

    // Loop forever to accept connections
    while (1) {
        struct conn_data *conn_data = malloc(sizeof(struct conn_data));
        conn_data->sock = accept(listen_sock, NULL, NULL);
        if (conn_data->sock < 0) {
            perror("accept failed");
            exit(1);
        }

        // Get the client IP address and name
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        getpeername(conn_data->sock, (struct sockaddr*) &client_addr, &client_len);
        char client_name[50];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_name, sizeof(client_name));

        // Print the client connection
        printf("Connection from %s (%d.%d.%d.%d:%d)\n", client_name,
               client_addr.sin_addr.s_addr, client_addr.sin_port);

        // Handle the client connection
        while (1) {
            // Read data from the client
            char buffer[1024];
            int bytes_read = read(conn_data->sock, buffer, 1024);
            if (bytes_read < 0) {
                perror("read failed");
                break;
            }

            // Print the received data
            printf("Received data: %s\n", buffer);

            // Send a response back to the client
            char *message = "Hello, my love!";
            send(conn_data->sock, message, strlen(message), 0);
        }

        // Close the connection
        close(conn_data->sock);
        free(conn_data);
    }

    return 0;
}