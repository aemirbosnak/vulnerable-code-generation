//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<malloc.h>

//Function to calculate modulus
uint64_t mod(uint64_t g,uint64_t n,uint64_t p){
    uint64_t r = 1;
    while(n){
        if(n & 1){
            r = (r * g) % p;
        }
        g = (g * g) % p;
        n >>= 1;
    }
    return r;
}

//Function to check if a number is prime or not
int is_prime(uint64_t p){
    if(p <= 1) return 0;
    if(p <= 3) return 1;
    if(p % 2 == 0 || p % 3 == 0) return 0;
    for(uint64_t i = 5; i * i <= p; i += 6){
        if(p % i == 0 || p % (i+2) == 0){
            return 0;
        }
    }
    return 1;
}

//Function to get random prime
uint64_t get_prime(int bits){
    uint64_t p = 0;
    int is_prime_num = 0;
    while(!is_prime_num){
        p = rand() % (1 << bits);
        if(p % 2 == 0) p++;
        is_prime_num = is_prime(p);
    }
    return p;
}

int main(){
    //Generating the public and private keys
    uint64_t p = get_prime(32);
    uint64_t q = get_prime(32);
    uint64_t n = p * q;
    uint64_t phi_n = (p-1) * (q-1);
    uint64_t e = 65537;
    uint64_t d = 0, k = 1;

    while(d == 0){
        k += phi_n;
        if(k % e == 0){
            d = k / e;
        }
    }

    //Printing the public and private keys
    printf("Public Key: (%ld, %ld)\n", n, e);
    printf("Private Key: (%ld, %ld)\n", n, d);

    //Encrypting and Decrypting a message
    char* message = "Hello, World!";
    uint64_t len = strlen(message);
    uint64_t* encrypted = malloc(len * sizeof(uint64_t));
    uint64_t* decrypted = malloc(len * sizeof(uint64_t));
    for(uint64_t i = 0; i < len; i++){
        encrypted[i] = mod((uint64_t)message[i], e, n);
        decrypted[i] = mod(encrypted[i], d, n);
    }

    //Printing the original message and the decrypted message
    printf("Original Message: %s\n", message);
    printf("Encrypted Message: ");
    for(uint64_t i = 0; i < len; i++){
        printf("%ld ", encrypted[i]);
    }
    printf("\nDecrypted Message: ");
    for(uint64_t i = 0; i < len; i++){
        printf("%c", (char)decrypted[i]);
    }
    printf("\n");

    //Freeing the memory
    free(encrypted);
    free(decrypted);

    return 0;
}