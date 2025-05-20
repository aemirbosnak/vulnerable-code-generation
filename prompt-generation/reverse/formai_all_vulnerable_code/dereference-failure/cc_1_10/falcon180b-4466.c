//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_DATA_SIZE 1024
#define TIMEOUT 5

int main(int argc, char *argv[])
{
    int sock, ret;
    struct sockaddr_in server;
    char send_data[MAX_DATA_SIZE], receive_data[MAX_DATA_SIZE];
    int data_size, total_sent = 0, total_received = 0;
    struct timeval timeout;

    if (argc < 3)
    {
        printf("Usage:./ping <IP Address> <Port Number>\n");
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server.sin_addr);
    server.sin_port = htons(atoi(argv[2]));

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Error creating socket\n");
        return 1;
    }

    ret = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (ret == -1)
    {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    printf("Connected to server\n");

    while (TRUE)
    {
        memset(send_data, 'A', MAX_DATA_SIZE);
        data_size = strlen(send_data);

        ret = send(sock, send_data, data_size, 0);
        if (ret == -1)
        {
            printf("Error sending data\n");
            close(sock);
            return 1;
        }

        total_sent += data_size;

        memset(receive_data, 0, MAX_DATA_SIZE);
        data_size = recv(sock, receive_data, MAX_DATA_SIZE, 0);
        if (data_size == -1)
        {
            printf("Error receiving data\n");
            close(sock);
            return 1;
        }

        total_received += data_size;

        printf("Sent %d bytes, received %d bytes\n", total_sent, total_received);

        if (data_size == 0)
        {
            printf("Connection closed by server\n");
            break;
        }
    }

    close(sock);
    return 0;
}