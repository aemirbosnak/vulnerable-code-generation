//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: detailed
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <netdb.h>

// Function to establish a TCP connection
int establishConnection(char* host, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(host);

    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send a SYN packet to the server
void sendSYN(int sockfd) {
    int len = sizeof(struct tcphdr);
    int status = send(sockfd, &len, len, 0);
    if (status < 0) {
        perror("Error sending SYN packet");
        exit(EXIT_FAILURE);
    }
}

// Function to receive and process the ACK packet
void processACK(int sockfd) {
    int len = sizeof(struct tcphdr);
    int status = recv(sockfd, &len, len, 0);
    if (status < 0) {
        perror("Error receiving ACK packet");
        exit(EXIT_FAILURE);
    }

    struct tcphdr* tcpHdr = (struct tcphdr*)malloc(len);
    memcpy(tcpHdr, (char*)malloc(len), len);

    int ackNum = ntohs(tcpHdr->th_ack);

    printf("Received ACK: %d\n", ackNum);
}

// Function to send a RST packet to the server
void sendRST(int sockfd) {
    int len = sizeof(struct tcphdr);
    int status = send(sockfd, &len, len, 0);
    if (status < 0) {
        perror("Error sending RST packet");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char* host = "192.168.1.1";
    int port = 80;

    // Establish a TCP connection
    int sockfd = establishConnection(host, port);
    if (sockfd < 0) {
        perror("Error establishing connection");
        exit(EXIT_FAILURE);
    }

    // Send a SYN packet
    sendSYN(sockfd);

    // Receive and process the ACK packet
    processACK(sockfd);

    // Send a RST packet
    sendRST(sockfd);

    return 0;
}