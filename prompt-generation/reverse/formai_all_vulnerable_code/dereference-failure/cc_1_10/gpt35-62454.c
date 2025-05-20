//FormAI DATASET v1.0 Category: Socket programming ; Style: secure
/* A secure C Socket programming example */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CONNECTIONS 10
#define MAX_BUFFER_SIZE 1024

void secure_delete(char *str, int len)
{
    for (int i = 0; i < len; i++)
    {
        str[i] = 0;
    }
    free(str);
}

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char *buffer = (char *)calloc(MAX_BUFFER_SIZE, sizeof(char));

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the given port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the given port
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen to incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1)
    {
        // Accept incoming connection request
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                 (socklen_t *)&addrlen)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted!\n");

        /* Code here to authenticate the client before proceeding */

        // Handle client request
        memset(buffer, 0, MAX_BUFFER_SIZE);
        int valread = read(new_socket, buffer, MAX_BUFFER_SIZE);
        printf("Received message: %s\n", buffer);

        /* Code here to process the client request safely */

        // Send response back to the client
        char *response = "Message received!";
        int res_len = strlen(response);
        int sent_bytes = write(new_socket, response, res_len);
        if (sent_bytes < res_len)
        {
            printf("Failed to send response to client\n");
        }

        // Close the connection
        close(new_socket);

        /* Clear sensitive data from memory */
        secure_delete(buffer, MAX_BUFFER_SIZE);
    }

    return 0;
}