//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

// Watson, I think this case is elementary.
int main(void) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    int server_port = 8080;
    int client_address_size = sizeof(client_address);
    char *request_buffer;

    // Let us establish our web server's headquarters at 221B Baker Street.
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(server_port);

    // Holmes, this server is now ready to listen for requests from the outside world.
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Bind failed");
        return EXIT_FAILURE;
    }

    // Inspector Lestrade, we shall now listen for curious web browsers.
    if (listen(server_socket, 5) == -1) {
        perror("Listen failed");
        return EXIT_FAILURE;
    }

    printf("Sherlock's Web Server is now listening on port %d.\n", server_port);

    while (1) {
        // My dear Watson, a client has come to visit.
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size)) == -1) {
            perror("Accept failed");
            return EXIT_FAILURE;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Watson, please fetch me the request from this visitor.
        int request_size = 1024;
        request_buffer = malloc(request_size);
        int bytes_received = recv(client_socket, request_buffer, request_size, 0);

        if (bytes_received == -1) {
            perror("Receive failed");
            return EXIT_FAILURE;
        } else if (bytes_received == 0) {
            printf("Client closed connection\n");
            close(client_socket);
            continue;
        }

        // Excellent, Watson. Now, let us analyze this request.
        char *request_line = strtok(request_buffer, "\r\n");
        char *method = strtok(request_line, " ");
        char *path = strtok(NULL, " ");
        char *http_version = strtok(NULL, "\r\n");

        // Elementary, my dear Watson. This client is requesting the file at %s.
        printf("Method: %s\n", method);
        printf("Path: %s\n", path);
        printf("HTTP version: %s\n", http_version);

        // Now, Watson, we must craft a response that will satisfy our client's insatiable curiosity.
        char *response_line;
        int response_status_code;

        if (strcmp(path, "/") == 0) {
            path = "/index.html";
        }

        if (strcmp(path, "/index.html") == 0) {
            response_status_code = 200;
            response_line = "HTTP/1.1 200 OK\r\n";
        } else if (strcmp(path, "/404.html") == 0) {
            response_status_code = 404;
            response_line = "HTTP/1.1 404 Not Found\r\n";
        } else {
            response_status_code = 403;
            response_line = "HTTP/1.1 403 Forbidden\r\n";
        }

        char *content_type;
        int content_length;

        if (response_status_code == 200) {
            content_type = "text/html";
            content_length = get_file_size(path);
        } else {
            content_type = "text/plain";
            content_length = strlen("Not Found");
        }

        char *response_header;

        response_header = malloc(1024);
        sprintf(response_header, "%s\r\nContent-Type: %s\r\nContent-Length: %d\r\n\r\n", response_line, content_type, content_length);

        // Excellent, Watson. Now, let us send this response to our eager client.
        int bytes_sent = send(client_socket, response_header, strlen(response_header), 0);

        if (bytes_sent == -1) {
            perror("Send failed");
            return EXIT_FAILURE;
        }

        if (response_status_code == 200) {
            int file_descriptor = open(path, O_RDONLY);

            if (file_descriptor == -1) {
                perror("Open failed");
                return EXIT_FAILURE;
            }

            char *file_buffer;
            file_buffer = malloc(content_length);
            int bytes_read = read(file_descriptor, file_buffer, content_length);

            if (bytes_read == -1) {
                perror("Read failed");
                return EXIT_FAILURE;
            }

            bytes_sent = send(client_socket, file_buffer, bytes_read, 0);

            if (bytes_sent == -1) {
                perror("Send failed");
                return EXIT_FAILURE;
            }

            close(file_descriptor);
            free(file_buffer);
        }

        printf("Response sent\n");

        close(client_socket);
    }

    return EXIT_SUCCESS;
}

int get_file_size(char *path) {
    struct stat file_info;

    if (stat(path, &file_info) == -1) {
        perror("Stat failed");
        return -1;
    }

    return file_info.st_size;
}