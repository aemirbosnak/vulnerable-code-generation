//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_REQUEST_SIZE 4096
#define MAX_HEADER_SIZE 512
#define MAX_RESPONSE_SIZE 32768
#define MAX_ERROR_SIZE 1024

/* Function to print error messages */ 
void print_error(const char* error_message) {
    fprintf(stderr, "%s\n", error_message);
}

/* Function to check if a string is numeric */ 
bool is_numeric(const char* str) {
    while (*str) {
        if (!isdigit(*str++)) {
            return false;
        }
    }
    return true;
}

/* Function to parse a URL and get the IP address and port */
bool parse_url(const char* url, char* host, char* path, int* port) {
    const char* protocol_end = strstr(url, "://");
    if (!protocol_end) {
        print_error("Invalid URL. No protocol specified.");
        return false;
    }

    const char* host_start = protocol_end + strlen("://");
    const char* path_start = strchr(host_start, '/');
    if (!path_start) {
        path_start = "/";
    }

    const char* port_start = strchr(host_start, ':');
    if (port_start && port_start < path_start) {
        *port = atoi(port_start + 1);
    } else {
        *port = 80;
    }

    int host_len = (port_start ? port_start : path_start) - host_start;
    strncpy(host, host_start, host_len);
    host[host_len] = '\0';

    strcpy(path, path_start);

    return true;
}

/* Function to build an HTTP request given the specified parameters */
bool build_http_request(const char* host, const char* path, const char* method, const char* headers[], char* request) {
    sprintf(request, "%s %s HTTP/1.1\r\n", method, path);
    strcat(request, "Host: ");
    strcat(request, host);
    strcat(request, "\r\n");

    for (int i = 0; headers[i]; i++) {
        strcat(request, headers[i]);
        strcat(request, "\r\n");
    }

    strcat(request, "\r\n");

    return true;
}

/* Main function to fetch a webpage */ 
int main(int argc, char** argv) {
    if (argc < 2) {
        print_error("Usage: http_client <url>");
        exit(EXIT_FAILURE);
    }

    char host[128] = "";
    char path[1024] = "";
    int port = 0;

    if (!parse_url(argv[1], host, path, &port)) {
        exit(EXIT_FAILURE);
    }

    char* headers[] = {
        "User-Agent: http_client/1.0",
        NULL
    };

    char request[MAX_REQUEST_SIZE] = "";
    if (!build_http_request(host, path, "GET", headers, request)) {
        print_error("Error building HTTP request.");
        exit(EXIT_FAILURE);
    }

    /* Open a connection to the server */
    struct hostent* server = gethostbyname(host);
    if (!server) {
        print_error("Error resolving server address.");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    memcpy(&server_address.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        print_error("Error opening socket.");
        exit(EXIT_FAILURE);
    }
    if (connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) != 0) {
        print_error("Error connecting to server.");
        exit(EXIT_FAILURE);
    }

    /* Send the HTTP request */
    if (send(socket_fd, request, strlen(request), 0) < 0) {
        print_error("Error sending HTTP request.");
        exit(EXIT_FAILURE);
    }

    /* Read the response from the server */
    char response[MAX_RESPONSE_SIZE] = "";
    int n = 0;
    while ((n = recv(socket_fd, response, MAX_RESPONSE_SIZE - 1, 0)) > 0) {
        response[n] = '\0';
        printf("%s", response);
    }

    if (n < 0) {
        print_error("Error reading from server.");
        exit(EXIT_FAILURE);
    }

    /* Close the socket */
    close(socket_fd);

    return EXIT_SUCCESS;
}