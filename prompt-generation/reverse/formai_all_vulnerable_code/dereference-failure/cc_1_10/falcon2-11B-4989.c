//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int socket_fd, port_number, n;
    struct sockaddr_in server_address;
    char message[256];
    char buffer[256];

    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        printf("Error: Unable to create socket\n");
        exit(1);
    }

    // Fill in the server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[1]));
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Unable to connect to server\n");
        exit(1);
    }

    // Receive message from server
    n = read(socket_fd, buffer, sizeof(buffer));
    if (n < 0) {
        printf("Error: Unable to read from server\n");
        exit(1);
    }

    // Display received message
    printf("Server: %s\n", buffer);

    // Get message from user
    printf("Enter message to send to server: ");
    fgets(message, 255, stdin);

    // Send message to server
    n = write(socket_fd, message, strlen(message));
    if (n < 0) {
        printf("Error: Unable to write to server\n");
        exit(1);
    }

    // Close socket
    close(socket_fd);

    return 0;
}