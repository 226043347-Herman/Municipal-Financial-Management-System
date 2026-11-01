#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 50
#define MAX_NAME  50
#define MAX_EMAIL 50
#define MAX_PHONE 20
#define MAX_TOWN  30
#define VAT_RATE  0.15f      /* 15% VAT */

/* Supplier data (shared by the three supplier functions) */
static char names[MAX_SUPPLIERS][MAX_NAME];
static char emails[MAX_SUPPLIERS][MAX_EMAIL];
static char phones[MAX_SUPPLIERS][MAX_PHONE];
static char towns[MAX_SUPPLIERS][MAX_TOWN];
static int  supplierCount = 0;

/* Function declarations */
void  addSupplier();
void  displaySupplier();
void  searchSupplier();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
void  displayMenu();

/* ---------------- Input helpers ---------------- */
static void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Reads a non-empty line into buf */
static void readField(const char *prompt, char *buf, int size) {
    do {
        printf("%s", prompt);
        if (fgets(buf, size, stdin) == NULL) {
            buf[0] = '\0';
        } else if (strchr(buf, '\n') == NULL) {
            clearBuffer();                       /* input was too long */
        } else {
            buf[strcspn(buf, "\n")] = '\0';
        }
        if (strlen(buf) == 0) {
            printf("This field cannot be empty.\n");
        }
    } while (strlen(buf) == 0);
}

/* Reads a float that must be 0 or more */
static float readAmount(const char *prompt) {
    float value;
    printf("%s", prompt);
    while (scanf("%f", &value) != 1 || value < 0) {
        printf("Invalid amount. Enter 0 or more: ");
        clearBuffer();
    }
    clearBuffer();
    return value;
}

/* ---------------- Supplier functions ---------------- */
void addSupplier() {
    if (supplierCount >= MAX_SUPPLIERS) {
        printf("\nSupplier list is full.\n");
        return;
    }

    printf("\n===== ADD SUPPLIER =====\n");
    readField("Enter Supplier Name: ", names[supplierCount],  MAX_NAME);
    readField("Enter Email: ",         emails[supplierCount], MAX_EMAIL);
    readField("Enter Phone: ",         phones[supplierCount], MAX_PHONE);
    readField("Enter Town: ",          towns[supplierCount],  MAX_TOWN);

    supplierCount++;
    printf("\nSupplier added successfully.\n");
}

void displaySupplier() {
    int i;

    if (supplierCount == 0) {
        printf("\nNo suppliers registered yet.\n");
        return;
    }

    printf("\n=============== SUPPLIER LIST ===============\n");
    printf("%-4s %-18s %-24s %-12s %-12s\n", "No.", "Name", "Email", "Phone", "Town");
    printf("---------------------------------------------------------------------\n");
    for (i = 0; i < supplierCount; i++) {
        printf("%-4d %-18s %-24s %-12s %-12s\n",
               i + 1, names[i], emails[i], phones[i], towns[i]);
    }
    printf("---------------------------------------------------------------------\n");
}

void searchSupplier() {
    char target[MAX_NAME];
    int i, found = 0;

    if (supplierCount == 0) {
        printf("\nNo suppliers to search.\n");
        return;
    }

    printf("\n===== SEARCH SUPPLIER =====\n");
    readField("Enter supplier name to search for: ", target, MAX_NAME);

    for (i = 0; i < supplierCount; i++) {
        if (strcmp(names[i], target) == 0) {
            printf("\n--- Supplier Found ---\n");
            printf("Name : %s\n", names[i]);
            printf("Email: %s\n", emails[i]);
            printf("Phone: %s\n", phones[i]);
            printf("Town : %s\n", towns[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("\nSupplier \"%s\" was not found.\n", target);
    }
}

/* ---------------- Financial functions ---------------- */
float calculateVAT(float amount) {
    return amount * VAT_RATE;
}

float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;      /* gross salary */
}

float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;               /* remaining budget */
}

/* ---------------- Menu function ---------------- */
void displayMenu() {
    printf("\n========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Add Supplier\n");
    printf("2. Display Supplier\n");
    printf("3. Search Supplier\n");
    printf("4. Calculate VAT\n");
    printf("5. Calculate Salary\n");
    printf("6. Calculate Budget\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main(void) {
    int choice;
    float amount, basic, housing, transport, revenue, expenses, result;

    do {
        displayMenu();

        if (scanf("%d", &choice) != 1) {
            choice = 0;                          /* invalid, handled by default */
        }
        clearBuffer();

        switch (choice) {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySupplier();
                break;
            case 3:
                searchSupplier();
                break;
            case 4:
                amount = readAmount("\nEnter amount (N$): ");
                result = calculateVAT(amount);
                printf("VAT (15%%)  : N$%.2f\n", result);
                printf("Total incl. VAT: N$%.2f\n", amount + result);
                break;
            case 5:
                basic     = readAmount("\nEnter basic salary (N$): ");
                housing   = readAmount("Enter housing allowance (N$): ");
                transport = readAmount("Enter transport allowance (N$): ");
                result = calculateSalary(basic, housing, transport);
                printf("Gross salary: N$%.2f\n", result);
                break;
            case 6:
                revenue  = readAmount("\nEnter revenue (N$): ");
                expenses = readAmount("Enter expenses (N$): ");
                result = calculateBudget(revenue, expenses);
                printf("Remaining budget: N$%.2f\n", result);
                if (result < 0) {
                    printf("Status: OVER BUDGET\n");
                } else {
                    printf("Status: WITHIN BUDGET\n");
                }
                break;
            case 7:
                printf("\nGoodbye.\n");
                break;
            default:
                printf("\nInvalid choice. Please enter 1 to 7.\n");
        }
    } while (choice != 7);

    return 0;
}