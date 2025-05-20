//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO_SERVER "myfifo_server"
#define FIFO_CLIENT "myfifo_client"
#define BUFFER_SIZE 100

// Server code
void run_server() {
    char buffer[BUFFER_SIZE];
    int server_fd;

    // Create the FIFO if it doesn't exist
    mkfifo(FIFO_SERVER, 0666);
    mkfifo(FIFO_CLIENT, 0666);

    printf("Server: Waiting for client...\n");

    // Open the FIFO for reading
    server_fd = open(FIFO_SERVER, O_RDONLY);
    
    while (1) {
        // Read message from client
        read(server_fd, buffer, sizeof(buffer));
        printf("Server: Received message: %s\n", buffer);
        
        // Breaking condition for server
        if (strcmp(buffer, "exit") == 0) {
            printf("Server: Exiting...\n");
            break;
        }
        
        // Prepare response message
        snprintf(buffer, sizeof(buffer), "Server received: %s", buffer);

        // Open client FIFO for writing
        int client_fd = open(FIFO_CLIENT, O_WRONLY);
        write(client_fd, buffer, strlen(buffer) + 1);
        close(client_fd);
    }

    close(server_fd);
    unlink(FIFO_SERVER);
    unlink(FIFO_CLIENT);
}

// Client code
void run_client() {
    char buffer[BUFFER_SIZE];
    int client_fd;

    // Open server FIFO for writing
    client_fd = open(FIFO_SERVER, O_WRONLY);

    while (1) {
        printf("Client: Enter message (type 'exit' to quit): ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove the newline character

        // Send message to server
        write(client_fd, buffer, strlen(buffer) + 1);

        // Breaking condition for client
        if (strcmp(buffer, "exit") == 0) {
            printf("Client: Exiting...\n");
            break;
        }

        // Open client FIFO for reading
        int server_fd = open(FIFO_CLIENT, O_RDONLY);
        read(server_fd, buffer, sizeof(buffer));
        printf("Client: Received response: %s\n", buffer);
        close(server_fd);
    }

    close(client_fd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <server|client>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "server") == 0) {
        run_server();
    } else if (strcmp(argv[1], "client") == 0) {
        run_client();
    } else {
        fprintf(stderr, "Invalid option! Use 'server' or 'client'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}