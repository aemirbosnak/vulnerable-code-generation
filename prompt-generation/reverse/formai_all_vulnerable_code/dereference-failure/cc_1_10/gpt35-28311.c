//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Sherlock Holmes
// It was a cloudy night, and the streets of London were lonely. 
// But that didn't stop Sherlock from working on his HTTP Client program.
// He had been at it for hours, and he refused to give up until he solved the mystery of the program.
// With a cup of tea in hand, he typed away at his keyboard, his fingers moving swiftly.
// Little did he know, he was about to stumble upon his biggest challenge yet.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {

    // Sherlock had to gather information about the host he'd be connecting to
    char *host = "www.example.com";
    char *path = "/";
    int port = 80;

    // Creating a TCP socket
    int socket_client = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_client < 0) {
        printf("Error creating socket\n");
        return -1;
    }

    // Getting host information
    struct hostent *host_info = gethostbyname(host);
    if(host_info == NULL) {
        printf("Could not get IP address for host: %s\n", host);
        return -1;
    }

    // Setting up the server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr = *((struct in_addr *) host_info->h_addr);

    // Connecting to server
    if(connect(socket_client, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Connection failed\n");
        return -1;
    }

    // Preparing the HTTP request
    char request[1000];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

    // Sending the request
    if(send(socket_client, request, strlen(request), 0) < 0) {
        printf("Error sending request\n");
        return -1;
    }

    // Reading the response
    char response[10000];
    int bytes_received = 0;
    while((bytes_received = recv(socket_client, response, sizeof(response), 0)) > 0) {
        printf("%.*s", bytes_received, response); // printing the response
    }

    // Closing the connection
    close(socket_client);

    // Sherlock felt a sense of accomplishment. He had successfully built his HTTP client program and retrieved data from the server.
    // As he sipped his tea, he couldn't help but wonder what other mysteries lay ahead. 
    return 0;
}