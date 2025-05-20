//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to handle client thread
void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    
    // Read FTP server response
    read(client_socket, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    while(1) {
        // Get user command
        char command[BUFFER_SIZE];
        memset(command, 0, BUFFER_SIZE);
        printf("ftp> ");
        fgets(command, BUFFER_SIZE, stdin);

        // Send command to server
        write(client_socket, command, strlen(command));

        // Read FTP server response
        memset(buffer, 0, BUFFER_SIZE);
        read(client_socket, buffer, BUFFER_SIZE);
        printf("%s\n", buffer);

        // If command is "quit", end thread
        if(strncmp(command, "quit", 4) == 0) {
            break;
        }
    }

    close(client_socket);
    pthread_exit(NULL);
}

// Main function
int main(int argc, char *argv[]) {

    // Check for correct number of arguments
    if(argc != 3) {
        printf("Usage: ./ftp_client hostname port\n");
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket < 0) {
        printf("Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(struct sockaddr_in));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_address.sin_addr);

    if(connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error connecting to server\n");
        exit(EXIT_FAILURE);
    }

    // Spawn client thread
    pthread_t client_thread;
    pthread_create(&client_thread, NULL, handle_client, (void *)&client_socket);

    // Wait for client thread to end
    pthread_join(client_thread, NULL);

    return 0;
}