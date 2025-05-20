//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define PORT 25
#define BUFFER_SIZE 1024

void send_data(int sock, char* command, char* message);
void receive_data(int sock, char* buffer);
void read_response(int sock, char* expected_response);
void close_socket(int sock);

int main(int argc, char const *argv[])
{
    int bsocket;
    struct hostent *host;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    if(argc != 2)
    {
        printf("Usage: %s <server_address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    host = gethostbyname(argv[1]);
    if(host == NULL)
    {
        herror("gethostbyname() failed");
        exit(EXIT_FAILURE);
    }

    bsocket = socket(AF_INET, SOCK_STREAM, 0);
    if(bsocket < 0)
    {
        perror("socket() creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr*)host->h_addr_list[0]);
    server_addr.sin_port = htons(PORT);

    if(connect(bsocket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }

    receive_data(bsocket, buffer);
    printf("%s\n", buffer);

    send_data(bsocket, "EHLO localhost\r\n", NULL);
    read_response(bsocket, "250");

    send_data(bsocket, "MAIL FROM: <sender@example.com>\r\n", NULL);
    read_response(bsocket, "250");

    send_data(bsocket, "RCPT TO: <recipient@example.com>\r\n", NULL);
    read_response(bsocket, "250");

    send_data(bsocket, "DATA\r\n", NULL);
    read_response(bsocket, "354");

    char* message = "Subject: Test email\r\nFrom: sender@example.com\r\nTo: recipient@example.com\r\n\r\nThis is a test email sent from a retro SMTP client program.\r\n.\r\n";
    send_data(bsocket, message, NULL);
    read_response(bsocket, "250");

    close_socket(bsocket);

    return 0;
}

void send_data(int sock, char* command, char* message)
{
    if(send(sock, command, strlen(command), 0) < 0)
    {
        perror("send() failed");
        exit(EXIT_FAILURE);
    }

    if(message != NULL)
    {
        if(send(sock, message, strlen(message), 0) < 0)
        {
            perror("send() failed");
            exit(EXIT_FAILURE);
        }
    }
}

void receive_data(int sock, char* buffer)
{
    memset(buffer, 0, BUFFER_SIZE);
    if(recv(sock, buffer, BUFFER_SIZE, 0) < 0)
    {
        perror("recv() failed");
        exit(EXIT_FAILURE);
    }
}

void read_response(int sock, char* expected_response)
{
    char buffer[BUFFER_SIZE];
    receive_data(sock, buffer);
    printf("%s\n", buffer);

    if(strncmp(buffer, expected_response, 3) != 0)
    {
        printf("Error: Unexpected response from server");
        close_socket(sock);
        exit(EXIT_FAILURE);
    }
}

void close_socket(int sock)
{
    if(close(sock) < 0)
    {
        perror("close() failed");
        exit(EXIT_FAILURE);
    }
}