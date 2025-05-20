//FormAI DATASET v1.0 Category: Simple Web Server ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>

#define PORT 8080
#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char resp[] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><title>The Surreal Web Server</title></head><body><h1>Welcome to the Surreal Web Server!</h1><p>The time is: ";

    char time_str[BUFFER_SIZE];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(time_str, sizeof(time_str), "%c\n", tm);
    strcat(resp, time_str);
    strcat(resp, "</p><p>This server exists in a dimension beyond your mortal understanding...</p></body></html>");

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("The Surreal Web Server is listening on port %d...\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        valread = read(new_socket, buffer, BUFFER_SIZE);
        printf("%s\n", buffer);

        write(new_socket, resp, strlen(resp));

        close(new_socket);
    }

    return 0;
}