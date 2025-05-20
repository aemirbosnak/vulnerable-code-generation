//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define HASH_LENGTH 64

typedef struct {
    char *key;
    char *message;
    char *hash;
} hash_t;

void generate_hash(hash_t *hash) {
    char *key = malloc(strlen(hash->key) + 1);
    strcpy(key, hash->key);
    char *message = malloc(strlen(hash->message) + 1);
    strcpy(message, hash->message);

    char *hash_str = malloc(HASH_LENGTH + 1);
    memset(hash_str, 0, HASH_LENGTH + 1);

    struct tm *time_info = malloc(sizeof(struct tm));
    time_t now = time(NULL);
    localtime_r(&now, time_info);
    int seconds = time_info->tm_sec;
    int minutes = time_info->tm_min;
    int hours = time_info->tm_hour;
    int day = time_info->tm_mday;
    int month = time_info->tm_mon + 1;
    int year = time_info->tm_year + 1900;

    sprintf(hash_str, "%d%d%d%d%d%d", seconds, minutes, hours, day, month, year);

    char *concat_str = malloc(strlen(key) + strlen(message) + strlen(hash_str) + 1);
    strcat(concat_str, key);
    strcat(concat_str, message);
    strcat(concat_str, hash_str);

    char *md5_hash = malloc(33);
    memset(md5_hash, 0, 33);

    MD5((unsigned char *)concat_str, strlen(concat_str), (unsigned char *)md5_hash);

    strcpy(hash->hash, md5_hash);

    free(key);
    free(message);
    free(hash_str);
    free(concat_str);
}

int main() {
    hash_t hash;
    hash.key = "secret_key";
    hash.message = "Hello, world!";

    generate_hash(&hash);

    printf("Key: %s\n", hash.key);
    printf("Message: %s\n", hash.message);
    printf("Hash: %s\n", hash.hash);

    return 0;
}