#include <stdio.h>
struct Equipment {
    char item[50];
    int id;
    int quantity;
    char expiry_date[20];
};
int main() {
    struct Equipment e[50];
    int choice,n=0;
    do{
        printf("\n=================== Equipment Management System ===================\n");
        printf("1. Add Equipment\n");
        printf("2. Display Equipment\n");
        printf("3. Update Equipment\n");
        printf("4. Delete Equipment\n");
        printf("5. Exit\n");
        printf("====================================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number of equipment items to add: ");
            scanf("%d", &n);
            for(int i = 0; i < n; i++) {
                printf("Enter item name: ");
                scanf("%s", e[i].item);
                printf("Enter item ID: ");
                scanf("%d", &e[i].id);
                printf("Enter quantity: ");
                scanf("%d", &e[i].quantity);
                printf("Enter expiry date (YYYY-MM-DD): ");
                scanf("%s", e[i].expiry_date);
            }
            break;
        case 2:
           if(n == 0) {
                printf("No equipment items to display.\n");
            } else {
                printf("\n=================== Equipment List ===================\n");
                printf("%-20s %-10s %-10s %-15s\n", "Item Name", "Item ID", "Quantity", "Expiry Date");
                printf("--------------------------------------------------------\n");
                for(int i = 0; i < n; i++) {
                    printf("%-20s %-10d %-10d %-15s\n", e[i].item, e[i].id, e[i].quantity, e[i].expiry_date);
                }
            }
            break;
        case 3:
            printf("Enter the item ID to update: ");
            int update_id;
            scanf("%d", &update_id);
            for(int i = 0; i < n; i++) {
                if(e[i].id == update_id) {
                    printf("Enter new item name: ");
                    scanf("%s", e[i].item);
                    printf("Enter new quantity: ");
                    scanf("%d", &e[i].quantity);
                    printf("Enter new expiry date (YYYY-MM-DD): ");
                    scanf("%s", e[i].expiry_date);
                    break;
                }
            }
            break;
        case 4:
            printf("Enter the item ID to delete: ");
            int delete_id;
            scanf("%d", &delete_id);
            for(int i = 0; i < n; i++) {
                if(e[i].id == delete_id) {
                    for(int j = i; j < n - 1; j++) {
                        e[j] = e[j + 1];
                    }
                    n--;
                    break;
                }
            }
            break;
        case 5:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }while(choice!=5);
}

