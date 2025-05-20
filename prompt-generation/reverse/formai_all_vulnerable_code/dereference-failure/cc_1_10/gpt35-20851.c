//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 993

int connect_to_server(char *server_ip)
{
    int socket_fd;
    char buffer[1024];
    struct sockaddr_in server_addr;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd < 0)
    {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    memset(buffer, '\0', sizeof(buffer));
    memset(&server_addr, '\0', sizeof(server_addr));
 
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    if(connect(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1)
    {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    return socket_fd;
}

void login(int socket_fd, char *username, char *password)
{
    char buffer[1024];
    memset(buffer, '\0', sizeof(buffer));
    read(socket_fd, buffer, sizeof(buffer));
    
    sprintf(buffer, "A1 LOGIN %s %s\n", username, password);
    write(socket_fd, buffer, strlen(buffer));
    
    memset(buffer, '\0', sizeof(buffer));
    read(socket_fd, buffer, sizeof(buffer));
    printf("%s", buffer);
}

void select_mailbox(int socket_fd, char *mailbox)
{
    char buffer[1024];
    memset(buffer, '\0', sizeof(buffer));
    sprintf(buffer, "A2 SELECT %s\n", mailbox);
    write(socket_fd, buffer, strlen(buffer));
    memset(buffer, '\0', sizeof(buffer));
    read(socket_fd, buffer, sizeof(buffer));
    printf("%s", buffer);
}

void fetch_messages(int socket_fd, int message_number)
{
    char buffer[1024];
    memset(buffer, '\0', sizeof(buffer));
    sprintf(buffer, "A3 FETCH %d (BODY[TEXT])\n", message_number);
    write(socket_fd, buffer, strlen(buffer));
    memset(buffer, '\0', sizeof(buffer));
    read(socket_fd, buffer, sizeof(buffer));
    printf("%s", buffer);
}

void logout(int socket_fd)
{
    char buffer[1024];
    memset(buffer, '\0', sizeof(buffer));
    sprintf(buffer, "A4 LOGOUT\n");
    write(socket_fd, buffer, strlen(buffer));
    memset(buffer, '\0', sizeof(buffer));
    read(socket_fd, buffer, sizeof(buffer));
    printf("%s", buffer);
}

int main()
{
    int socket_fd;
    char server_ip[] = "127.0.0.1";
    char username[] = "myusername";
    char password[] = "mypassword";
    char mailbox[] = "INBOX";
    int message_number = 1;

    socket_fd = connect_to_server(server_ip);

    login(socket_fd, username, password);

    select_mailbox(socket_fd, mailbox);

    fetch_messages(socket_fd, message_number);

    logout(socket_fd);

    close(socket_fd);

    return 0;
}