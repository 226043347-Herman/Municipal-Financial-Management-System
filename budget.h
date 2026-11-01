#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPARTMENTS 10

void  enterDepartmentBudget(void);
void  displayBudgets(void);
float calculateVAT(float amount);
float calculateBudget(float revenue, float expenses);
void  runVATCalculation(void);
void  runBudgetCalculation(void);

/* Used by the reports module */
int         getDepartmentCount(void);
const char *getDepartmentName(int index);
float       getAllocated(int index);
float       getExpenditure(int index);

#endif