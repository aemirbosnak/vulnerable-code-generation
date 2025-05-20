//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netdb.h>

#define MAX_PORT 65535
#define MAX_IP_LENGTH 16

int main() {
    int socket_fd;
    struct ifreq interface;
    struct hostent *host;
    struct sockaddr_in address;
    char *ip_address;
    char *interface_name;
    int port;

    scanf("%s", interface_name);

    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("socket");
        exit(1);
    }

    // Get interface IP address
    strncpy(interface.ifr_ifrn.ifrn_name, interface_name, IFNAMSIZ-1);
    if (ioctl(socket_fd, SIOCGIFADDR, &interface) == -1) {
        perror("ioctl");
        exit(1);
    }
    ip_address = inet_ntoa(((struct sockaddr_in *)&interface.ifr_ifru.ifru_addr)->sin_addr);

    // Scan for open ports on local IP address
    printf("Scanning ports on %s...\n", ip_address);
    for (port = 1; port <= MAX_PORT; port++) {
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = inet_addr(ip_address);
        address.sin_port = htons(port);

        // Attempt to connect to port
        if (connect(socket_fd, (struct sockaddr *)&address, sizeof(address)) >= 0) {
            printf("Port %d is open\n", port);
        }
    }

    // Scan for open ports on external IP address
    host = gethostbyname("google.com");
    printf("Scanning ports on external IP address...\n");
    for (port = 1; port <= MAX_PORT; port++) {
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = *((unsigned long *)host->h_addr);
        address.sin_port = htons(port);

        // Attempt to connect to port
        if (connect(socket_fd, (struct sockaddr *)&address, sizeof(address)) >= 0) {
            printf("Port %d is open\n", port);
        }
    }

    // Close socket
    close(socket_fd);

    return 0;
}