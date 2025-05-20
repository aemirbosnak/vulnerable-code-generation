//FormAI DATASET v1.0 Category: Firewall ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<netinet/tcp.h>
#include<sys/socket.h>

#define IP_HEADER_LEN 20
#define TCP_HEADER_LEN 20

char *blockedIPs[] = {"10.0.0.1", "192.168.1.1", "172.16.0.1"};
char *blockedDomains[] = {"example.com", "google.com", "facebook.com"};
int numBlockedIPs = 3;
int numBlockedDomains = 3;

// Function declaration
int checkBlockedIP(char *ip);
int checkBlockedDomain(char *domain);
void processPacket(unsigned char* buffer, int size);

int main()
{
    int sock_raw;
    socklen_t saddr_size;
    struct sockaddr saddr;

    unsigned char *buffer = (unsigned char *)malloc(65536);

    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);

    if (sock_raw < 0) {
        printf("Error creating socket. Exiting...");
        return -1;
    }

    while (1)
    {
        saddr_size = sizeof(saddr);
        int rx_len = recvfrom(sock_raw, buffer, 65536, 0, &saddr, &saddr_size);
        if (rx_len < 0) {
            printf("Receive failed. Exiting...");
            return -1;
        }
        processPacket(buffer, rx_len);
    }

    close(sock_raw);

    return 0;
}

void processPacket(unsigned char* buffer, int size)
{
    struct iphdr *iph = (struct iphdr*)buffer;

    if (iph->protocol == IPPROTO_TCP) {

        struct tcphdr *tcph = (struct tcphdr*)(buffer + IP_HEADER_LEN);

        int srcPort = ntohs(tcph->source);

        if (srcPort == 80 || srcPort == 443) { // Check only for HTTP(s) traffic

            char *domain = "";
            char ip[16];

            // Get IP address from packet
            struct sockaddr_in dest_addr;
            dest_addr.sin_addr.s_addr = iph->daddr;
            sprintf(ip, "%s", inet_ntoa(dest_addr.sin_addr));

            if (checkBlockedIP(ip)) {
                printf("Blocked IP address found: %s\n", ip);
                return;
            }

            // Get domain name from packet
            char *http_data = (char*)(buffer + IP_HEADER_LEN + TCP_HEADER_LEN);
            int data_size = size - (IP_HEADER_LEN + TCP_HEADER_LEN);
            char *http_request = strndup(http_data, data_size);
            char *start = strstr(http_request, "Host: ");
            if (start != NULL) {
                start += 6;
                char *end = strstr(start, "\r\n");
                if (end != NULL) {
                    int len = end - start;
                    domain = strndup(start, len);
                }
            }
            free(http_request);

            if (checkBlockedDomain(domain)) {
                printf("Blocked domain name found: %s\n", domain);
                return;
            }
        }
    }
}

int checkBlockedIP(char *ip)
{
    int i;
    for (i = 0; i < numBlockedIPs; i++) {
        if (strcmp(ip, blockedIPs[i]) == 0){
            return 1;
        }
    }
    return 0;
}

int checkBlockedDomain(char *domain)
{
    int i;
    for (i = 0; i < numBlockedDomains; i++) {
        if (strstr(domain, blockedDomains[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}