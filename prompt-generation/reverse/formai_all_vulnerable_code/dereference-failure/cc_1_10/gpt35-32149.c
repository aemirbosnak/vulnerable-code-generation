//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int sock;
    struct sockaddr_in server;
    struct hostent *host;
    char *message , server_reply[2000];
    int port = 80;

    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1){
        printf("Could not create socket");
    }
    puts("Socket created");

    //Get the DNS entry for the host
    host = gethostbyname(argv[1]);

    //Prepare the sockaddr_in structure
    server.sin_addr.s_addr = inet_addr(inet_ntoa(*((struct in_addr*)host->h_addr_list[0])));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0){
        perror("connect failed. Error");
        return 1;
    }

    puts("Connected\n");

    //Send HTTP request
    message = "GET / HTTP/1.1\r\n\r\n";
    if(send(sock, message, strlen(message), 0) < 0){
        puts("Send failed");
        return 1;
    }

    //Receive a reply from the server
    if(recv(sock, server_reply, 2000, 0) < 0){
        puts("recv failed");
    }

    puts("Server reply :");
    puts(server_reply);

    close(sock);
    return 0;
}