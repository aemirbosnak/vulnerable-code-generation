//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define PORT 80 // The port number of the web server
#define MAX_BUFFER_SIZE 1024

int main(int argc, char **argv) {

    // Get the network interface name from the command line argument
    if(argc < 2) {
        printf("Usage: %s <interface_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *interface_name = argv[1];

    // Create a socket for sending packet
    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(socket_fd == -1) {
        fprintf(stderr, "Failed to create a socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the network interface
    struct ifreq ifr;
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, interface_name, IFNAMSIZ-1);
    if(ioctl(socket_fd, SIOCGIFADDR, &ifr) == 0) {
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(PORT);
        addr.sin_addr.s_addr = htonl(INADDR_ANY);
        if(bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
            fprintf(stderr, "Failed to bind the socket: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    } else {
        fprintf(stderr, "Failed to get interface address: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Create an UDP packet to send
    char *packet = "Hello, world!";
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(PORT);
    dest_addr.sin_addr.s_addr = inet_addr("255.255.255.255");

    // Set socket options to allow broadcasting
    int broadcast_enable = 1;
    if(setsockopt(socket_fd, SOL_SOCKET, SO_BROADCAST, &broadcast_enable, sizeof(broadcast_enable)) == -1) {
        fprintf(stderr, "Failed to set socket option: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Send the packet to the broadcast address
    if(sendto(socket_fd, packet, strlen(packet) + 1, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) == -1) {
        fprintf(stderr, "Failed to send packet: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Receive UDP packets on the network interface
    struct sockaddr_in src_addr;
    socklen_t src_addr_len = sizeof(src_addr);
    char buffer[MAX_BUFFER_SIZE];
    while(1) {
        memset(buffer, 0, sizeof(buffer));
        int data_len = recvfrom(socket_fd, buffer, sizeof(buffer), 0, (struct sockaddr *)&src_addr, &src_addr_len);
        if(data_len == -1) {
            fprintf(stderr, "Failed to receive packet: %s\n", strerror(errno));
            break;
        }
        printf("Received packet from %s:%u\n", inet_ntoa(src_addr.sin_addr), ntohs(src_addr.sin_port));
        printf("%s\n", buffer);
    }

    close(socket_fd);
    return 0;
}