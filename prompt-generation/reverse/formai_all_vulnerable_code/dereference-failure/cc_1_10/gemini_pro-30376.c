//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: excited
// Hey there, welcome to the world of the most epic HTTP Proxy ever!

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>

// Our super secret global variables!
int proxy_port;
int server_port;
char *server_host;

// Handle those pesky signals like SIGINT and SIGTERM with grace!
void handle_signals(int signal) {
    printf("Received signal %d, shutting down the proxy...\n", signal);
    exit(0);
}

// Let's do some multithreading magic!
void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    free(arg); // We don't need the argument pointer anymore

    // Get ready to receive the client's HTTP request!
    char request[4096];
    int request_length = recv(client_socket, request, sizeof(request), 0);

    // Got the request? Let's parse it!
    char host[256];
    char path[256];
    sscanf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);

    // Time to connect to the real server!
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    struct hostent *server_info = gethostbyname(server_host);
    server_addr.sin_addr = *(struct in_addr *) server_info->h_addr_list[0];

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    connect(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

    // Relay the client's request to the server!
    send(server_socket, request, request_length, 0);

    // Now, let's relay the server's response to the client!
    char response[4096];
    int response_length = recv(server_socket, response, sizeof(response), 0);
    send(client_socket, response, response_length, 0);

    // All done! Cleanup time.
    close(client_socket);
    close(server_socket);
    pthread_exit(NULL);
}

// Let's get this party started!
int main(int argc, char **argv) {
    if (argc != 5) {
        printf("Usage: %s <proxy_port> <server_port> <server_host> <num_threads>\n", argv[0]);
        return 1;
    }

    // Initialize our super secret global variables!
    proxy_port = atoi(argv[1]);
    server_port = atoi(argv[2]);
    server_host = argv[3];

    // Let's handle those pesky signals!
    signal(SIGINT, handle_signals);
    signal(SIGTERM, handle_signals);

    // Set up our proxy server socket!
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(proxy_port);

    // Bind our socket to the proxy port!
    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

    // Listen for incoming client connections!
    listen(server_socket, 10);

    // Get ready to spawn multiple threads to handle clients!
    pthread_t threads[atoi(argv[4])];

    // Let's go into an infinite loop to handle client connections!
    while (1) {
        // Accept incoming client connections!
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_len);

        // Spawn a thread to handle the client!
        pthread_create(&threads[0], NULL, handle_client, malloc(sizeof(int)));
    }

    // We should never reach this point, but just in case...
    return 0;
}