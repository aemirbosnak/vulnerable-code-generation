//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

// Function to get IP address from hostname
char *get_ip_address(char *host)
{
    struct hostent *hent;
    int n;

    hent = gethostbyname(host);

    if (hent == NULL)
    {
        printf("Error resolving hostname\n");
        exit(EXIT_FAILURE);
    }

    struct in_addr **addresses = (struct in_addr **) hent->h_addr_list;

    for (n = 0; addresses[n] != NULL; n++)
    {
        printf("%s\n", inet_ntoa(*addresses[n]));
    }

    return inet_ntoa(*addresses[0]);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *host = argv[1];
    char *ip;
    int port = 80;

    // Get IP address of the hostname
    ip = get_ip_address(host);

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    // Check if socket was created successfully
    if (sock == -1)
    {
        printf("Error creating socket\n");
        return EXIT_FAILURE;
    }

    // Connect to server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error connecting to server\n");
        return EXIT_FAILURE;
    }

    // Send HTTP request to server
    char *request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    send(sock, request, strlen(request), 0);

    // Receive HTTP response from server
    char response[4096];
    int recv_size = recv(sock, response, 4096, 0);

    // Print HTTP response
    printf("%.*s", recv_size, response);

    // Close socket
    close(sock);

    return EXIT_SUCCESS;
}