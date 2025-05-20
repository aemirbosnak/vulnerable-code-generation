//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: statistical
/* As we build our HTTP client, we need to first establish a connection to a web server. */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define HOST "api.github.com"
#define PORT 80

int main() {

    /* Create the connection socket */
    int client_socket;
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    if (client_socket == -1) {
        printf("Could not create socket");
        return 1;
    }
    
    /* Get the server's IP address from the hostname */
    struct hostent *host;
    host = gethostbyname(HOST);
    
    if (host == NULL) {
        printf("Could not get host");
        return 1;
    }
    
    /* Set up the server address */
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr = *((struct in_addr*) host->h_addr);
    
    /* Connect to the server */
    int connection_result;
    connection_result = connect(client_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    
    if (connection_result == -1) {
        printf("Could not connect to server");
        close(client_socket);
        return 1;
    }
    
    /* Send our GET request to the server */
    char* message = "GET /repos/octocat/hello-world HTTP/1.1\r\n"
                    "Host: api.github.com\r\n"
                    "Connection: close\r\n\r\n";

    int bytes_sent;
    bytes_sent = send(client_socket, message, strlen(message), 0);
    
    if (bytes_sent == -1) {
        printf("Could not send message to server");
        close(client_socket);
        return 1;
    }
    
    /* Receive the response from the server and print it to the console */
    char response[4096];
    int bytes_received = recv(client_socket, response, 4096, 0);
    
    if (bytes_received == -1) {
        printf("Could not receive response from server");
        close(client_socket);
        return 1;
    }
    
    printf("%.*s\n", bytes_received, response);
    
    /* Close the socket */
    close(client_socket);
    
    return 0;
}