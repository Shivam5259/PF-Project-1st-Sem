#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct{
    char name[20];
    double number;
    char address[20];
}customer_detail;

int table=1;
int total_amount=0;

void printCentered(char*);
void line(int n);
void services();
void onlineService();
void physicalService();
void reserveTable();
void checkReservation();
void checkOut();
void order();
void breakfast();
void lunch();
void dinner();
void printMenu(char*);
void total(int);
void takeBill();

int main(){
    system("cls");
    printCentered("\e[32m=== Welcome To Our Restaurent: \e[1;35mThe Missing Piece:) ===\e[0m");
    line(2);
    printf("How can we make your dining experience exceptional today?");
    services();
    return 0;
}

void printCentered(char *text){
    int terminal_width=170;
    int text_len=strlen(text);
    int padding = (terminal_width - text_len) /2;

    for(int i=0; i<padding; i++){
      printf(" ");
    }
    printf("%s\n", text);
    return;
}

void line(int n){
    for(int i=0; i<n; i++){
        printf("\n");
    }
    return;
}

void services(){
    line(1);
    int choice;
    printf("1. Online Serives\n");
    printf("2. Phyical Services\n");
    printf("3. Exit\n");
    
    while(1){
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice){
            
            case 1:
                onlineService();
                exit(0);

            case 2:
                physicalService();
                exit(0);

            case 3:
                printf("Terminating the program!");
                exit(0);
            
            default:
                printf("Invalid Input....\n\n");
        }
    }
}

void onlineService(){
    system("cls");
    line(1);
    int choice;
    
    printf("1. Reserve Table\n");
    printf("2. Online Order\n");
    printf("3. Exit\n");
    
    while(1){
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice){
            
            case 1:
                reserveTable();
                break;

            case 2:
                order();

                break;

            case 3:
                printf("Terminating the program!");
                exit(0);
            
            default:
                printf("Invalid Input....\n\n");
        }
    }
}

void physicalService(){
    system("cls");
    line(1);
    int choice;
    
    printf("1. Have Reservation\n");
    printf("2. Reserve Table\n");
    printf("3. Takeaway\n");
    printf("4. Exit\n");
    
    while(1){
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice){
            
            case 1:
                checkReservation();
                break;

            case 2:
                reserveTable();
                break;

            case 3:
                order();
                break;

            case 4:
                printf("Terminating the program!");
                exit(0);
            
            default:
                printf("Invalid Input....\n\n");
        }
    }
}

void reserveTable(){
    getchar();
    system("cls");
    line(1);

    if(table>18){
        printf("Sorry! Currently, wwe,re fully seated:(");
        return;
    }
    else{
        customer_detail customer;
        
        printf("Enter the name of customer: ");
        fgets(customer.name, sizeof(customer.name), stdin);
        customer.name[strcspn(customer.name, "\n")] = '\0';

        printf("Enter contact number of customer: ");
        scanf("%lf", &customer.number);
        getchar();

        printf("Enter address of customer: ");
        fgets(customer.address, sizeof(customer.address), stdin);
        customer.address[strcspn(customer.address, "\n")] = '\0';

        FILE *file = NULL;
        file=fopen("customer_detail.txt", "a");

        if(file==NULL){
            printf("Error File Oppening!");
            return;
        }
        fprintf(file, "\nName: %s\n", customer.name);
        fprintf(file, "Table No. %d\n", table);
        fprintf(file, "Contact Number: %.0lf\n", customer.number);
        fprintf(file, "Address: %s\n", customer.address);
        fprintf(file, "------------------------");

        fclose(file);
        printf("\nMr. %s your table no. %d is successully reserved!", customer.name, table);
        table++;
    }
    return;
}

void checkReservation(){
    getchar();
    system("cls");
    line(1);

    char name[20];
    printf("Enter customer name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    FILE *file = NULL, *temp_file = NULL;
    file = fopen("customer_detail.txt", "r");

    if(file==NULL){
        printf("Error File Oppening!");
        return;
    }

    char line[300];
    char check_name[20];
    int found=0;
    int reserved_table;
    while(fgets(line, sizeof(line), file)){
        if(found==0){
            sscanf(line, "Name: %[^\n]", check_name);
            if(!(strcmp(check_name, name))){
                printf("6932");
                found=1;
            }
        }
        else if(found==1){
            sscanf(line, "Table No. %d", &reserved_table);
            break;
        }
    }
    fclose(file);
    if(found==1){
        printf("Yes Mr. %s, your reservation is available!\n", name);
        printf("Your Researved Table is: %d\n", reserved_table);
        table--;
    }
    else{
        printf("\nSorry Mr. %s, you don't have the reservation!\n", name);
        if(table>18){
            printf("Do you want to reserver now?\nEnter (Yes or No): ");
            char choice[10];
            getchar();
            fgets(choice, sizeof(choice), stdin);
            choice[strcspn(choice, "\n")] = '\0';

            if(!(strcmp(choice, "Yes"))){
                reserveTable();
            }
            else{
                printf("Thank You for choosing us!\n");
            }
        }
    }
    return;
}

void order(){
    system("cls");
    line(1);

    printCentered("\e[32m=== Welcome To Order Section Of: \e[1;35mThe Missing Piece:) ===\e[0m");
    line(2);
    printf("1. BreakFast\n");
    printf("2. Lunch\n");
    printf("3. Dinner\n");
    int choice;
    while(1){
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                breakfast();
                break;

            case 2:
                lunch();
                break;

            case 3:
                dinner();
                break;

            default:
                printf("Invalid Input\nTry Again!\n\n");
        }
    }
}

