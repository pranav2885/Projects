#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 100
#define MAX_WEBSITE_LENGTH 100
#define HASH_TABLE_SIZE 101

// Structure to store user credentials
struct Credential {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char website[MAX_WEBSITE_LENGTH]; // New variable for the website name
    struct Credential* next; // Pointer for chaining
};

// Hash table to store credentials
struct Credential* hashTable[HASH_TABLE_SIZE];

// Hash function
unsigned long hashString(const char* str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash % HASH_TABLE_SIZE;
}

// Function to add a new credential
void addCredential(const char* username, const char* password, const char* website) {
    struct Credential* newCredential = (struct Credential*)malloc(sizeof(struct Credential));
    if (!newCredential) {
        printf("Memory allocation error.\n");
        return;
    }

    strncpy(newCredential->username, username, MAX_USERNAME_LENGTH - 1);
    newCredential->username[MAX_USERNAME_LENGTH - 1] = '\0';

    strncpy(newCredential->password, password, MAX_PASSWORD_LENGTH - 1);
    newCredential->password[MAX_PASSWORD_LENGTH - 1] = '\0';

    strncpy(newCredential->website, website, MAX_WEBSITE_LENGTH - 1);
    newCredential->website[MAX_WEBSITE_LENGTH - 1] = '\0';

    // Hash the username to determine the index in the hash table
    unsigned long hashValue = hashString(newCredential->username);

    // Insert the new credential at the beginning of the linked list (chaining)
    newCredential->next = hashTable[hashValue];
    hashTable[hashValue] = newCredential;

    printf("Credential added successfully.\n");
}

// Function to view stored credentials
void viewCredentials() {
    printf("\nStored Credentials:\n");

    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        struct Credential* current = hashTable[i];

        while (current != NULL) {
            printf("Username: %s, Password: %s, Website: %s\n", current->username, current->password, current->website);
            current = current->next;
        }
    }
}

// Function to search for credentials based on the website name
void searchCredential(const char* website) {
    printf("\nSearch Results for Website: %s\n", website);

    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        struct Credential* current = hashTable[i];
        while (current != NULL) {
            if (strcmp(current->website, website) == 0) {
                printf("Username: %s, Password: %s\n", current->username, current->password);
            }
            current = current->next;
        }
    }
}

int main() {
    int choice;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char website[MAX_WEBSITE_LENGTH];

    do {
        printf("\nPassword Manager Menu:\n");
        printf("1. Add Credential\n");
        printf("2. Search Credentials\n");
        printf("3. View Credentials\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                printf("Enter website: ");
                scanf("%s", website);
                addCredential(username, password, website);
                break;

            case 2:
            	printf("Enter website to search: ");
                scanf("%s", website);
                searchCredential(website);
                break;

            case 3:
                viewCredentials();
                break;

            case 4:
                printf("Exiting Password Manager.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    // Free allocated memory before exiting
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        struct Credential* current = hashTable[i];
        while (current != NULL) {
            struct Credential* temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}

