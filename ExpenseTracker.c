// File: ExpenseTracker.c

#include <stdio.h>
#include <string.h>

#define MAX_EXPENSES 100

// Define the structure
struct Expense {
    char date[20];
    char item[50];
    float amount;
};

// Function declarations
void addExpense(struct Expense expenses[], int *count);
void viewExpenses(struct Expense expenses[], int count);
void calculateTotal(struct Expense expenses[], int count);

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    printf("\n===== Personal Expense Tracker =====\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Calculate Total Spent\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume the newline after number input

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                calculateTotal(expenses, count);
                break;
            case 4:
                printf("\nThank you for using Expense Tracker!\n");
                return 0;
            default:
                printf("\n⚠️ Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add a new expense
void addExpense(struct Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("\n⚠️ Expense list full! Cannot add more expenses.\n");
        return;
    }

    printf("\nEnter date (DD-MM-YYYY): ");
    fgets(expenses[*count].date, sizeof(expenses[*count].date), stdin);
    expenses[*count].date[strcspn(expenses[*count].date, "\n")] = 0; // remove newline

    printf("Enter item: ");
    fgets(expenses[*count].item, sizeof(expenses[*count].item), stdin);
    expenses[*count].item[strcspn(expenses[*count].item, "\n")] = 0; // remove newline

    printf("Enter amount: ");
    scanf("%f", &expenses[*count].amount);
    getchar(); // consume leftover newline

    (*count)++;
    printf("✅ Expense added successfully!\n");
}

// Function to view all expenses
void viewExpenses(struct Expense expenses[], int count) {
    if (count == 0) {
        printf("\n⚠️ No expenses to show!\n");
        return;
    }

    printf("\n----- List of Expenses -----\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Date: %s | Item: %s | Amount: ₹%.2f\n", i + 1, expenses[i].date, expenses[i].item, expenses[i].amount);
    }
}

// Function to calculate total spending
void calculateTotal(struct Expense expenses[], int count) {
    if (count == 0) {
        printf("\n⚠️ No expenses to calculate!\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    printf("\n💰 Total Spent: ₹%.2f\n", total);
}
