//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>

// Function prototypes
void handle_client(int client_socket);
void* server_thread(void* arg);
void signal_handler(int signal_num);

// Global variables
int server_socket;
pid_t server_pid;
int num_clients = 0;

// Main function
int main() {
    int listen_socket;
    int client_socket;
    int port_num = 8080;

    // Create a socket for listening
    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    // Bind the socket to the port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port_num);
    bind(listen_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    // Start listening for incoming connections
    listen(listen_socket, 5);

    printf("Web server is running on port %d\n", port_num);

    // Start the server thread
    server_pid = fork();
    if (server_pid < 0) {
        printf("Error forking process\n");
        return 1;
    }
    else if (server_pid == 0) {
        server_thread(NULL);
    }
    else {
        printf("Server process has been started with PID %d\n", server_pid);
    }

    // Handle signals
    signal(SIGCHLD, signal_handler);

    int client_socket_fd;
    char buffer[1024];
    while (1) {
        client_socket_fd = accept(listen_socket, NULL, NULL);
        if (client_socket_fd < 0) {
            perror("Error accepting connection");
            continue;
        }

        // Start a new thread to handle the client connection
        pthread_t thread;
        pthread_create(&thread, NULL, server_thread, (void*)client_socket_fd);

        // Handle the client connection
        handle_client(client_socket_fd);

        // Clean up the client socket
        close(client_socket_fd);
    }

    // Clean up the listen socket
    close(listen_socket);

    return 0;
}

// Server thread function
void* server_thread(void* arg) {
    int client_socket = *(int*)arg;

    // Handle the client connection
    handle_client(client_socket);

    // Clean up the client socket
    close(client_socket);

    // Exit the thread
    pthread_exit(NULL);
}

// Client connection handler function
void handle_client(int client_socket) {
    char request[1024];
    char response[1024];
    char* http_version = "HTTP/1.1 200 OK\r\n";
    char* content_type = "Content-Type: text/html\r\n\r\n";
    char* content_length = "Content-Length: ";
    char* header_end = "\r\n\r\n";
    int len;
    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);

    while ((len = read(client_socket, request, sizeof(request))) > 0) {
        if (request[len-1] == '\n') {
            request[len-1] = '\0';
        }
        printf("Received request: %s\n", request);

        strcpy(response, http_version);
        strcat(response, content_type);
        strcat(response, header_end);

        snprintf(response + strlen(response), sizeof(response) - strlen(response), "%s", "Hello World!");

        int response_len = strlen(response);
        snprintf(response + response_len, sizeof(response) - response_len, "%d", response_len);

        send(client_socket, response, strlen(response), 0);
        close(client_socket);
    }

    close(client_socket);
}

// Signal handler function
void signal_handler(int signal_num) {
    int status;
    pid_t child_pid = wait(&status);

    if (WIFEXITED(status)) {
        printf("Child process %d exited with status %d\n", child_pid, WEXITSTATUS(status));
    }
    else if (WIFSIGNALED(status)) {
        printf("Child process %d terminated due to signal %d\n", child_pid, WTERMSIG(status));
    }
    else {
        printf("Child process %d terminated abnormally\n", child_pid);
    }
}