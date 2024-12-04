#include<stdio.h>
int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
int main() {
    int arr[100];
    int size = 0;
    while (1) {
        int choice;
        printf("\nMENU\n");
        printf("1.Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. In ra gia tri lon nhat cua mang\n");
        printf("4. In ra ra cac phan tu la so nguuyen to trong mang\n");
        printf("5. Them mot phan tu moi vao mang\n");
        printf("6. Xoa mot phan tu trong mang\n");
        printf("7. Sap xep mang theo thu tu tang dan\n");
        printf("8. Tim kiem phan tu va in ra vi tri index\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban la: ");
        scanf("%d", &choice);
        if (choice == 9) break;
        switch (choice) {
            case 1: //Nhap so phan tu can nhap va gia tri cac phan tu
                printf("Nhap so phan tu: ");
                scanf("%d", &size);
                if (size > 100) {
                    printf("Kich thuoc mang vuot qua gioi han!\n");
                    size = 0;
                    break;
                }
                for (int i = 0; i < size; i++) {
                    printf("Nhap phan tu thu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;
            case 2: //In ra gia tri cac phan tu dang quan ly
                printf("Cac phan tu cua mang la:\n");
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 3: //In ra gia tri lon nhat cua mang
            {
                int max = arr[0];
                for (int i = 1; i < size; i++) {
                    if (arr[i] > max) {
                        max = arr[i];
                    }
                }
                printf("Gia tri lon nhat la: %d\n", max);
                break;
                }
            case 4: //In ra ra cac phan tu la so nguuyen to trong mang
                printf("Cac phan tu la so nguyen to:\n");
                for (int i = 0; i < size; i++) {
                    if (isPrime(arr[i])) {
                        printf("%d ", arr[i]);
                    }
                }
                printf("\n");
                break;
            case 5: //Them mot phan tu moi vao mang
			{
                if (size >= 100) {
                    printf("Mang da day , khong the them phan tu.\n");
                    break;
                }
                int value;
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                arr[size] = value;
                size++;
                break;
            }
            case 6: //Xoa mot phan tu trong mang
			{
                int pos;
                printf("Nhap vi tri can xoa (tu 0 den %d): ", size - 1);
                scanf("%d", &pos);
                if (pos < 0 || pos >= size) {
                    printf("Vi tri khong hop le!\n");
                    break;
                }
                for (int i = pos; i < size - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                size--;
                break;
            }
            case 7: //Sap xep mang theo thu tu tang dan
                for (int i = 0; i < size - 1; i++) {
                    for (int j = i + 1; j < size; j++) {
                        if (arr[i] > arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                printf("Mang da duoc sap xep.\n");
                break;
            case 8: //Tim kiem phan tu va in vi tri index 
			{
                int target, found = 0;
                printf("Nhap vi tri can tim kiem: ");
                scanf("%d", &target);
                for (int i = 0; i < size; i++) {
                    if (arr[i] == target) {
                        printf("Phan tu %d nam tai vi tri index %d\n", target, i);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Khong tim phan tu %d trong mang.\n", target);
                }
                break;
            }
            default:
                printf("Lua chon cua ban khong hop le!\n");
        }
    }
    return 0;
}
