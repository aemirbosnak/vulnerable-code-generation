//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT "80" // The port number to connect to for HTTP(S) requests

// Given a hostname, returns its IPv4 address
int get_ip_address(const char *hostname, char *ip_address) {
    struct addrinfo hints, *server_info, *p;
    struct sockaddr_in *ipv4_address;
    int status;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP

    if ((status = getaddrinfo(hostname, NULL, &hints, &server_info)) != 0) {
        printf("Error: getaddrinfo - %s\n", gai_strerror(status));
        return 1;
    }

    // Loop through all the results and connect to the first possible IPv4 address
    for (p = server_info; p != NULL; p = p->ai_next) {
        ipv4_address = (struct sockaddr_in*) p->ai_addr;
        inet_ntop(p->ai_family, &ipv4_address->sin_addr, ip_address, INET_ADDRSTRLEN);
        break; // Connect to the first possible IPv4 address
    }

    freeaddrinfo(server_info);

    if (p == NULL) {
        printf("Error: Could not connect to %s\n", hostname);
        return 1;
    }

    return 0;
}

// Given an IP address and a file path, sends an HTTP GET request to the server and returns
// the response time and data received
int send_http_request(const char *ip_address, const char *file_path, double *response_time, char *data_received) {
    struct timeval start_time, end_time, time_diff;
    struct addrinfo hints, *server_info, *p;
    int sockfd, num_bytes, status;
    char request_message[1024];
    char ip_port[16];
    struct sockaddr_in dest;

    // Format the request message as an HTTP GET request
    sprintf(request_message, "GET %s HTTP/1.1\r\nHost: %s:%s\r\n\r\n", file_path, ip_address, PORT);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP

    if ((status = getaddrinfo(ip_address, PORT, &hints, &server_info)) != 0) {
        printf("Error: getaddrinfo - %s\n", gai_strerror(status));
        return 1;
    }

    // Loop through all the results and connect to the first possible IPv4 address
    for (p = server_info; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            printf("Error: socket - %s\n", strerror(errno));
            continue;
        }

        // Connect to the server
        dest.sin_family = AF_INET;
        dest.sin_port = htons(atoi(PORT));
        dest.sin_addr = ((struct sockaddr_in *)(p->ai_addr))->sin_addr;
        memset(&(dest.sin_zero), '\0', 8);

        gettimeofday(&start_time, NULL);
        if (connect(sockfd, (struct sockaddr *)&dest, sizeof(struct sockaddr)) == -1) {
            printf("Error: connect - %s\n", strerror(errno));
            close(sockfd);
            continue;
        }
        gettimeofday(&end_time, NULL);

        break;
    }

    if (p == NULL) {
        printf("Error: Failed to connect to server\n");
        return 1;
    }

    freeaddrinfo(server_info);

    if (*response_time = ((end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_usec - start_time.tv_usec) / 1000.0) < 0) {
        printf("Error: Response time is negative\n");
        return 1;
    }

    // Send the HTTP GET request to the server
    if (send(sockfd, request_message, strlen(request_message), 0) == -1) {
        printf("Error: send - %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    // Receive the server's response
    if ((num_bytes = recv(sockfd, data_received, 1024 - 1, 0)) == -1) {
        printf("Error: recv - %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    close(sockfd);

    data_received[num_bytes] = '\0';

    return 0;
}

// Given a response time and data received, prints out the speed test results
void print_speed_test_results(double response_time, const char *data_received) {
    int download_speed = strlen(data_received) / (response_time / 1000.0);
    printf("Download speed: %d kb/s (%d bytes in %0.2f ms)\n", download_speed, strlen(data_received), response_time);
}

int main(int argc, char *argv[]) {
    char ip_address[INET_ADDRSTRLEN];
    double response_time;
    char data_received[1024];

    if (argc != 2) {
        printf("USAGE: %s <hostname>\n", argv[0]);
        return 1;
    }

    if (get_ip_address(argv[1], ip_address) != 0) {
        return 1;
    }

    if (send_http_request(ip_address, "/", &response_time, data_received) != 0) {
        return 1;
    }

    print_speed_test_results(response_time, data_received);

    return 0;
}