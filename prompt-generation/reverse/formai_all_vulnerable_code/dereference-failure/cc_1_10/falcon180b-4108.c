//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <server_ip>\n", argv[0]);
        exit(1);
    }

    char *server_ip = argv[1];
    struct sockaddr_in server_addr;
    int sockfd;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error_handling("socket failed");
    }

    // set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("connect failed");
    }

    // send request
    char request[100] = "GET /speedtest.php HTTP/1.1\r\nHost: ";
    strcat(request, server_ip);
    strcat(request, "\r\nConnection: close\r\n\r\n");

    send(sockfd, request, strlen(request), 0);

    // receive response
    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);

    time_t start_time = time(NULL);
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, response + bytes_received, BUFFER_SIZE - bytes_received, 0))!= 0) {
        if (bytes_received == -1) {
            error_handling("recv failed");
        }
    }

    time_t end_time = time(NULL);
    double elapsed_time = difftime(end_time, start_time);

    // calculate speed
    double speed = (double)bytes_received / (elapsed_time * 1000);

    // print result
    printf("Internet speed: %.2f kB/s\n", speed);

    close(sockfd);
    return 0;
}