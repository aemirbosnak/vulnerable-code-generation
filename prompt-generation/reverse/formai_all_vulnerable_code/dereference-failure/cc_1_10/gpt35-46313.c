//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT 25
#define SERVER_ADDR "smtp.gmail.com"

int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("Failed to create socket");
        return -1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    
    struct hostent *he = gethostbyname(SERVER_ADDR);
    if (he == NULL)
    {
        perror("Failed to get host");
        close(sock);
        return -1;
    }
    
    memcpy(&server.sin_addr, he->h_addr_list[0], he->h_length);
    
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Failed to connect to server");
        close(sock);
        return -1;
    }

    char recvBuff[1024];
    recv(sock, recvBuff, sizeof(recvBuff), 0);
    printf("Received: %s\n", recvBuff);

    char helo[] = "EHLO smtp.gmail.com\n";
    send(sock, helo, strlen(helo), 0);
    recv(sock, recvBuff, sizeof(recvBuff), 0);
    printf("Received: %s\n", recvBuff);

    char auth[] = "AUTH LOGIN\n";
    send(sock, auth, strlen(auth), 0);
    recv(sock, recvBuff, sizeof(recvBuff), 0);
    printf("Received: %s\n", recvBuff);

    char user[] = "<username>\n";
    send(sock, user, strlen(user), 0);
    recv(sock, recvBuff, sizeof(recvBuff), 0);
    printf("Received: %s\n", recvBuff);

    char pass[] = "<password>\n";
    send(sock, pass, strlen(pass), 0);
    recv(sock, recvBuff, sizeof(recvBuff), 0);
    printf("Received: %s\n", recvBuff);

    char mailfrom[] = "MAIL FROM:<sender@gmail.com>\n";
    send(sock, mailfrom, strlen(mailfrom), 0);
    recv(sock, recvBuff, sizeof(recvBuff), 0);
    printf("Received: %s\n", recvBuff);

    char rcptto[] = "RCPT TO:<receiver@gmail.com>\n";
    send(sock, rcptto, strlen(rcptto), 0);
    recv(sock, recvBuff, sizeof(recvBuff), 0);
    printf("Received: %s\n", recvBuff);

    char data[] = "DATA\n";
    send(sock, data, strlen(data), 0);
    recv(sock, recvBuff, sizeof(recvBuff), 0);
    printf("Received: %s\n", recvBuff);

    char subject[] = "Subject: Test Email\n";
    send(sock, subject, strlen(subject), 0);
    char body[] = "This is a test email sent via SMTP client.\n";
    send(sock, body, strlen(body), 0);
    char period[] = ".\n";
    send(sock, period, strlen(period), 0);
    recv(sock, recvBuff, sizeof(recvBuff), 0);
    printf("Received: %s\n", recvBuff);

    char quit[] = "QUIT\n";
    send(sock, quit, strlen(quit), 0);
    recv(sock, recvBuff, sizeof(recvBuff), 0);
    printf("Received: %s\n", recvBuff);

    close(sock);
    return 0;
}