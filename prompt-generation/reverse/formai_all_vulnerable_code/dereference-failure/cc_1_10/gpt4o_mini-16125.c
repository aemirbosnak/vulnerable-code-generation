//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_PORT 21
#define BUFFER_SIZE 1024
#define FTP_CMD_SIZE 32

// In a world ravaged by the apocalypse, communication is scarce. FTP is our remaining hope.

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Structure to hold our FTP Client details.
typedef struct {
    char *server_ip;
    int server_port;
    int sockfd;
} FTPClient;

// Initialize our FTP client.
void initialize_client(FTPClient *client, const char *ip, int port) {
    client->server_ip = strdup(ip); // Copy the server IP
    client->server_port = port;       // Set the server port
    client->sockfd = -1;              // Initially no socket
}

// Create the FTP connection.
void connect_to_server(FTPClient *client) {
    struct sockaddr_in server_addr;

    if ((client->sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error("Unable to create socket");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(client->server_port);
    
    if (inet_pton(AF_INET, client->server_ip, &server_addr.sin_addr) <= 0)
        error("Invalid address");

    if (connect(client->sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("Connection failed");
    
    printf("Connected to FTP server at %s:%d\n", client->server_ip, client->server_port);
}

// Send command to the FTP server
void send_command(FTPClient *client, const char *cmd) {
    send(client->sockfd, cmd, strlen(cmd), 0);
}

// Receive server response
void receive_response(FTPClient *client) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    bytes_received = recv(client->sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        error("Failed to receive response");
    }
    buffer[bytes_received] = '\0'; // Null-terminate the string
    printf("Response: %s\n", buffer);
}

// Execute simple FTP commands
void ftp_commands(FTPClient *client) {
    char cmd[FTP_CMD_SIZE];

    while (1) {
        printf("ftp> ");
        if (fgets(cmd, sizeof(cmd), stdin) == NULL)
            break;
        
        cmd[strcspn(cmd, "\n")] = 0; // Remove newline

        // Special command to quit
        if (strcmp(cmd, "quit") == 0) {
            printf("Disconnecting...\n");
            break;
        }

        // Send command to the server
        send_command(client, cmd);
        receive_response(client);
    }
}

// Clean up resources
void cleanup(FTPClient *client) {
    close(client->sockfd);
    free(client->server_ip);
    printf("Disconnected from server.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // In the ruins of civilization, we must build our connection.
    FTPClient client;
    initialize_client(&client, argv[1], atoi(argv[2]));
    
    connect_to_server(&client);
    ftp_commands(&client);
    cleanup(&client);

    return EXIT_SUCCESS;
}