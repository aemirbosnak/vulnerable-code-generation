//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAXLENGTH 100

typedef struct {
    char *key;
    char *value;
} entry;

typedef struct {
    entry **entries;
    int maxsize;
    int size;
} dict;

dict *init_dict(int maxsize) {
    dict *d = (dict *) malloc(sizeof(dict));
    d->entries = (entry **) malloc(sizeof(entry *) * maxsize);
    d->maxsize = maxsize;
    d->size = 0;
    return d;
}

void add(dict *d, char *key, char *value) {
    if(d->size == d->maxsize) {
        printf("Dictionary is full!\n");
        return;
    }
    entry *e = (entry *) malloc(sizeof(entry));
    e->key = key;
    e->value = value;
    d->entries[d->size] = e;
    d->size++;
}

void parse_dict(dict *d, char *jsonstr) {
    int i = 0, j = 0;
    char key[MAXLENGTH], value[MAXLENGTH];

    while(jsonstr[i] != '\0') {
        if(jsonstr[i] == '{') {
            i++;
            continue;
        }
        if(jsonstr[i] == '}') {
            break;
        }
        if(jsonstr[i] == '\"') {
            i++;
            j = 0;
            while(jsonstr[i] != '\"') {
                key[j] = jsonstr[i];
                i++;
                j++;
            }
            key[j] = '\0';
            i++;
        }
        if(jsonstr[i] == ':') {
            i++;
            j = 0;
            while(jsonstr[i] != '\,' && jsonstr[i] != '}') {
                value[j] = jsonstr[i];
                i++;
                j++;
            }
            value[j] = '\0';
        }
        if(isalpha(key[0])) {
            add(d, key, value);
        }
        i++;
    }
}

void print_dict(dict *d) {
    printf("{\n");
    for(int i = 0; i < d->size; i++) {
        printf("\t\"%s\": \"%s\",\n", d->entries[i]->key, d->entries[i]->value);
    }
    printf("}\n");
}

int main() {

    char jsonstr[MAXLENGTH] = "{\"name\":\"Alice\",\"age\":\"25\",\"city\":\"New York\"}";

    dict *person = init_dict(3);
    parse_dict(person, jsonstr);
    print_dict(person);

    return 0;
}