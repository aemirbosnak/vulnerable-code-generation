//FormAI DATASET v1.0 Category: Port Scanner ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

// Function to check if a port is open or closed
int is_port_open(char *ip,int port){

    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket for TCP connection
    sockfd=socket(AF_INET,SOCK_STREAM,0);

    // Check if socket creation failed
    if(sockfd==-1){
        return -1;
    }

    // Initialize the server address structure
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=inet_addr(ip);
    server_addr.sin_port=htons(port);

    // Connect to the server
    if(connect(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr))==-1){
        // Port is closed
        close(sockfd);
        return 0;
    }
    else{
        // Port is open
        close(sockfd);
        return 1;
    }
}

int main(int argc,char *argv[]){

    if(argc<2){
        printf("USAGE: %s <target_ip> <start_port> <end_port>\n",argv[0]);
        return -1;
    }

    char *target_ip=argv[1];
    int start_port=atoi(argv[2]);
    int end_port=atoi(argv[3]);

    printf("Scanning ports %d to %d on %s\n",start_port,end_port,target_ip);

    for(int i=start_port;i<=end_port;i++){
        if(is_port_open(target_ip,i)){
            printf("Port %d is open\n",i);
        }
    }

    printf("Scan completed\n");

    return 0;
}