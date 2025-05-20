//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// QoS monitor function
void qos_monitor(int socket_fd, const char *hostname)
{
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(hostname);
    server_addr.sin_port = htons(80);

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Build QoS packet
    char request[] = "GET / HTTP/1.1\r\nHost: ";
    strcat(request, hostname);
    strcat(request, "\r\nConnection: close\r\n\r\n");

    // Send QoS packet to server
    if (send(socket_fd, request, strlen(request), 0) == -1) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // Receive response from server
    char buffer[BUFFER_SIZE];
    int total_bytes_received = 0;
    while (true) {
        int bytes_received = recv(socket_fd, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received == -1) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }
        if (bytes_received == 0) {
            break;
        }
        total_bytes_received += bytes_received;
        buffer[bytes_received] = '\0';
    }

    // Calculate QoS metrics from server response
    int response_time = 0;
    int bytes_per_second = 0;
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    char *response = strstr(buffer, "HTTP/1.");
    if (response != NULL) {
        response += 9;
        int status_code = atoi(response);
        if (status_code >= 200 && status_code < 300) {
            gettimeofday(&end_time, NULL);
            response_time = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);
            bytes_per_second = total_bytes_received / (response_time / 1000000);
            printf("QoS metrics: Response Time = %dms, Bytes per Second = %d\n", response_time / 1000, bytes_per_second);
        } else {
            printf("QoS metrics: Status Code = %d\n", status_code);
        }
    } else {
        printf("QoS metrics: No HTTP response found\n");
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket failed");
        return EXIT_FAILURE;
    }

    qos_monitor(socket_fd, argv[1]);

    close(socket_fd);

    return EXIT_SUCCESS;
}