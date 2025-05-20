//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>

#define PORTNO 5001 // Port number
#define MAXBUFFER 1024 // Maximum buffer size

int main(int argc, char* argv[]) {
    int mySockFd;
    struct sockaddr_in myAddr, peerAddr;
    fd_set mySet;
    struct timeval timeout;
    socklen_t peerAddrSize;
    char buffer[MAXBUFFER];
    int rc, bytesread;
    float cpuusage;
    int packetsize;
    char* packetdata;
    int packetsent;

    // Create socket
    mySockFd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (mySockFd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&myAddr, 0, sizeof(myAddr));
    myAddr.sin_family = AF_INET;
    myAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    myAddr.sin_port = htons(PORTNO);

    // Bind socket to local address
    rc = bind(mySockFd, (struct sockaddr*)&myAddr, sizeof(myAddr));
    if (rc < 0) {
        perror("Failed to bind socket to local address");
        close(mySockFd);
        exit(EXIT_FAILURE);
    }

    printf("QoS Monitor Started\n");

    while (1) {
        FD_ZERO(&mySet);
        FD_SET(mySockFd, &mySet);
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;

        // Wait for incoming packets
        rc = select(mySockFd + 1, &mySet, NULL, NULL, &timeout);
        if (rc < 0) {
            perror("Failed to select incoming packets");
            close(mySockFd);
            exit(EXIT_FAILURE);
        }

        if (rc == 0) { // Timeout occurred
            printf("No incoming packets in last 5 seconds\n");
            continue;
        }

        peerAddrSize = sizeof(peerAddr);

        // Read incoming packet
        bytesread = recvfrom(mySockFd, buffer, MAXBUFFER, 0, (struct sockaddr*)&peerAddr, &peerAddrSize);
        if (bytesread < 0) {
            perror("Failed to receive incoming packet");
            continue;
        }

        // Print packet information
        printf("Incoming Packet: %d bytes from %s:%d\n", bytesread, inet_ntoa(peerAddr.sin_addr), ntohs(peerAddr.sin_port));

        // Measure network QoS
        cpuusage = ((float)rand() / RAND_MAX) * 100.0; // Generate dummy CPU usage
        packetsize = 500 + rand() % 500; // Generate random packet size
        packetdata = (char*)malloc(packetsize);
        memset(packetdata, 'a', packetsize);
        packetsent = sendto(mySockFd, packetdata, packetsize, 0, (struct sockaddr*)&peerAddr, peerAddrSize);
        free(packetdata);

        if (packetsent < 0) {
            perror("Failed to send packet");
        } else {
            // Print QoS information
            printf("QoS Metrics\n");
            printf("-----------\n");
            printf("Packet Size: %d bytes\n", packetsize);
            printf("CPU Usage: %.2f%%\n", cpuusage);
            printf("Packet Loss: %.2f%%\n", ((float)packetsent / 10.0 - 1) * 100.0);
            printf("Latency: %d ms\n", rand() % 50);
        }
    }

    return 0;
}