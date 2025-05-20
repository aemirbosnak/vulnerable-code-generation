//FormAI DATASET v1.0 Category: Firewall ; Style: ephemeral
#include<stdio.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>

int main(){
    //Create a socket
    int sockfd, connfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //Define the server address
    struct sockaddr_in servaddr, cli;
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cli, 0, sizeof(cli));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("192.168.1.100");
    servaddr.sin_port = htons(8888);

    //Bind the socket with the server address
    if(bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0){
        printf("Socket binding failed!\n");
        exit(0);
    }

    //Listen for connections
    if(listen(sockfd, 5) != 0){
        printf("Listening failed!\n");
        exit(0);
    }

    printf("Server now listening for incoming connections...\n");

    socklen_t len = sizeof(cli);
    
    //Accept the incoming connection
    connfd = accept(sockfd, (struct sockaddr*)&cli, &len);

    if (connfd < 0) {
        printf("Server accept failed!\n");
        exit(0);
    }

    printf("Connection accepted from %s:%d\n", inet_ntoa(cli.sin_addr), ntohs(cli.sin_port));

    //Allow only certain IPs
    char* allowed_ips[] = {"192.168.1.101", "192.168.1.102"};

    struct sockaddr_in* s = (struct sockaddr_in*)&cli;
    char* client_ip = inet_ntoa(s->sin_addr);

    int allowed = 0;
    for(int i = 0; i < 2; i++){
        if(strcmp(client_ip, allowed_ips[i]) == 0){
            allowed = 1;
            break;
        }
    }

    if(allowed){
        printf("Access granted to %s\n", client_ip);
        //Do something for allowed connections
    }else{
        printf("Access denied to %s\n", client_ip);
        close(connfd);
        close(sockfd);
    }

    return 0;
}