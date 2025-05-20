//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

// QoS parameters
#define TOS_LOW_DELAY        0x10
#define TOS_THROUGHPUT       0x08
#define TOS_RELIABILITY      0x04
#define TOS_MIN_COST         0x02

// Socket options
#define IP_TOS              1
#define IPPROTO_IP          0

// Network QoS Monitor
typedef struct {
    int sockfd;
    struct sockaddr_in servaddr;
    int tos;
    int interval;
    int duration;
    char *host;
    int port;
} QoSMonitor;

// Create a new QoS monitor
QoSMonitor *qos_monitor_new(char *host, int port, int tos, int interval, int duration) {
    QoSMonitor *qm = malloc(sizeof(QoSMonitor));
    qm->sockfd = -1;
    qm->servaddr.sin_family = AF_INET;
    qm->servaddr.sin_port = htons(port);
    qm->tos = tos;
    qm->interval = interval;
    qm->duration = duration;
    qm->host = strdup(host);
    qm->port = port;
    return qm;
}

// Destroy a QoS monitor
void qos_monitor_destroy(QoSMonitor *qm) {
    if (qm->sockfd != -1) {
        close(qm->sockfd);
    }
    free(qm->host);
    free(qm);
}

// Start the QoS monitor
int qos_monitor_start(QoSMonitor *qm) {
    // Create a socket
    qm->sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (qm->sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Set the socket options
    int optval = qm->tos;
    if (setsockopt(qm->sockfd, IPPROTO_IP, IP_TOS, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        return -1;
    }

    // Resolve the hostname
    struct hostent *hostent = gethostbyname(qm->host);
    if (hostent == NULL) {
        perror("gethostbyname");
        return -1;
    }

    // Connect to the server
    qm->servaddr.sin_addr = *(struct in_addr *)hostent->h_addr;
    if (connect(qm->sockfd, (struct sockaddr *)&qm->servaddr, sizeof(qm->servaddr)) == -1) {
        perror("connect");
        return -1;
    }

    // Start the timer
    time_t start = time(NULL);

    // Send data to the server
    while (time(NULL) - start < qm->duration) {
        char *data = "Hello, world!";
        int len = strlen(data);
        if (send(qm->sockfd, data, len, 0) == -1) {
            perror("send");
            return -1;
        }
        sleep(qm->interval);
    }

    // Close the socket
    close(qm->sockfd);
    qm->sockfd = -1;

    return 0;
}

// Print the QoS monitor results
void qos_monitor_print_results(QoSMonitor *qm) {
    printf("QoS Monitor Results:\n");
    printf("  Host: %s\n", qm->host);
    printf("  Port: %d\n", qm->port);
    printf("  TOS: %d\n", qm->tos);
    printf("  Interval: %d seconds\n", qm->interval);
    printf("  Duration: %d seconds\n", qm->duration);
}

// Main function
int main(int argc, char **argv) {
    if (argc < 5) {
        printf("Usage: %s <host> <port> <tos> <interval> <duration>\n", argv[0]);
        return 1;
    }

    // Create a QoS monitor
    QoSMonitor *qm = qos_monitor_new(argv[1], atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));

    // Start the QoS monitor
    if (qos_monitor_start(qm) == -1) {
        perror("qos_monitor_start");
        return 1;
    }

    // Print the QoS monitor results
    qos_monitor_print_results(qm);

    // Destroy the QoS monitor
    qos_monitor_destroy(qm);

    return 0;
}