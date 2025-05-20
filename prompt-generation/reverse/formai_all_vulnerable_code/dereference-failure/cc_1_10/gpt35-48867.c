//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    // Print welcome message
    printf("Welcome to HTTP client program!\n");

    // Check command line arguments
    if (argc < 2) {
        printf("Usage: %s [URL]\n", argv[0]);
        return 1;
    }

    // Parse URL
    char *url = argv[1];
    char *host_name = url;
    char *port_number = "80";
    char *path_name = "/";
    char *slash_pos = strstr(url, "/");
    if (slash_pos != NULL) {
        *slash_pos = '\0';
        path_name = slash_pos + 1;
        host_name = url;
    }
    char *colon_pos = strstr(host_name, ":");
    if (colon_pos != NULL) {
        *colon_pos = '\0';
        port_number = colon_pos + 1;
    }

    // Print URL components
    printf("Host name: %s\n", host_name);
    printf("Port number: %s\n", port_number);
    printf("Path name: %s\n", path_name);

    // Get host address
    struct hostent *server = gethostbyname(host_name);
    if (server == NULL) {
        printf("Error: No such host %s\n", host_name);
        return 1;
    }
    char *host_address = inet_ntoa(*((struct in_addr *) server->h_addr_list[0]));
    printf("Host address: %s\n", host_address);

    // Create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        printf("Error: Failed to create socket\n");
        return 1;
    }

    // Connect to server
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(port_number));
    server_address.sin_addr.s_addr = inet_addr(host_address);
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Error: Failed to connect to server\n");
        return 1;
    }

    // Send HTTP request
    char *request = malloc(BUFFER_SIZE);
    memset(request, 0, BUFFER_SIZE);
    sprintf(request, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path_name, host_name);
    printf("HTTP request:\n%s", request);
    if (send(client_socket, request, strlen(request), 0) < 0) {
        printf("Error: Failed to send HTTP request\n");
        return 1;
    }
    free(request);

    // Receive HTTP response
    char *response = malloc(BUFFER_SIZE);
    int bytes_received = recv(client_socket, response, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        printf("Error: Failed to receive HTTP response\n");
        return 1;
    }
    response[bytes_received] = '\0';
    printf("HTTP response:\n%s", response);
    free(response);

    // Close socket
    close(client_socket);

    // Print goodbye message
    printf("Thank you for using HTTP client program!\n");

    return 0;
}