#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// Global Variable
char username[20]="", password[20];                                // User's Username and password
float saving;                                                   // User's Total Savings
char staffID[10] = "12345678", staffPass[10] = "12345678";      // Staff's ID and password
int i = 0;

// User's transactions and cash deposit
char transAct[1000][20];
float transAmount[1000];

void firstTimeUser();
void userLogin();
void staffLogin();
void userConsole();
void transaction();
void deposit();
void bankStatement();
void staffConsole();

int main(){
	
	int main;
    system("cls");
    printf("............................................\n");
    printf("|         ABC Online Banking System        |\n");
    printf("|------------------------------------------|\n");
    printf("| 1. First Time User                       |\n");
    printf("| 2. User Login                            |\n");
    printf("| 3. Staff Login                           |\n");
    printf("| 4. Exit                                  |\n");
    printf("|..........................................|\n");
    printf("Select one >> ");
    scanf("%d", &main);
    
    while (main != 1 && main != 2 && main != 3 && main != 4){
    	printf("Invalid Input. Please Try Again\n");
    	printf(">> ");
    	scanf("%d", &main);
	}
	
	switch(main){
		case 1:
			firstTimeUser();
            break;
        case 2:
            userLogin();
            break;
        case 3:
            staffLogin();
            break;
        case 4:
            exit(0);
            break;
	}
}

void firstTimeUser(){
    system("cls");
    printf("............................................\n");
    printf("|             User Registeration           |\n");
    printf("|..........................................|\n\n");
    printf("Username >> ");
    scanf(" %[^\n]s", &username);
    printf("Password >> ");
    scanf(" %[^\n]s", &password);
    printf("Savings >> RM ");
    scanf("%f", &saving);

    printf("-- Successful Registered --\n");
    sleep(1);     // Pause output console a second
    main();
}

void userLogin(){

    char user[20], pass[20];
    int limit = 0;
    
    system("cls");
    printf("............................................\n");
    printf("|                User Log In               |\n");
    printf("|..........................................|\n\n");
    if(strcmp(username,"")==0)
    {
    	printf("Please choose first time user\n");
    	system("pause");
    	main();
	}
	printf("Username >> ");
    scanf(" %[^\n]s", &user);
    printf("Password >> ");
    scanf(" %[^\n]s", &pass);

    while(limit < 5 && ((strcmp(username, user) != 0 || strcmp(password, pass) != 0))){
        limit++;
        printf("Invalid Username or Password. Please Try Again...\n");
        printf("Username >> ");
        scanf(" %[^\n]s", &user);
        printf("Password >> ");
        scanf(" %[^\n]s", &pass);

        if (limit == 5){
            printf("Input limit reached. Sorry...\n");
            sleep(1);     // Pause output console for a second
            main();
        }
    }

    printf("-- Log In Successful --\n");
    sleep(1);     // Pause output console for a second
    userConsole();
}

void staffLogin(){
    char id[10], pass[10];
    int limit = 0;

    system("cls");
    printf("............................................\n");
    printf("|               Staff Log In               |\n");
    printf("|..........................................|\n\n");

    printf("Staff ID >> ");
    scanf(" %[^\n]s", &id);
    printf("Password >> ");
    scanf(" %[^\n]s", &pass);

    while(limit < 5 && ((strcmp(staffID, id) != 0 || strcmp(staffPass, pass) != 0))){
        limit++;
        printf("Invalid Username or Password. Please Try Again...\n");
        printf("Username >> ");
        scanf(" %[^\n]s", &id);
        printf("Password >> ");
        scanf(" %[^\n]s", &pass);

        if (limit == 5){
            printf("Input limit reached. Sorry...\n");
            sleep(1);     // Pause output console for a second
            main();
        }
    }

    printf("-- Log In Successful --\n");
    sleep(1);     // Pause output console for a second
    staffConsole();
}

