//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <errno.h>

// Function to print the usage message
void printUsage() {
    printf("Usage: ./scanner [ip range]\n");
    printf("Example: ./scanner 192.168.0.1-192.168.0.10\n");
}

// Function to parse the IP range
// Returns 0 if successful and -1 otherwise
int parseIPRange(char* range, char* start_ip, char* end_ip) {
    char* token;
    char* ptr;
    int i;

    // Split the range into two IPs
    token = strtok(range, "-");
    i = 0;
    while (token != NULL) {
        if (i == 0) {
            ptr = start_ip;
        } else {
            ptr = end_ip;
        }
        if (inet_pton(AF_INET, token, ptr) != 1) {
            perror("Error: Invalid IP address");
            return -1;
        }
        token = strtok(NULL, "-");
        i++;
    }

    return 0;
}

// Function to scan a single IP
void scanIP(struct in_addr ip) {
    struct sockaddr_in address;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        return;
    }
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(80);
    address.sin_addr = ip;
    if (connect(sock, (struct sockaddr*)&address, sizeof(address)) == 0) {
        printf("%s\n", inet_ntoa(ip));
    }
    close(sock);
}

// Function to scan a range of IPs
void scanIPRange(struct in_addr start_ip, struct in_addr end_ip) {
    struct in_addr ip = start_ip;
    while (1) {
        scanIP(ip);
        if (memcmp(&ip, &end_ip, sizeof(ip)) == 0) {
            break;
        }
        ip.s_addr = ntohl(ntohl(ip.s_addr) + 1);
    }
}

int main(int argc, char* argv[]) {
    char* range;
    char start_ip[16];
    char end_ip[16];
    struct in_addr start_ip_addr;
    struct in_addr end_ip_addr;

    // Check if the correct number of arguments are provided
    if (argc != 2) {
        printUsage();
        return -1;
    }

    // Get the range of IPs
    range = argv[1];

    // Parse the range of IPs
    if (parseIPRange(range, start_ip, end_ip) == -1) {
        return -1;
    }

    // Convert the start and end IPs into in_addr structures
    if (inet_pton(AF_INET, start_ip, &start_ip_addr) != 1) {
        perror("Error: Invalid IP address");
        return -1;
    }
    if (inet_pton(AF_INET, end_ip, &end_ip_addr) != 1) {
        perror("Error: Invalid IP address");
        return -1;
    }

    // Scan the range of IPs
    scanIPRange(start_ip_addr, end_ip_addr);

    return 0;
}