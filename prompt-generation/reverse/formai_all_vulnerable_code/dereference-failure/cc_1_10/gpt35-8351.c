//FormAI DATASET v1.0 Category: Ebook reader ; Style: authentic
#include<stdio.h>
#include<stdlib.h>

typedef struct page{
    char data[100]; // maximum 100 characters per page
    struct page* next; // pointer to next page
} Page;

typedef struct book{
    Page* first_page; // pointer to first page
    int num_pages; // number of pages in book
} Book;

// function to create a new page
Page* new_page(){
    Page* p = (Page*) malloc(sizeof(Page));
    p->next = NULL;
    return p;
}

// function to add a new page at the end of the book
void add_page(Book* b){
    Page* newp = new_page();
    if(b->first_page == NULL){ // if book has no pages
        b->first_page = newp;
    }
    else{ // find last page and add new page
        Page* last = b->first_page;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = newp;
    }
    b->num_pages++;
}

// function to read a page and print it
void read_page(Page* p){
    printf("%s\n", p->data);
}

// function to read all pages in a book
void read_book(Book* b){
    Page* current = b->first_page;
    while(current != NULL){
        read_page(current);
        current = current->next;
    }
}

// function to delete a book (free up memory)
void delete_book(Book* b){
    Page* current = b->first_page;
    while(current != NULL){
        Page* next = current->next;
        free(current);
        current = next;
    }
    b->first_page = NULL;
    b->num_pages = 0;
    free(b);
}

int main(){
    // create a new empty book
    Book* b = (Book*) malloc(sizeof(Book));
    b->first_page = NULL;
    b->num_pages = 0;

    // add some pages to the book
    add_page(b);
    Page* p = b->first_page;
    sprintf(p->data, "This is the first page of the book.");
    add_page(b);
    p = p->next;
    sprintf(p->data, "This is the second page of the book.");
    add_page(b);
    p = p->next;
    sprintf(p->data, "This is the third page of the book.");

    // read the entire book
    read_book(b);

    // delete the book
    delete_book(b);

    return 0;
}