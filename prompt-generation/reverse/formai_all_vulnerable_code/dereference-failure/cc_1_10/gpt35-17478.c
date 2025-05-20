//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ultraprecise
// C Network Quality of Service (QoS) monitor example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define MAX_PACKET_SIZE 4096

// The target IP address and port number
char *target_ip;
int target_port;

// The socket file descriptor
int sock;

// The packet structure
struct packet_t {
    struct timeval send_time;
    struct timeval recv_time;
    int seq_num;
    int error;
};

// The signal handler function
void interrupt_handler(int sig) {
    printf("\nCtrl-C pressed. Exiting...\n");
    close(sock);
    exit(0);
}

// The function to calculate the round-trip time
double rtt(struct timeval *send_time, struct timeval *recv_time) {
    double rtt;
    rtt = (double)(recv_time->tv_sec - send_time->tv_sec) * 1000.0;
    rtt += (double)(recv_time->tv_usec - send_time->tv_usec) / 1000.0;
    return rtt;
}

// The function to send a packet to the target
int send_packet(int seq_num) {
    struct packet_t packet;
    packet.seq_num = seq_num;
    gettimeofday(&packet.send_time, NULL);
    if (sendto(sock, &packet, sizeof(packet), 0, NULL, 0) < 0) {
        perror("ERROR sending packet");
        return -1;
    }
    return 0;
}

// The function to receive a packet from the target
int recv_packet(struct packet_t *packet) {
    fd_set read_fds;
    struct timeval timeout;
    int ret;
    FD_ZERO(&read_fds);
    FD_SET(sock, &read_fds);
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    ret = select(sock + 1, &read_fds, NULL, NULL, &timeout);
    if (ret < 0) {
        perror("ERROR select");
        return -1;
    }
    if (ret == 0) {
        printf("Packet lost\n");
        return -2;
    }
    if (recv(sock, packet, sizeof(struct packet_t), 0) < 0) {
        perror("ERROR receiving packet");
        return -1;
    }
    return 0;
}

// The function to print the result
void print_result(int sent, int received, double min_rtt, double avg_rtt, double max_rtt) {
    printf("\n--- %s ping statistics ---\n", target_ip);
    printf("%d packets transmitted, %d received, %.1f%% packet loss\n", sent, received, (double)(sent - received) / sent * 100.0);
    printf("rtt min/avg/max = %.3f/%.3f/%.3f ms\n\n", min_rtt, avg_rtt, max_rtt);
}

int main(int argc, char *argv[]) {
    struct sockaddr_in target_addr;
    struct hostent *he;
    int i;
    int packet_size = sizeof(struct packet_t);
    int sent = 0;
    int received = 0;
    double min_rtt = -1.0;
    double max_rtt = -1.0;
    double total_rtt = 0.0;
    double avg_rtt = -1.0;

    if (argc != 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return -1;
    }
    target_ip = argv[1];
    target_port = atoi(argv[2]);

    // Create a UDP socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        perror("ERROR opening socket");
        return -1;
    }

    // Fill in the target address structure
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(target_port);
    if ((he = gethostbyname(target_ip)) == NULL) {
        perror("ERROR resolving address");
        return -1;
    }
    memcpy(&target_addr.sin_addr, he->h_addr_list[0], he->h_length);

    // Register the signal handler
    signal(SIGINT, interrupt_handler);

    // Send and receive packets
    while (1) {
        struct packet_t packet;
        int ret;
        // Send a packet
        if (send_packet(sent + 1) < 0) {
            continue;
        }
        sent++;
        // Receive a packet
        ret = recv_packet(&packet);
        if (ret < 0) {
            continue;
        }
        if (packet.seq_num != sent) {
            printf("ERROR: sequence number mismatch\n");
            continue;
        }
        if (packet.error != 0) {
            printf("ERROR: packet error\n");
            continue;
        }
        gettimeofday(&packet.recv_time, NULL);
        printf("Packet received: sequence number=%d, rtt=%.3f ms\n", packet.seq_num, rtt(&packet.send_time, &packet.recv_time));
        if (min_rtt < 0 || rtt(&packet.send_time, &packet.recv_time) < min_rtt) {
            min_rtt = rtt(&packet.send_time, &packet.recv_time);
        }
        if (max_rtt < 0 || rtt(&packet.send_time, &packet.recv_time) > max_rtt) {
            max_rtt = rtt(&packet.send_time, &packet.recv_time);
        }
        total_rtt += rtt(&packet.send_time, &packet.recv_time);
        received++;
        if (sent >= 10) {
            break;
        }
    }

    // Calculate the average round-trip time
    if (received > 0) {
        avg_rtt = total_rtt / received;
    }

    // Print the result
    print_result(sent, received, min_rtt, avg_rtt, max_rtt);

    // Close the socket
    close(sock);

    return 0;
}