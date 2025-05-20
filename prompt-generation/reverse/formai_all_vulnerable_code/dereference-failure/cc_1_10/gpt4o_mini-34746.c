//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

// Function prototypes
void handle_ftp_commands(int sock);
void send_command(int sock, const char *cmd);
void receive_response(int sock);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);

    int sock;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    // Convert hostname to IP address
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sock);
        return EXIT_FAILURE;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        return EXIT_FAILURE;
    }

    printf("Successfully connected to the server %s:%d\n", hostname, port);
    handle_ftp_commands(sock);

    // Close the socket
    close(sock);
    return EXIT_SUCCESS;
}

void handle_ftp_commands(int sock) {
    char command[256];
    
    while (1) {
        printf("FTP> ");
        fgets(command, sizeof(command), stdin);

        // Remove trailing newline
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "quit") == 0) {
            printf("Exiting FTP client.\n");
            break;
        }

        send_command(sock, command);
        receive_response(sock);
    }
}

void send_command(int sock, const char *cmd) {
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        perror("Send command failed");
    }
}

void receive_response(int sock) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    
    int bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("Receive response failed");
    } else {
        buffer[bytes_received] = '\0';
        printf("Response: %s\n", buffer);
    }
}