#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PROVIDERS 50

struct ServiceProvider {
    char name[50];
    char serviceType[50];
    char contact[20];
    float rating;
    char review[100];
};

int main() {
    struct ServiceProvider providers[MAX_PROVIDERS];
    int count = 0;
    int choice;
    char searchType[50];
    char confirmExit; // for exit confirmation

    do {
        printf("\n========================================\n");
        printf("   LOCAL SERVICES DIRECTORY SYSTEM\n");
        printf("========================================\n");
        printf("1. Register Service Provider\n");
        printf("2. View All Providers\n");
        printf("3. Search by Service Type\n");
        printf("4. Add Rating and Review\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        if (choice == 1) {
            if (count < MAX_PROVIDERS) {
                printf("\nEnter Provider Name: ");
                fgets(providers[count].name, 50, stdin);
                providers[count].name[strcspn(providers[count].name, "\n")] = 0;

                printf("Enter Service Type (e.g., Plumber, Electrician): ");
                fgets(providers[count].serviceType, 50, stdin);
                providers[count].serviceType[strcspn(providers[count].serviceType, "\n")] = 0;

                printf("Enter Contact Number: ");
                fgets(providers[count].contact, 20, stdin);
                providers[count].contact[strcspn(providers[count].contact, "\n")] = 0;

                providers[count].rating = 0;
                strcpy(providers[count].review, "No reviews yet");

                printf("\n Provider Registered Successfully!\n");
                count++;
            } else {
                printf("\n Directory is full. Cannot register more providers.\n");
            }
        }
        else if (choice == 2) {
            printf("\n--- List of Service Providers ---\n");
            if (count == 0) {
                printf("No providers registered yet.\n");
            } else {
                for (int i = 0; i < count; i++) {
                    printf("%d. %s - %s - %s\n", i + 1,
                           providers[i].name,
                           providers[i].serviceType,
                           providers[i].contact);
                    printf("    Rating: %.1f | Review: %s\n",
                           providers[i].rating, providers[i].review);
                }
            }
        }
        else if (choice == 3) {
            printf("\nEnter Service Type to Search: ");
            fgets(searchType, 50, stdin);
            searchType[strcspn(searchType, "\n")] = 0;

            int found = 0;
            printf("\n--- Search Results ---\n");
            for (int i = 0; i < count; i++) {
                if (strstr(providers[i].serviceType, searchType) != NULL) {
                    printf("%s - %s - %s\n",
                           providers[i].name,
                           providers[i].serviceType,
                           providers[i].contact);
                    printf("    Rating: %.1f | Review: %s\n",
                           providers[i].rating, providers[i].review);
                    found = 1;
                }
            }
            if (!found) {
                printf("No providers found for that service type.\n");
            }
        }
        else if (choice == 4) {
            if (count == 0) {
                printf("\nNo providers available to rate.\n");
            } else {
                int num;
                printf("\nEnter Provider Number to Rate (1-%d): ", count);
                scanf("%d", &num);
                getchar();

                if (num > 0 && num <= count) {
                    printf("Enter rating (1.0-5.0): ");
                    scanf("%f", &providers[num - 1].rating);
                    getchar();

                    printf("Enter short review: ");
                    fgets(providers[num - 1].review, 100, stdin);
                    providers[num - 1].review[strcspn(providers[num - 1].review, "\n")] = 0;

                    printf("\n Review and rating added successfully!\n");
                } else {
                    printf("\nInvalid provider number.\n");
                }
            }
        }
        else if (choice == 5) {
            printf("\nAre you sure you want to exit? (Y/N): ");
            scanf(" %c", &confirmExit);
            confirmExit = toupper(confirmExit);

            if (confirmExit == 'Y') {
                printf("\nExiting Program... Goodbye!\n");
                break;
            } else {
                printf("\nReturning to main menu...\n");
            }
        }
        else {
            printf("\nInvalid choice. Try again.\n");
        }

    } while (1); // runs until user confirms exit

    return 0;
}
