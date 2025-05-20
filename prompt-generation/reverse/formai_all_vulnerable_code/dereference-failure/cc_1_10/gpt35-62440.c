//FormAI DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

    //checking if correct amount of arguments have been provided
    if(argc < 3) {
        printf("Usage: %s <IP address> <start port> <end port(optional)>\n", argv[0]);
        return 1;
    }

    //parsing IP address and start port
    char *ip_addr = argv[1];
    int start_port = atoi(argv[2]);
    
    //parsing end port if provided, else setting to 65535 (maximum port number)
    int end_port;
    if(argc == 4) {
        end_port = atoi(argv[3]);
    } else {
        end_port = 65535;
    }

    //creating socket and setting socket options
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));

    //setting target IP and declaring socket address structure
    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip_addr);

    //looping through specified port range and attempting to connect to each port
    for(int i=start_port; i <= end_port; i++) {
        target.sin_port = htons(i);
        if(connect(sock, (struct sockaddr*)&target, sizeof(target))) {
            printf("Port %d closed\n", i);
            continue;
        }
        printf("Port %d open\n", i);
        close(sock);
        sock = socket(AF_INET, SOCK_STREAM, 0); //resetting socket
    }

    return 0;
}