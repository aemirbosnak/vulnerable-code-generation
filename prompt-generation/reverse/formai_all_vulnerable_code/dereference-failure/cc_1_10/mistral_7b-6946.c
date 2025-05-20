//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_ADDRESS "www.google.com"
#define BUFFER_SIZE 1024
#define TIMEOUT 5

typedef struct {
    double total_size;
    double start_time;
    double end_time;
} TestResult;

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    TestResult result;

    result.total_size = 0;
    result.start_time = 0;
    result.end_time = 0;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error_exit("Can't create a socket\n");
    }

    if ((server = gethostbyname(SERVER_ADDRESS)) == NULL) {
        fprintf(stderr, "Unknown host %s\n", SERVER_ADDRESS);
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error_exit("Couldn't connect to server\n");
    }

    result.start_time = time(NULL);

    // Send a request to the server and receive a response
    char request[BUFFER_SIZE] = "GET / HTTP/1.1\r\nHost: %s\r\nUser-Agent: SpeedTest/1.0\r\nAccept: */*\r\n\r\n";
    snprintf(request, BUFFER_SIZE, request, SERVER_ADDRESS);

    if (send(sockfd, request, strlen(request), 0) < 0) {
        error_exit("Failed to send request to server\n");
    }

    char response[BUFFER_SIZE];
    ssize_t n;
    while ((n = recv(sockfd, response, BUFFER_SIZE, 0)) > 0) {
        result.total_size += n;
    }

    result.end_time = time(NULL);

    close(sockfd);

    printf("Internet Speed Test Results:\n");
    printf("-----------------------------\n");
    printf("Total data transferred: %.2f bytes\n", result.total_size);
    printf("Transfer rate: %.2f bytes/sec\n", result.total_size / (result.end_time - result.start_time));

    return EXIT_SUCCESS;
}