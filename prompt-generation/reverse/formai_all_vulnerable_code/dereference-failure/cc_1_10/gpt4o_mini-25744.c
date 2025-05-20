//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <signal.h>
#include <time.h>

#define BUFFER_SIZE 256
#define MAX_HOSTNAME_LENGTH 256
#define DEFAULT_PORT 8080

typedef struct {
    char hostname[MAX_HOSTNAME_LENGTH];
    int port;
    int packetLoss; // measured in percentage
    double latency; // measured in milliseconds
} QoSData;

void signalHandler(int signum) {
    printf("\nProgram interrupted. Exiting gracefully...\n");
    exit(signum);
}

void measureQoS(QoSData *data) {
    struct sockaddr_in serverAddr;
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct timespec start, end;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(data->port);
    
    // Convert hostname to IP
    struct hostent *host_entry;
    host_entry = gethostbyname(data->hostname);
    if (host_entry == NULL) {
        fprintf(stderr, "Error: Getting Hostname - %s\n", hstrerror(h_errno));
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    memcpy(&serverAddr.sin_addr, host_entry->h_addr_list[0], host_entry->h_length);

    // Prepare to send and receive data
    clock_gettime(CLOCK_MONOTONIC, &start);
    int sentBytes = sendto(sockfd, "Ping", strlen("Ping"), 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    
    if (sentBytes < 0) {
        perror("Sendto failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive response
    socklen_t addrLen = sizeof(serverAddr);
    int receivedBytes = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&serverAddr, &addrLen);

    clock_gettime(CLOCK_MONOTONIC, &end);

    if (receivedBytes < 0) {
        data->packetLoss = 100; // Assume 100% packet loss
        data->latency = -1;
    } else {
        data->packetLoss = 0; // No packet loss
        buffer[receivedBytes] = '\0'; // Null terminate the received data
        printf("Received: %s\n", buffer);
        
        // Calculate latency
        data->latency = (end.tv_sec - start.tv_sec) * 1000.0 + 
                        (end.tv_nsec - start.tv_nsec) / 1000000.0;
    }

    close(sockfd);
}

void printQoSData(const QoSData *data) {
    printf("QoS Monitor Results:\n");
    printf("Hostname: %s\n", data->hostname);
    printf("Port: %d\n", data->port);
    printf("Packet Loss: %d%%\n", data->packetLoss);
    printf("Latency: %.2f ms\n", data->latency);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname> [port]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, signalHandler);

    QoSData data;
    strncpy(data.hostname, argv[1], MAX_HOSTNAME_LENGTH);
    data.port = (argc > 2) ? atoi(argv[2]) : DEFAULT_PORT;
    data.packetLoss = -1;
    data.latency = -1;

    printf("Monitoring QoS for %s:%d...\n", data.hostname, data.port);
    sleep(2); // wait before measuring

    measureQoS(&data);
    printQoSData(&data);

    return 0;
}