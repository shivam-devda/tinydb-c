
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student
{
    int id;
    char name[50];
    int age;
};

void addStudent(struct Student students[], int *count)
{
    if (*count >= MAX_STUDENTS)
    {
        printf("Database is full!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &students[*count].id);

    printf("Enter name: ");
    scanf("%49s", students[*count].name);

    printf("Enter age: ");
    scanf("%d", &students[*count].age);

    (*count)++;

    printf("Student added successfully!\n");
}

void showStudents(struct Student students[], int count)
{
    if (count == 0)
    {
        printf("Database is empty.\n");
        return;
    }

    printf("\n=== ALL STUDENTS ===\n");

    for (int i = 0; i < count; i++)
    {
        printf("ID: %d\n", students[i].id);
        printf("NAME: %s\n", students[i].name);
        printf("AGE: %d\n", students[i].age);
        printf("--------------------\n");
    }
}

void searchStudent(struct Student students[], int count)
{
    int searchId;

    printf("Enter ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++)
    {
        if (students[i].id == searchId)
        {
            printf("\nStudent Found!\n");
            printf("ID: %d\n", students[i].id);
            printf("NAME: %s\n", students[i].name);
            printf("AGE: %d\n", students[i].age);
            return;
        }
    }

    printf("Student not found.\n");
}

void updateStudent(struct Student students[], int count)
{
    int updateId;

    printf("Enter ID to update: ");
    scanf("%d", &updateId);

    for (int i = 0; i < count; i++)
    {
        if (students[i].id == updateId)
        {
            printf("Enter new name: ");
            scanf("%49s", students[i].name);

            printf("Enter new age: ");
            scanf("%d", &students[i].age);

            printf("Student updated successfully!\n");
            return;
        }
    }

    printf("Student not found.\n");
}

void deleteStudent(struct Student students[], int *count)
{
    int deleteId;

    printf("Enter ID to delete: ");
    scanf("%d", &deleteId);

    for (int i = 0; i < *count; i++)
    {
        if (students[i].id == deleteId)
        {
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

int main()
{
    struct Student students[MAX_STUDENTS];

    int count = 0;
    int choice;

    while (1)
    {
        printf("\n====== TinyDB ======\n");
        printf("1. add student\n");
        printf("2. show students\n");
        printf("3. search student\n");
        printf("4. update student\n");
        printf("5. delete student\n");
        printf("6. exit\n");
        printf("====================\n");

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
                printf("TinyDB closed.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
