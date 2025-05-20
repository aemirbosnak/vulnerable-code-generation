//FormAI DATASET v1.0 Category: Port Scanner ; Style: detailed
#include <stdio.h>  
#include <sys/socket.h>  
#include <arpa/inet.h> 
#include <string.h>  
#include <stdlib.h>  
#include <errno.h>
#include <stdbool.h>

void scan_port(char *ip, int port_num)  
{  
    struct sockaddr_in sa;  
    int sockfd = socket(AF_INET , SOCK_STREAM , 0);  

    if (sockfd < 0)  
      fprintf(stderr, "socket error: %s\n", strerror(errno));  

    sa.sin_family = AF_INET;  
    sa.sin_addr.s_addr = inet_addr(ip);  
    sa.sin_port = htons(port_num);  

    int conn_status;
    conn_status = connect(sockfd,(struct sockaddr *)&sa , sizeof(sa));  

    if (conn_status == 0)  
    {    
         printf("Port %d Open\n",port_num);  
    }  
    else
    {
         fprintf(stderr, "Port %d Closed\n",port_num);
    }

    close(sockfd);  
}

int main(int argc, char **argv)  
{  
    if (argc != 4) {  
        printf("Usage: %s [IP] [min_port] [max_port]\n", argv[0]);  
        return 1;  
    }  
    
    char *ip = argv[1];
    int min_port = atoi(argv[2]);
    int max_port = atoi(argv[3]);

    if (min_port < 0 || max_port >=65536 || min_port > max_port) {
        printf("Invalid port range!\n");
        return 1;
    }

    for (int port = min_port; port <= max_port; port++) {
        scan_port(ip, port);
    }

    return 0;  
}