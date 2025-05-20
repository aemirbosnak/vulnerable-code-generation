//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_SIZE 1000

typedef struct{
    int *public_key;
    int *private_key;
}KeyPair;

void generate_keys(KeyPair *key_pair){
    int *public_key = (int*)malloc(MAX_SIZE*sizeof(int));
    int *private_key = (int*)malloc(MAX_SIZE*sizeof(int));

    for(int i=0;i<MAX_SIZE;i++){
        public_key[i] = rand()%100000;
        private_key[i] = rand()%100000;
    }

    key_pair->public_key = public_key;
    key_pair->private_key = private_key;
}

int encrypt(int *public_key, int message){
    int encrypted_message = 0;
    for(int i=0;i<MAX_SIZE;i++){
        encrypted_message += public_key[i]*pow(message,i);
    }
    return encrypted_message;
}

int decrypt(int *private_key, int encrypted_message){
    int decrypted_message = 0;
    for(int i=0;i<MAX_SIZE;i++){
        decrypted_message += private_key[i]*pow(encrypted_message,i);
    }
    return decrypted_message;
}

int main(){
    KeyPair key_pair;
    generate_keys(&key_pair);

    int message = 12345;
    int encrypted_message = encrypt(key_pair.public_key, message);
    int decrypted_message = decrypt(key_pair.private_key, encrypted_message);

    printf("Original message: %d\n", message);
    printf("Encrypted message: %d\n", encrypted_message);
    printf("Decrypted message: %d\n", decrypted_message);

    return 0;
}