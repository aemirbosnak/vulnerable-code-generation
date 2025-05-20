//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX 65535

int main(int argc, char *argv[]) {
    int sock, port, valread, sd;
    struct hostent *he;
    struct sockaddr_in serv_addr;
    char buffer[1025];

    if(argc < 3){
        printf("Usage :./a.out <hostname/ip> <port_range>\n");
        exit(0);
    }

    if((he=gethostbyname(argv[1])) == NULL){
        printf("No such host\n");
        exit(0);
    }

    for(port=atoi(argv[2]); port<=MAX; port++){
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock < 0){
            printf("Socket failed\n");
            exit(0);
        }

        bzero(&serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = *(long *)he->h_addr;
        serv_addr.sin_port = htons(port);

        if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
            printf("Connection failed\n");
            close(sock);
            continue;
        }

        printf("Port %d is open\n", port);
        close(sock);
    }

    return 0;
}