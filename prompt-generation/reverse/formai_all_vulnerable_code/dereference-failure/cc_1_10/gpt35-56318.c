//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFSIZE 1024

// Function prototypes
void scan_network(char *subnet, int port);

// Main function
int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <subnet>\n", argv[0]);
        printf("Example: %s 192.168.0\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    scan_network(argv[1], PORT);

    return 0;
}

// Function to scan the network
void scan_network(char *subnet, int port)
{
    char buf[BUFSIZE];
    int sock, status, i;
    struct hostent *host;
    struct sockaddr_in addr;

    for(i=1; i<=254; i++) {
        sprintf(buf, "%s.%d", subnet, i);

        // Attempt to resolve hostname
        if((host=gethostbyname(buf))==NULL) {
            printf("Error: Could not resolve hostname %s!\n", buf);
            continue;
        }

        // Create socket
        if((sock=socket(AF_INET, SOCK_STREAM, 0))== -1) {
            printf("Error: Could not create socket!\n");
            continue;
        }

        // Set socket options
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        memcpy(&addr.sin_addr, host->h_addr, host->h_length);
        memset(&(addr.sin_zero), 0, 8);

        // Attempt to connect to host
        status = connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr));
        if(status == -1) {
            // Host is unreachable
            close(sock);
            continue;
        }

        // Host is reachable
        printf("Host %s is up!\n", buf);
        close(sock);
    }

    printf("Scan complete!\n");
}