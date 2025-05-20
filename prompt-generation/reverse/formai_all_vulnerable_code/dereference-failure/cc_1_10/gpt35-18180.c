//FormAI DATASET v1.0 Category: Port Scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT_START 1
#define PORT_END 65535

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Please provide a host to scan\n");
        return 1;
    }

    const char *host = argv[1];
    struct hostent *host_entry;
    host_entry = gethostbyname(host);

    if (!host_entry) {
        fprintf(stderr, "%s is not a valid host\n", host);
        return 1;
    }

    char ip_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, host_entry->h_addr_list[0], ip_str, sizeof(ip_str));
    printf("Scanning %s (%s)...\n", host, ip_str);

    int sock;
    struct sockaddr_in target;

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip_str);

    printf("Port      Status\n");

    for (int port = PORT_START; port <= PORT_END; port++) {
        target.sin_port = htons(port);

        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
            return 1;
        }

        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("%-10dOpen\n", port);
        }

        close(sock);
    }

    return 0;
}