//FormAI DATASET v1.0 Category: Simple Web Server ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<pthread.h>

// Define a structure to store the information of a client
typedef struct {
    int fd;
    struct sockaddr_in addr;
} client_info;

void *handle_client(void *arg) {
    // Cast the argument back to client_info
    client_info *info = (client_info *) arg;
    int fd = info->fd;
    struct sockaddr_in addr = info->addr;
    free(info);

    // Receive the HTTP request
    char buffer[1024];
    recv(fd, buffer, sizeof(buffer), 0);

    // Create the HTTP response
    char response[] = "HTTP/1.1 200 OK\r\n"
                      "Content-Type: text/html\r\n"
                      "\r\n"
                      "<html>"
                      "<head><title>Hello, World!</title></head>"
                      "<body><h1>Hello, World!</h1></body>"
                      "</html>";

    // Send the HTTP response
    send(fd, response, strlen(response), 0);

    // Close the socket
    close(fd);
}

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Bind the socket to 0.0.0.0:8080
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;
    bind(sockfd, (struct sockaddr *) &addr, sizeof(addr));

    // Listen on the socket
    listen(sockfd, 5);

    // Accept incoming connections and spawn a new thread to handle each connection
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(sockfd, (struct sockaddr *) &client_addr, &client_addr_len);

        client_info *info = malloc(sizeof(client_info));
        info->fd = client_fd;
        info->addr = client_addr;

        pthread_t t;
        pthread_create(&t, NULL, handle_client, info);
    }

    return 0;
}