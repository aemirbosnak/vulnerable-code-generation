//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/in.h>
#include <time.h>

#define BUFFER_SIZE 65535

void errorExit(char *errorMessage) {
    printf("\n[ERROR] %s\n", errorMessage);
    exit(EXIT_FAILURE);
}

int main() {
    int rawSocketFD;
    if ((rawSocketFD = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) == -1)
        errorExit("Failed to create raw socket");

    unsigned char buffer[BUFFER_SIZE];
    struct sockaddr_in sourceSocket, destinationSocket;
    socklen_t sourceLength = sizeof(sourceSocket), destinationLength = sizeof(destinationSocket);

    while (1) {
        int packetSize = recvfrom(rawSocketFD, buffer, BUFFER_SIZE, 0,
                                  (struct sockaddr *) &sourceSocket, &sourceLength);
        if (packetSize == -1)
            errorExit("Failed to receive packets");

        int protocol = ntohs(((struct ethhdr *) buffer)->h_proto);

        time_t currentTime;
        time(&currentTime);
        char *timeString = ctime(&currentTime);
        timeString[strlen(timeString) - 1] = '\0';    //Removing the new line character

        printf("\n\n");
        printf("Time: %s\n", timeString);
        printf("Packet Size: %d bytes\n", packetSize);
        printf("Protocol: ");

        switch (protocol) {
            case ETH_P_IP:
                printf("IPv4\n");
                break;

            case ETH_P_IPV6:
                printf("IPv6\n");
                break;

            case ETH_P_ARP:
                printf("ARP\n");
                break;

            case ETH_P_RARP:
                printf("RARP\n");
                break;

            default:
                printf("Other\n");
                break;
        }

        struct iphdr *ipHeader = (struct iphdr *) (buffer + sizeof(struct ethhdr));

        printf("Source Address: %s\n", inet_ntoa(sourceSocket.sin_addr));
        printf("Destination Address: %s\n", inet_ntoa(destinationSocket.sin_addr));
        printf("Time to Live: %d\n", (unsigned int) ipHeader->ttl);

        switch (ipHeader->protocol) {
            case IPPROTO_TCP: {
                struct tcphdr *tcpHeader = (struct tcphdr *) (buffer + sizeof(struct ethhdr) + sizeof(struct iphdr));
                printf("Source Port: %d\n", ntohs(tcpHeader->source));
                printf("Destination Port: %d\n", ntohs(tcpHeader->dest));
                break;
            }

            case IPPROTO_UDP: {
                struct udphdr *udpHeader = (struct udphdr *) (buffer + sizeof(struct ethhdr) + sizeof(struct iphdr));
                printf("Source Port: %d\n", ntohs(udpHeader->source));
                printf("Destination Port: %d\n", ntohs(udpHeader->dest));
                break;
            }

            case IPPROTO_ICMP: {
                printf("ICMP\n");
                break;
            }

            default: {
                printf("Other Protocol\n");
                break;
            }
        }
    }

    return 0;
}