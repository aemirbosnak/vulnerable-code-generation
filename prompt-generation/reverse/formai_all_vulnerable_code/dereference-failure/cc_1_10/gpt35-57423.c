//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    struct hostent *host;
    struct in_addr **addr_list;
    char hostname[100];

    if (argc < 2) {
        printf("Please enter a hostname or IP address.\n");
        return 1;
    }

    // Get the IP address of the host
    strncpy(hostname, argv[1], 100);
    host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return 1;
    }
    addr_list = (struct in_addr **)host->h_addr_list;

    // Connect to each device on the network and retrieve its information
    for (int i = 0; addr_list[i] != NULL; i++) {
        struct sockaddr_in addr;
        int sock = socket(AF_INET, SOCK_STREAM, 0);

        if (sock == -1) {
            perror("socket");
            return 1;
        }

        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = addr_list[i]->s_addr;
        addr.sin_port = htons(7);

        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
            printf("%s is not available on the network.\n", inet_ntoa(*addr_list[i]));
            close(sock);
            continue;
        }

        printf("%s is available on the network.\n", inet_ntoa(*addr_list[i]));

        close(sock);
    }

    return 0;
}