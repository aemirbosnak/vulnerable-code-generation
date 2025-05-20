//FormAI DATASET v1.0 Category: Port Scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Check if the user has entered a host name or IP address
    if (argc < 2) {
        printf("Please enter the IP address or hostname to scan.\n");
        exit(1);
    }

    // Set up the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket() error");
        exit(1);
    }

    char *hostname = argv[1];
    struct hostent *host = gethostbyname(hostname);

    if (host == NULL) {
        printf("Cannot resolve the hostname %s\n", hostname);
        exit(1);
    }

    // Set up the destination address and port range
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr = *((struct in_addr *)host->h_addr);
    int ports[] = {22, 80, 443, 8080};
    int num_ports = sizeof(ports) / sizeof(int);

    // Scan each port
    printf("Scanning %s (%s):\n", hostname, inet_ntoa(addr.sin_addr));
    for (int i = 0; i < num_ports; i++) {
        addr.sin_port = htons(ports[i]);
        int result = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
        if (result == 0) {
            printf("Port %d: OPEN\n", ports[i]);
        } else {
            printf("Port %d: CLOSED\n", ports[i]);
        }
    }

    // Close the socket
    close(sockfd);
    return 0;
}