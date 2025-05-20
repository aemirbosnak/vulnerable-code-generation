//FormAI DATASET v1.0 Category: Simple Web Server ; Style: irregular
/* Hey there, I am a simple web server program written in C. */

/* First, let's include all the necessary libraries. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

/* I know you're wondering what this function does. Don't worry,
I will explain everything, just keep reading. */
void handle_request(int client_socket) {
    char response[] = "<html><head><title>Hello, World!</title></head><body><h1>Hello, World!</h1></body></html>";
    char headers[1000];

    /* Let's create the HTTP response headers. */
    sprintf(headers, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\nContent-Type: text/html\r\n\r\n", strlen(response));

    /* Send the headers and the response to the client. */
    send(client_socket, headers, strlen(headers), 0);
    send(client_socket, response, strlen(response), 0);

    /* Close the client socket when we're done. */
    close(client_socket);
}

/* Now let's start with the main function. */
int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    unsigned short server_port = 8080; /* Use port 8080, or any other that you like. */
    unsigned int client_address_length;

    /* Create the server socket. */
    server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    /* Check if there was any error creating the socket. */
    if (server_socket == -1) {
        perror("socket");
        return errno;
    }

    /* Bind the socket to a specific IP address and port. */
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("0.0.0.0");
    server_address.sin_port = htons(server_port);

    /* Check if there was any error binding the socket. */
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return errno;
    }

    /* Listen for incoming connections. */
    if (listen(server_socket, 5) == -1) {
        perror("listen");
        return errno;
    }

    /* Accept incoming connections and handle them one by one. */
    while (1) {
        client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);

        /* Check if there was any error accepting the incoming connection. */
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        /* Handle the request. */
        handle_request(client_socket);
    }

    /* Close the server socket. This should never happen in this program,
    since it runs indefinitely, but it's a good practice to close the socket
    when we're done with it. */
    close(server_socket);

    /* Return 0 if everything went well. */
    return 0;
}