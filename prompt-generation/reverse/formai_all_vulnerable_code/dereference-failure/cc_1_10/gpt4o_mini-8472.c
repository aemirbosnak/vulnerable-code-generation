//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writeLoveLetter(const char* filename, const char* loveLetter) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Could not open file for writing");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s", loveLetter);
    fclose(file);
    printf("Your love letter has been sealed with care.\n");
}

char* readLoveLetter(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file for reading");
        return NULL;
    }
    
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char *)malloc(length + 1);
    fread(content, 1, length, file);
    content[length] = '\0';

    fclose(file);
    return content;
}

void loveStory() {
    const char *filename = "love_letter.txt";
    const char *loveLetter = 
        "My Dearest,\n"
        "In the quiet moments of the night, when the stars softly twinkle, \n"
        "I find myself lost in thoughts of you. Your laughter dances in the air, \n"
        "and your smile shines brighter than the countless constellations above.\n\n"
        "Each heartbeat sings your name, echoing through the chambers of my soul. \n"
        "I pen these words not just to express my affection, but to weave our story\n"
        "into the very fabric of this world. Our love is like a timeless melody,\n"
        "playing softly in the background of my heart.\n\n"
        "If only I could gather all the moments we share and paint them on the canvas of eternity.\n"
        "I'll cherish every heartbeat spent in your embrace, every whisper of the wind\n"
        "that carries your sweet fragrance.\n\n"
        "With this letter, sealed in your memory, I promise to hold your essence\n"
        "like precious stardust. Know that you are my dream, my hope, and forever\n"
        "the love that lights my path.\n\n"
        "Yours eternally,\n"
        "Your Admirer";

    writeLoveLetter(filename, loveLetter);

    char *content = readLoveLetter(filename);
    if (content != NULL) {
        printf("\nReading your love letter:\n");
        printf("%s\n", content);
        free(content);
    }
}

void addRomanticLine(const char* filename) {
    const char *romanticLine = 
        "\nP.S. Every moment apart is like an eternity, and I will wait for you\n"
        "across lifetimes, crafting our love saga until the stars align once more.";
    
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Could not open file for appending");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s", romanticLine);
    fclose(file);
    printf("A romantic line has been added to your letter.\n");
}

int main() {
    printf("Welcome to the Love Letter Creator!\n");
    loveStory();

    const char *filename = "love_letter.txt";
    char choice;
    printf("\nWould you like to add a special line to your love letter? (y/n): ");
    scanf(" %c", &choice);
    
    if (choice == 'y' || choice == 'Y') {
        addRomanticLine(filename);
        printf("\nFinal love letter:\n");
        char *finalContent = readLoveLetter(filename);
        if (finalContent != NULL) {
            printf("%s\n", finalContent);
            free(finalContent);
        }
    }

    printf("May your love story continue to blossom eternally.\n");
    return 0;
}