#include <stdio.h>
#include <stdlib.h>

#define MAX_N 20
#define MAX_SUBSETS 250000

typedef struct {
    int elements[MAX_N];
    int size;
} Subset;

int n;
int arr[MAX_N];
int target_sum;

Subset valid_subsets[MAX_SUBSETS];
int subset_count = 0;

void find_subsets(int idx, int current_sum, int current_subset[], int subset_size) {
    if (current_sum == target_sum) {
        if (subset_count < MAX_SUBSETS) {
            valid_subsets[subset_count].size = subset_size;
            for (int i = 0; i < subset_size; i++) {
                valid_subsets[subset_count].elements[i] = current_subset[i];
            }
            subset_count++;
        }
        return;
    }

    if (idx == n || current_sum > target_sum) {
        return;
    }

    current_subset[subset_size] = arr[idx];
    find_subsets(idx + 1, current_sum + arr[idx], current_subset, subset_size + 1);

    find_subsets(idx + 1, current_sum, current_subset, subset_size);
}

int main() {
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &target_sum);

    int current_subset[MAX_N];
    find_subsets(0, 0, current_subset, 0);

    if (subset_count == 0) {
        printf("-1\n");
    } else {
        for (int i = subset_count - 1; i >= 0; i--) {
            for (int j = 0; j < valid_subsets[i].size; j++) {
                printf("%d", valid_subsets[i].elements[j]);
                if (j < valid_subsets[i].size - 1) {
                    printf(" ");
                }
            }
            printf(" \n");
        }
    }

    return 0;
}

