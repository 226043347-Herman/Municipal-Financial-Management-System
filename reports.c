#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "utilities.h"

void displayEmployeeReport(void) {
    int i, n = getEmployeeCount();
    float total = 0, highest, lowest;

    printf("\n========== EMPLOYEE REPORT ==========\n");
    if (n == 0) {
        printf("No employees registered yet.\n");
        return;
    }

    highest = lowest = getEmployeeSalary(0);
    for (i = 0; i < n; i++) {
        float s = getEmployeeSalary(i);
        total += s;
        if (s > highest) highest = s;
        if (s < lowest)  lowest = s;
    }

    printf("Total Employees : %d\n", n);
    printf("Average Salary  : N$%.2f\n", total / n);
    printf("Highest Salary  : N$%.2f\n", highest);
    printf("Lowest Salary   : N$%.2f\n", lowest);
}

void displayBudgetReport(void) {
    int i, n = getDepartmentCount(), exceeded = 0;
    float totalAllocated = 0, totalSpent = 0;

    printf("\n=========== BUDGET REPORT ===========\n");
    if (n == 0) {
        printf("No department budgets entered yet.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        totalAllocated += getAllocated(i);
        totalSpent     += getExpenditure(i);
    }

    printf("Total Allocated : N$%.2f\n", totalAllocated);
    printf("Total Spent     : N$%.2f\n", totalSpent);
    printf("Remaining       : N$%.2f\n", calculateBudget(totalAllocated, totalSpent));
    printf("Departments exceeding budget:\n");
    for (i = 0; i < n; i++) {
        if (getExpenditure(i) > getAllocated(i)) {
            printf(" - %s (over by N$%.2f)\n", getDepartmentName(i),
                   getExpenditure(i) - getAllocated(i));
            exceeded++;
        }
    }
    if (exceeded == 0) {
        printf(" None\n");
    }
}

void displayReports(void) {
    int choice;

    do {
        printf("\n===== REPORTS =====\n");
        printf("1. Employee Report\n2. Budget Report\n3. Back\n");
        printf("Enter your choice: ");
        choice = readChoice();

        switch (choice) {
            case 1: displayEmployeeReport(); break;
            case 2: displayBudgetReport();   break;
            case 3: break;
            default: printf("Invalid choice. Please enter 1 to 3.\n");
        }
    } while (choice != 3);
}