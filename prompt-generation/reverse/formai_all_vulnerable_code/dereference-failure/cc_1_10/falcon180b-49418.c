//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netdb.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    char iface[IF_NAMESIZE];
    struct ifreq ifr;
    int sock, n;
    char buf[BUF_SIZE];
    struct sockaddr_in server_addr;
    struct hostent *host;
    char *host_name;
    int port;

    // Get interface name from command line argument
    strncpy(iface, argv[1], IF_NAMESIZE);

    // Open socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5405);

    // Resolve host name
    host = gethostbyname("localhost");
    if (host == NULL) {
        fprintf(stderr, "Error: %s\n", hstrerror(h_errno));
        return 1;
    }

    // Copy IP address to server address
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    // Send interface name to server
    n = strlen(iface);
    if (send(sock, iface, n, 0) < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    // Receive response from server
    n = recv(sock, buf, BUF_SIZE, 0);
    if (n < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    // Close socket
    close(sock);

    // Print response
    printf("Response: %s\n", buf);

    return 0;
}