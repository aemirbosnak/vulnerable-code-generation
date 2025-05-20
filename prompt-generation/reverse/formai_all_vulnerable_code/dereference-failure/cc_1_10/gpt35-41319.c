//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <unistd.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }
    char *hostname = argv[1];
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host %s\n", hostname);
        exit(1);
    }
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }
    struct sockaddr_in serv_addr;
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Error connecting");
    }
    const char *request = "GET /speedtest/random2500x2500.jpg HTTP/1.1\r\nHost: speedtest.net\r\n\r\n";
    if (write(sockfd, request, strlen(request)) < 0) {
        error("Error writing to socket");
    }
    char buffer[1024];
    int total_bytes = 0;
    clock_t start = clock();
    int n;
    while ((n = read(sockfd, buffer, 1024)) > 0) {
        total_bytes += n;
    }
    if (n < 0) {
        error("Error reading from socket");
    }
    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    double speed = (double)total_bytes / (1024 * 1024 * elapsed_time);
    printf("Download speed: %.2f Mbps\n", speed);
    close(sockfd);
    return 0;
}