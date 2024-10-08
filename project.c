#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaring typedef struct User
typedef struct{
    char acc_name[30];
    int acc_num;
    char password[20];
    int balance;
}User;

// Declaring functions

//void log_menu(void);                      // login menu[not req]
    User create_acc(User *user);            // new acc to existing list of users
    int exist_acc(User *user);              // login to existing dummy acc; int i
void main_menu(User user);                  // main menu
    int fund_menu(User user);               // fund transfer menu
        int send_money(User user);          // fund transfer sub- send money
        int rec_money(User user);           // fund transfer sub- receive money
    int bill_pay(User user);                // bill n payment
    void card_menu(User user);              // card menu
        void create_card(User user);        // create new card
        void add_card(User user);           // enter existing card
    void cust_support(User user);           // customer support
    void remove_acc(User user);             // remove account
    void log_out(User user);                // log out of current account; end of program
void send_receipt(User user, int  amt, char acc_name2[]);     // receipt
void dep_receipt(User user, int  amt, char acc_name2[]);      // receipt
void logo(void);                            // logo


int main(void)
{
    int option = 0, a = 0;
    User user1 = {"ABC", 1234567890, "master_key", 25000}; // Dummy
    User user2 = {"DEF", 1987654321, "master_key", 10000}; // Dummy
    User users[] = {user1, user2};
    int i = 1; //sizeof(users)/sizeof(users[0]);

    // Login menu
    logo();
    printf("\n\t**********************************************************************\n");
    printf("\t*\t\tWelcome to Banking Management System!                *\n");
    printf("\t*\t\t\t     Login Menu                              *\n");
    printf("\t*____________________________________________________________________*\n");
    printf("\t*\t1 = \tCreate a new account                                 *\n");
    printf("\t*\t2 = \tLog in(if existing user)                             *\n");
    printf("\t**********************************************************************\n");

    // User input
    do{
        printf("\t\t\t\tChoose your option: ");
        scanf("%d", &option);
        if(option < 0 || option > 3)
            printf("\t\t\tInvalid input !! Try again!\n");
    }while(option < 0 || option > 3);
    printf("\n\n");

    switch(option)
    {
        case 1:
            users[i] = create_acc(users); // returns struct user
            break;
        case 2:
            i = exist_acc(users); // returns index in users array
            break;
    }
    //printf("login done\n");

    main_menu(users[i]);
    return 0;
}

// defining functions

User create_acc(User *user)                 // Create account[takes input for acc_name, acc_num, password, first balance]
{
    User user1 = {"Hello", 1234456677, "master_key", 210000}; // Dummy
    return user1;
}

int exist_acc(User *user)                   // Login to existing account
{
    return 0; // index value of users array
}

void main_menu(User user)                   // Main menu
{
    int option;
    printf("bal%d\n", user.balance);
    logo();
    printf("\n\t**********************************************************************\n");
    printf("\t*\t\tWelcome to Banking Management System!                *\n");
    printf("\t*\t\t\t      Main Menu                              *\n");
    printf("\t*____________________________________________________________________*\n");
    printf("\t*\t1 = \tFund transfer.                                       *\n");
    printf("\t*\t2 = \tOnline payments and billing.                         *\n");
    printf("\t*\t3 = \tCards.                                               *\n");
    printf("\t*\t4 = \tCustomer support.                                    *\n");
    printf("\t*\t5 = \tRemove your existing bank account.                   *\n");
    printf("\t*\t6 = \tLog out.                                             *\n");
    printf("\t**********************************************************************\n");

    // Taking user input
    do{
        printf("\t\t\t\tChoose your option: ");
        scanf("%d", &option);
        if(option < 0 || option > 7)
            printf("Invalid input !! Try again!\n");
    }while(option < 0 || option > 7);
    printf("\n\n");

    switch(option)
    {
        case 1:
            user.balance = fund_menu(user);
            break;
        case 2:
            user.balance = bill_pay(user);
            break;
        case 3:
            card_menu(user);
            break;
        case 4:
            cust_support(user);
            break;
        case 5:
            remove_acc(user);
            break;
        case 6:
            log_out(user);
            break;
    }
    main_menu(user);
}

int fund_menu(User user)                    // Fund menu
{
    int option = 0, balance = user.balance;
    printf("\n\t**********************************************************************\n");
    printf("\t*\t\tWelcome to Fund transfer: Master Menu!               *\n");
    printf("\t*____________________________________________________________________*\n");
    printf("\t*\t1 =\tSend money                                           *\n");
    printf("\t*\t2 =\tReceive money                                        *\n");
    printf("\t**********************************************************************\n");

    // User input
    printf("\t\t\t\tEnter your choice: ");
    do{
        scanf("%d", &option);
        if(option < 0 || option > 3)
            printf("\t\t\tInvalid input!! Try again!\n");
    }while(option < 0 || option > 3);
    printf("\n\n");

    switch(option)
    {
        case 1:
            balance = send_money(user);
            break;
        case 2:
            //balance = rec_money(user);
            break;
    }
    return balance;
}

