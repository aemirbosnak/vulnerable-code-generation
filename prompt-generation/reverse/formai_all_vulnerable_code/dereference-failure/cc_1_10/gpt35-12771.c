//FormAI DATASET v1.0 Category: Network Ping Test ; Style: grateful
/*  
    Grateful Ping Test
    By: Your Name
    
    This program tests the connection to a remote server by sending ICMP packets via network sockets.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define PACKET_SIZE 64 
#define PORT_NO 0 
#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0

int send_packet(int sock_id, char* ip_address, int ttl) {
    
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(PORT_NO);
    dest_addr.sin_addr.s_addr = inet_addr(ip_address);
    setsockopt(sock_id, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl));

    char send_buf[PACKET_SIZE], recv_buf[PACKET_SIZE];
    memset(send_buf, '\0', PACKET_SIZE);
    memset(recv_buf, '\0', PACKET_SIZE);

    struct icmphdr *icmp_header = (struct icmphdr *) send_buf;
    icmp_header->type = ICMP_ECHO_REQUEST;
    icmp_header->code = 0;
    icmp_header->checksum = 0;
    icmp_header->un.echo.id = htons(getpid());
    icmp_header->un.echo.sequence = htons(1);

    int ret = sendto(sock_id, send_buf, PACKET_SIZE, 0, (struct sockaddr *) &dest_addr, sizeof(dest_addr));
    if (ret < 0) {
        fprintf(stderr, "Packet send error: %s\n", strerror(errno));
        return 0;
    }
    
    struct sockaddr_in recv_addr;
    socklen_t addr_len = sizeof(recv_addr);

    ret = recvfrom(sock_id, recv_buf, PACKET_SIZE, 0, (struct sockaddr *) &recv_addr, &addr_len);
    if (ret < 0) {
        fprintf(stderr, "Packet receive error: %s\n", strerror(errno));
        return 0;
    }

    struct icmphdr *recv_icmp_header = (struct icmphdr *) recv_buf;
    if (recv_icmp_header->type == ICMP_ECHO_REPLY) {
        printf("Response from %s, ttl=%d\n", ip_address, ttl);
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname or IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* ip_address = argv[1];
    struct hostent *h;
    if ((h = gethostbyname(ip_address)) == NULL) {
        fprintf(stderr, "Unable to resolve hostname: %s\n", hstrerror(h_errno));
        return EXIT_FAILURE;
    }

    printf("Pinging %s [%s]:\n", h->h_name, inet_ntoa(*((struct in_addr *) h->h_addr_list[0])));

    int sock_id = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock_id < 0) {
        fprintf(stderr, "Socket creation error: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    for (int ttl = 1; ttl <= 30; ttl++) {
        setuid(getuid());
        if (send_packet(sock_id, ip_address, ttl)) {
            break;
        }
    }

    close(sock_id);
    return EXIT_SUCCESS;
}