#include <stdio.h>
#include <time.h>


void income();
void expenses();

void directExpense();
void recordMealExpense();

void transport();
void otherExpense();

void aboutUs();



int main(){

    time_t date;
    time(&date);

    FILE *totalCashAvailable;

    float total;

    totalCashAvailable = fopen("totalCashAvailable.txt","r");

    fscanf(totalCashAvailable,"%f",&total);





    printf("\n\n\t\t\t\t\t*********************************************\n");

    printf("\t\t\t\t\t*FINANCIAL MANEGMENT FOR UNIVERSITY STUDENTS*\n");

    printf("\t\t\t\t\t*********************************************\n\n\n");


    printf("\t\t\tDATE: %s",ctime(&date));


    printf("\n\t\t\tTOTAL CASH AVAILABLE: %.2f \n",total);

        printf("\n\n\t\t\t\t\t\t     MAIN MENU:");

        printf("\n\n\t\t\t\t\t\tINCOME\t\t[i]");

        printf("\n\t\t\t\t\t\tEXPENSES\t[e]");

        printf("\n\t\t\t\t\t\tABOUT US\t[a]");

        printf("\n\t\t\t\t\t\tEXIT\t\t[x]");

        printf("\n\n\t\t\t\t\t\tENTER YOUR CHOICE:");

// Interface design is in here  income  = fopenf("","w")

char homePageSelection; // Assign the selecting function from the homepage
scanf("%s",&homePageSelection);


switch(homePageSelection){

    case 'E':case 'e':
        expenses();
        break;
    case 'I':case 'i':
        income();
        break;
    case 'A':case 'a':
        aboutUs();
        break;
    case 'X':case 'x':
        exitApp();
        break;

};

system("pause");
return 0;

}


void income(){

    float income;
    float total;

    FILE *totalCashAvailable;
    totalCashAvailable = fopen("totalCashAvailable.txt","r");

    if(totalCashAvailable==NULL){

           printf("Error");

    }else{


           fscanf(totalCashAvailable,"%f",&total);
           fclose(totalCashAvailable);

           printf("\n\n\t\t\t\t\t\tENTER THE INCOME (Rs) = ");
           scanf("%f",&income);

           if(income>0){

                total+=income;
                totalCashAvailable = fopen("totalCashAvailable.txt","w");
                fprintf(totalCashAvailable,"%.2f",total);
                fclose(totalCashAvailable);


                FILE *incomeDate;
                time_t date;
                time(&date);
                incomeDate=fopen("Income.txt","a+");
                fprintf(incomeDate,"Income = %.2f \t Date & Time : %s\n",income,ctime(&date));
                fclose(incomeDate);


            }

    }

    printf("\n\n\t\t\t\t\t*********************************************\n");

    printf("\t\t\t\t\t\t\t*THANK YOU!*\n");

    printf("\t\t\t\t\t\t\t*TASK IS COMPLETED!*\n");

    printf("\t\t\t\t\t*********************************************\n\n\n");



};


void expenses(){


    //printf("Enter Your Choice = ");
    time_t date;
    time(&date);

    FILE *totalCashAvailable;
    float total;

    totalCashAvailable = fopen("totalCashAvailable.txt","r");

    fscanf(totalCashAvailable,"%f",&total);

    fclose(totalCashAvailable);




    printf("\n\n\t\t\t\t\t*********************************************\n");

    printf("\t\t\t\t\t\t\t*Expenses for Meals*\n");

    printf("\t\t\t\t\t*********************************************\n\n\n");


    //printf("\t\t\tDATE: %s",ctime(&date));


   // printf("\n\t\t\tTOTAL CASH AVAILABLE: %.2f \n",&total);

        printf("\n\n\t\t\t\t\t\t\tUNIVERSITY CANTEEN MEAL EXPENSES:");

        printf("\n\n\t\t\t\t\t\tDIRECT SAVE MEAL EXPENSES(UNIVERSITY CANTEEN)\t[d]\n");

        printf("\n\t\t\t\t\t\tRECORD AND SAVE EXPENSES(UNIVERSITY CANTEEN)\t[r]");

        printf("\n\n\t\t\t\t\t\tENTER YOUR CHOICE:");

        char mealsExpensesInputChoice;
        scanf("%s",&mealsExpensesInputChoice);



  switch(mealsExpensesInputChoice){

        case 'D':case 'd':

            directExpense();
            transport();
            otherExpense();

            //transport function

            break;

        case 'R':case 'r':

            recordMealExpense();
            transport();
            otherExpense();

            break;



}


};





