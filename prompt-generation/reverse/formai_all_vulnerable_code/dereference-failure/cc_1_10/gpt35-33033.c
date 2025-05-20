//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char **argv) {

    if(argc < 3) {
        printf("Usage : ./qos_monitor <ip_address> <port_number>\n");
        exit(1);
    }

    int sockfd, port_num;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUF_SIZE];
    fd_set read_fds;

    port_num = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0) {
        perror("Error creating socket.\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(port_num);

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0 ) {
        perror("Error connecting to the server.\n");
        exit(1);
    }

    int count = 0; 
    while(1) {
        FD_ZERO(&read_fds);
        FD_SET(sockfd, &read_fds);
        struct timeval tv;
        tv.tv_sec = 1;
        tv.tv_usec = 0;

        int sel_ret = select(sockfd+1, &read_fds, NULL, NULL, &tv);
        if(sel_ret == -1) {
            perror("Error performing select.\n");
            exit(1);
        }
        else if(sel_ret == 0) {
            printf("Timeout occured, no data received.\n");
        }
        else {
            int len = read(sockfd, buffer, sizeof(buffer));
            buffer[len] = '\0';
            count++;
            printf("Received data #%d: %s\n", count, buffer);
        }
    }

    close(sockfd);

    return 0;
}