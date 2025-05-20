//FormAI DATASET v1.0 Category: Firewall ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: ./firewall <port_number>\n");
        exit(0);
    }

    int port_number = atoi(argv[1]);

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER_SIZE] = {0};
    char* message = "Access Denied. Firewall enabled.\n";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }    

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port_number);

    // Binding the socket to the specified port
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Waiting for clients to connect
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Firewall enabled on port %d\n", port_number);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        valread = read(new_socket, buffer, MAX_BUFFER_SIZE);

        if (valread > 0) {
            char* ip_address = inet_ntoa(address.sin_addr);
            printf("Connection request received from %s\n", ip_address);
            printf("Request: %s\n", buffer);

            // Example firewall rule - block all messages containing the string "password"
            if (strstr(buffer, "password") != NULL) {
                printf("Firewall blocked message from %s.\n", ip_address);
                send(new_socket, message, strlen(message), 0);
            }
            else {
                // Forward the message to the destination server
                // In this example, we are not implementing any actual server logic
                // Instead, we just reply with an acknowledgement message
                printf("Forwarding message to server.\n");
                send(new_socket, "Message received.\n", 18, 0);
            }
        }
        else {
            printf("Invalid request received from %s\n", inet_ntoa(address.sin_addr));
        }

        memset(buffer, 0, MAX_BUFFER_SIZE);
        close(new_socket);
    }

    return 0;
}