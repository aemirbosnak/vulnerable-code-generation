//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/telnet.h>

#define PORT 8080

// Structure to represent a client connection
struct client_conn {
    int sock;
    char *client_addr;
    int client_port;
};

// Function to create a new client connection
struct client_conn *new_client_conn(int sock, char *client_addr, int client_port) {
    struct client_conn *conn = malloc(sizeof(struct client_conn));
    conn->sock = sock;
    conn->client_addr = client_addr;
    conn->client_port = client_port;
    return conn;
}

// Function to send a message to a client connection
void send_message(int sock, char *message, struct client_conn *conn) {
    send(sock, message, strlen(message), 0);
}

// Function to close a client connection
void close_client_conn(int sock, struct client_conn *conn) {
    close(sock);
    free(conn);
}

// Function to create a server socket
int create_server_socket(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(port)
    };
    bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(sock, 3);
    return sock;
}

// Function to accept a client connection
struct client_conn *accept_client_conn(int sock) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_addr_len);
    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, sizeof(client_ip));
    printf("New client connection from IP: %s, port: %d\n", client_ip, ntohs(client_addr.sin_port));
    return new_client_conn(client_sock, client_ip, ntohs(client_addr.sin_port));
}

int main(int argc, char *argv[]) {
    int server_sock = create_server_socket(PORT);
    struct client_conn *client_conn = accept_client_conn(server_sock);

    // Handle client messages
    while (1) {
        char message[1024];
        read(client_conn->sock, message, 1024);
        printf("Client message: %s\n", message);

        // Send a response back to the client
        char *response = "Hello, client!";
        send_message(client_conn->sock, response, client_conn);
    }

    close_client_conn(server_sock, client_conn);
    return 0;
}