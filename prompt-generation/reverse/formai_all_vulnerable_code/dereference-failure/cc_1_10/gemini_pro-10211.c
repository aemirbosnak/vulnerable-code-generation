//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define TEST_DURATION 10 // in seconds
#define MAX_CONNECTIONS 10

// Function to get the IP address of a hostname
char *get_ip_address(const char *hostname) {
    struct hostent *host;
    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname %s\n", hostname);
        return NULL;
    }
    return inet_ntoa(*((struct in_addr *)host->h_addr));
}

// Function to create a socket and connect to a server
int create_socket_and_connect(const char *ip_address, int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error: Could not create socket\n");
        return -1;
    }

    // Set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(ip_address);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        fprintf(stderr, "Error: Could not connect to server\n");
        return -1;
    }

    return sockfd;
}

// Function to send data to a server
int send_data(int sockfd, char *buffer, int buffer_size) {
    int bytes_sent;

    bytes_sent = send(sockfd, buffer, buffer_size, 0);
    if (bytes_sent == -1) {
        fprintf(stderr, "Error: Could not send data to server\n");
        return -1;
    }

    return bytes_sent;
}

// Function to receive data from a server
int receive_data(int sockfd, char *buffer, int buffer_size) {
    int bytes_received;

    bytes_received = recv(sockfd, buffer, buffer_size, 0);
    if (bytes_received == -1) {
        fprintf(stderr, "Error: Could not receive data from server\n");
        return -1;
    }

    return bytes_received;
}

// Function to perform an Internet speed test
int internet_speed_test(const char *hostname, int port) {
    int i, sockfd, bytes_sent, bytes_received;
    char ip_address[INET_ADDRSTRLEN];
    char buffer[BUFFER_SIZE];
    struct timeval start_time, end_time;
    double elapsed_time, download_speed, upload_speed;

    // Get the IP address of the hostname
    const char *ip = get_ip_address(hostname);
    if (ip == NULL) {
        return -1;
    }

    // Create a socket and connect to the server
    sockfd = create_socket_and_connect(ip, port);
    if (sockfd == -1) {
        return -1;
    }

    // Download speed test
    printf("Download Speed Test:\n");
    gettimeofday(&start_time, NULL);
    for (i = 0; i < TEST_DURATION; i++) {
        bytes_sent = send_data(sockfd, buffer, BUFFER_SIZE);
        if (bytes_sent == -1) {
            return -1;
        }
    }
    gettimeofday(&end_time, NULL);
    elapsed_time = (double)(end_time.tv_sec - start_time.tv_sec) +
                    (double)(end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    download_speed = (double)(bytes_sent * 8) / (elapsed_time * 1000000);
    printf("Download speed: %f Mbps\n", download_speed);

    // Upload speed test
    printf("Upload Speed Test:\n");
    gettimeofday(&start_time, NULL);
    for (i = 0; i < TEST_DURATION; i++) {
        bytes_received = receive_data(sockfd, buffer, BUFFER_SIZE);
        if (bytes_received == -1) {
            return -1;
        }
    }
    gettimeofday(&end_time, NULL);
    elapsed_time = (double)(end_time.tv_sec - start_time.tv_sec) +
                    (double)(end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    upload_speed = (double)(bytes_received * 8) / (elapsed_time * 1000000);
    printf("Upload speed: %f Mbps\n", upload_speed);

    // Close the socket
    close(sockfd);

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Perform the Internet speed test
    int ret = internet_speed_test(argv[1], atoi(argv[2]));
    if (ret == -1) {
        fprintf(stderr, "Error: Internet speed test failed\n");
        return 1;
    }

    return 0;
}