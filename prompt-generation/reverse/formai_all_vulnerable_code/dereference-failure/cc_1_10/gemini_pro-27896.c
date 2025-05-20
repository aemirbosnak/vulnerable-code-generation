//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <ip address> <port number> <filename>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);
    char *filename = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_number);
    serv_addr.sin_addr.s_addr = inet_addr(ip_address);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror("fopen");
        exit(1);
    }

    char buffer[1024];
    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        int n = read(sockfd, buffer, sizeof(buffer));
        if (n <= 0)
        {
            break;
        }
        fprintf(fp, "%s", buffer);
    }

    fclose(fp);
    close(sockfd);

    return 0;
}