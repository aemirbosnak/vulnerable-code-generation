//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: futuristic
// Neon Network Analyzer v2048
// Codecrafted by A.I. CyberTech

#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>

int main() {
    // Initialize variables
    int sockfd, bytes, ping_time;
    char hostname[256], ip[256], buffer[1024];
    struct utsname system_info;
    struct sockaddr_in serv_addr;
    struct timeval start, end;

    // Get system information
    uname(&system_info);

    // Get hostname
    gethostname(hostname, sizeof(hostname));

    // Resolve hostname to IP address
    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }
    inet_ntop(host->h_addrtype, host->h_addr, ip, sizeof(ip));

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    serv_addr.sin_addr.s_addr = inet_addr("1.1.1.1");

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send GET request
    snprintf(buffer, sizeof(buffer), "GET / HTTP/1.1\r\nHost: 1.1.1.1\r\n\r\n");
    bytes = send(sockfd, buffer, strlen(buffer), 0);
    if (bytes < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Get start time
    gettimeofday(&start, NULL);

    // Receive response
    bytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Get end time
    gettimeofday(&end, NULL);

    // Calculate ping time
    ping_time = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;

    // Close socket
    close(sockfd);

    // Print results
    printf("Neon Network Analyzer v2048\n");
    printf("----------------------------\n");
    printf("System: %s\n", system_info.sysname);
    printf("Hostname: %s\n", hostname);
    printf("IP Address: %s\n", ip);
    printf("Ping Time: %d ms\n", ping_time);

    return EXIT_SUCCESS;
}