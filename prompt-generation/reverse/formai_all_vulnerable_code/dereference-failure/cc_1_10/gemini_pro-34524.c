//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

#define MAX_PAYLOAD_SIZE 1024
#define DEFAULT_PORT 80
#define DEFAULT_TIMEOUT 1000 // milliseconds

typedef struct {
    struct sockaddr_in addr;
    socklen_t addr_len;
    int sockfd;
    char payload[MAX_PAYLOAD_SIZE];
    size_t payload_len;
    struct timeval start_time;
    struct timeval end_time;
    double rtt;
    int success;
} PingRequest;

int create_socket(const char *hostname, int port) {
    struct addrinfo hints, *result;
    int sockfd;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = IPPROTO_UDP;

    if (getaddrinfo(hostname, NULL, &hints, &result) != 0) {
        perror("getaddrinfo");
        return -1;
    }

    sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        freeaddrinfo(result);
        return -1;
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) != 0) {
        perror("connect");
        close(sockfd);
        freeaddrinfo(result);
        return -1;
    }

    freeaddrinfo(result);
    return sockfd;
}

int send_ping_request(PingRequest *request) {
    ssize_t sent_bytes;

    gettimeofday(&request->start_time, NULL);
    sent_bytes = send(request->sockfd, request->payload, request->payload_len, 0);
    if (sent_bytes == -1) {
        perror("send");
        return -1;
    }

    return 0;
}

int receive_ping_response(PingRequest *request) {
    ssize_t recv_bytes;
    struct sockaddr_in from_addr;
    socklen_t from_addr_len = sizeof(from_addr);

    gettimeofday(&request->end_time, NULL);
    recv_bytes = recvfrom(request->sockfd, request->payload, request->payload_len, 0, (struct sockaddr *) &from_addr, &from_addr_len);
    if (recv_bytes == -1) {
        perror("recvfrom");
        return -1;
    }

    return 0;
}

double calculate_rtt(PingRequest *request) {
    return (request->end_time.tv_sec - request->start_time.tv_sec) * 1000.0 + (request->end_time.tv_usec - request->start_time.tv_usec) / 1000.0;
}

int main(int argc, char **argv) {
    char *hostname;
    int port;
    int timeout;
    int num_pings;
    int i;
    int sockfd;
    PingRequest request;

    if (argc < 2) {
        printf("Usage: %s <hostname> [<port> [<timeout> [<num_pings>]]]\n", argv[0]);
        return 1;
    }

    hostname = argv[1];
    port = DEFAULT_PORT;
    timeout = DEFAULT_TIMEOUT;
    num_pings = 1;

    if (argc >= 3) {
        port = atoi(argv[2]);
    }

    if (argc >= 4) {
        timeout = atoi(argv[3]);
    }

    if (argc >= 5) {
        num_pings = atoi(argv[4]);
    }

    sockfd = create_socket(hostname, port);
    if (sockfd == -1) {
        return 1;
    }

    memset(&request, 0, sizeof(request));
    request.sockfd = sockfd;
    request.addr_len = sizeof(request.addr);
    request.payload_len = MAX_PAYLOAD_SIZE;

    for (i = 0; i < num_pings; i++) {
        if (send_ping_request(&request) == -1) {
            break;
        }

        if (receive_ping_response(&request) == -1) {
            break;
        }

        request.rtt = calculate_rtt(&request);
        request.success = 1;

        printf("Ping %d: %lf ms\n", i + 1, request.rtt);
    }

    close(sockfd);
    return 0;
}