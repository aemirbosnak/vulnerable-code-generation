//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>

typedef struct word {
    char *s;
    int count;
} word;

typedef struct spam_filter {
    struct word *words;
    int words_len;
} spam_filter;

int compare_words(const void* a, const void* b) {
    return strcmp(((struct word*)a)->s, ((struct word*)b)->s);
}

spam_filter* load_filter(char *filename) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    spam_filter* filter = malloc(sizeof(spam_filter));
    if(!filter) return NULL;
    
    filter->words = NULL;
    filter->words_len = 0;

    fp = fopen(filename, "r");
    if(!fp) return NULL;

    while((read = getline(&line, &len, fp)) != -1) {
        if(*line == '\0') {
            free(line);
            line = NULL;
            continue;
        }
       
        char *s = strdup(line);
        qsort(filter->words, filter->words_len, sizeof(word), compare_words);
        struct word *w = bsearch(&s, filter->words, filter->words_len, sizeof(word), compare_words);
        if(!w) {
            filter->words = realloc(filter->words, (filter->words_len + 1) * sizeof(word));
            if(!filter->words) return NULL;
            filter->words_len += 1;
            filter->words[filter->words_len - 1].s = s;
            filter->words[filter->words_len - 1].count = 0;
        }
        filter->words[w - filter->words].count++;
    }
    
    qsort(filter->words, filter->words_len, sizeof(word), compare_words);
    
    fclose(fp);
    free(line);
    
    return filter;
}

int check_word(spam_filter *filter, char *s) {
    struct word *w = bsearch(&s, filter->words, filter->words_len, sizeof(word), compare_words);
    return w ? w->count : 0;
}

void destroy_filter(spam_filter *filter) {
    int i;
    for(i = 0; i < filter->words_len; i++) {
        free(filter->words[i].s);
    }
    free(filter->words);
    free(filter);
}

int main(int argc, char **argv) {
    spam_filter *filter;
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <filter file>\n", argv[0]);
        return 1;
    }
    filter = load_filter(argv[1]);
    if(!filter) {
        fprintf(stderr, "Error loading filter file\n");
        return 1;
    }
    while(1) {
        char *line = NULL;
        char *word;
        int spam_score = 0;
        int i;
       
        size_t len = 0;
        ssize_t read;
       
        int c;
        while(1) {
            c = getchar();
            if(c == EOF || c == '\n' || c == '\r') break;
        }

        if(c == EOF) break;
       
        line = malloc(len + 1);
        if(!line) {
            fprintf(stderr, "Error allocating memory\n");
            destroy_filter(filter);
            return 1;
        }
        
        getline(&line, &len, stdin);
        line[len - 1] = '\0';
        
        /* Tokenize the line and check each word against the filter */
        word = strtok(line, " ");
        while(word) {
            spam_score += check_word(filter, word);
            word = strtok(NULL, " ");
        }
       
        /* Display the results */
        if(spam_score == 0) {
            printf("Not spam\n");
        } else {
            printf("Spam: %d\n", spam_score);
        }
        free(line);
    }

    destroy_filter(filter);
    return 0;
}