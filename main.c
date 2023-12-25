#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a task
struct Task {
    char description[100];
    int priority;
};

// Function to add a task to the to-do list
void addTask(struct Task *tasks, int *taskCount, const char *description, int priority) {
    // Check if the array is full
    if (*taskCount >= 10) {
        printf("To-do list is full. Cannot add more tasks.\n");
        return;
    }

    // Add the task
    strcpy(tasks[*taskCount].description, description);
    tasks[*taskCount].priority = priority;

    // Increment the task count
    (*taskCount)++;

    printf("Task added successfully!\n");
}

// Function to display all tasks
void displayTasks(const struct Task *tasks, int taskCount) {
    if (taskCount == 0) {
        printf("No tasks in the to-do list.\n");
    } else {
        printf("To-Do List:\n");
        for (int i = 0; i < taskCount; ++i) {
            printf("%d. Priority %d: %s\n", i + 1, tasks[i].priority, tasks[i].description);
        }
    }
}

int main() {
    struct Task tasks[10];  // Array to store tasks
    int taskCount = 0;      // Variable to keep track of the number of tasks

    int choice;
    char description[100];
    int priority;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice) {
            case 1:
                // Add Task
                printf("Enter task description: ");
                scanf("%s", description);
                printf("Enter priority (1-5): ");
                scanf("%d", &priority);

                addTask(tasks, &taskCount, description, priority);
                break;

            case 2:
                // Display Tasks
                displayTasks(tasks, taskCount);
                break;

            case 3:
                // Exit
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 3);

    return 0;
}

