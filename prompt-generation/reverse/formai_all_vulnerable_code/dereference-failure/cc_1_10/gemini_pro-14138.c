//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 16
#define MAX_DICT_SIZE 4096

typedef struct {
    unsigned char *code;
    unsigned int length;
} code_t;

typedef struct {
    unsigned char *dict;
    unsigned int size;
} dict_t;

code_t *codes;
dict_t *dict;

void init_dict(void)
{
    dict = malloc(sizeof(dict_t));
    dict->dict = malloc(MAX_DICT_SIZE);
    dict->size = 0;
}

void free_dict(void)
{
    free(dict->dict);
    free(dict);
}

void add_to_dict(unsigned char *str, unsigned int length)
{
    if (dict->size + length > MAX_DICT_SIZE) {
        return;
    }
    memcpy(dict->dict + dict->size, str, length);
    dict->size += length;
}

code_t *find_in_dict(unsigned char *str, unsigned int length)
{
    unsigned int i;
    for (i = 0; i < dict->size; i++) {
        if (!strncmp(dict->dict + i, str, length)) {
            return &codes[i];
        }
    }
    return NULL;
}

void add_to_codes(unsigned char *str, unsigned int length)
{
    code_t *code;
    code = malloc(sizeof(code_t));
    code->code = malloc(MAX_CODE_LENGTH);
    code->length = length;
    memcpy(code->code, str, length);
    codes = realloc(codes, (dict->size + 1) * sizeof(code_t));
    codes[dict->size] = *code;
    dict->size++;
}

void compress(unsigned char *str, unsigned int length)
{
    unsigned int i, j;
    code_t *code;
    for (i = 0; i < length; i++) {
        for (j = i + 1; j <= length; j++) {
            code = find_in_dict(str + i, j - i);
            if (code) {
                printf("%d ", code->length);
                i = j;
                break;
            }
        }
        if (j > length) {
            add_to_dict(str + i, 1);
            printf("1 ");
            i++;
        }
    }
    printf("\n");
}

void decompress(void)
{
    unsigned int i, length;
    unsigned char *str;
    while (scanf("%d", &length) != EOF) {
        str = malloc(length);
        for (i = 0; i < length; i++) {
            str[i] = dict->dict[i];
        }
        printf("%s", str);
        free(str);
    }
}

int main(void)
{
    init_dict();
    compress("abracadabra", 11);
    decompress();
    free_dict();
    return 0;
}