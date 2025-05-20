//FormAI DATASET v1.0 Category: Port Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MAX_PORT 65535

/*create a socket and return socket file descriptor*/
int create_socket()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

/*scan a single port*/
void scan_port(char *host, int port)
{
    //create socket
    int sockfd = create_socket();
    
    //set timeout for socket
    struct timeval timeout;
    timeout.tv_sec = 1; //1 second timeout
    timeout.tv_usec = 0;
    if(setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("Error setting socket timeout");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    //set address to scan
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &(addr.sin_addr));
    
    //connect to address
    if(connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        printf("Port %d on %s is open\n", port, host);
    }
    
    close(sockfd);
}

/*scan a range of ports*/
void scan_range(char *host, int start_port, int end_port)
{
    for(int port = start_port; port <= end_port; port++) {
        scan_port(host, port);
    }
}

int main(int argc, char **argv)
{
    //check if proper arguments given
    if(argc != 3) {
        printf("Usage: port-scanner <host> <port>\n");
        printf("Example: port-scanner google.com 80\n");
        printf("Or: port-scanner google.com 1-1000\n");
        exit(EXIT_FAILURE);
    }
    
    //get host and port
    char *host = argv[1];
    char *port_str = argv[2];
    
    //parse port string
    int start_port = -1, end_port = -1;
    if(strchr(port_str, '-')) { //range of ports
        sscanf(port_str, "%d-%d", &start_port, &end_port);
    } else { //single port
        start_port = end_port = atoi(port_str);
    }
    
    //check if ports are valid
    if(start_port < 1 || start_port > MAX_PORT || end_port < 1 || end_port > MAX_PORT) {
        printf("Invalid port range\n");
        exit(EXIT_FAILURE);
    }
    
    //scan ports
    printf("Scanning ports %d-%d on %s...\n", start_port, end_port, host);
    scan_range(host, start_port, end_port);
    
    return 0;
}