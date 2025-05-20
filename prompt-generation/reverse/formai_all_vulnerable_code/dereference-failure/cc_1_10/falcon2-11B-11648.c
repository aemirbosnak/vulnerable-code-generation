//Falcon2-11B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        printf("Usage: %s <ssid>\n", argv[0]);
        exit(1);
    }

    struct hostent *server;
    struct in_addr *ip_addr;
    struct sockaddr_in sin;
    struct hostent *host;
    int sockfd, bytes_read;
    int packet_size = 256;

    char *ssid = argv[1];

    printf("Connecting to %s...\n", ssid);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &(int){1}, sizeof(int)) < 0)
    {
        perror("ERROR setting broadcast option");
        exit(1);
    }

    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = htonl(INADDR_BROADCAST);
    sin.sin_port = htons(0);

    memset(&sin, 0, sizeof(sin));

    if (bind(sockfd, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        perror("ERROR on bind");
        exit(1);
    }

    printf("Sending probe request...\n");
    bytes_read = sendto(sockfd, ssid, strlen(ssid), 0, (struct sockaddr *)&sin, sizeof(sin));

    if (bytes_read < 0)
    {
        perror("ERROR sending probe request");
        exit(1);
    }

    printf("Waiting for replies...\n");
    char buffer[packet_size];
    int n;

    while ((n = recvfrom(sockfd, buffer, packet_size, 0, NULL, NULL)) > 0)
    {
        printf("Received reply: %s\n", buffer);
    }

    printf("Disconnecting...\n");
    shutdown(sockfd, SHUT_RDWR);
    close(sockfd);

    return 0;
}