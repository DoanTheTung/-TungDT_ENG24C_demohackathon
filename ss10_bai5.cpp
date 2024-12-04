#include <stdio.h>
int selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    return size;
}

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[100], size, target;

    // Nhap so phan tu va gia tri cua mang
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &size);

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < size; i++) {
        printf("Phan tu th? %d: ", i);
        scanf("%d", &arr[i]);
    }

    // Sap xep lai mang
    size = selectionSort(arr, size);
    printf("Mang sau khi sap xep theo thu tu tang dan:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Nhap phan tu can tim kiem
    printf("Nhap phan tu can tim kiem: ");
    scanf("%d", &target);

    // Tim kiem nhi phan
    int result = binarySearch(arr, size, target);
    if (result != -1) {
        printf("Phan tu %d duoc tim thay tai vi tri index %d\n", target, result);
    } else {
        printf("Phan tu %d khong co trong mang.\n", target);
    }
    return 0;
}
