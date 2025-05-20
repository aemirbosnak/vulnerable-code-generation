//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/select.h>


#define BUF_SIZE 1024

void handle_error(const char * msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        handle_error("Error: No such host exists");
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handle_error("Error: Failed to create socket");
    }

    struct sockaddr_in server_addr;
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr,
         server->h_length);
    server_addr.sin_port = htons(143);


    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        handle_error("Error: Failed to establish connection");
    }

    char buffer[BUF_SIZE];
    memset(buffer, 0, BUF_SIZE);

    strcpy(buffer, "a0001 LOGIN username password\r\n");

    if (send(sock, buffer, strlen(buffer), 0) < 0)
        handle_error("Error: Failed to send message");

    memset(buffer, 0, BUF_SIZE);
    if (recv(sock, buffer, BUF_SIZE, 0) < 0) {
        handle_error("Error: Failed to receive message");
    }

    printf("Server response: %s\n", buffer);

    strcpy(buffer, "a0002 SELECT Inbox\r\n");

    if (send(sock, buffer, strlen(buffer), 0) < 0)
        handle_error("Error: Failed to send message");


    memset(buffer, 0, BUF_SIZE);
    if (recv(sock, buffer, BUF_SIZE, 0) < 0) {
        handle_error("Error: Failed to receive message");
    }

    printf("Server response: %s\n", buffer);

    char *seq_num;
    char *start = buffer;
    char *end = buffer;

    while (( seq_num = strstr(start, "*")) != NULL){
        end = strstr(seq_num, "\r\n");
        int len = end - seq_num + 2;

        char data[len];
        strncpy (data, seq_num, len);
        printf("%s\n", data);
        start = end;
    }

    close(sock);

    return 0;
}