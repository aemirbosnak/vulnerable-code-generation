//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_NODES 10

// QoS metric structure
typedef struct {
    int node_id;
    double latency;
    double jitter;
    double packet_loss;
} qos_metric_t;

// Node structure
typedef struct {
    int node_id;
    struct sockaddr_in addr;
} node_t;

// QoS monitor data structure
typedef struct {
    node_t nodes[MAX_NODES];
    int num_nodes;
    qos_metric_t metrics[MAX_NODES];
} qos_monitor_t;

// Create a new QoS monitor
qos_monitor_t* qos_monitor_create() {
    qos_monitor_t* monitor = malloc(sizeof(qos_monitor_t));
    memset(monitor, 0, sizeof(qos_monitor_t));
    return monitor;
}

// Add a node to the QoS monitor
void qos_monitor_add_node(qos_monitor_t* monitor, int node_id, char* ip, int port) {
    if (monitor->num_nodes >= MAX_NODES) {
        return;
    }

    monitor->nodes[monitor->num_nodes].node_id = node_id;
    monitor->nodes[monitor->num_nodes].addr.sin_family = AF_INET;
    monitor->nodes[monitor->num_nodes].addr.sin_addr.s_addr = inet_addr(ip);
    monitor->nodes[monitor->num_nodes].addr.sin_port = htons(port);
    monitor->num_nodes++;
}

// Send QoS measurement messages to all nodes
void qos_monitor_send_messages(qos_monitor_t* monitor) {
    int i;

    for (i = 0; i < monitor->num_nodes; i++) {
        int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (sockfd < 0) {
            perror("socket");
            continue;
        }

        struct timeval tv;
        tv.tv_sec = 1;
        tv.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

        // Send a measurement message to the node
        char message[1024];
        sprintf(message, "MEASUREMENT %d", monitor->nodes[i].node_id);
        sendto(sockfd, message, strlen(message), 0, (struct sockaddr*)&monitor->nodes[i].addr, sizeof(monitor->nodes[i].addr));

        close(sockfd);
    }
}

// Receive QoS measurement responses from nodes
void qos_monitor_receive_responses(qos_monitor_t* monitor) {
    int i;

    for (i = 0; i < monitor->num_nodes; i++) {
        int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (sockfd < 0) {
            perror("socket");
            continue;
        }

        struct timeval tv;
        tv.tv_sec = 1;
        tv.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

        // Bind the socket to the node's address
        if (bind(sockfd, (struct sockaddr*)&monitor->nodes[i].addr, sizeof(monitor->nodes[i].addr)) < 0) {
            perror("bind");
            close(sockfd);
            continue;
        }

        // Receive a measurement response from the node
        char message[1024];
        socklen_t addrlen = sizeof(monitor->nodes[i].addr);
        int n = recvfrom(sockfd, message, sizeof(message), 0, (struct sockaddr*)&monitor->nodes[i].addr, &addrlen);
        if (n < 0) {
            perror("recvfrom");
            close(sockfd);
            continue;
        }

        // Parse the measurement response
        sscanf(message, "RESPONSE %d %lf %lf %lf", &monitor->metrics[i].node_id, &monitor->metrics[i].latency, &monitor->metrics[i].jitter, &monitor->metrics[i].packet_loss);

        close(sockfd);
    }
}

// Print the QoS metrics
void qos_monitor_print_metrics(qos_monitor_t* monitor) {
    int i;

    for (i = 0; i < monitor->num_nodes; i++) {
        printf("Node %d: latency=%lf, jitter=%lf, packet_loss=%lf\n",
               monitor->metrics[i].node_id, monitor->metrics[i].latency, monitor->metrics[i].jitter, monitor->metrics[i].packet_loss);
    }
}

// Destroy the QoS monitor
void qos_monitor_destroy(qos_monitor_t* monitor) {
    free(monitor);
}

int main() {
    // Create a QoS monitor
    qos_monitor_t* monitor = qos_monitor_create();

    // Add nodes to the QoS monitor
    qos_monitor_add_node(monitor, 1, "192.168.1.1", 1234);
    qos_monitor_add_node(monitor, 2, "192.168.1.2", 1234);
    qos_monitor_add_node(monitor, 3, "192.168.1.3", 1234);

    // Send QoS measurement messages to all nodes
    qos_monitor_send_messages(monitor);

    // Receive QoS measurement responses from nodes
    qos_monitor_receive_responses(monitor);

    // Print the QoS metrics
    qos_monitor_print_metrics(monitor);

    // Destroy the QoS monitor
    qos_monitor_destroy(monitor);

    return 0;
}