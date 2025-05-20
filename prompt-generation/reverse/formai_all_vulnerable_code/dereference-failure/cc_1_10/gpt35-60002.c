//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>

#define BUFFER_SIZE 1024
#define MAX_HOSTNAME 256
#define TIMEOUT 30

// Function to display error message and exit
void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Function to create a socket connection and return the socket file descriptor
int create_socket(const char *hostname, int port, struct sockaddr_in *server_addr) {
    // Resolve the IP address of the host
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        error_exit("Error in resolving the hostname");
    }

    // Create a socket for the connection
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        error_exit("Error in creating a socket");
    }

    // Configure the server address details
    memset(server_addr, 0, sizeof(*server_addr));
    server_addr->sin_family = AF_INET;
    server_addr->sin_addr.s_addr = *((in_addr_t *) host->h_addr_list[0]);
    server_addr->sin_port = htons(port);

    return socket_fd;
}

// Function to set socket communication to non-blocking mode
void set_nonblocking(int socket_fd) {
    int flags = fcntl(socket_fd, F_GETFL, 0);
    if (flags == -1) {
        error_exit("Error in getting socket flags");
    }

    flags |= O_NONBLOCK;
    if (fcntl(socket_fd, F_SETFL, flags) == -1) {
        error_exit("Error in setting socket flags");
    }
}

// Function to connect to the server
void connect_server(int socket_fd, struct sockaddr_in server_addr, int *timeout_flag) {
    // Set the socket to non-blocking mode
    set_nonblocking(socket_fd);

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        if (errno == EINPROGRESS) {
            // Connection is in progress, set a timeout and wait for the response
            fd_set checking_set;
            FD_ZERO(&checking_set);
            FD_SET(socket_fd, &checking_set);

            struct timeval timeout;
            timeout.tv_sec = TIMEOUT;
            timeout.tv_usec = 0;

            int result = select(socket_fd + 1, NULL, &checking_set, NULL, &timeout);

            if (result == -1) {
                error_exit("Error in select");
            } else if (result == 0) {
                // Timeout occurred
                *timeout_flag = 1;
            } else {
                // Connection established
                int error = 0;
                socklen_t error_len = sizeof(error);
                if (getsockopt(socket_fd, SOL_SOCKET, SO_ERROR, &error, &error_len) == -1) {
                    error_exit("Error in getting socket options");
                }

                if (error != 0) {
                    *timeout_flag = 1;
                }
            }
        } else {
            // Error occurred in connection
            *timeout_flag = 1;
        }
    }
}

// Function to calculate the average RTT and packet loss
void calculate_metrics(double *avg_rtt, int *packet_loss, int *total_packets_sent) {
    char buffer[BUFFER_SIZE];
    struct timeval start_time, end_time, timeout;
    double rtt_sum = 0;
    int packets_received = 0, packets_lost = 0;

    // Set a timeout for receiving the response
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    while (*total_packets_sent < 10) {
        // Send a ping message to the server and record the start time
        gettimeofday(&start_time, NULL);
        sprintf(buffer, "PING %d\n", *total_packets_sent + 1);
        send(1, buffer, strlen(buffer), 0);

        // Wait for the response or timeout
        fd_set checking_set;
        FD_ZERO(&checking_set);
        FD_SET(1, &checking_set);

        int result = select(1 + 1, &checking_set, NULL, NULL, &timeout);

        // Record the end time and calculate the round trip time
        gettimeofday(&end_time, NULL);
        double rtt = (double) ((end_time.tv_sec - start_time.tv_sec) * 1000000 + end_time.tv_usec - start_time.tv_usec) / 1000;
        rtt_sum += rtt;

        // Check if the response was received or lost
        if (result == -1) {
            error_exit("Error in select");
        } else if (result == 0) {
            // Timeout occurred
            packets_lost++;
        } else {
            // Response received
            if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
                error_exit("Error in getting ping response");
            }

            packets_received++;
        }

        // Increment the total packets sent
        *total_packets_sent++;
    }

    // Calculate the average round trip time and packet loss percentage
    *avg_rtt = rtt_sum / packets_received;
    *packet_loss = ((double) packets_lost / *total_packets_sent) * 100;
}

int main() {
    const char *hostname = "www.example.com";
    int port = 80;

    // Create a socket connection to the server
    struct sockaddr_in server_addr;
    int socket_fd = create_socket(hostname, port, &server_addr);

    // Connect to the server and calculate the QoS metrics
    int timeout_flag = 0;
    connect_server(socket_fd, server_addr, &timeout_flag);

    double avg_rtt;
    int packet_loss, total_packets_sent = 0;
    if (timeout_flag == 0) {
        calculate_metrics(&avg_rtt, &packet_loss, &total_packets_sent);
    } else {
        printf("Error: Connection timed out\n");
    }

    // Display the QoS metrics
    printf("Average Round Trip Time: %.2lf ms\n", avg_rtt);
    printf("Packet Loss Percentage: %d%%\n", packet_loss);

    // Close the socket connection
    close(socket_fd);

    return 0;
}