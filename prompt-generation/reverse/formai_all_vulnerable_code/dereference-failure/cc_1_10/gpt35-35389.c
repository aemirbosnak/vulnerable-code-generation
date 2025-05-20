//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define HOST_NAME "example.com"
#define REQUEST "GET / HTTP/1.1\r\nHost: " HOST_NAME "\r\nConnection: close\r\n\r\n"

int main() {
    struct hostent *he;
    struct in_addr **addr_list;
    struct sockaddr_in server;
    int socket_desc, status;
    char server_reply[1024];

    // Resolve hostname to IP
    he = gethostbyname(HOST_NAME);
    if (he == NULL) {
        printf("Could not resolve hostname\n");
        return 1;
    }

    // Get list of addresses for given hostname
    addr_list = (struct in_addr **)he->h_addr_list;
    if (addr_list[0] == NULL) {
        printf("Could not get address list\n");
        return 1;
    }

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket\n");
        return 1;
    }

    // Set up server information
    server.sin_addr = *addr_list[0];
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    // Connect to server
    status = connect(socket_desc, (struct sockaddr *)&server, sizeof(server));
    if (status < 0) {
        printf("Could not connect to server\n");
        return 1;
    }

    // Send HTTP request
    status = send(socket_desc, REQUEST, strlen(REQUEST), 0);
    if (status < 0) {
        printf("Could not send request\n");
        close(socket_desc);
        return 1;
    }

    // Receive server reply
    while ((status = recv(socket_desc, server_reply, 1024, 0)) > 0) {
        printf("%.*s", status, server_reply);
    }
    if (status < 0) {
        printf("Could not receive reply\n");
        close(socket_desc);
        return 1;
    }

    // Close socket
    close(socket_desc);

    return 0;
}