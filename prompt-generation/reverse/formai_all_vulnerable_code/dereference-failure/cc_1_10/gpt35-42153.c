//FormAI DATASET v1.0 Category: Network Ping Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define MAX_PACKET_SIZE 2048
#define PORT_NUM 33434
#define MAX_HOPS 30

// Function to generate random IP address
char* generateRandomIP(){
    srand(time(NULL));
    char* ip = malloc(sizeof(char)*16);
    sprintf(ip, "%d.%d.%d.%d", rand()%255, rand()%255, rand()%255, rand()%255);
    return ip;
}

// Function to ping an IP
void ping(char* ipAddr) {
    // Create socket
    int sock;
    if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        perror("Could not create socket");
        return;
    }

    // Set socket options
    int ttl = MAX_HOPS;
    if (setsockopt(sock, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0) {
        perror("Could not set TTL");
        return;
    }

    struct timeval timeout;
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
        perror("Could not set socket timeout");
        return;
    }

    // Create socket address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT_NUM);
    addr.sin_addr.s_addr = inet_addr(ipAddr);

    // Prepare packet data
    char packet[MAX_PACKET_SIZE];
    memset(packet, 'ping', sizeof(packet));

    // Send the packet
    if (sendto(sock, packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error sending ping packet");
        return;
    }

    // Receive response
    struct sockaddr_in recvAddr;
    socklen_t recvAddrSize = sizeof(recvAddr);
    char recvPacket[MAX_PACKET_SIZE];
    int recvSize;
    if ((recvSize = recvfrom(sock, recvPacket, sizeof(recvPacket), 0, (struct sockaddr *)&recvAddr, &recvAddrSize)) < 0) {
        perror("No response received");
        return;
    }

    // Print response data
    char recvIp[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(recvAddr.sin_addr), recvIp, INET_ADDRSTRLEN);
    printf("Received response from %s\n", recvIp);
    printf("Response data: %s\n", recvPacket);
}

int main() {
    char* ip = generateRandomIP();
    printf("Pinging IP address: %s\n", ip);
    ping(ip);
    return 0;
}