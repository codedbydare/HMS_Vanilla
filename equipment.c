#include <stdio.h>
struct Equipment {
    char item[50];
    int id;
    int quantity;
    char expiry_date[20];
};
int main() {
    struct Equipment e;
    int choice;
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
            // Add Equipment code
            break;
        
        default:
            break;
        }
    }while(choice!=5);
}