void directExpense(){

            float mealsExpenses;
            char meal_description[100];
            time_t date;
            time(&date);

    printf("\n\n");
    printf("\t\t\tMeal Name\t\t\tPrice(Rs.)\t\tTakeaway Price(Rs.)\n\n");
    printf("\t\t\tVegetable rice\t\t\t70.00\t\t\t75.00\n");
    printf("\t\t\tFish rice\t\t\t100.00\t\t\t105.00\n");
    printf("\t\t\tChicken rice\t\t\t120.00\t\t\t125.00\n");
    printf("\t\t\tEgg rice\t\t\t90.00\t\t\t95.00\n");
    printf("\t\t\tFried rice(Normal)\t\t110.00\t\t\t115.00\n");
    printf("\t\t\tChicken fried rice\t\t200.00\t\t\t205.00\n");
    printf("\t\t\tPan cake\t\t\t40.00\t\t\t45.00\n");
    printf("\t\t\tRolls\t\t\t\t65.00\t\t\t70.00\n");
    printf("\t\t\tRotee\t\t\t\t40.00\t\t\t45.00\n");
    printf("\t\t\tThose\t\t\t\t30.00\t\t\t35.00\n");
    printf("\t\t\tWade\t\t\t\t10.00\t\t\t10.00\n");
    printf("\t\t\tMilo\t\t\t\t130.00\t\t\t130.00\n\n");


            printf("\n\n\t\t\t\t\t\tENTER MEAL EXPENSE(RS)  = ");
            scanf("%f",&mealsExpenses);
            fflush(stdin);
            printf("\n\t\t\t\t\t\tDISCRIPTION = ");
            gets(meal_description);

            FILE *expenses;
            expenses = fopen("Expenses.txt","a+");
            fprintf(expenses,"***V***\n\nDate = %s\nMeal Expense = %.2f\n\nMeal Description = %s\n",ctime(&date),mealsExpenses,meal_description);
            fclose(expenses);

            FILE *totalCashAvailable;
            float totalCashAvailable_IN_totalCashAvailable;
            totalCashAvailable = fopen("totalCashAvailable.txt","r");
            fscanf(totalCashAvailable,"%f",&totalCashAvailable_IN_totalCashAvailable);
            fclose(totalCashAvailable);

            totalCashAvailable_IN_totalCashAvailable -= mealsExpenses;


            totalCashAvailable = fopen("totalCashAvailable.txt","w");
            fprintf(totalCashAvailable,"%.2f",totalCashAvailable_IN_totalCashAvailable);
            fclose(totalCashAvailable);



}

//\n\n***^***

