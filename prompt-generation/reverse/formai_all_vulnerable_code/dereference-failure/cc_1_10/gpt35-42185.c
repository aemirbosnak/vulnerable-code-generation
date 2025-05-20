//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: high level of detail
/*
 * Network Topology Mapper Example Program
 * Written by [Your Name]
 * Date: [Current Date]
 * Description: This program is designed to map the network topology of a given IP range and output the results to a file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define MAX_IP_LEN 16
#define MAX_PORT_NUM 65535

void map_network_topology(char *subnet);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <subnet>\n", argv[0]);
        return 1;
    }

    map_network_topology(argv[1]);

    return 0;
}

void map_network_topology(char *subnet) {
    struct in_addr addr;
    char ip[MAX_IP_LEN];
    int sockfd, port, result;
    struct sockaddr_in dest;

    // Open output file
    FILE *output_file = fopen("network_topology.txt", "w");
    if(output_file == NULL) {
        printf("Error: Could not open file\n");
        return;
    }

    // Open socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        printf("Error: %s\n", strerror(errno));
        fclose(output_file);
        return;
    }

    // Loop through IP range
    int i;
    for(i = 1; i <= 255; i++) {
        // Construct IP address
        sprintf(ip, "%s.%d", subnet, i);

        // Convert IP address to binary form
        result = inet_pton(AF_INET, ip, &(dest.sin_addr));
        if(result == -1) {
            printf("Error: %s\n", strerror(errno));
            fclose(output_file);
            close(sockfd);
            return;
        }
        // Loop through ports
        for(port = 1; port <= MAX_PORT_NUM; port++) {
            // Set destination port
            dest.sin_port = htons(port);

            // Attempt connection
            result = connect(sockfd, (struct sockaddr *)&dest, sizeof(dest));
            if(result == 0) {
                // Print connection information to file
                inet_pton(AF_INET, ip, &addr);
                fprintf(output_file, "Connected to %s:%d\n", inet_ntoa(addr), port);
            }
        }
    }

    // Close socket and file
    fclose(output_file);
    close(sockfd);
}