//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 5
#define MAX_MESSAGE_LENGTH 1024

struct client_connection {
    int sock;
    char client_ip[16];
    char client_port[6];
};

int main(void) {
    int listen_sock, client_sock;
    struct sockaddr_in listen_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[MAX_MESSAGE_LENGTH];
    struct client_connection client_list[MAX_CLIENT_CONNECTIONS];
    int i, j;

    // Create the listening socket
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("Error creating listening socket");
        exit(1);
    }

    // Set up the listening address
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(12345);

    // Bind the listening socket to the address and port
    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("Error binding listening socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_sock, 3) < 0) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    // Accept an incoming connection
    client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("Error accepting incoming connection");
        exit(1);
    }

    // Print the client's IP address and port
    printf("Connection accepted from IP address: %s, port: %s\n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Add the client to the list of connected clients
    for (i = 0; i < MAX_CLIENT_CONNECTIONS; i++) {
        if (client_list[i].sock == 0) {
            break;
        }
    }
    client_list[i].sock = client_sock;
    strcpy(client_list[i].client_ip, inet_ntoa(client_addr.sin_addr));
    strcpy(client_list[i].client_port, ntohs(client_addr.sin_port));

    // Loop indefinitely to handle incoming messages from clients
    while (1) {
        // Receive a message from the client
        recv(client_sock, buffer, MAX_MESSAGE_LENGTH, 0);

        // Print the message to the console
        printf("Received message from client: %s\n", buffer);

        // Send a response back to the client
        send(client_sock, "Hello, client!", 13, 0);
    }

    // Close the client socket
    close(client_sock);

    // Close the listening socket
    close(listen_sock);

    return 0;
}