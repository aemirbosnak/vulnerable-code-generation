//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <errno.h>

#define MAX_HOST_NAME 256
#define MAX_DEVICE_NAME 256

struct hostent *gethostbyname(const char *name);
int gethostname(char *name, size_t namelen);

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *host;
    char hostname[MAX_HOST_NAME];
    char devicename[MAX_DEVICE_NAME];

    if (argc!= 2) {
        printf("usage: %s <device_name>\n", argv[0]);
        exit(1);
    }

    strcpy(devicename, argv[1]);

    // Get the hostname of the device
    gethostname(hostname, MAX_HOST_NAME);

    // Get the IP address of the device
    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: could not get host information\n");
        exit(1);
    }

    // Create a socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error: could not create socket\n");
        exit(1);
    }

    // Set the destination address and port
    struct sockaddr_in dest;
    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(1234);
    inet_pton(AF_INET, host->h_addr, &dest.sin_addr);

    // Send a UDP packet to the device
    char message[1000];
    strcpy(message, "Hello, ");
    strcat(message, devicename);
    strcat(message, "!\n");
    sendto(sock, message, strlen(message), 0, (struct sockaddr *)&dest, sizeof(dest));

    // Close the socket
    close(sock);

    return 0;
}