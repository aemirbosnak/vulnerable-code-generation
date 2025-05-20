//FormAI DATASET v1.0 Category: Encryption ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Define a couple of constants */
#define MAX_STR_LEN 256 // Maximum length of string input
#define MAX_KEY_LEN 32  // Maximum length of encryption key

/* Function declarations */
int encrypt(char *plaintext, char *key, char *ciphertext);
int decrypt(char *ciphertext, char *key, char *plaintext);


int main() {
    char plaintext[MAX_STR_LEN];
    char ciphertext[MAX_STR_LEN];
    char decrypted[MAX_STR_LEN];
    char key[MAX_KEY_LEN];
    printf("Please enter the plaintext to be encrypted:\n");
    fgets(plaintext, MAX_STR_LEN, stdin);
    printf("Please enter the encryption key (maximum length %d):\n", MAX_KEY_LEN);
    fgets(key, MAX_KEY_LEN, stdin);
    int ret_val = encrypt(plaintext, key, ciphertext);
    if (ret_val) {
        printf("Encryption failed with error code %d\n", ret_val);
        exit(1);
    }
    printf("The encrypted text is:\n%s\n", ciphertext);

    ret_val = decrypt(ciphertext, key, decrypted);
    if (ret_val) {
        printf("Decryption failed with error code %d\n", ret_val);
        exit(1);
    }
    printf("The decrypted text is:\n%s\n", decrypted);
    return 0;
}


/*
 * Function to encrypt the plaintext using the key.
 */
int encrypt(char *plaintext, char *key, char *ciphertext) {
    int key_len = strlen(key) - 1; // ignore newline character
    int pt_len = strlen(plaintext) - 1; // ignore newline character
    if (key_len != pt_len) {
        return 1; // error: key and plaintext length mismatch
    }
    srand(time(NULL)); // seed the random number generator with current time
    int shift_amt[key_len];
    for (int i=0; i<key_len; i++) {
        shift_amt[i] = rand() % 26; // generate a random shift amount between 0 and 25
    }
    for (int i=0; i<pt_len; i++) {
        int pt_char = plaintext[i] - 'a'; // convert plaintext character to integer between 0 and 25
        int shift_amt_i = shift_amt[i]; // get the shift amount for the i-th character
        int shifted_pt_char = (pt_char + shift_amt_i) % 26; // shift the plaintext character by shift amount
        char ciphertext_i = shifted_pt_char + 'a'; // convert shifted integer back to character
        ciphertext[i] = ciphertext_i; // add the ciphertext character to the output string
    }
    ciphertext[pt_len] = '\0'; // add null character at the end of the string
    return 0;
}


/*
 * Function to decrypt the ciphertext using the key.
 */
int decrypt(char *ciphertext, char *key, char *plaintext) {
    int key_len = strlen(key) - 1; // ignore newline character
    int ct_len = strlen(ciphertext) - 1; // ignore newline character
    if (key_len != ct_len) {
        return 1; // error: key and ciphertext length mismatch
    }
    int shift_amt[key_len];
    for (int i=0; i<key_len; i++) {
        shift_amt[i] = key[i] - 'a'; // convert key character to integer between 0 and 25
    }
    for (int i=0; i<ct_len; i++) {
        int ct_char = ciphertext[i] - 'a'; // convert ciphertext character to integer between 0 and 25
        int shift_amt_i = shift_amt[i]; // get the shift amount for the i-th character
        int shifted_ct_char = (ct_char - shift_amt_i + 26) % 26; // shift the ciphertext character backward by shift amount
        char plaintext_i = shifted_ct_char + 'a'; // convert shifted integer back to character
        plaintext[i] = plaintext_i; // add the plaintext character to the output string
    }
    plaintext[ct_len] = '\0'; // add null character at the end of the string
    return 0;
}