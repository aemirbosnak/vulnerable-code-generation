//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int connect_to_server(char *server_name, int port_number);
void receive_data(int socket, char *buffer, int buffer_size);
void send_data(int socket, char *data);

int main() {
    char server_name[] = "pop.gmail.com"; // Change this to your email provider's POP3 server
    int port_number = 995;
    char username[] = "username@gmail.com"; // Change this to your email address
    char password[] = "password"; // Change this to your email password

    int socket = connect_to_server(server_name, port_number);

    receive_data(socket, NULL, BUFFER_SIZE); // Receive greeting message from server
    send_data(socket, "USER "); // Send username command
    send_data(socket, username);
    send_data(socket, "\r\n");

    receive_data(socket, NULL, BUFFER_SIZE); // Receive acknowledgement message from server
    send_data(socket, "PASS "); // Send password command
    send_data(socket, password);
    send_data(socket, "\r\n");

    receive_data(socket, NULL, BUFFER_SIZE); // Receive another acknowledgement message from server
    send_data(socket, "STAT\r\n"); // Send stat command to get mail summary information

    char buffer[BUFFER_SIZE];
    receive_data(socket, buffer, BUFFER_SIZE); // Receive mail summary information
    printf("Mail summary information: %s", buffer);

    // Close connection
    send_data(socket, "QUIT\r\n");
    close(socket);

    return 0;
}

int connect_to_server(char *server_name, int port_number) {
    struct sockaddr_in server_address;
    struct hostent *server;

    // Get host information
    server = gethostbyname(server_name);

    // Set up the server address struct
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    server_address.sin_addr.s_addr = *((unsigned long*) server->h_addr);

    // Create the socket
    int socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_file_descriptor < 0) {
        perror("Could not create socket");
        exit(1);
    }

    // Connect to the server
    if (connect(socket_file_descriptor, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }

    return socket_file_descriptor;
}

void receive_data(int socket, char *buffer, int buffer_size) {
    ssize_t bytes_received;
    if (buffer == NULL) {
        char discard_buffer[buffer_size];
        bytes_received = recv(socket, discard_buffer, buffer_size - 1, 0); // Discard received data
    } else {
        bytes_received = recv(socket, buffer, buffer_size - 1, 0); // Receive data
        buffer[bytes_received] = '\0'; // Null-terminate received data
    }

    if (bytes_received < 0) {
        perror("Failed to receive data");
        exit(1);
    }
}

void send_data(int socket, char *data) {
    if (send(socket, data, strlen(data), 0) < 0) {
        perror("Failed to send data");
        exit(1);
    }
}