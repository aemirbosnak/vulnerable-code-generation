//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Define struct to hold keys
typedef struct{
    long int p;
    long int q;
    long int n;
    long int totient;
    long int e;
    long int d;
}public_key;

// Function to generate prime numbers
int is_prime(long int num){
    int i;
    for(i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}

// Function to generate public and private keys
public_key generate_keys(){
    public_key keys;
    long int p, q, n, r, e, d;
    p = rand() % 100 + 1; // Randomly choose p
    while(!is_prime(p)){
        p = rand() % 100 + 1;
    }
    q = rand() % 100 + 1; // Randomly choose q
    while(!is_prime(q)){
        q = rand() % 100 + 1;
    }
    n = p * q; // Calculate n
    keys.n = n;
    keys.totient = (p - 1) * (q - 1); // Calculate totient
    e = rand() % (keys.totient - 2) + 2; // Randomly choose e
    while(1){
        if(is_prime(e) && keys.totient % e != 0){
            break;
        }
        e++;
    }
    keys.e = e;
    r = 1;
    while(((r * keys.totient) + 1) % e != 0){ // Find d
        r++;
    }
    d = ((r * keys.totient) + 1) / e;
    keys.d = d;
    keys.p = p;
    keys.q = q;
    return keys; // Return public key struct
}

// Encrypt function
long int encrypt(long int message, long int e, long int n){
    long int cipher = 1;
    int i;
    for(i = 0; i < e; i++){
        cipher = (cipher * message) % n;
    }
    return cipher;
}

// Decrypt function
long int decrypt(long int cipher, long int d, long int n){
    long int message = 1;
    int i;
    for(i = 0; i < d; i++){
        message = (message * cipher) % n;
    }
    return message;
}

int main(){
    // Get input
    char message[100];
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    
    // Generate keys
    public_key keys = generate_keys();
    
    // Print keys
    printf("Public Key:\n");
    printf("n: %ld\ne: %ld\n", keys.n, keys.e);
    printf("Private Key:\n");
    printf("p: %ld\nq: %ld\nd: %ld\n", keys.p, keys.q, keys.d);
    
    // Encrypt message
    long int cipher[strlen(message)];
    int i;
    for(i = 0; i < strlen(message); i++){
        char c = message[i];
        cipher[i] = encrypt(c, keys.e, keys.n);
    }
    
    // Decrypt message
    char decrypted[strlen(message)];
    for(i = 0; i < strlen(message); i++){
        long int c = cipher[i];
        decrypted[i] = decrypt(c, keys.d, keys.n);
    }
    decrypted[strlen(message) - 1] = '\0'; // Remove newline character from end of decrypted message
    
    // Print encrypted and decrypted messages
    printf("Encrypted message: ");
    for(i = 0; i < strlen(message); i++){
        printf("%ld ", cipher[i]);
    }
    printf("\nDecrypted message: %s", decrypted);
    
    return 0;
}