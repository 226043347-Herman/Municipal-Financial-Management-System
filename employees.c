#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "utilities.h"

#define NAME_LEN 50
#define DEPT_LEN 30

static int   ids[MAX_EMPLOYEES];
static char  names[MAX_EMPLOYEES][NAME_LEN];
static char  departments[MAX_EMPLOYEES][DEPT_LEN];
static float basic[MAX_EMPLOYEES];
static float housing[MAX_EMPLOYEES];
static float transport[MAX_EMPLOYEES];
static int   employeeCount = 0;

float calculateSalary(float basicPay, float housingAllow, float transportAllow) {
    return basicPay + housingAllow + transportAllow;      /* gross salary */
}

int getEmployeeCount(void) {
    return employeeCount;
}

float getEmployeeSalary(int index) {
    return calculateSalary(basic[index], housing[index], transport[index]);
}

static void printEmployee(int i) {
    printf("\n--- Employee Found ---\n");
    printf("ID         : %d\n", ids[i]);
    printf("Name       : %s\n", names[i]);
    printf("Department : %s\n", departments[i]);
    printf("Basic      : N$%.2f\n", basic[i]);
    printf("Housing    : N$%.2f\n", housing[i]);
    printf("Transport  : N$%.2f\n", transport[i]);
    printf("Gross      : N$%.2f\n", getEmployeeSalary(i));
}

void addEmployee(void) {
    int id, i;

    if (employeeCount >= MAX_EMPLOYEES) {
        printf("\nEmployee list is full.\n");
        return;
    }

    printf("\n===== ADD EMPLOYEE =====\n");
    id = readPositiveInt("Enter Employee ID: ");
    for (i = 0; i < employeeCount; i++) {
        if (ids[i] == id) {
            printf("Employee ID already exists. Add cancelled.\n");
            return;
        }
    }

    ids[employeeCount] = id;
    readLine("Enter Name: ", names[employeeCount], NAME_LEN);
    readLine("Enter Department: ", departments[employeeCount], DEPT_LEN);
    basic[employeeCount]     = readAmount("Enter Basic Salary (N$): ");
    housing[employeeCount]   = readAmount("Enter Housing Allowance (N$): ");
    transport[employeeCount] = readAmount("Enter Transport Allowance (N$): ");

    employeeCount++;
    printf("\nEmployee added successfully.\n");
}

void displayEmployees(void) {
    int i;

    if (employeeCount == 0) {
        printf("\nNo employees registered yet.\n");
        return;
    }

    printf("\n====================== EMPLOYEE LIST ======================\n");
    printf("%-6s %-18s %-14s %-12s\n", "ID", "Name", "Department", "Gross (N$)");
    printf("-----------------------------------------------------------\n");
    for (i = 0; i < employeeCount; i++) {
        printf("%-6d %-18s %-14s %-12.2f\n",
               ids[i], names[i], departments[i], getEmployeeSalary(i));
    }
    printf("-----------------------------------------------------------\n");
}

void searchEmployee(void) {
    int choice, i, found = 0;

    if (employeeCount == 0) {
        printf("\nNo employees to search.\n");
        return;
    }

    printf("\nSearch by:\n1. Employee ID\n2. Employee Name\nEnter choice: ");
    choice = readChoice();

    if (choice == 1) {
        int id = readPositiveInt("Enter Employee ID: ");
        for (i = 0; i < employeeCount; i++) {
            if (ids[i] == id) {
                printEmployee(i);
                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        char target[NAME_LEN];
        readLine("Enter Employee Name (or part of it): ", target, NAME_LEN);
        for (i = 0; i < employeeCount; i++) {
            if (strstr(names[i], target) != NULL) {
                printEmployee(i);
                found = 1;
            }
        }
    } else {
        printf("Invalid choice.\n");
        return;
    }

    if (!found) {
        printf("\nNo matching employee found.\n");
    }
}

void runSalaryCalculation(void) {
    float b, h, t;

    printf("\n===== CALCULATE SALARY =====\n");
    b = readAmount("Enter basic salary (N$): ");
    h = readAmount("Enter housing allowance (N$): ");
    t = readAmount("Enter transport allowance (N$): ");
    printf("Gross salary: N$%.2f\n", calculateSalary(b, h, t));
}