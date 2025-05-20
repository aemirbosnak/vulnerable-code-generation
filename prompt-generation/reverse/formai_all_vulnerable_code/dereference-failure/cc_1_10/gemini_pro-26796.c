//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
typedef enum {
    G,
    PG,
    PG13,
    R,
    NC17
} rating;

// Define the movie struct
typedef struct {
    char *title;
    int year;
    rating rating;
} movie;

// Define the function to print the movie rating system
void print_rating_system() {
    printf("Movie Rating System:\n");
    printf("G: General Audiences. All ages admitted.\n");
    printf("PG: Parental Guidance Suggested. Some material may not be suitable for children.\n");
    printf("PG13: Parents Strongly Cautioned. Some material may be inappropriate for children under 13.\n");
    printf("R: Restricted. Under 17 requires accompanying parent or adult guardian.\n");
    printf("NC17: No One 17 and Under Admitted.\n");
}

// Define the function to get the movie rating
rating get_rating() {
    int rating;
    printf("Enter the movie rating (0-4): ");
    scanf("%d", &rating);
    return rating;
}

// Define the function to create a movie
movie *create_movie() {
    // Allocate memory for the movie
    movie *m = malloc(sizeof(movie));

    // Get the movie title
    printf("Enter the movie title: ");
    char *title = malloc(100);
    scanf("%s", title);

    // Get the movie year
    printf("Enter the movie year: ");
    int year;
    scanf("%d", &year);

    // Get the movie rating
    rating rating = get_rating();

    // Set the movie fields
    m->title = title;
    m->year = year;
    m->rating = rating;

    // Return the movie
    return m;
}

// Define the function to print the movie
void print_movie(movie *m) {
    printf("Movie Title: %s\n", m->title);
    printf("Movie Year: %d\n", m->year);
    printf("Movie Rating: ");
    switch (m->rating) {
        case G:
            printf("G");
            break;
        case PG:
            printf("PG");
            break;
        case PG13:
            printf("PG13");
            break;
        case R:
            printf("R");
            break;
        case NC17:
            printf("NC17");
            break;
    }
    printf("\n");
}

// Define the main function
int main() {
    // Print the movie rating system
    print_rating_system();

    // Create a movie
    movie *m = create_movie();

    // Print the movie
    print_movie(m);

    // Free the memory allocated for the movie
    free(m->title);
    free(m);

    return 0;
}