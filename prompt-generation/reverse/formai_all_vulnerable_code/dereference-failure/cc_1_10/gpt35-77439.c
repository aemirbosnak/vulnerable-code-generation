//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: creative
#include <stdio.h>
#include <stdbool.h>
#include <string.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[1000] , server_reply[2000];
    
    printf("Enter the URL you want to access: ");
    char url[100];
    fgets(url, 100, stdin);
    strtok(url, "\n");

    // resolve IP address from URL
    struct hostent *he;
    struct in_addr **addr_list;
    he = gethostbyname(url);
    addr_list = (struct in_addr **) he->h_addr_list;

    // connect to server using TCP socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
        return 1;
    }
    server.sin_addr = *addr_list[0];
    server.sin_family = AF_INET;
    server.sin_port = htons( 80 );
 
    // Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        printf("Connection error");
        return 1;
    }
     
    // Create HTTP GET request
    sprintf(message, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", url);
     
    // Send request to server
    if( send(sock , message , strlen(message) , 0) < 0)
    {
        printf("Send failed");
        return 1;
    }
    
    // Receive server response
    if( recv(sock , server_reply , 2000 , 0) < 0)
    {
        printf("Receive failed");
    }
     
    printf("Server reply: %s", server_reply);
     
    return 0;
}