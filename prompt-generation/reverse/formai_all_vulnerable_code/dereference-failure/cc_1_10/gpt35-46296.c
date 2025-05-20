//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 80 // Port to connect to

int main(int argc, char *argv[]) {
    struct ifaddrs *ifap, *ifa;
    struct sockaddr_in *ipaddr;
    char ip[INET_ADDRSTRLEN];
    int sockfd, ret;
    struct hostent *host;
    struct sockaddr_in servaddr;
    char buf[1024];
    char *scan_range;
    int start, end, i, j;

    // Get network interface addresses
    if (getifaddrs(&ifap) != 0) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    // Print network interface addresses
    for (ifa = ifap; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr->sa_family == AF_INET) { // IPv4 only
            ipaddr = (struct sockaddr_in *)ifa->ifa_addr;
            inet_ntop(AF_INET, &(ipaddr->sin_addr), ip, INET_ADDRSTRLEN);
            printf("%s: %s\n", ifa->ifa_name, ip);
        }
    }
    freeifaddrs(ifap);

    // Get scan range from user
    printf("Enter scan range (e.g. 192.168.0.1-255): ");
    scanf("%ms", &scan_range);

    // Parse scan range
    char *token = strtok(scan_range, "-");
    start = atoi(token);
    token = strtok(NULL, "-");
    end = atoi(token);

    // Connect to each IP address in scan range
    for (i = start; i <= end; i++) {
        for (j = 1; j <= 255; j++) {
            sprintf(ip, "%d.%d.%d.%d", i, j, j, j); // Construct IP address string
            printf("Scanning %s...", ip);

            // Create socket
            sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (sockfd == -1) {
                perror("socket");
                exit(EXIT_FAILURE);
            }

            // Get host by name (DNS lookup)
            host = gethostbyname(ip);
            if (host == NULL) {
                perror("gethostbyname");
                close(sockfd);
                continue;
            }

            // Set server address
            memset(&servaddr, 0, sizeof(struct sockaddr_in));
            servaddr.sin_family = AF_INET;
            servaddr.sin_port = htons(PORT);
            memcpy(&servaddr.sin_addr, host->h_addr_list[0], sizeof(struct in_addr));

            // Connect to server
            ret = connect(sockfd, (const struct sockaddr *)&servaddr, sizeof(struct sockaddr_in));
            if (ret == 0) {
                printf("port %d open\n", PORT);
            } else {
                printf("port %d closed\n", PORT);
            }

            close(sockfd);
        }
    }

    return 0;
}