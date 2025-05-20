//FormAI DATASET v1.0 Category: Client Server Application ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

void recursion(int socket_descriptor, char msg[]){
    char recv_msg[1024], send_msg[1024];
    int len;
    memset(recv_msg,0,1024);
    memset(send_msg,0,1024);
    printf("Enter message: ");
    fgets(send_msg,1024,stdin);
    send_msg[strlen(send_msg)-1]=0;
    if(strcmp(send_msg,"exit")!=0){
        send(socket_descriptor,send_msg,strlen(send_msg),0);
        if(recv(socket_descriptor,recv_msg,1024,0)==0){
            printf("Server disconnected\n");
            return;
        }
        printf("Server Response: %s\n",recv_msg);
        recursion(socket_descriptor,msg);
    }
    else{
        printf("Closing the connection\n");
        send(socket_descriptor,send_msg,strlen(send_msg),0);
        return;
    }
}

int main(int argc,char* argv[])
{
    int socket_descriptor,port_number;
    struct sockaddr_in server_address;
    char* server_ip;
    char msg[1024];

    if(argc<3){
        printf("Usage: %s Server_IP_Address Port\n",argv[0]);
        return 0;
    }
    else{
        server_ip=argv[1];
        port_number=atoi(argv[2]);
    }

    //Create a socket
    socket_descriptor=socket(AF_INET,SOCK_STREAM,0);
    if(socket_descriptor<0){
        printf("Error: Failed to create the socket\n");
        return 0;
    }

    //Setting the server details to a structure
    server_address.sin_family=AF_INET;
    server_address.sin_addr.s_addr=inet_addr(server_ip);
    server_address.sin_port=htons(port_number);

    //Establishing the connection
    if(connect(socket_descriptor,(struct sockaddr*)&server_address,sizeof(server_address))!=0){
        printf("Error: Connection to the server %s failed\n",server_ip);
        return 0;
    }
    else{
        printf("Connection with the server %s established\n",server_ip);
        recursion(socket_descriptor,msg);
        close(socket_descriptor);
        return 0;
    }
}