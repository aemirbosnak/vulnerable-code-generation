//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 1024 //maximum buffer size
#define SERVER_PORT 8000 //server port number
#define PROXY_PORT 8080 //proxy port number
#define SERVER_ADDRESS "127.0.0.1" //server IP address
#define PROXY_ADDRESS "127.0.0.1" //proxy IP address

/* function to handle request */
void* handle_request(void *arg) {
    int client_sockfd = *((int *) arg);
    char buffer[MAX_BUFFER_SIZE];
    int bytes_recv, bytes_sent;
    int server_sockfd;
    struct sockaddr_in server_addr;

    //create socket for server
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //set server address parameters
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);

    //connect to server
    if (connect(server_sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        close(client_sockfd);
        return NULL;
    }

    //receive data from client
    memset(buffer, 0, sizeof(buffer));
    bytes_recv = recv(client_sockfd, buffer, MAX_BUFFER_SIZE, 0);

    /* modify request */
    char modified_buffer[MAX_BUFFER_SIZE];
    strcpy(modified_buffer, buffer);
    char* first_line = strtok(modified_buffer, "\r\n");
    char* http_method = strtok(first_line, " ");
    char* http_url = strtok(NULL, " ");
    char* http_version = strtok(NULL, " ");
    sprintf(first_line, "%s %s %s\r\n", http_method, http_url, http_version);
    char* host_header = strstr(buffer, "Host:");
    char* modified_host_header = strdup(host_header);
    strtok(modified_host_header, "\r\n");
    sprintf(modified_host_header, "%s\r\n", "Host: " SERVER_ADDRESS);

    /* send modified request to server */
    bytes_sent = send(server_sockfd, modified_buffer, strlen(modified_buffer), 0);

    /* receive response from server and send to client */
    memset(buffer, 0, sizeof(buffer));
    while ((bytes_recv = recv(server_sockfd, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        bytes_sent = send(client_sockfd, buffer, bytes_recv, 0);
        memset(buffer, 0, sizeof(buffer));
    }

    //close sockets
    close(server_sockfd);
    close(client_sockfd);

    return NULL;
}

/* main function */
int main(void) {
    int proxy_sockfd, client_sockfd;
    struct sockaddr_in proxy_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    pthread_t tid;

    //create a socket for the proxy server
    proxy_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //set proxy address parameters
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(PROXY_PORT);
    proxy_addr.sin_addr.s_addr = inet_addr(PROXY_ADDRESS);

    //bind the socket to the proxy address
    if (bind(proxy_sockfd, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Failed to bind to proxy address");
        exit(EXIT_FAILURE);
    }

    //listen for incoming clients
    if (listen(proxy_sockfd, 5) < 0) {
        perror("Failed to listen for clients");
        exit(EXIT_FAILURE);
    }

    printf("Proxy server is running on port %d\n", PROXY_PORT);

    //accept incoming clients and handle them in separate threads
    while (true) {
        client_sockfd = accept(proxy_sockfd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_sockfd < 0) {
            perror("Failed to accept incoming client");
        } else {
            pthread_create(&tid, NULL, handle_request, &client_sockfd);
            pthread_detach(tid);
        }
    }

    //close proxy server socket
    close(proxy_sockfd);

    return 0;
}