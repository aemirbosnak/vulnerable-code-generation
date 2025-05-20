//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

/* Defines */
#define BUFSIZE 1024
#define DEFAULT_PORT 5000

/* Function Declarations */
int create_socket(int port);
int accept_connection(int server_socket);
void handle_client(int sock_fd);
void error_handler(char *msg);

/* Main Function */
int main(int argc, char *argv[]) {
    int port;
    if (argc < 2) {
        port = DEFAULT_PORT;
    } else {
        port = atoi(argv[1]);
    }

    // Create Socket
    int server_socket = create_socket(port);

    // Accept connections and handle clients
    while (1) {
        int client_socket = accept_connection(server_socket);
        if (fork() == 0) {
            handle_client(client_socket);
            exit(0);
        }
        close(client_socket);
    }
}

/* Function Definitions */
int create_socket(int port) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        error_handler("Error opening socket");
    }

    int option = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) < 0) {
        error_handler("Error setting socket option");
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error_handler("Error binding socket to port");
    }

    if (listen(server_socket, 5) < 0) {
        error_handler("Error listening on socket");
    }

    return server_socket;
}

int accept_connection(int server_socket) {
    struct sockaddr_in client_address;
    socklen_t client_address_length = sizeof(client_address);
    int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
    if (client_socket < 0) {
        error_handler("Error accepting connection");
    }

    printf("Client connected: %s\n", inet_ntoa(client_address.sin_addr));

    return client_socket;
}

void handle_client(int sock_fd) {
    // Set socket to non-blocking
    int flags = fcntl(sock_fd, F_GETFL, 0);
    if (flags == -1) {
        error_handler("Error getting socket flags");
    }
    if (fcntl(sock_fd, F_SETFL, flags | O_NONBLOCK) < 0) {
        error_handler("Error setting socket flags");
    }

    char buffer[BUFSIZE];
    int n;
    struct timeval start, end;
    double elapsed_time;

    while (1) {
        gettimeofday(&start, NULL);

        // Receive data
        n = recv(sock_fd, buffer, BUFSIZE, 0);
        if (n < 0 && errno != EWOULDBLOCK) {
            error_handler("Error receiving data");
        } else if (n == 0) {
            break;
        } else if (n > 0) {
            // Send data back to client
            n = send(sock_fd, buffer, n, 0);
            if (n < 0 && errno != EWOULDBLOCK) {
                error_handler("Error sending data");
            }
        }

        gettimeofday(&end, NULL);
        elapsed_time = ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);
        printf("Elapsed time: %f\n", elapsed_time);
    }

    close(sock_fd);
    printf("Client disconnected\n");
}

void error_handler(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}