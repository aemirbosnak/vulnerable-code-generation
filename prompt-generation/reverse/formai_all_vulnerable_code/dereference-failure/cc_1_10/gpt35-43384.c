//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <linux/if_link.h>
#include <time.h>

/* Function prototypes */
void get_local_addresses();
void print_banner();
void scan_network(char *network_address);

/* Global variables */
char *local_addresses[10];
int num_of_addresses = 0;

/* Main function */
int main() {
    get_local_addresses();
    print_banner();
    char network_address[16];
    printf("Enter network address to scan: ");
    fgets(network_address, 16, stdin);
    strtok(network_address, "\n"); // Remove newline character from input
    printf("Scanning network ...\n\n");
    scan_network(network_address);
    return 0;
}

/* Function to get local IP addresses */
void get_local_addresses() {
    struct ifaddrs *addrs;
    struct sockaddr_in *ip_addr;
    void *addr;
    char ip_address[INET_ADDRSTRLEN];
    getifaddrs(&addrs);
    while (addrs != NULL) {
        if (addrs->ifa_addr != NULL && addrs->ifa_addr->sa_family == AF_INET && strcmp(addrs->ifa_name, "lo") != 0) {
            ip_addr = (struct sockaddr_in *) addrs->ifa_addr;
            addr = &(ip_addr->sin_addr);
            inet_ntop(AF_INET, addr, ip_address, INET_ADDRSTRLEN);
            local_addresses[num_of_addresses] = (char *) malloc(sizeof(char) * INET_ADDRSTRLEN);
            strcpy(local_addresses[num_of_addresses], ip_address);
            num_of_addresses++;
        }
        addrs = addrs->ifa_next;
    }
    freeifaddrs(addrs);
}

/* Function to print the program banner */
void print_banner() {
    printf("\t\tWireless Network Scanner\n");
    printf("\t\t========================\n");
    printf("Local IP addresses:\n");
    for (int i = 0; i < num_of_addresses; i++) {
        printf("%s\n", local_addresses[i]);
    }
    printf("\n");
}

/* Function to scan the specified network address */
void scan_network(char *network_address) {
    int i, sockfd;
    struct hostent *host;
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    printf("Available hosts:\n");
    printf("=================\n");
    for (i = 1; i < 255; i++) {
        char ip[16];
        sprintf(ip, "%s.%d", network_address, i);
        if ((host = gethostbyname(ip)) != NULL) {
            char host_ip[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, host->h_addr, host_ip, INET_ADDRSTRLEN);
            if (strcmp(host_ip, network_address) != 0 && strstr(host_ip, network_address) != NULL) {
                printf("%s\n", host_ip);
            }
        }
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);
        sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        struct sockaddr_in sin;
        sin.sin_family = AF_INET;
        sin.sin_port = htons(1);
        inet_pton(AF_INET, ip, &(sin.sin_addr));
        connect(sockfd, (struct sockaddr *) &sin, sizeof sin);
    }
}