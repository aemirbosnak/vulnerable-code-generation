//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sock = 0;
    struct hostent *host = NULL;
    struct sockaddr_in server;
    char buffer[1024];
    double start = 0.0, end = 0.0;
    int bytes_read = 0;
    int total_bytes = 0;

    // Get server IP address
    if ((host = gethostbyname("speedtest.net")) == NULL) {
        printf("Error: could not resolve hostname\n");
        return 1;
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: could not create socket\n");
        return 1;
    }

    // Connect to server
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    server.sin_addr = *((struct in_addr *)host->h_addr);
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error: could not connect to server\n");
        return 1;
    }

    // Send GET request
    char request[100] = "GET / HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n";
    send(sock, request, strlen(request), 0);

    // Read response
    while ((bytes_read = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        total_bytes += bytes_read;
    }

    // Calculate speed
    end = time(NULL);
    start = ((double)start == 0.0)? end : start;
    double speed = (double)total_bytes / (end - start);
    printf("Internet speed: %.2f bytes/second\n", speed);

    // Close socket
    close(sock);
    return 0;
}