//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    // check if URL provided
    if(argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    char *hostname = url;
    char *path = "/";

    // get path
    for(int i = 0; i < strlen(url); i++) {
        if(url[i] == '/') {
            path = &url[i];
            hostname[i] = '\0';
            break;
        }
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;

    // convert hostname to IP address
    if(inet_pton(AF_INET, hostname, &server.sin_addr) <= 0) {
        perror("Invalid URL");
        return 1;
    }

    server.sin_port = htons(80);

    // connect to server
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket < 0) {
        perror("Socket error");
        return 1;
    }

    if(connect(client_socket, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection error");
        return 1;
    }

    // send HTTP request
    char request[1000];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);

    if(send(client_socket, request, strlen(request), 0) < 0) {
        perror("Send error");
        return 1;
    }

    // receive response and print
    char response[10000];
    int bytes_received = 0;

    while(1) {
        int bytes = recv(client_socket, response + bytes_received, 10000 - bytes_received, 0);
        if(bytes <= 0) break;
        bytes_received += bytes;
    }

    printf("%s", response);

    close(client_socket);

    return 0;
}