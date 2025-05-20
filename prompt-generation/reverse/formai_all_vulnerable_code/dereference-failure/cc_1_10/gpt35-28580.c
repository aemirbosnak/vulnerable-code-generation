//FormAI DATASET v1.0 Category: Port Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

void get_ip(char *host, char *ip){
    struct hostent *he;
    struct in_addr **addr_list;

    if((he=gethostbyname(host))==NULL){
        perror("gethostbyname");
        exit(1);
    }

    addr_list = (struct in_addr **) he->h_addr_list;
    for(int i = 0; addr_list[i]!=NULL; i++){
        strcpy(ip, inet_ntoa(*addr_list[i]));
        return;
    }
}

int connect_socket(char *ip, int port){
    struct sockaddr_in serv_addr;
    int sockfd;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, '\0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(ip);

    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))<0){
        return 0;
    }

    close(sockfd);
    return 1;
}

void scan(char *host, int start_port, int end_port){
    char ip[100];
    get_ip(host, ip);
    
    printf("Scanning %s (%s) from port %d to %d \n", host, ip, start_port, end_port);

    for(int port = start_port; port <= end_port; port++){
        if(connect_socket(ip, port)){
            printf("Port %d is open. \n", port);
            scan(host, port+1, end_port);
        }
    }
}

int main(int argc, char *argv[]){
    if(argc < 4){
        printf("Usage: ./scanner TARGET START_PORT END_PORT \n");
        exit(1);
    }

    char *host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    scan(host, start_port, end_port);

    return 0;
}