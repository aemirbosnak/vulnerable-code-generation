//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_SIZE 2048

int main(int argc, char *argv[]) {

    // Check for correct usage
    if (argc != 3) {
        printf("Usage: ./httpclient <server_hostname> <server_port>\n");
        exit(EXIT_FAILURE);
    }

    // Obtain server details
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Couldn't create socket");
        exit(EXIT_FAILURE);
    }

    // Setup server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &(server_address.sin_addr));

    // Connect to server
    int connection = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (connection < 0) {
        perror("Couldn't connect to server");
        exit(EXIT_FAILURE);
    }

    // Create HTTP request
    char *request = "GET / HTTP/1.1\r\nHost: ";
    strcat(request, hostname);
    char *end_request = "\r\n\r\n";
    strcat(request, end_request);

    // Send request to server
    if (send(client_socket, request, strlen(request), 0) < 0 ) {
        perror("Couldn't send request");
        exit(EXIT_FAILURE);
    }

    // Receive response from server
    char response[MAX_SIZE];
    memset(response, 0, MAX_SIZE);
    int received_bytes = recv(client_socket, response, MAX_SIZE, 0);
    if (received_bytes < 0) {
        perror("Couldn't receive response");
        exit(EXIT_FAILURE);
    }

    // Print server response
    printf("%s\n", response);

    // Close socket
    close(client_socket);
    return 0;
}