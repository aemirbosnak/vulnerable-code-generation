//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char* encrypt(char str[], int key){
    int i, len = strlen(str);
    char* result = malloc(len * sizeof(char));
    
    for(i=0; i<len; i++){
        if(isalpha(str[i])){
            if(isupper(str[i])){
                result[i] = ((str[i]-65+key)%26)+65;
            }
            else{
                result[i] = ((str[i]-97+key)%26)+97;
            }
        }
        else{
            result[i] = str[i];
        }
    }
    return result;
}

char* decrypt(char str[], int key){
    int i, len = strlen(str);
    char* result = malloc(len * sizeof(char));
    
    for(i=0; i<len; i++){
        if(isalpha(str[i])){
            if(isupper(str[i])){
                result[i] = ((str[i]-65-key+26)%26)+65;
            }
            else{
                result[i] = ((str[i]-97-key+26)%26)+97;
            }
        }
        else{
            result[i] = str[i];
        }
    }
    return result;
}

int main(){
    char p[100], *e, *d;
    int key;
    printf("Enter plaintext message:\n");
    fgets(p, 100, stdin);
    
    printf("Enter encryption key:\n");
    scanf("%d", &key);
    
    e = encrypt(p, key);
    printf("Encrypted message: %s\n", e);
    
    d = decrypt(e, key);
    printf("Decrypted message: %s\n", d);
    
    free(e);
    free(d);
    
    return 0;
}