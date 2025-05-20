//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100

int server_sock;
struct sockaddr_in server_addr;
int client_socks[MAX_CLIENTS];
pthread_t client_threads[MAX_CLIENTS];

void *client_handler(void *arg) {
    int client_sock = *(int *)arg;
    char buffer[1024];
    int n;

    while ((n = read(client_sock, buffer, sizeof(buffer))) > 0) {
        printf("Received message: %s\n", buffer);
        
        // Parse the message and perform the appropriate action
        char *command = strtok(buffer, " ");
        if (strcmp(command, "lights") == 0) {
            char *action = strtok(NULL, " ");
            if (strcmp(action, "on") == 0) {
                // Turn on the lights
                printf("Turning on the lights\n");
                write(client_sock, "Lights turned on\n", strlen("Lights turned on\n"));
            } else if (strcmp(action, "off") == 0) {
                // Turn off the lights
                printf("Turning off the lights\n");
                write(client_sock, "Lights turned off\n", strlen("Lights turned off\n"));
            } else {
                // Send an error message
                printf("Invalid action: %s\n", action);
                write(client_sock, "Invalid action\n", strlen("Invalid action\n"));
            }
        } else if (strcmp(command, "temperature") == 0) {
            // Get the current temperature
            float temperature = 20.0; // Placeholder value
            printf("Current temperature: %f\n", temperature);
            char temperature_str[10];
            snprintf(temperature_str, sizeof(temperature_str), "%f", temperature);
            write(client_sock, temperature_str, strlen(temperature_str));
        } else {
            // Send an error message
            printf("Invalid command: %s\n", command);
            write(client_sock, "Invalid command\n", strlen("Invalid command\n"));
        }
    }

    if (n == 0) {
        printf("Client disconnected\n");
    } else {
        printf("Error reading from client: %s\n", strerror(errno));
    }

    close(client_sock);
    return NULL;
}

int main() {
    // Create the server socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the server socket to non-blocking
    int flags = fcntl(server_sock, F_GETFL);
    if (flags == -1) {
        perror("fcntl");
        return EXIT_FAILURE;
    }
    if (fcntl(server_sock, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl");
        return EXIT_FAILURE;
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the server socket to the address
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_sock, MAX_CLIENTS) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Accept incoming connections in a loop
    while (1) {
        int client_sock = accept(server_sock, NULL, NULL);
        if (client_sock == -1) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                // No new connections available, continue the loop
                continue;
            } else {
                perror("accept");
                return EXIT_FAILURE;
            }
        }

        // Set the client socket to non-blocking
        flags = fcntl(client_sock, F_GETFL);
        if (flags == -1) {
            perror("fcntl");
            return EXIT_FAILURE;
        }
        if (fcntl(client_sock, F_SETFL, flags | O_NONBLOCK) == -1) {
            perror("fcntl");
            return EXIT_FAILURE;
        }

        // Create a new thread to handle the client connection
        int *arg = malloc(sizeof(int));
        *arg = client_sock;
        if (pthread_create(&client_threads[client_sock], NULL, client_handler, arg) != 0) {
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }

    // Close the server socket
    close(server_sock);

    return EXIT_SUCCESS;
}