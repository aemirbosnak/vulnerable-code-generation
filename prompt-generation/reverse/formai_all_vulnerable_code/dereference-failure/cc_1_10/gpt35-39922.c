//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {

    // Create socket for server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket < 0) {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }

    // Define socket address details for server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the server socket to the defined address
    if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Socket binding failed!");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if(listen(server_socket, 3) < 0) {
        perror("Socket listening failed!");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    int client_socket;
    struct sockaddr_in client_address;
    int address_size = sizeof(client_address);
    char buffer[MAX_BUFFER_SIZE] = {0};

    while(1) {
        if((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&address_size)) < 0) {
            perror("Socket accept failed!");
            exit(EXIT_FAILURE);
        }

        // Receive data from the client
        int bytes_received = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
        if(bytes_received < 0) {
            perror("Error receiving message from client!");
        } else if(bytes_received == 0) {
            printf("Client disconnected.\n");
        } else {
            printf("Received message from client: %s\n", buffer);

            // Parse the message
            char *token = strtok(buffer, " ");
            char *variables[3] = {0};
            int i = 0;
            while(token != NULL && i < 3) {
                variables[i] = token;
                token = strtok(NULL, " ");
                i++;
            }

            // Do some calculations with the variables
            int result = atoi(variables[0]) * atoi(variables[1]) + atoi(variables[2]);

            // Send the result back to the client
            char response[MAX_BUFFER_SIZE] = {0};
            sprintf(response, "%d", result);
            send(client_socket, response, strlen(response), 0);
        }

        // Clear the buffer
        memset(buffer, 0, MAX_BUFFER_SIZE);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}