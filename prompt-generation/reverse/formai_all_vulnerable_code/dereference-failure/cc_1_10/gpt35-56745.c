//FormAI DATASET v1.0 Category: Encryption ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

#define MIN_LENGTH 7
#define MAX_LENGTH 128

char* encrypt(const char* message, const char* key);
char* decrypt(const char* message, const char* key);
char* generate_key(int length);
void print_error(const char* format, ...);

int main() {
    char message[MAX_LENGTH];
    char *key, *encrypted_message, *decrypted_message;
    int length;

    printf("Enter the message to encrypt (max %d characters): ", MAX_LENGTH - 1);
    fgets(message, MAX_LENGTH, stdin);
    printf("Enter the length of the key (minimum %d): ", MIN_LENGTH);
    scanf("%d", &length);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        print_error("Invalid key length!\n");
        return 1;
    }

    key = generate_key(length);
    encrypted_message = encrypt(message, key);
    decrypted_message = decrypt(encrypted_message, key);

    printf("\nKey:\n%s\n\n", key);
    printf("Encrypted message:\n%s\n\n", encrypted_message);
    printf("Decrypted message:\n%s\n", decrypted_message);

    free(key);
    free(encrypted_message);
    free(decrypted_message);

    return 0;
}

char* encrypt(const char* message, const char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char* result = (char*) malloc(message_length + 1);

    for (int i = 0; i < message_length; i++) {
        result[i] = message[i] ^ key[i % key_length];
    }

    result[message_length] = '\0';

    return result;
}

char* decrypt(const char* message, const char* key) {
    return encrypt(message, key);
}

char* generate_key(int length) {
    char* result = (char*) malloc(length + 1);
    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        result[i] = (char) (rand() % 256);
    }

    result[length] = '\0';

    return result;
}

void print_error(const char* format, ...) {
    va_list args;
    va_start(args, format);

    vfprintf(stderr, format, args);

    va_end(args);
}