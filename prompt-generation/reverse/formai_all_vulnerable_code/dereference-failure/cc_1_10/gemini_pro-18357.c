//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

struct host_info {
    char *hostname;
    struct hostent *hostent;
    struct sockaddr_in sockaddr;
};

// Create a socket and connect to the specified host
int create_socket_and_connect(struct host_info *host_info) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&host_info->sockaddr, sizeof(host_info->sockaddr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Send a ping message to the specified host
void send_ping_message(int sockfd) {
    const char *ping_message = "PING";
    if (send(sockfd, ping_message, strlen(ping_message), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
}

// Receive a ping response from the specified host
char *receive_ping_response(int sockfd) {
    char *response = malloc(1024);
    if (recv(sockfd, response, 1024, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    return response;
}

// Close the specified socket
void close_socket(int sockfd) {
    if (close(sockfd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
}

// Get the hostname of the specified host
char *get_hostname(const char *hostname) {
    struct hostent *hostent = gethostbyname(hostname);
    if (hostent == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    return hostent->h_name;
}

// Get the IP address of the specified host
char *get_ip_address(const char *hostname) {
    struct hostent *hostent = gethostbyname(hostname);
    if (hostent == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    return inet_ntoa(*((struct in_addr *)hostent->h_addr_list[0]));
}

// Get the port number of the specified host
int get_port_number(const char *hostname) {
    struct servent *servent = getservbyname("ping", "tcp");
    if (servent == NULL) {
        perror("getservbyname");
        exit(EXIT_FAILURE);
    }

    return servent->s_port;
}

// Print the ping results
void print_ping_results(struct host_info *host_info, char *response, struct timespec start, struct timespec end) {
    printf("Ping results for %s (%s):\n", host_info->hostname, host_info->sockaddr.sin_addr.s_addr);
    printf("Response: %s\n", response);
    printf("Round-trip time: %.3f ms\n", (double)(end.tv_sec - start.tv_sec) * 1000 + (double)(end.tv_nsec - start.tv_nsec) / 1000000);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct host_info host_info;
    host_info.hostname = argv[1];
    host_info.hostent = gethostbyname(host_info.hostname);
    if (host_info.hostent == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }
    host_info.sockaddr.sin_family = AF_INET;
    host_info.sockaddr.sin_port = htons(get_port_number("ping"));
    host_info.sockaddr.sin_addr = *((struct in_addr *)host_info.hostent->h_addr_list[0]);

    int sockfd = create_socket_and_connect(&host_info);
    send_ping_message(sockfd);

    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    char *response = receive_ping_response(sockfd);
    clock_gettime(CLOCK_REALTIME, &end);

    print_ping_results(&host_info, response, start, end);
    close_socket(sockfd);

    return EXIT_SUCCESS;
}