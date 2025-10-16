#include <stdio.h>

int main() {
    int choice;
    float balance = 500.00, amount;

    do {
        printf("\nINDIAN BANK HELP CENTER\n");
        printf("Please Select your Transaction\n");
        printf("[1] Balance Inquiry\n");
        printf("[2] Deposit\n");
        printf("[3] Withdraw\n");
        printf("[4] Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Your current balance: P%.2f\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("P%.2f deposited successfully!\n", amount);
                } else {
                    printf("Invalid deposit amount.\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (amount <= 0) {
                    printf("Invalid withdrawal amount.\n");
                } else if (balance - amount < 100) {
                    printf("Withdrawal denied! You must maintain at least P100.00 in your account.\n");
                } else if (amount > balance) {
                    printf("Insufficient balance!\n");
                } else {
                    balance -= amount;
                    printf("You withdrew P%.2f successfully!\n", amount);
                }
                break;

            case 4:
                printf("Thank you for using INDIAN BANK HELP CENTER!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}