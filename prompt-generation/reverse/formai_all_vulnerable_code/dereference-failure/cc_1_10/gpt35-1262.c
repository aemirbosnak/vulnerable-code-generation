//FormAI DATASET v1.0 Category: Port Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

void print_banner() {
    printf("\n*****************************************\n");
    printf("*            MEDIEVAL PORT SCANNER       *\n");
    printf("*****************************************\n\n");
}

void print_usage(char *prog_name) {
    printf("Usage: %s <ip_address> <start_port> <end_port>\n", prog_name);
}

int main(int argc, char** argv) {

    if (argc < 4) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    char* host_name = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    print_banner();

    printf("Scanning host %s from port %d to %d...\n", host_name, start_port, end_port);

    struct hostent *he = gethostbyname(host_name);

    if (he == NULL) {
        printf("Invalid hostname\n");
        exit(EXIT_FAILURE);
    }

    struct in_addr **addr_list = (struct in_addr **) he->h_addr_list;

    for (int i = 0; addr_list[i] != NULL; i++) {
        char ip_address[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, addr_list[i], ip_address, INET_ADDRSTRLEN);

        printf("Scanning IP address %s...\n", ip_address);

        for (int port = start_port; port <= end_port; port++) {

            struct sockaddr_in sa;

            memset(&sa, 0, sizeof(sa));
            sa.sin_family = AF_INET;
            sa.sin_addr.s_addr = inet_addr(ip_address);
            sa.sin_port = htons(port);

            int sock = socket(AF_INET, SOCK_STREAM, 0);
            if (sock < 0) {
                perror("socket()");
                continue;
            }

            int ret = connect(sock, (struct sockaddr *)&sa, sizeof(sa));
            if (ret < 0) {
                // Port is closed
                close(sock);
                continue;
            } else {
                // Port is open
                printf("Port %d: OPEN\n", port);
                close(sock);
            }
        }
    }

    exit(EXIT_SUCCESS);
}