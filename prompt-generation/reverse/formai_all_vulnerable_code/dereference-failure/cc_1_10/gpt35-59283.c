//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket;
    struct sockaddr_in server_address;
    char *server_hostname = "example.com";
    char *http_request = "GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n";
    char server_response[BUFFER_SIZE];
    
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Could not create socket");
        exit(-1);
    }
    
    struct hostent *server = gethostbyname(server_hostname);
    if (server == NULL) {
        fprintf(stderr, "Could not resolve hostname '%s'\n", server_hostname);
        exit(-1);
    }

    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(80);

    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Could not connect to server");
        exit(-1);
    }

    if (send(client_socket, http_request, strlen(http_request), 0) < 0) {
        perror("Could not send HTTP request");
        exit(-1);
    }

    int bytes_received = recv(client_socket, server_response, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("Could not receive server response");
        exit(-1);
    }
    
    printf("Server response:\n%s\n", server_response);
    close(client_socket);
    
    return 0;
}