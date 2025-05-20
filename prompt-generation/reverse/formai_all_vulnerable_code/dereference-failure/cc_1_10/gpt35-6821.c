//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define CMD_BUF_SIZE 1024
#define DATA_BUF_SIZE 4096
#define USERNAME "username"
#define PASSWORD "password"

void error_handle(char* msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char* argv[])
{
    if(argc!=3)
    {
        printf("Usage: %s <server_ip> <port>\n", argv[0]);
        exit(1);
    }

    int control_sock=socket(AF_INET, SOCK_STREAM, 0);
    if(control_sock==-1)
        error_handle("Cannot create socket");
    
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr=inet_addr(argv[1]);

    if(connect(control_sock, (struct sockaddr*)&server_addr, sizeof(server_addr))==-1)
        error_handle("Cannot connect to the server");

    char cmd_buffer[CMD_BUF_SIZE];
    char data_buffer[DATA_BUF_SIZE];
    int msg_len, sent_len, recv_len;

    // Attempt to log in to the server
    recv_len=read(control_sock, data_buffer, DATA_BUF_SIZE-1); // Read server greeting message
    if(recv_len<=0)
        error_handle("Cannot receive message from server");
    printf("%s\n", data_buffer);

    // Send username
    sprintf(cmd_buffer, "USER %s\r\n", USERNAME);
    sent_len=write(control_sock, cmd_buffer, strlen(cmd_buffer));
    if(sent_len==-1)
        error_handle("Cannot send message to server");

    // Receive response
    recv_len=read(control_sock, data_buffer, DATA_BUF_SIZE-1);
    if(recv_len<=0)
        error_handle("Cannot receive message from server");
    printf("%s\n", data_buffer);

    // Send password
    sprintf(cmd_buffer, "PASS %s\r\n", PASSWORD);
    sent_len=write(control_sock, cmd_buffer, strlen(cmd_buffer));
    if(sent_len==-1)
        error_handle("Cannot send message to server");

    // Receive response
    recv_len=read(control_sock, data_buffer, DATA_BUF_SIZE-1);
    if(recv_len<=0)
        error_handle("Cannot receive message from server");
    printf("%s\n", data_buffer);

    // Enter passive mode to receive data from server
    sprintf(cmd_buffer, "PASV\r\n");
    sent_len=write(control_sock, cmd_buffer, strlen(cmd_buffer));
    if(sent_len==-1)
        error_handle("Cannot send message to server");

    // Receive response
    recv_len=read(control_sock, data_buffer, DATA_BUF_SIZE-1);
    if(recv_len<=0)
        error_handle("Cannot receive message from server");
    printf("%s\n", data_buffer);

    // Extract the IP address and port number of the server from the response
    int ip_part_1, ip_part_2, ip_part_3, ip_part_4, p1, p2;
    if(sscanf(data_buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)", &ip_part_1, &ip_part_2, &ip_part_3, &ip_part_4, &p1, &p2)!=6)
        error_handle("Cannot extract server IP address and port number");
    int data_sock=socket(AF_INET, SOCK_STREAM, 0);
    if(data_sock==-1)
        error_handle("Cannot create socket");
    struct sockaddr_in data_addr;
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family=AF_INET;
    char ip_str[16];
    sprintf(ip_str, "%d.%d.%d.%d", ip_part_1, ip_part_2, ip_part_3, ip_part_4);
    data_addr.sin_addr.s_addr=inet_addr(ip_str);
    data_addr.sin_port=htons(p1*256+p2);
    if(connect(data_sock, (struct sockaddr*)&data_addr, sizeof(data_addr))==-1)
        error_handle("Cannot connect to the server");

    // Request to list files on the server
    sprintf(cmd_buffer, "LIST\r\n");
    sent_len=write(control_sock, cmd_buffer, strlen(cmd_buffer));
    if(sent_len==-1)
        error_handle("Cannot send message to server");

    // Receive directory listing from server in the data socket
    while((recv_len=read(data_sock, data_buffer, DATA_BUF_SIZE-1))>0)
    {
        data_buffer[recv_len]='\0';
        printf("%s", data_buffer);
    }
    printf("\n");

    // Close data socket
    close(data_sock);

    // Quit session with the server
    sprintf(cmd_buffer, "QUIT\r\n");
    sent_len=write(control_sock, cmd_buffer, strlen(cmd_buffer));
    if(sent_len==-1)
        error_handle("Cannot send message to server");

    // Receive response
    recv_len=read(control_sock, data_buffer, DATA_BUF_SIZE-1);
    if(recv_len<=0)
        error_handle("Cannot receive message from server");
    printf("%s\n", data_buffer);

    // Close control socket
    close(control_sock);

    return 0;
}