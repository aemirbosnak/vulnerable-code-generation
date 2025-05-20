//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server_ip_address> <server_port>\n", argv[0]);
        return 1;
    }

    char *server_ip_address = argv[1];
    int server_port = atoi(argv[2]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip_address);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send a request to the server
    char request[] = "GET / HTTP/1.1\r\n\r\n";
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the response from the server
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    clock_t start_time = clock();

    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        // Keep receiving data until the server closes the connection
    }

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate the download speed
    double download_speed = (double)bytes_received / elapsed_time;

    // Print the download speed
    printf("Download speed: %.2f KB/s\n", download_speed / 1024);

    // Close the socket
    close(sock);

    return 0;
}