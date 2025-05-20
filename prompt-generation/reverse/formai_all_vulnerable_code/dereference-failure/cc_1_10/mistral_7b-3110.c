//MISTRAL-7B DATASET v1.0 Category: Network Topology Mapper ; Style: funny
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_HOSTS 100
#define MAX_NAME_LENGTH 50
#define PACKET_SIZE 1024

typedef struct {
    char name[MAX_NAME_LENGTH];
    int ip_address;
} host_t;

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s <network>\n", argv[0]);
        return 1;
    }

    int network = inet_addr(argv[1]);

    if (inet_ntop(AF_INET, &network, NULL, sizeof(struct in_addr)) == NULL) {
        perror("Invalid network address");
        return 1;
    }

    printf("\nWelcome to the Hilarious Network Topology Mapper v1.0\n");
    printf("------------------------------------------------------\n");
    printf("Your network address is: %s\n", inet_ntoa(*(struct in_addr *) &network));

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    host_t hosts[MAX_HOSTS];
    int num_hosts = 0;

    printf("\nScanning network for hosts...\n");
    for (int i = 1; i <= 255; i++) {
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(1);
        server_addr.sin_addr.s_addr = htonl(network & htonl(~(1 << (8 + i))));

        char buffer[PACKET_SIZE];
        memset(buffer, 'A', PACKET_SIZE);

        int sent = sendto(sockfd, buffer, PACKET_SIZE, 0, (struct sockaddr *) &server_addr, sizeof(server_addr));

        if (sent > 0) {
            int receive = recvfrom(sockfd, buffer, PACKET_SIZE, 0, NULL, NULL);

            if (receive > 0 && strncmp(buffer, "ping", 3) == 0) {
                strcpy(hosts[num_hosts].name, inet_ntoa(*(struct in_addr *) &server_addr.sin_addr));
                hosts[num_hosts].ip_address = server_addr.sin_addr.s_addr;
                num_hosts++;
            }
        }

        if (num_hosts >= MAX_HOSTS) {
            printf("Maximum number of hosts reached.\n");
            break;
        }

        usleep(50000); // Wait for 50ms before sending next packet
    }

    printf("\nFound %d hosts in your network:\n", num_hosts);
    for (int i = 0; i < num_hosts; i++) {
        printf("\n%s (%d)", hosts[i].name, hosts[i].ip_address);
    }

    close(sockfd);

    return 0;
}