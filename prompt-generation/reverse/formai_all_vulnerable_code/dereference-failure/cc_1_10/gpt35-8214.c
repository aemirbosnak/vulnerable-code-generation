//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 2048

// Function to read server response
int read_response(int sock, char *buffer)
{
    int recv_size = recv(sock, buffer, BUF_SIZE, 0);
    buffer[recv_size] = '\0';
    return recv_size;
}

// Function to send command to server
void send_command(int sock, char *command)
{
    char *temp = (char *)malloc(strlen(command) + 2);
    sprintf(temp, "%s\r\n", command);
    send(sock, temp, strlen(temp), 0);
    free(temp);
}

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char *username, *password;
    char buffer[BUF_SIZE];

    // Check command line arguments
    if (argc != 4) {
        printf("Usage: %s <server address> <username> <password>\n", argv[0]);
        return 1;
    }

    username = argv[2];
    password = argv[3];

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }

    // Configure server address
    server.sin_family = AF_INET;
    server.sin_port = htons(110);
    if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        return 1;
    }

    // Read server response
    read_response(sock, buffer);
    printf("%s", buffer);

    // Send username
    send_command(sock, "USER");
    send_command(sock, username);
    read_response(sock, buffer);
    printf("%s", buffer);

    // Send password
    send_command(sock, "PASS");
    send_command(sock, password);
    read_response(sock, buffer);
    printf("%s", buffer);

    // List emails
    send_command(sock, "LIST");
    read_response(sock, buffer);
    printf("%s", buffer);

    // Quit
    send_command(sock, "QUIT");

    // Close socket
    close(sock);

    return 0;
}