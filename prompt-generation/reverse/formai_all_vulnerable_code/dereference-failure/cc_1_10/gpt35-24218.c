//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0); // creating a socket
    if (sock == -1) // checking if the socket was created successfully
    {
        printf("Can't create a socket. Try again later!\n");
        return 1;
    }

    // initializing the server hostname
    char hostname[100] = "puzzle.example.com";

    // resolving the server's IP address
    struct hostent *he;
    he = gethostbyname(hostname);
    if (he == NULL) // checking if the hostname was resolved successfully
    {
        printf("Can't resolve the server's hostname.\n");
        return 1;
    }

    // initializing the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = *((unsigned long *)he->h_addr);
    server_address.sin_port = htons(25); // initializing the SMTP port number

    // establishing a connection to the server
    int connection_status = connect(sock, (struct sockaddr *)&server_address, sizeof(server_address));
    if (connection_status == -1) // checking if the connection was established successfully
    {
        printf("Can't establish a connection with the server.\n");
        return 1;
    }

    // receiving the server's greeting message
    char server_response[1024];
    recv(sock, &server_response, sizeof(server_response), 0);
    printf("%s", server_response);

    // sending the first message to the server
    char *message = "EHLO myclientdomain.com\r\n";
    send(sock, message, strlen(message), 0);

    // receiving the server's response to the first message
    recv(sock, &server_response, sizeof(server_response), 0);
    printf("%s", server_response);

    // sending the second message to the server
    message = "MAIL FROM:<myemail@myclientdomain.com>\r\n";
    send(sock, message, strlen(message), 0);

    // receiving the server's response to the second message
    recv(sock, &server_response, sizeof(server_response), 0);
    printf("%s", server_response);

    // sending the third message to the server
    message = "RCPT TO:<receiveremail@example.com>\r\n";
    send(sock, message, strlen(message), 0);

    // receiving the server's response to the third message
    recv(sock, &server_response, sizeof(server_response), 0);
    printf("%s", server_response);

    // sending the fourth message to the server
    message = "DATA\r\n";
    send(sock, message, strlen(message), 0);

    // receiving the server's response to the fourth message
    recv(sock, &server_response, sizeof(server_response), 0);
    printf("%s", server_response);

    // sending the message body to the server
    message = "Subject: A Puzzling SMTP Client Example Program\r\n\r\nDear Receiver,\r\n\r\nI hope my program has puzzled you enough!\r\n\r\nSincerely,\r\nThe SMTP Client Program\r\n.\r\n";
    send(sock, message, strlen(message), 0);

    // receiving the server's response to the message body
    recv(sock, &server_response, sizeof(server_response), 0);
    printf("%s", server_response);

    // sending the fifth message to the server
    message = "QUIT\r\n";
    send(sock, message, strlen(message), 0);

    // receiving the server's response to the fifth message
    recv(sock, &server_response, sizeof(server_response), 0);
    printf("%s", server_response);

    // closing the socket
    close(sock);

    return 0;
}