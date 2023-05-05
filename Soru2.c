#include <stdio.h>
#include <stdlib.h>

void merge(int arr1[], int size1, int arr2[], int size2, int mergedArr[]) {

    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            mergedArr[k++] = arr1[i++];
        } else {
            mergedArr[k++] = arr2[j++];
        }
    }

 
    while (i < size1) {
        mergedArr[k++] = arr1[i++];
    }
    while (j < size2) {
        mergedArr[k++] = arr2[j++];
    }
}

int* mergeSort(int arr[], int size) {
    if (size == 1) {
        int* sortedArr = (int*)malloc(sizeof(int));
        sortedArr[0] = arr[0];
        return sortedArr;
    }

    int mid = size / 2;
    int* leftArr = (int*)malloc(mid * sizeof(int));
    for (int i = 0; i < mid; i++) {
        leftArr[i] = arr[i];
    }
    int* sortedLeftArr = mergeSort(leftArr, mid);
    free(leftArr);

    int* rightArr = (int*)malloc((size - mid) * sizeof(int));
    for (int i = mid; i < size; i++) {
        rightArr[i - mid] = arr[i];
    }
    int* sortedRightArr = mergeSort(rightArr, size - mid);
    free(rightArr);

    int* mergedArr = (int*)malloc(size * sizeof(int));
    merge(sortedLeftArr, mid, sortedRightArr, size - mid, mergedArr);

    free(sortedLeftArr);
    free(sortedRightArr);

    return mergedArr;
}

int* mergeTwoArrays(int arr1[], int size1, int arr2[], int size2) {
    int* sortedArr1 = mergeSort(arr1, size1);
    int* sortedArr2 = mergeSort(arr2, size2);

    int* mergedArr = (int*)malloc((size1 + size2) * sizeof(int));
    merge(sortedArr1, size1, sortedArr2, size2, mergedArr);

    free(sortedArr1);
    free(sortedArr2);

    return mergedArr;
}

int main() {
    int arr1[100], arr2[100];
    int size1, size2;

    printf("İlk dizi uzunluğunu giriniz: ");
    scanf("%d", &size1);

    printf("İlk dizi elemenlarını giriniz: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("İkinci dizi uzunluğunu giriniz: ");
    scanf("%d", &size2);

    printf("İkinci dizi elemenlarını giriniz: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    int* mergedArr = mergeTwoArrays(arr1, size1, arr2, size2);

    printf("Merged array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", mergedArr[i]);
    }
    printf("\n");

    free(mergedArr);

    return 0;
}
