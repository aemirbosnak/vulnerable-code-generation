//FormAI DATASET v1.0 Category: Database Indexing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char keyword[20];
    int index;
} Index;

void add_index(const char* keyword, int index, Index** index_list_ptr, int* index_count_ptr) {
    (*index_count_ptr)++;
    *index_list_ptr = realloc(*index_list_ptr, (*index_count_ptr) * sizeof(Index));
    Index new_index;
    strcpy(new_index.keyword, keyword);
    new_index.index = index;
    (*index_list_ptr)[(*index_count_ptr) - 1] = new_index;
}

void search_index(const char* keyword, Index* index_list, int index_count) {
    int found = 0;
    for(int i=0; i<index_count; i++) {
        if(strcmp(index_list[i].keyword, keyword) == 0) {
            printf("Keyword '%s' found at index %d\n", keyword, index_list[i].index);
            found = 1;
        }
    }
    if(!found) {
        printf("Keyword '%s' not found\n", keyword);
    }
}

int main() {
    printf("Initializing indexing system...\n");
    Index* index_list = NULL;
    int index_count = 0;

    add_index("gun", 25, &index_list, &index_count);
    add_index("food", 10, &index_list, &index_count);
    add_index("water", 15, &index_list, &index_count);
    add_index("medical", 30, &index_list, &index_count);
    
    printf("Indexing complete. You can now search for keywords.\n");
    printf("Enter a keyword to search for (or 'exit' to quit): ");
    
    char keyword[20];
    scanf("%s", keyword);
    while(strcmp(keyword, "exit") != 0) {
        search_index(keyword, index_list, index_count);
        printf("Enter a keyword to search for (or 'exit' to quit): ");
        scanf("%s", keyword);
    }

    printf("Exiting indexing system...\n");
    free(index_list);
    return 0;
}