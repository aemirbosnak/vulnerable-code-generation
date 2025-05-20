//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Structure to store client information
struct client_info {
    int sock;
    char name[50];
};

// Function to create a new client socket
int create_client_socket(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    return connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0;
}

// Function to send and receive data between client and server
void communicate(int sock) {
    char buffer[1024];
    int recv_len = recv(sock, buffer, 1024, 0);
    printf("Received message from client: %s\n", buffer);
    send(sock, "Hello, client!", 13, 0);
}

int main(int argc, char *argv[]) {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(1);
    }
    if (listen(server_sock, 3) < 0) {
        perror("Listen failed");
        exit(1);
    }
    printf("Server listening on port %d...\n", PORT);
    int client_sock = accept(server_sock, NULL, NULL);
    struct client_info *client_info = malloc(sizeof(struct client_info));
    client_info->sock = client_sock;
    char *name = "Anonymous";
    if (getnameinfo((struct sockaddr *)&client_info->sock, sizeof(struct sockaddr_in), name, 50, NULL, 0, NULL) == 0) {
        printf("Client connected: %s\n", name);
    }
    communicate(client_sock);
    close(client_sock);
    free(client_info);
    close(server_sock);
    return 0;
}