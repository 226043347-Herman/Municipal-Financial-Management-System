#include <stdio.h>
#include <string.h>

#define MAX_NAME  50
#define MAX_EMAIL 50
#define MAX_PHONE 20
#define MAX_TOWN  30

/* Reads a line, removes the newline and re-prompts if the input is empty */
static void readField(const char *prompt, char *buf, int size) {
    do {
        printf("%s", prompt);
        if (fgets(buf, size, stdin) == NULL) {
            buf[0] = '\0';
        } else if (strchr(buf, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);   /* input too long */
        } else {
            buf[strcspn(buf, "\n")] = '\0';
        }
        if (strlen(buf) == 0) {
            printf("This field cannot be empty.\n");
        }
    } while (strlen(buf) == 0);
}

int main(void) {
    char name[MAX_NAME];
    char nameCopy[MAX_NAME];
    char email[MAX_EMAIL];
    char phone[MAX_PHONE];
    char town[MAX_TOWN];
    char searchName[MAX_NAME];

    printf("========================================\n");
    printf("     SUPPLIER INFORMATION SYSTEM\n");
    printf("========================================\n\n");

    /* 1. Accept all four fields */
    readField("Enter Supplier Name: ", name, MAX_NAME);
    readField("Enter Email: ", email, MAX_EMAIL);
    readField("Enter Phone: ", phone, MAX_PHONE);
    readField("Enter Town: ", town, MAX_TOWN);

    /* 2. Display the information */
    printf("\n--------- SUPPLIER INFORMATION ---------\n");
    printf("%-10s: %s\n", "Name", name);
    printf("%-10s: %s\n", "Email", email);
    printf("%-10s: %s\n", "Phone", phone);
    printf("%-10s: %s\n", "Town", town);

    /* 3. Length of the supplier name */
    printf("\nLength of supplier name: %zu characters\n", strlen(name));

    /* 4. Copy the supplier name into a second variable */
    strcpy(nameCopy, name);
    printf("Copied name: %s\n", nameCopy);

    /* 5. Search for the supplier */
    printf("\n--------- SEARCH FOR SUPPLIER ----------\n");
    readField("Enter supplier name to search for: ", searchName, MAX_NAME);

    /* 6. Appropriate message */
    if (strcmp(searchName, nameCopy) == 0) {
        printf("\nSupplier found: %s (%s)\n", name, town);
    } else {
        printf("\nSupplier \"%s\" was not found.\n", searchName);
    }

    return 0;
}