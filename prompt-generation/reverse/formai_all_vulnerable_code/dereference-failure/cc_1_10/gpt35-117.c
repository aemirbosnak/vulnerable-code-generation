//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <time.h>

#define PACKET_SIZE 1024
#define MONITOR_INTERVAL 5

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(0);
    }

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[PACKET_SIZE];
    memset(buffer, 0, PACKET_SIZE);

    portno = 8080;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    int sent_packets = 0;
    int received_packets = 0;
    int lost_packets = 0;
    int total_bits = 0;
    int interval_bits = 0;

    time_t prev_time;
    time_t cur_time;
    double elapsed_time;

    while (1) {
        // Send packet to server
        n = send(sockfd, buffer, strlen(buffer), 0);
        if (n < 0) {
            error("ERROR sending packet");
        }
        sent_packets++;

        // Receive packet from server
        n = recv(sockfd, buffer, PACKET_SIZE, 0);
        if (n < 0) {
            error("ERROR receiving packet");
        }
        received_packets++;
        interval_bits += strlen(buffer);

        // Calculate total bits and lost packets
        total_bits += strlen(buffer);
        lost_packets = sent_packets - received_packets;

        // Monitor interval
        prev_time = time(NULL);
        cur_time = time(NULL);
        elapsed_time = difftime(cur_time, prev_time);
        if (elapsed_time >= MONITOR_INTERVAL) {
            double packet_loss_rate = (double) lost_packets / (double) sent_packets;
            double bandwidth = (double) (interval_bits * 8) / (double) (MONITOR_INTERVAL * 1000000);

            printf("Packet Loss Rate: %.2f\n", packet_loss_rate);
            printf("Bandwidth: %.2f Mbps\n", bandwidth);

            interval_bits = 0;
            prev_time = cur_time;
        }

        // Sleep for one second
        sleep(1);
    }

    close(sockfd);
    return 0;
}