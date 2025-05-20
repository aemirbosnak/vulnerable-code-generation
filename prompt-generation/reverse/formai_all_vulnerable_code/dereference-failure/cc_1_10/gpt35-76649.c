//FormAI DATASET v1.0 Category: Simple Web Server ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_REQUEST_SIZE 2048
#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char *response_body = "<html><body><h1>Hello, World!</h1></body></html>";
    int response_body_size = strlen(response_body);
    char response_header[256];
    sprintf(response_header, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n", response_body_size);

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (true) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                   (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        char *request_buffer = (char*)malloc(sizeof(char) * MAX_REQUEST_SIZE);
        valread = read(new_socket , request_buffer, MAX_REQUEST_SIZE);

        if (valread == 0) {
            continue;
        }

        request_buffer[valread] = '\0';
        printf("%s\n", request_buffer);

        // Send HTTP response
        write(new_socket , response_header, strlen(response_header));
        write(new_socket , response_body, strlen(response_body));
        printf("%s\n", response_header);
        printf("%s\n", response_body);

        free(request_buffer);
        close(new_socket);
    }

    return 0;
}