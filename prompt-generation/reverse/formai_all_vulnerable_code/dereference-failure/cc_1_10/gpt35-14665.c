//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#define BUFSIZE 1024
#define TIMEOUT 10

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server_addr;
    struct timeval tv;
    fd_set rfds;
    int retval, bytes_sent, bytes_recv;
    char buf[BUFSIZE];

    if(argc != 3)
    {
        printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(1);
    }

    if((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        perror("socket");
        exit(1);
    }

    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if(inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0)
    {
        perror("inet_pton");
        exit(1);
    }

    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    printf("\nEnter the message to send to server...\n");
    fgets(buf, BUFSIZE-1, stdin);
    bytes_sent = send(sock, buf, strlen(buf), 0);
    if(bytes_sent < 0)
    {
        perror("send");
        exit(1);
    }
    printf("%d bytes sent to server: %s\n", bytes_sent, buf);

    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    FD_ZERO(&rfds);
    FD_SET(sock, &rfds);

    retval = select(sock+1, &rfds, NULL, NULL, &tv);
    if(retval == -1)
    {
        perror("select");
        exit(1);
    }
    else if(retval == 0)
    {
        printf("Timeout occurred\n");
        close(sock);
        exit(1);
    }

    if(FD_ISSET(sock, &rfds))
    {
        bytes_recv = recv(sock, buf, BUFSIZE-1, 0);
        if(bytes_recv < 0)
        {
            perror("recv");
            close(sock);
            exit(1);
        }
        buf[bytes_recv] = '\0';
        printf("%d bytes received from server: %s\n", bytes_recv, buf);
    }

    close(sock);

    return 0;
}