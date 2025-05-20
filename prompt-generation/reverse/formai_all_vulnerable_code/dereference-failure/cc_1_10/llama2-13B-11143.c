//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>

#define PORT 8080

// Structure to hold the client request and response
struct client_req {
    char *request;
    char *response;
};

// Function to handle a client request and send a response
void handle_client_req(int sock, struct client_req *req) {
    // Print the client's request
    printf("Received request from client: %s\n", req->request);

    // Send a response back to the client
    char *response = "Hello, client!";
    send(sock, response, strlen(response), 0);

    // Free the request and response memory
    free(req->request);
    free(req->response);
}

// Function to create a new client socket and listen for incoming requests
int create_client_socket(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind the socket to the port and listen for incoming requests
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Listening on port %d...\n", port);

    return sock;
}

// Function to handle the server's main loop
void server_main_loop(int sock) {
    struct client_req *req;
    while (1) {
        // Accept an incoming client request
        socklen_t client_len = sizeof(struct sockaddr_in);
        int client_sock = accept(sock, (struct sockaddr *)NULL, &client_len);

        // Create a new request and response structure
        req = malloc(sizeof(struct client_req));

        // Read the client's request from the socket
        read(client_sock, req->request, 1024);

        // Handle the client's request and send a response
        handle_client_req(client_sock, req);

        // Free the request and response memory
        free(req->request);
        free(req->response);
    }
}

int main() {
    // Create a new server socket
    int sock = create_client_socket(PORT);

    // Start the server's main loop
    server_main_loop(sock);

    return 0;
}