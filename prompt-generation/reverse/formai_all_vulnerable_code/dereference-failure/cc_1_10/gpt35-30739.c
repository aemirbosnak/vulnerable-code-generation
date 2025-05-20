//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAXSIZE 1024

int main(int argc, char **argv){

    char *username = "myusername@example.com";
    char *password = "mypassword";
    char *server = "imap.example.com";

    struct hostent *he;
    he = gethostbyname(server);

    struct sockaddr_in server_address;
    memcpy(&server_address.sin_addr, he->h_addr_list[0], he->h_length);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(993);

    int client_socket;
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    char buffer[MAXSIZE];
    memset(buffer, 0, sizeof(buffer));
    read(client_socket, buffer, MAXSIZE);
    printf("%s\n", buffer);

    char login_command[MAXSIZE];
    sprintf(login_command, "a1 LOGIN %s %s\n", username, password);
    send(client_socket, login_command, strlen(login_command), 0);
    memset(buffer, 0, sizeof(buffer));
    read(client_socket, buffer, MAXSIZE);
    printf("%s\n", buffer);

    char list_command[MAXSIZE];
    sprintf(list_command, "a2 LIST \"\" *\n");
    send(client_socket, list_command, strlen(list_command), 0);
    memset(buffer, 0, sizeof(buffer));
    read(client_socket, buffer, MAXSIZE);
    printf("%s\n", buffer);

    char logout_command[MAXSIZE];
    sprintf(logout_command, "a3 LOGOUT\n");
    send(client_socket, logout_command, strlen(logout_command), 0);
    memset(buffer, 0, sizeof(buffer));
    read(client_socket, buffer, MAXSIZE);
    printf("%s\n", buffer);

    close(client_socket);

    return 0;
}