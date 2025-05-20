//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

char* read_message(int socket_fd);
void send_message(int socket_fd, const char* message);

int main(int argc, char** argv)
{
    if (argc < 4)
    {
        printf("Usage: %s <server_ip> <server_port> <username> <password>\n", argv[0]);
        return 1;
    }

    // Create a socket for connecting to the POP3 server
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1)
    {
        perror("Failed to create socket");
        return 1;
    }

    // Set up the address for the POP3 server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    // Connect to the POP3 server
    if (connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1)
    {
        perror("Failed to connect to server");
        return 1;
    }

    // Read the greeting from the server
    char* response = read_message(socket_fd);
    printf("%s\n", response);
    free(response);

    // Send the user's credentials
    char message[BUFFER_SIZE];
    sprintf(message, "USER %s\r\n", argv[3]);
    send_message(socket_fd, message);
    response = read_message(socket_fd);
    printf("%s\n", response);
    free(response);

    sprintf(message, "PASS %s\r\n", argv[4]);
    send_message(socket_fd, message);
    response = read_message(socket_fd);
    printf("%s\n", response);
    free(response);

    // List the user's email
    send_message(socket_fd, "LIST\r\n");
    response = read_message(socket_fd);
    printf("%s\n", response);
    free(response);

    // Quit the session
    send_message(socket_fd, "QUIT\r\n");
    response = read_message(socket_fd);
    printf("%s\n", response);
    free(response);

    // Close the socket
    close(socket_fd);

    return 0;
}

char* read_message(int socket_fd)
{
    char* buffer = (char*)malloc(BUFFER_SIZE);
    int num_bytes = recv(socket_fd, buffer, BUFFER_SIZE-1, 0);
    if (num_bytes == -1)
    {
        perror("Failed to receive message");
        exit(1);
    }
    buffer[num_bytes] = '\0';
    return buffer;
}

void send_message(int socket_fd, const char* message)
{
    int num_bytes = send(socket_fd, message, strlen(message), 0);
    if (num_bytes == -1)
    {
        perror("Failed to send message");
        exit(1);
    }
}