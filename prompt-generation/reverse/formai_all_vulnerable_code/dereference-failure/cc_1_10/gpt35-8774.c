//FormAI DATASET v1.0 Category: Compression algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for the algorithm
#define MAX_DICT_SIZE 127
#define MAX_CODESIZE 12

// Define a data structure for the dictionary
typedef struct dictionary {
    int size;
    unsigned char *string[MAX_DICT_SIZE];
} dictionary;

// Define a function to initialize the dictionary
void init_dict(dictionary *dict) {
    dict->size = 0;
    for(int i=0; i<MAX_DICT_SIZE; i++) {
        dict->string[i] = NULL;
    }
}

// Define a function to get the index of a string in the dictionary
int get_index(dictionary *dict, char *str) {
    for(int i=0; i<dict->size; i++) {
        if(strcmp(dict->string[i], str) == 0) {
            return i;
        }
    }
    return -1;
}

// Define a function to add a new string to the dictionary
int add_string(dictionary *dict, char *str) {
    if(dict->size < MAX_DICT_SIZE) {
        dict->string[dict->size] = (unsigned char *) malloc(strlen(str)+1);
        strcpy(dict->string[dict->size], str);
        dict->size++;
        return dict->size-1;
    }
    else {
        return -1;
    }
}

// Define a function to encode a string using LZW compression
int encode(FILE *input_file, FILE *output_file) {
    dictionary *dict = (dictionary *) malloc(sizeof(dictionary));
    init_dict(dict);
    int code = 0;
    int count = 0;
    char str[MAX_CODESIZE];
    unsigned char c;
    while((c = getc(input_file)) != EOF) {
        str[count] = c;
        str[count+1] = '\0';
        int index = get_index(dict, str);
        if(index != -1) {
            code = index;
        }
        else {
            fprintf(output_file, "%d ", code);
            if(add_string(dict, str) != -1) {
                code = dict->size-1;
            }
            count = 0;
            str[count] = c;
            str[count+1] = '\0';
        }
        count++;
    }
    if(count > 0) {
        fprintf(output_file, "%d ", code);
    }
    return 0;
}

// Define a function to decode a string using LZW compression
int decode(FILE *input_file, FILE *output_file) {
    dictionary *dict = (dictionary *) malloc(sizeof(dictionary));
    init_dict(dict);
    int old_code = 0;
    int new_code = 0;
    int count = 0;
    char str[MAX_CODESIZE];
    while(fscanf(input_file, "%d", &new_code) != EOF) {
        if(new_code >= dict->size) {
            sprintf(str, "%s%c", dict->string[old_code], dict->string[old_code][0]);
        }
        else {
            strcpy(str, dict->string[new_code]);
        }
        fputs(str, output_file);
        if(add_string(dict, str) != -1) {
            old_code = new_code;
        }
    }
    return 0;
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *compressed_file = fopen("compressed.txt", "w");
    FILE *output_file = fopen("output.txt", "w");
    encode(input_file, compressed_file);
    fclose(input_file);
    fclose(compressed_file);

    compressed_file = fopen("compressed.txt", "r");
    decode(compressed_file, output_file);
    fclose(compressed_file);
    fclose(output_file);

    return 0;
}