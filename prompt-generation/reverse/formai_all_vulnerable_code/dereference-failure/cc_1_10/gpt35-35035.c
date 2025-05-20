//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: standalone
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1000

int main(int argc, char *argv[]) {
    int sock, port;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char request[BUFFER_SIZE];
    char* message = "Hello, world!";
    port = 80;
    
    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Could not create socket");
        return 1;
    }

    // Get the IP address for the server
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        perror("Could not find host");
        return 1;
    }

    // Populate the server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Could not connect");
        return 1;
    }

    // Build the request string
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);

    // Send the request
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("Could not send request");
        return 1;
    }

    // Receive the response and print it
    while (recv(sock, buffer, BUFFER_SIZE, 0) > 0) {
        printf("%s", buffer);
    }

    // Clean up
    close(sock);
    return 0;
}