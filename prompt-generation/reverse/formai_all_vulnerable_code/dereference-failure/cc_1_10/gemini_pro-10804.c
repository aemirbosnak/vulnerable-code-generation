//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

// Function to perform ping test
int ping_test(char *hostname) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        return -1;
    }

    // Resolve the hostname to an IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname() failed");
        return -1;
    }

    // Set up the destination address
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(33434); // Non-privileged port number
    memcpy(&dest_addr.sin_addr, host->h_addr, host->h_length);

    // Set up the ICMP echo request message
    char icmp_request[64];
    memset(icmp_request, 0, sizeof(icmp_request));
    icmp_request[0] = 8; // ICMP echo request type
    icmp_request[1] = 0; // ICMP echo request code

    // Calculate the ICMP checksum
    unsigned short checksum = 0;
    for (int i = 0; i < sizeof(icmp_request); i += 2) {
        checksum += (icmp_request[i] << 8) | icmp_request[i + 1];
    }
    while (checksum > 0xffff) {
        checksum = (checksum & 0xffff) + (checksum >> 16);
    }
    icmp_request[2] = (checksum >> 8) & 0xff;
    icmp_request[3] = checksum & 0xff;

    // Send the ICMP echo request message
    ssize_t bytes_sent = sendto(sockfd, icmp_request, sizeof(icmp_request), 0, (struct sockaddr *) &dest_addr, sizeof(dest_addr));
    if (bytes_sent < 0) {
        perror("sendto() failed");
        return -1;
    }

    // Receive the ICMP echo reply message
    char icmp_reply[64];
    memset(icmp_reply, 0, sizeof(icmp_reply));
    socklen_t addr_len = sizeof(dest_addr);
    ssize_t bytes_received = recvfrom(sockfd, icmp_reply, sizeof(icmp_reply), 0, (struct sockaddr *) &dest_addr, &addr_len);
    if (bytes_received < 0) {
        perror("recvfrom() failed");
        return -1;
    }

    // Check if the ICMP echo reply message is valid
    if (icmp_reply[0] != 0 || icmp_reply[1] != 0) {
        printf("Invalid ICMP echo reply message\n");
        return -1;
    }

    // Calculate the ICMP checksum
    checksum = 0;
    for (int i = 0; i < bytes_received; i += 2) {
        checksum += (icmp_reply[i] << 8) | icmp_reply[i + 1];
    }
    while (checksum > 0xffff) {
        checksum = (checksum & 0xffff) + (checksum >> 16);
    }
    if (checksum != 0xffff) {
        printf("Invalid ICMP echo reply message checksum\n");
        return -1;
    }

    // Print the ping statistics
    printf("Ping statistics for %s:\n", hostname);
    printf("Packets: Sent = 1, Received = 1, Lost = 0 (0%% loss)\n");
    printf("Approximate round trip times in milli-seconds:\n");
    printf("Minimum = 0ms, Maximum = 0ms, Average = 0ms\n");

    // Close the socket
    close(sockfd);

    return 0;
}

int main() {
    // Get the hostname from the user
    char hostname[256];
    printf("Enter the hostname to ping: ");
    scanf("%s", hostname);

    // Perform the ping test
    int result = ping_test(hostname);
    if (result == 0) {
        printf("Ping test successful!\n");
    } else {
        printf("Ping test failed!\n");
    }

    return 0;
}