int send_money(User user)                   // Send money
{
    long int ben_acc = 0;
    int amount = 0, option = 0, balance = user.balance;
    char ben_name[25], ans, pass[20];
    printf("\t**********************************************************************\n");
    printf("\t*\t\tWelcome to Fund Transfer: Send money!                *\n");
    printf("\t*____________________________________________________________________*\n");
    printf("\t*\tEnter 12 digit beneficiary account number: ");
    scanf("%li", &ben_acc);
    printf("\t*\tEnter beneficiary name: ");
    scanf("%s", ben_name);
    printf("\t*\tEnter amount(in Rupees): ");
    scanf("%d", &amount);
    printf("\t**********************************************************************\n");
    printf("\t\t Modes of payment:\n");
    printf("\t\t*************************\n");
    printf("\t\t*\t1 =\tIMPS\t*\n");
    printf("\t\t*\t2 =\tNEFT\t*\n");
    printf("\t\t*\t3 =\tRTGS\t*\n");
    printf("\t\t*************************\n");
        do{
            printf("\tSelect your mode of payment: ");
            scanf("%d", &option);
            if(option < 0 || option > 4)
                printf("\t\t\tInvalid input!! Try again!\n");
        }while(option < 0 || option > 4);
    printf("\t%s", user.password);
    getchar();
    printf("\n\tEnter your password: ");
    gets(pass);
    if(strcmp(pass,user.password) == 0)
    {
        switch(option)
        {
            case 1:
                if(amount >= 1 && amount <= 200000)
                {
                    if((balance-amount) >= 0)
                    {
                        balance -= amount;
                        printf("\t\t\tTransaction successfully completed!!\n");
                        printf("\t\t\tNew balance\t= Rs. %12d\n", balance);
                        printf("\t\t\tAmount deducted\t= Rs. %12d\n",amount);
                        printf("\t\tDo you want to print receipt? (y/n): ");
                        scanf("%c", &ans);
                        if(ans == 'y')
                            send_receipt(user, amount, ben_name);
                    }
                    return balance;
                    break;
                }
            case 2:
                if(amount >= 1)
                {
                    if((balance-amount) >= 0)
                    {
                        balance -= amount;
                        printf("\t\t\tTransaction successfully completed!!\n");
                        printf("\t\t\tNew balance\t= Rs. %12d\n", balance);
                        printf("\t\t\tAmount deducted\t= Rs. %12d\n",amount);
                        printf("\t\tDo you want to print receipt?(y/n): ");
                        scanf("%c", &ans);
                        if(ans == 'y')
                            send_receipt(user, amount, ben_name);
                    }
                    return balance;
                    break;
                }
            case 3:
                if(amount >= 200000)
                {
                    if((balance-amount) >= 0)
                    {
                        balance -= amount;
                        printf("\t\t\tTransaction successfully completed!!\n");
                        printf("\t\t\tNew balance\t= Rs. %12d\n", balance);
                        printf("\t\t\tAmount deducted\t= Rs. %12d\n",amount);
                        printf("\t\tDo you want to print receipt? (y/n): ");
                        scanf("%s", &ans);
                        if(ans == 'y')
                            send_receipt(user, amount, ben_name);
                    }
                    return balance;
                    break;
                }
            default:
                printf("\t\t\tTransaction failed!! Try again!\n");
                break;
        }
    }
    else
        printf("\t\t\tTransaction failed!! Try again!\n");
    return balance;
}

int bill_pay(User user)                     // Pay your bills online
{
    printf("pay ur bill\n");
    return user.balance;
}

void card_menu(User user)                   // Card menu
{
    int option = 0, balance = user.balance;
    logo();
    printf("\n\t**********************************************************************\n");
    printf("\t*\t\tWelcome to Cards: Master Menu!                          *\n");
    printf("\t*____________________________________________________________________*\n");
    printf("\t*\t1 =\tGenerate New Card                                    *\n");
    printf("\t*\t2 =\tAdd Existing Card                                    *\n");
    printf("\t**********************************************************************\n");

    // User input
    printf("\t\t\t\tEnter your choice: ");
    do{
        scanf("%d", &option);
        if(option < 0 || option > 3)
            printf("\t\t\tInvalid input!! Try again!\n");
    }while(option < 0 || option > 3);
    printf("\n\n");

    switch(option)
    {
        case 1:
            create_card(user);
            break;
        case 2:
            add_card(user);
            break;
    }
}

void create_card(User user)                 // Create new card
{
    printf("Add new card\n");
}

void add_card(User user)                    // Add existing card
{
    printf("Add exisiting card\n");
}

void cust_support(User user)                // Customer support
{
    printf("customer support\n");
}

void remove_acc(User user)                  // Remove your bank account
{
    printf("remove acc\n");
}

void log_out(User user)                     // Log out of current session
{
    printf("log out\n");
    exit(0); // exit out of program completely
}

void send_receipt(User user, int amt, char acc_name2[])  // Receipt template[uses user.acc_name(from), amt, acc_name2(to)]
{
    printf("\tsend receipt\n");
}

void dep_receipt(User user, int amt, char acc_name2[])   // Receipt template[uses user.acc_name(to), amt, acc_name2(from)]
{
    printf("\tdep receipt\n");
}

void logo(void)                             // Logo
{
    int i, j, n = 5;
    for(i = 1; i <= n; i++)
    {
        printf("\t\t    ");
        for(j = 1; j <= n; j++)
        {
            if(j == i || (j == (n - i + 1)))
                printf("₹ ");
            else if((j == (i + 1) && j != 2 && j!= n) || (j == (i - 1)) && j != 1 && j != (n - 1))
                printf("  ");
            else
                printf("☆ ");
        }
        if(i == 3)
            printf("\t☆ Welcome to <Bank_name> !!! ☆");
        printf("\n");
    }
}
