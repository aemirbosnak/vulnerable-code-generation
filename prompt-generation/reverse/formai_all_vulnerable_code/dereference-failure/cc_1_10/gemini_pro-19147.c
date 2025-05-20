//GEMINI-pro DATASET v1.0 Category: Networking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// A function to print the usage of the program.
void usage(char *program_name) {
    printf("Usage: %s <hostname> <port>\n", program_name);
    printf("Example: %s www.example.com 80\n", program_name);
    exit(EXIT_FAILURE);
}

// A function to resolve a hostname to an IP address.
char *resolve_hostname(char *hostname) {
    struct hostent *host_entry;
    host_entry = gethostbyname(hostname);
    if (host_entry == NULL) {
        fprintf(stderr, "Error resolving hostname: %s\n", hostname);
        exit(EXIT_FAILURE);
    }
    return inet_ntoa(*((struct in_addr *) host_entry->h_addr));
}

// A function to create a socket.
int create_socket(char *ip_address, char *port) {
    int socket_fd;
    struct sockaddr_in server_address;

    // Create a socket.
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address.
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(port));
    server_address.sin_addr.s_addr = inet_addr(ip_address);

    // Connect to the server.
    if (connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    return socket_fd;
}

// A function to send data to a socket.
void send_data(int socket_fd, char *data) {
    if (send(socket_fd, data, strlen(data), 0) == -1) {
        perror("Error sending data");
        exit(EXIT_FAILURE);
    }
}

// A function to receive data from a socket.
char *receive_data(int socket_fd) {
    char buffer[1024];
    int bytes_received;

    bytes_received = recv(socket_fd, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        perror("Error receiving data");
        exit(EXIT_FAILURE);
    }

    return strdup(buffer);
}

// A function to close a socket.
void close_socket(int socket_fd) {
    close(socket_fd);
}

int main(int argc, char **argv) {
    char *hostname, *ip_address, *port, *data, *response;
    int socket_fd;

    // Check the number of arguments.
    if (argc != 3) {
        usage(argv[0]);
    }

    // Get the hostname, port, and data from the command line arguments.
    hostname = argv[1];
    port = argv[2];
    data = "Hello, world!";

    // Resolve the hostname to an IP address.
    ip_address = resolve_hostname(hostname);

    // Create a socket.
    socket_fd = create_socket(ip_address, port);

    // Send data to the socket.
    send_data(socket_fd, data);

    // Receive data from the socket.
    response = receive_data(socket_fd);

    // Print the response.
    printf("Response from server: %s\n", response);

    // Close the socket.
    close_socket(socket_fd);

    return EXIT_SUCCESS;
}