//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_DATA 1024

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in server_addr;
    char send_data[MAX_DATA];
    char recv_data[MAX_DATA];
    int data_size;
    int opt = 1;

    if (argc < 3)
    {
        printf("Usage:./ping_test <IP Address> <Port Number>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1)
    {
        printf("Error: Socket creation failed.\n");
        exit(1);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
    {
        printf("Error: Setsockopt failed.\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error: Connection failed.\n");
        exit(1);
    }

    printf("Connection established.\n");

    while (1)
    {
        printf("Enter data to send: ");
        fgets(send_data, MAX_DATA, stdin);
        data_size = strlen(send_data);

        if (send(sockfd, send_data, data_size, 0) == -1)
        {
            printf("Error: Send failed.\n");
            exit(1);
        }

        memset(recv_data, 0, MAX_DATA);
        data_size = recv(sockfd, recv_data, MAX_DATA, 0);

        if (data_size <= 0)
        {
            printf("Error: Receive failed.\n");
            exit(1);
        }

        printf("Received data: %s\n", recv_data);
    }

    close(sockfd);

    return 0;
}