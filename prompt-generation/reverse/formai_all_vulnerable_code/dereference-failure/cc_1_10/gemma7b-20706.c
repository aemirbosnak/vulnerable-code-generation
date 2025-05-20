//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *resume_text = "Surrealist C Resume Parsing System\n\n"
                            "Name: Leopold Von Schnitzel\n"
                            "Address: 123 Main St., New York, NY 10001\n"
                            "Phone Number: (555) 123-4567\n"
                            "Email Address: leopold@schnitzel.com\n"
                            "\n"
                            "Summary\n"
                            "Surrealist artist with a passion for painting and sculpture. Known for his unique style and creative imagination.\n"
                            "\n"
                            "Skills\n"
                            "Creativity, Imagination, Surrealism, Painting, Sculpture, Problem-solving\n"
                            "\n"
                            "References\n"
                            "Available upon request.\n"
                            "\n"
                            "Additional Notes\n"
                            "Inquisitive mind, boundless energy, and a penchant for the extraordinary.\n";

    // Tokenize the resume text into words
    char *word_list = strtok(resume_text, " ");

    // Create a dictionary of words
    int word_count = 0;
    char **word_dict = malloc(100 * sizeof(char *));
    word_dict[word_count++] = strdup(word_list[0]);
    word_dict[word_count++] = strdup(word_list[1]);
    word_dict[word_count++] = strdup(word_list[2]);
    word_dict[word_count++] = strdup(word_list[3]);
    word_dict[word_count++] = strdup(word_list[4]);
    word_dict[word_count++] = strdup(word_list[5]);
    word_dict[word_count++] = strdup(word_list[6]);
    word_dict[word_count++] = strdup(word_list[7]);
    word_dict[word_count++] = strdup(word_list[8]);
    word_dict[word_count++] = strdup(word_list[9]);

    // Print the words in the dictionary
    for (int i = 0; i < word_count; i++)
    {
        printf("%s ", word_dict[i]);
    }

    // Free the memory allocated for the word dictionary
    free(word_dict);

    return 0;
}