//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char* data;
    int size;
} String;

void init(String* s, int size) {
    s->data = malloc(size * sizeof(char));
    s->size = size;
}

void copy(String* dest, String* src) {
    int i;
    for(i = 0; i < src->size; i++) {
        dest->data[i] = src->data[i];
    }
    dest->size = src->size;
}

void concat(String* dest, String* src1, String* src2) {
    int i, j, k;
    int size = dest->size + src1->size + src2->size;
    char* temp = malloc(size * sizeof(char));
    for(i = 0; i < dest->size; i++) {
        temp[i] = dest->data[i];
    }
    for(i = 0; i < src1->size; i++) {
        temp[i + dest->size] = src1->data[i];
    }
    for(i = 0; i < src2->size; i++) {
        temp[i + dest->size + src1->size] = src2->data[i];
    }
    free(dest->data);
    dest->data = temp;
    dest->size = size;
}

void delete(String* s) {
    free(s->data);
    s->data = NULL;
    s->size = 0;
}

int main() {
    String s1, s2, s3;
    init(&s1, 10);
    init(&s2, 20);
    init(&s3, 30);
    strcpy(s1.data, "Hello");
    strcpy(s2.data, "World");
    strcpy(s3.data, "Alan");
    printf("s1 = %s\n", s1.data);
    printf("s2 = %s\n", s2.data);
    printf("s3 = %s\n", s3.data);
    concat(&s1, &s2, &s3);
    printf("s1 = %s\n", s1.data);
    delete(&s1);
    delete(&s2);
    delete(&s3);
    return 0;
}