#include <stdio.h>
#include <string.h>
struct student
{
   int id;

   char name[50];
   int age;
};

int main() {
struct student students[3];
students[0].id =1206;
students[0].age =17;
strcpy(students[0].name, "shivam");

students[1].id =1207;
students[1].age =23;
strcpy(students[1].name,"harsh");

students[2].id =1208;
students[2].age =24;
strcpy(students[2].name,"sawraj");

printf("ID: %d\n",students[0].id);
printf("AGE: %d\n",students[0].age);
printf("NAME: %s\n",students[0].name);
printf("ID: %d\n",students[1].id);
printf("AGE: %d\n",students[1].age);
printf("NAME: %s\n",students[1].name);
printf("ID: %d\n",students[2].id);
printf("AGE: %d\n",students[2].age);
printf("NAME: %s\n",students[2].name);
  return 0;
}