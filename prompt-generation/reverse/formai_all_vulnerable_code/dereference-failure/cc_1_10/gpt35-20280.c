//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFF_SIZE 1024

// Function to print the response from the server
void print_response(char *response)
{
    printf("Server response:\n%s\n", response);
}

int main()
{
    // Variables
    int sock_fd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Buffer for sending/receiving messages
    char buff[MAX_BUFF_SIZE];

    // Connection information
    char server_name[] = "pop.gmail.com";
    int port_number = 995;
    char username[] = "myemail@gmail.com";
    char password[] = "mypassword";

    // Create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Check for error creating socket
    if (sock_fd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Get host information
    server = gethostbyname(server_name);

    // Check for error getting host information
    if (!server)
    {
        fprintf(stderr, "Error: no such host %s\n", server_name);
        exit(1);
    }

    // Set server address information
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port_number);

    // Connect to server
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Read welcome message from server
    memset(buff, 0, MAX_BUFF_SIZE);
    if (read(sock_fd, buff, MAX_BUFF_SIZE) < 0)
    {
        perror("Error reading message from server");
        exit(1);
    }

    print_response(buff);

    // Send user information
    sprintf(buff, "USER %s\n", username);
    if (send(sock_fd, buff, strlen(buff), 0) < 0)
    {
        perror("Error sending message to server");
        exit(1);
    }

    // Read response from server
    memset(buff, 0, MAX_BUFF_SIZE);
    if (read(sock_fd, buff, MAX_BUFF_SIZE) < 0)
    {
        perror("Error reading message from server");
        exit(1);
    }

    print_response(buff);

    // Send password information
    sprintf(buff, "PASS %s\n", password);
    if (send(sock_fd, buff, strlen(buff), 0) < 0)
    {
        perror("Error sending message to server");
        exit(1);
    }

    // Read response from server
    memset(buff, 0, MAX_BUFF_SIZE);
    if (read(sock_fd, buff, MAX_BUFF_SIZE) < 0)
    {
        perror("Error reading message from server");
        exit(1);
    }

    print_response(buff);

    // Retrieve message
    sprintf(buff, "RETR 1\n");
    if (send(sock_fd, buff, strlen(buff), 0) < 0)
    {
        perror("Error sending message to server");
        exit(1);
    }

    // Read response from server
    memset(buff, 0, MAX_BUFF_SIZE);
    if (read(sock_fd, buff, MAX_BUFF_SIZE) < 0)
    {
        perror("Error reading message from server");
        exit(1);
    }

    print_response(buff);

    // Close socket
    close(sock_fd);

    return 0;
}