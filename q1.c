q1:
#include <stdio.h>
#include <string.h>

struct Emp {
    int code;
    char name[50];
    int doj[3];
};

void assignVals(struct Emp *e, int c, const char *n, int d, int m, int y) {
    e->code = c;
    strcpy(e->name, n);
    e->doj[0] = d;
    e->doj[1] = m;
    e->doj[2] = y;
}

void checkTenure(struct Emp emps[], int sz) {
    int cDay, cMonth, cYear;
    printf("Enter the current date (day month year): ");
    scanf("%d %d %d", &cDay, &cMonth, &cYear);

    int cnt = 0;
    printf("\nEmployees with more than 3 years tenure:\n");
    printf("--------------------------------------\n");

    for (int i = 0; i < sz; i++) {
        int tYears = cYear - emps[i].doj[2];
        int tMonths = cMonth - emps[i].doj[1];
        int tDays = cDay - emps[i].doj[0];

        if (tMonths < 0 || (tMonths == 0 && tDays < 0)) {
            tYears--;
        }

        if (tYears > 3) {
            printf("Employee Code: %d\n", emps[i].code);
            printf("Employee Name: %s\n", emps[i].name);
            printf("Date of Joining: %02d-%02d-%d\n\n", 
                emps[i].doj[0], 
                emps[i].doj[1], 
                emps[i].doj[2]);
            cnt++;
        }
    }

    printf("Total employees with more than 3 years tenure: %d\n", cnt);
}

int main() {
    struct Emp emps[4];

    assignVals(&emps[0], 101, "Alice", 15, 3, 2018);
    assignVals(&emps[1], 102, "Bob", 10, 7, 2020);
    assignVals(&emps[2], 103, "Charlie", 25, 12, 2015);
    assignVals(&emps[3], 104, "Diana", 5, 6, 2019);

    checkTenure(emps, 4);

    return 0;
}
