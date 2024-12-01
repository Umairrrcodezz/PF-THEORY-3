q4:
#include <stdio.h>
#include <stdlib.h>

void inputEmployees(int** ratings, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        ratings[i] = (int*)malloc(numPeriods * sizeof(int));
        for (int j = 0; j < numPeriods; j++) {
            do {
                printf("Enter rating for Employee %d, Period %d (1-10): ", i + 1, j + 1);
                scanf("%d", &ratings[i][j]);
            } while (ratings[i][j] < 1 || ratings[i][j] > 10);
        }
    }
}

void displayPerformance(int** ratings, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee %d: ", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            printf("%d ", ratings[i][j]);
        }
        printf("\n");
    }
}

int findEmployeeOfTheYear(int** ratings, int numEmployees, int numPeriods) {
    int bestEmployee = 0;
    double bestAverage = 0.0;
    for (int i = 0; i < numEmployees; i++) {
        int total = 0;
        for (int j = 0; j < numPeriods; j++) {
            total += ratings[i][j];
        }
        double average = (double)total / numPeriods;
        if (average > bestAverage) {
            bestAverage = average;
            bestEmployee = i;
        }
int main() {
    int numEmployees, numPeriods;
    printf("Enter number of employees: ");
    scanf("%d", &numEmployees);
    printf("Enter number of evaluation periods: ");
    scanf("%d", &numPeriods);

    int** ratings = (int**)malloc(numEmployees * sizeof(int*));

    inputEmployees(ratings, numEmployees, numPeriods);
    displayPerformance(ratings, numEmployees, numPeriods);

    int bestEmployee = findEmployeeOfTheYear(ratings, numEmployees, numPeriods);
    printf("Employee of the Year: Employee %d\n", bestEmployee + 1);

    int bestPeriod = findHighestRatedPeriod(ratings, numEmployees, numPeriods);
    printf("Highest Rated Period: Period %d\n", bestPeriod + 1);

    int worstEmployee = findWorstPerformingEmployee(ratings, numEmployees, numPeriods);
    printf("Worst Performing Employee: Employee %d\n", worstEmployee + 1);

    for (int i = 0; i < numEmployees; i++) {
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}
