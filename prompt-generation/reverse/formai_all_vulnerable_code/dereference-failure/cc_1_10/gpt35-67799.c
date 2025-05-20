//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <ctype.h>
#include <netdb.h>

#define MAX_BUF_SIZE 2048
#define MAX_HOST_SIZE 100
#define DEFAULT_PORT 80

// function to check if the input string is a valid IPv4 address
bool is_valid_ip(char *ip) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip, &(sa.sin_addr));
    return result != 0;
}

void proxy(int client_fd, char *host, int port) {
    char buffer[MAX_BUF_SIZE], method[10], path[MAX_BUF_SIZE], version[10], url[MAX_BUF_SIZE], host_header[MAX_HOST_SIZE];
    int n = read(client_fd, buffer, MAX_BUF_SIZE);

    // parse request line
    sscanf(buffer, "%s %s %s", method, path, version);

    // check if HTTP method is GET or POST
    if (strcasecmp(method, "GET") != 0 && strcasecmp(method, "POST") != 0) {
        printf("Invalid Method\n");
        exit(EXIT_FAILURE);
    }

    // parse URL
    sscanf(path, "http://%s", url);

    // check if URL is valid IP or domain name
    if (!is_valid_ip(url) && !strstr(url, ".")) {
        printf("Invalid URL\n");
        exit(EXIT_FAILURE);
    }

    // get host header
    sprintf(host_header, "Host: %s\r\n", url);

    // create socket to connect to server
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // get server IP address from URL
    struct hostent *server;
    server = gethostbyname(url);
    if (server == NULL) {
        printf("Error: Host not found\n");
        exit(EXIT_FAILURE);
    }

    // construct server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // connect to server
    if (connect(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Connection failed\n");
        exit(EXIT_FAILURE);
    }

    // send request to server
    write(server_fd, method, strlen(method));
    write(server_fd, " ", 1);
    write(server_fd, path, strlen(path));
    write(server_fd, " HTTP/1.0\r\n", strlen(" HTTP/1.0\r\n"));
    write(server_fd, host_header, strlen(host_header));
    write(server_fd, "User-Agent: Mozilla/5.0\r\n", strlen("User-Agent: Mozilla/5.0\r\n"));
    write(server_fd, "Connection: close\r\n", strlen("Connection: close\r\n"));
    write(server_fd, "\r\n", strlen("\r\n"));

    // receive response from server and pass it to client
    while ((n = read(server_fd, buffer, MAX_BUF_SIZE)) > 0) {
        write(client_fd, buffer, n);
    }
    close(server_fd);
}

int main(int argc, char *argv[]) {
    // check command line arguments
    if (argc < 2 || argc > 3) {
        printf("Usage: %s <port> [host]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // get port number
    int port = atoi(argv[1]);
    if (port < 1 || port > 65535) {
        printf("Invalid Port\n");
        exit(EXIT_FAILURE);
    }

    // set host to default hostname if not provided as argument
    char *host;
    if (argc == 3) {
        host = argv[2];
    } else {
        host = "localhost";
    }

    // create socket to listen for incoming client connections
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // bind socket to port number
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
    if (bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Bind failed\n");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_fd, 5) < 0) {
        printf("Error: Listen failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Proxy server started at port %d\n", port);

    // accept incoming connections and process them
    while (1) {
        // accept connection from client
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr*) &client_addr, &client_len);
        if (client_fd < 0) {
            printf("Error: Accept failed\n");
            exit(EXIT_FAILURE);
        }

        // handle client request through proxy server
        proxy(client_fd, host, DEFAULT_PORT);

        // close client connection
        close(client_fd);
    }

    // close server connection
    close(server_fd);

    return 0;
}