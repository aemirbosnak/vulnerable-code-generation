//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: thoughtful
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>

int main(int argc , char *argv[])
{
    int socket_desc;
    struct sockaddr_in server;
    char *message , server_reply[2000];

    // Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }

    // Get IP address from host name
    struct hostent *he;
    struct in_addr **addr_list;
         
    if ( (he = gethostbyname( "www.example.com" ) ) == NULL)
    {
        printf("Failed to resolve hostname");
    }
         
    addr_list = (struct in_addr **) he->h_addr_list;

    // Set up server information
    server.sin_addr = *((struct in_addr *) addr_list[0]);
    server.sin_family = AF_INET;
    server.sin_port = htons( 80 );

    // Connect to remote server
    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("connect error");
        return 1;
    }

    puts("Connected to server\n");

    // Prepare the HTTP request
    message = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";

    if( send(socket_desc , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }

    puts("Data Sent\n");

    // Receive a reply from the server
    if( recv(socket_desc, server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }

    puts("Reply received\n");
    puts(server_reply);

    return 0;
}