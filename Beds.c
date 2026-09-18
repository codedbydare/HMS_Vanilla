/*Bed Management Menu*/
#include<stdio.h>
int menu() 
{
    int choice;
    printf("\n\n===Beds Management Menu===\n");
    printf("1. Add Beds\n");
    printf("2. View Beds\n");
    printf("3. Update Beds\n");
    printf("4. Delete Beds\n");
    printf("5. Exit\n");  
    
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}
