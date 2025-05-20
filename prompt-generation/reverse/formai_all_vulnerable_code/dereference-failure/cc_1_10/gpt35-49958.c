//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main() {
    int client_sock;
    char hostname[] = "localhost";
    struct hostent *host;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char request[BUFFER_SIZE];
    char method[] = "GET";
    char path[] = "/";
    char http_version[] = "HTTP/1.1";

    //Resolve hostname to IP address
    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Unable to resolve hostname\n");
        exit(1);
    }

    //Create socket
    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock == -1) {
        printf("Unable to create socket\n");
        exit(1);
    }

    //Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);
    server_addr.sin_port = htons(80);

    //Connect to server
    if (connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Unable to connect\n");
        close(client_sock);
        exit(1);
    }

    // Build the HTTP request
    sprintf(request, "%s %s %s\r\nHost: %s\r\nConnection: close\r\n\r\n", method, path, http_version, hostname);

    //Send the request to the server
    if (send(client_sock, request, strlen(request), 0) == -1) {
        printf("Unable to send request\n");
        close(client_sock);
        exit(1);
    }

    //Read response from server
    while (recv(client_sock, buffer, BUFFER_SIZE, 0) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }

    //Clean up
    close(client_sock);

    return 0;
}