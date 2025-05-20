//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: Cryptic
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *key;
  int value;
} Hash;

Hash *createHash(int size) {
  Hash *hash = (Hash *)malloc(sizeof(Hash) * size);
  memset(hash, 0, sizeof(Hash) * size);
  return hash;
}

int hashFunction(char *key, int size) {
  int hashValue = 0;
  while (*key) {
    hashValue += *key++;
  }
  return hashValue % size;
}

int insertData(Hash *hash, int size, char *key, int value) {
  int hashValue = hashFunction(key, size);
  int i = 0;
  while (hash[hashValue].key && strcmp(hash[hashValue].key, key)) {
    hashValue = (hashValue + i * i++) % size;
  }
  if (!hash[hashValue].key) {
    hash[hashValue].key = (char *)malloc(strlen(key) + 1);
    strcpy(hash[hashValue].key, key);
  }
  hash[hashValue].value = value;
  return hashValue;
}

int searchData(Hash *hash, int size, char *key) {
  int hashValue = hashFunction(key, size);
  int i = 0;
  while (hash[hashValue].key && strcmp(hash[hashValue].key, key)) {
    hashValue = (hashValue + i * i++) % size;
  }
  if (hash[hashValue].key && !strcmp(hash[hashValue].key, key)) {
    return hash[hashValue].value;
  }
  return -1;
}

int deleteData(Hash *hash, int size, char *key) {
  int hashValue = hashFunction(key, size);
  int i = 0;
  while (hash[hashValue].key && strcmp(hash[hashValue].key, key)) {
    hashValue = (hashValue + i * i++) % size;
  }
  if (hash[hashValue].key && !strcmp(hash[hashValue].key, key)) {
    free(hash[hashValue].key);
    memset(&hash[hashValue], 0, sizeof(Hash));
    return 0;
  }
  return -1;
}

void printHash(Hash *hash, int size) {
  for (int i = 0; i < size; i++) {
    if (hash[i].key) {
      printf("%d: %s-%d\n", i, hash[i].key, hash[i].value);
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  Hash *hash = createHash(n);
  char key[101];
  int choice, value;
  while (1) {
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        scanf("%s %d", key, &value);
        insertData(hash, n, key, value);
        break;
      case 2:
        scanf("%s", key);
        value = searchData(hash, n, key);
        printf("%d\n", value);
        break;
      case 3:
        scanf("%s", key);
        deleteData(hash, n, key);
        break;
      case 4:
        printHash(hash, n);
        break;
      case 5:
        exit(0);
    }
  }
  return 0;
}