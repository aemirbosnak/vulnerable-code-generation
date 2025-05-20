//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

// Some genius macros
#define SPEED_TEST_URL "speedtest.net"
#define SPEED_TEST_PORT 80
#define SPEED_TEST_BUFFER_SIZE 1024

// Function to get the current time in milliseconds
long long get_current_time_ms() {
    struct timeval time;
    gettimeofday(&time, NULL);
    return time.tv_sec * 1000 + time.tv_usec / 1000;
}

// Function to send an HTTP request to the speed test server
int send_http_request(int sockfd, char *host, char *path) {
    char request[256];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
    return send(sockfd, request, strlen(request), 0);
}

// Function to receive the HTTP response from the speed test server
int receive_http_response(int sockfd, char *buffer, int buffer_size) {
    int bytes_received = 0;
    while (bytes_received < buffer_size) {
        int bytes_to_read = buffer_size - bytes_received;
        int bytes_read = recv(sockfd, buffer + bytes_received, bytes_to_read, 0);
        if (bytes_read == 0) {
            break;
        }
        bytes_received += bytes_read;
    }
    return bytes_received;
}

// Function to parse the HTTP response from the speed test server
int parse_http_response(char *buffer, int buffer_size, int *content_length) {
    char *content_length_header = strstr(buffer, "Content-Length: ");
    if (content_length_header == NULL) {
        return -1;
    }
    char *content_length_value = content_length_header + strlen("Content-Length: ");
    *content_length = atoi(content_length_value);
    return 0;
}

// Function to download the speed test file from the speed test server
int download_speed_test_file(int sockfd, char *file_name, int file_size) {
    FILE *file = fopen(file_name, "wb");
    if (file == NULL) {
        return -1;
    }
    char buffer[SPEED_TEST_BUFFER_SIZE];
    int bytes_received = 0;
    int bytes_to_receive = file_size;
    while (bytes_received < file_size) {
        int bytes_to_read = bytes_to_receive < SPEED_TEST_BUFFER_SIZE ? bytes_to_receive : SPEED_TEST_BUFFER_SIZE;
        int bytes_read = recv(sockfd, buffer, bytes_to_read, 0);
        if (bytes_read == 0) {
            break;
        }
        bytes_received += bytes_read;
        bytes_to_receive -= bytes_read;
        fwrite(buffer, 1, bytes_read, file);
    }
    fclose(file);
    return 0;
}

// Function to calculate the download speed
double calculate_download_speed(int file_size, long long start_time, long long end_time) {
    return (double)file_size / ((double)(end_time - start_time) / 1000.0);
}

// Function to perform the speed test
double perform_speed_test() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }
    struct hostent *host = gethostbyname(SPEED_TEST_URL);
    if (host == NULL) {
        perror("gethostbyname");
        return -1;
    }
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SPEED_TEST_PORT);
    addr.sin_addr = *((struct in_addr *)host->h_addr);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return -1;
    }
    char path[256];
    sprintf(path, "/speedtest/upload.php");
    if (send_http_request(sockfd, SPEED_TEST_URL, path) == -1) {
        perror("send");
        return -1;
    }
    char buffer[SPEED_TEST_BUFFER_SIZE];
    int bytes_received = receive_http_response(sockfd, buffer, SPEED_TEST_BUFFER_SIZE);
    if (bytes_received == -1) {
        perror("recv");
        return -1;
    }
    int content_length;
    if (parse_http_response(buffer, bytes_received, &content_length) == -1) {
        return -1;
    }
    long long start_time = get_current_time_ms();
    if (download_speed_test_file(sockfd, "speedtest.bin", content_length) == -1) {
        perror("recv");
        return -1;
    }
    long long end_time = get_current_time_ms();
    close(sockfd);
    double download_speed = calculate_download_speed(content_length, start_time, end_time);
    return download_speed;
}

// Function to print the speed test results
void print_speed_test_results(double download_speed) {
    printf("Download Speed: %.2f Mbps\n", download_speed);
}

int main(int argc, char *argv[]) {
    double download_speed = perform_speed_test();
    if (download_speed == -1) {
        perror("perform_speed_test");
        return EXIT_FAILURE;
    }
    print_speed_test_results(download_speed);
    return EXIT_SUCCESS;
}