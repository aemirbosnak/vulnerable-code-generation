//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

// Colors for output
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define RESET "\x1B[0m"

// Helper function to resolve a hostname to an IP address
char *resolve_hostname(char *hostname) {
    struct hostent *host;
    host = gethostbyname(hostname);
    if (host == NULL) {
        return NULL;
    }
    return inet_ntoa(*((struct in_addr *) host->h_addr));
}

// Helper function to create a socket
int create_socket() {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return -1;
    }
    return sockfd;
}

// Helper function to send a ping request
int send_ping_request(int sockfd, char *ip) {
    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(80);
    dest_addr.sin_addr.s_addr = inet_addr(ip);

    char request[] = "PING";
    int bytes_sent = sendto(sockfd, request, sizeof(request), 0, (struct sockaddr *) &dest_addr, sizeof(dest_addr));
    if (bytes_sent < 0) {
        perror("Error sending ping request");
        return -1;
    }
    return bytes_sent;
}

// Helper function to receive a ping response
int receive_ping_response(int sockfd, char *ip) {
    struct sockaddr_in source_addr;
    socklen_t source_addr_len = sizeof(source_addr);

    char response[1024];
    int bytes_received = recvfrom(sockfd, response, sizeof(response), 0, (struct sockaddr *) &source_addr, &source_addr_len);
    if (bytes_received < 0) {
        perror("Error receiving ping response");
        return -1;
    }

    if (strcmp(ip, inet_ntoa(source_addr.sin_addr)) != 0) {
        printf(RED "Warning: Ping response received from unexpected IP address: %s\n" RESET, inet_ntoa(source_addr.sin_addr));
        return -1;
    }

    return bytes_received;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hostname or IP address>\n", argv[0]);
        return 1;
    }

    char *ip = resolve_hostname(argv[1]);
    if (ip == NULL) {
        printf(RED "Error resolving hostname: %s\n" RESET, argv[1]);
        return 1;
    }

    printf("Pinging %s (%s)...\n", argv[1], ip);

    int sockfd = create_socket();
    if (sockfd < 0) {
        return 1;
    }

    int bytes_sent = send_ping_request(sockfd, ip);
    if (bytes_sent < 0) {
        close(sockfd);
        return 1;
    }

    printf(YELLOW "Sent %d bytes of data\n" RESET, bytes_sent);

    int bytes_received = receive_ping_response(sockfd, ip);
    if (bytes_received < 0) {
        close(sockfd);
        return 1;
    }

    printf(GREEN "Received %d bytes of data\n" RESET, bytes_received);

    close(sockfd);

    printf(GREEN "Ping successful!\n" RESET);

    return 0;
}