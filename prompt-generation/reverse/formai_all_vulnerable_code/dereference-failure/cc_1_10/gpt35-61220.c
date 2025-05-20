//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_BUF_SIZE 2048

// Function to check if a given string is an IP address
int isIP(char *str) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, str, &(sa.sin_addr));
    return result != 0;
}

// Function to parse URL and return host and port
int parseURL(char *url, char *host, int *port) {
    // Check if URL is valid
    if (strncmp(url, "http://", 7) != 0) {
        fprintf(stderr, "Invalid URL!\n");
        return -1;
    }
    
    // Parse host and port from URL
    char *p = url + 7; // Remove http:// from beginning
    char *port_str = strchr(p, ':');
    char *path_str = strchr(p, '/');
    if (port_str > path_str || port_str == NULL) {
        // Default port
        *port = 80;
        strncpy(host, p, path_str - p);
    } else {
        // Custom port
        *port = atoi(port_str + 1);
        strncpy(host, p, port_str - p);
    }
    host[path_str - p] = '\0'; // Null-terminate host
    return 0;
}

// Function to send and receive data between client and server
int processData(int client_fd, int server_fd) {
    char buf[MAX_BUF_SIZE];
    int bytes_recv, bytes_sent;
    fd_set read_set;
    int status;

    while (1) {
        FD_ZERO(&read_set);
        FD_SET(client_fd, &read_set);
        FD_SET(server_fd, &read_set);

        status = select(FD_SETSIZE, &read_set, NULL, NULL, NULL);
        if (status < 0) {
            perror("select() failed");
            return -1;
        }

        // Read from client and send to server
        if (FD_ISSET(client_fd, &read_set)) {
            bytes_recv = recv(client_fd, buf, sizeof(buf), 0);
            if (bytes_recv <= 0) {
                break;
            }
            bytes_sent = send(server_fd, buf, bytes_recv, 0);
            if (bytes_sent <= 0) {
                break;
            }
        }

        // Read from server and send to client
        if (FD_ISSET(server_fd, &read_set)) {
            bytes_recv = recv(server_fd, buf, sizeof(buf), 0);
            if (bytes_recv <= 0) {
                break;
            }
            bytes_sent = send(client_fd, buf, bytes_recv, 0);
            if (bytes_sent <= 0) {
                break;
            }
        }
    }

    close(client_fd);
    close(server_fd);
    return 0;
}

int main(int argc, char *argv[]) {
    int client_fd, server_fd, port;
    char *url = argv[1];
    char host[MAX_BUF_SIZE];

    // Check if URL argument exists
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return -1;
    }

    // Parse host and port from URL
    if (parseURL(url, host, &port) < 0) {
        return -1;
    }

    // Resolve hostname to IP address
    struct hostent *he;
    struct in_addr **addr_list;
    if (isIP(host)) {
        he = NULL;
    } else if ((he = gethostbyname(host)) == NULL) {
            // get the host info
        herror("gethostbyname() failed");
        return 1;
    }
    addr_list = (struct in_addr **)he->h_addr_list;
    char ip[17];
    strcpy(ip, inet_ntoa(*addr_list[0]));
    printf("Resolved %s to %s\n", host, ip);

    // Create client socket
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() failed");
        return -1;
    }

    // Set up the client address structure
    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(0); // Bind to any available port
    client_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind the socket to a local address
    if (bind(client_fd, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0) {
        perror("bind() failed");
        return -1;
    }

    // Listen for incoming connections
    if (listen(client_fd, 1) < 0) {
        perror("listen() failed");
        return -1;
    }

    printf("Listening on port %d\n", ntohs(client_addr.sin_port));

    // Connect to server
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() failed");
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        return -1;
    }

    printf("Connected to server %s:%d\n", ip, port);

    // Process client requests
    while (1) {
        // Accept incoming connection from client
        struct sockaddr_in client_conn;
        int client_len = sizeof(client_conn);
        int client_conn_fd = accept(client_fd, (struct sockaddr *)&client_conn, (socklen_t *)&client_len);
        if (client_conn_fd < 0) {
            perror("accept() failed");
            return -1;
        }

        printf("Accepted new connection from %s:%d\n", inet_ntoa(client_conn.sin_addr), ntohs(client_conn.sin_port));

        // Fork a child process to handle connection
        if (fork() == 0) {
            close(client_fd);
            processData(client_conn_fd, server_fd);
            exit(0);
        } else {
            close(client_conn_fd);
        }
    }

    close(server_fd);
    return 0;
}