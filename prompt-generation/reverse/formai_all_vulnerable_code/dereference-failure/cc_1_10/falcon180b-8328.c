//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <time.h>

#define MAX_PACKETS 100
#define PACKET_SIZE 64
#define PACKET_INTERVAL 10 // in milliseconds

int main(int argc, char *argv[]) {
    int sock, opt = 1;
    struct sockaddr_in server_addr;
    char buffer[PACKET_SIZE];
    int packet_count = 0;
    int packet_loss = 0;
    int jitter = 0;
    time_t start_time, end_time;
    double elapsed_time;
    struct timeval tv;

    if (argc!= 3) {
        printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    while (packet_count < MAX_PACKETS) {
        gettimeofday(&tv, NULL);
        start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;

        sendto(sock, buffer, PACKET_SIZE, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

        gettimeofday(&tv, NULL);
        end_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;

        elapsed_time = (end_time - start_time) / PACKET_INTERVAL;

        if (elapsed_time > 0) {
            if (elapsed_time > PACKET_INTERVAL) {
                packet_loss++;
            } else {
                jitter += PACKET_INTERVAL - elapsed_time;
            }
        }

        packet_count++;
    }

    close(sock);

    printf("Packets sent: %d\n", packet_count);
    printf("Packet loss: %d%%\n", (int)(packet_loss * 100.0 / packet_count));
    printf("Jitter: %dms\n", (int)(jitter / packet_count));

    return 0;
}