//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Constants for QoS thresholds
#define GOOD_QOS 80
#define MODERATE_QOS 60
#define POOR_QOS 40

volatile int running = 1;   // Flag to indicate whether to continue program execution

// Function to handle interrupts and gracefully exit program
void sigint_handler(int signal)
{
    running = 0;
}

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("Usage: %s <host> <port>\n", argv[0]);
        printf("Example: %s www.google.com 80\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in address;
    struct hostent *host;
    int sock, result, count, threshold, total_time;

    signal(SIGINT, sigint_handler);

    while(running)
    {
        // Get host IP address
        host = gethostbyname(hostname);
        if(host == NULL)
        {
            printf("Error: Could not resolve host %s\n", hostname);
            return 1;
        }

        // Create socket and set socket options
        sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if(sock == -1)
        {
            printf("Error: Could not create socket\n");
            return 1;
        }

        address.sin_family = AF_INET;
        address.sin_port = htons(port);
        memcpy(&address.sin_addr.s_addr, host->h_addr, host->h_length);

        // Connect to the host
        result = connect(sock, (struct sockaddr *)&address, sizeof(address));
        if(result == -1)
        {
            printf("Error: Could not connect to host %s:%d\n", hostname, port);
            close(sock);
            return 1;
        }

        // Measure connection speed by sending multiple requests and calculating average response time
        total_time = 0;
        for(count = 0; count < 10; count++)
        {
            // Send request
            char *request = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";
            result = send(sock, request, strlen(request), 0);
            if(result == -1)
            {
                printf("Error: Could not send request\n");
                close(sock);
                return 1;
            }

            // Receive response
            char buffer[1024];
            struct timeval start, end;
            gettimeofday(&start, NULL);
            result = recv(sock, buffer, sizeof(buffer), 0);
            gettimeofday(&end, NULL);
            if(result == -1)
            {
                printf("Error: Could not receive response\n");
                close(sock);
                return 1;
            }
            total_time += ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);
        }

        // Calculate average response time and display QoS
        int average_time = total_time / 10;
        if(average_time >= GOOD_QOS)
        {
            printf("Network QoS is good (average response time: %d microseconds)\n", average_time);
            threshold = GOOD_QOS;
        }
        else if(average_time >= MODERATE_QOS)
        {
            printf("Network QoS is moderate (average response time: %d microseconds)\n", average_time);
            threshold = MODERATE_QOS;
        }
        else
        {
            printf("Network QoS is poor (average response time: %d microseconds)\n", average_time);
            threshold = POOR_QOS;
        }

        // Wait for some time before sending another request
        sleep(5);

        // Check whether QoS has degraded and alert user if necessary
        total_time = 0;
        for(count = 0; count < 10; count++)
        {
            // Send request
            char *request = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";
            result = send(sock, request, strlen(request), 0);
            if(result == -1)
            {
                printf("Error: Could not send request\n");
                close(sock);
                return 1;
            }

            // Receive response
            char buffer[1024];
            struct timeval start, end;
            gettimeofday(&start, NULL);
            result = recv(sock, buffer, sizeof(buffer), 0);
            gettimeofday(&end, NULL);
            if(result == -1)
            {
                printf("Error: Could not receive response\n");
                close(sock);
                return 1;
            }
            total_time += ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);
        }

        // Calculate average response time and alert user if QoS has degraded
        average_time = total_time / 10;
        if(average_time < threshold)
        {
            printf("Network QoS has degraded (average response time: %d microseconds)\n", average_time);
        }

        // Close socket
        close(sock);
    }

    return 0;
}