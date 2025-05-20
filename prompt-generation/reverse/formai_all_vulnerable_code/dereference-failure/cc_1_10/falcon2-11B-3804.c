//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_LINE 80

void print_usage(char* prog) {
    printf("%s -a <ip_address> -p <port>\n", prog);
}

void print_error(char* msg) {
    printf("%s\n", msg);
    exit(1);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        print_usage(argv[0]);
        return 1;
    }

    char* ip = argv[1];
    int port = atoi(argv[2]);

    struct hostent* host;
    struct in_addr** addresses;

    host = gethostbyname(ip);
    if (host == NULL) {
        print_error("Invalid IP address");
        return 1;
    }

    addresses = (struct in_addr**) host->h_addr_list;
    if (addresses == NULL) {
        print_error("Invalid IP address");
        return 1;
    }

    for (int i = 0; addresses[i]!= NULL; i++) {
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        memcpy(&addr.sin_addr, addresses[i], sizeof(struct in_addr));
        addr.sin_port = htons(port);

        int sock = socket(AF_INET, SOCK_DGRAM, 0);
        if (sock == -1) {
            print_error("Failed to create socket");
            return 1;
        }

        int rc = connect(sock, (struct sockaddr*)&addr, sizeof(addr));
        if (rc == -1) {
            print_error("Failed to connect");
            return 1;
        }

        char buffer[MAX_LINE];
        int n = read(sock, buffer, sizeof(buffer));
        if (n == -1) {
            print_error("Failed to read from socket");
            return 1;
        }

        printf("%s\n", buffer);
        close(sock);
    }

    return 0;
}