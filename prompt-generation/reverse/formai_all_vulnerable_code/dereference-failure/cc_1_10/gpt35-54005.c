//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Romeo and Juliet
/* Romeo: 
My dear Juliet, the time has come
To build an IMAP client just for fun.
With C we'll craft this software true,
To fetch our emails both old and new.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

/* Juliet:
My sweet Romeo, let's start with care, 
And define the details we must share.
Let's set up the socket for connection
To the server with secure affection.*/
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server = {0};
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));

    if (!inet_pton(AF_INET, argv[1], &server.sin_addr)) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    /* Romeo:
Now let's greet the server politely,
And start off with a handshake wittily.
Then send the login credentials true, 
For the server to authenticate you. */
    char buffer[1024] = {0};
    recv(sock, buffer, 1024, 0);
    printf("%s", buffer);

    char login[1024] = {0};
    printf("Username: ");
    fgets(login, 1024, stdin);
    char* username = strtok(login, "\n");

    char password[1024] = {0};
    printf("Password: ");
    fgets(password, 1024, stdin);
    char* pass = strtok(password, "\n");

    char login_cmd[1024];
    snprintf(login_cmd, 1024, "LOGIN %s %s\n", username, pass);

    if (send(sock, login_cmd, strlen(login_cmd), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, sizeof(buffer));
    recv(sock, buffer, 1024, 0);
    printf("%s", buffer);


    /* Juliet:
Oh Romeo, let's fetch our mail,
And handle the server's responses without fail.
Let's use the IMAP protocol secure, 
And filter for the mail we must ensure.*/
    char fetch[1024] = {0};
    snprintf(fetch, 1024, "FETCH 1:* BODY[HEADER.FIELDS (FROM SUBJECT)]\r\n");

    if (send(sock, fetch, strlen(fetch), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, sizeof(buffer));
    recv(sock, buffer, 1024, 0);

    char* header_start = strstr(buffer, "From:");
    while (header_start) {
        char* header_end = strstr(header_start, "\r\n\r\n");
        if (!header_end) {
            break;
        }

        int header_len = header_end - header_start + strlen("\r\n\r\n");
        char* header = calloc(header_len + 1, sizeof(char));
        strncpy(header, header_start, header_len);

        printf("%s", header);

        free(header);
        header_start = strstr(header_end, "From:");
    }


    /* Romeo:
Dear Juliet, our program so great,
Will handle an error without hate.
Let's make sure to close the socket true,
And exit with errors or success too. */
    close(sock);
    return EXIT_SUCCESS;
}