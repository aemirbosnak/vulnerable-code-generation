//GEMINI-pro DATASET v1.0 Category: Networking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    // Get the hostname
    char hostname[256];
    gethostname(hostname, sizeof(hostname));

    // Get the host IP address
    struct hostent *he = gethostbyname(hostname);
    if (he == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }
    struct in_addr **addr_list = (struct in_addr **)he->h_addr_list;
    char *ip_address = inet_ntoa(*addr_list[0]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr("8.8.8.8");
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send a request to the server
    const char *request = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    if (send(sock, request, strlen(request), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive a response from the server
    char response[4096];
    int bytes_received = recv(sock, response, sizeof(response), 0);
    if (bytes_received == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response
    printf("%s", response);

    // Close the socket
    close(sock);

    return EXIT_SUCCESS;
}