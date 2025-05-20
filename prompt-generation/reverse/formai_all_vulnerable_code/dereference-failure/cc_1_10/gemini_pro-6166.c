//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Print out the error message and exit the program
void error(char *msg) {
    perror(msg);
    exit(1);
}

// Get the IP address of a domain name
struct in_addr *get_ip_address(char *domain_name) {
    struct hostent *host;
    struct in_addr *ip_address;

    // Get the host information
    host = gethostbyname(domain_name);
    if (host == NULL) {
        error("gethostbyname");
    }

    // Get the IP address
    ip_address = (struct in_addr *) host->h_addr_list[0];
    return ip_address;
}

// Create a socket and connect to the IP address
int create_socket(struct in_addr *ip_address) {
    int sockfd;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("socket");
    }

    // Connect to the IP address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = ip_address->s_addr;

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        error("connect");
    }

    return sockfd;
}

// Send a ping request to the IP address
void ping(int sockfd) {
    char *request = "GET / HTTP/1.1\r\nHost: www.example.com\r\nConnection: close\r\n\r\n";

    // Send the ping request
    if (send(sockfd, request, strlen(request), 0) == -1) {
        error("send");
    }

    // Receive the ping response
    char response[1024];
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        error("recv");
    }

    // Print out the ping response
    printf("%s", response);

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <domain name>\n", argv[0]);
        exit(1);
    }

    // Get the IP address of the domain name
    struct in_addr *ip_address = get_ip_address(argv[1]);

    // Create a socket and connect to the IP address
    int sockfd = create_socket(ip_address);

    // Send a ping request to the IP address
    ping(sockfd);

    return 0;
}