//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: intelligent
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <linux/if_link.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {

    char buf[MAX_BUF_SIZE];
    char *destination_ip;
    int timeout;
    int start_port, end_port;
    struct sockaddr_in dest;

    if (argc != 5) {
        printf("Invalid number of arguments provided.\n");
        printf("Usage: ./wireless_scanner <destination_ip> <timeout> <start_port> <end_port>\n");
        return 1;
    }

    destination_ip = argv[1];

    if (inet_pton(AF_INET, destination_ip, &dest.sin_addr) != 1) {
        printf("Invalid destination IP provided.\n");
        return 1;
    }

    timeout = atoi(argv[2]);
    start_port = atoi(argv[3]);
    end_port = atoi(argv[4]);

    if (start_port > end_port || start_port < 0 || end_port > 65535) {
        printf("Invalid port range provided.\n");
        return 1;
    }

    printf("Scanning ports %d to %d on %s...\n", start_port, end_port, destination_ip);

    for (int port = start_port; port <= end_port; port++) {

        struct timeval tv;
        tv.tv_sec = timeout / 1000;
        tv.tv_usec = (timeout % 1000) * 1000;

        int sock = socket(AF_INET, SOCK_STREAM, 0);

        if (sock < 0) {
            perror("Error creating socket");
            return 1;
        }

        setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

        dest.sin_family = AF_INET;
        dest.sin_port = htons(port);

        if (connect(sock, (const struct sockaddr *) &dest, sizeof(dest)) != -1) {

            struct servent *service = getservbyport(htons(port), "tcp");

            if (service != NULL)
                printf("%d/tcp: %s\n", port, service->s_name);
            else
                printf("%d/tcp: unknown\n", port);
        }

        close(sock);
    }

    printf("Scanning complete.\n");
    return 0;
}