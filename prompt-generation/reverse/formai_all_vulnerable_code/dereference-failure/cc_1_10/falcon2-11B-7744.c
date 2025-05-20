//Falcon2-11B DATASET v1.0 Category: Wireless Network Scanner ; Style: excited
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    struct hostent *host;
    struct sockaddr_in addr;
    char ip_address[NI_MAXHOST];
    int sockfd, n;
    char* ssid = "SSID";

    if (argc!= 2) {
        fprintf(stderr, "usage: %s ssid\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    if (inet_ntop(AF_INET, &addr.sin_addr, ip_address, NI_MAXHOST) == NULL) {
        perror("inet_ntop");
        exit(1);
    }

    if (gethostbyname(ssid) == NULL) {
        fprintf(stderr, "Invalid SSID\n");
        exit(1);
    }

    host = gethostbyname(ssid);

    if (host == NULL) {
        fprintf(stderr, "Invalid SSID\n");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    addr.sin_addr = *(struct in_addr *)host->h_addr;

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    printf("Listening for wireless network scanner...\n");

    while (1) {
        n = recvfrom(sockfd, ip_address, NI_MAXHOST, 0, NULL, NULL);

        if (n < 0) {
            perror("recvfrom");
            exit(1);
        }

        printf("Received: %s\n", ip_address);
    }

    return 0;
}