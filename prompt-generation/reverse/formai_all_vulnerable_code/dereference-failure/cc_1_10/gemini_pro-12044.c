//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

// Define the maximum number of clients that can connect to the server
#define MAX_CLIENTS 10

// Define the port number that the server will listen on
#define PORT 8080

// Define the maximum size of the request that the server can handle
#define MAX_REQUEST_SIZE 1024

// Define the maximum size of the response that the server can send
#define MAX_RESPONSE_SIZE 1024

// Define the maximum number of threads that can be used to handle client requests
#define MAX_THREADS 10

// Define the structure of a client request
typedef struct {
    int socket;
    char request[MAX_REQUEST_SIZE];
    int request_size;
} client_request;

// Define the structure of a server response
typedef struct {
    char response[MAX_RESPONSE_SIZE];
    int response_size;
} server_response;

// Define the structure of a thread argument
typedef struct {
    client_request *request;
    server_response *response;
} thread_argument;

// Define the function that will be executed by each thread
void *handle_client_request(void *arg) {
    // Get the client request and server response from the thread argument
    thread_argument *args = (thread_argument *)arg;
    client_request *request = args->request;
    server_response *response = args->response;

    // Parse the client request
    char *method = strtok(request->request, " ");
    char *uri = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Check if the request is valid
    if (strcmp(method, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
        response->response_size = sprintf(response->response, "HTTP/1.1 400 Bad Request\r\n\r\n");
    }
    else {
        // Get the file that the client is requesting
        FILE *file = fopen(uri, "r");

        // Check if the file exists
        if (file == NULL) {
            response->response_size = sprintf(response->response, "HTTP/1.1 404 Not Found\r\n\r\n");
        }
        else {
            // Read the file into the response
            int bytes_read = fread(response->response, 1, MAX_RESPONSE_SIZE, file);
            response->response_size = bytes_read;

            // Add the Content-Type header to the response
            char content_type[100];
            if (strstr(uri, ".html") != NULL) {
                strcpy(content_type, "Content-Type: text/html\r\n");
            }
            else if (strstr(uri, ".css") != NULL) {
                strcpy(content_type, "Content-Type: text/css\r\n");
            }
            else if (strstr(uri, ".js") != NULL) {
                strcpy(content_type, "Content-Type: text/javascript\r\n");
            }
            else {
                strcpy(content_type, "Content-Type: text/plain\r\n");
            }
            strcat(response->response, content_type);

            // Add the Content-Length header to the response
            char content_length[100];
            sprintf(content_length, "Content-Length: %d\r\n", response->response_size);
            strcat(response->response, content_length);

            // Add the Server header to the response
            strcat(response->response, "Server: MyWebServer/1.0\r\n");

            // Add the Connection header to the response
            strcat(response->response, "Connection: close\r\n");

            // Add a blank line to the end of the response
            strcat(response->response, "\r\n");

            // Close the file
            fclose(file);
        }
    }

    // Send the response to the client
    send(request->socket, response->response, response->response_size, 0);

    // Close the client socket
    close(request->socket);

    // Free the memory allocated for the client request and server response
    free(request);
    free(response);

    // Return NULL to indicate that the thread has finished executing
    return NULL;
}

// Define the main function
int main() {
    // Create a socket for the server to listen on
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Check if the socket was created successfully
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    // Set the socket options
    int optval = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Bind the socket to the port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }

    // Create a thread pool to handle client requests
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    // Accept incoming connections and handle them in a separate thread
    while (1) {
        // Accept a new connection
        int client_socket = accept(server_socket, NULL, NULL);

        // Check if the client socket was created successfully
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Create a new client request and server response
        client_request *request = malloc(sizeof(client_request));
        server_response *response = malloc(sizeof(server_response));

        // Initialize the client request and server response
        request->socket = client_socket;
        request->request_size = 0;
        response->response_size = 0;

        // Create a new thread to handle the client request
        thread_argument *args = malloc(sizeof(thread_argument));
        args->request = request;
        args->response = response;

        pthread_create(&threads[thread_count], NULL, handle_client_request, (void *)args);

        // Increment the thread count
        thread_count++;

        // Check if the maximum number of threads has been reached
        if (thread_count >= MAX_THREADS) {
            // Wait for one of the threads to finish executing
            pthread_join(threads[0], NULL);

            // Decrement the thread count
            thread_count--;
        }
    }

    // Close the server socket
    close(server_socket);

    return 0;
}