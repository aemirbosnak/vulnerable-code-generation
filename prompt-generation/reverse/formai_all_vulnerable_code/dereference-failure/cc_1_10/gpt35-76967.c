//FormAI DATASET v1.0 Category: Port Scanner ; Style: secure
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#define TIMEOUT 2                                     //Timeout for connection establishment
#define MAX_PORT_NUM 65535                           //Maximum number of ports to scan

int main(int argc, char *argv[])
{
    int sockfd, port, scan_start = 1, scan_end = MAX_PORT_NUM;
    char *host, *protocol = "tcp";                   //TCP protocol by default
    struct sockaddr_in server_address;
    struct timeval timeout;                         //Timeout structure for socket operations
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    if(argc < 2)
    {
        printf("\nUsage: %s hostname [startport] [endport] [tcp/udp]\n", argv[0]);
        printf("\nDefaults: startport = 1, endport = 65535, protocol = TCP\n");
        exit(1);
    }

    host = argv[1];

    if(argc >= 3)
    {
        scan_start = atoi(argv[2]);
    }

    if(argc >= 4)
    {
        scan_end = atoi(argv[3]);
    }

    if(argc >= 5)
    {
        protocol = argv[4];
    }

    if(strcmp(protocol, "tcp") != 0 && strcmp(protocol, "udp") != 0)
    {
        printf("\nInvalid protocol. Please specify either TCP or UDP.\n");
        exit(1);
    }

    printf("\nScanning host %s for open %s ports from %d to %d:\n\n", host, protocol, scan_start, scan_end);

    for(port=scan_start; port <= scan_end; port++)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        if(sockfd < 0)
        {
            perror("\nError creating socket.");
            exit(1);
        }

        memset(&server_address, 0, sizeof(server_address)); //Initializing server address structure
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(port);
        server_address.sin_addr.s_addr = inet_addr(host); //Converting hostname to IP address

        setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout)); //Setting socket options for timeout
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

        if(connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) == 0) //Trying to establish connection
        {
            printf("Port %d - open\n", port);
            close(sockfd); //Closing socket if connection successful
        }
    }

    printf("\nScan complete.\n");
    
    return 0;
}