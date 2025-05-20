//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int size;
} String;

void init(String* str) {
    str->size = 0;
    str->data[0] = '\0';
}

void append(String* str, char c) {
    if(str->size >= MAX_SIZE) {
        printf("Error: String is full.\n");
        return;
    }
    str->data[str->size++] = c;
    str->data[str->size] = '\0';
}

void print(String str) {
    printf("%s", str.data);
}

int main() {
    String input;
    init(&input);

    printf("Enter a string: ");
    fgets(input.data, MAX_SIZE, stdin);

    int n;
    printf("Enter the number of strings to search for: ");
    scanf("%d", &n);

    char** search_strings = (char**)malloc(n * sizeof(char*));
    for(int i = 0; i < n; i++) {
        search_strings[i] = (char*)malloc(MAX_SIZE * sizeof(char));
        printf("Enter string %d: ", i+1);
        fgets(search_strings[i], MAX_SIZE, stdin);
    }

    int count = 0;
    char* pos = strtok(input.data, " ");
    while(pos!= NULL) {
        for(int i = 0; i < n; i++) {
            if(strcmp(pos, search_strings[i]) == 0) {
                printf("Found string %s\n", pos);
                count++;
            }
        }
        pos = strtok(NULL, " ");
    }

    if(count == 0) {
        printf("No matching strings found.\n");
    }

    for(int i = 0; i < n; i++) {
        free(search_strings[i]);
    }
    free(search_strings);

    return 0;
}