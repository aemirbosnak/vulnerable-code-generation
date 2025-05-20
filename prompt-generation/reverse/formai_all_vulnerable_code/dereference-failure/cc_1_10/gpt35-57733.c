//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<pthread.h>

#define BUF_SIZE 1024

void *recv_mail(void *sock_desc){
    int sock = *(int*)sock_desc;
    char buf[BUF_SIZE];
    char *msg;

    //Send "USER" command
    sprintf(buf, "USER <username>\r\n");
    msg = "Username sent...\n";
    write(sock, buf, strlen(buf));
    write(STDOUT_FILENO, msg, strlen(msg));
    memset(buf, 0x00, BUF_SIZE);

    //Send "PASS" command
    sprintf(buf, "PASS <password>\r\n");
    msg = "Password sent...\n";
    write(sock, buf, strlen(buf));
    write(STDOUT_FILENO, msg, strlen(msg));
    memset(buf, 0x00, BUF_SIZE);

    //Send "LIST" command
    sprintf(buf, "LIST\r\n");
    msg = "List sent...\n";
    write(sock, buf, strlen(buf));
    write(STDOUT_FILENO, msg, strlen(msg));
    memset(buf, 0x00, BUF_SIZE);

    //receive mail from the server
    read(sock, buf, BUF_SIZE);
    printf("%s\n", buf);
    memset(buf, 0x00, BUF_SIZE);

    close(sock);
    pthread_exit(NULL);
}


int main(int argc, char *argv[]){
    int ret;
    int sock_desc;
    struct sockaddr_in serv_addr;
    pthread_t thread;

    if(argc!=3){
        printf("Usage: %s <Server IP> <Server Port>\n", argv[0]);
        exit(1);
    }

    //open socket
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_desc == -1){
        perror("socket() error");
        exit(2);
    }

    memset(&serv_addr, 0, sizeof(serv_addr)); //memsets serv_addr to all zeros
    serv_addr.sin_family = AF_INET; //IPv4 Address
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]); // Server IP
    serv_addr.sin_port = htons(atoi(argv[2])); // Server PORT

    //connect to server
    ret = connect(sock_desc, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if(ret == -1){
        perror("connect() error");
        exit(3);
    }

    //create thread for receiving email
    ret = pthread_create(&thread, NULL, recv_mail, (void*)&sock_desc);
    if(ret){
        perror("pthread_create() error");
        exit(4);
    }

    //wait for the thread to complete
    pthread_join(thread, NULL);

    return 0;
}