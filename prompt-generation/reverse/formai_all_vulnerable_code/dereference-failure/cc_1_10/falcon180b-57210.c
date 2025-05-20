//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sock, ret;
    struct sockaddr_in server_addr;
    char *ip = argv[1];
    int port = atoi(argv[2]);
    char send_buf[BUF_SIZE];
    char recv_buf[BUF_SIZE];
    int send_len, recv_len;
    struct timeval timeout;
    int opt = TRUE;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set socket options
    ret = setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, (void *)&opt, sizeof(opt));
    if (ret == -1)
    {
        printf("Error setting socket option\n");
        exit(1);
    }

    // Set timeout
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    // Connect to server
    ret = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1)
    {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send data
    strcpy(send_buf, "PING");
    send_len = strlen(send_buf);
    ret = send(sock, send_buf, send_len, 0);
    if (ret == -1)
    {
        printf("Error sending data\n");
        exit(1);
    }

    // Receive data
    memset(recv_buf, 0, BUF_SIZE);
    ret = recv(sock, recv_buf, BUF_SIZE, 0);
    if (ret == -1)
    {
        printf("Error receiving data\n");
        exit(1);
    }

    // Display received data
    printf("Received: %s\n", recv_buf);

    // Close socket
    close(sock);

    return 0;
}