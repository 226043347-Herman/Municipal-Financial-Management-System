#include <stdio.h>
#include <string.h>

#define MAX_NAME 50

int main(void) {
    char municipality[MAX_NAME];
    char mayor[MAX_NAME];
    long population;

    printf("========================================\n");
    printf("   MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");

    printf("\nWelcome to Windhoek Municipality\n\n");

    printf("Enter Municipality Name: ");
    fgets(municipality, MAX_NAME, stdin);
    municipality[strcspn(municipality, "\n")] = '\0';

    printf("Enter Mayor's Name: ");
    fgets(mayor, MAX_NAME, stdin);
    mayor[strcspn(mayor, "\n")] = '\0';

    printf("Enter Population: ");
    while (scanf("%ld", &population) != 1 || population < 0) {
        printf("Invalid population. Enter a positive number: ");
        while (getchar() != '\n');
    }

    printf("\n========================================\n");
    printf("        MUNICIPALITY REPORT\n");
    printf("========================================\n");
    printf("%-20s: %s\n", "Municipality", municipality);
    printf("%-20s: %s\n", "Mayor", mayor);
    printf("%-20s: %ld\n", "Population", population);
    printf("========================================\n");

    return 0;
}