//FormAI DATASET v1.0 Category: Network Ping Test ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

#define PACKETSIZE 64

// Function to calculate the checksum of the packet
unsigned short calculateChecksum(void *addr, int len)
{
    int nleft = len;
    int sum = 0;
    unsigned short *w = addr;
    unsigned short answer = 0;

    while (nleft > 1)
    {
        sum += *w++;
        nleft -= 2;
    }

    if (nleft == 1)
    {
        *(unsigned char *)(&answer) = *(unsigned char *)w;
        sum += answer;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = ~sum;

    return answer;
}

// Function to send the ping packet to the server
void sendPing(int sockfd, struct sockaddr_in *recipient, int seq)
{
    char packet[PACKETSIZE] = {0};
    struct timeval tv;

    // Fill the packet with default values
    memset(packet, 0, PACKETSIZE);

    packet[0] = 0x08;   // ICMP Echo Request
    packet[1] = 0;      // ICMP Code
    *(unsigned short *)&packet[4] = htons(seq);  // ICMP Sequence Number
    *(unsigned short *)&packet[6] = calculateChecksum(&packet, PACKETSIZE); // Calculate the Checksum

    sendto(sockfd, packet, PACKETSIZE, 0, (struct sockaddr *)recipient, sizeof(*recipient));
}

// Function to receive the ping response from the server
int receivePing(int sockfd, struct sockaddr_in *recipient, int seq, struct timeval *timeout)
{
    char packet[PACKETSIZE] = {0};
    fd_set readfds;
    struct timeval tv;
    int ret = 0;
    int len = sizeof(*recipient);

    // Initialize the readfds set
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    // Set the timeout value
    tv.tv_sec = timeout->tv_sec;
    tv.tv_usec = timeout->tv_usec;

    // Wait for the response from the server
    ret = select(sockfd+1, &readfds, NULL, NULL, &tv);

    if (ret < 0)
        return ret;

    if (FD_ISSET(sockfd, &readfds))
    {
        // Receive the response from the server
        ret = recvfrom(sockfd, packet, PACKETSIZE, 0, (struct sockaddr *)recipient, &len);

        if (ret == PACKETSIZE && packet[0] == 0x00 && packet[1] == 0)
        {
            if (*(unsigned short *)&packet[6] == calculateChecksum(&packet, PACKETSIZE))
            {
                if (*(unsigned short *)&packet[4] == htons(seq))
                    return 1;
            }
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in recipient;
    struct hostent *host;
    struct timeval timeout;

    if (argc != 2)
    {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    // Lookup the IP address of the host
    host = gethostbyname(argv[1]);

    if (host == NULL)
    {
        printf("Could not resolve hostname: %s\n", argv[1]);
        return 1;
    }

    memset(&recipient, 0, sizeof(recipient));

    recipient.sin_family = AF_INET;
    recipient.sin_addr = *((struct in_addr *)host->h_addr);
    recipient.sin_port = htons(0);

    // Create the socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (sockfd < 0)
    {
        printf("Could not create socket.\n");
        return 1;
    }

    // Set the timeout value for the socket
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    printf("Ping Test started for %s\n", argv[1]);

    for (int seq=1; seq<=10; seq++)
    {
        // Send the ping packet to the server
        sendPing(sockfd, &recipient, seq);

        // Receive the ping response from the server
        int successful = receivePing(sockfd, &recipient, seq, &timeout);

        if (successful)
            printf("Packet number: %d successfully sent and received.\n", seq);
        else
            printf("Packet number: %d failed to send or receive.\n", seq);

        sleep(1);
    }

    // Close the socket
    close(sockfd);

    printf("Ping Test complete.\n");

    return 0;
}