//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <ctype.h>

#define MAXLINE 1024

typedef struct {
    char *mail_folder;
    char *username;
    char *password;
    char *server_address;
    int port;
    int fd;
    int quit;
} imap_connection;

int read_imap_response(int sockfd, char *line);
void free_imap_connection(imap_connection *con);

int main(int argc, char *argv[])
{
    imap_connection con = {NULL, NULL, NULL, NULL, 0, 0, 0};

    if (argc!= 5) {
        printf("Usage: imap_client <username> <password> <server_address> <port>\n");
        return 1;
    }

    con.username = argv[1];
    con.password = argv[2];
    con.server_address = argv[3];
    con.port = atoi(argv[4]);

    con.fd = socket(AF_INET, SOCK_STREAM, 0);

    if (con.fd < 0) {
        perror("Socket creation error");
        return 1;
    }

    if (connect(con.fd, (struct sockaddr *) &(con.server_address), sizeof(con.server_address)) < 0) {
        perror("Connection error");
        return 1;
    }

    char command[MAXLINE];
    sprintf(command, "auth login PLAIN %s %s", con.username, con.password);
    write(con.fd, command, strlen(command));

    if (read_imap_response(con.fd, command) == -1) {
        perror("Authentication failed");
        return 1;
    }

    sprintf(command, "list \"\" \"\"");
    write(con.fd, command, strlen(command));

    if (read_imap_response(con.fd, command) == -1) {
        perror("Listing failed");
        return 1;
    }

    printf("IMAP folder list:\n");
    while (1) {
        if (strstr(command, "OK list completed")!= NULL) {
            break;
        }

        printf("%s\n", command);
        if (read_imap_response(con.fd, command) == -1) {
            perror("Listing failed");
            return 1;
        }
    }

    free_imap_connection(&con);

    return 0;
}

int read_imap_response(int sockfd, char *line)
{
    int n;
    char *buf;
    size_t len;

    buf = (char *) malloc(MAXLINE * sizeof(char));
    if (buf == NULL) {
        perror("malloc failed");
        return -1;
    }

    len = 0;
    while ((n = read(sockfd, buf + len, MAXLINE - len)) > 0) {
        len += n;
        if (len >= MAXLINE) {
            free(buf);
            perror("Read error");
            return -1;
        }
    }

    if (n < 0) {
        perror("Read error");
        free(buf);
        return -1;
    }

    line[strcspn(buf, "\n")] = '\0';
    free(buf);

    return 0;
}

void free_imap_connection(imap_connection *con)
{
    if (con->fd!= 0) {
        close(con->fd);
    }

    free(con->mail_folder);
    free(con->username);
    free(con->password);
    free(con->server_address);
}