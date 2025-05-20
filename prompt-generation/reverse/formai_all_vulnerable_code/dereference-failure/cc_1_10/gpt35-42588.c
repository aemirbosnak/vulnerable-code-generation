//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main()
{
    printf("Welcome to my HTTP client example program!\n\n");

    // Create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1)
    {
        printf("Oops! Failed to create socket.\n");
        return 1;
    }
    else
    {
        printf("Socket creation successful!\n");
    }

    // Get server name and port number from user
    char server_name[BUFFER_SIZE], server_port[BUFFER_SIZE];
    printf("\nPlease enter the server name or IP address: ");
    scanf("%s", server_name);
    printf("Please enter the server port number: ");
    scanf("%s", server_port);

    // Get server info
    struct hostent *server = gethostbyname(server_name);
    if (server == NULL)
    {
        printf("Oops! Failed to get server info.\n");
        return 1;
    }
    else
    {
        printf("Successfully got server info!\n");
    }

    // Set server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*)*(server->h_addr_list)));
    server_address.sin_port = htons(atoi(server_port));

    // Connect to server
    int connection_status = connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    if (connection_status == -1)
    {
        printf("Oops! Failed to connect to server.\n");
        return 1;
    }
    else
    {
        printf("Connection successful!\n");
    }

    // Send GET request to server
    char request[BUFFER_SIZE];
    memset(&request, 0, sizeof(request));
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s:%s\r\n\r\n", server_name, server_port);
    send(client_socket, request, sizeof(request), 0);
    printf("\nSent GET request to server:\n%s", request);

    // Receive response from server
    char response[BUFFER_SIZE];
    memset(&response, 0, sizeof(response));
    recv(client_socket, response, sizeof(response), 0);
    printf("\nReceived response from server:\n%s", response);

    // Close socket
    close(client_socket);
    printf("\nSocket closed. Thank you for using my program!\n");

    return 0;
}