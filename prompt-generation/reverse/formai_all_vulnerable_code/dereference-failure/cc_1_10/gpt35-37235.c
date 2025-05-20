//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

// Function declarations
void scan_network(char* ip_prefix, int start, int end, int port, char* interface);
bool is_port_open(char* ip, int port);
void print_usage_and_exit();

int main(int argc, char **argv) {
    // Check if enough arguments were passed
    if(argc < 5 || argc > 6) {
        print_usage_and_exit();
    }

    char* ip_prefix = argv[1];
    int start = atoi(argv[2]);
    int end = atoi(argv[3]);

    // Check if start and end are valid
    if(start < 0 || end > 255 || start > end) {
        printf("Invalid start and end values\n");
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[4]);

    // Check if port is valid
    if(port < 0 || port > 65535) {
        printf("Invalid port number\n");
        exit(EXIT_FAILURE);
    }

    char* interface = NULL;

    if(argc == 6) {
        interface = argv[5];
    }

    // Begin scanning network
    scan_network(ip_prefix, start, end, port, interface);

    return 0;
}

// Function to recursively scan network
void scan_network(char* ip_prefix, int start, int end, int port, char* interface) {
    struct hostent *host;
    struct sockaddr_in addr;
    char* ip = malloc(16 * sizeof(char));  // Allocate memory for ip string

    // Loop through all possible ip addresses
    for(int i=start; i<=end; i++) {
        sprintf(ip, "%s.%d", ip_prefix, i);  // Construct ip address string

        // Check if port is open on this ip address
        if(is_port_open(ip, port)) {
            // Print out ip address and port details
            printf("%s:%d is open\n", ip, port);
        }

        // Check if this ip has any further subnets to scan
        if(i < end) {
            // If interface is specified, use that for scanning subnets
            if(interface != NULL) {
                // Generate new ip prefix for subnet
                char* new_prefix = malloc((strlen(ip)+2) * sizeof(char));
                sprintf(new_prefix, "%s.%d", ip_prefix, i);

                // Construct command for scanning subnet
                char command[100];
                sprintf(command, "sudo arp-scan -I %s %s/%d-%d | grep -oE '([0-9]{1,3}[\\.]){3}[0-9]{1,3}'", interface, new_prefix, i+1, end);

                // Open process for running command
                FILE* fp = popen(command, "r");
                char line[25];

                // Read output of command line by line
                while(fgets(line, sizeof(line), fp)) {
                    strtok(line, "\n");  // Remove newline character
                    scan_network(line, 1, 255, port, NULL);  // Recursively scan subnet
                }

                pclose(fp);
                free(new_prefix);
            } else {
                // Recursively scan next subnet
                scan_network(ip_prefix, (i+1)*256, (i+1)*256+255, port, NULL);
            }
        }
    }

    free(ip);
}

// Function to check if a port is open on a specific ip address
bool is_port_open(char* ip, int port) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("ERROR openning socket");
        exit(EXIT_FAILURE);
    }

    // Get host information
    server = gethostbyname(ip);
    if(server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, '\0', sizeof(serv_addr));

    // Set socket details
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    // Try to connect to server
    if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        close(sockfd);
        return false;
    } else {
        close(sockfd);
        return true;
    }
}

// Function to print usage and exit
void print_usage_and_exit() {
    printf("Usage: wireless_scanner <ip_prefix> <start> <end> <port> [interface]\n");
    exit(EXIT_FAILURE);
}