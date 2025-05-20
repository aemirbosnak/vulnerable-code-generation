//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 65535
#define TRUE 1
#define FALSE 0
#define DEBUG FALSE

int main(int argc, char *argv[])
{
    int sock, port, valread, sd;
    struct sockaddr_in serv_addr;
    char buffer[1025];
    int addrlen = sizeof(serv_addr);

    if(argc!= 3)
    {
        printf("Usage :./port_scanner <IP Address> <Port Number>\n");
        exit(0);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == -1)
    {
        perror("socket failed");
        exit(errno);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));

    if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0)
    {
        printf("Invalid address/ Address not supported\n");
        exit(0);
    }

    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        close(sock);
        exit(0);
    }

    printf("Port %s is open\n", argv[2]);

    close(sock);
    exit(0);
}