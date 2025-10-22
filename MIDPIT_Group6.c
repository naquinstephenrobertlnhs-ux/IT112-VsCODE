#include <stdio.h>      // For input/output functions like printf, scanf, fgets
#include <string.h>     // For string operations such as strcpy, strstr, strcspn
#include <ctype.h>      // For character operations like toupper

#define MAX_PROVIDERS 50 // Maximum number of service providers allowed

// Structure to store service provider details
struct ServiceProvider {
    char name[50];        // Provider name
    char serviceType[50]; // Type of service offered
    char contact[20];     // Contact number
    float rating;         // Rating value (1.0–5.0)
    char review[100];     // Text review from users
};

int main() {

    // Array to store all service providers
    struct ServiceProvider providers[MAX_PROVIDERS];

    // Keeps track of number of registered providers
    int count = 0;

    // Stores the user’s menu choice
    int choice;

    // Used for searching by service type
    char searchType[50];

    // Used for confirming program exit (Y/N)
    char confirmExit;

    // Main program loop
    do {

        // Display main menu
        printf("\n========================================\n");
        printf("   LOCAL SERVICES DIRECTORY SYSTEM\n");
        printf("========================================\n");
        printf("1. Register Service Provider\n");
        printf("2. View All Providers\n");
        printf("3. Search by Service Type\n");
        printf("4. Add Rating and Review\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        // Read user input safely (check if valid number)
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid choice. Try again.\n");
            while (getchar() != '\n'); // clear invalid input
            continue;
        }

        // Clear leftover newline from input buffer
        getchar();

        // Option 1: Register a new service provider
        if (choice == 1) {

            // Check if directory is not full
            if (count < MAX_PROVIDERS) {

                // Input provider name
                printf("\nEnter Provider Name: ");
                fgets(providers[count].name, sizeof(providers[count].name), stdin);
                providers[count].name[strcspn(providers[count].name, "\n")] = 0;

                // Input service type
                printf("Enter Service Type (e.g., Plumber, Electrician): ");
                fgets(providers[count].serviceType, sizeof(providers[count].serviceType), stdin);
                providers[count].serviceType[strcspn(providers[count].serviceType, "\n")] = 0;
                
                // Input contact number
                printf("Enter Contact Number: ");
                fgets(providers[count].contact, sizeof(providers[count].contact), stdin);
                providers[count].contact[strcspn(providers[count].contact, "\n")] = 0;

            if (strlen(providers[count].name) == 0 ||
                    strlen(providers[count].serviceType) == 0 ||
                    strlen(providers[count].contact) == 0) {
                    printf("\nError: All fields are required. Registration cancelled.\n");

                } else {
                    // Set default rating and review
                    providers[count].rating = 0.0;
                    strcpy(providers[count].review, "No reviews yet");

                    // Confirmation message
                    printf("\nProvider Registered Successfully!\n");
                    count++;
                }

                // If directory is full
            } else {
                printf("\nDirectory is full. Cannot register more providers.\n");
            }
        }

        // Option 2: View all registered providers
        else if (choice == 2) {

            // Display header
            printf("\n--- List of Service Providers ---\n");

            // If no providers exist yet
            if (count == 0) {
                printf("No providers registered yet.\n");
            }

            // Otherwise, list all providers
            else {
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

        // Option 3: Search for providers by service type
        else if (choice == 3) {

            // Ask user for search keyword
            printf("\nEnter Service Type to Search: ");
            fgets(searchType, 50, stdin);
            searchType[strcspn(searchType, "\n")] = 0;

            // Variable to check if match is found
            int found = 0;

            // Display search results
            printf("\n--- Search Results ---\n");

            // Loop through all providers to find matches
            for (int i = 0; i < count; i++) {

                // strstr checks if searchType is part of serviceType
                if (strstr(providers[i].serviceType, searchType) != NULL) {

                    // Print matching provider
                    printf("%s - %s - %s\n",
                           providers[i].name,
                           providers[i].serviceType,
                           providers[i].contact);
                    printf("    Rating: %.1f | Review: %s\n",
                           providers[i].rating, providers[i].review);

                    // Mark as found
                    found = 1;
                }
            }

            // If no match found
            if (!found) {
                printf("No providers found for that service type.\n");
            }
        }

        // Option 4: Add rating and review
        else if (choice == 4) {

            // Check if providers exist
            if (count == 0) {
                printf("\nNo providers available to rate.\n");
            }

            // If there are providers
            else {
                int num; // Provider index

                // Ask user which provider to rate
                printf("\nEnter Provider Number to Rate (1-%d): ", count);
                scanf("%d", &num);
                getchar();

                // Check if provider number is valid
                if (num > 0 && num <= count) {

                    // Input new rating
                    printf("Enter rating (1.0-5.0): ");
                    scanf("%f", &providers[num - 1].rating);
                    getchar();

                    // Input short review text
                    printf("Enter short review/feedback: ");
                    fgets(providers[num - 1].review, 100, stdin);
                    providers[num - 1].review[strcspn(providers[num - 1].review, "\n")] = 0;

                    // Confirmation message
                    printf("\n Review and rating added successfully!\n");
                }

                // Invalid provider number
                else {
                    printf("\nInvalid provider number.\n");
                }
            }
        }

        // Option 5: Exit the program
        else if (choice == 5) {

            // Ask for exit confirmation
            printf("\nAre you sure you want to exit? (Y/N): ");
            scanf(" %c", &confirmExit);

            // Convert answer to uppercase (for 'y' or 'Y')
            confirmExit = toupper(confirmExit);

            // If user confirms exit
            if (confirmExit == 'Y') {
                printf("\nExiting Program... Goodbye!\n");
                break; // End loop
            }

            // If user cancels exit
            else {
                printf("\nReturning to main menu...\n");
            }
        }

        // Handle invalid input (not 1–5)
        else {
            printf("\nInvalid choice. Try again.\n");
        }

    // Loop keeps running until user chooses to exit
    } while (1);

    // Program finished successfully
    return 0;
}