void recordMealExpense(){

            time_t date;
            time(&date);



            struct meals {

                char name[20];
                float price;
                int quantity;
                float total;
                char description[50];

            };

            float totalCash = 0;

            struct meals meal;
            int howMany;


    printf("\n\n");
    printf("\t\t\tMeal Name\t\t\tPrice(Rs.)\t\tTakeaway Price(Rs.)\n\n");
    printf("\t\t\tVegetable rice\t\t\t70.00\t\t\t75.00\n");
    printf("\t\t\tFish rice\t\t\t100.00\t\t\t105.00\n");
    printf("\t\t\tChicken rice\t\t\t120.00\t\t\t125.00\n");
    printf("\t\t\tEgg rice\t\t\t90.00\t\t\t95.00\n");
    printf("\t\t\tFried rice(Normal)\t\t110.00\t\t\t115.00\n");
    printf("\t\t\tChicken fried rice\t\t200.00\t\t\t205.00\n");
    printf("\t\t\tPan cake\t\t\t40.00\t\t\t45.00\n");
    printf("\t\t\tRolls\t\t\t\t65.00\t\t\t70.00\n");
    printf("\t\t\tRotee\t\t\t\t40.00\t\t\t45.00\n");
    printf("\t\t\tThose\t\t\t\t30.00\t\t\t35.00\n");
    printf("\t\t\tWade\t\t\t\t10.00\t\t\t10.00\n");
    printf("\t\t\tMilo\t\t\t\t130.00\t\t\t130.00\n\n");

            printf("\n\n\t\t\t\t\t\tENTER NUMBER OF *DIFFERENT* FOOD YOU BOUGHT (1,2,3,4,etc) = ");
            scanf("%d",&howMany);

            FILE *mealExpense;
            mealExpense = fopen("Expenses.txt","a+");
            fprintf(mealExpense,"***V***\n\nDate = %s\n",ctime(&date));

            for(int i = 1;i<=howMany;i++){

            printf("\n\n\t\t\t\t\t\tENTER %d FOOD NAME  = ",i);
            fflush(stdin);
            gets(meal.name);

            printf("\n\n\t\t\t\t\t\tENTER PRICE ONE ITEM  = ");
            scanf("%f",&meal.price);
            printf("\n\n\t\t\t\t\t\tENTER QUANTITY(1,2,3, etc) = ");
            scanf("%d",&meal.quantity);
            fflush(stdin);
            printf("\n\n\t\t\t\t\t\tENTER A DESCRIPTION = ");
            gets(&meal.description);

            meal.total = meal.price * meal.quantity;

            totalCash += meal.total;


            fprintf(mealExpense,"Meal Name(%d) = %s\tPrice = %.2f\tQuantity = %d\tTotal Price for that Meal = %.2f\n\nMeal %d Description = %s\n\n",i,meal.name,meal.price,meal.quantity,meal.total,i,meal.description);


            };

            fclose(mealExpense);

             FILE *totalCashAvailable;
            float totalCashAvailable_IN_totalCashAvailable;
            totalCashAvailable = fopen("totalCashAvailable.txt","r");
            fscanf(totalCashAvailable,"%f",&totalCashAvailable_IN_totalCashAvailable);
            fclose(totalCashAvailable);

            totalCashAvailable_IN_totalCashAvailable -= totalCash;


            totalCashAvailable = fopen("totalCashAvailable.txt","w");
            fprintf(totalCashAvailable,"%.2f",totalCashAvailable_IN_totalCashAvailable);
            fclose(totalCashAvailable);



//\n***^***\n\n

}


