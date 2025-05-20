//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        return -1;
    }

    // Create a socket
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    // Bind the socket to an ip address and port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(atoi(argv[2]));
    bind(fd, (struct sockaddr *)&addr, sizeof(addr));

    // Listen for incoming connections
    listen(fd, 10);

    // Accept incoming connections
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_fd = accept(fd, (struct sockaddr *)&client_addr, &client_addr_len);

    // Read the request from the client
    char request[BUFFER_SIZE];
    memset(request, 0, sizeof(request));
    read(client_fd, request, sizeof(request));

    // Parse the request to get the host and port
    char *host = strstr(request, "Host: ") + strlen("Host: ");
    char *end_host = strstr(host, "\r\n");
    *end_host = '\0';
    char *port = strchr(host, ':');
    if (port == NULL) {
        port = "80";
    } else {
        *port = '\0';
        port++;
    }

    // Connect to the remote server
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(host);
    server_addr.sin_port = htons(atoi(port));
    connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Send the request to the remote server
    write(server_fd, request, strlen(request));

    // Forward the response from the remote server to the client
    char response[BUFFER_SIZE];
    ssize_t n;
    while ((n = read(server_fd, response, sizeof(response))) > 0) {
        write(client_fd, response, n);
    }

    // Close the sockets
    close(client_fd);
    close(server_fd);
    close(fd);

    return 0;
}