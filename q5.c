q5:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeInventory(char ***speciesSupplies, int *speciesCount) {
    printf("Enter the number of species: ");
    scanf("%d", speciesCount);
    *speciesSupplies = (char **)malloc(*speciesCount * sizeof(char *));
    for (int i = 0; i < *speciesCount; i++) {
        (*speciesSupplies)[i] = NULL;
    }
}

void addSupplies(char **speciesSupplies, int speciesIndex) {
    int supplyCount;
    printf("Enter the number of supplies for species %d: ", speciesIndex + 1);
    scanf("%d", &supplyCount);
    speciesSupplies[speciesIndex] = (char *)malloc(supplyCount * 100 * sizeof(char));
    for (int i = 0; i < supplyCount; i++) {
        printf("Enter supply %d: ", i + 1);
        scanf("%s", &speciesSupplies[speciesIndex][i * 100]);
    }
}

void updateSupply(char **speciesSupplies, int speciesIndex) {
    int supplyIndex;
    char newSupply[100];
    printf("Enter the index of the supply to update for species %d: ", speciesIndex + 1);
    scanf("%d", &supplyIndex);
    printf("Enter the new name of the supply: ");
    scanf("%s", newSupply);
    strcpy(&speciesSupplies[speciesIndex][(supplyIndex - 1) * 100], newSupply);
}

void removeSpecies(char ***speciesSupplies, int *speciesCount, int speciesIndex) {
    free((*speciesSupplies)[speciesIndex]);
    for (int i = speciesIndex; i < *speciesCount - 1; i++) {
        (*speciesSupplies)[i] = (*speciesSupplies)[i + 1];
    }
    *speciesSupplies = (char **)realloc(*speciesSupplies, (*speciesCount - 1) * sizeof(char *));
    (*speciesCount)--;
}

void displayInventory(char **speciesSupplies, int speciesCount) {
    for (int i = 0; i < speciesCount; i++) {
        printf("Species %d supplies:\n", i + 1);
        for (int j = 0; speciesSupplies[i] != NULL && speciesSupplies[i][j * 100] != '\0'; j++) {
            printf("  %s\n", &speciesSupplies[i][j * 100]);
        }
    }
}

int main() {
    char **speciesSupplies;
    int speciesCount;
    int choice, speciesIndex;
    initializeInventory(&speciesSupplies, &speciesCount);
    while (1) {
        printf("1. Add Supplies\n2. Update Supply\n3. Remove Species\n4. Display Inventory\n5. Exit\nChoose an option: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter species index: ");
            scanf("%d", &speciesIndex);
            addSupplies(speciesSupplies, speciesIndex - 1);
        } else if (choice == 2) {
            printf("Enter species index: ");
            scanf("%d", &speciesIndex);
            updateSupply(speciesSupplies, speciesIndex - 1);
        } else if (choice == 3) {
            printf("Enter species index to remove: ");
            scanf("%d", &speciesIndex);
            removeSpecies(&speciesSupplies, &speciesCount, speciesIndex - 1);
        } else if (choice == 4) {
            displayInventory(speciesSupplies, speciesCount);
        } else if (choice == 5) {
            break;
        }
    }
    for (int i = 0; i < speciesCount; i++) {
        free(speciesSupplies[i]);
    }
    free(speciesSupplies);
    return 0;
}
