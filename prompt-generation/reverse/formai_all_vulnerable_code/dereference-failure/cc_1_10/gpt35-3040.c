//FormAI DATASET v1.0 Category: Chat server ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define CONFIG_FILE "config.ini"
#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int load_configuration(char *host, int *port) {
    FILE *fp = fopen(CONFIG_FILE, "r");
    if (fp == NULL) {
        error("Error opening configuration file.");
    }

    char line_buffer[BUFFER_SIZE];
    while (fgets(line_buffer, BUFFER_SIZE, fp)) {
        char *param = strtok(line_buffer, "=");
        char *value = strtok(NULL, "=");

        if (strcmp(param, "host") == 0) {
            strcpy(host, value);
            host[strcspn(host, "\n")] = 0; // Remove trailing newline
        } else if (strcmp(param, "port") == 0) {
            *port = atoi(value);
        }
    }

    fclose(fp);
    return 0;
}

int main() {
    char host[BUFFER_SIZE];
    int port = 0;

    load_configuration(host, &port);

    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        error("Error creating socket.");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(host);
    server_addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error binding socket.");
    }

    listen(server_fd, 5); // Queue max 5 clients

    printf("Server started and listening on %s:%d.\n", host, port);

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_fd < 0) {
            error("Error accepting client connection.");
        }

        char buffer[BUFFER_SIZE];
        int bytes_read = read(client_fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0) {
            error("Error reading from client.");
        }

        printf("Received message from client: %s\n", buffer);

        char response[] = "Message received!";
        int bytes_written = write(client_fd, response, strlen(response));
        if (bytes_written < 0) {
            error("Error writing to client.");
        }

        close(client_fd);
    }

    close(server_fd);
    return 0;
}