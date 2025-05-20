//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>

#define MAX_PACKET_SIZE 1024
#define TIMEOUT_SECS 5

// Let's create our trusty ping function.
int ping(const char *host) {
    // First, we need a socket to send our packets.
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Now, let's create the address we're going to send the packets to.
    struct hostent *he;
    he = gethostbyname(host);
    if (he == NULL) {
        herror("gethostbyname");
        return -1;
    }

    // Time to set up the socket address structure.
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80); // Let's use the venerable port 80.
    memcpy(&servaddr.sin_addr, he->h_addr, he->h_length);

    // Let's prepare a buffer to hold our packet.
    char packet[MAX_PACKET_SIZE];
    memset(packet, 0, sizeof(packet));

    // Time to start the ping-pong game.
    int sent_count = 0;
    int received_count = 0;

    while (sent_count < 10) { // Let's send 10 packets.
        // First, let's send a packet.
        if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
            perror("sendto");
            return -1;
        }

        // Now, let's wait for a response.
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        struct timeval timeout;
        timeout.tv_sec = TIMEOUT_SECS;
        timeout.tv_usec = 0;
        int select_result = select(sockfd + 1, &readfds, NULL, NULL, &timeout);
        if (select_result > 0) { // We got a response!
            received_count++;
        }

        // Let's take a break for a bit.
        sleep(1);

        // Increment the sent count.
        sent_count++;
    }

    // Time to close the socket and wrap up.
    close(sockfd);

    // Let's calculate the packet loss percentage.
    float packet_loss = (1.0 - (float)received_count / (float)sent_count) * 100.0;

    // And finally, let's print the results.
    printf("Ping results for %s:\n", host);
    printf("Sent: %d, Received: %d, Packet loss: %.2f%%\n", sent_count, received_count, packet_loss);

    // And that's it! We've pinged the host and displayed the results.
    return 0;
}

// Now, let's create a calming main function.
int main(int argc, char *argv[]) {
    // Let's make sure we have a host to ping.
    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    // And finally, let's do the pinging.
    ping(argv[1]);

    // All done! Let's return with a gentle touch.
    return 0;
}