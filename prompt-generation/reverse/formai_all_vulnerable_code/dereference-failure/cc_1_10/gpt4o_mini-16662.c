//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <time.h>

#define PACKET_COUNT 5
#define TIMEOUT 1
#define PING_SIZE 64

void print_usage(char *program_name) {
    printf("Usage: %s <hostname>\n", program_name);
}

int ping(const char *hostname) {
    struct sockaddr_in addr;
    struct hostent *host;
    char command[100];
    FILE *fp;
    int packet_loss = 0, total_loss = 0, total_time = 0;

    host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    memcpy(&addr.sin_addr.s_addr, host->h_addr, host->h_length);
    
    snprintf(command, sizeof(command), "ping -c %d -W %d -s %d %s", PACKET_COUNT, TIMEOUT, PING_SIZE, hostname);
    
    fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen");
        return -1;
    }
    
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (strstr(buffer, "bytes from")) {
            int time;
            sscanf(buffer, "%*s %*s %*s %*s %*s %*s time=%d", &time);
            total_time += time;
        } else if (strstr(buffer, "packet loss")) {
            sscanf(buffer, "%*s %*s %*d%*[^0-9]%d%%", &packet_loss);
            total_loss = packet_loss;
        }
    }
    
    pclose(fp);

    printf("--- %s ping statistics ---\n", hostname);
    printf("%d packets transmitted, %d packets received, %d%% packet loss\n", PACKET_COUNT, PACKET_COUNT - total_loss, total_loss);
    if (PACKET_COUNT - total_loss > 0) {
        printf("round-trip min/avg/max = %d/%d/%d ms\n", total_time / (PACKET_COUNT - total_loss), total_time / (PACKET_COUNT - total_loss), total_time);
    } else {
        printf("No packets received.\n");
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];

    printf("Pinging %s...\n", hostname);
    if (ping(hostname) == -1) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}