//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int send_data(int socket, char *data);
char *receive_data(int socket);

int main()
{
    // Declare socket variables
    int client_socket;
    struct sockaddr_in server_address;

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(25);

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Send HELO command
    send_data(client_socket, "HELO example.com\r\n");
    printf("%s", receive_data(client_socket)); // Print server response

    // Send MAIL FROM command
    send_data(client_socket, "MAIL FROM:<sender@example.com>\r\n");
    printf("%s", receive_data(client_socket)); // Print server response

    // Send RCPT TO command
    send_data(client_socket, "RCPT TO:<recipient@example.com>\r\n");
    printf("%s", receive_data(client_socket)); // Print server response

    // Send DATA command
    send_data(client_socket, "DATA\r\n");
    printf("%s", receive_data(client_socket)); // Print server response

    // Send message data
    send_data(client_socket, "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test email\r\n\r\nHello, this is a test email.\r\n.\r\n");
    printf("%s", receive_data(client_socket)); // Print server response

    // Send QUIT command
    send_data(client_socket, "QUIT\r\n");
    printf("%s", receive_data(client_socket)); // Print server response

    // Close socket
    close(client_socket);

    return 0;
}

// Function to send data to server
int send_data(int socket, char *data)
{
    int bytes_sent;
    if ((bytes_sent = send(socket, data, strlen(data), 0)) == -1)
    {
        perror("Error sending data");
        exit(EXIT_FAILURE);
    }
    return bytes_sent;
}

// Function to receive data from server
char *receive_data(int socket)
{
    char *buffer = malloc(MAX_BUFFER_SIZE);
    int bytes_received;
    if ((bytes_received = recv(socket, buffer, MAX_BUFFER_SIZE, 0)) == -1)
    {
        perror("Error receiving data");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    return buffer;
}