//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 4096
#define BACKLOG 10

void die(const char *message) {
    fprintf(stderr, "%s: %s\n", message, strerror(errno));
    exit(1);
}

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    int read_size = read(client_sock, buffer, BUFFER_SIZE);
    if (read_size < 0) {
        die("Failed to read from client");
    }
    
    // Since this is a proxy, we need to find the destination server
    char method[16], url[256], version[16];
    sscanf(buffer, "%s %s %s", method, url, version);

    // Remove "http://" if present
    char *http_prefix = "http://";
    char *host_start = strstr(url, http_prefix);
    if (host_start) {
        host_start += strlen(http_prefix);
    } else {
        host_start = url;
    }
    
    // Extract hostname and port (default to 80)
    char *host_end = strchr(host_start, '/');
    if (!host_end) host_end = host_start + strlen(host_start);
    
    char host[256];
    int port = 80;
    if (strchr(host_start, ':')) {
        sscanf(host_start, "%[^:]:%d", host, &port);
    } else {
        strncpy(host, host_start, host_end - host_start);
        host[host_end - host_start] = '\0';
    }
    
    // Create a socket for the destination server
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        die("Could not create socket");
    }

    // Setup the server structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        die("Invalid address");
    }

    // Connect to the server
    if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Connection to server failed");
    }
    
    // Forward the request to the server
    write(server_sock, buffer, read_size);
    
    // Read the response from the server
    while ((read_size = read(server_sock, buffer, BUFFER_SIZE)) > 0) {
        write(client_sock, buffer, read_size);
    }

    // Clean up
    close(server_sock);
    close(client_sock);
}

int main() {
    int proxy_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_sock < 0) {
        die("Could not create proxy socket");
    }

    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(PORT);

    if (bind(proxy_sock, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        die("Bind failed");
    }

    if (listen(proxy_sock, BACKLOG) < 0) {
        die("Listen failed");
    }

    printf("In the remnants of the world, the HTTP Proxy stands...\n");
    
    while (1) {
        int client_sock = accept(proxy_sock, NULL, NULL);
        if (client_sock < 0) {
            die("Accept failed");
        }
        handle_client(client_sock);
    }
    
    close(proxy_sock);
    return 0;
}