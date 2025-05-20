//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Structure to hold the client and server information
struct sock_info {
    int sock;
    struct sockaddr_in client_addr;
    char buffer[1024];
};

// Function to create a socket and bind it to a specific address and port
int create_socket(int domain, int type, int protocol) {
    int sock = socket(domain, type, protocol);
    if (sock < 0) {
        perror("Error creating socket");
        return sock;
    }
    return sock;
}

// Function to bind a socket to a specific address and port
int bind_socket(int sock, struct sockaddr_in *addr) {
    if (bind(sock, addr, sizeof(*addr)) < 0) {
        perror("Error binding socket");
        close(sock);
        return -1;
    }
    return sock;
}

// Function to listen for incoming connections
int listen_socket(int sock) {
    if (listen(sock, 3) < 0) {
        perror("Error listening for incoming connections");
        close(sock);
        return -1;
    }
    return sock;
}

// Function to accept an incoming connection and create a new socket
int accept_socket(int sock) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("Error accepting incoming connection");
        close(sock);
        return -1;
    }
    return client_sock;
}

// Function to send and receive data on a socket
int send_recv_data(int sock, char *data, int len) {
    int sent = send(sock, data, len, 0);
    if (sent < 0) {
        perror("Error sending data");
        return -1;
    }
    int recv_len = recv(sock, NULL, 0, 0);
    if (recv_len < 0) {
        perror("Error receiving data");
        return -1;
    }
    char *recv_data = malloc(recv_len + 1);
    recv(sock, recv_data, recv_len, 0);
    recv_data[recv_len] = '\0';
    return recv_data;
}

// Function to create a server and listen for incoming connections
int main() {
    int server_sock = create_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };
    bind_socket(server_sock, &server_addr);
    listen_socket(server_sock);

    // Loop to listen for incoming connections
    while (1) {
        int client_sock = accept_socket(server_sock);
        struct sock_info *client_info = malloc(sizeof(*client_info));
        client_info->sock = client_sock;
        client_info->client_addr = server_addr;
        char *client_data = send_recv_data(client_sock, "Hello, client!", 13);
        if (client_data == NULL) {
            perror("Error sending or receiving data");
            close(client_sock);
            continue;
        }
        printf("Received message from client: %s\n", client_data);
        free(client_data);
        close(client_sock);
    }
    return 0;
}