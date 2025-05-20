//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <netdb.h>
#include <time.h>
#include <stdbool.h>
#include <signal.h>

#define FTP_PORT 21
#define MAXSIZE 65535

bool isconnected = false;
int sockfd = 0;
struct sockaddr_in server_addr;
char command[MAXSIZE];
char response[MAXSIZE];
char buffer[MAXSIZE];

char* getReply()
{
    int len = read(sockfd, response, sizeof(response));
    response[len] = '\0';
    return response;
}

void writetoserver(char* msg)
{
    //write message to server
    send(sockfd, msg, strlen(msg), 0);
}

// connect to server
int connectToServer()
{
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("error creating socket");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("connection failed");
        return -1;
    }

    if (strcmp(getReply(), "220 ") != 0)
    {
        return -1;
    }

    return 0;
}

// login to server
int login(char* user, char* pass)
{
    sprintf(command, "USER %s\r\n", user);
    writetoserver(command);
    if (strcmp(getReply(), "331 ") != 0)
    {
        return -1;
    }

    sprintf(command, "PASS %s\r\n", pass);
    writetoserver(command);
    if (strcmp(getReply(), "230 ") != 0)
    {
        return -1;
    }

    return 0;
}

// disconnect from server
int disconnect()
{
    writetoserver("QUIT\r\n");
    if (strcmp(getReply(), "221 ") != 0)
    {
        return -1;
    }

    close(sockfd);
    return 0;
}

// store file on server
int store(char* filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        return -1;
    }

    sprintf(command, "STOR %s\r\n", filename);
    writetoserver(command);
    if (strcmp(getReply(), "150 ") != 0)
    {
        return -1;
    }

    int bytes_read = 0;
    int count = 0;
    do
    {
        bytes_read = read(fd, buffer, sizeof(buffer));
        send(sockfd, buffer, bytes_read, 0);
        count += bytes_read;
    } while (bytes_read > 0);

    close(fd);

    if (strcmp(getReply(), "226 ") != 0)
    {
        return -1;
    }
    return 0;
}

// retrieve file from server
int retrieve(char* filename)
{
    int fd = open(filename, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0)
    {
        return -1;
    }

    sprintf(command, "RETR %s\r\n", filename);
    writetoserver(command);

    if (strcmp(getReply(), "150 ") != 0)
    {
        return -1;
    }

    int bytes_read = 0;
    int count = 0;
    do
    {
        bytes_read = recv(sockfd, buffer, sizeof(buffer), 0);
        write(fd, buffer, bytes_read);
        count += bytes_read;
    } while (bytes_read > 0);

    close(fd);

    if (strcmp(getReply(), "226 ") != 0)
    {
        return -1;
    }
    return 0;
}

// parse the command and call appropriate function
void parseCommand(char* cmd)
{
    char* tokens[2];
    int index = 0;
    char* token = strtok(cmd, " ");
    while (token != NULL)
    {
        tokens[index++] = token;
        token = strtok(NULL, " ");
    }

    if (strcmp(tokens[0], "quit") == 0)
    {
        if (isconnected)
        {
            disconnect();
            isconnected = false;
        }
        exit(0);
    }
    else if (strcmp(tokens[0], "connect") == 0)
    {
        if (isconnected)
        {
            printf("already connected\n");
            return;
        }
        if (connectToServer() == 0)
        {
            printf("%s\n", getReply());
            isconnected = true;
        }
        return;
    }
    else if (!isconnected)
    {
        printf("not connected to any server\n");
        return;
    }
    else if (strcmp(tokens[0], "login") == 0)
    {
        if (login(tokens[1], tokens[2]) == 0)
        {
            printf("%s\n", getReply());
        }
        else
        {
            printf("invalid login details\n");
        }
        return;
    }
    else if (strcmp(tokens[0], "store") == 0)
    {
        if (store(tokens[1]) == 0)
        {
            printf("file %s stored successfully\n", tokens[1]);
        }
        else
        {
            printf("error occured while storing file\n");
        }
        return;
    }
    else if (strcmp(tokens[0], "retrieve") == 0)
    {
        if (retrieve(tokens[1]) == 0)
        {
            printf("file %s retrieved successfully\n", tokens[1]);
        }
        else
        {
            printf("error occured while retrieving file\n");
        }
        return;
    }
    else if (strcmp(tokens[0], "help") == 0)
    {
        printf("Commands:\n");
        printf("connect - connect to server\n");
        printf("login   - login to server\n");
        printf("store   - store file on server\n");
        printf("retrieve- retrieve file from server\n");
        printf("quit    - disconnect from server and exit\n");
        return;
    }
    else
    {
        printf("invalid command\n");
    }
}

// signal handler for CTRL-C
void sigintCallback(int sig)
{
    printf("CTRL-C pressed. Disconnecting...\n");
    if (isconnected)
    {
        disconnect();
        isconnected = false;
    }
    exit(0);
}

int main()
{
    printf("Welcome to FTP client\n");
    signal(SIGINT, sigintCallback);

    while (true)
    {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        if (strlen(command) > 0 && command[strlen(command)-1] == '\n')
        {
            command[strlen(command)-1] = '\0';
        }
        parseCommand(command);
    }
    return 0;
}