//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_DEVICES 1024
#define MAX_HOPS 256
#define PACKET_SIZE 64

int main(int argc, char *argv[]) {
    const char* usage = "Usage: %s <IP Address>\n";
    if(argc < 2) {
        fprintf(stderr, usage, argv[0]);
        exit(EXIT_FAILURE);
    }

    char *target_ip = argv[1];

    // Initialize sockets
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(sockfd < 0) {
        fprintf(stderr, "Error in socket creation: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    struct timeval timeout = {2, 0};
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(struct timeval));

    struct sockaddr_in destination_addr = {0};
    destination_addr.sin_family = AF_INET;
    inet_pton(AF_INET, target_ip, &destination_addr.sin_addr);

    // Initialize device array
    char device_array[MAX_DEVICES][INET_ADDRSTRLEN];
    struct in_addr ip_addr = {0};
    inet_pton(AF_INET, "127.0.0.1", &ip_addr);

    for(int i = 0; i < MAX_DEVICES; i++) {
        snprintf(device_array[i], INET_ADDRSTRLEN, "%s", inet_ntoa(ip_addr));
        ip_addr.s_addr++;
    }

    // Initialize hops array
    char hops_array[MAX_HOPS][INET_ADDRSTRLEN];

    // Send packets with increasing TTL values
    for(int ttl = 1; ttl <= MAX_HOPS; ttl++) {
        struct timeval start_time;
        gettimeofday(&start_time, NULL);

        for(int i = 0; i < PACKET_SIZE; i++) {
            char msg[PACKET_SIZE] = {0};
            snprintf(msg, PACKET_SIZE, "PING TTL=%d.%d\n", ttl, i);
            int ret = sendto(sockfd, msg, strlen(msg), 0, (struct sockaddr*)&destination_addr, sizeof(destination_addr));
            if(ret < 0) {
                break;
            }
        }

        struct sockaddr_in received_from_addr = {0};
        socklen_t received_from_addr_len = sizeof(received_from_addr);

        // Receive all packets that were sent with this TTL
        while(1) {
            char buf[PACKET_SIZE] = {0};
            int received_bytes = recvfrom(sockfd, buf, PACKET_SIZE, 0, (struct sockaddr*)&received_from_addr, &received_from_addr_len);

            if(received_bytes >= 0 && memcmp(&(received_from_addr.sin_addr), &(destination_addr.sin_addr), sizeof(struct in_addr)) == 0) {
                // If we receive a packet from the destination, add the receiver IP to the device array and break
                snprintf(device_array[sizeof(device_array)/INET_ADDRSTRLEN], INET_ADDRSTRLEN, "%s", inet_ntoa(received_from_addr.sin_addr));
                break;
            }

            if(received_bytes < 0 || received_bytes >= PACKET_SIZE) {
                break;
            }

            if(buf[0] == 'P' && buf[1] == 'I' && buf[2] == 'N' && buf[3] == 'G') {
                // If the packet is a ping packet, add the source IP to the hops array
                snprintf(hops_array[sizeof(hops_array)/INET_ADDRSTRLEN], INET_ADDRSTRLEN, "%s", inet_ntoa(received_from_addr.sin_addr));
            }
        }

        struct timeval end_time;
        gettimeofday(&end_time, NULL);
        int elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000 +
                           (end_time.tv_usec - start_time.tv_usec) / 1000;

        // Output results for this TTL
        printf("%2d: ", ttl);
        if(sizeof(hops_array)/INET_ADDRSTRLEN == 0) {
            printf("*\n");
        } else {
            for(int i = 0; i < sizeof(hops_array)/INET_ADDRSTRLEN; i++) {
                if(strcmp(hops_array[i], "") == 0) {
                    break;
                }
                printf("%s ", hops_array[i]);
            }
            printf(" (%d ms)\n", elapsed_time);
        }

        // Clear hops array for next TTL iteration
        memset(hops_array, 0, sizeof(hops_array));
    }

    // Output device array
    printf("\nDetected devices:\n");
    for(int i = 0; i < sizeof(device_array)/INET_ADDRSTRLEN; i++) {
        if(strcmp(device_array[i], "") == 0) {
            break;
        }
        printf("%s\n", device_array[i]);
    }

    close(sockfd);
    return 0;
}