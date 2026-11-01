#include <stdio.h>
#include <string.h>
#include "utilities.h"

void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Reads a non-empty line into buf (re-prompts if empty) */
void readLine(const char *prompt, char *buf, int size) {
    do {
        printf("%s", prompt);
        if (fgets(buf, size, stdin) == NULL) {
            buf[0] = '\0';
        } else if (strchr(buf, '\n') == NULL) {
            clearBuffer();                      /* input was too long */
        } else {
            buf[strcspn(buf, "\n")] = '\0';
        }
        if (strlen(buf) == 0) {
            printf("This field cannot be empty.\n");
        }
    } while (strlen(buf) == 0);
}

/* Reads a float that is 0 or more */
float readAmount(const char *prompt) {
    float value;
    printf("%s", prompt);
    while (scanf("%f", &value) != 1 || value < 0) {
        printf("Invalid amount. Enter 0 or more: ");
        clearBuffer();
    }
    clearBuffer();
    return value;
}

/* Reads an int greater than 0 */
int readPositiveInt(const char *prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1 || value <= 0) {
        printf("Invalid number. Enter a positive whole number: ");
        clearBuffer();
    }
    clearBuffer();
    return value;
}

/* Reads a menu choice; returns -1 if the input is not a number */
int readChoice(void) {
    int choice;
    if (scanf("%d", &choice) != 1) {
        choice = -1;
    }
    clearBuffer();
    return choice;
}