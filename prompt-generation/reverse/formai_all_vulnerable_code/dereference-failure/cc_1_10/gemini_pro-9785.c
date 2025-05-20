//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>
#include <sys/time.h>

// Buffers and default values
#define BUFFER_SIZE         (1024 * 1024)
#define DEFAULT_SERVER_HOST "www.google.com"
#define DEFAULT_SERVER_PORT 80
#define DEFAULT_TEST_TIMES  10

// Function prototypes
int test_internet_speed(const char *server_host, int server_port, int test_times);
double get_current_time();
double get_time_difference(double start, double end);
void print_result(double elapsed_time, double total_bytes);

int main(int argc, char *argv[]) {
    char *server_host = DEFAULT_SERVER_HOST;
    int server_port = DEFAULT_SERVER_PORT;
    int test_times = DEFAULT_TEST_TIMES;

    // Parse command line arguments
    if (argc > 1) {
        server_host = argv[1];
    }
    if (argc > 2) {
        server_port = atoi(argv[2]);
    }
    if (argc > 3) {
        test_times = atoi(argv[3]);
    }

    // Test the Internet speed
    double elapsed_time = test_internet_speed(server_host, server_port, test_times);
    double total_bytes = BUFFER_SIZE * test_times;

    // Print the result
    print_result(elapsed_time, total_bytes);

    return 0;
}

int test_internet_speed(const char *server_host, int server_port, int test_times) {
    int sockfd, bytes_received;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    struct hostent *server;
    double start_time, end_time;
    double elapsed_time = 0.0;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket() failed");
        return -1;
    }

    // Get the server's IP address
    server = gethostbyname(server_host);
    if (server == NULL) {
        perror("gethostbyname() failed");
        close(sockfd);
        return -1;
    }

    // Fill in the server's address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(server_port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect() failed");
        close(sockfd);
        return -1;
    }

    // Send the request to the server
    if (write(sockfd, "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n")) == -1) {
        perror("write() failed");
        close(sockfd);
        return -1;
    }

    // Receive the response from the server
    for (int i = 0; i < test_times; i++) {
        start_time = get_current_time();

        bytes_received = read(sockfd, buffer, BUFFER_SIZE);
        if (bytes_received == -1) {
            perror("read() failed");
            close(sockfd);
            return -1;
        }

        end_time = get_current_time();
        elapsed_time += get_time_difference(start_time, end_time);
    }

    // Close the socket
    close(sockfd);

    return elapsed_time;
}

double get_current_time() {
    struct timeval tv;

    if (gettimeofday(&tv, NULL) == -1) {
        perror("gettimeofday() failed");
        return -1.0;
    }

    return tv.tv_sec + tv.tv_usec / 1000000.0;
}

double get_time_difference(double start, double end) {
    return end - start;
}

void print_result(double elapsed_time, double total_bytes) {
    double speed = total_bytes / elapsed_time;

    printf("Internet speed: %.2f MB/s\n", speed / (1024.0 * 1024.0));
}