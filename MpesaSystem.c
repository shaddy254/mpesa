#include<stdio.h>
#include<string.h>

///varaibles
char name;
int withdraw_cash;
int transaction;
int mpesa_first_page;
int FINAL;
int  number;
int phone_number;
int amount_to_send;
int security_pin;
 int money_send;
int number_moneyis_send;



// int mpesa_pin;
// void withDrawFromATM();
// void withDrawFromAgent();
// void sendMoney();
// void withDrawMoney();
// void buyAirTime();
// void loansAndSavings();
// void lipaNaMpesa();
// void selectMpesaTransaction();
// void selectSSafaricomPlus();
// void  myPhone();
// void saveFile();
// void readFile();
void userConfirmation();

int main(){
    printf("Please select \n 1: for safaricom \n 2: for Mpesa : ");
    scanf("%d", &mpesa_first_page);
    // saveFile();
    // readFile();
    if(mpesa_first_page == 1)
       selectSSafaricomPlus();
    if(mpesa_first_page == 2) 
      selectMpesaTransaction();
    else 
       printf("Invalid Choice.");
    
    return 0;
}

void selectMpesaTransaction(){
    printf("***************************************\n");
    printf("Kindly enter your Choice of Transaction : \n");
    printf("1. Send Cash \n");
    printf("2. Withdrwal Cash \n");
    printf("3. Buy Airtime \n");
    printf("4. Loans AND Savings \n");
    printf("5. Lipa NaMPesa \n");
    printf("******************************************\n");
    scanf("%d", &transaction);
    switch (transaction){
        case 1://send money
            sendMoney();
            break;
        case 2: // withdarw cash
            withDrawMoney();
            break;
        case 3: // buy airtime
            buyAirTime();
            break;
        case 4: // loans and savings
            loansAndSavings();
            break;
        case 5: // Lipa na Mpesa 
            lipaNaMpesa();
            break; 
        default:
            printf("invalid choice please try again\n");
            break;
    }
}

void selectSSafaricomPlus(){
    printf("safaricom++");
    //TODO
}

//option 1
void sendMoney(){
    printf("Kindly enter phone Number : ");
    scanf("%s", &phone_number);
    printf("Kindly enter Amount to Send : ");
    scanf("%d", &amount_to_send);
    
    for (int i = 0; i < 3; i++) {
        printf("Kindly enter Security pin: \n");
        scanf("%d", &security_pin);
            if(security_pin == 1234){
                printf("You have transfered &d to &s ", amount_to_send, phone_number);
                break;
            }else if(i <=3){
                printf("Kindly Enter the Correct pin \n");
            }else {
               printf("Too manty attempts..... Contact Customer care for assistance \n");
            }
        }
    }
    

void withDrawMoney(){
    int withdraw_cash;
    printf("**********************************************\n");
    printf("withdraw from \n 1: From Agent\n 2:From ATM\n");
    scanf("%d", &withdraw_cash);
    if (withdraw_cash == 1) 
        withDrawFromAgent();
    else if(withdraw_cash == 2)
        withDrawFromATM();
    else
        printf("invalid choice\n");
}

void buyAirTime(){
  
}

void loansAndSavings(){
    //TODO
}

void selectMpesaTansaction(){
    //TODO
}

void  lipaNaMpesa(){
  //TODO
 }

 void withDrawFromATM(){
     printf("Operatiion not available for now. Try later\n");
 }

 void withDrawFromAgent(){
    int agentNumber;
    int amount_to_withdral;
    int mpesa_pin;
    int count = 0; //initialise count
    printf("enter Agent Number\n");
    scanf("%d", &agentNumber);
    printf( "please enter the amount to withdraw \n");
    scanf("%d", &amount_to_withdral);

    do {
        printf("Enter your MPesa PIN \n");
        scanf("%d", &mpesa_pin);
        count = count+1;
        if(count > 2){
            printf("Too many Attempts. Kindly Contact Customer care for Assistance \n");
            // goto FINAL;
            break;
        }
        else if (mpesa_pin == 1234){
           printf("SUCCESS\n");
        //    goto FINAL;
            break;
        }
    }while(mpesa_pin != 1234);

    FINAL:
        printf("Thank you for using MPesa.\n");
 }

void saveFile(){
    FILE *file_to_write;  //dfining a file like int x
    int i, n;  //loooping in the forloop
    char name[20], phone_number[10]; //define two strings name, phone number
     
    file_to_write= fopen("contacts.txt", "w"); //open the fie to write in append mode
    printf("Enter number of contacts to write : "); //number of time to loop to get numbers
    scanf("%d", &n); //get the number of times from keyboard
    fwrite("-------------------------------------\n", 68, 1, file_to_write); //
    fputs("\n", file_to_write); //write a new line
    fwrite("NO. \t\t\t\t CONTACT NAME\n", 68, 1, file_to_write );
   
    //loop n times
    for (i = 0; i < n; i++)  {
        printf("Enter name and contact of Person \n");  //
        scanf("%s %s", name, phone_number);
        fseek(file_to_write, 10, SEEK_CUR); //positio cursor to cur position
        fwrite(name, strlen(name), 1, file_to_write); //write the name to file
        fprintf(file_to_write, "\t"); //write a tab space to file
        fwrite(phone_number, strlen(phone_number), 1, file_to_write); //write the contact to file
        fputs("\n", file_to_write); //new line
    }
    
    fseek(file_to_write, 10, SEEK_END); //place cursor to end of file
    fwrite("-------------------------------------\n", 68, 1, file_to_write); //write to file .............
    fputs("\n", file_to_write);  //new line
    fclose(file_to_write); //close the file
    printf("Contact Added to the File and saved Successfully. \n");
    return;
}

void readFile(){
    FILE *file_to_read;
    char msg[121];
    char string[] = "Our Fathrer who art in Heaven \n";
    int a[20];
    int i;
    
    printf("Enter the reading file \n");
    scanf("%s", &file_to_read);
    file_to_read = fopen(file_to_read, "r");

    if (file_to_read == NULL) {
        /* code */
        printf("File %s does not exist", file_to_read);
    }else {
        printf("The file is successfully opened. \n");
        fseek(file_to_read, 10, SEEK_SET);

        while (!(feof(file_to_read))) {
            // printf("Reaading file %d times \n", i);
            fgets(msg, strlen(string), file_to_read);
            printf("%s", msg);
            i++;
        }
    }
    fclose(file_to_read);
}

void userConfirmation()
{
    struct transactionstatement
    { 
       char name;
        int money_send;
        int number_moneyis_send;    
    } ;

    int i;
    int n;
     
    printf("customer records\n");
    
    FILE *file_to_read;
   file_to_read = fopen("c:\\ userconfirmation.text", "r");   
   if (file_to_read == NULL)
   {
      printf("error!");
      exit(1);
   }
    for ( i = 0; i <n; i++)
    {
        printf("enter the name money has been send to");
        scanf("%d", &name);
        printf("enter the number the money has been send to");
        scanf("%d", &number_moneyis_send);
        printf("enter the amount money send ");
        scanf("%d", &amount_to_send);
        fprintf(file_to_read,"name:\n name:");
        fclose(file_to_read);
        return 0;
    
    }
}
