#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Employee structure
struct Employee {
    int id;
    char name[50];
    float salary;
    struct Employee* next;
    
};

//Function prototypes
struct Employee* createEmployee(int id, const char* name, float salary);
void addEmployee(struct Employee** head, int id, const char* name, float salary);
void removeEmployee(struct Employee** head, int id);
void searchEmployee(struct Employee* head, int id);
void displaySalary(struct Employee* head, const char* name); 
void displayEmployees(struct Employee* head);


int main() {
    struct Employee* head = NULL;
    int choice, id;
    char name[50];
    float salary;

    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Remove Employee\n");
        printf("3. Search Employee\n");
        printf("4. Display Salary\n");
        printf("5. Display Employees\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Employee ID: ");
                scanf("%d", &id);
                printf("Enter Employee Name: ");
                scanf("%s", name);
                printf("Enter Employee Salary: ");
                scanf("%f", &salary);
                addEmployee(&head, id, name, salary);
                break;
            case 2:
                printf("Enter Employee ID to remove: ");
                scanf("%d", &id);
                removeEmployee(&head, id);
                break;
            case 3:
                printf("Enter Employee ID to search: ");
                scanf("%d", &id);
                searchEmployee(head, id);
                break;
             case 4:
                printf("Enter Employee Name to display salary: ");
    			scanf("%s", name);
    			displaySalary(head, name);
    			break;
            case 5:
                displayEmployees(head);
                break;
            case 6:
            	exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Function to create a new employee
struct Employee* createEmployee(int id, const char* name, float salary) {
    struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
    newEmployee->id = id;
    strcpy(newEmployee->name, name);
    newEmployee->salary = salary;
    newEmployee->next = NULL;
    return newEmployee;
}

// Function to add an employee to the linked list
void addEmployee(struct Employee** head, int id, const char* name, float salary) {
    struct Employee* newEmployee = createEmployee(id, name, salary);
    newEmployee->next = *head;
    *head = newEmployee;
    printf("Employee added successfully.\n");
}

// Function to remove an employee from the linked list
void removeEmployee(struct Employee** head, int id) {
    struct Employee* current = *head;
    struct Employee* prev = NULL;

    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Employee with ID %d not found.\n", id);
    } else {
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
        printf("Employee with ID %d removed successfully.\n", id);
    }
}

// Function to search for an employee by ID
void searchEmployee(struct Employee* head, int id) {
    struct Employee* current = head;

    while (current != NULL) {
        if (current->id == id) {
            printf("Employee found: ID: %d, Name: %s, Salary: %.2f\n", current->id, current->name, current->salary);
            return;
        }
        current = current->next;
    }

    printf("Employee with ID %d not found.\n", id);
}

// Function to display salary by searching with name
void displaySalary(struct Employee* head, const char* name) {
    struct Employee* current = head;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Salary of '%s' is %.2f\n", name, current->salary);
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("Employee with name %s not found.\n", name);
    }
}

// Function to display all employees
void displayEmployees(struct Employee* head) {
    struct Employee* current = head;
    if (current == NULL) {
        printf("No employees in the system.\n");
    } else {
        printf("Employee Details:\n");
        while (current != NULL) {
            printf("ID: %d, Name: %s, Salary: %.2f\n", current->id, current->name, current->salary);
            current = current->next;
        }
    }
}
