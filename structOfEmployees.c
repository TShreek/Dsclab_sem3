#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct emp
{
    char name[20];
    int emp_id;
    char dept[20];
    float sal;
};

void printDetails(struct emp* ptr, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("\n The employee details of employee %d are :", i + 1);
        printf("\n Name : %s\n Emp ID : %d \n Dept name : %s \n Salary: %f", ptr[i].name, ptr[i].emp_id, ptr[i].dept, ptr[i].sal);
    }
}

void deptSal(struct emp* ptr, int n)
{
    char dept_name[20];
    printf("\nEnter the name of the department: ");
    scanf("%s", dept_name);
    float sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(strcmp(dept_name, (ptr + i)->dept) == 0)
            sum += (ptr + i)->sal;
    }
    printf("\n The total salary of the department is %f", sum);
}

int main()
{
    printf("\n Enter the number of employees: ");
    int n;
    scanf("%d", &n);
    struct emp *p = (struct emp*)malloc(n * sizeof(struct emp));
    for(int i = 0; i < n; i++)
    {
        printf("\n Enter employee name: ");
        scanf("%s", p[i].name);
        printf("\n Enter employee ID: ");
        scanf("%d", &p[i].emp_id);
        printf("\n Enter the department of the employee: ");
        scanf("%s", p[i].dept);
        printf("\n Enter the employee salary: ");
        scanf("%f", &p[i].sal);
    }
    printDetails(p, n);
    deptSal(p, n);
    free(p);
    return 0;
}
