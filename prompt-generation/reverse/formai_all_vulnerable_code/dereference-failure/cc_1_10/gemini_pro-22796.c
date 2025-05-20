//GEMINI-pro DATASET v1.0 Category: Networking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// A custom error handling macro
#define DIE(msg) do { perror(msg); exit(EXIT_FAILURE); } while(0)

// Function to print the usage of the program
void usage(char *program_name)
{
    printf("Usage: %s <port>\n", program_name);
    printf("Where <port> is the port to listen on.\n");
    exit(EXIT_FAILURE);
}

// Function to set up the server socket
int setup_server_socket(unsigned short port)
{
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        DIE("socket");

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
        DIE("bind");

    // Listen for connections
    if (listen(sockfd, 5) == -1)
        DIE("listen");

    return sockfd;
}

// Function to handle client connections
void handle_client_connection(int sockfd)
{
    char buffer[256];
    int n;

    // Read from the client
    while ((n = read(sockfd, buffer, sizeof(buffer))) > 0)
    {
        // Write back to the client
        if (write(sockfd, buffer, n) == -1)
            DIE("write");
    }

    // Close the connection
    close(sockfd);
}

int main(int argc, char **argv)
{
    int sockfd, client_sockfd;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len;

    // Check for the correct number of arguments
    if (argc != 2)
        usage(argv[0]);

    // Get the port number
    unsigned short port = atoi(argv[1]);

    // Set up the server socket
    sockfd = setup_server_socket(port);

    // Accept client connections
    while (1)
    {
        // Accept a client connection
        client_addr_len = sizeof(client_addr);
        if ((client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len)) == -1)
            DIE("accept");

        // Handle the client connection
        handle_client_connection(client_sockfd);
    }

    // Close the server socket
    close(sockfd);

    return EXIT_SUCCESS;
}