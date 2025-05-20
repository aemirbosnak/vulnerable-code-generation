//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_REQUEST_SIZE 1024
#define MAX_RESPONSE_SIZE 4096

int make_socket(const char *host, const char *port)
{
    struct addrinfo hints = {0};
    struct addrinfo *result, *rp;
    int s;
    
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    
    s = getaddrinfo(host, port, &hints, &result);
    if (s != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        return -1;
    }
    
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        s = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (s == -1) {
            continue;
        }
        
        if (connect(s, rp->ai_addr, rp->ai_addrlen) != -1) {
            break;
        }
        
        close(s);
    }
    
    freeaddrinfo(result);
    
    if (rp == NULL) {
        fprintf(stderr, "Could not connect to %s:%s\n", host, port);
        return -1;
    }
    
    return s;
}

int send_all(int s, const char *buf, int len)
{
    int total = 0;
    int bytesleft = len;
    int n;
    
    while (total < len) {
        n = send(s, buf + total, bytesleft, 0);
        if (n == -1) {
            break;
        }
        
        total += n;
        bytesleft -= n;
    }
    
    return (n == -1) ? -1 : total;
}

int recv_all(int s, char *buf, int len)
{
    int total = 0;
    int bytesleft = len;
    int n;
    
    while (total < len) {
        n = recv(s, buf + total, bytesleft, 0);
        if (n == -1) {
            break;
        }
        
        total += n;
        bytesleft -= n;
    }
    
    return (n == -1) ? -1 : total;
}

int http_get(const char *url, char *response)
{
    char host[128];
    char path[256];
    int s;
    char request[MAX_REQUEST_SIZE];
    char buf[MAX_RESPONSE_SIZE];
    int len;
    char *status_line;
    int status = -1;
    
    if (strncmp(url, "http://", 7) != 0) {
        fprintf(stderr, "Invalid URL: %s\n", url);
        return -1;
    }
    
    url += 7;
    
    strncpy(host, url, 127);
    
    char *slash = strchr(host, '/');
    if (slash == NULL) {
        strcpy(path, "/");
    } else {
        *slash = '\0';
        strncpy(path, slash, 255);
    }
    
    sprintf(request, "GET %s HTTP/1.0\r\nHost: %s\r\n\r\n", path, host);
    
    s = make_socket(host, "80");
    if (s < 0) {
        return -1;
    }
    
    len = strlen(request);
    if (send_all(s, request, len) != len) {
        fprintf(stderr, "Error sending request\n");
        close(s);
        return -1;
    }
    
    len = recv_all(s, buf, MAX_RESPONSE_SIZE);
    if(len > 0) {
        status_line = strtok(buf, "\n");
        if(strncmp(status_line, "HTTP/1.1 ", 9) == 0) {
            status = atoi(status_line+9);
        }
    }

    close(s);

    if(status != 200) {
        return -1;
    }

    strncpy(response, buf, MAX_RESPONSE_SIZE);

    return 0;
}

void recursive_GET(const char *url, int depth)
{
    char response[MAX_RESPONSE_SIZE];
    http_get(url, response);
    
    printf("%d %s\n", depth, url);
    
    if(depth == 0) {
        return;
    }
    
    char *start, *end, *p;
    char buffer[MAX_RESPONSE_SIZE];
    
    start = strstr(response, "<a href=");
    while(start != NULL) {
        start += 9;
        end = strstr(start, "\"");
        
        p = buffer;
        while(start != end) {
            *p++ = *start++;
        }
        *p = '\0';
        
        if(strncmp(buffer, "http://", 7) == 0) {
            recursive_GET(buffer, depth - 1);
        }
        
        start = strstr(start, "<a href=");
    }  
}

int main(int argc, char **argv)
{
    if(argc != 3) {
        printf("Usage: %s <url> <depth>\n", argv[0]);
        return 0;
    }

    recursive_GET(argv[1], atoi(argv[2]));

    return 0;
}