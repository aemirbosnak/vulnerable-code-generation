//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

void error(char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

struct ProxyThreadData {
    int client_sockfd;
};

void *proxyThread(void *arg) {
    struct ProxyThreadData *data = (struct ProxyThreadData*) arg;

    // Setup buffers and variables
    char buffer[BUFFER_SIZE];
    char request_buffer[BUFFER_SIZE];
    int n;

    // Read client's request
    bzero(request_buffer,BUFFER_SIZE);
    n = read(data->client_sockfd,request_buffer,BUFFER_SIZE-1);
    if (n < 0) error("ERROR reading from socket");

    // Parse host and port from request
    char *request_host = strstr(request_buffer, "Host:");
    request_host += 6; // Start of hostname
    char *end_of_host = strstr(request_host, "\r\n");
    *end_of_host = '\0'; // Terminate the string
    char *request_port = strstr(request_host, ":");
    if (request_port != NULL) {
        *request_port++ = '\0';
    } else {
        request_port = "80"; // HTTP default port
    }

    // Print request details for debugging
    printf("Request: [%s:%s]\n", request_host, request_port);

    // Resolve hostname to IP address
    struct hostent *server = gethostbyname(request_host);
    if (server == NULL) error("ERROR, no such host");
    char *server_ip = inet_ntoa(*((struct in_addr *) server->h_addr));

    // Create a socket to server
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) error("ERROR opening socket");

    // Connect to the server
    struct sockaddr_in server_address;
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(request_port));
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    if (connect(server_sockfd,(struct sockaddr *) &server_address,sizeof(server_address)) < 0) {
        error("ERROR connecting to server");
    }

    // Send client's request to server
    n = write(server_sockfd, request_buffer, strlen(request_buffer));
    if (n < 0) error("ERROR writing to socket");

    // Proxy server's response back to client
    while (1) {
        bzero(buffer,BUFFER_SIZE);
        n = read(server_sockfd,buffer,BUFFER_SIZE-1);
        if (n < 0) error("ERROR reading from socket");
        if (n == 0) break;
        // TODO: Handle response
        n = write(data->client_sockfd,buffer,n);
        if (n < 0) error("ERROR writing to socket");
    }

    // Close all sockets
    close(server_sockfd);
    close(data->client_sockfd);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    // Check port of proxy server command line argument
    if (argc != 2) {
        fprintf(stderr,"Usage: %s <port-number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create socket for proxy server
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) error("ERROR opening socket");

    // Reuse socket port if already in use
    int reuse = 1;
    setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int));

    // Bind socket to port
    struct sockaddr_in server_address;
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(atoi(argv[1]));
    if (bind(server_sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        error("ERROR on binding");
    }

    // Listen for client connections
    listen(server_sockfd, 5);
    printf("Proxy running on port %s...\n", argv[1]);

    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_length = sizeof(client_address);
        bzero((char *) &client_address, client_length);
        int client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_address, &client_length);

        if (client_sockfd < 0) {
            error("ERROR on accept");
        } else {
            pthread_t thread;
            struct ProxyThreadData *thread_data = (struct ProxyThreadData*) malloc(sizeof(struct ProxyThreadData));
            thread_data->client_sockfd = client_sockfd;
            pthread_create(&thread, NULL, proxyThread, (void *) thread_data);
        }
    }

    // Should never reach this point
    return EXIT_SUCCESS;
}