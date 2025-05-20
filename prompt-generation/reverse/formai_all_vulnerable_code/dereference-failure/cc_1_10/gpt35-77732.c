//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_BUFF_SIZE 1024

int socket_connection(char * server_addr, int port)
{
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }
    server = gethostbyname(server_addr);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
              }
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR connecting\n");
        exit(1);
    }
    return sockfd;
}

char * read_from_socket(int sockfd)
{
    char buffer[MAX_BUFF_SIZE];
    memset(buffer, 0, MAX_BUFF_SIZE);
    if(read(sockfd, buffer, MAX_BUFF_SIZE) < 1)
       return NULL;
    return strdup(buffer);
}


void write_to_socket(int sockfd, char * message)
{
    write(sockfd, message, strlen(message));
}

void logout(int sockfd)
{
    write_to_socket(sockfd, "a001 logout\r\n");
    char * r = read_from_socket(sockfd);
    if(r != NULL)
        printf("%s", r);
    close(sockfd);
    exit(1);
}   

void handle_response(int sockfd)
{
    char * r = read_from_socket(sockfd);
    if(r != NULL)
        printf("%s", r);
}

void login_to_server(int sockfd, char * username, char * password)
{
    char buffer[MAX_BUFF_SIZE];
    memset(buffer, 0, MAX_BUFF_SIZE);
    snprintf(buffer,sizeof(buffer),"a001 login %s %s\r\n", username, password);
    write_to_socket(sockfd, buffer);
    handle_response(sockfd);
}

void imap_recursively(int sockfd)
{
    char buffer[MAX_BUFF_SIZE];
    char read_buf[MAX_BUFF_SIZE];
    memset(buffer, 0, MAX_BUFF_SIZE);
    snprintf(buffer,sizeof(buffer),"a002 select Inbox\r\n");
    write_to_socket(sockfd, buffer);
    handle_response(sockfd);
    memset(buffer, 0, MAX_BUFF_SIZE);
    snprintf(buffer,sizeof(buffer),"a003 search unseen\r\n");
    write_to_socket(sockfd, buffer);
    handle_response(sockfd);
    memset(buffer, 0, MAX_BUFF_SIZE);
    snprintf(buffer,sizeof(buffer),"a004 fetch 1 full\r\n");
    write_to_socket(sockfd, buffer);
    handle_response(sockfd);
    memset(buffer, 0, MAX_BUFF_SIZE);
    snprintf(buffer,sizeof(buffer),"a005 store 1 +Flags (\\Seen)\r\n");
    write_to_socket(sockfd, buffer);
    handle_response(sockfd);
    memset(buffer, 0, MAX_BUFF_SIZE);
    snprintf(buffer,sizeof(buffer),"a006 uid fetch 1:* (UID FLAGS)\r\n");
    write_to_socket(sockfd, buffer);
    handle_response(sockfd);
    printf("Type 'q' to quit\n");
    while(1)
    {
        printf("> ");
        fgets(read_buf, MAX_BUFF_SIZE, stdin);
        if(read_buf[0] == 'q')
        {
            logout(sockfd);
        }
        write_to_socket(sockfd, read_buf);
        handle_response(sockfd);
    }
}

int main(int argc, char * argv[])
{
    if(argc < 4)
    {
        printf("missing args: ./prog [server] [port] [username] [password]\n");
        exit(1);
    }
    int port = atoi(argv[2]);
    char * server = argv[1];
    char * username = argv[3];
    char * password = argv[4];
    int sockfd = socket_connection(server, port);
    handle_response(sockfd);
    login_to_server(sockfd, username, password);
    imap_recursively(sockfd);
    return 0;
}