void userConsole(){

    // For console output purposes only
    char savingString[15];
    sprintf(savingString, "%.2f", saving);

    int select;
    system("cls");
    printf("............................................\n");
    printf("|         ABC Online Banking System        |\n");
    printf("|------------------------------------------|\n");
    printf("|Savings: RM %-30s|\n", savingString);
    printf("|------------------------------------------|\n");
    printf("| 1. Transaction                           |\n");
    printf("| 2. Cash Deposit                          |\n");
    printf("| 3. Bank Statement                        |\n");
    printf("| 4. Log Out                               |\n");
    printf("| 5. Exit                                  |\n");
    printf("|..........................................|\n");
    printf("Select One >> ");
    scanf("%d", &select);
    
    while (select != 1 && select != 2 && select != 3 && select != 4 && select != 5){
        printf("Invalid Input. Please Try Again\n");
    	printf(">> ");
    	scanf("%d", &select);
    }

    switch (select){
    case 1:
        transaction();
        break;
    case 2:
        deposit();
        break;
    case 3:
        bankStatement();
        userConsole();
        break;
    case 4:
        main();
        break;
    case 5:
        exit(0);
        break;
    }
}

void transaction(){
    // For console output purposes only
    char savingString[15];
    sprintf(savingString, "%.2f", saving);

    int select;
    int billSelect;
    char accNum[10];
    float payment;
    int topupSelect;
    char accTransfer[10];
    float amount;


    system("cls");
    printf("............................................\n");
    printf("|              Transaction Page            |\n");
    printf("|------------------------------------------|\n");
    printf("|Savings: RM %-30s|\n", savingString);
    printf("|------------------------------------------|\n");
    printf("| 1. Bill Payment                          |\n");
    printf("| 2. Prepaid Reload                        |\n");
    printf("| 3. Account Transfer                      |\n");
    printf("|..........................................|\n");
    printf("Select One >> ");
    scanf("%d", &select);

    while (select != 1 && select != 2 && select != 3){
        printf("Invalid Input. Please Try Again\n");
    	printf(">> ");
    	scanf("%d", &select);
    }

    switch(select){
        case 1:
        system("cls");
        printf("............................................\n");
        printf("|                Bill Payment              |\n");
        printf("|------------------------------------------|\n");
        printf("|Savings: RM %-30s|\n", savingString);
        printf("|------------------------------------------|\n");
        printf("| 1. Electric Bills                        |\n");
        printf("| 2. Water Bills                           |\n");
        printf("| 3. Astro Bills                           |\n");
        printf("|..........................................|\n");
        printf("Select One >> ");
        scanf("%d", &billSelect);
        while (select != 1 && select != 2 && select != 3){
            printf("Invalid Input. Please Try Again\n");
            printf(">> ");
            scanf("%d", &billSelect);
        }

        switch (billSelect) {
            case 1:
                system("cls");
                printf("............................................\n");
                printf("|               Electric Bill              |\n");
                printf("|..........................................|\n");
                printf(" Bill Account Number >> ");
                scanf(" %[^\n]s", &accNum);
                printf(" Payment Amount >> RM ");
                scanf("%f", &payment);
                while(payment>saving){
                	printf("You Do Not Have Enough Balance. Please Try Again\n");
                	printf(" Payment Amount >> RM ");
                	scanf("%f", &payment);
				}
                // Store the data to global variable
                strcpy(transAct[i], "Electric Bill");
                transAmount[i] = payment;
                saving = saving - transAmount[i];
                i++;

                printf("-- Payment Successful --\n");
                system("pause");
                break;
            case 2:
                system("cls");
                printf("............................................\n");
                printf("|                 Water Bill               |\n");
                printf("|..........................................|\n");
                printf(" Bill Account Number >> ");
                scanf(" %[^\n]s", &accNum);
                printf(" Payment Amount >> RM ");
                scanf("%f", &payment);
				while(payment>saving){
                	printf("You Do Not Have Enough Balance. Please Try Again\n");
                	printf(" Payment Amount >> RM ");
                	scanf("%f", &payment);
				}
                // Store the data to global variable
                strcpy(transAct[i], "Water Bill");
                transAmount[i] = payment;
                saving = saving - transAmount[i];
                i++;

                printf("-- Payment Successful --\n");
                system("pause");
                break;
            case 3:
                system("cls");
                printf("............................................\n");
                printf("|                 Astro Bill               |\n");
                printf("|..........................................|\n");
                printf(" Bill Account Number >> ");
                scanf(" %[^\n]s", &accNum);
                printf(" Payment Amount >> RM ");
                scanf("%f", &payment);
				while(payment>saving){
                	printf("You Do Not Have Enough Balance. Please Try Again\n");
                	printf(" Payment Amount >> RM ");
                	scanf("%f", &payment);
				}
                
                strcpy(transAct[i], "Astro Bill");
                transAmount[i] = payment;
                saving = saving - transAmount[i];
                i++;

                printf("-- Payment Successful --\n");
                system("pause");
                break;
        } break;
        case 2:
            system("cls");
            printf("............................................\n");
            printf("|               Prepaid Reload             |\n");
            printf("|------------------------------------------|\n");
            printf("|Savings: RM %-30s|\n", savingString);
            printf("|------------------------------------------|\n");
            printf("| 1. RM 5                                  |\n");
            printf("| 2. RM 10                                 |\n");
            printf("| 3. RM 30                                 |\n");
            printf("| 4. RM 50                                 |\n");
            printf("| 5. RM 100                                |\n");
            printf("|..........................................|\n");
            printf("Select One >> ");
            scanf("%d", &topupSelect);

            while (topupSelect != 1 && topupSelect != 2 && topupSelect != 3 && topupSelect != 4 && topupSelect != 5){
                printf("Invalid Input. Please Try Again\n");
                printf(">> ");
                scanf("%d", &topupSelect);
            }
			
            strcpy(transAct[i], "TopUp");
            transAmount[i] = payment;
            if (topupSelect == 1)
                transAmount[i] = 5;
            else if (topupSelect == 2)
                transAmount[i] = 10;
            else if (topupSelect == 3)
                transAmount[i] = 30;
            else if (topupSelect == 4)
                transAmount[i] = 50;
            else
                transAmount[i] = 100;
            saving = saving - transAmount[i];
            i++;

            printf("-- Reload Successful --\n");
            system("pause");
            break;
        case 3:
            system("cls");
            printf("............................................\n");
            printf("|              Account Transfer            |\n");
            printf("|..........................................|\n\n");
            printf(" Recepient's Account Number >> ");
            scanf(" %[^\n]s", &accTransfer);
            printf(" Amount >> RM ");
            scanf("%f", &amount);
			while(amount>saving){
                	printf("You Do Not Have Enough Balance. Please Try Again\n");
                	printf(" Payment Amount >> RM ");
                	scanf("%f", &amount);
				}
            strcpy(transAct[i], "Account Tranfer");
            transAmount[i] = amount;
            saving = saving - transAmount[i];
            i++;

            printf("-- Transfer Successful --\n");
            system("pause");
            break;
    }
    userConsole();
}

