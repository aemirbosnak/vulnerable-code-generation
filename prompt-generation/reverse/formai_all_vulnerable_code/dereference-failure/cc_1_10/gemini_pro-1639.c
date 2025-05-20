//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFF_SIZE    1024
#define MAX_PORTS    65535

char* hostname;
struct hostent* host;
int sfd;

void usage(char* name) {
    fprintf(stderr, "Usage: %s hostname start_port end_port\n", name);
    exit(1);
}

int main(int argc, char** argv) {
    if (argc != 4) {
        usage(argv[0]);
    }

    hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if ((start_port < 0) || (start_port > end_port) || (end_port > MAX_PORTS)) {
        usage(argv[0]);
    }

    host = gethostbyname(hostname);
    if (!host) {
        herror("gethostbyname");
        exit(1);
    }

    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr = *(struct in_addr*)host->h_addr_list[0];

    for (int port = start_port; port <= end_port; port++) {
        addr.sin_port = htons(port);

        if (connect(sfd, (struct sockaddr*)&addr, sizeof(addr)) == 0) {
            printf("Port %d on %s is open\n", port, hostname);
        } else {
            if (errno == ECONNREFUSED) {
                printf("Port %d on %s is closed\n", port, hostname);
            } else {
                perror("connect");
                exit(1);
            }
        }
    }

    close(sfd);
    return 0;
}