//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: beginner-friendly
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

// Function to calculate QoS parameters
void calculateQoS(int sockfd, struct sockaddr_in serverAddr, char* packet){
    int packetLength = strlen(packet);
    int rtt = 0;
    int jitter = 0;

    // Calculate round trip time (RTT)
    rtt = ((int)packetLength * 8) / ((double)sockfd);

    // Calculate jitter
    jitter = (rtt - (int)packetLength) / (int)packetLength;

    // Print QoS parameters
    printf("Packet length: %d bytes\n", packetLength);
    printf("Round Trip Time (RTT): %d ms\n", rtt);
    printf("Jitter: %d ms\n", jitter);
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serverAddr;
    char packet[1000];

    // Create a socket
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket failed");
        return 1;
    }

    // Set up server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5000);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if(connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0){
        perror("connect failed");
        return 1;
    }

    // Send a packet to the server
    sprintf(packet, "Hello, Server!");
    send(sockfd, packet, strlen(packet), 0);

    // Receive a packet from the server
    int nBytes;
    nBytes = recv(sockfd, packet, sizeof(packet), 0);
    if(nBytes < 0){
        perror("recv failed");
        return 1;
    }
    printf("Received packet: %s\n", packet);

    // Calculate QoS parameters
    calculateQoS(sockfd, serverAddr, packet);

    // Close socket
    close(sockfd);

    return 0;
}