//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 8192
#define CRLF "\r\n"

/* Function to create the server socket */
int create_server_socket(int port) {
    int server_socket;
    struct sockaddr_in server_address;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 10) == -1) {
        perror("Error listening on server socket");
        exit(EXIT_FAILURE);
    }

    return server_socket;
}

/* Function to connect to remote server */
int connect_to_server(char *host, int port) {
    int client_socket;
    struct sockaddr_in server_address;
    struct hostent *server;

    server = gethostbyname(host);
    if (server == NULL) {
        perror("Error getting server by name");
        exit(EXIT_FAILURE);
    }

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error creating client socket");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    return client_socket;
}

/* Function to forward data between client and server */
void forward_data(int client_socket, int server_socket) {
    int buffer_size;
    char buffer[MAX_BUFFER_SIZE];

    while((buffer_size = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        send(server_socket, buffer, buffer_size, 0);
        memset(buffer, 0, MAX_BUFFER_SIZE);

        buffer_size = recv(server_socket, buffer, MAX_BUFFER_SIZE, 0);
        send(client_socket, buffer, buffer_size, 0);
        memset(buffer, 0, MAX_BUFFER_SIZE);
    }
}

/* Main function to accept client connections and handle requests */
int main(int argc, char **argv) {
    int server_socket, client_socket, remote_socket;
    struct sockaddr_in client_address;
    socklen_t client_address_length;
    char request_buffer[MAX_BUFFER_SIZE], method[MAX_BUFFER_SIZE], request_uri[MAX_BUFFER_SIZE], version[MAX_BUFFER_SIZE], host[MAX_BUFFER_SIZE], port[10], *remains;
    int request_buffer_size, i, j;
    fd_set set;
    int max_fd = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    server_socket = create_server_socket(atoi(argv[1]));

    while (1) {
        FD_ZERO(&set);
        FD_SET(server_socket, &set);
        max_fd = server_socket;

        if (select(max_fd+1, &set, NULL, NULL, NULL) == -1) {
            perror("Error in select");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(server_socket, &set)) {
            client_address_length = sizeof(client_address);
            client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
            if (client_socket == -1) {
                perror("Error accepting client socket");
                continue;
            }

            printf("New client connection from %s:%d\n", inet_ntoa(client_address.sin_addr), client_address.sin_port);

            memset(request_buffer, 0, MAX_BUFFER_SIZE);
            request_buffer_size = recv(client_socket, request_buffer, MAX_BUFFER_SIZE, 0);
            if (request_buffer_size <= 0) {
                perror("Error reading request");
                continue;
            }

            for (i = 0; i < request_buffer_size; i++) {
                if (request_buffer[i] == ' ') {
                    method[i] = '\0';
                    break;
                }
                method[i] = request_buffer[i];
            }

            for (j = i+1; j < request_buffer_size; j++) {
                if (request_buffer[j] == ' ') {
                    request_uri[j-i-1] = '\0';
                    break;
                }
                request_uri[j-i-1] = request_buffer[j];
            }

            for (i = j+1; i < request_buffer_size; i++) {
                if (request_buffer[i] == '\r' || request_buffer[i] == '\n') {
                    version[i-j-1] = '\0';
                    break;
                }
                version[i-j-1] = request_buffer[i];
            }

            remains = request_buffer + i + 1;
            memset(host, 0, MAX_BUFFER_SIZE);
            for (i = 0; i < strlen(remains); i++) {
                if (remains[i] == ':' || remains[i] == '\r' || remains[i] == '\n') {
                    break;
                }
                host[i] = remains[i];
            }

            strcpy(port, "80");
            if (remains[i] == ':') {
                remains += i+1;
                memset(port, 0, 10);
                for (i = 0; i < strlen(remains); i++) {
                    if (remains[i] == '\r' || remains[i] == '\n') {
                        break;
                    }
                    port[i] = remains[i];
                }
            }

            remote_socket = connect_to_server(host, atoi(port));
            send(remote_socket, request_buffer, request_buffer_size, 0);

            forward_data(client_socket, remote_socket);

            close(remote_socket);
            close(client_socket);
        }
    }

    return 0;
}