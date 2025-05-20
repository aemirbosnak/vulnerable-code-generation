//FormAI DATASET v1.0 Category: Port Scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h> 
#include <arpa/inet.h>
#include <unistd.h>

int scan_port(char *ip_addr, int port_num)
{
    struct sockaddr_in server;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    
    if(sock == -1)
    {
        perror("Socket creation failed\n");
        return 1;
    }
    
    server.sin_addr.s_addr = inet_addr(ip_addr);
    server.sin_family = AF_INET;
    server.sin_port = htons(port_num);

    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0)
    {
        printf("Port %d is open\n", port_num);
        close(sock);
        return 0;
    }

    close(sock);
    return 1;
}

int main(int argc, char *argv[])
{
    const char *ip_addr = argv[1];
    int start_port = atoi(argv[2]), end_port = atoi(argv[3]);
    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip_addr);

    for(int i = start_port; i <= end_port; i++)
    {
        if(scan_port(ip_addr, i) == 0)
        {
            printf("Port %d is open on %s\n", i, ip_addr);
        }
    }

    printf("Port scanning complete\n");
    return 0;
}