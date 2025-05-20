//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: medieval
//  A Medieval File Synchronizer: A Chronicle of Synchronization
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The Scroll structure to hold the enchanting tales of synchronizations
typedef struct Scroll {
    char *scroll_name;
    char *content;
} Scroll;

// Function to create a new scroll
Scroll *create_scroll(const char *name, const char *content) {
    Scroll *new_scroll = malloc(sizeof(Scroll));
    new_scroll->scroll_name = strdup(name);
    new_scroll->content = strdup(content);
    return new_scroll;
}

// Function to destroy a scroll, turning it back to dust
void destroy_scroll(Scroll *scroll) {
    free(scroll->scroll_name);
    free(scroll->content);
    free(scroll);
}

// Function to display the contents of the scroll
void display_scroll(const Scroll *scroll) {
    printf("Scroll of %s:\n", scroll->scroll_name);
    printf("%s\n", scroll->content);
}

// Function to synchronize two scrolls, merging their tales
Scroll *synchronize_scrolls(const Scroll *scroll1, const Scroll *scroll2) {
    char *merged_content;
    
    // Craft the combined tale
    asprintf(&merged_content, "%s\n\nAnd thus spoke the scroll of %s:\n%s\n\nWho joins with the scroll of %s:\n%s",
              scroll1->content, 
              scroll1->scroll_name,
              scroll1->content,
              scroll2->scroll_name,
              scroll2->content);

    // Create a new scroll to hold the combined tale
    return create_scroll("Combined Scroll", merged_content);
}

// Function to save the scroll's content to an eternal archive (file)
void save_scroll_to_file(const Scroll *scroll) {
    char filename[50];
    snprintf(filename, sizeof(filename), "%s.txt", scroll->scroll_name);
    
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Alas! Failed to save the scroll to the archives.\n");
        return;
    }
    
    fprintf(file, "%s\n", scroll->content);
    fclose(file);
    printf("The scroll of %s has been inscribed into the eternal archive '%s.txt'.\n", 
           scroll->scroll_name, scroll->scroll_name);
}

int main() {
    // The grand initial scrolls telling tales of valor
    Scroll *scroll1 = create_scroll("Valiant Knight", "In the days of old, a knight did rise to defend the realm.");
    Scroll *scroll2 = create_scroll("Cunning Sorcerer", "Amidst shadows, the sorcerer conjured spells of ancient lore.");

    // Display the original scrolls
    display_scroll(scroll1);
    display_scroll(scroll2);

    // The grand synchronization ceremony
    Scroll *combined_scroll = synchronize_scrolls(scroll1, scroll2);
    
    // Display the newly minted scroll
    display_scroll(combined_scroll);
    
    // Save the new scroll to the eternal archive
    save_scroll_to_file(combined_scroll);
    
    // Time to say farewell to our scrolls
    destroy_scroll(scroll1);
    destroy_scroll(scroll2);
    destroy_scroll(combined_scroll);

    return 0;
}