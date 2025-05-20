//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_HOSTNAME 256
#define MAX_DATAGRAM_SIZE 65535

int main(int argc, char *argv[])
{
    if (argc!= 3)
    {
        fprintf(stderr, "Usage: %s <hostname> <number_of_packets>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char hostname[MAX_HOSTNAME];
    strcpy(hostname, argv[1]);

    int num_packets = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);

    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0)
    {
        fprintf(stderr, "Invalid hostname\n");
        exit(EXIT_FAILURE);
    }

    int packet_size = MAX_DATAGRAM_SIZE;
    char *data = malloc(packet_size);
    memset(data, 'A', packet_size);

    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 0;

    for (int i = 0; i < num_packets; i++)
    {
        sendto(sock, data, packet_size, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

        // Set timeout for 1 second
        setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv));

        char buffer[MAX_DATAGRAM_SIZE];
        int len = recvfrom(sock, buffer, MAX_DATAGRAM_SIZE, 0, NULL, NULL);

        if (len > 0)
        {
            printf("Received response of length %d\n", len);
        }
        else
        {
            if (errno == ETIMEDOUT)
            {
                printf("No response received\n");
            }
            else
            {
                perror("recvfrom");
            }
        }
    }

    close(sock);
    free(data);

    return 0;
}