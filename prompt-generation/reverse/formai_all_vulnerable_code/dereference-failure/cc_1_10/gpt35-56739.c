//FormAI DATASET v1.0 Category: Network Ping Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <time.h>

int calculateRTT(struct timeval sentTime, struct timeval receivedTime);

int main(int argc, char *argv[]) 
{
    if(argc != 2) {
        printf("Usage: %s <IP address>\n",argv[0]);
        exit(1);
    }

    char *medievalMsg[] = {"Dost thou remember the Tower of Barad-dûr?", 
                            "In the land of Mordor, where the shadows lie.",
                            "One Ping to rule them all, One Ping to find them,",
                            "One Ping to bring them all, and in the darkness bind them",
                            "By the power of the Holy Grail, I command you to answer!"};
    int medievalMsgLen = sizeof(medievalMsg) / sizeof(medievalMsg[0]);

    struct timeval sentTime, receivedTime;
    int packetCount = 0, packetLoss = 0, rttSum = 0, rttMax = 0, rttMin = 10000;
    float packetLossPercentage;

    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(sock < 0) {
        printf("Socket open error!\n");
        exit(1);
    }

    struct hostent *hostInfo = gethostbyname(argv[1]);
    if(hostInfo == NULL) {
        printf("Failed to resolve host IP address.\n");
        exit(1);
    }

    printf("Pinging to IP address %s [%s] using medieval network packets.\n", argv[1], inet_ntoa(*((struct in_addr*) hostInfo->h_addr)));

    for(int i=0; i<10; i++){
        
        struct sockaddr_in dest_address;
        dest_address.sin_family = AF_INET;
        dest_address.sin_addr = *((struct in_addr*) hostInfo->h_addr);
        dest_address.sin_port = htons(0);

        char pingPacket[1024];
        memset(&pingPacket, 0, sizeof(pingPacket));

        int packetSize = 5 + strlen(medievalMsg[i % medievalMsgLen]) + 1;  
        snprintf(pingPacket, packetSize, "MED%d:%s", i, medievalMsg[i % medievalMsgLen]); 

        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        gettimeofday(&sentTime, NULL);

        if(sendto(sock, pingPacket, packetSize, 0, (struct sockaddr*) &dest_address, sizeof(dest_address)) < 0) {
            printf("Error sending packet.\n");
            packetCount--;
            packetLoss++;
            continue;
        }

        int addrLen = sizeof(dest_address);
        char receivedPacket[1024];
        memset(&receivedPacket, 0, sizeof(receivedPacket));

        if(setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0){
            printf("Error in setting timeout.\n");
            packetCount--;
            packetLoss++;
            continue;
        }

        int receivedBytes = recvfrom(sock, receivedPacket, sizeof(receivedPacket), 0, (struct sockaddr*) &dest_address, &addrLen);
        if(receivedBytes < 0) {
            printf("Packet lost!\n");
            packetLoss++;
        } else {
            gettimeofday(&receivedTime, NULL);
            int rtt = calculateRTT(sentTime, receivedTime);
            printf("Ping Reply from %s: Sequence Number = %d, RTT = %dms, Message = %s.\n", argv[1], i, rtt, receivedPacket+5);
            packetCount++;
            rttSum += rtt;
            if(rtt > rttMax) rttMax = rtt;
            if(rtt < rttMin) rttMin = rtt;
        }
        sleep(1);
    }

    packetLossPercentage = ((float) packetLoss / packetCount) * 100.0;

    printf("\n--- Ping Statistics ---\n");
    printf("%d packets transmitted, %d packets received, %.2f%% packet loss.\n", packetCount+packetLoss, packetCount, packetLossPercentage);
    printf("Round Trip Time: Min = %dms, Max = %dms, Average = %.2fms.\n", rttMin, rttMax, (float) rttSum/packetCount);

    close(sock);

    return 0;
}

int calculateRTT(struct timeval sentTime, struct timeval receivedTime) {
    int seconds = receivedTime.tv_sec - sentTime.tv_sec;
    int microseconds = receivedTime.tv_usec - sentTime.tv_usec;
    if(microseconds < 0){
        seconds--;
        microseconds += 1000000;
    }
    return (seconds * 1000) + (microseconds / 1000);
}