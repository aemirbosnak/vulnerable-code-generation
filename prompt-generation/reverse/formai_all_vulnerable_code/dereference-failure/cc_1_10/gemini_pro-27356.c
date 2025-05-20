//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define MAX_APPOINTMENTS 100

// Structure to store client information
typedef struct client {
    int sockfd;
    char *name;
    char *email;
    char *phone;
    char *appointments[MAX_APPOINTMENTS];
    int num_appointments;
} client;

// Structure to store appointment information
typedef struct appointment {
    char *date;
    char *time;
    char *description;
} appointment;

// Global variables
client clients[MAX_CLIENTS];
int num_clients = 0;
int server_sockfd;

// Function to create a new client
client *create_client(int sockfd, char *name, char *email, char *phone) {
    client *new_client = malloc(sizeof(client));
    new_client->sockfd = sockfd;
    new_client->name = strdup(name);
    new_client->email = strdup(email);
    new_client->phone = strdup(phone);
    new_client->num_appointments = 0;
    return new_client;
}

// Function to add a new appointment to a client
void add_appointment(client *client, appointment *appointment) {
    client->appointments[client->num_appointments++] = strdup(appointment->description);
}

// Function to handle client requests
void handle_client(client *client) {
    while (1) {
        // Receive request from client
        char request[1024];
        int n = recv(client->sockfd, request, sizeof(request), 0);
        if (n == 0) {
            // Client has disconnected
            break;
        }

        // Parse request
        char *command = strtok(request, " ");
        char *args = strtok(NULL, "\n");

        // Execute command
        if (strcmp(command, "ADD_APPOINTMENT") == 0) {
            // Parse appointment details
            char *date = strtok(args, " ");
            char *time = strtok(NULL, " ");
            char *description = strtok(NULL, "\n");

            // Create appointment
            appointment *appointment = malloc(sizeof(appointment));
            appointment->date = strdup(date);
            appointment->time = strdup(time);
            appointment->description = strdup(description);

            // Add appointment to client
            add_appointment(client, appointment);

            // Send confirmation to client
            char response[1024];
            sprintf(response, "APPOINTMENT_ADDED %s", description);
            send(client->sockfd, response, strlen(response), 0);
        } else if (strcmp(command, "GET_APPOINTMENTS") == 0) {
            // Get client's appointments
            char response[1024];
            strcpy(response, "APPOINTMENTS ");
            for (int i = 0; i < client->num_appointments; i++) {
                strcat(response, client->appointments[i]);
                strcat(response, " ");
            }
            send(client->sockfd, response, strlen(response), 0);
        } else if (strcmp(command, "QUIT") == 0) {
            // Client wants to quit
            break;
        }
    }

    // Close client socket
    close(client->sockfd);

    // Free client memory
    free(client->name);
    free(client->email);
    free(client->phone);
    for (int i = 0; i < client->num_appointments; i++) {
        free(client->appointments[i]);
    }
    free(client);
}

// Function to start the server
void start_server(int port) {
    // Create server socket
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Bind server socket to port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
    if (bind(server_sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for client connections
    if (listen(server_sockfd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }

    // Accept client connections
    while (1) {
        // Accept client connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }

        // Get client information
        char name[1024];
        char email[1024];
        char phone[1024];
        recv(client_sockfd, name, sizeof(name), 0);
        recv(client_sockfd, email, sizeof(email), 0);
        recv(client_sockfd, phone, sizeof(phone), 0);

        // Create new client
        client *new_client = create_client(client_sockfd, name, email, phone);

        // Add client to list of clients
        clients[num_clients++] = *new_client;

        // Handle client requests
        handle_client(new_client);
    }

    // Close server socket
    close(server_sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Get port number from command line arguments
    int port = atoi(argv[1]);

    // Start server
    start_server(port);

    return 0;
}