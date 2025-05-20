//FormAI DATASET v1.0 Category: Port Scanner ; Style: protected
//Unique C Port Scanner Example Program
//By [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

//Define port range
#define LOWER_PORT 1
#define UPPER_PORT 65535

int main(int argc, char *argv[]) {

    int sock, status, port;
    struct sockaddr_in target;

    if(argc < 2 || argc > 3) {
        printf("Usage: %s [Target IP] [Target Port] (optional)\n", argv[0]);
        return 0;
    }

    //Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        perror("Socket creation failed");
        return 1;
    }

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);

    //Single port scan
    if(argc == 3) {

        port = atoi(argv[2]);
        target.sin_port = htons(port);

        //Connect to port
        status = connect(sock, (struct sockaddr *)&target, sizeof(target));

        if(status == -1) {
            printf("Port %d: Closed\n", port);
        } else {
            printf("Port %d: Open\n", port);
        }

    } else { //Range of ports scan

        for(port = LOWER_PORT; port <= UPPER_PORT; port++) {

            target.sin_port = htons(port);
            status = connect(sock, (struct sockaddr *)&target, sizeof(target));

            //Check if connection established
            if(status == -1) {
                continue;
            } else {
                printf("Port %d: Open\n", port);
            }
        }
    }

    close(sock);
    return 0;
}