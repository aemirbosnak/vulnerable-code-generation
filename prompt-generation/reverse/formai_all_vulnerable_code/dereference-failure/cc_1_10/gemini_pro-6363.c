//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>

// Colors for terminal output
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

// Function to calculate the time difference between two timevals
double timeval_diff(struct timeval *a, struct timeval *b) {
    return (double)(a->tv_sec - b->tv_sec) + (double)(a->tv_usec - b->tv_usec) / 1000000.0;
}

// Function to perform a single speed test
double speed_test(char *server_ip, int port) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, server_ip, &servaddr.sin_addr) <= 0) {
        perror("Error converting server IP address");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send a request to the server
    n = write(sockfd, "GET /speedtest.php HTTP/1.1\r\n", 32);
    if (n < 0) {
        perror("Error sending request to server");
        exit(1);
    }

    // Read the response from the server
    n = read(sockfd, buffer, 1024);
    if (n < 0) {
        perror("Error reading response from server");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    // Parse the response from the server and get the download speed
    char *start = strstr(buffer, "Download: ");
    if (start == NULL) {
        printf("Error parsing server response\n");
        exit(1);
    }
    char *end = strstr(start, " Mbit/s");
    if (end == NULL) {
        printf("Error parsing server response\n");
        exit(1);
    }
    *end = '\0';
    double speed = atof(start + 9);

    return speed;
}


// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server_ip> <port>\n", argv[0]);
        return 1;
    }

    // Get the server IP address and port
    char *server_ip = argv[1];
    int port = atoi(argv[2]);

    // Perform multiple speed tests and calculate the average speed
    int num_tests = 10;
    double total_speed = 0;
    for (int i = 0; i < num_tests; i++) {
        double speed = speed_test(server_ip, port);
        total_speed += speed;
    }
    double average_speed = total_speed / num_tests;

    // Print the results
    printf(GREEN"Your internet speed is: "YELLOW"%.2f Mbit/s\n"RESET, average_speed);

    return 0;
}