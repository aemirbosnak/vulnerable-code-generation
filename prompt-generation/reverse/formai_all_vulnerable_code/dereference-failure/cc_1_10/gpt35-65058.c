//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 2048

/* Function prototypes */
void error(char* msg);
int create_tcp_socket();
char* get_ip(char* host);
char* build_get_query(char* host, char* user, char* pass);

int main(int argc, char* argv[])
{
    struct sockaddr_in* remote;
    int sock;
    char* ip;
    char* get;
    char buf[BUF_SIZE];

    if(argc < 4){
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    /* Create TCP socket */
    sock = create_tcp_socket();

    /* Get ip address from hostname */
    ip = get_ip(argv[1]);

    /* Initialize remote socket structure */
    remote = (struct sockaddr_in*)malloc(sizeof(struct sockaddr_in));
    remote->sin_family = AF_INET;
    inet_pton(AF_INET, ip, &(remote->sin_addr));
    remote->sin_port = htons(110);

    /* Free ip string */
    free(ip);

    /* Connect to POP3 server */
    if(connect(sock, (struct sockaddr*)remote, sizeof(struct sockaddr)) < 0){
        error("Could not connect");
    }

    /* Receive server greeting message */
    memset(buf, 0, sizeof(buf));
    while(recv(sock, buf, BUF_SIZE, 0) > 0){
        if(strstr(buf, "+OK") != NULL){
            break;
        }
        memset(buf, 0, sizeof(buf));
    }
    printf("%s", buf);

    /* Build and send login request */
    get = build_get_query(argv[1], argv[2], argv[3]);
    printf("%s", get);
    send(sock, get, strlen(get), 0);

    /* Receive login confirmation message */
    memset(buf, 0, sizeof(buf));
    while(recv(sock, buf, BUF_SIZE, 0) > 0){
        if(strstr(buf, "+OK") != NULL){
            break;
        }
        memset(buf, 0, sizeof(buf));
    }
    printf("%s", buf);

    /* Cleanup */
    free(get);
    free(remote);
    close(sock);

    return 0;
}

/* Function to print error message and exit */
void error(char* msg)
{
    perror(msg);
    exit(1);
}

/* Function to create TCP socket */
int create_tcp_socket()
{
    int sock;

    if((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
        error("Can't create TCP socket");
    }

    return sock;
}

/* Function to get ip address from hostname */
char* get_ip(char* host)
{
    struct hostent* hent;
    char* ip;

    if((hent = gethostbyname(host)) == NULL){
        herror("Can't get IP address");
        exit(1);
    }

    ip = inet_ntoa(*((struct in_addr*)hent->h_addr));

    return ip;
}

/* Function to build POP3 login request message */
char* build_get_query(char* host, char* user, char* pass)
{
    char* query;

    query = (char*)malloc(sizeof(char)*BUF_SIZE);
    sprintf(query, "USER %s\r\nPASS %s\r\n", user, pass);

    return query;
}