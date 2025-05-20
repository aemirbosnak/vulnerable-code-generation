//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PI 3.14159265358979323846
#define BUFFER_SIZE 4096
#define PORT 80

int main(int argc, char *argv[]) {
    int socket_desc, read_size;
    struct sockaddr_in server;
    char *host = argv[1];
    char *path = argv[2];
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    int len;

    // Step 1: Initialize socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket\n");
        return -1;
    }

    // Step 2: Prepare the address structure
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, host, &server.sin_addr);

    // Step 3: Connect to the remote server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed. Error is ");
        return -1;
    }

    // Step 4: Send the request
    snprintf(request, BUFFER_SIZE,
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "User-Agent: C-HTTP-Client/1.0\r\n"
             "Accept: */*\r\n"
             "Connection: keep-alive\r\n"
             "\r\n",
             path, host);

    len = send(socket_desc, request, strlen(request), 0);
    if (len < 0) {
        perror("Send failed: ");
        return -1;
    }

    // Step 5: Read the response
    read_size = recv(socket_desc, response, BUFFER_SIZE, 0);
    if (read_size < 0) {
        perror("Receive failed: ");
        return -1;
    }

    // Step 6: Print the response
    printf("Response:\n%s\n", response);

    // Step 7: Close the socket
    close(socket_desc);

    return 0;
}