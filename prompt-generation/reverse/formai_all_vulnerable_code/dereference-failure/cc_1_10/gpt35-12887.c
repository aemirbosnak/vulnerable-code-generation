//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define DEFAULT_PORT 8080

void *handle_client(void *sock_fd) {
    int client_sock_fd = *((int *) sock_fd);
    char buffer[BUFFER_SIZE];

    memset(buffer, 0, BUFFER_SIZE);
    recv(client_sock_fd, buffer, BUFFER_SIZE-1, 0);
    printf("Client request:\n%s\n", buffer);

    // Change the host in the request to our proxy host
    char host[] = "Host: ";
    strcat(host, "localhost:8080");
    char *replace_index = strstr(buffer, "Host:");
    size_t host_len = strlen(host);
    size_t replace_len = strlen(replace_index);
    memmove(replace_index + host_len, replace_index + replace_len, strlen(replace_index) - replace_len);
    memcpy(replace_index, host, host_len);

    // Create a connection to the server
    int server_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(DEFAULT_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    connect(server_sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Send the modified request to the server
    send(server_sock_fd, buffer, strlen(buffer), 0);

    // Receive response from server and send it to client
    memset(buffer, 0, BUFFER_SIZE);
    while(recv(server_sock_fd, buffer, BUFFER_SIZE-1, 0) > 0) {
        send(client_sock_fd, buffer, strlen(buffer), 0);
        memset(buffer, 0, BUFFER_SIZE);
    }
    close(client_sock_fd);
    close(server_sock_fd);
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    int server_sock_fd, client_sock_fd;
    int port = DEFAULT_PORT;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    pthread_t tid;

    if (argc > 1) {
        port = atoi(argv[1]);
    }

    server_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_sock_fd, 5);

    printf("Proxy server is running on port %d\n", port);

    while(1) {
        client_addr_len = sizeof(client_addr);
        client_sock_fd = accept(server_sock_fd, (struct sockaddr *)&client_addr, &client_addr_len);

        pthread_create(&tid, NULL, handle_client, &client_sock_fd);
        pthread_detach(tid);
    }

    close(server_sock_fd);
    return 0;
}