//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void a_case_of_the_mysterious_request(int client_socket, char *buffer)
{
    char method[10], url[256], protocol[10];
    
    sscanf(buffer, "%s %s %s", method, url, protocol);
    
    char hostname[256];
    int port = 80; // Default HTTP port
    
    // Extract hostname from URL
    char *start = strstr(url, "//");
    start = start ? start + 2 : url; // Skip the "http://"
    char *end = strchr(start, '/');
    if (end)
    {
        strncpy(hostname, start, end - start);
        hostname[end - start] = '\0';
    }
    else
    {
        strcpy(hostname, start);
    }

    printf("Observing the method: %s\n", method);
    printf("Discerning the target hostname: %s\n", hostname);

    // Proceed to uncover the truth behind this request
    int server_socket;
    struct sockaddr_in server_addr;

    // Establishing connection to the host
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0)
    {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Connection to the server failed");
        close(server_socket);
        return;
    }

    printf("Connected to the server, now forwarding the request...\n");

    // Forward the request
    send(server_socket, buffer, strlen(buffer), 0);
    
    char response[BUFFER_SIZE];
    int bytes_received;

    // Listen for the reply from the server
    while ((bytes_received = recv(server_socket, response, BUFFER_SIZE - 1, 0)) > 0)
    {
        response[bytes_received] = '\0';
        send(client_socket, response, bytes_received, 0);
    }

    close(server_socket);
    printf("The case is resolved; connection closed.\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Behold, the command must include a listening port.\n");
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);
    int server_socket, client_socket, addr_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    // A distinguished server socket for the noble cause
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0)
    {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Defining the server's characteristics
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Binding this port was unsuccessful");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    listen(server_socket, 5);
    printf("The HTTP Proxy is now listening at port %d. What a sight!\n", port);

    while (1)
    {
        addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addr_len);
        if (client_socket < 0)
        {
            perror("Failed to accept client connection");
            continue; // Providing another chance to listen
        }

        printf("A new suspect has arrived!\n");

        // Receiving the HTTP request
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received < 0)
        {
            perror("Failed to receive data");
            close(client_socket);
            continue;
        }
        buffer[bytes_received] = '\0';
        
        a_case_of_the_mysterious_request(client_socket, buffer);
        close(client_socket);
    }

    close(server_socket);
    printf("The game is afoot! Proxy has terminated.\n");
    return 0;
}