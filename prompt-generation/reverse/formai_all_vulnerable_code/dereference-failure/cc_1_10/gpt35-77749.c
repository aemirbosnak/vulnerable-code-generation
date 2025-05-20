//FormAI DATASET v1.0 Category: Port Scanner ; Style: active
#include<stdio.h>
#include<netdb.h>
#include<arpa/inet.h>

int main(int argc, char *argv[])
{
    struct hostent *host;
    int start_port, end_port;
    
    if(argc != 4)
    {
        printf("Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        return -1;
    }
    
    host = gethostbyname(argv[1]);
    
    if(!host)
    {
        printf("Error: Unable to resolve hostname %s\n", argv[1]);
        return -1;
    }
    
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);
    
    if(start_port < 0 || end_port > 65535 || start_port > end_port)
    {
        printf("Invalid port range.\n");
        return -1;
    }
    
    printf("Scanning ports %d to %d on %s (%s):\n", start_port, end_port, host->h_name, inet_ntoa(*(struct in_addr*)host->h_addr_list[0]));
    
    for(int i = start_port; i <= end_port; i++)
    {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        
        struct sockaddr_in target;
        target.sin_family = AF_INET;
        target.sin_port = htons(i);
        target.sin_addr = *(struct in_addr*)host->h_addr_list[0];
        
        int result = connect(sock, (struct sockaddr*)&target, sizeof(target));
        
        if(result == 0)
        {
            printf("\tPort %d: Open\n", i);
        }
        
        close(sock);
    }
    
    printf("Scan complete.\n");
    
    return 0;
}