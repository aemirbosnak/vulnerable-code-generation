//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: statistical
/* In this program, we will transmit data between a server and multiple clients using TCP/IP protocol. We will collect statistical data about the transmission speed and number of successful transmissions. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

// Define the port number and buffer size
#define PORT 8080
#define BUFFER_SIZE 1024

// Define global variables
int successful_transmissions = 0;
int total_transmissions = 0;
clock_t start_time;
clock_t end_time;

// Define the function to handle the connection with the clients
void *client_handler(void *client_socket_void_p)
{
    int client_socket = *((int *)client_socket_void_p);
    char buffer[BUFFER_SIZE];
    while (1)
    {
        // Receive data from the client
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received < 0)
        {
            printf("Error receiving data from the client\n");
            break;
        }
        else if (bytes_received == 0)
        {
            printf("Client disconnected\n");
            break;
        }

        // Transmit the data back to the client
        int bytes_sent = send(client_socket, buffer, bytes_received, 0);
        if (bytes_sent < 0)
        {
            printf("Error transmitting data to the client\n");
            break;
        }

        // Increment the counters
        successful_transmissions++;
        total_transmissions++;

        // Check if the time limit has been reached
        end_time = clock();
        double time_diff = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        if (time_diff >= 60)
        {
            printf("Total transmissions: %d\n", total_transmissions);
            printf("Successful transmissions: %d\n", successful_transmissions);
            printf("Transmission success rate: %.2f%%\n", (double)successful_transmissions / total_transmissions * 100);

            // Reset the counters and restart the timer
            successful_transmissions = 0;
            total_transmissions = 0;
            start_time = clock();
        }
    }

    // Close the socket and return
    close(client_socket);
    return NULL;
}

int main()
{
    // Initialize the socket variables
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);

    // Bind the socket to the specified port
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0)
    {
        printf("Error creating socket\n");
        return -1;
    }
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        printf("Error binding socket\n");
        return -1;
    }

    // Start listening for incoming connections
    listen(server_socket, 5);

    // Start the timer
    start_time = clock();

    // Wait for incoming connections and handle them
    printf("Listening for incoming connections on port %d\n", PORT);
    while (1)
    {
        // Accept the incoming connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket < 0)
        {
            printf("Error accepting connection\n");
            continue;
        }

        // Create a new thread to handle the client
        pthread_t client_thread;
        int *client_socket_p = malloc(sizeof(int));
        *client_socket_p = client_socket;
        if (pthread_create(&client_thread, NULL, client_handler, client_socket_p) < 0)
        {
            printf("Error creating thread for client\n");
            continue;
        }
        pthread_detach(client_thread);
    }

    // Close the server socket and return
    close(server_socket);
    return 0;
}