#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 50

void  addEmployee(void);
void  displayEmployees(void);
void  searchEmployee(void);
float calculateSalary(float basic, float housing, float transport);
void  runSalaryCalculation(void);

/* Used by the reports module */
int   getEmployeeCount(void);
float getEmployeeSalary(int index);

#endif