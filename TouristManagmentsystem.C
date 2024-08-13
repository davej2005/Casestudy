#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for passenger details
typedef struct Passenger {
    char name[50];
    char gender[10];
    int age;
    struct Passenger* next; // Pointer to the next node
} Passenger;

// Global variables
Passenger* head = NULL; // Head of the linked list for passengers
int package_cost = 0; // To store cost of selected package

// Function to display the heading
void heading() {
    system("cls"); // Clear the screen (use system("clear") for Unix-based systems)
    printf("**********************************\n");
    printf("    TOURISM MANAGEMENT SYSTEM\n");
    printf("**********************************\n");
}

// Function to add a passenger node to the linked list
void add_node(char *name, char *gender, int age) {
    Passenger* new_passenger = (Passenger*)malloc(sizeof(Passenger));
    strcpy(new_passenger->name, name);
    strcpy(new_passenger->gender, gender);
    new_passenger->age = age;
    new_passenger->next = NULL;

    if (head == NULL) {
        head = new_passenger;
    } else {
        Passenger* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_passenger;
    }
}

// Function to capture passenger details
void details() {
    int num_passengers;
    char name[50], gender[10];
    int age;

    printf("Enter the number of passengers: ");
    scanf("%d", &num_passengers);

    for (int i = 0; i < num_passengers; i++) {
        printf("Enter details for passenger %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", name);
        printf("Gender: ");
        scanf("%s", gender);
        printf("Age: ");
        scanf("%d", &age);

        add_node(name, gender, age);
    }
}

// Function to display the receipt
void receipt() {
    int num_passengers = 0;
    Passenger* temp = head;

    printf("\nReceipt:\n");
    printf("Package Cost: %d\n", package_cost);
    printf("Passenger Details:\n");

    while (temp != NULL) {
        printf("Name: %s, Gender: %s, Age: %d\n", temp->name, temp->gender, temp->age);
        num_passengers++;
        temp = temp->next;
    }

    printf("Total Passengers: %d\n", num_passengers);
    printf("Total Amount: %d\n", num_passengers * package_cost);
}

// Function to display International Tour packages
void inter() {
    int choice;

    printf("International Tour Packages:\n");
    printf("1. Europe - $2000\n");
    printf("2. USA - $2500\n");
    printf("3. Australia - $1800\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: package_cost = 2000; break;
        case 2: package_cost = 2500; break;
        case 3: package_cost = 1800; break;
        default: printf("Invalid choice. Exiting.\n"); exit(1);
    }
}

// Function to display India Tour packages
void india() {
    int choice;

    printf("India Tour Packages:\n");
    printf("1. Delhi - $500\n");
    printf("2. Goa - $600\n");
    printf("3. Jaipur - $700\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1: package_cost = 500; break;
        case 2: package_cost = 600; break;
        case 3: package_cost = 700; break;
        default: printf("Invalid choice. Exiting.\n"); exit(1);
    }
}

int main() {
    int tour_choice;

    heading();

    printf("Choose Tour Package:\n");
    printf("1. International\n");
    printf("2. India\n");
    printf("Enter your choice: ");
    scanf("%d", &tour_choice);

    switch (tour_choice) {
        case 1: inter(); break;
        case 2: india(); break;
        default: printf("Invalid choice. Exiting.\n"); exit(1);
    }

    details();
    receipt();

    // Free allocated memory
    Passenger* temp = head;
    while (temp != NULL) {
        Passenger* next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}
