#include <stdio.h>

/* Reads a non-negative double, re-prompting on invalid input */
static double readMoney(const char *prompt) {
    double value;
    printf("%s", prompt);
    while (scanf("%lf", &value) != 1 || value < 0) {
        printf("Invalid amount. Enter a non-negative number: ");
        while (getchar() != '\n');
    }
    return value;
}

int main(void) {
    double revenue, expenses, balance;
    int departments;
    double payroll, procurement, assets;

    printf("========================================\n");
    printf("      MUNICIPAL BUDGET CALCULATOR\n");
    printf("========================================\n\n");

    /* Core exercise */
    revenue  = readMoney("Enter Total Revenue (N$): ");
    expenses = readMoney("Enter Total Expenses (N$): ");

    balance = revenue - expenses;

    printf("\n--------------- BUDGET -----------------\n");
    printf("%-12s: N$%.2f\n", "Revenue", revenue);
    printf("%-12s: N$%.2f\n", "Expenses", expenses);
    printf("%-12s: N$%.2f\n", "Balance", balance);
    printf("----------------------------------------\n");

    /* Extension exercise */
    printf("\n--- Additional Municipal Information ---\n");

    printf("Enter Number of Departments: ");
    while (scanf("%d", &departments) != 1 || departments < 0) {
        printf("Invalid number. Enter 0 or more: ");
        while (getchar() != '\n');
    }

    payroll     = readMoney("Enter Total Payroll (N$): ");
    procurement = readMoney("Enter Total Procurement (N$): ");
    assets      = readMoney("Enter Total Assets Value (N$): ");

    printf("\n========================================\n");
    printf("     BASIC MUNICIPAL FINANCIAL SUMMARY\n");
    printf("========================================\n");
    printf("%-20s: %d\n",      "Departments", departments);
    printf("%-20s: N$%.2f\n",  "Total Revenue", revenue);
    printf("%-20s: N$%.2f\n",  "Total Expenses", expenses);
    printf("%-20s: N$%.2f\n",  "Balance", balance);
    printf("%-20s: N$%.2f\n",  "Payroll", payroll);
    printf("%-20s: N$%.2f\n",  "Procurement", procurement);
    printf("%-20s: N$%.2f\n",  "Assets", assets);
    printf("----------------------------------------\n");

    if (balance > 0) {
        printf("Status: SURPLUS\n");
    } else if (balance < 0) {
        printf("Status: DEFICIT\n");
    } else {
        printf("Status: BREAK-EVEN\n");
    }
    printf("========================================\n");

    return 0;
}