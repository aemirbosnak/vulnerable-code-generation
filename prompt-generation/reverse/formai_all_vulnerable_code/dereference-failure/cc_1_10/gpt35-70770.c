//FormAI DATASET v1.0 Category: Socket programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define PORT 8080
#define MAX_PENDING_CONNECTIONS 10
#define BUFFER_SIZE 1024

int listen_socket_file_descriptor, connected_socket_file_descriptor;
struct sockaddr_in server_address, client_address;
int address_length;
char buffer[BUFFER_SIZE];

void sig_handler(int signo) {
    if(signo == SIGINT) {
        printf("\nClosing the server\n");
        close(listen_socket_file_descriptor);
        exit(0);
    }
}

void set_socket_to_non_blocking_mode(int socket_fd) {
    int flags = fcntl(socket_fd, F_GETFL, 0);
    fcntl(socket_fd, F_SETFL, flags | O_NONBLOCK);
}

void handle_connection() {
    int received_bytes, sent_bytes;
    char message[] = "Hello from server";
    while(1) {
        received_bytes = recv(connected_socket_file_descriptor, buffer, BUFFER_SIZE, 0);
        if(received_bytes > 0) {
            printf("Received message from client: %s\n", buffer);
            sent_bytes = send(connected_socket_file_descriptor, message, strlen(message), 0);
            if(sent_bytes == -1) {
                printf("Error sending message to client");
                break;
            }
            memset(buffer, 0, BUFFER_SIZE);
        } else if(received_bytes == 0) {
            break;
        } else {
            if(errno != EWOULDBLOCK) {
                printf("Error while receiving data from client");
                break;
            }
        }
    }
    close(connected_socket_file_descriptor);
}

int main() {
    signal(SIGINT, sig_handler);

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    listen_socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if(listen_socket_file_descriptor == -1) {
        perror("Error creating listening socket");
        exit(1);
    }

    if(bind(listen_socket_file_descriptor, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket to address");
        exit(1);
    }

    if(listen(listen_socket_file_descriptor, MAX_PENDING_CONNECTIONS) == -1) {
        perror("Error setting socket for listening");
        exit(1);
    }

    set_socket_to_non_blocking_mode(listen_socket_file_descriptor);

    printf("Server is listening on port %d\n", PORT);

    while(1) {
        address_length = sizeof(client_address);
        connected_socket_file_descriptor = accept(listen_socket_file_descriptor, (struct sockaddr *)&client_address, (socklen_t *)&address_length);

        if(connected_socket_file_descriptor == -1) {
            if(errno != EWOULDBLOCK && errno != EAGAIN) {
                perror("Error accepting incoming connection");
                exit(1);
            }
        } else {
            set_socket_to_non_blocking_mode(connected_socket_file_descriptor);
            printf("Incoming connection accepted\n");
            handle_connection();
        }
    }

    close(listen_socket_file_descriptor);

    return 0;
}