//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> 
#include<string.h> 
#include<time.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>

#define PORT 8080

int main(int argc, char const *argv[]) 
{ 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char cmd[1024] = {0}; 
    char output[1024] = {0};
    char* ipaddress = NULL;

    // Get the ip address of the system
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;  
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;  

    getaddrinfo(NULL, "8080", &hints, &res);

    // convert the IP address in a sockaddr_in structure
    void *addr;
    char *ipver;
    struct sockaddr_in *ipv4 = (struct sockaddr_in *)res->ai_addr;
    addr = &(ipv4->sin_addr);
    ipaddress = malloc(INET_ADDRSTRLEN);
    inet_ntop(res->ai_family, addr, ipaddress, INET_ADDRSTRLEN);

    // create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 

    memset(&serv_addr, '0', sizeof(serv_addr)); 

    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 

    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, ipaddress, &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 

    // connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 

    // send the command to the server
    strcpy(cmd, "ps -e -o pid,vsz,comm=");
    strcat(cmd, argv[1]);

    // send the command to the server
    send(sock , cmd , strlen(cmd) , 0 ); 

    // Reading the output from server
    while ((valread = read( sock , output, 1024)) > 0) 
    { 
        printf("%s",output); 
    }
    return 0; 
}