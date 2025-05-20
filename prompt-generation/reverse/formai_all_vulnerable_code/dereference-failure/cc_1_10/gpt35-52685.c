//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>

int create_socket(char *host, char *port){
    struct addrinfo hints, *res, *p;
    int status, sock_fd;
    
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(host, port, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    for (p = res; p != NULL; p = p->ai_next) {
        if ((sock_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("client: socket");
            continue;
        }

        if (connect(sock_fd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sock_fd);
            perror("client: connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "client: failed to connect\n");
        exit(2);
    }

    freeaddrinfo(res);

    return sock_fd;
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    char *host = argv[1];
    char *port = argv[2];

    int sock_fd = create_socket(host,port);

    char buffer[8192];
    char command[1024];
    char filename[1024];
    char arg_buffer[1024];
    int bytes;

    while(1) {
        printf("Enter a command: ");
        fgets(command,1024,stdin);
        if(strncmp(command,"get ",4) == 0) {
            memset(filename,0,sizeof(filename));
            strncpy(filename,&command[4],(strlen(command)-5));
            sprintf(arg_buffer,"RETR %s",filename);
            send(sock_fd,arg_buffer,strlen(arg_buffer),0);
            
            //receive response code
            memset(buffer,0,sizeof(buffer));
            bytes = recv(sock_fd,buffer,sizeof(buffer),0);
            buffer[bytes] = '\0';
            printf("%s",buffer);

            //check for successful response
            if(buffer[0] == '5' || buffer[0] == '4') {
                continue;
            }

            //open file for writing
            FILE *file = fopen(filename,"w");

            //receive file data
            memset(buffer,0,sizeof(buffer));
            while((bytes = recv(sock_fd,buffer,sizeof(buffer),0)) > 0) {
                fwrite(buffer,1,bytes,file);
                memset(buffer,0,sizeof(buffer));
            }
            fclose(file);

            //receive closing message
            memset(buffer,0,sizeof(buffer));
            bytes = recv(sock_fd,buffer,sizeof(buffer),0);
            buffer[bytes] = '\0';
            printf("%s",buffer);
        }
        else if(strncmp(command,"exit",4) == 0) {
            sprintf(arg_buffer,"QUIT");
            send(sock_fd,arg_buffer,strlen(arg_buffer),0);

            //receive and print closing message
            memset(buffer,0,sizeof(buffer));
            bytes = recv(sock_fd,buffer,sizeof(buffer),0);
            buffer[bytes] = '\0';
            printf("%s",buffer);
            break;
        }
        else {
            printf("Invalid command. Available commands: get, exit\n");
        }
    }

    close(sock_fd);
    return 0;
}