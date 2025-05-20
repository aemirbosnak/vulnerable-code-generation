//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Structure to store the test result
typedef struct {
    double download_speed;
    double upload_speed;
} test_result;

// Function to get the hostname from a URL
char *get_hostname(char *url) {
    char *hostname = malloc(strlen(url) + 1);
    strcpy(hostname, url);
    char *p = strstr(hostname, "//");
    if (p != NULL) {
        p += 2;
    }
    p = strchr(p, '/');
    if (p != NULL) {
        *p = '\0';
    }
    return hostname;
}

// Function to perform a download speed test
double download_speed_test(char *hostname, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    struct hostent *he = gethostbyname(hostname);
    if (he == NULL) {
        perror("gethostbyname");
        return -1;
    }
    servaddr.sin_addr = *((struct in_addr *)he->h_addr);
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return -1;
    }
    char buf[BUFSIZ];
    int bytes_received = 0;
    struct timeval start, end;
    gettimeofday(&start, NULL);
    while (bytes_received < 1024 * 1024) {
        int n = recv(sockfd, buf, BUFSIZ, 0);
        if (n < 0) {
            perror("recv");
            return -1;
        }
        bytes_received += n;
    }
    gettimeofday(&end, NULL);
    double elapsed_seconds = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    close(sockfd);
    return bytes_received / elapsed_seconds;
}

// Function to perform an upload speed test
double upload_speed_test(char *hostname, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    struct hostent *he = gethostbyname(hostname);
    if (he == NULL) {
        perror("gethostbyname");
        return -1;
    }
    servaddr.sin_addr = *((struct in_addr *)he->h_addr);
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return -1;
    }
    char buf[BUFSIZ];
    int bytes_sent = 0;
    struct timeval start, end;
    gettimeofday(&start, NULL);
    while (bytes_sent < 1024 * 1024) {
        int n = send(sockfd, buf, BUFSIZ, 0);
        if (n < 0) {
            perror("send");
            return -1;
        }
        bytes_sent += n;
    }
    gettimeofday(&end, NULL);
    double elapsed_seconds = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    close(sockfd);
    return bytes_sent / elapsed_seconds;
}

// Function to print the test result
void print_result(test_result result) {
    printf("Download speed: %.2f Mbps\n", result.download_speed / 1024 / 1024);
    printf("Upload speed: %.2f Mbps\n", result.upload_speed / 1024 / 1024);
}

// Main function
int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }
    char *hostname = get_hostname(argv[1]);
    int port = atoi(argv[2]);
    test_result result;
    result.download_speed = download_speed_test(hostname, port);
    result.upload_speed = upload_speed_test(hostname, port);
    print_result(result);
    return 0;
}