#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "reports.h"
#include "utilities.h"

static void displayMenu(void) {
    printf("\n========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf(" 1. Add Employee\n");
    printf(" 2. Display Employees\n");
    printf(" 3. Search Employee\n");
    printf(" 4. Calculate Salary\n");
    printf(" 5. Enter Department Budget\n");
    printf(" 6. Display Department Budgets\n");
    printf(" 7. Calculate Budget\n");
    printf(" 8. Calculate VAT\n");
    printf(" 9. Reports\n");
    printf("10. Exit\n");
    printf("Enter your choice: ");
}

int main(void) {
    int choice;

    do {
        displayMenu();
        choice = readChoice();

        switch (choice) {
            case 1:  addEmployee();           break;
            case 2:  displayEmployees();      break;
            case 3:  searchEmployee();        break;
            case 4:  runSalaryCalculation();  break;
            case 5:  enterDepartmentBudget(); break;
            case 6:  displayBudgets();        break;
            case 7:  runBudgetCalculation();  break;
            case 8:  runVATCalculation();     break;
            case 9:  displayReports();        break;
            case 10: printf("\nGoodbye.\n");  break;
            default: printf("\nInvalid choice. Please enter 1 to 10.\n");
        }
    } while (choice != 10);

    return 0;
}