void deposit(){
    float amount;

    system("cls");
    printf("............................................\n");
    printf("|                Cash Deposit              |\n");
    printf("|..........................................|\n\n");
    printf("Deposit Amount >> RM ");
    scanf("%f", &amount);

    strcpy(transAct[i], "Cash Deposit");
    transAmount[i] = amount;
    saving = saving + transAmount[i];
    i++;

    userConsole();
}

void bankStatement(){
    int j = 0;
    char amountString[10];
    system("cls");
    printf("..................................................\n");
    printf("|           ABC Online Banking System            |\n");
    printf("| Username: %-37s|\n", username);
    printf("|------------------------------------------------|\n");
    printf("| %-20s | %-10s | %-10s |\n", "Transactions", "In(RM)", "Out(RM)");
    for (j; j < i; j++){
        sprintf(amountString, "%.2f", transAmount[j]);
        if (strcmp(transAct[j], "Cash Deposit") == 0)
            printf("| %-20s | %-10s | %-10s |\n", transAct[j], amountString, "");
        else
            printf("| %-20s | %-10s | %-10s |\n", transAct[j], "", amountString);
    }
    printf("|------------------------------------------------|\n");
    char savingString[10];
    sprintf(savingString, "%.2f", saving);
    printf("| Savings Balance: RM %-27s|\n", savingString);
    printf("|................................................|\n");
    system("pause");
}

void staffConsole(){
    char approval;
    system("cls");
    printf("............................................\n");
    printf("|         ABC Online Banking System        |\n");
    printf("|..........................................|\n\n");
    if(i!=0)
    {
		printf("User wanted to print bank statement.\nDo you want to approve?");
	    printf("Enter Y / N >> ");
	    scanf(" %c", &approval);
	    if (toupper(approval) == 'Y'){
	        bankStatement();
	        printf("The bank statement successfully approved. The statement will be sent to the user via email.\n");
	    } else {
	        printf("User's request rejected.\n");
	    }
	}
	else
	printf("No request bank statement from user");
    system("pause");
    main();
}
