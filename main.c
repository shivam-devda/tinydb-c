#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student
{
    int id;
    char name[50];
    int age;
};

/* Function prototypes */
void addStudent(struct Student students[], int *count);
void showStudents(struct Student students[], int count);
void searchStudent(struct Student students[], int count);
void updateStudent(struct Student students[], int count);
void deleteStudent(struct Student students[], int *count);
void displayStudent(struct Student student);
int idExists(struct Student students[], int count, int id);


/* Check whether an ID already exists */
int idExists(struct Student students[], int count, int id)
{
    for (int i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            return 1;
        }
    }

    return 0;
}


/* Display one student */
void displayStudent(struct Student student)
{
    printf("ID   : %d\n", student.id);
    printf("NAME : %s\n", student.name);
    printf("AGE  : %d\n", student.age);
}


/* Add a new student */
void addStudent(struct Student students[], int *count)
{
    if (*count >= MAX_STUDENTS)
    {
        printf("\nDatabase is full!\n");
        return;
    }

    int id;

    printf("\n--- Add Student ---\n");

    printf("Enter ID: ");
    scanf("%d", &id);

    /* Prevent duplicate ID */
    if (idExists(students, *count, id))
    {
        printf("Error: Student ID already exists!\n");
        return;
    }

    students[*count].id = id;

    printf("Enter name: ");
    scanf("%49s", students[*count].name);

    printf("Enter age: ");
    scanf("%d", &students[*count].age);

    /* Basic age validation */
    if (students[*count].age <= 0 || students[*count].age > 120)
    {
        printf("Invalid age!\n");
        return;
    }

    (*count)++;

    printf("Student added successfully!\n");
}


/* Show all students */
void showStudents(struct Student students[], int count)
{
    if (count == 0)
    {
        printf("\nDatabase is empty.\n");
        return;
    }

    printf("\n========== ALL STUDENTS ==========\n");
    printf("Total students: %d\n\n", count);

    for (int i = 0; i < count; i++)
    {
        printf("Student #%d\n", i + 1);
        printf("--------------------\n");

        displayStudent(students[i]);

        printf("--------------------\n");
    }
}


/* Search student */
void searchStudent(struct Student students[], int count)
{
    int searchId;

    printf("\n--- Search Student ---\n");

    printf("Enter ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++)
    {
        if (students[i].id == searchId)
        {
            printf("\nStudent Found!\n");
            printf("--------------------\n");

            displayStudent(students[i]);

            printf("--------------------\n");
            return;
        }
    }

    printf("Student not found.\n");
}


/* Update student */
void updateStudent(struct Student students[], int count)
{
    int updateId;

    printf("\n--- Update Student ---\n");

    printf("Enter ID to update: ");
    scanf("%d", &updateId);

    for (int i = 0; i < count; i++)
    {
        if (students[i].id == updateId)
        {
            printf("\nCurrent information:\n");
            displayStudent(students[i]);

            printf("\nEnter new name: ");
            scanf("%49s", students[i].name);

            printf("Enter new age: ");
            scanf("%d", &students[i].age);

            if (students[i].age <= 0 || students[i].age > 120)
            {
                printf("Invalid age!\n");
                return;
            }

            printf("Student updated successfully!\n");
            return;
        }
    }

    printf("Student not found.\n");
}


/* Delete student */
void deleteStudent(struct Student students[], int *count)
{
    int deleteId;

    printf("\n--- Delete Student ---\n");

    printf("Enter ID to delete: ");
    scanf("%d", &deleteId);

    for (int i = 0; i < *count; i++)
    {
        if (students[i].id == deleteId)
        {
            /* Shift students left */
            for (int j = i; j < *count - 1; j++)
            {
                students[j] = students[j + 1];
            }

            (*count)--;

            printf("Student deleted successfully!\n");
            return;
        }
    }

    printf("Student not found.\n");
}


/* Main function */
int main()
{
    struct Student students[MAX_STUDENTS];

    int count = 0;
    int choice;

    while (1)
    {
        printf("\n");
        printf("=================================\n");
        printf("           TinyDB-C\n");
        printf("=================================\n");
        printf("Students: %d/%d\n", count, MAX_STUDENTS);
        printf("---------------------------------\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("=================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent(students, &count);
                break;

            case 2:
                showStudents(students, count);
                break;

            case 3:
                searchStudent(students, count);
                break;

            case 4:
                updateStudent(students, count);
                break;

            case 5:
                deleteStudent(students, &count);
                break;

            case 6:
                printf("\nTinyDB closed. Goodbye!\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;