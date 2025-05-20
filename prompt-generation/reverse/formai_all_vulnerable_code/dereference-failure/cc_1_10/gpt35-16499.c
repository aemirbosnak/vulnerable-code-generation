//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<openssl/evp.h>
#include<openssl/aes.h>
#include<netdb.h>
#include<netinet/in.h>
#include<unistd.h>

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){
    if (argc < 2){
        fprintf(stderr,"usage %s port\n", argv[0]);
        exit(1);
    }

    int portno = atoi(argv[1]);
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        error("ERROR opening socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0){
        error("ERROR on binding");
    }

    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr, &clilen);

    if (newsockfd < 0){
        error("ERROR on accept");
    }

    char password[] = "password";
    char iv[] = "0000000000000000";

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL){
        error("ERROR: Unable to create new EVP context");
    }

    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char *)password, (unsigned char *)iv) != 1){
        error("ERROR: Unable to initialize encryption context");
    }

    char buffer[256], decrypted[256];
    bzero(buffer,256);
    while(1){
        int n = read(newsockfd,buffer,255);
        if (n < 0){
            error("ERROR reading from socket");
        }

        if (n == 0){
            printf("Client disconnected\n");
            break;
        }

        int outlen, tmplen;
        if (EVP_DecryptUpdate(ctx, (unsigned char *)decrypted, &outlen, (unsigned char *)buffer, n) != 1){
            error("ERROR: Unable to perform encryption");
        }

        if (EVP_DecryptFinal_ex(ctx, (unsigned char *)decrypted + outlen, &tmplen) != 1){
            error("ERROR: Unable to perform final decryption");
        }

        printf("Received message from client: %s\n", decrypted);
        bzero(buffer,256);
        bzero(decrypted,256);
        outlen=0;
    }

    EVP_CIPHER_CTX_free(ctx);
    close(newsockfd);
    close(sockfd);
    return 0;

}