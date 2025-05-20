//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define WORDS_PER_STORY 5
#define STORIES_PER_EXERCISE 3

// Structure to hold a story
typedef struct {
    char *title;
    char *author;
    char *text;
} story_t;

// Function to generate a random story
story_t *random_story(void) {
    // Generate a random title
    char *title = malloc(10);
    sprintf(title, "The %s Adventure", rand() % 100);

    // Generate a random author
    char *author = malloc(10);
    sprintf(author, "By %s", rand() % 100);

    // Generate a random text
    char *text = malloc(50);
    sprintf(text, "Once upon a time, in a land far, far away, there lived a brave %s who %s",
                    rand() % 10 == 0 ? "princess" : "dragon",
                    rand() % 10 == 0 ? "was sleeping" : "had a quest");

    // Create a story struct
    story_t *story = malloc(sizeof(story_t));
    story->title = title;
    story->author = author;
    story->text = text;

    return story;
}

// Function to print a story
void print_story(story_t *story) {
    printf("Title: %s\nAuthor: %s\nText: %s\n", story->title, story->author, story->text);
}

int main(void) {
    // Create an array of stories
    story_t *stories[STORIES_PER_EXERCISE];
    for (int i = 0; i < STORIES_PER_EXERCISE; i++) {
        stories[i] = random_story();
    }

    // Print each story
    for (int i = 0; i < STORIES_PER_EXERCISE; i++) {
        print_story(stories[i]);
    }

    return 0;
}