#include <stdio.h>
#include <string.h>

#define NUM_SALARIES 50
#define NUM_BUDGETS  10
#define NUM_REGS     20
#define REG_LEN      20

static void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Reads a float greater than 0, re-prompting on invalid input */
static float readPositiveFloat(const char *prompt) {
    float value;
    printf("%s", prompt);
    while (scanf("%f", &value) != 1 || value <= 0) {
        printf("Invalid amount. Enter a positive number: ");
        clearBuffer();
    }
    clearBuffer();
    return value;
}

/* ---------------- A. Employee salaries ---------------- */
static void salaryPart(void) {
    float salaries[NUM_SALARIES];
    float total = 0, average, highest, lowest, target;
    int i, found = 0;

    printf("\n===== A. EMPLOYEE SALARIES =====\n");
    for (i = 0; i < NUM_SALARIES; i++) {
        char prompt[40];
        sprintf(prompt, "Enter salary %d (N$): ", i + 1);
        salaries[i] = readPositiveFloat(prompt);
    }

    printf("\nAll salaries:\n");
    for (i = 0; i < NUM_SALARIES; i++) {
        printf("%2d. N$%.2f\n", i + 1, salaries[i]);
    }

    highest = lowest = salaries[0];
    for (i = 0; i < NUM_SALARIES; i++) {
        total += salaries[i];
        if (salaries[i] > highest) highest = salaries[i];
        if (salaries[i] < lowest)  lowest = salaries[i];
    }
    average = total / NUM_SALARIES;

    printf("\nAverage salary: N$%.2f\n", average);
    printf("Highest salary: N$%.2f\n", highest);
    printf("Lowest salary : N$%.2f\n", lowest);

    target = readPositiveFloat("\nEnter a salary to search for (N$): ");
    for (i = 0; i < NUM_SALARIES; i++) {
        if (salaries[i] == target) {
            printf("Found at position %d.\n", i + 1);
            found = 1;
        }
    }
    if (!found) printf("Salary not found.\n");
}

/* ---------------- B. Department budgets ---------------- */
static void budgetPart(void) {
    float budgets[NUM_BUDGETS];
    float total = 0, temp;
    int i, j;

    printf("\n===== B. DEPARTMENT BUDGETS =====\n");
    for (i = 0; i < NUM_BUDGETS; i++) {
        char prompt[50];
        sprintf(prompt, "Enter budget for department %d (N$): ", i + 1);
        budgets[i] = readPositiveFloat(prompt);
    }

    printf("\nDepartment budgets:\n");
    for (i = 0; i < NUM_BUDGETS; i++) {
        printf("Department %2d: N$%.2f\n", i + 1, budgets[i]);
        total += budgets[i];
    }

    printf("\nTotal budget  : N$%.2f\n", total);
    printf("Average budget: N$%.2f\n", total / NUM_BUDGETS);

    /* Bubble sort, lowest to highest */
    for (i = 0; i < NUM_BUDGETS - 1; i++) {
        for (j = 0; j < NUM_BUDGETS - 1 - i; j++) {
            if (budgets[j] > budgets[j + 1]) {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\nBudgets sorted lowest to highest:\n");
    for (i = 0; i < NUM_BUDGETS; i++) {
        printf("%2d. N$%.2f\n", i + 1, budgets[i]);
    }
}

/* ---------------- C. Vehicle registrations ---------------- */
static void registrationPart(void) {
    char registrations[NUM_REGS][REG_LEN];
    char target[REG_LEN];
    int i, found = 0;

    printf("\n===== C. VEHICLE REGISTRATION NUMBERS =====\n");
    for (i = 0; i < NUM_REGS; i++) {
        do {
            printf("Enter registration number %d: ", i + 1);
            fgets(registrations[i], REG_LEN, stdin);
            if (strchr(registrations[i], '\n') == NULL) {
                clearBuffer();                       /* input was too long */
            } else {
                registrations[i][strcspn(registrations[i], "\n")] = '\0';
            }
            if (strlen(registrations[i]) == 0) {
                printf("Registration cannot be empty.\n");
            }
        } while (strlen(registrations[i]) == 0);
    }

    printf("\nAll registration numbers:\n");
    for (i = 0; i < NUM_REGS; i++) {
        printf("%2d. %s\n", i + 1, registrations[i]);
    }

    printf("\nEnter a registration number to search for: ");
    fgets(target, REG_LEN, stdin);
    if (strchr(target, '\n') == NULL) clearBuffer();
    target[strcspn(target, "\n")] = '\0';

    for (i = 0; i < NUM_REGS; i++) {
        if (strcmp(registrations[i], target) == 0) {
            printf("Found at position %d.\n", i + 1);
            found = 1;
        }
    }
    if (!found) printf("Registration number not found.\n");
}

int main(void) {
    int choice;

    do {
        printf("\n========================================\n");
        printf("  MUNICIPAL INFORMATION MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Employee Salaries\n");
        printf("2. Department Budgets\n");
        printf("3. Vehicle Registration Numbers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            choice = 0;                 /* invalid, falls into default */
            clearBuffer();
        } else {
            clearBuffer();
        }

        switch (choice) {
            case 1: salaryPart();       break;
            case 2: budgetPart();       break;
            case 3: registrationPart(); break;
            case 4: printf("Goodbye.\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}