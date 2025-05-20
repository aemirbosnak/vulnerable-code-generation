//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DICT_SIZE 10000
#define MAX_CODE_SIZE 1000

typedef struct {
    char *str;
    int code;
} DictItem;

typedef struct {
    DictItem dict[MAX_DICT_SIZE];
    int dict_size;
    FILE *in_file;
    FILE *out_file;
} Compressor;

void init_dict(Compressor *c) {
    c->dict_size = 0;
    c->in_file = NULL;
    c->out_file = NULL;
}

void add_dict_item(Compressor *c, char *str, int code) {
    if (c->dict_size >= MAX_DICT_SIZE) {
        printf("Error: dictionary is full\n");
        return;
    }
    DictItem item = {str, code};
    c->dict[c->dict_size++] = item;
}

int get_dict_index(Compressor *c, char *str) {
    for (int i = 0; i < c->dict_size; i++) {
        if (strcmp(c->dict[i].str, str) == 0) {
            return c->dict[i].code;
        }
    }
    return -1;
}

void write_code(Compressor *c, int code) {
    if (c->out_file == NULL) {
        printf("Error: output file not opened\n");
        return;
    }
    fwrite(&code, sizeof(int), 1, c->out_file);
}

void write_string(Compressor *c, char *str) {
    int index = get_dict_index(c, str);
    if (index >= 0) {
        write_code(c, index);
    } else {
        add_dict_item(c, str, c->dict_size);
        write_code(c, c->dict_size - 1);
    }
}

int main(int argc, char *argv[]) {
    Compressor c;
    init_dict(&c);
    c.in_file = fopen(argv[1], "rb");
    if (c.in_file == NULL) {
        printf("Error: input file not found\n");
        return 1;
    }
    c.out_file = fopen(argv[2], "wb");
    if (c.out_file == NULL) {
        printf("Error: output file not found\n");
        return 1;
    }
    char buffer[1024];
    int code_size = 0;
    while (fread(buffer, 1, 1024, c.in_file) > 0) {
        for (int i = 0; i < strlen(buffer); i++) {
            write_string(&c, buffer + i);
        }
    }
    fclose(c.in_file);
    fclose(c.out_file);
    return 0;
}