//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<errno.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 25
#define BUFFER_SIZE 1000

//Function to send data to the server
void send_data(int sock, char *data)
{
    int len = strlen(data);
    send(sock, data, len, 0);
}

//Function to receive data from the server
void receive_data(int sock, char *buffer)
{
    memset(buffer, 0, BUFFER_SIZE);
    int len = recv(sock, buffer, BUFFER_SIZE, 0);
    buffer[len] = '\0';
    printf("Received: %s\n", buffer);
}

int main()
{
    //Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    //Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if(connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error connecting to server\n");
        exit(1);
    }

    //Send SMTP commands
    char *helo = "HELO localhost\r\n";
    send_data(sock, helo);
    receive_data(sock, NULL);

    char *mail = "MAIL FROM:<sender@example.com>\r\n";
    send_data(sock, mail);
    receive_data(sock, NULL);

    char *rcpt = "RCPT TO:<recipient@example.com>\r\n";
    send_data(sock, rcpt);
    receive_data(sock, NULL);

    char *data = "Subject: Test Message\r\n\r\nHello, World!\r\n.\r\n";
    send_data(sock, data);
    receive_data(sock, NULL);

    //Close the socket
    close(sock);
    return 0;
}