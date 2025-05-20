//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    struct sockaddr_in server_address;
    struct hostent *server;
    int socket_file_descriptor, port_number, sent_bytes, received_bytes;
    char buffer[BUFFER_SIZE];

    // Check if correct number of command-line arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s hostname port message\n", argv[0]);
        exit(1);
    }

    // Convert port number from string to integer
    port_number = atoi(argv[2]);

    // Create socket file descriptor using IPv4 and TCP protocol
    socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_file_descriptor < 0) {
        fprintf(stderr, "Error: Could not create socket\n");
        exit(1);
    }

    // Get host IP address using hostname
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: Could not find host\n");
        exit(1);
    }

    // Set server address family, IP address, and port number
    bzero((char *)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(port_number);

    // Connect to server
    if (connect(socket_file_descriptor, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error: Could not connect to server\n");
        close(socket_file_descriptor);
        exit(1);
    }

    // Send message to server
    sprintf(buffer, "MAIL FROM:<%s>", argv[3]);
    sent_bytes = send(socket_file_descriptor, buffer, strlen(buffer), 0);
    if (sent_bytes < 0) {
        fprintf(stderr, "Error: Could not send message\n");
        close(socket_file_descriptor);
        exit(1);
    }

    // Receive response from server
    bzero(buffer, BUFFER_SIZE);
    received_bytes = recv(socket_file_descriptor, buffer, BUFFER_SIZE, 0);
    if (received_bytes < 0) {
        fprintf(stderr, "Error: Could not receive response\n");
        close(socket_file_descriptor);
        exit(1);
    }
    printf("%s\n", buffer);

    // Close socket file descriptor
    close(socket_file_descriptor);

    return 0;
}