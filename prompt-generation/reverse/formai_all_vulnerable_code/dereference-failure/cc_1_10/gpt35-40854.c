//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    char *host = "www.example.com";
    char *request = "GET / HTTP/1.0\r\nHost: www.example.com\r\n\r\n";
    struct sockaddr_in server;
    struct hostent *he;
    int socket_desc, response_len = 0;
    char server_reply[2000];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }

    // Get server IP address
    if ((he = gethostbyname(host)) == NULL) {
        printf("Could not resolve host");
    }
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr = *((struct in_addr *)he->h_addr);
    server.sin_port = htons(80);

    // Connect to server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        return 1;
    }

    // Send request
    if (send(socket_desc, request, strlen(request), 0) < 0) {
        perror("Send failed");
        return 1;
    }

    // Receive response
    if ((response_len = recv(socket_desc, server_reply, 2000, 0)) < 0) {
        perror("Receive failed");
        return 1;
    }
    printf("Response:\n%s\n", server_reply);

    // Close connection
    close(socket_desc);
    return 0;
}