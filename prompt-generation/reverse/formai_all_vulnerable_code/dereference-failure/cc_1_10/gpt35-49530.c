//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAXSIZE 256
#define USER_AGENT "POP3Client/1.0"

void error(char *errmsg) {
    fprintf(stderr, "%s\n", errmsg);
    exit(1);
}

int connect_to_server(char *hostname, int port) {
    int sock_fd;
    struct sockaddr_in addr;
    struct hostent *server = gethostbyname(hostname);

    if (server == NULL)
        error("ERROR, no such host");

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0)
        error("ERROR opening socket");

    bzero((char *) &addr, sizeof(addr));
    addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&addr.sin_addr.s_addr,
          server->h_length);
    addr.sin_port = htons(port);

    if (connect(sock_fd,(struct sockaddr *) &addr,sizeof(addr)) < 0)
        error("ERROR connecting");

    return sock_fd;
}

int read_line(int sockfd, char *buffer, int size) {
    int n, i = 0, retval = 0;

    while (i < size - 1) {
        n = read(sockfd, buffer + i, 1);
        if (n == -1)
            error("ERROR reading from socket");
        if (n == 0)
            break;
        if (buffer[i] == '\n' && i != 0)
            break;
        i++;
    }

    buffer[i] = '\0';
    retval = i;
    return retval;
}

void send_command(int sockfd, char *cmd, char *param) {
    char buffer[MAXSIZE];

    if (param != NULL) {
        sprintf(buffer, "%s %s\r\n", cmd, param);
    } else {
        sprintf(buffer, "%s\r\n", cmd);
    }

    if (write(sockfd, buffer, strlen(buffer)) < 0)
        error("ERROR writing to socket");
}

int get_response_code(int sockfd) {
    char buffer[MAXSIZE];
    int retval;

    read_line(sockfd, buffer, MAXSIZE);
    sscanf(buffer, "%d", &retval);
    return retval;
}

void get_greeting(int sockfd) {
    char buffer[MAXSIZE];

    if (read_line(sockfd, buffer, MAXSIZE) < 0)
        error("ERROR reading greeting");

    printf("%s", buffer);
}

void get_message(int sockfd) {
    char buffer[MAXSIZE];

    while (1) {
        read_line(sockfd, buffer, MAXSIZE);

        if (strcmp(buffer, ".\r\n") == 0)
            break;

        printf("%s", buffer);
    }
}

void login(int sockfd, char *username, char *password) {
    char buffer[MAXSIZE];

    // Send user command
    send_command(sockfd, "USER", username);
    if (get_response_code(sockfd) != 331)
        error("ERROR: USER command failed");

    // Send pass command
    send_command(sockfd, "PASS", password);
    if (get_response_code(sockfd) != 230)
        error("ERROR: PASS command failed");

    printf("Successfully logged in.\n");
}

void quit(int sockfd) {
    // Send quit command
    send_command(sockfd, "QUIT", NULL);
    if (get_response_code(sockfd) != 221)
        error("ERROR: QUIT command failed");

    printf("Successfully logged out.\n");
}

void process_commands(int sockfd) {
    char cmd[MAXSIZE];
    char username[MAXSIZE];
    char password[MAXSIZE];

    while (1) {
        printf("Enter POP3 command ('LOGIN' to login, 'QUIT' to quit): ");
        fgets(cmd, MAXSIZE, stdin);
        cmd[strlen(cmd) - 1] = '\0';

        if (strcasecmp(cmd, "QUIT") == 0) {
            quit(sockfd);
            break;
        } else if (strcasecmp(cmd, "LOGIN") == 0) {
            printf("Enter username: ");
            fgets(username, MAXSIZE, stdin);
            username[strlen(username) - 1] = '\0';

            printf("Enter password: ");
            fgets(password, MAXSIZE, stdin);
            password[strlen(password) - 1] = '\0';

            login(sockfd, username, password);
        } else if (strcasecmp(cmd, "LIST") == 0) {
            send_command(sockfd, "LIST", NULL);

            if (get_response_code(sockfd) != 110)
                error("ERROR: LIST command failed");

            get_message(sockfd);
        } else if (strcasecmp(cmd, "STAT") == 0) {
            send_command(sockfd, "STAT", NULL);

            if (get_response_code(sockfd) != 110)
                error("ERROR: STAT command failed");

            get_message(sockfd);
        } else {
            printf("Unknown command: %s\n", cmd);
        }
    }
}

int main(int argc, char **argv) {
    int sockfd;

    if (argc < 2)
        error("Usage: pop3client hostname");

    sockfd = connect_to_server(argv[1], 110);
    get_greeting(sockfd);
    process_commands(sockfd);

    close(sockfd);
    return 0;
}