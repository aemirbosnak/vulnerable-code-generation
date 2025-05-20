//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    int port;
    char response[BUFFER_SIZE];
    int response_len;

    // Check if the correct number of arguments are provided
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    // Convert the IP address from string to integer
    struct in_addr ip_address;
    inet_pton(AF_INET, argv[1], &ip_address);

    // Set the server's address
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = ip_address.s_addr;

    // Set the initial and maximum port numbers
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX_PORTS - 1;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Loop through all ports and check if they are open
    for (port = start_port; port <= end_port; port++) {
        // Set the port number
        server.sin_port = htons(port);

        // Connect to the server
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            // Send a request to the server
            send(sock, "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n", 
                strlen("GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n"), 0);

            // Receive a response from the server
            response_len = recv(sock, response, BUFFER_SIZE, 0);
            if (response_len > 0) {
                response[response_len] = '\0';
                printf("Port %d is open\n", port);
            }
        } else {
            // If the connection fails, the port is closed
            printf("Port %d is closed\n", port);
        }
    }

    // Close the socket
    close(sock);

    return 0;
}