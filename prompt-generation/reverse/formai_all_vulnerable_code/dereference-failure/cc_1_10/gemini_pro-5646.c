//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: multivariable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void test_speed(char *server_ip, int port, int buffer_size, int seconds) {
    int sockfd;
    struct sockaddr_in servaddr;

    printf("Connecting to server: %s:%d\n", server_ip, port);
    
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        return;
    }

    // Configure the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(server_ip);
    servaddr.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error connecting to server");
        return;
    }

    printf("Connected to server\n");

    // Send a request to the server
    char *request = "GET / HTTP/1.1\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("Error sending request to server");
        return;
    }

    printf("Sent request to server\n");

    // Receive the response from the server
    char buffer[buffer_size];
    memset(buffer, 0, buffer_size);
    int bytes_received = 0;
    time_t start_time = time(NULL);

    while (bytes_received < buffer_size && (time(NULL) - start_time) < seconds) {
        int n = recv(sockfd, buffer, buffer_size, 0);
        if (n == -1) {
            perror("Error receiving response from server");
            return;
        }
        bytes_received += n;
    }

    printf("Received response from server\n");

    // Calculate the speed
    double speed = (double)bytes_received / seconds;
    printf("Speed: %.2f bytes/s\n", speed);

    // Close the socket
    close(sockfd);
}

int main(int argc, char **argv) {
    if (argc != 6) {
        printf("Usage: %s <server_ip> <port> <buffer_size> <seconds> <iterations>\n", argv[0]);
        return 1;
    }

    char *server_ip = argv[1];
    int port = atoi(argv[2]);
    int buffer_size = atoi(argv[3]);
    int seconds = atoi(argv[4]);
    int iterations = atoi(argv[5]);

    for (int i = 0; i < iterations; i++) {
        test_speed(server_ip, port, buffer_size, seconds);
    }

    return 0;
}