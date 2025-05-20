//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_LENGTH 16
#define MAX_MASK_LENGTH 3

// Function to convert IP address string to integer
unsigned long ipToLong(const char *ip) {
    struct sockaddr_in sa;
    inet_pton(AF_INET, ip, &(sa.sin_addr));
    return ntohl(sa.sin_addr.s_addr);
}

// Function to convert integer to IP address string
void longToIp(unsigned long ipLong, char *ip) {
    struct in_addr addr;
    addr.s_addr = htonl(ipLong);
    strcpy(ip, inet_ntoa(addr));
}

// Function to compute network address
unsigned long computeNetworkAddress(unsigned long ip, unsigned long mask) {
    return ip & mask;
}

// Function to compute broadcast address
unsigned long computeBroadcastAddress(unsigned long network, unsigned long mask) {
    return network | ~mask;
}

// Function to compute the range of assignable IPs
void computeAssignableIPs(unsigned long network, unsigned long broadcast, char *startIP, char *endIP) {
    // Start IP is network + 1
    unsigned long start = network + 1;
    // End IP is broadcast - 1
    unsigned long end = broadcast - 1;

    longToIp(start, startIP);
    longToIp(end, endIP);
}

// Main program entry
int main() {
    char ipStr[MAX_IP_LENGTH];
    char maskStr[MAX_MASK_LENGTH];
    unsigned long ip, mask, network, broadcast;
    char startIP[MAX_IP_LENGTH], endIP[MAX_IP_LENGTH];

    printf("Subnet Calculator\n");

    // Get user input for IP address
    printf("Enter an IP address (e.g., 192.168.1.10): ");
    scanf("%15s", ipStr);
    
    // Get user input for subnet mask
    printf("Enter a subnet mask (e.g., 255.255.255.0): ");
    scanf("%2s", maskStr);
    
    // Convert inputs into long integers
    ip = ipToLong(ipStr);
    mask = ipToLong(maskStr);

    // Calculate network and broadcast addresses
    network = computeNetworkAddress(ip, mask);
    broadcast = computeBroadcastAddress(network, mask);

    // Calculate range of assignable IPs
    computeAssignableIPs(network, broadcast, startIP, endIP);

    // Display results
    printf("\nResults:\n");
    printf("-------------------------\n");
    printf("IP Address: %s\n", ipStr);
    printf("Subnet Mask: %s\n", maskStr);
    longToIp(network, ipStr);
    printf("Network Address: %s\n", ipStr);
    longToIp(broadcast, ipStr);
    printf("Broadcast Address: %s\n", ipStr);
    printf("First Assignable IP: %s\n", startIP);
    printf("Last Assignable IP: %s\n", endIP);
    printf("-------------------------\n");

    return 0;
}