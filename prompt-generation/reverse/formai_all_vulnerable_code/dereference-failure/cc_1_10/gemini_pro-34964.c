//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Define the maximum number of connections
#define MAX_CONNECTIONS 100

// Define the maximum size of a packet
#define MAX_PACKET_SIZE 1024

// Define the port number to listen on
#define PORT_NUMBER 5555

// Define the number of threads to use
#define NUM_THREADS 4

// Initialize a lock to protect the global variables
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// Define the global variables
int num_connections = 0;
int connections[MAX_CONNECTIONS];

// Define the thread function
void *thread_function(void *arg)
{
    int client_socket = *(int *)arg;
    char buffer[MAX_PACKET_SIZE];

    // Receive a packet from the client
    int num_bytes_received = recv(client_socket, buffer, MAX_PACKET_SIZE, 0);

    // If there was an error receiving the packet, close the client socket
    if (num_bytes_received < 0)
    {
        close(client_socket);
        pthread_exit(NULL);
    }

    // Otherwise, process the packet
    else
    {
        // Get the IP address of the client
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        getpeername(client_socket, (struct sockaddr *)&client_addr, &client_addr_len);

        // Print the IP address of the client
        printf("Received a packet from %s\n", inet_ntoa(client_addr.sin_addr));

        // Send a packet back to the client
        send(client_socket, buffer, num_bytes_received, 0);

        // Close the client socket
        close(client_socket);
    }

    // Exit the thread
    pthread_exit(NULL);
}

// Define the main function
int main(int argc, char *argv[])
{
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // If there was an error creating the socket, print an error message and exit
    if (server_socket < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Set the socket options
    int optval = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
    {
        perror("Error setting socket options");
        exit(1);
    }

    // Bind the socket to the port number
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT_NUMBER);
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for connections on the socket
    if (listen(server_socket, MAX_CONNECTIONS) < 0)
    {
        perror("Error listening for connections");
        exit(1);
    }

    // Create a pool of threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++)
    {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0)
        {
            perror("Error creating thread");
            exit(1);
        }
    }

    // Accept connections from clients
    while (1)
    {
        // Accept a connection from a client
        int client_socket = accept(server_socket, NULL, NULL);

        // If there was an error accepting the connection, print an error message and continue
        if (client_socket < 0)
        {
            perror("Error accepting connection");
            continue;
        }

        // Otherwise, add the client socket to the list of connections and increment the number of connections
        pthread_mutex_lock(&lock);
        connections[num_connections] = client_socket;
        num_connections++;
        pthread_mutex_unlock(&lock);
    }

    // Close the server socket
    close(server_socket);

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Exit the program
    return 0;
}