void breakfast(){
    getchar();
    system("cls");
    line(1);

    printf("Press enter for menu: ");
    getchar();
    printMenu("BreakFast");
    int choice;
    while(1){
        printf("1. View Menu again\n2. CheckOut\nEnter dish number\nEnter you choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                system("cls");
                printMenu("BreakFast");
                break;

            case 2:
                checkOut();
                return;

            default:
                total(choice);
        }
    }
}

void lunch(){
    getchar();
    system("cls");
    line(1);

    printf("Press enter for menu: ");
    getchar();
    printMenu("Lunch");
    int choice;
    while(1){
        printf("1. View Menu again\n2. CheckOut\nEnter dish number\nEnter you choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                system("cls");
                printMenu("Lunch");
                break;

            case 2:
                checkOut();
                return;

            default:
                total(choice);
        }
    }
}

void dinner(){
    getchar();
    system("cls");
    line(1);

    printf("Press enter for menu: ");
    getchar();
    printMenu("Dinner");
    int choice;
    while(1){
        printf("1. View Menu again\n2. CheckOut\nEnter dish number\nEnter you choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                system("cls");
                printMenu("Dinner");
                break;

            case 2:
                checkOut();
                return;

            default:
                total(choice);
        }
    }
}

void printMenu(char *string){
    FILE *file = NULL;
    file =  fopen("menu.txt", "r");

    if(file == NULL){
        printf("Error File Opening!");
        return;
    }

    char line[300];
    char check[10];
    while(fgets(line, sizeof(line), file)){
        sscanf(line, "%s", check);
        if(!strcmp(check, string)){
            while(line != NULL && strcmp(line, "----------------------------------") != 0){
                fgets(line, sizeof(line), file);
                printf("%s\n", line);
            }
            break;
        }
    }
    fclose(file);
}

void total(int a){
    int quantity;
    printf("Enter the quatity of the dish: ");
    scanf("%d", &quantity);

    FILE *file = NULL;
    file = fopen("menu.txt", "r");

    if(file == NULL){
        printf("Error Opening File!");
        return;
    }

    int n, price;
    char line[300];
    while(fgets(line, sizeof(line), file)){
        sscanf(line, "%d. %*s %d", &n, &price);
        if(n==a){
            total_amount+=(price*quantity);
            break;
        }
    }
    fclose(file);
}

void checkOut(){
    getchar();
    system("cls");
    line(1);

    char name[20];
    printf("Enter customer name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    FILE *file = NULL, *temp_file = NULL;
    file = fopen("customer_detail.txt", "r");
    temp_file = fopen("Temp_file", "w");

    if(file==NULL || temp_file==NULL){
        printf("Error File Oppening!");
        return;
    }

    char line[300];
    char check_name[20];
    int found=0;
    int reserved_table;
    while(fgets(line, sizeof(line), file)){
        sscanf(line, "Name: %[^\n]", check_name);
        if(!(strcmp(check_name, name))){
            found=1;
            while(fgets(line, sizeof(line), file) != NULL && strcmp(line, "------------------------") != 0);
        }
        else{
            fputs(line, temp_file);
        }
    }
    fclose(file);
    fclose(temp_file);
    if(found==1){
        remove("customer_detail.txt");
        rename("Temp_file.txt", "customer_detail.txt");
        table--;
        takeBill();
        printCentered("\e[32mThank you for dining with us! We hope you enjoyed your meal. Have a great day, and we look forward to serving you again soon!\e[32m");
    }
    else{
        printf("\nEnter Valid Name!\n");
        checkOut();
    }
    return;
}

void takeBill(){
    printf("Your Total Bill is %d", total_amount);
    if(total_amount>=2000 && total_amount<5000){
        printf("On the order of more than 2000 you got the discount of 10%\n");
        total_amount-=(total_amount*0.1);
    }
    else if(total_amount>=5000 && total_amount<10000){
        printf("On the order of more than 5000, you got the discount of 20%\n");
        total_amount-=(total_amount*0.2);
    }
    else if(total_amount>=10000){
        printf("On the order of more than 10000, you got the discount of 40%\n");
        total_amount-=(total_amount*0.4);
    }
    printf("The GST on the bill is 18%\n");
    printf("\nYour Net Bill is %.1lf\n", total_amount+(total_amount*0.18));

    printf("You want to pay online or cash?\n");
    printf("1. Online Payment\n");
    printf("2. Cash Payment\n");
    
    int choice, credit, pass;
    while(1){
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice){

            case 1:
                printf("Enter Credit Card Number: ");
                scanf("%d", credit);
                printf("Enter Your Password: ");
                scanf("%d", pass);
                printf("The payment has successfully received\n");
                return;

            case 2:
                printf("The payment has successfully received\n");
                return;
            
            default:
                printf("Enter Valid Option\n");
        }
    }
    return;
}