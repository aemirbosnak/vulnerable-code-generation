//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUF 1024

// function to read response
void read_response(int sock, char *buffer) {
    memset(buffer, 0, MAX_BUF);
    recv(sock, buffer, MAX_BUF, 0);
}

// function to send request
void send_request(int sock, char *request) {
    send(sock, request, strlen(request), 0);
}

int main() {
    char *hostname = "imap.gmail.com";
    char *username = "example@gmail.com";
    char *password = "some_password";
    int port = 993;
    
    struct hostent *he;
    struct sockaddr_in server;
    char buffer[MAX_BUF];
    int sock;
    
    // create socket
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("socket() failed\n");
        exit(1);
    }
    
    // get host by name
    if((he = gethostbyname(hostname)) == NULL) {
        printf("gethostbyname() failed\n");
        exit(1);
    }
    
    // setup server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr = *((struct in_addr *)he->h_addr);
    
    // connect to server
    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("connect() failed\n");
        exit(1);
    }
    
    // read initial response
    read_response(sock, buffer);
    printf("%s\n", buffer);
    
    // login to server
    char login_request[MAX_BUF];
    sprintf(login_request, "a001 LOGIN %s %s\r\n", username, password);
    send_request(sock, login_request);
    read_response(sock, buffer);
    printf("%s\n", buffer);
    
    // select mailbox
    char select_request[MAX_BUF];
    sprintf(select_request, "a002 SELECT INBOX\r\n");
    send_request(sock, select_request);
    read_response(sock, buffer);
    printf("%s\n", buffer);
    
    // fetch messages
    char fetch_request[MAX_BUF];
    sprintf(fetch_request, "a003 FETCH 1:10 BODY[HEADER.FIELDS (FROM TO SUBJECT)]\r\n");
    send_request(sock, fetch_request);
    read_response(sock, buffer);
    printf("%s\n", buffer);
    
    // logout
    char logout_request[MAX_BUF];
    sprintf(logout_request, "a004 LOGOUT\r\n");
    send_request(sock, logout_request);
    read_response(sock, buffer);
    printf("%s\n", buffer);
    
    // close socket
    close(sock);
    
    return 0;
}