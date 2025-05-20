//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
 
int main(int argc, char *argv[])
{
    struct hostent *he;
    struct sockaddr_in server;
    int sock;
    char message[1000], server_reply[2000];
     
    if(argc != 2)
    {
        printf("Usage: %s <server_address>\n", argv[0]);
        return 1;
    }
     
    // resolve hostname to IP address
    if((he = gethostbyname(argv[1])) == NULL)
    {
        printf("Could not resolve hostname\n");
        return 1;
    }
     
    // create socket
    if((sock = socket(AF_INET , SOCK_STREAM , 0)) < 0)
    {
        printf("Could not create socket\n");
        return 1;
    }
     
    // set server info structure
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr = *((struct in_addr *)he->h_addr);
    server.sin_port = htons(80);
     
    // connect to server
    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        printf("Connection failed\n");
        return 1;
    }
     
    printf("Connected to %s\n", argv[1]);
     
    // send HTTP GET request to server
    strcpy(message, "GET / HTTP/1.1\r\n");
    strcat(message, "Host: ");
    strcat(message, argv[1]);
    strcat(message, "\r\n");
    strcat(message, "Connection: close\r\n");
    strcat(message, "\r\n");
    if(send(sock, message, strlen(message), 0) < 0)
    {
        printf("Send failed\n");
        return 1;
    }
     
    printf("Request sent:\n%s", message);
     
    // receive and print server response
    if(recv(sock, server_reply, 2000, 0) < 0)
    {
        printf("Receive failed\n");
        return 1;
    }
     
    printf("Response received:\n%s", server_reply);
     
    return 0;
}