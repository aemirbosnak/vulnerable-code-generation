//FormAI DATASET v1.0 Category: Port Scanner ; Style: romantic
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int port_start, port_end, i;
    struct sockaddr_in server;
    struct timeval timeout;
    timeout.tv_sec = 2; // setting timeout of 2 seconds
    timeout.tv_usec = 0;
    int sock_fd, status, optval;
    char target_host[20];

    if(argc < 3)
    {
        printf("usage: %s <start_port> <end_port> <target_host>\n", argv[0]);
        return 0;
    }

    port_start = atoi(argv[1]);
    port_end = atoi(argv[2]);
    strcpy(target_host, argv[3]);

    for(i=port_start; i<=port_end; i++)
    {
        sock_fd = socket(AF_INET, SOCK_STREAM, 0);
        if(sock_fd < 0)
            perror("Error: Socket could not be created");

        // setting socket option to 2-second timeout
        status = setsockopt(sock_fd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(struct timeval));
        if(status < 0)
            perror("Error: Setting socket option failed");
        
        // setting server details
        server.sin_family = AF_INET;
        server.sin_port = htons(i);
        server.sin_addr.s_addr = inet_addr(target_host);

        // connecting to the specified port
        status = connect(sock_fd, (struct sockaddr*)&server, sizeof(server));
        if(status == 0)
            printf("Port %d is open on %s\n", i, target_host);

        // closing the socket
        optval = 1;
        setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
        close(sock_fd);
    }
    return 0;
}