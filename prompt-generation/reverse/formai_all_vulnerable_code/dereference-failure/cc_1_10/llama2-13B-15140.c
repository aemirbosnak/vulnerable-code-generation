//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: irregular
// This is not your average web server...

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct employee {
    char name[50];
    char title[50];
    int age;
};

struct employee employees[] = {
    {"Alice", "Dev", 25},
    {"Bob", "QA", 30},
    {"Charlie", "Manager", 40}
};

int main(void) {
    int server_fd, client_fd;
    socklen_t client_len = sizeof(struct employee);
    char buffer[512];

    // Create the server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set address and port number
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind the server socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening for incoming connections...\n");

    // Accept an incoming connection
    client_fd = accept(server_fd, (struct sockaddr *)NULL, &client_len);
    if (client_fd < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted from client...\n");

    // Read the incoming request
    read(client_fd, buffer, 512);
    printf("Received request: %s\n", buffer);

    // Send the server's response
    char *employee_name = "Alice";
    char *employee_title = "Dev";
    char response[512];
    sprintf(response, "Hello, %s! I am %s.", buffer, employee_title);
    send(client_fd, response, strlen(response), 0);

    // Close the client socket
    close(client_fd);

    // Close the server socket
    close(server_fd);

    return 0;
}