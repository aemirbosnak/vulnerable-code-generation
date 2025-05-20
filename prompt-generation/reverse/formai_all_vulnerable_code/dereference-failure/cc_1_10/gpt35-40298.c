//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: Could not resolve '%s'\n", hostname);
        return 1;
    }

    char *ip_address = inet_ntoa(*((struct in_addr *) host->h_addr_list[0]));
    printf("IP address: %s\n", ip_address);

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Error: Failed to create socket");
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    server_address.sin_addr.s_addr = inet_addr(ip_address);

    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error: Failed to connect to server");
        return 1;
    }

    char *request = "GET / HTTP/1.1\r\nHost: ";
    char *header = strcat(request, hostname);
    header = strcat(header, "\r\nConnection: close\r\n\r\n");

    if (send(client_socket, header, strlen(header), 0) < 0) {
        perror("Error: Failed to send request");
        return 1;
    }

    char response_buffer[BUFFER_SIZE];
    while (recv(client_socket, response_buffer, BUFFER_SIZE - 1, 0) > 0) {
        printf("%s", response_buffer);
        memset(response_buffer, 0, BUFFER_SIZE);
    }

    if (close(client_socket) < 0) {
        perror("Error: Failed to close socket");
        return 1;
    }

    return 0;
}