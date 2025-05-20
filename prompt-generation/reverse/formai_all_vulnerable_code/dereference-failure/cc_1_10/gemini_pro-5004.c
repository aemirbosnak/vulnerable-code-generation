//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: visionary
// Aeon Vigilant, an AI-Driven Intrusion Detection System of the Future

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

enum AlertSeverity { LOW, MEDIUM, HIGH, CRITICAL };

struct Intrusion {
    char *src_ip;
    char *src_port;
    char *dest_ip;
    char *dest_port;
    char *attack_type;
    enum AlertSeverity severity;
};

struct NetworkMonitor {
    int sockfd;
    struct sockaddr_in server_addr;
    socklen_t addr_len;
};

// AI Engine for Intrusion Analysis
int analyze_intrusion(struct Intrusion *intrusion) {
    int risk_score = 0;

    // Evaluate source IP reputation
    if (strlen(intrusion->src_ip) < 10 || strlen(intrusion->src_ip) > 15) {
        risk_score += 5;
    }

    if (strcmp(intrusion->src_port, "22") == 0 || strcmp(intrusion->src_port, "23") == 0) {
        risk_score += 3;
    }

    if (strcmp(intrusion->dest_port, "3389") == 0 || strcmp(intrusion->dest_port, "445") == 0) {
        risk_score += 7;
    }

    if (strcmp(intrusion->attack_type, "Port Scan") == 0 || strcmp(intrusion->attack_type, "Brute Force") == 0) {
        risk_score += 10;
    }

    // Determine alert severity based on risk score
    if (risk_score < 10) {
        intrusion->severity = LOW;
    } else if (risk_score >= 10 && risk_score < 20) {
        intrusion->severity = MEDIUM;
    } else if (risk_score >= 20 && risk_score < 30) {
        intrusion->severity = HIGH;
    } else {
        intrusion->severity = CRITICAL;
    }

    return risk_score;
}

// Network Monitoring Thread
void *network_monitor(void *arg) {
    struct NetworkMonitor *monitor = (struct NetworkMonitor *)arg;
    char buffer[2048];

    while (1) {
        recvfrom(monitor->sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&monitor->server_addr, &monitor->addr_len);

        struct Intrusion intrusion;
        sscanf(buffer, "%s %s %s %s %s", intrusion.src_ip, intrusion.src_port, intrusion.dest_ip, intrusion.dest_port, intrusion.attack_type);

        int risk_score = analyze_intrusion(&intrusion);

        if (intrusion.severity == LOW) {
            printf("[Info] Low severity intrusion detected from %s:%s.\n", intrusion.src_ip, intrusion.src_port);
        } else if (intrusion.severity == MEDIUM) {
            printf("[Warning] Medium severity intrusion detected from %s:%s.\n", intrusion.src_ip, intrusion.src_port);
        } else if (intrusion.severity == HIGH) {
            printf("[Alert] High severity intrusion detected from %s:%s.\n", intrusion.src_ip, intrusion.src_port);
        } else {
            printf("[Critical] Critical severity intrusion detected from %s:%s.\n", intrusion.src_ip, intrusion.src_port);
        }
    }

    pthread_exit(NULL);
}

int main() {
    struct NetworkMonitor monitor;

    if ((monitor.sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket() failed");
        return EXIT_FAILURE;
    }

    monitor.server_addr.sin_family = AF_INET;
    monitor.server_addr.sin_addr.s_addr = INADDR_ANY;
    monitor.server_addr.sin_port = htons(5000);
    monitor.addr_len = sizeof(monitor.server_addr);

    if (bind(monitor.sockfd, (struct sockaddr *)&monitor.server_addr, monitor.addr_len) < 0) {
        perror("bind() failed");
        return EXIT_FAILURE;
    }

    pthread_t tid;
    pthread_create(&tid, NULL, network_monitor, &monitor);
    pthread_join(tid, NULL);

    close(monitor.sockfd);
    return EXIT_SUCCESS;
}