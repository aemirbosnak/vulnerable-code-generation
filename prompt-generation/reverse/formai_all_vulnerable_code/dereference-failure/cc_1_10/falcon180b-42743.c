//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    int e;
    int n;
} RSA;

void generate_keys(RSA *rsa) {
    int p = rand() % (MAX_SIZE - 1) + 2;
    int q = rand() % (MAX_SIZE - 1) + 2;
    int phi_n = (p - 1) * (q - 1);
    int e = rand() % phi_n;
    while (gcd(e, phi_n)!= 1) {
        e = rand() % phi_n;
    }
    rsa->e = e;
    rsa->n = p * q;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void encrypt(Person *person, RSA *rsa) {
    char *message = malloc(strlen(person->name) + 1);
    strcpy(message, person->name);
    char *ciphertext = malloc(MAX_SIZE);
    int m = strlen(message);
    int i = 0;
    for (int j = 0; j < m; j++) {
        char c = message[j];
        if (isalpha(c)) {
            c = toupper(c);
            int k = c - 'A';
            if (k >= 0 && k < 26) {
                k = (k + 13) % 26;
                ciphertext[i++] = k + 'A';
            }
        } else {
            ciphertext[i++] = c;
        }
    }
    int pt = 0;
    for (int i = 0; i < strlen(ciphertext); i++) {
        pt = (pt * 26 + (ciphertext[i] - 'A' + 13) % 26) % rsa->n;
    }
    char *encrypted_message = malloc(MAX_SIZE);
    sprintf(encrypted_message, "%d %s", pt, ciphertext);
    printf("Encrypted message: %s\n", encrypted_message);
    free(message);
    free(ciphertext);
}

void decrypt(char *encrypted_message, RSA *rsa) {
    int n = rsa->n;
    int pt = atoi(encrypted_message);
    int m = pt % n;
    char *message = malloc(MAX_SIZE);
    for (int i = 0; i < strlen(encrypted_message); i++) {
        char c = encrypted_message[i];
        if (isalpha(c)) {
            int k = c - 'A';
            if (k >= 0 && k < 26) {
                k = (k - 13 + 26) % 26;
                message[i] = k + 'A';
            }
        } else {
            message[i] = c;
        }
    }
    printf("Decrypted message: %s\n", message);
    free(message);
}

int main() {
    Person person;
    strcpy(person.name, "Alice");
    person.age = 25;
    RSA rsa;
    generate_keys(&rsa);
    encrypt(&person, &rsa);
    decrypt(person.name, &rsa);
    return 0;
}