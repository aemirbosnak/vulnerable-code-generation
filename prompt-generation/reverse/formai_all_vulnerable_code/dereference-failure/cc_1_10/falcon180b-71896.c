//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define PORT 21
#define BUFFER_SIZE 1024

// Function for creating a socket
int create_socket() {
    int sockfd;
    struct addrinfo hints, *server;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((getaddrinfo("localhost", "21", &hints, &server))!= 0) {
        printf("getaddrinfo error: %s\n", gai_strerror(errno));
        return -1;
    }

    sockfd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);

    if (sockfd == -1) {
        printf("socket error: %s\n", strerror(errno));
        return -1;
    }

    return sockfd;
}

// Function for connecting to the server
int connect_to_server(int sockfd) {
    struct sockaddr_in server_addr;
    int ret;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    if (ret == -1) {
        printf("connect error: %s\n", strerror(errno));
        return -1;
    }

    return 0;
}

// Function for receiving data from the server
void* receive_data(void* arg) {
    int sockfd = *(int*)arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Disconnected from server\n");
            break;
        }

        printf("Received from server: %s\n", buffer);
    }

    close(sockfd);
    pthread_exit(0);
}

// Function for sending data to the server
void* send_data(void* arg) {
    int sockfd = *(int*)arg;
    char* message = (char*)arg;

    send(sockfd, message, strlen(message), 0);

    close(sockfd);
    pthread_exit(0);
}

int main() {
    int sockfd;
    pthread_t thread_id[2];

    // Create socket
    sockfd = create_socket();

    if (sockfd == -1) {
        return -1;
    }

    // Connect to server
    if (connect_to_server(sockfd) == -1) {
        return -1;
    }

    // Create threads for receiving and sending data
    pthread_create(&thread_id[0], NULL, receive_data, &sockfd);
    pthread_create(&thread_id[1], NULL, send_data, "Hello from client!");

    // Wait for threads to finish
    for (int i = 0; i < 2; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}