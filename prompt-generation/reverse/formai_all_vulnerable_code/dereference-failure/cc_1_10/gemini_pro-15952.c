//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

// Constants for network scanning
#define DEFAULT_SCAN_RANGE "192.168.1.0/24"
#define SCAN_PORT 80
#define REQUEST_TIMEOUT 1000 // milliseconds

// Structure to store network scanning results
typedef struct scan_result {
    char *ip_address;
    int port;
    int status; // 0 for success, -1 for failure
    char *error_message;
} scan_result;

// Function to allocate and initialize a scan result structure
scan_result *scan_result_init(const char *ip_address, int port, int status, const char *error_message) {
    scan_result *result = malloc(sizeof(scan_result));
    if (!result) {
        return NULL;
    }

    result->ip_address = strdup(ip_address);
    result->port = port;
    result->status = status;
    result->error_message = NULL;

    if (error_message) {
        result->error_message = strdup(error_message);
    }

    return result;
}

// Function to free a scan result structure
void scan_result_free(scan_result *result) {
    if (!result) {
        return;
    }

    free(result->ip_address);
    free(result->error_message);
    free(result);
}

// Function to get all IPv4 addresses on the local machine
char **get_local_ipv4_addresses(void) {
    char **addresses = NULL;
    size_t address_count = 0;

    struct ifaddrs *ifaddr, *ifa;
    if (getifaddrs(&ifaddr) != 0) {
        perror("getifaddrs");
        return NULL;
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
            char *address = inet_ntoa(((struct sockaddr_in *)ifa->ifa_addr)->sin_addr);
            addresses = realloc(addresses, (address_count + 1) * sizeof(char *));
            addresses[address_count++] = strdup(address);
        }
    }

    freeifaddrs(ifaddr);

    addresses = realloc(addresses, (address_count + 1) * sizeof(char *));
    addresses[address_count] = NULL;

    return addresses;
}

// Function to scan a network for responsive hosts on a specific port
scan_result **scan_network(const char *network_range, int port) {
    scan_result **results = NULL;
    size_t result_count = 0;

    // Parse network range
    struct in_addr network_address;
    struct in_addr broadcast_address;
    if (inet_aton(network_range, &network_address) == 0) {
        perror("inet_aton");
        return NULL;
    }

    broadcast_address.s_addr = htonl(ntohl(network_address.s_addr) | ~ntohl(0xffffffff));

    // Get local IPv4 addresses
    char **local_addresses = get_local_ipv4_addresses();
    if (!local_addresses) {
        fprintf(stderr, "Error getting local IPv4 addresses\n");
        return NULL;
    }

    // Scan network
    for (unsigned long ip = ntohl(network_address.s_addr); ip <= ntohl(broadcast_address.s_addr); ip++) {
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = htonl(ip);
        addr.sin_port = htons(port);

        // Create a socket
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("socket");
            continue;
        }

        // Set socket timeout
        struct timeval timeout;
        timeout.tv_sec = REQUEST_TIMEOUT / 1000;
        timeout.tv_usec = (REQUEST_TIMEOUT % 1000) * 1000;
        if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
            perror("setsockopt");
            close(sockfd);
            continue;
        }

        // Connect to the remote host
        if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            // Host is responsive
            scan_result *result = scan_result_init(inet_ntoa(addr.sin_addr), port, 0, NULL);
            results = realloc(results, (result_count + 1) * sizeof(scan_result *));
            results[result_count++] = result;
        } else {
            // Host is not responsive
            char error_message[256];
            strerror_r(errno, error_message, sizeof(error_message));
            scan_result *result = scan_result_init(inet_ntoa(addr.sin_addr), port, -1, error_message);
            results = realloc(results, (result_count + 1) * sizeof(scan_result *));
            results[result_count++] = result;
        }

        // Close the socket
        close(sockfd);
    }

    // Free local IPv4 addresses
    for (size_t i = 0; local_addresses[i]; i++) {
        free(local_addresses[i]);
    }
    free(local_addresses);

    results = realloc(results, (result_count + 1) * sizeof(scan_result *));
    results[result_count] = NULL;

    return results;
}

// Function to print scan results
void print_scan_results(scan_result **results) {
    for (size_t i = 0; results[i]; i++) {
        printf("%s:%d ", results[i]->ip_address, results[i]->port);
        if (results[i]->status == 0) {
            printf("open\n");
        } else {
            printf("closed: %s\n", results[i]->error_message);
        }
    }
}

// Main function
int main(int argc, char **argv) {
    // Get network range from command-line arguments
    char *network_range = DEFAULT_SCAN_RANGE;
    if (argc > 1) {
        network_range = argv[1];
    }

    // Scan network
    scan_result **results = scan_network(network_range, SCAN_PORT);
    if (!results) {
        fprintf(stderr, "Error scanning network\n");
        return EXIT_FAILURE;
    }

    // Print scan results
    print_scan_results(results);

    // Free scan results
    for (size_t i = 0; results[i]; i++) {
        scan_result_free(results[i]);
    }
    free(results);

    return EXIT_SUCCESS;
}