//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>

// Function to get the current timestamp in milliseconds
long long get_timestamp() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000;
}

// Function to measure the latency of a network connection
long long measure_latency(const char *host, int port) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Get the IP address of the host
    struct hostent *he = gethostbyname(host);
    if (!he) {
        perror("gethostbyname");
        return -1;
    }

    // Connect to the host
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    memcpy(&addr.sin_addr, he->h_addr, he->h_length);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        return -1;
    }

    // Send a message to the host
    char *msg = "hello";
    if (send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("send");
        return -1;
    }

    // Receive a message from the host
    char buf[1024];
    int n = recv(sockfd, buf, sizeof(buf), 0);
    if (n < 0) {
        perror("recv");
        return -1;
    }

    // Calculate the latency
    long long timestamp = get_timestamp();
    long long rtt = timestamp - (long long)buf[n - 1];

    // Close the socket
    close(sockfd);

    return rtt;
}

// Function to measure the throughput of a network connection
long long measure_throughput(const char *host, int port, int duration) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Get the IP address of the host
    struct hostent *he = gethostbyname(host);
    if (!he) {
        perror("gethostbyname");
        return -1;
    }

    // Connect to the host
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    memcpy(&addr.sin_addr, he->h_addr, he->h_length);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        return -1;
    }

    // Send data to the host
    char *data = malloc(1024);
    memset(data, 1, 1024);
    int total_sent = 0;
    long long timestamp = get_timestamp();
    while (get_timestamp() - timestamp < duration * 1000) {
        int n = send(sockfd, data, 1024, 0);
        if (n < 0) {
            perror("send");
            return -1;
        }
        total_sent += n;
    }

    // Calculate the throughput
    long long throughput = total_sent / duration;

    // Close the socket
    close(sockfd);

    return throughput;
}

int main() {
    // Measure the latency of a connection to www.google.com on port 80
    long long latency = measure_latency("www.google.com", 80);
    if (latency < 0) {
        fprintf(stderr, "Error measuring latency\n");
        return 1;
    }

    // Measure the throughput of a connection to www.google.com on port 80
    long long throughput = measure_throughput("www.google.com", 80, 10);
    if (throughput < 0) {
        fprintf(stderr, "Error measuring throughput\n");
        return 1;
    }

    // Print the results
    printf("Latency: %lld ms\n", latency);
    printf("Throughput: %lld KB/s\n", throughput);

    return 0;
}