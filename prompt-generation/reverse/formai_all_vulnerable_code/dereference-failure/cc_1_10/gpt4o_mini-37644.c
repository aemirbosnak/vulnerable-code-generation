//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_PINGS 5
#define BUFFER_SIZE 64

void ping(const char *ip, int count) {
    struct sockaddr_in addr;
    char buffer[BUFFER_SIZE];
    struct timeval start, end;
    int packet_loss = 0;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0); // No port needed for ICMP
    inet_pton(AF_INET, ip, &addr.sin_addr);

    printf("Pinging %s:\n", ip);

    for (int i = 0; i < count; i++) {
        gettimeofday(&start, NULL);

        // Send ICMP Echo Request
        sprintf(buffer, "ping %s -c 1 -W 1 > /dev/null", ip);
        int result = system(buffer);

        gettimeofday(&end, NULL);
        
        long elapsed_time = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000; // RTT in ms
        
        if (result == 0) {
            printf("Reply from %s: bytes=64 time=%ldms\n", ip, elapsed_time);
        } else {
            printf("Request timed out for %s\n", ip);
            packet_loss++;
        }
        
        sleep(1); // Wait 1 second before the next ping
    }

    float loss_percentage = (float)packet_loss / count * 100;
    printf("\n--- %s Ping Statistics ---\n", ip);
    printf("%d packets transmitted, %d packets received, %.1f%% packet loss\n", count, count - packet_loss, loss_percentage);
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s <IP_ADDRESS> <NUMBER_OF_PINGS>\n", argv[0]);
        return 1;
    }
    
    const char *ip_address = argv[1];
    int number_of_pings = atoi(argv[2]);

    if (number_of_pings < 1 || number_of_pings > MAX_PINGS) {
        printf("Please enter a valid number of pings (1 to %d).\n", MAX_PINGS);
        return 1;
    }

    ping(ip_address, number_of_pings);
    return 0;
}