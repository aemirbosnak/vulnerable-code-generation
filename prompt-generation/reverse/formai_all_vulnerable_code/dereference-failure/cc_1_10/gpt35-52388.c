//FormAI DATASET v1.0 Category: Simple Web Server ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/stat.h>

#define PORT "8080"
#define WEB_ROOT "/var/www/html"

/*
 * Function: parse_request
 * --------------------------
 * Parse the incoming HTTP request and extract the relevant information
 *
 * request: The incoming HTTP request
 * path: Pointer to char array to store the requested resource path
 */
void parse_request(char *request, char *path) {
    char *token;
    token = strtok(request, " ");
    token = strtok(NULL, " ");
    strncpy(path, token, strlen(token) + 1);
}

/*
 * Function: send_response
 * ------------------------
 * Send an HTTP response to the client for the requested resource
 *
 * client_sock: Socket file descriptor for the client connection
 * status_code: HTTP status code of the response
 * content_type: Content-Type of the response
 * content_length: Length of the content in bytes
 * content: Pointer to the content to be sent
 */
void send_response(int client_sock, int status_code, char *content_type,
                   int content_length, char *content) {
    char response[4096];
    sprintf(response, "HTTP/1.1 %d OK\r\n", status_code);
    sprintf(response + strlen(response), "Content-Type: %s\r\n", content_type);
    sprintf(response + strlen(response), "Content-Length: %d\r\n", content_length);
    sprintf(response + strlen(response), "\r\n");
    sprintf(response + strlen(response), "%s", content);
    send(client_sock, response, strlen(response), 0);
}

int main(int argc, char *argv[]) {
    struct addrinfo hints, *res;
    int server_sock, client_sock;
    struct sockaddr_storage client_addr;
    socklen_t sin_size;
    char request[4096], path[4096], file_path[4096];
    int num_bytes;
    struct stat file_stat;

    // Set up hints for getaddrinfo
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; 

    // Get address info for the server
    getaddrinfo(NULL, PORT, &hints, &res);

    // Create a socket for the server
    server_sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    // Bind the server socket to the port
    bind(server_sock, res->ai_addr, res->ai_addrlen);

    // Listen on the socket for incoming connections
    listen(server_sock, 10);

    // Loop forever, accepting and servicing connections
    while (true) {
        sin_size = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &sin_size);
        if (client_sock == -1) {
            perror("accept");
            continue;
        }

        // Receive the HTTP request
        memset(request, 0, sizeof(request));
        num_bytes = recv(client_sock, request, sizeof(request), 0);
        if (num_bytes == -1) {
            perror("recv");
            continue;
        }

        // Parse the request and construct the file path
        memset(path, 0, sizeof(path));
        parse_request(request, path);
        sprintf(file_path, "%s%s", WEB_ROOT, path);

        // Check if the file exists and is readable
        if (access(file_path, R_OK) == -1) {
            send_response(client_sock, 404, "text/html", 0, "");
            close(client_sock);
            continue;
        }

        // Get the file stats to determine content length
        stat(file_path, &file_stat);
        int file_size = file_stat.st_size;

        // Open and read the file into memory
        int fd = open(file_path, O_RDONLY);
        char *file_contents = malloc(file_size+1);
        read(fd, file_contents, file_size);
        file_contents[file_size] = '\0';
        close(fd);

        // Set the content type based on the file extension
        char *content_type;
        if (strstr(file_path, ".html")) {
            content_type = "text/html";
        } else if (strstr(file_path, ".css")) {
            content_type = "text/css";
        } else if (strstr(file_path, ".js")) {
            content_type = "application/javascript";
        } else {
            content_type = "text/plain";
        }

        // Send the HTTP response with the file contents
        send_response(client_sock, 200, content_type, file_size, file_contents);
        free(file_contents);
        close(client_sock);
    }

    freeaddrinfo(res);
    return 0;
}