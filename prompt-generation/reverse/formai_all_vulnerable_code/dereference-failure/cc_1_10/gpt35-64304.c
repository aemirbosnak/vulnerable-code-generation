//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 1024

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sock, port, n;
    char buffer[MAXSIZE], user[MAXSIZE], password[MAXSIZE];
    struct sockaddr_in server_address;

    // Check if the user has provided the correct number of arguments
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <Server Address> <Port>\n", argv[0]);
        exit(1);
    }

    // Create a new socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        error("Failed to create the socket");
    }

    // Initialize server address information
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    port = atoi(argv[2]);
    server_address.sin_port = htons(port);

    // Connect to the server
    if (connect(sock, (struct sockaddr *) &server_address, sizeof(server_address)) < 0)
    {
        error("Failed to connect to the server");
    }

    // Read the response from the server
    memset(buffer, 0, MAXSIZE);
    n = read(sock, buffer, MAXSIZE - 1);
    if (n < 0)
    {
        error("Failed to read from the server");
    }

    // Send the USER command to the server
    printf("%s\n", buffer);
    printf("Username: ");
    fflush(stdout);
    fgets(user, MAXSIZE, stdin);
    sprintf(buffer, "USER %s", user);
    if (send(sock, buffer, strlen(buffer), 0) < 0)
    {
        error("Failed to send the USER command to the server");
    }

    // Read the response from the server
    memset(buffer, 0, MAXSIZE);
    n = read(sock, buffer, MAXSIZE - 1);
    if (n < 0)
    {
        error("Failed to read from the server");
    }
    printf("%s\n", buffer);

    // Send the PASS command to the server
    printf("Password: ");
    fflush(stdout);
    fgets(password, MAXSIZE, stdin);
    sprintf(buffer, "PASS %s", password);
    if (send(sock, buffer, strlen(buffer), 0) < 0)
    {
        error("Failed to send the PASS command to the server");
    }

    // Read the response from the server
    memset(buffer, 0, MAXSIZE);
    n = read(sock, buffer, MAXSIZE - 1);
    if (n < 0)
    {
        error("Failed to read from the server");
    }
    printf("%s\n", buffer);

    // Send the LIST command to the server
    sprintf(buffer, "LIST\r\n");
    if (send(sock, buffer, strlen(buffer), 0) < 0)
    {
        error("Failed to send the LIST command to the server");
    }

    // Read the response from the server
    memset(buffer, 0, MAXSIZE);
    n = read(sock, buffer, MAXSIZE - 1);
    if (n < 0)
    {
        error("Failed to read from the server");
    }
    printf("%s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}