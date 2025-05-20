//FormAI DATASET v1.0 Category: Network Ping Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netinet/udp.h>
#include <netinet/ip.h>
#include <netinet/if_ether.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

unsigned short checksum (unsigned short *buf, int bufsz) {
    unsigned long sum = 0;
    while (bufsz > 1) {
        sum += *buf++;
        bufsz -= 2;
    }
    if (bufsz == 1) {
        sum += *(unsigned char*)buf;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return ~sum;
}

char* dnslookup(char* hostaddress) {
    struct sockaddr_in server_addr;
    struct hostent* hp;
    server_addr.sin_family = AF_INET;
    hp = gethostbyname(hostaddress);
    if (hp == NULL) {
        return NULL;
    }
    memcpy(&server_addr.sin_addr, hp->h_addr_list[0], hp->h_length);
    return inet_ntoa(server_addr.sin_addr);
}

int main(int argc, char* argv[]) {

    if(argc < 2 || argc > 4) {
        printf("Invalid usage. Please provide host name or address.\n");
        return -1;
    }

    int sock;
    char *host;
    if (isdigit(argv[1][0])) {
        host = argv[1];
    } else {
        host = dnslookup(argv[1]);
        if (host == NULL) {
            printf("Unable to lookup DNS for provided host name");
            return -1;
        }
    }

    sock = socket(PF_INET, SOCK_RAW, IPPROTO_UDP);
    if(sock < 0) {
        printf("Unable to create socket");
        return -1;
    }

    struct sockaddr_in server_addr;
    int flag;

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    const char *message = "Ping Test";
    int message_len = strlen(message);

    unsigned char *packet = (unsigned char *) calloc(4096, sizeof(unsigned char));

    struct udphdr *udpheader = (struct udphdr *) (packet + sizeof(struct iphdr));

    int seq_no = 0;
    int packet_size = sizeof(struct iphdr) + sizeof(struct udphdr) + message_len;

    while(TRUE) {
        // IP Header
        struct iphdr *ipheader = (struct iphdr *) packet;
        ipheader->ihl = 5;
        ipheader->version = 4;
        ipheader->tos = 16;
        ipheader->id = htons(54321);
        ipheader->ttl = 64;
        ipheader->protocol = IPPROTO_UDP;
        ipheader->saddr = inet_addr("192.168.0.20");
        ipheader->daddr = server_addr.sin_addr.s_addr;
        ipheader->tot_len = packet_size;
        ipheader->check = checksum((unsigned short *) packet, ipheader->tot_len);
      
        // UDP Header
        udpheader->source = htons(56789);
        udpheader->dest = htons(33434);
        udpheader->len = htons(sizeof(struct udphdr) + message_len);
        udpheader->check = 0;

        // Ping message
        memcpy(packet + sizeof(struct iphdr) + sizeof(struct udphdr), message, message_len);

        // send packet
        sendto(sock, packet, packet_size, 0, (struct sockaddr *) &server_addr, sizeof(server_addr));
        printf("Ping sent to %s\n", host);

        //receive packet
        unsigned char *buffer = (unsigned char *) calloc(4096, sizeof(unsigned char));
        struct sockaddr_in sender_addr;
        socklen_t sender_addr_len;
        sender_addr_len = sizeof(sender_addr);
        recvfrom(sock, buffer, 4096, 0, (struct sockaddr *) &sender_addr, &sender_addr_len);
        printf("Ping received from %s\n", inet_ntoa(sender_addr.sin_addr));

        // Free allocated memory
        free(buffer);

        // Pause for 1 second
        sleep(1);
    }

    // Free allocated memory
    free(packet);

    // close the socket
    close(sock);

    return 0;
}