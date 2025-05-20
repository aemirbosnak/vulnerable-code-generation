//FormAI DATASET v1.0 Category: Networking ; Style: statistical
/* This program demonstrates a simple client-server communication system using sockets.
 * The server collects statistical data from the connected clients and displays it to the user.
 * The program creates a server socket, binds it to a port, listens for client connections and accepts them.
 * Once a client is connected, the server receives data sent by the client, analyzes it and sends back a response.
 * The communication between the server and the client is done using TCP/IP sockets.
 * Inspirational credit to GeeksforGeeks.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 5   // maximum number of clients that can connect to the server
#define BUFFER_SIZE 256 // maximum size of the buffer used for receiving and sending data

int main() {
    // create a socket for the server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error: could not create socket.");
        return 1;
    }
    
    // bind the socket to an IP address and a port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(10000);
    
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        printf("Error: could not bind.");
        return 1;
    }
    
    // listen for client connections
    printf("Server listening for connections...\n");
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error: could not listen.");
        return 1;
    }
    
    // accept client connections and receive data from them
    int client_socket, client_address_size;
    struct sockaddr_in client_address;
    char buffer[BUFFER_SIZE];
    int numbers_count = 0, numbers_sum = 0, numbers_average = 0;
    
    while (1) {
        client_address_size = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_size);
        if (client_socket == -1) {
            printf("Error: could not accept connection.");
            continue;
        }
        
        // receive data from the client
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error: could not receive data.");
            continue;
        }
        
        buffer[bytes_received] = '\0';
        printf("Received data from %s:%d: %s\n", 
                inet_ntoa(client_address.sin_addr),
                ntohs(client_address.sin_port),
                buffer);
        
        // analyze the data and send a response back to the client
        sscanf(buffer, "%d %d %d", &numbers_count, &numbers_sum, &numbers_average);
        numbers_count++;
        numbers_sum += numbers_average;
        numbers_average = numbers_sum / numbers_count;
        snprintf(buffer, BUFFER_SIZE, "%d %d %d", numbers_count, numbers_sum, numbers_average);
        
        if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
            printf("Error: could not send data.");
            continue;
        }
        
        printf("Sent data to %s:%d: %s\n", 
                inet_ntoa(client_address.sin_addr),
                ntohs(client_address.sin_port),
                buffer);
        
        close(client_socket);
    }
    
    close(server_socket);
    return 0;
}