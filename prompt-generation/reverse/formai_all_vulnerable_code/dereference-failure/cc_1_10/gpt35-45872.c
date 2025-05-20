//FormAI DATASET v1.0 Category: Network Ping Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>

#define PORT 80
#define PING_TIMEOUT 500000 //in microseconds

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Please enter a hostname or IP address to test.\n");
        exit(1);
    }

    struct hostent *host_entry;
    struct in_addr **addr_list;
    struct timeval start, end;
    int sockfd, count = 0;
    double total_time = 0;
    char ip_address[INET_ADDRSTRLEN];

    host_entry = gethostbyname(argv[1]);
    if (host_entry == NULL) {
        printf("Error: Invalid hostname or IP address.\n");
        exit(1);
    }

    printf("\nPING %s (%s):\n", host_entry->h_name,
           inet_ntop(AF_INET, host_entry->h_addr_list[0], ip_address, INET_ADDRSTRLEN));

    addr_list = (struct in_addr **) host_entry->h_addr_list;

    while (*addr_list != NULL) {
        sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (sockfd < 0) {
            perror("Error: Failed to create socket");
            exit(1);
        }

        struct sockaddr_in server_address;
        bzero(&server_address, sizeof(server_address));
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(PORT);
        server_address.sin_addr = **addr_list;

        printf("Pinging %s\n", inet_ntoa(server_address.sin_addr));

        ssize_t n;
        char buffer[32];
        bzero(buffer, sizeof(buffer));

        if (gettimeofday(&start, NULL) < 0) {
            perror("Error: Failed to get start time");
            exit(1);
        }

        if (sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *) &server_address,
                   sizeof(server_address)) < 0) {
            perror("Error: Failed to send data");
            exit(1);
        }

        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);

        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = PING_TIMEOUT;

        if (select(sockfd + 1, &readfds, NULL, NULL, &timeout) <= 0) {
            printf("Request timed out.\n");
        } else {
            if ((n = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL)) < 0) {
                perror("Error: Failed to receive data");
                exit(1);
            }

            if (gettimeofday(&end, NULL) < 0) {
                perror("Error: Failed to get end time");
                exit(1);
            }

            double time_elapsed = (end.tv_sec - start.tv_sec) * 1000.0;
            time_elapsed += (end.tv_usec - start.tv_usec) / 1000.0;

            printf("Response received in %.2fms.\n", time_elapsed);
            total_time += time_elapsed;
            count++;
        }

        addr_list++;
        close(sockfd);
        printf("\n");
    }

    printf("--- %s ping statistics ---\n", host_entry->h_name);
    printf("%d packets transmitted, %d packets received, %.2f%% packet loss\n", count,
           count - ((int) total_time / 1000), ((count - ((int) total_time / 1000)) / (double) count) * 100);
    printf("Total time: %.2fms\n", total_time);
    printf("Average response time: %.2fms\n", total_time / count);

    return 0;
}