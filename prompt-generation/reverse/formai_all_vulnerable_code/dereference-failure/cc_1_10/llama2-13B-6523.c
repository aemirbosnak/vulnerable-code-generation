//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_LEN 1024
#define MAX_PACKET_LEN 4096

int main(int argc, char *argv[]) {
    int sock, cli_sock;
    struct sockaddr_in cli_addr, serv_addr;
    socklen_t cli_len = sizeof(cli_addr);
    char client_ip[40];
    char client_port[10];
    char buffer[MAX_PACKET_LEN];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Set address and port for the server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);

    // Bind the socket to the address and port
    if (bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("binding failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listening failed");
        exit(1);
    }

    printf("Listening on port %d...\n", 8080);

    // Loop indefinitely to handle incoming connections
    while (1) {
        // Accept an incoming connection
        cli_sock = accept(sock, (struct sockaddr *)&cli_addr, &cli_len);
        if (cli_sock < 0) {
            perror("accept failed");
            continue;
        }

        // Get the client IP address and port
        inet_ntop(AF_INET, &cli_addr.sin_addr, client_ip, sizeof(client_ip));
        sprintf(client_port, "%d", ntohs(cli_addr.sin_port));

        // Check if the client IP address is allowed
        if (strcmp(client_ip, "127.0.0.1") != 0) {
            // Check if the client port is within the allowed range
            if (atoi(client_port) < 8080 || atoi(client_port) > 8090) {
                printf("Blocking incoming connection from %s on port %d...\n", client_ip, atoi(client_port));
                shutdown(cli_sock, SHUT_RD);
                close(cli_sock);
                continue;
            }
        }

        // Read data from the client
        read(cli_sock, buffer, MAX_PACKET_LEN);

        // Print the received data
        printf("Received data from client: %s\n", buffer);

        // Send a response back to the client
        char *response = "Hello, client!";
        send(cli_sock, response, strlen(response), 0);

        // Close the socket
        close(cli_sock);
    }

    return 0;
}