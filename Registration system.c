#include <stdio.h>
main ()
{
    //Variable Declaration
    int choice;
    int usr_choice;
    printf("=========================================");
    printf("          Beginner Module                ");
    printf("=========================================");
    printf("1.User Management System");
    printf("2.Hospital");
    printf("Enter Choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("=========================================");
        printf("          USER SYSTEM                    ");
        printf("=========================================");
        printf("1.User Login ");
        printf("1.User Registration ");
        printf("New member? Create Account");
        printf("Enter Choice: ");
        scanf("%d",&int usr_choice);
        

        break;
  
        default:
        printf("Invalid Choice");
    
    
    }

}