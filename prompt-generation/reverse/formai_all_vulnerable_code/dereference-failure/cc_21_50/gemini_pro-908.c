//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Max request size
#define MAX_REQ_SIZE 1024

// Response status codes
#define STATUS_OK 200
#define STATUS_NOT_FOUND 404

// Mime types
#define MIME_HTML "text/html"
#define MIME_CSS "text/css"
#define MIME_JS "application/javascript"
#define MIME_JPG "image/jpeg"
#define MIME_PNG "image/png"

int main(int argc, char **argv) {
    // Check arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get port number
    int port = atoi(argv[1]);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return EXIT_FAILURE;
    }

    // Set socket options
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("ERROR setting socket option");
        return EXIT_FAILURE;
    }

    // Bind socket to port
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR binding socket");
        return EXIT_FAILURE;
    }

    // Listen for connections
    if (listen(sockfd, 5) < 0) {
        perror("ERROR listening on socket");
        return EXIT_FAILURE;
    }

    // Main loop
    while (1) {
        // Accept connection
        struct sockaddr_in cli_addr;
        socklen_t cli_len = sizeof(cli_addr);
        int connfd = accept(sockfd, (struct sockaddr *) &cli_addr, &cli_len);
        if (connfd < 0) {
            perror("ERROR accepting connection");
            continue;
        }

        // Read request
        char req[MAX_REQ_SIZE];
        memset(req, 0, MAX_REQ_SIZE);
        if (read(connfd, req, MAX_REQ_SIZE - 1) < 0) {
            perror("ERROR reading request");
            close(connfd);
            continue;
        }

        // Parse request
        char *method = strtok(req, " ");
        char *path = strtok(NULL, " ");
        char *http_ver = strtok(NULL, "\r\n");

        // Check request method
        if (strcmp(method, "GET") != 0) {
            // Send error response
            char *error_msg = "HTTP/1.1 405 Method Not Allowed\r\nContent-Length: 0\r\n\r\n";
            if (write(connfd, error_msg, strlen(error_msg)) < 0) {
                perror("ERROR writing response");
            }
            close(connfd);
            continue;
        }

        // Check request path
        if (strcmp(path, "/") == 0) {
            path = "/index.html";
        }

        // Get file extension
        char *ext = strrchr(path, '.');
        if (ext == NULL) {
            ext = "";
        }

        // Get file size
        FILE *fp = fopen(path, "rb");
        if (fp == NULL) {
            // Send 404 Not Found response
            char *error_msg = "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n";
            if (write(connfd, error_msg, strlen(error_msg)) < 0) {
                perror("ERROR writing response");
            }
            close(connfd);
            continue;
        }
        fseek(fp, 0, SEEK_END);
        long file_size = ftell(fp);
        rewind(fp);

        // Get mime type
        char *mime_type;
        if (strcmp(ext, ".html") == 0) {
            mime_type = MIME_HTML;
        } else if (strcmp(ext, ".css") == 0) {
            mime_type = MIME_CSS;
        } else if (strcmp(ext, ".js") == 0) {
            mime_type = MIME_JS;
        } else if (strcmp(ext, ".jpg") == 0) {
            mime_type = MIME_JPG;
        } else if (strcmp(ext, ".png") == 0) {
            mime_type = MIME_PNG;
        } else {
            mime_type = "text/plain";
        }

        // Create response header
        char *header = malloc(1024);
        sprintf(header, "HTTP/1.1 %d OK\r\nContent-Type: %s\r\nContent-Length: %ld\r\n\r\n", STATUS_OK, mime_type, file_size);

        // Send response header
        if (write(connfd, header, strlen(header)) < 0) {
            perror("ERROR writing response");
            free(header);
            fclose(fp);
            close(connfd);
            continue;
        }

        // Send file data
        char buf[1024];
        while (fread(buf, 1, sizeof(buf), fp) > 0) {
            if (write(connfd, buf, sizeof(buf)) < 0) {
                perror("ERROR writing response");
                free(header);
                fclose(fp);
                close(connfd);
                continue;
            }
        }

        // Clean up
        free(header);
        fclose(fp);
        close(connfd);
    }

    return EXIT_SUCCESS;
}