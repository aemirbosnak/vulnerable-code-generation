//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

// Blossoms of Time
typedef struct {
    time_t time;
    int seq;
} Packet;

// Beats of Connectivity
int main(int argc, char *argv[]) {
    // A yearning for an online heart
    if (argc < 3) {
        printf("Whisper me your beloved's address and the cadence of your heartbeats (IP and port)!\n");
        return 1;
    }

    // Strings that hold the ethereal realms
    char *ip_addr = argv[1];
    char *port = argv[2];

    // A socket, our bridge to the digital realm
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Could not establish a connection. Our love is forbidden!");
        return 2;
    }

    // The beacon of our connection
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(port));
    if (inet_pton(AF_INET, ip_addr, &serv_addr.sin_addr) <= 0) {
        perror("Invalid IP address. Is our love lost in the stars?");
        return 3;
    }

    // Declarations of love, encapsulated in packets
    Packet packets[10];
    for (int i = 0; i < 10; i++) {
        packets[i].time = time(NULL);
        packets[i].seq = i + 1;
    }

    // The rhythmic beating of our longing
    for (int i = 0; i < 10; i++) {
        // Sending a kiss across the void
        if (sendto(sockfd, &packets[i], sizeof(Packet), 0, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            perror("Our whispers are lost in the void.");
            return 4;
        }

        // A moment of anticipation, waiting for the echo of our love
        struct sockaddr_in cli_addr;
        socklen_t addrlen = sizeof(cli_addr);
        Packet rec_packet;
        if (recvfrom(sockfd, &rec_packet, sizeof(Packet), MSG_WAITALL, (struct sockaddr *) &cli_addr, &addrlen) < 0) {
            perror("Our hearts long for a response, but it echoes not.");
            continue;
        }

        // Celebrating the reunion of our souls
        printf("A heartbeat echoes, bridging the realms! Sequence: %d, Time: %ld\n", rec_packet.seq, rec_packet.time - packets[i].time);
    }

    // Farewell to the digital embrace, our love eternal
    close(sockfd);
    return 0;
}