void transport(){

    printf("\n\n\t\t\t\t\t*********************************************\n");

    printf("\t\t\t\t\t\t\t*Expenses for Transport*\n");

    printf("\t\t\t\t\t*********************************************\n\n\n");

    printf("\t\t\tTransport\n\n\n");
    printf("\t\t\tFrom\t\t\tTo\t\t\tPrice(Rs.)\t\tBy\n\n");
    printf("\t\t\tUWU\t\t\tBadulla\t\t\t50.00\t\t\tBus\n");
    printf("\t\t\tBadulla\t\t\tPassara\t\t\t120.00\t\t\tBus\n");
    printf("\t\t\tUWU\t\t\t2nd Mile Post\t\t30.00\t\t\tBus\n");
    printf("\t\t\tUWU\t\t\tAlugolla\t\t100.00\t\t\tBus\n");
    printf("\t\t\tBadulla\t\t\tElla\t\t\t50.00\t\t\tTrain\n");
    printf("\t\t\tUWU\t\t\tJayagama\t\t30.00\t\t\tBus\n");
    printf("\t\t\tBadulla\t\t\tMahiyangana\t\t200.00\t\t\tBus\n");
    printf("\t\t\tUWU\t\t\tWewassa\t\t\t70.00\t\t\tBus\n");
    printf("\t\t\tBadulla\t\t\tDunhinda\t\t450.00\t\t\tThree-wheel\n");
    printf("\t\t\tBadulla\t\t\tHaputale\t\t60.00\t\t\tTrain\n");
    printf("\t\t\tHaputale\t\tAddishom\t\t100.00\t\t\tBus\n");


            float transportExpenses;
            char transport_description[100];


            printf("\n\n\t\t\t\t\t\tENTER TRANSPORT EXPENSE (Rs) = ");
            scanf("%f",&transportExpenses);
            fflush(stdin);
            printf("\n\t\t\t\t\t\tDISCRIPTION = ");
            gets(transport_description);

            FILE *expenses;
            expenses = fopen("Expenses.txt","a+");
            fprintf(expenses,"\nTransport Expense = %.2f\n\nTransport Description = %s\n",transportExpenses,transport_description);
            fclose(expenses);


            FILE *totalCashAvailable;
            float totalCashAvailable_IN_totalCashAvailable;
            totalCashAvailable = fopen("totalCashAvailable.txt","r");
            fscanf(totalCashAvailable,"%f",&totalCashAvailable_IN_totalCashAvailable);
            fclose(totalCashAvailable);

            totalCashAvailable_IN_totalCashAvailable -= transportExpenses;


            totalCashAvailable = fopen("totalCashAvailable.txt","w");
            fprintf(totalCashAvailable,"%.2f",totalCashAvailable_IN_totalCashAvailable);
            fclose(totalCashAvailable);




};

void otherExpense(){



    printf("\n\n\t\t\t\t\t*********************************************\n");

    printf("\t\t\t\t\t\t\t*Other Expenses*\n");

    printf("\t\t\t\t\t*********************************************\n\n\n");

            float *p;
            float otherExpenses;
            char other_description[100];
            float totalCash = 0;
             p = &otherExpenses;

            int howMany;

            printf("\n\n\t\t\t\t\t\tENTER NUMBER OF *DIFFERENT* OTHER EXPENSES(1,2,3,4,etc) = ");
            scanf("%d",&howMany);

            FILE *otherExpense;
            otherExpense = fopen("Expenses.txt","a+");


            for(int i = 1;i<=howMany;i++){



            printf("\n\n\t\t\t\t\t\tENTER %d Price (Rs) = ",i);
            scanf("%f",&otherExpenses);
            fflush(stdin);
            printf("\n\t\t\t\t\t\tDISCRIPTION = ");
            gets(other_description);

            totalCash += otherExpenses;


            fprintf(otherExpense,"\nOther Expense(%d) = %.2f\n\nTransport Description = %s\n",i,*p,other_description);




            }

            fprintf(otherExpense,"\n\n***^***\n\n");

            fclose(otherExpense);

            FILE *totalCashAvailable;
            float totalCashAvailable_IN_totalCashAvailable;
            totalCashAvailable = fopen("totalCashAvailable.txt","r");
            fscanf(totalCashAvailable,"%f",&totalCashAvailable_IN_totalCashAvailable);
            fclose(totalCashAvailable);

            totalCashAvailable_IN_totalCashAvailable -= totalCash;


            totalCashAvailable = fopen("totalCashAvailable.txt","w");
            fprintf(totalCashAvailable,"%.2f",totalCashAvailable_IN_totalCashAvailable);
            fclose(totalCashAvailable);

    printf("\n\n\t\t\t\t\t*********************************************\n");

    printf("\t\t\t\t\t\t\t*THANK YOU!*\n");

    printf("\t\t\t\t\t\t\t*TASK IS COMPLETED!*\n");

    printf("\t\t\t\t\t*********************************************\n\n\n");




};

void aboutUs(){



};

void exitApp(){




};
