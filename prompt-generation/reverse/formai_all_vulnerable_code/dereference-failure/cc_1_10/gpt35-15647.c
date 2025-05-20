//FormAI DATASET v1.0 Category: String manipulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_STR_LENGTH 100

typedef struct {
    char* str;
    int length;
} String;

void* reverse_string(void* arg) {
    String* str = (String*)arg;
    char temp;
    int i, j;
    
    for (i = 0, j = str->length - 1; i < j; i++, j--) {
        temp = str->str[i];
        str->str[i] = str->str[j];
        str->str[j] = temp;
    }
    
    return NULL;
}

int main() {
    char str[MAX_STR_LENGTH];
    pthread_t thread;
    String* str_arg = (String*)malloc(sizeof(String));
    
    printf("Enter a string with maximum length of %d: ", MAX_STR_LENGTH);
    fgets(str, MAX_STR_LENGTH, stdin);
    
    str_arg->str = strdup(str);
    str_arg->length = strlen(str_arg->str) - 1;
    
    if (pthread_create(&thread, NULL, reverse_string, str_arg)) {
        fprintf(stderr, "Error creating thread.\n");
        return 1;
    }
    
    if (pthread_join(thread, NULL)) {
        fprintf(stderr, "Error joining thread.\n");
        return 1;
    }
    
    printf("Reversed string: %s", str_arg->str);
    
    free(str_arg->str);
    free(str_arg);
    
    return 0;
}