//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<netinet/in.h>
#include<netdb.h>

#define PORT 80

int create_socket(char *url)
{
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server = gethostbyname(url);

    memset((char *) &serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;

    memcpy((char *)&serv_addr.sin_addr.s_addr,(char *)server->h_addr, server->h_length);

    serv_addr.sin_port = htons(PORT);

    connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

    return sockfd;
}

void send_request(char *http_request, char *url)
{
    int sockfd;
    int bytes_sent;

    sockfd = create_socket(url);

    bytes_sent = send(sockfd, http_request, strlen(http_request),0);

    printf("Request sent to server:\n");
    printf("%s\n",http_request);

    close(sockfd);
}

void build_request(char *method, char *url, char *http_request)
{
    sprintf(http_request, "%s / HTTP/1.1\r\nHost: %s\r\nUser-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:54.0) Gecko/20100101 Firefox/54.0\r\n\r\n", method, url);
}

int main()
{
    char *url = "www.google.com";
    char http_request[5000];
    char *method = "GET";

    build_request(method, url, http_request);

    printf("HTTP request to be sent:\n");
    printf("%s\n", http_request);

    send_request(http_request, url);

    return 0;
}