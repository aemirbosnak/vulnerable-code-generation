//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 4096

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} connection_t;

typedef struct {
    int num_requests;
    int num_successful_requests;
    int num_failed_requests;
    struct timeval start_time;
    struct timeval end_time;
} monitor_data_t;

void handle_request(connection_t *conn, monitor_data_t *data) {
    int n;
    char buffer[MAX_BUFFER_SIZE];

    // Clear the buffer
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Send a request to the website
    n = send(conn->sockfd, "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n"), 0);
    if (n < 0) {
        perror("send");
        data->num_failed_requests++;
        return;
    }

    // Receive the response from the website
    n = recv(conn->sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (n < 0) {
        perror("recv");
        data->num_failed_requests++;
        return;
    }

    // Check if the response is successful
    if (strstr(buffer, "HTTP/1.1 200 OK") != NULL) {
        data->num_successful_requests++;
    } else {
        data->num_failed_requests++;
    }

    // Close the connection
    close(conn->sockfd);
}

void monitor_website(const char *hostname, int port, int num_requests, monitor_data_t *data) {
    int i;
    connection_t conn;

    // Create a socket
    conn.sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (conn.sockfd < 0) {
        perror("socket");
        return;
    }

    // Get the IP address of the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return;
    }

    // Set the connection address
    memset(&conn.addr, 0, sizeof(conn.addr));
    conn.addr.sin_family = AF_INET;
    conn.addr.sin_port = htons(port);
    memcpy(&conn.addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);

    // Connect to the website
    if (connect(conn.sockfd, (struct sockaddr *) &conn.addr, sizeof(conn.addr)) < 0) {
        perror("connect");
        return;
    }

    // Start the timer
    gettimeofday(&data->start_time, NULL);

    // Send the requests to the website
    for (i = 0; i < num_requests; i++) {
        handle_request(&conn, data);
    }

    // Stop the timer
    gettimeofday(&data->end_time, NULL);
}

void print_results(monitor_data_t *data) {
    double elapsed_time;

    // Calculate the elapsed time
    elapsed_time = (data->end_time.tv_sec - data->start_time.tv_sec) * 1000.0 + (data->end_time.tv_usec - data->start_time.tv_usec) / 1000.0;

    // Print the results
    printf("Number of requests: %d\n", data->num_requests);
    printf("Number of successful requests: %d\n", data->num_successful_requests);
    printf("Number of failed requests: %d\n", data->num_failed_requests);
    printf("Elapsed time: %.2f ms\n", elapsed_time);
}

int main(int argc, char *argv[]) {
    monitor_data_t data;
    const char *hostname;
    int port;
    int num_requests;

    // Get the input parameters
    if (argc < 4) {
        printf("Usage: %s <hostname> <port> <num_requests>\n", argv[0]);
        return 1;
    }

    hostname = argv[1];
    port = atoi(argv[2]);
    num_requests = atoi(argv[3]);

    // Initialize the data structure
    memset(&data, 0, sizeof(data));
    data.num_requests = num_requests;

    // Monitor the website
    monitor_website(hostname, port, num_requests, &data);

    // Print the results
    print_results(&data);

    return 0;
}