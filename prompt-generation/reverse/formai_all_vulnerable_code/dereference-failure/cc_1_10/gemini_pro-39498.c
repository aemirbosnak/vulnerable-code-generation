//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define PING_PACKET_SIZE 64

// ICMP request header
struct icmp_request {
    uint8_t type;              // always 8
    uint8_t code;              // type-specific code (0 for echo request)
    uint16_t checksum;          // checksum of header and data
    uint16_t id;                // id of sending process
    uint16_t sequence;           // sequence number
    uint64_t data;             // timestamp (in microseconds)
};

// Send an ICMP echo request
int send_icmp_request(int sockfd, struct sockaddr_in *addr, int ttl) {
    // Create an ICMP request packet
    struct icmp_request request;
    memset(&request, 0, sizeof(request));
    request.type = 8;
    request.code = 0;
    request.id = getpid();
    request.sequence = 0;
    request.data = time(NULL);

    // Set the TTL
    int optval = ttl;
    setsockopt(sockfd, IPPROTO_IP, IP_TTL, &optval, sizeof(optval));

    // Send the request
    int sent = sendto(sockfd, &request, sizeof(request), 0, (struct sockaddr *) addr, sizeof(*addr));
    if (sent < 0) {
        perror("sendto");
        return -1;
    }

    return sent;
}

// Receive an ICMP echo reply
int recv_icmp_reply(int sockfd, struct icmp_request *request, struct sockaddr_in *addr) {
    // Receive the reply
    int addr_len = sizeof(*addr);
    int received = recvfrom(sockfd, request, sizeof(*request), 0, (struct sockaddr *) addr, &addr_len);
    if (received < 0) {
        perror("recvfrom");
        return -1;
    }

    // Check the checksum
    uint16_t checksum = 0;
    for (int i = 0; i < sizeof(*request); i++) {
        checksum += ((uint8_t *) request)[i];
    }
    if (checksum != 0xffff) {
        printf("Invalid checksum\n");
        return -1;
    }

    return received;
}

// Print the results
void print_results(struct icmp_request *request, struct sockaddr_in *addr, double rtt) {
    // Convert the timestamp to a human-readable format
    time_t timestamp = (time_t) request->data;
    char *timestamp_str = ctime(&timestamp);

    // Print the results
    printf("Packet sent to: %s\n", inet_ntoa(addr->sin_addr));
    printf("ICMP echo reply received\n");
    printf("Round trip time: %.2f ms\n", rtt * 1000);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <host> <ttl>\n", argv[0]);
        return -1;
    }

    // Get the host and TTL
    char *host = argv[1];
    int ttl = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Resolve the host
    struct hostent *hostent = gethostbyname(host);
    if (hostent == NULL) {
        printf("Could not resolve host: %s\n", host);
        return -1;
    }

    // Set up the sockaddr_in for the destination address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr = *((struct in_addr *) hostent->h_addr_list[0]);

    // Send an ICMP echo request
    int sent = send_icmp_request(sockfd, &addr, ttl);
    if (sent < 0) {
        return -1;
    }

    // Receive an ICMP echo reply
    struct icmp_request request;
    int received = recv_icmp_reply(sockfd, &request, &addr);
    if (received < 0) {
        return -1;
    }

    // Calculate the round trip time
    double rtt = (time(NULL) - request.data) / 1000000.0;

    // Print the results
    print_results(&request, &addr, rtt);

    // Close the socket
    close(sockfd);

    return 0;
}