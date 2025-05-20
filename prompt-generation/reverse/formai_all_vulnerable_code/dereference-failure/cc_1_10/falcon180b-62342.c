//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void send_request(int sock) {
    char request[50] = "GET /speedtest.php HTTP/1.1\r\nHost: www.speedtest.net\r\nConnection: close\r\n\r\n";
    send(sock, request, strlen(request), 0);
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char response[BUFFER_SIZE];
    int bytes_received = 0;
    double start_time, end_time;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, "www.speedtest.net", &server_addr.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Send request
    send_request(sock);

    // Receive response
    while ((bytes_received = recv(sock, response, BUFFER_SIZE, 0)) > 0) {
        response[bytes_received] = 0;
        printf("%s", response);
    }

    // Close socket
    close(sock);

    // Calculate time taken
    start_time = clock();
    end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate speed
    double speed = (double)bytes_received / time_taken;

    // Print results
    printf("\n\nInternet Speed Test Results:\n");
    printf("Bytes Received: %d\n", bytes_received);
    printf("Time Taken: %f seconds\n", time_taken);
    printf("Internet Speed: %f bytes/second\n", speed);

    return 0;
}