//FormAI DATASET v1.0 Category: Firewall ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

struct packet {
    int source_ip;
    int dest_ip;
    int source_port;
    int dest_port;
    char payload[1024];
};

int main() {
    int num_packets = 0;
    int num_blocked = 0;
    struct packet *packets = malloc(sizeof(struct packet) * 100);

    printf("Welcome to the Firewall Program!\n\n");

    while (1) {
        printf("Enter packet information (source IP, dest IP, source port, dest port, payload):\n");
        scanf("%d %d %d %d %s", &packets[num_packets].source_ip, &packets[num_packets].dest_ip,
              &packets[num_packets].source_port, &packets[num_packets].dest_port, packets[num_packets].payload);

        // Check if payload contains keyword
        if (strstr(packets[num_packets].payload, "hacker") != NULL || strstr(packets[num_packets].payload, "attack") != NULL) {
            num_blocked++;
            printf("\nBlocked: Packet contains dangerous payload!\n");
        } else {
            printf("\nAccepted: Packet allowed through firewall.\n");
        }

        printf("\n");

        num_packets++;

        // Check if packet limit has been reached
        if (num_packets >= 100) {
            printf("Packet limit reached. Exiting program.\n");
            break;
        }
    }

    printf("Firewall statistics:\n");
    printf("Total Packets: %d\n", num_packets);
    printf("Blocked Packets: %d\n", num_blocked);
    printf("Accepted Packets: %d\n", num_packets - num_blocked);

    free(packets);

    return 0;
}