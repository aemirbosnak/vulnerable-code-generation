//FormAI DATASET v1.0 Category: Port Scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PORTS 100
#define TIMEOUT 3

void scan_port(char *ip, int port);

int main(int argc, char **argv){
    if(argc != 2){
        printf("Invalid arguments. Usage: ./portscanner <ip address>\n");
        return 1;
    }

    char *ip = argv[1];

    for(int port = 1; port <= MAX_PORTS; port++){
        scan_port(ip, port);
    }

    return 0;
}

void scan_port(char *ip, int port){
    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock < 0){
        perror("socket() error");
        exit(1);
    }

    // Set socket to non-blocking mode
    int flags = fcntl(sock, F_GETFL, 0);
    fcntl(sock, F_SETFL, flags | O_NONBLOCK);

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    // Connect to server
    int status = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if(status != 0){
        if(errno == EINPROGRESS){
            // Connection in progress, wait for it to complete
            fd_set set;
            FD_ZERO(&set);
            FD_SET(sock, &set);

            struct timeval timeout;
            timeout.tv_sec = TIMEOUT;
            timeout.tv_usec = 0;

            status = select(sock + 1, NULL, &set, NULL, &timeout);

            if(status == -1){
                perror("select() error");
                exit(1);
            }
            else if(status == 0){
                // Connection timed out
                printf("Port %d closed\n", port);
                close(sock);
                return;
            }
            else{
                // Connection successful
                printf("Port %d open\n", port);
                close(sock);
                return;
            }
        }
        else{
            // Connection failed
            printf("Port %d closed\n", port);
            close(sock);
            return;
        }
    }
    else{
        // Connection successful
        printf("Port %d open\n", port);
        close(sock);
        return;
    }
}