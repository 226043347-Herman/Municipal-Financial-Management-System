#include <stdio.h>
#include "budget.h"
#include "utilities.h"

#define DEPT_NAME_LEN 30
#define VAT_RATE 0.15f          /* 15% VAT */

static char  deptNames[MAX_DEPARTMENTS][DEPT_NAME_LEN];
static float allocated[MAX_DEPARTMENTS];
static float expenditure[MAX_DEPARTMENTS];
static int   deptCount = 0;

float calculateVAT(float amount) {
    return amount * VAT_RATE;
}

float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;              /* remaining budget */
}

int getDepartmentCount(void)            { return deptCount; }
const char *getDepartmentName(int i)    { return deptNames[i]; }
float getAllocated(int i)               { return allocated[i]; }
float getExpenditure(int i)             { return expenditure[i]; }

void enterDepartmentBudget(void) {
    if (deptCount >= MAX_DEPARTMENTS) {
        printf("\nDepartment list is full.\n");
        return;
    }

    printf("\n===== ENTER DEPARTMENT BUDGET =====\n");
    readLine("Enter Department Name: ", deptNames[deptCount], DEPT_NAME_LEN);
    allocated[deptCount]   = readAmount("Enter Allocated Budget (N$): ");
    expenditure[deptCount] = readAmount("Enter Expenditure (N$): ");
    deptCount++;
    printf("\nDepartment budget saved.\n");
}

void displayBudgets(void) {
    int i;

    if (deptCount == 0) {
        printf("\nNo department budgets entered yet.\n");
        return;
    }

    printf("\n======================= DEPARTMENT BUDGETS =======================\n");
    printf("%-16s %-14s %-14s %-14s %-12s\n",
           "Department", "Allocated", "Spent", "Remaining", "Status");
    printf("------------------------------------------------------------------\n");
    for (i = 0; i < deptCount; i++) {
        float remaining = calculateBudget(allocated[i], expenditure[i]);
        printf("%-16s %-14.2f %-14.2f %-14.2f %-12s\n",
               deptNames[i], allocated[i], expenditure[i], remaining,
               remaining < 0 ? "OVER BUDGET" : "WITHIN BUDGET");
    }
    printf("------------------------------------------------------------------\n");
}

void runVATCalculation(void) {
    float amount, vat;

    printf("\n===== CALCULATE VAT =====\n");
    amount = readAmount("Enter amount (N$): ");
    vat = calculateVAT(amount);
    printf("VAT (15%%)       : N$%.2f\n", vat);
    printf("Total incl. VAT : N$%.2f\n", amount + vat);
}

void runBudgetCalculation(void) {
    float revenue, expenses, result;

    printf("\n===== CALCULATE BUDGET =====\n");
    revenue  = readAmount("Enter revenue (N$): ");
    expenses = readAmount("Enter expenses (N$): ");
    result = calculateBudget(revenue, expenses);
    printf("Remaining budget: N$%.2f\n", result);
    printf("Status: %s\n", result < 0 ? "OVER BUDGET" : "WITHIN BUDGET");
}