//FormAI DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h> 
#include <stdlib.h> 
#include <netdb.h> 
#include <sys/socket.h> 

void scan_ports(const char *hostname, int start_port, int end_port) { 

    struct sockaddr_in addr; 
    struct hostent *host; 

    host = gethostbyname(hostname); 
    if (host == NULL) { 
        printf("%s: unknown host\n", hostname); 
        return; 
    } 

    for (int port = start_port; port <= end_port; port++) { 
        /* create a socket */ 
        int sockfd = socket(AF_INET, SOCK_STREAM, 0); 
        if (sockfd < 0) { 
            perror("socket() creation failed"); 
            exit(EXIT_FAILURE); 
        } 

        /* set socket address structures */ 
        memset(&addr, 0, sizeof(addr)); 
        addr.sin_family = AF_INET; 
        addr.sin_port = htons(port); 
        addr.sin_addr.s_addr = *(long*)host->h_addr_list[0]; 

        /* connect to the remote host */ 
        if (connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == 0) { 
            printf("Port %d is open\n", port); 
        } else { 
            printf("Port %d is closed\n", port); 
        } 

        /* close the socket */ 
        close(sockfd); 
    } 
} 

int main(int argc, char **argv) { 
    if (argc != 4) { 
        printf("usage: %s <hostname/IP> <start_port> <end_port>\n", argv[0]); 
        return 1; 
    } 

    char *hostname = argv[1]; 
    int start_port = atoi(argv[2]); 
    int end_port = atoi(argv[3]); 

    scan_ports(hostname, start_port, end_port); 

    return 0; 
}