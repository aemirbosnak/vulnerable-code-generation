//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 200
#define MAX_ARRAY_SIZE 100

// Structure to represent a scientific paper
typedef struct {
    char *title;
    char *author;
    char *journal;
    int year;
    char *abstract;
} paper_t;

// Function to allocate memory for a scientific paper
paper_t *alloc_paper(void) {
    paper_t *paper = (paper_t *)malloc(sizeof(paper_t));
    paper->title = (char *)malloc(MAX_STR_LEN * sizeof(char));
    paper->author = (char *)malloc(MAX_STR_LEN * sizeof(char));
    paper->journal = (char *)malloc(MAX_STR_LEN * sizeof(char));
    paper->year = 0;
    paper->abstract = (char *)malloc(MAX_STR_LEN * sizeof(char));
    return paper;
}

// Function to deallocate memory for a scientific paper
void dealloc_paper(paper_t *paper) {
    free(paper->title);
    free(paper->author);
    free(paper->journal);
    free(paper->abstract);
    free(paper);
}

// Function to allocate memory for an array of scientific papers
paper_t **alloc_array(int size) {
    paper_t **array = (paper_t **)malloc(size * sizeof(paper_t *));
    for (int i = 0; i < size; i++) {
        array[i] = alloc_paper();
    }
    return array;
}

// Function to deallocate memory for an array of scientific papers
void dealloc_array(paper_t **array, int size) {
    for (int i = 0; i < size; i++) {
        dealloc_paper(array[i]);
    }
    free(array);
}

// Example program to demonstrate memory management
int main(void) {
    srand(time(NULL)); // for randomizing array size
    int array_size = rand() % 10 + 1; // allocate array of size 1 to 10
    paper_t **array = alloc_array(array_size);

    // Populate the array with random scientific papers
    for (int i = 0; i < array_size; i++) {
        array[i] = alloc_paper();
        strcpy(array[i]->title, "Random Paper ");
        strcpy(array[i]->author, "Random Author ");
        array[i]->year = rand() % 100 + 1;
        strcpy(array[i]->abstract, "This is a random abstract ");
    }

    // Use the array of scientific papers for a while
    for (int i = 0; i < array_size; i++) {
        printf("Paper %d: %s\n", i, array[i]->title);
    }

    // Deallocate memory for the array of scientific papers
    dealloc_array(array, array_size);

    return 0;
}