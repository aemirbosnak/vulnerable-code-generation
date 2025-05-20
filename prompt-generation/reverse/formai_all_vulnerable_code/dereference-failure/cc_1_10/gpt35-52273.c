//FormAI DATASET v1.0 Category: Ebook reader ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 60 //Length of each page

int pages = 0; //Total Pages in Ebook
char *ebook_pages[PAGE_SIZE]; //Array to store Ebook pages

int main() {
    FILE *fp;
    char filename[50];

    printf("Enter Ebook filename: ");
    scanf("%s", filename);
    
    //Open Ebook file
    fp = fopen(filename, "r");
    
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }
    
    int i;
    //Get total number of pages
    while (!feof(fp)) {
        ebook_pages[pages] = (char*)malloc(PAGE_SIZE * sizeof(char));
        fgets(ebook_pages[pages], PAGE_SIZE, fp);
        pages++;
    }
    
    int current_page = 0;
    char input;
    do {
        //Clear console
        system("clear");
        
        //Print current page
        printf("%s", ebook_pages[current_page]);
        
        printf("\n\n");
        
        //Prompt user for navigation options
        printf("Press 'n' to move to next page or 'p' to go to previous page.\n");
        printf("Press 'q' to quit Ebook reader.\n");
        scanf(" %c", &input);
        
        switch (input) {
            case 'n':
                if (current_page < pages - 1) {
                    current_page++;
                }
                break;
            case 'p':
                if (current_page >= 1) {
                    current_page--;
                }
                break;
            case 'q':
                printf("Quitting Ebook reader...\n");
                break;
            default:
                printf("Invalid input\n");
        }
    } while (input != 'q');

    //Free allocated memory
    for (i = 0; i < pages; i++) {
        free(ebook_pages[i]);
    }
    
    return 0;
}