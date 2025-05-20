//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/time.h>

#define BUFSIZE 1024

float calculateThroughput(float totalData, float totalTime) {
    return (totalData / totalTime);
}

float calculateLatency(float sumRTTs, float totalPackets) {
    return (sumRTTs / totalPackets);
}

void displayQoS(float throughputValue, float latencyValue) {
    printf("Network Quality of Service (QoS) Monitor:\n");
    printf("Throughput:\t%.3f KB/s\n", throughputValue);
    printf("Latency:\t%.3f ms\n", latencyValue);
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUFSIZE];
    struct hostent *host;
    int port, n;
    float throughput, sumRTTs, latency;
    int packetCount = 0;
    struct timeval t1, t2;
    float elapsedTime, totalData = 0;

    if(argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    host = gethostbyname(argv[1]);
    port = atoi(argv[2]);

    // Creating socket file descriptor
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr = *((struct in_addr *) host->h_addr);

    // Connecting to server
    if(connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    printf("Enter 'exit' to terminate the connection.\n");

    while(1) {
        memset(buffer, 0, BUFSIZE);
        printf("Enter message: ");
        fgets(buffer, BUFSIZE, stdin);

        // Terminate connection if user enters 'exit'
        if(strncmp(buffer, "exit", 4) == 0) {
            close(sockfd);
            printf("\nConnection terminated.\n");
            break;
        }

        // Sending data to server
        write(sockfd, buffer, strlen(buffer));

        gettimeofday(&t1, NULL);

        // Receiving data from server
        n = read(sockfd, buffer, BUFSIZE);

        gettimeofday(&t2, NULL);

        // Calculating round-trip time and total transferred data
        elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
        elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
        sumRTTs += elapsedTime;
        totalData += n;

        if(n < 0) {
            perror("Error receiving data");
        } else {
            printf("Server: %s", buffer);
            packetCount++;
        }
    }

    // Calculating throughput and latency
    throughput = calculateThroughput(totalData / 1024.0, elapsedTime / 1000.0);
    latency = calculateLatency(sumRTTs, packetCount);

    // Displaying the QoS
    displayQoS(throughput, latency);

    return 0;
}