//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_IP_LEN 20
#define MAX_PORT_LEN 6
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [hostname] [port]\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    char *port = argv[2];
    char ip[MAX_IP_LEN];
    char buffer[MAX_BUFFER_SIZE];
    int sockfd, numbytes;
    struct hostent *he;
    struct sockaddr_in their_addr;

    // Get IP address by hostname
    if ((he = gethostbyname(hostname)) == NULL) {
        perror("gethostbyname");
        return 1;
    }

    inet_ntop(AF_INET, he->h_addr, ip, sizeof(ip));

    printf("Monitoring network quality of service for %s (%s) on port %s\n", hostname, ip, port);

    // Create socket for TCP connection
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return 1;
    }

    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(atoi(port));
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(their_addr.sin_zero), '\0', 8);

    // Connect to server using created socket
    if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        return 1;
    }

    printf("Connected to server on port %s\n", port);

    // Monitor QoS by measuring response time of dummy request
    while (1) {
        clock_t t_start, t_end;

        t_start = clock();

        // Send dummy request to server
        if (send(sockfd, "ping", 4, 0) == -1) {
            perror("send");
            return 1;
        }

        // Receive response from server
        if ((numbytes = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0)) == -1) {
            perror("recv");
            return 1;
        }

        buffer[numbytes] = '\0';

        t_end = clock();

        // Calculate response time in milliseconds
        double response_time = ((double)(t_end - t_start) / CLOCKS_PER_SEC) * 1000;

        printf("Response time: %.3f ms\n", response_time);

        // Sleep for 1 second before next measurement 
        sleep(1);
    }

    close(sockfd);

    return 0;
}