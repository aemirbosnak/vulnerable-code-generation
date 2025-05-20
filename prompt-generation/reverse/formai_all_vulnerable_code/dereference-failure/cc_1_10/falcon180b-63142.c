//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define TRUE 1
#define FALSE 0
#define TIMEOUT 5

int main(int argc, char *argv[])
{
    int sockfd, ret, len;
    struct sockaddr_in serv_addr;
    char send_data[MAX_DATA_SIZE];
    char recv_data[MAX_DATA_SIZE];
    struct timeval tv;

    if (argc!= 3)
    {
        printf("Usage:./ping <IP address> <port number>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Error: socket creation failed\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(atoi(argv[2]));

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret == -1)
    {
        printf("Error: connection failed\n");
        exit(1);
    }

    printf("Connected to %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    memset(send_data, 'A', MAX_DATA_SIZE);
    send_data[MAX_DATA_SIZE - 1] = '\0';

    ret = send(sockfd, send_data, MAX_DATA_SIZE, 0);
    if (ret == -1)
    {
        printf("Error: send failed\n");
        exit(1);
    }

    memset(recv_data, 0, MAX_DATA_SIZE);
    ret = recv(sockfd, recv_data, MAX_DATA_SIZE, 0);
    if (ret == -1)
    {
        printf("Error: recv failed\n");
        exit(1);
    }

    printf("Received: %s\n", recv_data);

    close(sockfd);
    return 0;
}