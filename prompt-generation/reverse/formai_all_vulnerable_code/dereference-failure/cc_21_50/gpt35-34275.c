//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    // Create the server socket
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sock < 0) {
        perror("Error creating server socket");
        exit(1);
    }

    // Allow reuse of port
    int reuse_addr = 1;
    if(setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &reuse_addr, sizeof(int)) == -1) {
        perror("Error setting socket options");
        exit(1);
    }

    // Set up the server address struct
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind the server socket
    if(bind(server_sock, (struct sockaddr*)&server_addr, sizeof(struct sockaddr_in)) == -1) {
        perror("Error binding server socket");
        exit(1);
    }

    // Listen for incoming connections
    if(listen(server_sock, MAX_CLIENTS) == -1) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    struct sockaddr_in client_addr[MAX_CLIENTS];
    int client_sock[MAX_CLIENTS];
    int num_clients = 0;

    // Server loop
    while(true) {
        // Check for incoming connections
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(server_sock, &read_fds);
        for(int i=0; i<num_clients; i++) {
            FD_SET(client_sock[i], &read_fds);
        }

        // Wait for incoming data
        int max_fd = server_sock;
        for(int i=0; i<num_clients; i++) {
            if(client_sock[i] > max_fd) max_fd = client_sock[i];
        }

        if(select(max_fd+1, &read_fds, NULL, NULL, NULL) == -1) {
            perror("Error waiting for incoming data");
            exit(1);
        }

        // Accept incoming connections
        if(FD_ISSET(server_sock, &read_fds)) {
            socklen_t client_addr_len = sizeof(struct sockaddr_in);
            client_sock[num_clients] = accept(server_sock, (struct sockaddr*)&client_addr[num_clients], &client_addr_len);
            if(client_sock[num_clients] == -1) {
                perror("Error accepting incoming connection");
                exit(1);
            }

            printf("Client connected: %s:%d\n", inet_ntoa(client_addr[num_clients].sin_addr), ntohs(client_addr[num_clients].sin_port));
            num_clients++;
        }

        // Handle incoming data
        for(int i=0; i<num_clients; i++) {
            if(FD_ISSET(client_sock[i], &read_fds)) {
                char buffer[BUFFER_SIZE];
                int bytes_read = recv(client_sock[i], buffer, BUFFER_SIZE, 0);
                if(bytes_read == -1) {
                    perror("Error receiving data from client");
                    exit(1);
                }

                if(bytes_read == 0) {
                    // Client disconnected
                    printf("Client disconnected: %s:%d\n", inet_ntoa(client_addr[i].sin_addr), ntohs(client_addr[i].sin_port));
                    close(client_sock[i]);

                    // Shift the array of client addresses and sockets
                    for(int j=i; j<num_clients; j++) {
                        client_addr[j] = client_addr[j+1];
                        client_sock[j] = client_sock[j+1];
                    }
                    num_clients--;
                } else {
                    // Forward the data to the server
                    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
                    if(server_sock < 0) {
                        perror("Error creating server socket");
                        exit(1);
                    }

                    struct sockaddr_in server_addr;
                    memset(&server_addr, 0, sizeof(struct sockaddr_in));
                    server_addr.sin_family = AF_INET;
                    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
                    server_addr.sin_port = htons(80);

                    if(connect(server_sock, (struct sockaddr*)&server_addr, sizeof(struct sockaddr_in)) == -1) {
                        perror("Error connecting to server");
                        exit(1);
                    }

                    if(send(server_sock, buffer, bytes_read, 0) == -1) {
                        perror("Error sending data to server");
                        exit(1);
                    }

                    // Receive data from the server and forward it to the client
                    while(true) {
                        int bytes_read = recv(server_sock, buffer, BUFFER_SIZE, 0);
                        if(bytes_read == -1) {
                            perror("Error receiving data from server");
                            exit(1);
                        }

                        if(bytes_read == 0) break;

                        if(send(client_sock[i], buffer, bytes_read, 0) == -1) {
                            perror("Error sending data to client");
                            exit(1);
                        }
                    }
                }
            }
        }
    }

    return 0;
}