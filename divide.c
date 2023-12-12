#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


void CreateArray(int *arr, int size);
void PrintArray(int *arr, int size);
bool IsZero(int *arr, int size);


int main () {

    int n;
    int x = 0, y = 0;
    bool check = true;
    printf("array size: ");
    scanf("%d", &n);
    srand(time(0));

    int *nums = malloc(n * sizeof(int));
    int *before = malloc(n * sizeof(int));
    int *after = malloc(n*sizeof(int));

    puts("Elements:");
    CreateArray(nums, n);

    if(IsZero(nums, n)) {
        for(int i=0; i<n; i++) {
            if(check) {
                check = false;
                while(nums[i] != 0) {
                    before[x++] = nums[i++];
                    // x++; i++;
                }
                i++;
            }
            after[y++] = nums[i];
        }

        before = realloc(before, x * sizeof(int));
        after = realloc(after, y * sizeof(int));

        puts("Before:");
        PrintArray(before, x);
        puts("After:");
        PrintArray(after, y);
    } else {
        printf("There is no 0 in this array\n");
    }

    free(nums);
    free(before);
    free(after);

    return 0;
}


void CreateArray(int *arr, int size) {
    for(int i=0; i<size; i++) {
        *(arr+i) = rand() % 10;
        printf("%d ", *(arr+i));
    }
    printf("\n\n");
}


void PrintArray(int *arr, int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", *(arr+i));
    }
    printf("\n");
}


bool IsZero(int *arr, int size) {
    for(int i=0; i<size; i++) {
        if(*(arr+i) == 0) {
            return true;
        }
    }
    return false;
}
