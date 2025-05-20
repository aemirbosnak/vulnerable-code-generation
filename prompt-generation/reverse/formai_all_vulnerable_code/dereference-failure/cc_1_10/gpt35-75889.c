//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ifaddrs.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>

#define PORT 55555  // Port number for scanning

int main() {
    struct ifaddrs *ifap, *ifa;
    struct sockaddr_in *sa;
    char *addr;
    int sock;
    char buffer[1024];
    char target_ip[20];
    memset(target_ip, 0, sizeof(target_ip));

    // Get list of all available network interfaces
    if (getifaddrs(&ifap) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    // Iterate through the interfaces
    for (ifa = ifap; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr->sa_family == AF_INET) {
            // We found an IPv4 address
            sa = (struct sockaddr_in *) ifa->ifa_addr;
            addr = inet_ntoa(sa->sin_addr);

            // Copy the address to our target IP buffer
            strcpy(target_ip, addr);

            // Create a socket for scanning
            sock = socket(AF_INET, SOCK_STREAM, 0);
            if (sock == -1) {
                perror("socket");
                exit(EXIT_FAILURE);
            }

            // Set socket options for scanning
            struct timeval tv;
            tv.tv_sec = 1;
            tv.tv_usec = 0;
            if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
                perror("setsockopt");
            }

            // Connect to the target IP on the specified port
            struct sockaddr_in target;
            memset(&target, 0, sizeof(target));
            target.sin_family = AF_INET;
            target.sin_addr.s_addr = inet_addr(target_ip);
            target.sin_port = htons(PORT);
            if (connect(sock, (struct sockaddr *) &target, sizeof(target)) == -1) {
                // Connection failed, port is closed
            } else {
                // Connection successful, port is open!
                printf("%s:%d - OPEN\n", target_ip, PORT);
            }

            // Close the socket for this interface
            close(sock);
        }
    }

    // Free memory used by the interface list
    freeifaddrs(ifap);

    return 0;
}