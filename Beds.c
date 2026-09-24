#include <stdio.h>
#include <string.h>

struct Bed
{
    int id;
    char category[50];
    float rate;
    int occupied;
};

void createBed()
{
    FILE *fp;
    FILE *check;
    struct Bed bed, temp;
    int duplicate = 0;

    printf("\n========= ADD BED =========\n");
    printf("Enter Bed ID: ");
    scanf("%d", &bed.id);
    if(bed.id <= 0)
    {
        printf("Invalid Bed ID!!\n");
        return;
    }

    check = fopen("beds.txt", "r");
    if(check != NULL)
    {
        while(fscanf(check, "%d|%49[^|]|%f|%d",
                     &temp.id,
                     temp.category,
                     &temp.rate,
                     &temp.occupied) == 4)
        {
            if(temp.id == bed.id)
            {
                duplicate = 1;
                break;
            }
        }
        fclose(check);
    }
    if(duplicate)
    {
        printf("Bed ID Already Exists!!\n");
        return;
    }
    printf("Enter Category: ");
    scanf(" %[^\n]", bed.category);

    if(strlen(bed.category) == 0)
    {
        printf("Category Cannot Be Empty!!\n");
        return;
    }
    printf("Enter Daily Rate: ");
    scanf("%f", &bed.rate);

    if(bed.rate <= 0)
    {
        printf("Daily Rate Must Be Greater Than 0!!\n");
        return;
    }
    bed.occupied = 0;
    fp = fopen("beds.txt", "a");
    if(fp == NULL)
    {
        printf("File Could Not Be Opened!!\n");
        return;
    }
    fprintf(fp, "%d|%s|%.2f|%d\n",
            bed.id,
            bed.category,
            bed.rate,
            bed.occupied);

    fclose(fp);

    printf("\nBed Created Successfully!!\n");
}


void listBed()
{
    FILE *fp;
    struct Bed bed;

    fp = fopen("beds.txt", "r");

    if(fp == NULL)
    {
        printf("\nNo Beds Found!!\n");
        return;
    }

    printf("\n========================= BED DETAILS =========================\n");

    printf("%-10s %-20s %-15s %-15s\n",
           "Bed ID",
           "Category",
           "Daily Rate",
           "Status");

    printf("---------------------------------------------------------------\n");

    while(fscanf(fp, "%d|%49[^|]|%f|%d",
                 &bed.id,
                 bed.category,
                 &bed.rate,
                 &bed.occupied) == 4)
    {
        printf("%-10d %-20s Rs %-11.2f %-15s\n",
               bed.id,
               bed.category,
               bed.rate,
               bed.occupied ? "Occupied" : "Available");
    }

    printf("===============================================================\n");

    fclose(fp);
}

void updateBed()
{
    FILE *fp;
    FILE *temp;
    struct Bed bed;
    int searchID;
    int found = 0;

    printf("\n========= UPDATE BED =========\n");

    printf("Enter Bed ID: ");
    scanf("%d", &searchID);

    if(searchID <= 0)
    {
        printf("Invalid Bed ID!!\n");
        return;
    }

    fp = fopen("beds.txt", "r");
    temp = fopen("temp.txt", "w");

    if(fp == NULL || temp == NULL)
    {
        printf("File Could Not Be Opened!!\n");
        return;
    }

    while(fscanf(fp, "%d|%49[^|]|%f|%d",
                 &bed.id,
                 bed.category,
                 &bed.rate,
                 &bed.occupied) == 4)
    {
        if(searchID == bed.id)
        {
            found = 1;
            printf("\nBed Found!!\n");

            printf("\nCurrent Category: %s\n", bed.category);
            printf("Current Rate: Rs %.2f\n", bed.rate);

            printf("\nEnter New Category: ");
            scanf(" %[^\n]", bed.category);

            printf("Enter New Daily Rate: ");
            scanf("%f", &bed.rate);

            if(bed.rate <= 0)
            {
                printf("Invalid Rate!! Update Cancelled.\n");

                fclose(fp);
                fclose(temp);
                remove("temp.txt");
                return;
            }
        }

        fprintf(temp, "%d|%s|%.2f|%d\n",
                bed.id,
                bed.category,
                bed.rate,
                bed.occupied);
    }

    fclose(fp);
    fclose(temp);

    if(found)
    {
        remove("beds.txt");
        rename("temp.txt", "beds.txt");

        printf("\nBed Updated Successfully!!\n");
    }
    else
    {
        remove("temp.txt");
        printf("\nBed With ID %d Not Found!!\n", searchID);
    }
}


void deleteBed()
{
    FILE *fp;
    FILE *temp;
    struct Bed bed;
    int searchID;
    int found = 0;

    printf("\n========= DELETE BED =========\n");

    printf("Enter Bed ID: ");
    scanf("%d", &searchID);

    if(searchID <= 0)
    {
        printf("Invalid Bed ID!!\n");
        return;
    }

    fp = fopen("beds.txt", "r");
    temp = fopen("temp.txt", "w");

    if(fp == NULL || temp == NULL)
    {
        printf("File Could Not Be Opened!!\n");
        return;
    }

    while(fscanf(fp, "%d|%49[^|]|%f|%d",
                 &bed.id,
                 bed.category,
                 &bed.rate,
                 &bed.occupied) == 4)
    {
        if(searchID == bed.id)
        {
            found = 1;

            if(bed.occupied == 1)
            {
                printf("\nBed Is Currently Occupied!!\n");
                printf("Bed Cannot Be Deleted.\n");

                fclose(fp);
                fclose(temp);
                remove("temp.txt");
                return;
            }

            continue;
        }

        fprintf(temp, "%d|%s|%.2f|%d\n",
                bed.id,
                bed.category,
                bed.rate,
                bed.occupied);
    }

    fclose(fp);
    fclose(temp);

    if(found==1)
    {
        remove("beds.txt");
        rename("temp.txt", "beds.txt");
        printf("\nBed Deleted Successfully!!\n");
    }
    else
    {
        remove("temp.txt");
        printf("\nBed With ID %d Not Found!!\n", searchID);
    }
}

int main()
{
    int choice;
    printf("====================================\n");
    printf("====== BED MANAGEMENT SYSTEM =======\n");
    printf("====================================\n");
    do
    {
        printf("\n1. Add Bed");
        printf("\n2. View Beds");
        printf("\n3. Update Bed");
        printf("\n4. Delete Bed");
        printf("\n5. Exit");
        printf("\n\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createBed();
                break;

            case 2:
                listBed();
                break;

            case 3:
                updateBed();
                break;

            case 4:
                deleteBed();
                break;

            case 5:
                printf("\nExiting Program...\n");
                break;

            default:
                printf("\nInvalid Choice!!\n");
        }
    } while(choice != 5);
    return 0;
}