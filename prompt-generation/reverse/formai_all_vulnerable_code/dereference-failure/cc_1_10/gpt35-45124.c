//FormAI DATASET v1.0 Category: Port Scanner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

// Function to check if the socket is connectable
int is_connectable(char* ip, int port)
{
    struct sockaddr_in target;
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    // Zero out the target structure
    memset(&target, 0, sizeof(target));
    
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip);
    target.sin_port = htons(port);
    
    if(connect(sock, (struct sockaddr *)&target, sizeof(target)) >= FALSE)
    {
        close(sock);
        return TRUE;
    }
    
    close(sock);
    return FALSE;
}

int main(int argc, char* argv[])
{
    char* ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
    
    // Loop through all the ports and check if they are connectable
    for(int port = start_port; port <= end_port; port++)
    {
        if(is_connectable(ip, port))
        {
            printf("%d open\n", port);
        }
    }
    
    return 0;
}