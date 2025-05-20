//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4

typedef struct {
    char symbol[3];
    char name[30];
    int num;
    char category[20];
} Element;

Element elements[118] = {
    {"H", "Hydrogen", 1, "Non-metal"},
    {"He", "Helium", 2, "Noble gas"},
    {"Li", "Lithium", 3, "Alkali metal"},
    {"Be", "Beryllium", 4, "Alkaline earth metal"},
    {"B", "Boron", 5, "Metalloid"},
    {"C", "Carbon", 6, "Non-metal"},
    {"N", "Nitrogen", 7, "Non-metal"},
    {"O", "Oxygen", 8, "Non-metal"},
    {"F", "Fluorine", 9, "Halogen"},
    {"Ne", "Neon", 10, "Noble gas"},
    {"Na", "Sodium", 11, "Alkali metal"},
    {"Mg", "Magnesium", 12, "Alkaline earth metal"},
    {"Al", "Aluminum", 13, "Post-transition metal"},
    {"Si", "Silicon", 14, "Metalloid"},
    {"P", "Phosphorus", 15, "Non-metal"},
    {"S", "Sulfur", 16, "Non-metal"},
    {"Cl", "Chlorine", 17, "Halogen"},
    {"Ar", "Argon", 18, "Noble gas"},
    {"K", "Potassium", 19, "Alkali metal"},
    {"Ca", "Calcium", 20, "Alkaline earth metal"},
    {"Sc", "Scandium", 21, "Transition metal"},
    {"Ti", "Titanium", 22, "Transition metal"},
    {"V", "Vanadium", 23, "Transition metal"},
    {"Cr", "Chromium", 24, "Transition metal"},
    {"Mn", "Manganese", 25, "Transition metal"},
    {"Fe", "Iron", 26, "Transition metal"},
    {"Co", "Cobalt", 27, "Transition metal"},
    {"Ni", "Nickel", 28, "Transition metal"},
    {"Cu", "Copper", 29, "Transition metal"},
    {"Zn", "Zinc", 30, "Transition metal"},
    {"Ga", "Gallium", 31, "Post-transition metal"},
    {"Ge", "Germanium", 32, "Metalloid"},
    {"As", "Arsenic", 33, "Metalloid"},
    {"Se", "Selenium", 34, "Non-metal"},
    {"Br", "Bromine", 35, "Halogen"},
    {"Kr", "Krypton", 36, "Noble gas"},
    {"Rb", "Rubidium", 37, "Alkali metal"},
    {"Sr", "Strontium", 38, "Alkaline earth metal"},
    {"Y", "Yttrium", 39, "Transition metal"},
    {"Zr", "Zirconium", 40, "Transition metal"},
    {"Nb", "Niobium", 41, "Transition metal"},
    {"Mo", "Molybdenum", 42, "Transition metal"},
    {"Tc", "Technetium", 43, "Transition metal"},
    {"Ru", "Ruthenium", 44, "Transition metal"},
    {"Rh", "Rhodium", 45, "Transition metal"},
    {"Pd", "Palladium", 46, "Transition metal"},
    {"Ag", "Silver", 47, "Transition metal"},
    {"Cd", "Cadmium", 48, "Transition metal"},
    {"In", "Indium", 49, "Post-transition metal"},
    {"Sn", "Tin", 50, "Post-transition metal"},
    {"Sb", "Antimony", 51, "Metalloid"},
    {"Te", "Tellurium", 52, "Metalloid"},
    {"I", "Iodine", 53, "Halogen"},
    {"Xe", "Xenon", 54, "Noble gas"},
    {"Cs", "Cesium", 55, "Alkali metal"},
    {"Ba", "Barium", 56, "Alkaline earth metal"},
    {"La", "Lanthanum", 57, "Lanthanide"},
    {"Ce", "Cerium", 58, "Lanthanide"},
    {"Pr", "Praseodymium", 59, "Lanthanide"},
    {"Nd", "Neodymium", 60, "Lanthanide"},
    {"Pm", "Promethium", 61, "Lanthanide"},
    {"Sm", "Samarium", 62, "Lanthanide"},
    {"Eu", "Europium", 63, "Lanthanide"},
    {"Gd", "Gadolinium", 64, "Lanthanide"},
    {"Tb", "Terbium", 65, "Lanthanide"},
    {"Dy", "Dysprosium", 66, "Lanthanide"},
    {"Ho", "Holmium", 67, "Lanthanide"},
    {"Er", "Erbium", 68, "Lanthanide"},
    {"Tm", "Thulium", 69, "Lanthanide"},
    {"Yb", "Ytterbium", 70, "Lanthanide"},
    {"Lu", "Lutetium", 71, "Lanthanide"},
    {"Hf", "Hafnium", 72, "Transition metal"},
    {"Ta", "Tantalum", 73, "Transition metal"},
    {"W", "Tungsten", 74, "Transition metal"},
    {"Re", "Rhenium", 75, "Transition metal"},
    {"Os", "Osmium", 76, "Transition metal"},
    {"Ir", "Iridium", 77, "Transition metal"},
    {"Pt", "Platinum", 78, "Transition metal"},
    {"Au", "Gold", 79, "Transition metal"},
    {"Hg", "Mercury", 80, "Transition metal"},
    {"Tl", "Thallium", 81, "Post-transition metal"},
    {"Pb", "Lead", 82, "Post-transition metal"},
    {"Bi", "Bismuth", 83, "Post-transition metal"},
    {"Po", "Polonium", 84, "Metalloid"},
    {"At", "Astatine", 85, "Halogen"},
    {"Rn", "Radon", 86, "Noble gas"},
    {"Fr", "Francium", 87, "Alkali metal"},
    {"Ra", "Radium", 88, "Alkaline earth metal"},
    {"Ac", "Actinium", 89, "Actinide"},
    {"Th", "Thorium", 90, "Actinide"},
    {"Pa", "Protactinium", 91, "Actinide"},
    {"U", "Uranium", 92, "Actinide"},
    {"Np", "Neptunium", 93, "Actinide"},
    {"Pu", "Plutonium", 94, "Actinide"},
    {"Am", "Americium", 95, "Actinide"},
    {"Cm", "Curium", 96, "Actinide"},
    {"Bk", "Berkelium", 97, "Actinide"},
    {"Cf", "Californium", 98, "Actinide"},
    {"Es", "Einsteinium", 99, "Actinide"},
    {"Fm", "Fermium", 100, "Actinide"},
    {"Md", "Mendelevium", 101, "Actinide"},
    {"No", "Nobelium", 102, "Actinide"},
    {"Lr", "Lawrencium", 103, "Actinide"},
    {"Rf", "Rutherfordium", 104, "Transition metal"},
    {"Db", "Dubnium", 105, "Transition metal"},
    {"Sg", "Seaborgium", 106, "Transition metal"},
    {"Bh", "Bohrium", 107, "Transition metal"},
    {"Hs", "Hassium", 108, "Transition metal"},
    {"Mt", "Meitnerium", 109, "Transition metal"},
    {"Ds", "Darmstadtium", 110, "Transition metal"},
    {"Rg", "Roentgenium", 111, "Transition metal"},
    {"Cn", "Copernicium", 112, "Transition metal"},
    {"Nh", "Nihonium", 113, "Post-transition metal"},
    {"Fl", "Flerovium", 114, "Post-transition metal"},
    {"Mc", "Moscovium", 115, "Post-transition metal"},
    {"Lv", "Livermorium", 116, "Post-transition metal"},
    {"Ts", "Tennessine", 117, "Halogen"},
    {"Og", "Oganesson", 118, "Noble gas"}
};

