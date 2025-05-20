//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buf[BUFSIZE];
    struct timeval start, end;
    double elapsed;
    double total_bytes = 0;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // Resolve the hostname
    struct hostent *he;
    if ((he = gethostbyname(argv[1])) == NULL) {
        herror("gethostbyname");
        exit(1);
    }

    // Initialize the sockaddr_in structure
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    servaddr.sin_addr = *((struct in_addr *)he->h_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send a request to the server
    if (write(sockfd, "GET / HTTP/1.1\nHost: www.example.com\n\n", strlen("GET / HTTP/1.1\nHost: www.example.com\n\n")) < 0) {
        perror("write");
        exit(1);
    }

    // Start the timer
    gettimeofday(&start, NULL);

    // Receive the response from the server
    while ((n = read(sockfd, buf, BUFSIZE)) > 0) {
        total_bytes += n;
    }

    // Stop the timer
    gettimeofday(&end, NULL);

    // Calculate the elapsed time
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    // Calculate the download speed
    double speed = total_bytes / elapsed;

    // Print the results
    printf("Download speed: %.2f KB/s\n", speed / 1024);

    // Close the socket
    close(sockfd);

    return 0;
}