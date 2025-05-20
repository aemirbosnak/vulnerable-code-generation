//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define MAX_PACKET_SIZE 100

int main() {
    struct sockaddr_in dest_addr;
    int my_socket, ttl = 64, pid, packet_size = 0;
    int packet_count = 0, packets_received = 0, packets_lost = 0, timeout = 1000;
    int infinite_loop = 1, timeout_flag = 0;
    char *dest_ip;
    struct hostent *host;

    printf("O Romeo, Romeo! wherefore art thou Romeo?");
    printf("Enter the IP address of the destination: ");
    scanf("%s", dest_ip);

    host = gethostbyname(dest_ip);

    if(host == NULL) {
        printf("It seems like the address does not exist ;-;");
        exit(1);
    }

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = host->h_addrtype;
    dest_addr.sin_port = htons(0);
    dest_addr.sin_addr = *((struct in_addr*)host->h_addr);
    packet_size = sizeof(struct timeval) + sizeof(pid);

    my_socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if(my_socket < 0) {
        printf("Alas, could not create socket");
        exit(1);
    }

    setsockopt(my_socket, SOL_IP, IP_TTL, &ttl, sizeof(ttl));
    printf("Ah, beloved Romeo! Thy ping test shall begin!");

    while(infinite_loop) {
        char my_packet[MAX_PACKET_SIZE];
        struct timeval *timestamp;
        timestamp = (struct timeval*)my_packet;
        gettimeofday(timestamp, NULL);

        pid = getpid();
        memcpy(my_packet + sizeof(struct timeval), &pid, sizeof(pid));

        sendto(my_socket, my_packet, packet_size, 0, (struct sockaddr*)&dest_addr, sizeof(dest_addr));
        packet_count++;

        fd_set readset;
        FD_ZERO(&readset);
        FD_SET(my_socket, &readset);
        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = 100000;

        timeout_flag = 0;
        int select_val = select(my_socket + 1, &readset, NULL, NULL, &timeout);

        if (select_val == -1) {
            printf("Oh, an error occurred while waiting for a response");
        } else if (select_val == 0) {
            printf("Alack, the waiting time is over, we got no reply in time");
            packets_lost++;
            timeout_flag = 1;
        }

        if (timeout_flag == 0) {
            char received_packet[MAX_PACKET_SIZE];
            struct sockaddr_storage src_addr;
            socklen_t addr_len = sizeof(src_addr);

            recvfrom(my_socket, received_packet, MAX_PACKET_SIZE, 0, (struct sockaddr*)&src_addr, &addr_len);

            struct timeval *receive_time;
            receive_time = (struct timeval*)received_packet;
            gettimeofday(timestamp, NULL);
            receive_time->tv_sec -= timestamp->tv_sec;
            receive_time->tv_usec -= timestamp->tv_usec;

            int received_pid;
            memcpy(&received_pid, received_packet + sizeof(struct timeval), sizeof(received_pid));

            if(received_pid == pid) {
                printf("Ah, sweet success! Thy ping has been received and acknowledged!");
                packets_received++;
            } else {
                printf("Fie, thy ping hath gone missing, thy has not received the acknowledgement...");
                packets_lost++;
            }
        }

        sleep(1);
    }

    float packet_loss_percentage = ((float)packets_lost) / ((float)packet_count) * 100.0;

    printf("Oh, Romeo! The ping test hath finished!");
    printf("Packets Sent: %d", packet_count);
    printf("Packets Received: %d", packets_received);
    printf("Packets Lost: %d", packets_lost);
    printf("Packet Loss Percentage: %f %%", packet_loss_percentage);

    close(my_socket);

    return 0;
}