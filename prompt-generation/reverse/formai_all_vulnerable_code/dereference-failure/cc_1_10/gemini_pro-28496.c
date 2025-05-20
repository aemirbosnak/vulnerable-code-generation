//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

// Function to resolve hostname to IP address
char * resolve_hostname(char * hostname) {
    struct hostent * host_entry;
    host_entry = gethostbyname(hostname);
    return inet_ntoa(*((struct in_addr *)host_entry->h_addr_list[0]));
}

// Function to perform ping operation
int ping_operation(char * host, int count, int timeout) {
    int sockfd, bytes_sent, bytes_received;
    struct sockaddr_in serv_addr;
    char * buf = "PING";
    char recv_buf[1024];
    struct timeval start, end;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Error creating socket");
        return -1;
    }

    // Set server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    serv_addr.sin_addr.s_addr = inet_addr(host);

    // Set timeout
    struct timeval tv;
    tv.tv_sec = timeout;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

    // Ping loop
    int sent = 0, received = 0, lost = 0;
    for (int i = 0; i < count; i++) {
        // Send ping request
        bytes_sent = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
        if (bytes_sent < 0) {
            perror("Error sending ping request");
            continue;
        }

        gettimeofday(&start, NULL);

        // Receive ping response
        bytes_received = recvfrom(sockfd, recv_buf, 1024, 0, NULL, NULL);
        gettimeofday(&end, NULL);

        if (bytes_received < 0) {
            lost++;
            continue;
        }

        // Calculate RTT
        long long elapsed_time = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
        printf("Reply from %s: bytes=%d time=%lld ms\n", host, bytes_received, elapsed_time);

        received++;
    }

    // Close socket
    close(sockfd);

    // Print ping statistics
    printf("\n----------------------------------------\n");
    printf("Ping statistics for %s\n", host);
    printf("Packets: Sent = %d, Received = %d, Lost = %d (%%%f)\n", sent, received, lost, (double) lost/sent * 100);
    printf("----------------------------------------\n");

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s hostname count [timeout]\n", argv[0]);
        return 1;
    }

    int count = atoi(argv[2]);
    int timeout = 1000; // Default timeout is 1 second
    if (argc >= 4) {
        timeout = atoi(argv[3]);
    }

    // Resolve hostname to IP address
    char * host = resolve_hostname(argv[1]);
    if (host == NULL) {
        printf("Error resolving hostname\n");
        return 1;
    }

    // Perform ping operation
    ping_operation(host, count, timeout);

    return 0;
}