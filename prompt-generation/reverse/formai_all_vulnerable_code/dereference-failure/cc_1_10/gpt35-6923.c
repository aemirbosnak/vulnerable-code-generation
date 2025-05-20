//FormAI DATASET v1.0 Category: Movie Rating System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie {
    char title[50];
    char director[50];
    int year;
    int rating;
};

//Function prototypes
void add_movie(struct movie *m);
void edit_movie(struct movie *m);
void delete_movie(struct movie *m);
void display_movies(struct movie *m);
void rate_movie(struct movie *m);

int main() {
    struct movie list[20];
    int count = 0;
    int choice;

    while(1) {
        printf("Welcome to the Unique C Movie Rating System!\n");
        printf("1. Add a movie\n");
        printf("2. Edit a movie\n");
        printf("3. Delete a movie\n");
        printf("4. Display all movies\n");
        printf("5. Rate a movie\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_movie(&list[count]);
                count++;
                break;
            case 2:
                edit_movie(list);
                break;
            case 3:
                delete_movie(list);
                count--;
                break;
            case 4:
                display_movies(list);
                break;
            case 5:
                rate_movie(list);
                break;
            case 6:
                printf("Thank you for using the Unique C Movie Rating System!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}

void add_movie(struct movie *m) {
    printf("Enter the movie title: ");
    scanf("%s", m->title);
    printf("Enter the movie director: ");
    scanf("%s", m->director);
    printf("Enter the year of release: ");
    scanf("%d", &m->year);
    m->rating = 0;
    printf("Movie successfully added!\n");
}

void edit_movie(struct movie *m) {
    int i, count;
    char title[50];

    if(count == 0) {
        printf("No movies present in the system.\n");
        return;
    }

    printf("Enter the movie title to edit: ");
    scanf("%s", title);

    for(i = 0; i < count; i++) {
        if(strcmp(m[i].title, title) == 0) {
            printf("Enter new movie title: ");
            scanf("%s", m[i].title);
            printf("Enter new movie director: ");
            scanf("%s", m[i].director);
            printf("Enter new year of release: ");
            scanf("%d", &m[i].year);
            printf("Movie details updated!\n");
            return;
        }
    }
    printf("Movie not found.\n");
}

void delete_movie(struct movie *m) {
    int i, count;
    char title[50];

    if(count == 0) {
        printf("No movies present in the system.\n");
        return;
    }

    printf("Enter the movie title to delete: ");
    scanf("%s", title);

    for(i = 0; i < count; i++) {
        if(strcmp(m[i].title, title) == 0) {
            m[i] = m[count-1];
            printf("Movie successfully deleted!\n");
            return;
        }
    }
    printf("Movie not found.\n");
}

void display_movies(struct movie *m) {
    int i, count;
    if(count == 0) {
        printf("No movies present in the system.\n");
        return;
    }

    printf("Title\t\tDirector\tYear\tRating\n");
    for(i = 0; i < count; i++) {
        printf("%s\t\t%s\t\t%d\t%d\n", m[i].title, m[i].director, m[i].year, m[i].rating);
    }
}

void rate_movie(struct movie *m) {
    int i, count, rating;
    char title[50];

    if(count == 0) {
        printf("No movies present in the system.\n");
        return;
    }

    printf("Enter the title of the movie to rate: ");
    scanf("%s", title);

    for(i = 0; i < count; i++) {
        if(strcmp(m[i].title, title) == 0) {
            printf("Enter the rating (out of 10) for %s: ", title);
            scanf("%d", &rating);
            m[i].rating = rating;
            printf("%s rated %d / 10\n", title, rating);
            return;
        }
    }
    printf("Movie not found.\n");
}