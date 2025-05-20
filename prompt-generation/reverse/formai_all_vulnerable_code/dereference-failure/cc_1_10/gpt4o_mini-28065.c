//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

#define MAX_HOST_LEN 256
#define MAX_BUFFER_SIZE 1024
#define DEFAULT_PORT 80
#define PING_COUNT 4

// Function prototypes
void performQoSTest(const char *hostname);
double measureLatency(const char *hostname);
void logResults(const char *hostname, double latency, int packetLoss);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    performQoSTest(argv[1]);
    return EXIT_SUCCESS;
}

void performQoSTest(const char *hostname) {
    printf("Starting QoS monitor for host: %s\n", hostname);
    
    double latency = measureLatency(hostname);
    int packetLoss = rand() % 100; // Simulating packet loss percentage for monitoring
    
    printf("Latency: %.2f ms\n", latency);
    printf("Simulated Packet Loss: %d%%\n", packetLoss);
    
    logResults(hostname, latency, packetLoss);
}

double measureLatency(const char *hostname) {
    struct sockaddr_in server_addr;
    int sockfd;
    struct hostent *he;
    double latency = 0.0;
    char buffer[MAX_BUFFER_SIZE];

    // Resolve host
    if ((he = gethostbyname(hostname)) == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(DEFAULT_PORT);
    memcpy(&server_addr.sin_addr, he->h_addr_list[0], he->h_length);

    // Connect to server
    struct timeval start, end;

    gettimeofday(&start, NULL);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(sockfd);
        return -1;
    }
    gettimeofday(&end, NULL);
    
    // Calculate latency
    latency = ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);
    close(sockfd);
    
    return latency;
}

void logResults(const char *hostname, double latency, int packetLoss) {
    FILE *logFile;
    time_t t;
    struct tm *tm_info;
    char timeString[26];

    t = time(NULL);
    tm_info = localtime(&t);

    strftime(timeString, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    
    logFile = fopen("qos_log.txt", "a");
    if (!logFile) {
        perror("fopen");
        return;
    }
    
    fprintf(logFile, "[%s] Host: %s | Latency: %.2f ms | Packet Loss: %d%%\n", 
            timeString, hostname, latency, packetLoss);
    
    fclose(logFile);
    printf("Results logged to qos_log.txt\n");
}