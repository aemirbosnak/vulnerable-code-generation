//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if(argc != 3){
        fprintf(stderr, "Usage: %s HttpAddress PortNumber\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *http_address = argv[1];
    int port_number = atoi(argv[2]);

    struct hostent* host = gethostbyname(http_address);
    if(host == NULL){
        fprintf(stderr, "Failed to get host by name\n");
        exit(EXIT_FAILURE);
    }

    // Set up client socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket < 0){
        fprintf(stderr, "Failed to create client socket\n");
        exit(EXIT_FAILURE);
    }

    // Set up server socket address and connect to server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    memcpy(&server_address.sin_addr.s_addr, host->h_addr, host->h_length);
    server_address.sin_port = htons(port_number);

    if(connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0){
        fprintf(stderr, "Failed to connect to server\n");
        exit(EXIT_FAILURE);
    }

    // Build HTTP request message
    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE, "GET /index.html HTTP/1.1\r\nHost: %s\r\nUser-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:88.0) Gecko/20100101 Firefox/88.0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\nAccept-Language: en-US,en;q=0.5\r\nAccept-Encoding: gzip, deflate\r\nConnection: keep-alive\r\nUpgrade-Insecure-Requests: 1\r\n\r\n", http_address);

    // Send HTTP request to server
    if(send(client_socket, request, strlen(request), 0) < 0){
        fprintf(stderr, "Failed to send HTTP request to server\n");
        exit(EXIT_FAILURE);
    }

    // Receive the HTTP response from the server
    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);

    if(recv(client_socket, response, BUFFER_SIZE, 0) < 0){
        fprintf(stderr, "Failed to receive HTTP response from server\n");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", response);

    // Close client socket
    close(client_socket);

    return EXIT_SUCCESS;
}