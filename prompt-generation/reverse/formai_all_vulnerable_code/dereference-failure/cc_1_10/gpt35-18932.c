//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: genious
// Custom C Network Quality of Service (QoS) monitor program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define MESSAGE_SIZE 256 // Define maximum message size

int main(int argc, char *argv[]) {

    if (argc < 2) { // Check if IP address or host name argument is provided
        printf("Please provide an IP address or host name as an argument\n");
        return 1;
    }

    char *ip_address = argv[1]; // Retrieve IP address or host name from argument
    int port = 80; // Default port for HTTP request

    // Create TCP socket
    int tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (tcp_socket == -1) {
        printf("Failed to create TCP socket\n");
        return 1;
    }

    // Retrieve host information using getaddrinfo
    struct addrinfo hints;
    struct addrinfo *servinfo;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET; // Use IPv4 addresses
    hints.ai_socktype = SOCK_STREAM; // Use TCP protocol
    int error = getaddrinfo(ip_address, NULL, &hints, &servinfo);
    if (error != 0) {
        printf("Failed to retrieve host information: %s\n", gai_strerror(error));
        return 1;
    }

    // Set server address and port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr = ((struct sockaddr_in *)servinfo->ai_addr)->sin_addr;

    // Connect to server
    printf("Connecting to %s...\n", ip_address);
    int connection_status = connect(tcp_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (connection_status == -1) {
        printf("Failed to connect to server\n");
        return 1;
    }

    printf("Connection established!\n");

    // Send HTTP request to retrieve web page
    char *http_request = "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n";
    char message[MESSAGE_SIZE];
    sprintf(message, http_request, ip_address);
    int bytes_sent = send(tcp_socket, message, strlen(message), 0);
    if (bytes_sent == -1) {
        printf("Failed to send HTTP request\n");
        return 1;
    }

    // Reset message buffer
    memset(message, 0, MESSAGE_SIZE);

    // Start timer
    struct timeval start_time;
    gettimeofday(&start_time, NULL);

    // Receive response from server
    int total_bytes_received = 0;
    while (1) {
        int bytes_received = recv(tcp_socket, message, MESSAGE_SIZE, 0);
        if (bytes_received == -1) {
            printf("Failed to receive data\n");
            return 1;
        } else if (bytes_received == 0) {
            break;
        } else {
            total_bytes_received += bytes_received;
            memset(message, 0, MESSAGE_SIZE);
        }
    }

    // Stop timer
    struct timeval stop_time;
    gettimeofday(&stop_time, NULL);
    double time_elapsed = (double)(stop_time.tv_sec - start_time.tv_sec) + (double)(stop_time.tv_usec - start_time.tv_usec) / 1000000;

    printf("Received %d bytes in %.2f seconds\n", total_bytes_received, time_elapsed);

    // Calculate network speed in bytes per second
    double network_speed = (double)total_bytes_received / time_elapsed;
    printf("Network speed: %.2f bytes/s\n", network_speed);

    // Clean up
    close(tcp_socket);
    freeaddrinfo(servinfo);

    return 0;
}