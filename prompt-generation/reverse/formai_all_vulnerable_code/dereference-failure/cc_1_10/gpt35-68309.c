//FormAI DATASET v1.0 Category: Port Scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to check if a given port is open or not
void check_port(char *ip_addr, int port_num)
{
    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1)
    {
        printf("Could not create socket\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_addr);
    serv_addr.sin_port = htons(port_num);

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0)
    {
        printf("[+] Port %d is open\n", port_num);
    }
    close(sockfd);
}

// Main function to scan ports
int main(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("Usage: %s <ip_address> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    char *ip_addr = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if(start_port < 1 || end_port > 65535 || start_port > end_port)
    {
        printf("Invalid port range\n");
        return 1;
    }

    printf("Scanning %s from port %d to %d\n", ip_addr, start_port, end_port);

    for(int i = start_port; i <= end_port; i++)
    {
        check_port(ip_addr, i);
    }

    printf("Port scan completed\n");

    return 0;
}