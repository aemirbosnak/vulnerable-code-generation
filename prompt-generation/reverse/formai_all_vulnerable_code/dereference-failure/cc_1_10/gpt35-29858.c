//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define MAX_ROUTERS 10
#define MAX_STRING_LENGTH 256

// Functions to handle different operations
void parse_arguments(int argc, char *argv[], char **interface);
void print_routers(char routers[MAX_ROUTERS][MAX_STRING_LENGTH], int num_routers);
int add_router(char routers[MAX_ROUTERS][MAX_STRING_LENGTH], char *router);
int discover_routers(char routers[MAX_ROUTERS][MAX_STRING_LENGTH], char *interface);

int main(int argc, char *argv[]) {
    char *interface = NULL;
    char routers[MAX_ROUTERS][MAX_STRING_LENGTH];
    int num_routers;

    // Parse command line arguments
    parse_arguments(argc, argv, &interface);

    // Discover routers on specified interface
    num_routers = discover_routers(routers, interface);

    // Print out list of routers found
    printf("Routers found on '%s':\n", interface);
    print_routers(routers, num_routers);

    return 0;
}

void parse_arguments(int argc, char *argv[], char **interface) {
    // Check number of arguments
    if (argc == 2) {
        // Assign interface from command line argument
        *interface = argv[1];
    } else {
        // Print usage and exit
        printf("Usage: wireless-scanner <interface>\n\n");
        exit(-1);
    }
}

int discover_routers(char routers[MAX_ROUTERS][MAX_STRING_LENGTH], char *interface) {
    int sd;
    struct ifreq ifr;
    unsigned char *mac;
    struct sockaddr_in *sin;
    int num_routers = 0;

    // Open socket
    sd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sd < 0) {
        perror("socket() failed");
        exit(-1);
    }

    // Get interface MAC address
    memset(&ifr, 0, sizeof(ifr));
    strcpy(ifr.ifr_name, interface);
    if (ioctl(sd, SIOCGIFHWADDR, &ifr) < 0) {
        perror("ioctl() failed");
        exit(-1);
    }
    mac = (unsigned char *) ifr.ifr_hwaddr.sa_data;

    // Set socket options to multicast
    int on = 1;
    if (setsockopt(sd, SOL_SOCKET, SO_BROADCAST, (char *) &on, sizeof(on)) < 0) {
        perror("setsockopt() failed");
        exit(-1);
    }

    // Set socket timeout
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    if (setsockopt(sd, SOL_SOCKET, SO_RCVTIMEO, (char *) &tv, sizeof(tv)) < 0) {
        perror("setsockopt() failed");
        exit(-1);
    }

    // Bind socket to interface
    memset(&ifr, 0, sizeof(ifr));
    strcpy(ifr.ifr_name, interface);
    if (setsockopt(sd, SOL_SOCKET, SO_BINDTODEVICE, (char *)&ifr, sizeof(ifr)) < 0) {
        perror("setsockopt() failed");
        exit(-1);
    }

    // Create packet to send
    unsigned char packet[1024];
    memset(packet, 0, sizeof(packet));
    packet[0] = 0x01;
    packet[1] = 0x00;
    packet[2] = 0x5e;
    packet[3] = 0x00;
    packet[4] = 0x00;
    packet[5] = 0x01;

    // Send packet to multicast address
    sin = (struct sockaddr_in *) packet;
    sin->sin_family = AF_INET;
    sin->sin_port = htons(520);
    sin->sin_addr.s_addr = inet_addr("224.0.0.1");

    if (sendto(sd, packet, sizeof(packet), 0, (struct sockaddr *) sin, sizeof(struct sockaddr)) < 0) {
        perror("sendto() failed");
        exit(-1);
    }

    // Listen for responses
    while (true) {
        unsigned char buffer[1024];
        struct sockaddr_in peer;
        socklen_t peer_len = sizeof(struct sockaddr_in);
        int recv_len = recvfrom(sd, buffer, sizeof(buffer), 0, (struct sockaddr *) &peer, &peer_len);

        if (recv_len > 0) {
            // Check packet header
            if (buffer[0] == 0x01 && buffer[1] == 0x00 && buffer[2] == 0x5e && buffer[3] == 0x00 && buffer[4] == 0x00 && buffer[5] == 0x01) {
                // Get router IP address
                char ip[INET_ADDRSTRLEN];
                inet_ntop(AF_INET, &peer.sin_addr, ip, INET_ADDRSTRLEN);

                // Add router to list
                if (add_router(routers, ip) == 0) {
                    num_routers++;
                }
            }
        } else {
            // Timeout
            break;
        }
    }

    // Close socket
    close(sd);

    return num_routers;
}

int add_router(char routers[MAX_ROUTERS][MAX_STRING_LENGTH], char *router) {
    int i;

    // Check if router already in list
    for (i = 0; i < MAX_ROUTERS; i++) {
        if (strcmp(routers[i], router) == 0) {
            return -1;
        }
    }

    // Find next available slot in list
    for (i = 0; i < MAX_ROUTERS; i++) {
        if (strcmp(routers[i], "") == 0) {
            strcpy(routers[i], router);
            return 0;
        }
    }

    // List is full
    return -1;
}

void print_routers(char routers[MAX_ROUTERS][MAX_STRING_LENGTH], int num_routers) {
    int i;

    for (i = 0; i < num_routers; i++) {
        printf("%d. %s\n", i+1, routers[i]);
    }
}