int generate_question(int questions[], int previous_questions[], int num_questions) {
    srand(time(NULL));
    int question_index = rand() % num_questions;
    while (previous_questions[question_index] == 1) {
        question_index = rand() % num_questions;
    }
    previous_questions[question_index] = 1;
    questions[question_index] = 1;
    return question_index;
}

void print_question(int question_index) {
    printf("%d. What is the symbol of %s?\n", question_index + 1, elements[question_index].name);
    char options[MAX_OPTIONS][3];
    int answer_index = rand() % MAX_OPTIONS;
    options[answer_index][0] = elements[question_index].symbol[0];
    options[answer_index][1] = elements[question_index].symbol[1];
    options[answer_index][2] = '\0';
    int i, j;
    for (i = 0; i < MAX_OPTIONS; i++) {
        if (i == answer_index) continue;
        int option_index = rand() % 118;
        while (option_index == question_index) {
            option_index = rand() % 118;
        }
        options[i][0] = elements[option_index].symbol[0];
        options[i][1] = elements[option_index].symbol[1];
        options[i][2] = '\0';
        for (j = 0; j < i; j++) {
            if (strcmp(options[i], options[j]) == 0) {
                i--;
                break;
            }
        }
    }
    for (i = 0; i < MAX_OPTIONS; i++) {
        printf("%c) %s ", 'A' + i, options[i]);
    }
    printf("\n");
}

int main() {
    int previous_questions[MAX_QUESTIONS] = {0};
    int questions[MAX_QUESTIONS] = {0};
    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("You will be given 10 questions.\n");
    printf("For each question, you must select the correct symbol of the element given its name.\n");
    printf("Good luck!\n");
    int correct = 0;
    int i;
    for (i = 0; i < MAX_QUESTIONS; i++) {
        int question_index = generate_question(questions, previous_questions, 118);
        print_question(question_index);
        char answer;
        do {
            printf("Your answer: ");
            scanf(" %c", &answer);
            answer = toupper(answer);
        } while (answer < 'A' || answer > 'A' + MAX_OPTIONS - 1);
        if (answer - 'A' == rand() % MAX_OPTIONS) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect. The correct answer was %s.\n", elements[question_index].symbol);
        }
    }
    printf("You got %d out of %d questions correct.\n", correct, MAX_QUESTIONS);
    printf("Thanks for playing!\n");
    return 0;
}