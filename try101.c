#include <stdio.h>
#include <string.h>

// Define a structure for a student
typedef struct {
    char name[50];
    int id;
    float gpa;
} Student;

// Define a constant for the max number of students
#define MAX_STUDENTS 5

// Global array of students and a counter
Student students[MAX_STUDENTS];
int studentCount = 0;

// Function prototype to add a student
void addStudent(const char* name, int id, float gpa);

// Function prototype to print all students
void printAllStudents();

// Main function - program entry point
int main() {
    printf("Simple Student Record System\n");
    printf("============================\n\n");

    // Add some sample students
    addStudent("Alice Smith", 101, 3.8);
    addStudent("Bob Johnson", 102, 3.5);
    addStudent("Charlie Brown", 103, 3.2);

    // Print the current list of students
    printAllStudents();

    return 0; // Indicate successful execution
}

/**
 * @brief Adds a new student to the global array.
 * * @param name The student's name.
 * @param id The student's ID.
 * @param gpa The student's GPA.
 */
void addStudent(const char* name, int id, float gpa) {
    // Check if the database is full
    if (studentCount < MAX_STUDENTS) {
        // Copy data into the array
        strcpy(students[studentCount].name, name);
        students[studentCount].id = id;
        students[studentCount].gpa = gpa;
        
        printf("Added student: %s\n", name);
        studentCount++; //Increment the student counter
    } else {
        printf("Error: Student database is full. Cannot add %s.\n", name);
    }
}

/**
 * @brief Prints all students currently in the array.
 */
void printAllStudents() {
    printf("\n--- Student List (%d/%d) ---\n", studentCount, MAX_STUDENTS);
    
    // Check if there are any students
    if (studentCount == 0) {
        printf("No students in the system.\n");
        return;
    }

    // Loop through all added students and print their details
    for (int i = 0; i < studentCount; i++) {
        printf("Student %d:\n", i + 1);
        printf("  Name: %s\n", students[i].name);
        printf("  ID:   %d\n", students[i].id);
        printf("  GPA:  %.2f\n", students[i].gpa);
        printf("----------------------\n");
    }
}
