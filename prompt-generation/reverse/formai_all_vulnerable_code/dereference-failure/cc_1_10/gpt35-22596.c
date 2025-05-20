//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define MAX_SOCKET_COUNT 65000

int main(int argc, char **argv) {
    int err, i, sock, count = 0;
    struct in_addr ip;
    struct sockaddr_in sa;
    char inet_addr_str[INET_ADDRSTRLEN];
    char hostname[NI_MAXHOST];
    fd_set fds;
    struct timeval timeout;
    int domain_list[] = { AF_INET, AF_INET6 };
    int domain_size = sizeof(domain_list) / sizeof(int);

    printf("Scanning for wireless networks...\n");

    for (i = 0; i < domain_size; i++) {
        memset(&sa, 0, sizeof(sa));
        sa.sin_family = domain_list[i];
        sa.sin_port = htons(0);

        if ((sock = socket(domain_list[i], SOCK_STREAM, 0)) < 0) {
            fprintf(stderr, "Failed to create socket. Error: %s\n", strerror(errno));
            continue;
        }

        if (bind(sock, (struct sockaddr *)&sa, sizeof(sa)) < 0) {
            fprintf(stderr, "Failed to bind socket. Error: %s\n", strerror(errno));
            close(sock);
            continue;
        }

        if (getsockname(sock, (struct sockaddr *)&sa, (socklen_t *)sizeof(sa)) < 0) {
            fprintf(stderr, "Failed to get socket name. Error: %s\n", strerror(errno));
            close(sock);
            continue;
        }

        if (inet_ntop(domain_list[i], &sa.sin_addr, inet_addr_str, sizeof(inet_addr_str)) == NULL) {
            fprintf(stderr, "Failed to convert IP address to string. Error: %s\n", strerror(errno));
            close(sock);
            continue;
        }

        if ((err = getnameinfo((struct sockaddr *)&sa, sizeof(sa), hostname, sizeof(hostname), NULL, 0, 0)) != 0) {
            fprintf(stderr, "Failed to get name information for socket. Error: %s\n", gai_strerror(err));
            close(sock);
            continue;
        }

        printf("Wireless network found! Domain: %d, IP Address: %s, Hostname: %s\n", domain_list[i], inet_addr_str, hostname);
        count++;
        close(sock);

        if (count >= MAX_SOCKET_COUNT) {
            printf("Maximum socket count reached! Exiting...\n");
            break;
        }

        // Sleep for 1 second between scans
        sleep(1);
    }

    printf("Scan complete. %d wireless networks found.\n", count);

    return 0;
}