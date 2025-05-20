//Falcon2-11B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_STR_LEN 256

int main(int argc, char *argv[])
{
    int sockfd, valread, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_STR_LEN];
    char *ssid;
    char *signal_strength;

    if (argc!= 2)
    {
        fprintf(stderr, "Usage: %s <ssid>\n", argv[0]);
        return 1;
    }

    ssid = argv[1];

    signal_strength = "N/A";

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        perror("socket");
        return 1;
    }

    server = gethostbyname(ssid);
    if (server == NULL)
    {
        fprintf(stderr, "Error, no such host\n");
        return 1;
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(0);

    valread = recvfrom(sockfd, buffer, MAX_STR_LEN, 0, (struct sockaddr *)&serv_addr, &n);
    if (valread <= 0)
    {
        fprintf(stderr, "Error receiving from socket\n");
        return 1;
    }

    printf("Signal strength for %s: %s\n", ssid, buffer);

    return 0;
}