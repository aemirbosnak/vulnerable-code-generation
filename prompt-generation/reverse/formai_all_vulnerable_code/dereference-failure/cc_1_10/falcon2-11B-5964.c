//Falcon2-11B DATASET v1.0 Category: Networking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFERSIZE 1024

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s port\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    listen(server_socket, 5);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket < 0) {
            printf("Error accepting client\n");
            continue;
        }

        char buffer[BUFFERSIZE];
        int bytes_read = recv(client_socket, buffer, BUFFERSIZE, 0);

        if (bytes_read < 0) {
            printf("Error reading from client\n");
            continue;
        }

        printf("Client connected: %s\n", buffer);

        // Handle GET request
        if (strcmp(buffer, "GET /index.html HTTP/1.1\r\n\r\n") == 0) {
            FILE *file = fopen("index.html", "r");

            if (file == NULL) {
                printf("Error opening index.html\n");
                continue;
            }

            fseek(file, 0, SEEK_END);
            int file_size = ftell(file);
            fseek(file, 0, SEEK_SET);

            char file_content[file_size + 1];
            fread(file_content, 1, file_size, file);
            file_content[file_size] = '\0';

            send(client_socket, file_content, strlen(file_content), 0);
            fclose(file);
        }

        // Handle POST request
        else if (strcmp(buffer, "POST /form.html HTTP/1.1\r\nContent-Type: application/x-www-form-urlencoded\r\n\r\nname=John&age=25") == 0) {
            printf("POST request received\n");

            // Process the form data

            send(client_socket, "HTTP/1.1 200 OK\r\n\r\n", 26, 0);
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}