//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <unistd.h>

int main()
{
    // Get the local IP address.
    struct ifaddrs *ifaddr;
    getifaddrs(&ifaddr);
    struct ifaddrs *ifa = ifaddr;
    char *ip_address = NULL;
    while (ifa) {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
            struct sockaddr_in *addr = (struct sockaddr_in *)ifa->ifa_addr;
            ip_address = inet_ntoa(addr->sin_addr);
            break;
        }
        ifa = ifa->ifa_next;
    }
    freeifaddrs(ifaddr);

    // Create a UDP socket.
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the broadcast option on the socket.
    int broadcast = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Send a broadcast message.
    struct sockaddr_in broadcast_addr;
    broadcast_addr.sin_family = AF_INET;
    broadcast_addr.sin_port = htons(4242);
    broadcast_addr.sin_addr.s_addr = INADDR_BROADCAST;
    char *broadcast_message = "Scanning for wireless networks";
    if (sendto(sockfd, broadcast_message, strlen(broadcast_message), 0, (struct sockaddr *)&broadcast_addr, sizeof(broadcast_addr)) == -1) {
        perror("sendto");
        exit(EXIT_FAILURE);
    }

    // Receive responses from wireless networks.
    struct sockaddr_in recv_addr;
    socklen_t recv_addr_len = sizeof(recv_addr);
    char recv_buffer[1024];
    while (1) {
        int recv_len = recvfrom(sockfd, recv_buffer, sizeof(recv_buffer), 0, (struct sockaddr *)&recv_addr, &recv_addr_len);
        if (recv_len == -1) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }

        // Process the response.
        printf("Received response from %s: %s\n", inet_ntoa(recv_addr.sin_addr), recv_buffer);
    }

    // Close the socket.
    close(sockfd);

    return 0;
}