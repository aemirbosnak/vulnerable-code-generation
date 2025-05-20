//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define the movie rating system
enum rating {
    G,
    PG,
    PG13,
    R,
    NC17
};

// Define the movie genres
enum genre {
    ACTION,
    ADVENTURE,
    COMEDY,
    DRAMA,
    FANTASY,
    HORROR,
    MYSTERY,
    ROMANCE,
    SCI_FI,
    THRILLER,
    WESTERN
};

// Define the movie structure
struct movie {
    char *title;
    enum rating rating;
    enum genre genre;
    int year;
};

// Create a new movie
struct movie *create_movie(char *title, enum rating rating, enum genre genre, int year) {
    struct movie *movie = malloc(sizeof(struct movie));
    movie->title = title;
    movie->rating = rating;
    movie->genre = genre;
    movie->year = year;
    return movie;
}

// Print the movie information
void print_movie(struct movie *movie) {
    printf("%s (%d) %s %d\n", movie->title, movie->rating, movie->genre, movie->year);
}

// Get the movie rating from the user
enum rating get_rating() {
    char input;
    do {
        printf("Enter the movie rating (G, PG, PG13, R, NC17): ");
        scanf(" %c", &input);
        input = toupper(input);
    } while (input != 'G' && input != 'P' && input != 'R' && input != 'N');
    switch (input) {
        case 'G':
            return G;
        case 'P':
            return PG;
        case 'R':
            return R;
        case 'N':
            return NC17;
        default:
            return PG13;
    }
}

// Get the movie genre from the user
enum genre get_genre() {
    char input;
    do {
        printf("Enter the movie genre (A, C, D, F, H, M, R, S, T, W): ");
        scanf(" %c", &input);
        input = toupper(input);
    } while (input != 'A' && input != 'C' && input != 'D' && input != 'F' && input != 'H' && input != 'M' && input != 'R' && input != 'S' && input != 'T' && input != 'W');
    switch (input) {
        case 'A':
            return ACTION;
        case 'C':
            return COMEDY;
        case 'D':
            return DRAMA;
        case 'F':
            return FANTASY;
        case 'H':
            return HORROR;
        case 'M':
            return MYSTERY;
        case 'R':
            return ROMANCE;
        case 'S':
            return SCI_FI;
        case 'T':
            return THRILLER;
        case 'W':
            return WESTERN;
        default:
            return ADVENTURE;
    }
}

// Get the movie year from the user
int get_year() {
    int year;
    do {
        printf("Enter the movie year: ");
        scanf(" %d", &year);
    } while (year < 1888);
    return year;
}

// Main function
int main() {
    // Create a new movie
    struct movie *movie = create_movie("The Shawshank Redemption", R, DRAMA, 1994);

    // Print the movie information
    print_movie(movie);

    // Get the movie rating from the user
    movie->rating = get_rating();

    // Get the movie genre from the user
    movie->genre = get_genre();

    // Get the movie year from the user
    movie->year = get_year();

    // Print the movie information
    print_movie(movie);

    return 0;
}