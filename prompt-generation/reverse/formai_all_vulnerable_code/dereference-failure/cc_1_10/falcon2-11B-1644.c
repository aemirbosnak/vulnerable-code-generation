//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <string.h>

#define BUF_SIZE 2048

struct PacketInfo {
    struct sockaddr_in srcAddr;
    struct sockaddr_in dstAddr;
    int portNo;
    int packetLen;
};

struct PacketData {
    unsigned char data[BUF_SIZE];
};

void* packetMonitorThread(void* arg) {
    int sockfd;
    struct PacketInfo* packetInfo;
    struct PacketData* packetData;

    sockfd = (int)arg;

    // Read packets continuously
    while (1) {
        packetInfo = (struct PacketInfo*)malloc(sizeof(struct PacketInfo));
        packetData = (struct PacketData*)malloc(sizeof(struct PacketData));

        recvfrom(sockfd, packetData->data, BUF_SIZE, 0, (struct sockaddr*)&packetInfo->srcAddr, &packetInfo->portNo);
        packetInfo->dstAddr = packetInfo->srcAddr;
        packetInfo->packetLen = sizeof(struct sockaddr_in) + sizeof(int) + BUF_SIZE;

        printf("Source IP: %s\n", inet_ntoa(packetInfo->srcAddr.sin_addr));
        printf("Destination IP: %s\n", inet_ntoa(packetInfo->dstAddr.sin_addr));
        printf("Port Number: %d\n", ntohs(packetInfo->portNo));
        printf("Packet Length: %d\n", packetInfo->packetLen);

        free(packetInfo);
        free(packetData);
    }

    return NULL;
}

void writeToFile(const char* filename, const struct PacketInfo* packetInfo, const struct PacketData* packetData) {
    FILE* file = fopen(filename, "a");

    fprintf(file, "Source IP: %s\n", inet_ntoa(packetInfo->srcAddr.sin_addr));
    fprintf(file, "Destination IP: %s\n", inet_ntoa(packetInfo->dstAddr.sin_addr));
    fprintf(file, "Port Number: %d\n", ntohs(packetInfo->portNo));
    fprintf(file, "Packet Length: %d\n", packetInfo->packetLen);

    fclose(file);
}

int main() {
    struct PacketInfo packetInfo;
    struct PacketData packetData;

    packetInfo.srcAddr.sin_family = AF_INET;
    packetInfo.dstAddr.sin_family = AF_INET;

    packetInfo.srcAddr.sin_port = htons(80);
    packetInfo.dstAddr.sin_port = htons(80);

    packetInfo.srcAddr.sin_addr.s_addr = inet_addr("192.168.0.1");
    packetInfo.dstAddr.sin_addr.s_addr = inet_addr("192.168.0.2");

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd == -1) {
        perror("Error creating socket");
        return 1;
    }

    packetInfo.packetLen = sizeof(struct sockaddr_in) + sizeof(int) + BUF_SIZE;

    packetMonitorThread(sockfd);

    writeToFile("packet.log", &packetInfo, &packetData);

    return 0;
}