//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char* key;
    int keylen;
}key;

char* genkey(int len){
    char* key = (char*)malloc(len*sizeof(char));
    for(int i=0;i<len;i++){
        key[i]=(char)(rand()%255);
    }
    return key;
}

void enc(key k, char* pt, char* ct){
    int i,j;
    int ptlen = strlen(pt);
    for(i=0,j=0;i<ptlen;i++,j++){
        if(j==k.keylen){
            j=0;
        }
        ct[i]=pt[i]^k.key[j];
    }
}

void dec(key k, char* ct, char* pt){
    int i,j;
    int ctlen = strlen(ct);
    for(i=0,j=0;i<ctlen;i++,j++){
        if(j==k.keylen){
            j=0;
        }
        pt[i]=ct[i]^k.key[j];
    }
}

int main(){
    int keylen;
    printf("Enter key length: ");
    scanf("%d", &keylen);
    key k;
    k.key=genkey(keylen);
    k.keylen=keylen;
    char pt[100],ct[100];
    printf("Enter plaintext: ");
    scanf("%s", pt);
    enc(k, pt, ct);
    printf("Ciphertext: %s\n", ct);
    dec(k, ct, pt);
    printf("Plaintext: %s\n", pt);
    return 0;
}