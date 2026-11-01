#include <stdio.h>
#include <string.h>

#define MAX_NAME 50

/* Reads a mark that must be 0 or more, re-prompting on invalid input */
static double readMark(const char *prompt) {
    double mark;
    printf("%s", prompt);
    while (scanf("%lf", &mark) != 1 || mark < 0) {
        printf("Invalid mark. Enter a number of 0 or more: ");
        while (getchar() != '\n');
    }
    return mark;
}

int main(void) {
    char name[MAX_NAME];
    double test1, test2, assignment, total;
    char result[15];

    printf("========================================\n");
    printf("      CONSOLIDATED ASSESSMENT\n");
    printf("========================================\n\n");

    printf("Enter Student Name: ");
    fgets(name, MAX_NAME, stdin);
    name[strcspn(name, "\n")] = '\0';

    test1      = readMark("Enter Test 1 Mark: ");
    test2      = readMark("Enter Test 2 Mark: ");
    assignment = readMark("Enter Assignment Mark: ");

    total = test1 + test2 + assignment;

    if (total >= 75) {
        strcpy(result, "Distinction");
    } else if (total >= 60) {
        strcpy(result, "Credit");
    } else if (total >= 50) {
        strcpy(result, "Pass");
    } else {
        strcpy(result, "Fail");
    }

    printf("\n========================================\n");
    printf("          ASSESSMENT REPORT\n");
    printf("========================================\n");
    printf("%-15s: %s\n",   "Student", name);
    printf("%-15s: %.1f\n", "Test 1", test1);
    printf("%-15s: %.1f\n", "Test 2", test2);
    printf("%-15s: %.1f\n", "Assignment", assignment);
    printf("----------------------------------------\n");
    printf("%-15s: %.1f\n", "Total", total);
    printf("%-15s: %s\n",   "Result", result);
    printf("========================================\n");

    if (total > 100) {
        printf("Note: total is above 100. Check the marks entered.\n");
    }

    return 0;
}