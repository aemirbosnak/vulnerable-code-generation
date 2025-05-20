//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h> 

#define HTTP_PORT 80

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[1000] , server_reply[2000];
    
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
    
    //Get server IP address
    struct hostent *he;
    he = gethostbyname(argv[1]);
    if (he == NULL) 
    {
        printf("Failed to resolve hostname");
        return 1;
    }
    char *ip = inet_ntoa(*(struct in_addr*)he->h_addr);
    printf("%s resolved to %s\n", argv[1], ip);
    
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(HTTP_PORT);

    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
    
    puts("Connected\n");
     
    //Send HTTP request
    sprintf(message, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1]);
    if (send(sock , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
    puts("HTTP request sent\n");

    //Receive HTTP response
    int bytes_received = 0;
    while ((bytes_received = recv(sock , server_reply , sizeof(server_reply) , 0)) > 0)
    {
        fwrite(server_reply , 1 , bytes_received , stdout);
    }
    puts("HTTP response received\n");

    close(sock);
    return 0;
}