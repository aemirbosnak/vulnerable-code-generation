//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define MAX_CONNS 100
#define MAX_PKT_LEN 1024

struct connection {
    int sock;
    struct sockaddr_in client_addr;
    char client_ip[16];
    int established;
};

int main(int argc, char *argv[]) {
    int listen_sock;
    struct sockaddr_in listen_addr;
    struct connection *conns = NULL;
    int num_conns = 0;

    // Create the listen socket
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Set up the listen address
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &listen_addr.sin_addr);

    // Bind the listen socket to the listen address
    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("binding failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_sock, 3) < 0) {
        perror("listening failed");
        exit(1);
    }

    printf("Listening for incoming connections on port 8080...\n");

    while (1) {
        // Accept an incoming connection
        int client_sock = accept(listen_sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept failed");
            continue;
        }

        // Get the client IP address and port number
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        getpeername(client_sock, (struct sockaddr *)&client_addr, &client_addr_len);

        // Check if the client IP address is allowed
        if (strcmp(client_addr.sin_addr.s_addr, INADDR_ANY) == 0) {
            // Allow all clients
            printf("Connection accepted from %s port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        } else {
            // Deny the connection if the client IP address is not allowed
            printf("Connection rejected from %s port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            close(client_sock);
            continue;
        }

        // Establish a new connection
        struct connection *new_conn = malloc(sizeof(struct connection));
        new_conn->sock = client_sock;
        new_conn->client_addr = client_addr;
        strcpy(new_conn->client_ip, inet_ntoa(client_addr.sin_addr));
        new_conn->established = 1;

        // Add the new connection to the list of active connections
        num_conns++;
        conns = realloc(conns, sizeof(struct connection) * num_conns);
        conns[num_conns - 1] = *new_conn;

        // Handle established connections
        for (int i = 0; i < num_conns; i++) {
            struct connection *conn = &conns[i];
            if (conn->established) {
                // Check if the connection is still active
                if (connect(conn->sock, (struct sockaddr *)&conn->client_addr, sizeof(conn->client_addr)) < 0) {
                    // If the connection is no longer active, close it
                    close(conn->sock);
                    conn->established = 0;
                }
            }
        }
    }

    return 0;
}