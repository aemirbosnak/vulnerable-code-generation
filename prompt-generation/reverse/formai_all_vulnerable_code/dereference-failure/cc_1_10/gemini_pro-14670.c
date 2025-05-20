//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: Cryptic
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<netdb.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

struct pAtch{
    int s, c, b;
};

struct pAtch* pAtch(int a, int b, int c){
    struct pAtch* t = malloc(sizeof(struct pAtch)); t->s = a; t->c = b; t->b = c; return t;
}

int mSock(){
    int s = socket(AF_INET, SOCK_STREAM, 0); if (s < 0) { perror("Socket"); exit(1); } return s;
}

void bInd(int s, struct sockaddr_in* serv_addr){
    if (bind(s, (struct sockaddr*) serv_addr, sizeof(*serv_addr)) < 0) { perror("Bind"); exit(1); }
}

void lIstn(int s){
    if (listen(s, 5) < 0) { perror("Listen"); exit(1); }
}

struct pAtch* aCcept(int s){
    int c = accept(s, NULL, NULL); if (c < 0) { perror("Accept"); exit(1); }
    return pAtch(s, c, 0);
}

int sEnd(int c, char *b, int b_size){
    int s = send(c, b, b_size, 0);
    if (s < 0) { perror("Send"); exit(1); } return s;
}

int rEcv(int c, char *b, int b_size){
    int r = recv(c, b, b_size, 0);
    if (r < 0) { perror("Receive"); exit(1); } return r;
}

int cLose_s(int s){
    close(s);
    return 0;
}

int cLose_c(int c){
    close(c);
    return 0;
}

int fRee_pAtch(struct pAtch* patch){
    free(patch);
    return 0;
}

int main(int argc, char** argv){
    int s = mSock();
    struct sockaddr_in serv_addr, cli_addr;
    memset(&serv_addr, 0, sizeof(serv_addr)); serv_addr.sin_family = AF_INET; serv_addr.sin_port = htons(80); serv_addr.sin_addr.s_addr = INADDR_ANY;
    bInd(s, &serv_addr); lIstn(s);
    printf("Listening for connections on port %d\n", ntohs(serv_addr.sin_port));
    while (1){
        struct pAtch* p = aCcept(s);
        int b, b_size = sizeof(b);
        char b_r[b_size];
        while ((b = rEcv(p->c, b_r, b_size)) > 0){
            if (strcmp(b_r, "quit")){
                sEnd(p->c, b_r, b_size);
                printf("Echoed: %s\n", b_r);
            }else{
                cLose_c(p->c); fRee_pAtch(p);
                break;
            }
        }
        if (b < 0){ fRee_pAtch(p); break; }
    }
    cLose_s(s);
    return 0;
}