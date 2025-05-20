//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[]){

    //create socket
    int client_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(client_socket == -1){
        printf("Unable to create socket!\n");
        return -1;
    }

    //set address information
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");   //change this to your server IP address
    server_address.sin_port = htons(25);    // SMTP port

    //connect to server
    if(connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1){
        printf("Unable to connect to server!\n");
        close(client_socket);
        return -1;
    }

    //receive server response
    char recv_buf[BUF_SIZE];
    memset(recv_buf, 0, sizeof(recv_buf));
    int recv_len = read(client_socket, recv_buf, sizeof(recv_buf));
    printf("SMTP server response: %s", recv_buf);

    //send HELO command
    char helo_cmd[BUF_SIZE];
    memset(helo_cmd, 0, sizeof(helo_cmd));
    sprintf(helo_cmd, "HELO %s\r\n", argv[1]);   //enter domain(localhost) name as argument
    write(client_socket, helo_cmd, strlen(helo_cmd));

    //receive server response
    memset(recv_buf, 0, sizeof(recv_buf));
    recv_len = read(client_socket, recv_buf, sizeof(recv_buf));
    printf("SMTP server response: %s", recv_buf);

    //send MAIL FROM command
    char mail_from_cmd[BUF_SIZE];
    memset(mail_from_cmd, 0, sizeof(mail_from_cmd));
    sprintf(mail_from_cmd, "MAIL FROM:<%s>\r\n", argv[2]);   //enter sender email address as second argument
    write(client_socket, mail_from_cmd, strlen(mail_from_cmd));

    //receive server response
    memset(recv_buf, 0, sizeof(recv_buf));
    recv_len = read(client_socket, recv_buf, sizeof(recv_buf));
    printf("SMTP server response: %s", recv_buf);

    //send RCPT TO command
    char rcpt_to_cmd[BUF_SIZE];
    memset(rcpt_to_cmd, 0, sizeof(rcpt_to_cmd));
    sprintf(rcpt_to_cmd, "RCPT TO:<%s>\r\n", argv[3]);   //enter recipient email address as third argument
    write(client_socket, rcpt_to_cmd, strlen(rcpt_to_cmd));

    //receive server response
    memset(recv_buf, 0, sizeof(recv_buf));
    recv_len = read(client_socket, recv_buf, sizeof(recv_buf));
    printf("SMTP server response: %s", recv_buf);

    //send DATA command
    char data_cmd[] = "DATA\r\n";
    write(client_socket, data_cmd, strlen(data_cmd));

    //receive server response
    memset(recv_buf, 0, sizeof(recv_buf));
    recv_len = read(client_socket, recv_buf, sizeof(recv_buf));
    printf("SMTP server response: %s", recv_buf);

    //send mail body
    char body[BUF_SIZE];
    memset(body, 0, sizeof(body));
    sprintf(body, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", argv[2], argv[3], argv[4], argv[5]);   //enter email details as arguments
    write(client_socket, body, strlen(body));

    //receive server response
    memset(recv_buf, 0, sizeof(recv_buf));
    recv_len = read(client_socket, recv_buf, sizeof(recv_buf));
    printf("SMTP server response: %s", recv_buf);

    //send QUIT command
    char quit_cmd[] = "QUIT\r\n";
    write(client_socket, quit_cmd, strlen(quit_cmd));

    //receive server response
    memset(recv_buf, 0, sizeof(recv_buf));
    recv_len = read(client_socket, recv_buf, sizeof(recv_buf));
    printf("SMTP server response: %s", recv_buf);

    //close socket
    close(client_socket);

    return 0;
}