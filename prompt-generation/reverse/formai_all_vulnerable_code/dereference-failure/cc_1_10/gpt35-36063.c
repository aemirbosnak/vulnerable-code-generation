//FormAI DATASET v1.0 Category: Firewall ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT 8080
#define ALLOWED_IP "192.168.0.0/16"
#define ALLOWED_PORT 80

void createFirewall(){
    //create a socket
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
 

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    int new_socket;
    struct sockaddr_in client_address;
    char *client_ip;
    while(1){
        if ((new_socket = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        client_ip = inet_ntoa(client_address.sin_addr);
        if(strcmp(ALLOWED_IP,client_ip)!=0){
            printf("Access Denied! Connection from %s not allowed.\n",client_ip);
            close(new_socket);
        }else{
            printf("Connection from %s is allowed.\n",client_ip);
            int buff_size = 1024;
            char buffer[buff_size];
            int valread = read( new_socket , buffer, buff_size);
            int i=0;
            while(i<valread){
                if(buffer[i] == ALLOWED_PORT){
                    printf("Port access granted.\n");
                    send(new_socket , "Port access granted." , strlen("Port access granted.") , 0 );
                    close(new_socket);
                }else{
                    printf("Port access denied.\n");
                    send(new_socket , "Port access denied." , strlen("Port access denied.") , 0 );
                    close(new_socket);
                }
                i++;
            }
        }
    }
}

int main(){
    printf("Firewall Active...\n");
    createFirewall();
    return 0;
}