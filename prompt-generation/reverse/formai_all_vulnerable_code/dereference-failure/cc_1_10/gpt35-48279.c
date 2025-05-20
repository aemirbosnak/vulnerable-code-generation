//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/time.h>
#include <netdb.h>
#include <signal.h>

#define MAX_BUFFER_SIZE 1024
#define DEFAULT_PORT 5000
#define DEFAULT_BACKLOG 5
#define DEFAULT_INTERVAL 5 // seconds

int sock_fd;
int run_flag;

void signal_handler(int signum);

int main(int argc, char **argv)
{
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addrlen = sizeof(client_addr);

    // initialize server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(DEFAULT_PORT);

    // create socket
    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd == -1)
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // set socket options
    int optval = 1;
    setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // bind socket
    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // register signal handler
    signal(SIGINT, signal_handler);
    run_flag = 1;

    // receive and send data in loop
    while (run_flag)
    {
        char buffer[MAX_BUFFER_SIZE];
        int recv_bytes = recvfrom(sock_fd, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &client_addrlen);

        if (recv_bytes == -1)
        {
            perror("Receive failed");
            continue;
        }

        // parse received data
        buffer[recv_bytes] = '\0';
        char *token = strtok(buffer, ",");
        char *packet_size_str = token;
        token = strtok(NULL, ",");
        char *delay_str = token;

        // calculate network delay
        struct timeval current_time;
        gettimeofday(&current_time, NULL);
        long long start_time = current_time.tv_sec * 1000000 + current_time.tv_usec;
        long long transmit_time = atoll(delay_str);
        long long end_time = start_time + (current_time.tv_usec - transmit_time) * 1000; // microseconds to nanoseconds
        long long delay_ns = end_time - start_time;

        // print QoS metrics
        printf("Packet size: %s bytes, Network delay: %lld nanoseconds\n", packet_size_str, delay_ns);

        // simulate packet loss
        if (rand() % 100 < 20)
        {
            printf("Packet loss detected, dropping packet\n");
            continue;
        }

        // send response
        char response[MAX_BUFFER_SIZE];
        snprintf(response, MAX_BUFFER_SIZE, "ACK,%lld", end_time);
        sendto(sock_fd, response, strlen(response), 0, (struct sockaddr *)&client_addr, client_addrlen);

        // wait for interval
        sleep(DEFAULT_INTERVAL);
    }

    // clean up
    close(sock_fd);

    return EXIT_SUCCESS;
}

void signal_handler(int signum)
{
    run_flag = 0;
}