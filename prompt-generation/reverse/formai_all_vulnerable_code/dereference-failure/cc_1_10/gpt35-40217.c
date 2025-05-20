//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_DEVICES 100 // Maximun number of devices the program can handle at once

/* Device struct represents a network device */
struct Device {
    char ip_address[15];
    char mac_address[18];
};

/* Function to scan the network and detect devices in it */
int network_scan(struct Device* devices) {
    int sockfd, cnt = 0;
    struct sockaddr_in address;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    memset(&address, 0, sizeof(struct sockaddr_in));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(0);

    if (bind(sockfd, (struct sockaddr*) &address, sizeof(struct sockaddr_in)) < 0) {
        perror("bind() failed");
        exit(EXIT_FAILURE);
    }

    struct timeval timeout;
    timeout.tv_sec = 1;     // Wait for 1 second for a response
    timeout.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout)) < 0) {
        perror("setsockopt() failed");
        exit(EXIT_FAILURE);
    }

    int broadcast = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast)) < 0) {
        perror("setsockopt() failed");
        exit(EXIT_FAILURE);
    }
    
    char message[] = "PING";
    struct sockaddr_in broadcast_address;
    memset(&broadcast_address, 0, sizeof(broadcast_address));
    broadcast_address.sin_family = AF_INET;
    broadcast_address.sin_addr.s_addr = inet_addr("255.255.255.255"); // Broadcast to all devices
    broadcast_address.sin_port = htons(50000); // Choose an arbitrary port number

    if (sendto(sockfd, (const char*)message, strlen(message), 0, (const struct sockaddr*) &broadcast_address, sizeof(broadcast_address)) < 0) {
        perror("sendto() failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in remote_address;
    socklen_t remote_address_len = sizeof(remote_address);
    char buffer[1024];

    while (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*) &remote_address, &remote_address_len) > 0) {
        struct Device device;
        strcpy(device.ip_address, inet_ntoa(remote_address.sin_addr)); // Get the IP address of the detected device
        strncpy(device.mac_address, buffer, sizeof(device.mac_address)); // Get the MAC address of the detected device
        devices[cnt++] = device;
        if (cnt >= MAX_DEVICES)
            break;
    }

    close(sockfd);
    return cnt;
}

/* Function to output the network topology */
void show_topology(struct Device* devices, int num_devices) {
    printf("Network Topology:\n");
    for (int i = 0; i < num_devices; i++) {
        printf("%s (%s)\n", devices[i].ip_address, devices[i].mac_address);
    }
}

int main() {
    struct Device devices[MAX_DEVICES]; // Array to store detected devices
    int num_devices = network_scan(devices); // Scan the network and detect devices
    show_topology(devices, num_devices); // Output the network topology
    return 0;
}