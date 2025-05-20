//MISTRAL-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <time.h>
#define PORT 80
#define BUF_SIZE 1024
#define SERVER_IP "192.168.1.1" // Replace with the target website IP
#define URL_LENGTH 100
#define HEADER_LENGTH 20

int main() {
    int sockfd, new_sockfd, read_size, len;
    struct sockaddr_in server, client;
    char buffer[BUF_SIZE];
    char *request = (char*) malloc(URL_LENGTH);
    char *header = (char*) malloc(HEADER_LENGTH);
    char response[BUF_SIZE];
    time_t start_time, end_time, elapsed_time;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &server.sin_addr);

    if (connect(sockfd, (struct sockaddr*) &server, sizeof(server)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    start_time = time(NULL);

    snprintf(request, URL_LENGTH, "GET / HTTP/1.1\r\nHost: %s\r\nUser-Agent: Uptime-Monster/1.0\r\nAccept: */*\r\nConnection: close\r\n\r\n", SERVER_IP);

    write(sockfd, request, strlen(request));

    read_size = recv(sockfd, buffer, BUF_SIZE, 0);
    if (read_size <= 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }

    strcpy(response, buffer);

    strncpy(header, buffer, HEADER_LENGTH);
    len = strlen(header);

    if (strstr(header, "HTTP/1.1 200 OK") || strstr(header, "HTTP/1.0 200 OK")) {
        end_time = time(NULL);
        elapsed_time = end_time - start_time;
        printf("Website is up. Response time: %.2f seconds\n", elapsed_time);
    } else {
        perror("Error in response header");
        exit(EXIT_FAILURE);
    }

    free(request);
    free(header);
    close(sockfd);

    return 0;
}