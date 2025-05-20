//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char send_buff[BUFF_SIZE];
    char recv_buff[BUFF_SIZE];
    int n;
    int port = 25;
    
    if (argc!= 4) {
        printf("Usage:./client <server_ip> <sender_email> <receiver_email>\n");
        exit(1);
    }
    
    strcpy(send_buff, "HELO client\r\n");
    send(sock, send_buff, strlen(send_buff), 0);
    
    strcpy(send_buff, "MAIL FROM:<");
    strcat(send_buff, argv[2]);
    strcat(send_buff, ">\r\n");
    send(sock, send_buff, strlen(send_buff), 0);
    
    strcpy(send_buff, "RCPT TO:<");
    strcat(send_buff, argv[3]);
    strcat(send_buff, ">\r\n");
    send(sock, send_buff, strlen(send_buff), 0);
    
    strcpy(send_buff, "DATA\r\n");
    send(sock, send_buff, strlen(send_buff), 0);
    
    strcpy(send_buff, "Subject: Test Email\r\n");
    send(sock, send_buff, strlen(send_buff), 0);
    
    strcpy(send_buff, "Hello, this is a test email sent from a SMTP client.\r\n");
    send(sock, send_buff, strlen(send_buff), 0);
    
    strcpy(send_buff, ".\r\n");
    send(sock, send_buff, strlen(send_buff), 0);
    
    close(sock);
    
    return 0;
}