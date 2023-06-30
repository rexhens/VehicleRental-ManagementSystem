#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct client Client;
struct vehicle{
    char plateNum[20];
    char carModel[20];
    int yearProduced;
    char fuelType[20];
    double consumption;
    int noSeats;
    double dailyPrice;
    int nrOfRes;
    struct vehicle *link;
};

struct reservation{
    char plateNum[20];
    int reservationID;
    int reservationDate;
    int reservationDateInt;
    int clientId;
    int nrDays;
    double totalPrice;
    int daysPassedReservation;
    struct reservation *link;
};

struct client{
    int clientID;
    int nrReservation;
    char clientName[20];
    char clientSurname[20];
    int passportID;
    char state[20];
    int phoneNumber;
    struct client *link;
};

int cntVehicle,cntReservation,cntClient;

void getDataFileVehicle(struct vehicle **head)
{
    FILE *file1 = NULL;
    file1 = fopen("C:\\Users\\User\\CLionProjects\\projectProgramming\\allVehicleInfo.txt","r");
    if(file1==NULL)
    {
        printf("The file doesn't exist!");
        return;
    }

    fscanf(file1,"%d",&cntVehicle);
    if(cntVehicle==0)
    {
        printf("There are no vehicles added!");
        return;
    }
    int j = 0;
    struct vehicle *prevVehicle = NULL,*newVehicle= NULL;
    for (int i = 0; i < cntVehicle; ++i) {
        newVehicle= (struct vehicle*)malloc(sizeof (struct vehicle));
        fscanf(file1,"%s%d%lf%d%lf",newVehicle->plateNum,&newVehicle->yearProduced,
               &newVehicle->consumption,&newVehicle->noSeats,&newVehicle->dailyPrice);
        fscanf(file1,"%s%s%d",newVehicle->carModel,newVehicle->fuelType,&newVehicle->nrOfRes);
        newVehicle->link = NULL;
        j++;

        if(i==0)
        {
            *head = newVehicle;
        } else{
            for(prevVehicle=*head;prevVehicle->link!=NULL;prevVehicle=prevVehicle->link){

            }
            prevVehicle->link = newVehicle;
            newVehicle->link = NULL;
        }

    }
    printf("%d vehicles are added!\n",j);
}


void printDataFileVehicle(struct vehicle *head)
{
    FILE *file1 = fopen("C:\\Users\\User\\CLionProjects\\projectProgramming\\allVehicleInfo.txt","w");
    if(file1==NULL)
    {
        printf("The file doesn't exist!");
        return;
    }
    fprintf(file1,"%d\n",cntVehicle);
    int i=0;
    for(;head!=NULL;head=head->link)
    {
        fprintf(file1,"%s %d %.2lf %d %.2lf %s %s %d\n",head->plateNum ,
                head -> yearProduced,head->consumption,head->noSeats ,
                head->dailyPrice,head->carModel,head->fuelType,head->nrOfRes);
        i++;
    }
    printf("\n%d vehicles are added in the file!",i);

}


void printDataFileAllReservations(struct reservation *head)
{

    FILE *file1 = fopen("C:\\Users\\User\\CLionProjects\\projectProgramming\\reservation.txt","w");
    if(file1==NULL)
    {
        printf("The file doesn't exist!");
        return;
    }
    fprintf(file1,"%d\n",cntReservation);
    int i=0;

    for(;head!=NULL;head=head->link) {
        head->daysPassedReservation--;
        if(head->daysPassedReservation<0)
        {
            head->daysPassedReservation = -1;
        }
        fprintf(file1, "%d %d %d %.2lf %d %s\n", head->reservationID, head->reservationDate,
                 head->clientId, head->totalPrice,head->reservationDateInt,head->plateNum);
        i++;

    }

    printf("%d reservations are added in the file of reservations!\n",i);


}


void getDataReservation(struct reservation **head)
{
    FILE *file1 = NULL;
    file1 = fopen("C:\\Users\\User\\CLionProjects\\projectProgramming\\reservation.txt","r");
    if(file1==NULL)
    {
        printf("The file doesn't exist!");
        return;
    }

    fscanf(file1,"%d",&cntReservation);
    if(cntReservation==0)
    {
        printf("There are no reservations added!");
        return;
    }
    struct reservation *prevVehicle = NULL,*newVehicle= NULL;
    int j=0;
    for (int i = 0; i < cntReservation; ++i) {
        newVehicle= (struct reservation*)malloc(sizeof (struct reservation));
        fscanf(file1,"%d%d%d%lf%d%s",&newVehicle->reservationID,&newVehicle->reservationDate,
               &newVehicle->clientId,&newVehicle->totalPrice,&newVehicle->reservationDateInt,newVehicle->plateNum);
        newVehicle->link = NULL;
        j++;

        if(i==0)
        {
            *head = newVehicle;
        } else{
            for(prevVehicle=*head;prevVehicle->link!=NULL;prevVehicle=prevVehicle->link){

            }
            prevVehicle->link = newVehicle;
            newVehicle->link = NULL;
        }

    }
    printf("%d reservations are added!\n",j);
}



void getDataFileClient(struct client **head)
{
    FILE *file1 = NULL;
    file1 = fopen("C:\\Users\\User\\CLionProjects\\projectProgramming\\clients.txt","r");
    if(file1==NULL)
    {
        printf("The file doesn't exist!");
        return;
    }

    fscanf(file1,"%d",&cntClient);
    if(cntReservation==0)
    {
        printf("There are no clients available!");
        return;
    }
    int j=0;
    struct client *prevVehicle = NULL,*newVehicle= NULL;
    for (int i = 0; i < cntClient; ++i) {
        newVehicle= (struct client*)malloc(sizeof (struct client));
        fscanf(file1,"%d%s%s%s%d%d%d",&newVehicle->clientID,newVehicle->clientName,
               newVehicle->clientSurname,newVehicle->state,&newVehicle->passportID,&newVehicle->phoneNumber,&newVehicle->nrReservation);
        newVehicle->link = NULL;
        j++;

        if(i==0)
        {
            *head = newVehicle;
        } else{
            for(prevVehicle=*head;prevVehicle->link!=NULL;prevVehicle=prevVehicle->link){

            }
            prevVehicle->link = newVehicle;
            newVehicle->link = NULL;
        }

    }
    printf("%d clients are registered!\n",j);
}

void printDataFileClient(struct client *head)
{
    FILE *file1 = fopen("C:\\Users\\User\\CLionProjects\\projectProgramming\\clients.txt","w");
    if(file1==NULL)
    {
        printf("The file doesn't exist!");
        return;
    }
    fprintf(file1,"%d\n",cntClient);
    int i=0;
    for(;head!=NULL;head=head->link)
    {
        fprintf(file1,"%d %s %s %s %d %d %d\n",head->clientID,head->clientName,
                head->clientSurname,head->state,head->passportID,head->phoneNumber,head->nrReservation);
        i++;
    }
    printf("\n%d clients are added in the file!",i);

}

int getNumber(){
    int n;
    scanf("%d",&n);
    return n;
}

double getDouble(){
    double n;
    scanf("%lf",&n);
    return n;
}



void searchByPlate(struct vehicle *head)
{
    char plateNum[20];
    printf("Enter your plate Key");
    scanf("%s",plateNum);

int i = 1;
    while (head!=NULL)
    {
        if(strcmp(head->plateNum,plateNum)==0)
        {
            printf("Car %d\n"
                   "Vehicle plate number: %s\n"
                   "Vehicle year produced: %d\n"
                   "Vehicle car model: %s\n"
                   "Vehicle fuel type: %s\n"
                   "Vehicle consumption: %.2lf\n"
                   "Vehicle number of seats: %d\n"
                   "Vehicle daily price: %.2lf\n\n",i,head->plateNum ,
                   head -> yearProduced, head->carModel,head->fuelType,
                   head->consumption,head->noSeats , head->dailyPrice);
            i++;
        }
        head=head->link;
    }
}



void displayReservation(struct reservation *head)
{
    if(head==NULL)
    {
        printf("There are no reservations added!");
        return;
    }
    int i = 1;
    for ( ;head!=NULL;head=head->link) {
        printf("Reservation no: %d\n"
               "Reservation ID: %d\n"
               "Reservation Date: %d\n"
               "Reservation number of days: %d \n"
               "Reservation client ID: %d\n"
               "Reservation total price: %.2lf\n\n",i,head->reservationID,head->reservationDate,
               head->reservationDateInt,head->clientId,head->totalPrice);
        i++;
    }

}


void swapNodesData(struct vehicle *node1, struct vehicle *node2) {
    // Swap the plateNum
    char temp[20];
    strcpy(temp ,node1->plateNum);
    strcpy(node1->plateNum,node2->plateNum);
    strcpy(node2->plateNum,temp);

    // Swap the yearProduced
    int tempYearProduced = node1->yearProduced;
    node1->yearProduced = node2->yearProduced;
    node2->yearProduced = tempYearProduced;

    // Swap the fuelType
    char tempFuelType[20];
    strcpy(tempFuelType, node1->fuelType);
    strcpy(node1->fuelType, node2->fuelType);
    strcpy(node2->fuelType, tempFuelType);

    char model[20];
    strcpy(model ,node1->plateNum);
    strcpy(node1->plateNum,node2->plateNum);
    strcpy(node2->plateNum,model);


    // Swap the consumption
    double tempConsumption = node1->consumption;
    node1->consumption = node2->consumption;
    node2->consumption = tempConsumption;

    // Swap the noSeats
    int tempNoSeats = node1->noSeats;
    node1->noSeats = node2->noSeats;
    node2->noSeats = tempNoSeats;

    // Swap the dailyPrice
    double tempDailyPrice = node1->dailyPrice;
    node1->dailyPrice = node2->dailyPrice;
    node2->dailyPrice = tempDailyPrice;

    // Swap the nrOfReservation
    int tempNrOfReservation = node1->nrOfRes;
    node1->nrOfRes = node2->nrOfRes;
    node2->nrOfRes = tempNrOfReservation;
}

void printSorted(struct vehicle **head) {
    struct vehicle *current = *head;
int i=0;
    printf("Sorted List:\n");
    for (i=0;i<3;i++){
        printf("Plate Number: %s\n", current->plateNum);
        printf("Year Produced: %d\n", current->yearProduced);
        printf("Car model: %s\n",current->carModel);
        printf("Fuel Type: %s\n", current->fuelType);
        printf("Consumption: %.2lf\n", current->consumption);
        printf("Number of Seats: %d\n", current->noSeats);
        printf("Daily Price: %.2lf\n", current->dailyPrice);
        printf("Number of Reservations: %d\n", current->nrOfRes);
        printf("--------------------\n");

        current = current->link;
    }
}

void sortOnRes(struct vehicle **head) {

    if (*head == NULL || (*head)->link == NULL) {
        return ;
    }

    struct vehicle *current = *head;
    struct vehicle *temp = NULL;
    int swapped;

    do {
        swapped = 0;
        current = *head;

        while (current->link != temp) {
            //if (current->dailyPrice > current->ptr->dailyPrice) {
            if(current->nrOfRes < current->link->nrOfRes){
                // Swap the data of current and current->ptr nodes
                swapNodesData(current, current->link);
                swapped = 1;
            }
            current = current->link;
        }
        temp = current;
    } while (swapped);

}

void sortList(struct vehicle **head) {
    if (*head == NULL || (*head)->link == NULL) {
        return;
    }

    struct vehicle *current = NULL;
    struct vehicle *temp = NULL;
    int swapped;

    do {
        swapped = 0;
        current = *head;

        while (current->link != temp) {
            //if (current->dailyPrice > current->ptr->dailyPrice) {
            if(current->nrOfRes > current->link->nrOfRes){
                // Swap the data of current and current->ptr nodes
                swapNodesData(current, current->link);
                swapped = 1;
            }
            current = current->link;
        }
        temp = current;
    } while (swapped);
}

void sortDisplay(struct vehicle **head ) {
    struct vehicle *newRecord = (struct vehicle *)malloc(sizeof(struct vehicle));

    // Sort the linked list
    sortOnRes(head);

    // Print the sorted list
    printSorted(head);
}

void sortOnPrice(struct vehicle **head) {

    if (*head == NULL || (*head)->link == NULL) {
        return ;
    }

    struct vehicle *current = *head;
    struct vehicle *temp = NULL;
    int swapped;

    do {
        swapped = 0;
        current = *head;

        while (current->link != temp) {
            if(current->dailyPrice < current->link->dailyPrice){
                // Swap the data of current and current->ptr nodes
                swapNodesData(current, current->link);
                swapped = 1;
            }
            current = current->link;
        }
        temp = current;
    } while (swapped);

}


void sortDisplayPrice(struct vehicle **head ) {
    struct vehicle *newRecord = (struct vehicle *)malloc(sizeof(struct vehicle));

    // Sort the linked list
    sortOnPrice(head);

    // Print the sorted list
    printSorted(head);
}

void  removeVehicle(struct vehicle **head , int index) {
    struct vehicle *newVehicle = NULL, *deletedVehicle = NULL, *prevVehicle = NULL;
    prevVehicle =(struct vehicle*) malloc(sizeof(struct vehicle));
    if (*head == NULL) {
        printf("\nThe list is empty!\n"
               "Please add a vehicle!\n");
        return;
    } else {
        newVehicle = *head;
        if (index == 1) {
            deletedVehicle = newVehicle;
            *head = newVehicle->link;
            free(deletedVehicle);
            cntVehicle--;
            return;
        }

        for (int i = 0; i < index - 1; ++i) {
            prevVehicle = newVehicle;
            newVehicle=newVehicle->link;
            if(newVehicle==NULL)
            {
                printf("\nThe vehicle not found\n");
                printf("Please write the correct information!\n");
                return;
            }
        }
        deletedVehicle = newVehicle->link;
        prevVehicle->link = newVehicle->link;
        free(deletedVehicle);
        cntVehicle--;
    }
}

void removeVehicleByPlate(struct vehicle **head, const char plateNumber[]) {
    struct vehicle *newVehicle = NULL, *deletedVehicle = NULL, *prevVehicle = NULL;

    if (*head == NULL) {
        printf("\nThe list is empty!\n"
               "Please add a vehicle!\n");
        return;
    } else {
        newVehicle = *head;


        if (strcmp(newVehicle->plateNum, plateNumber) == 0) {
            *head = newVehicle->link;
            free(newVehicle);
            cntVehicle--;
            printf("\nVehicle with plate number '%s' has been removed.\n", plateNumber);
            return;
        }

        while (newVehicle != NULL && strcmp(newVehicle->plateNum, plateNumber) != 0) {
            prevVehicle = newVehicle;
            newVehicle = newVehicle->link;
        }

        if (newVehicle == NULL) {
            printf("\nThe vehicle was not found with the given plate number %s.\n", plateNumber);
            printf("Please provide correct information!\n");
            return;
        }

        deletedVehicle = newVehicle;
        prevVehicle->link = newVehicle->link;
        free(deletedVehicle);
        cntVehicle--;
        printf("\nVehicle with plate number '%s' has been removed.\n", plateNumber);
    }
}




int cntVehicle,cntReservation,cntClient;


void insertVehicle(struct vehicle **head){
    struct vehicle *newVehicle=NULL,*currVehicle=NULL,*compereVehicle=NULL;
    newVehicle =(struct vehicle*) malloc(sizeof (struct vehicle));
    printf("Enter vehicle plate number: ");
    scanf("%s",newVehicle->plateNum);


    printf("Enter the year the car is produced: ");
    newVehicle->yearProduced = getNumber();

    printf("Enter vehicle car model(s): ");
    scanf("%s",newVehicle->carModel);

    printf("Enter vehicle car fuel type(s): ");
    scanf("%s",newVehicle->fuelType);

    printf("Enter vehicle car consumption: ");
    newVehicle->consumption = getDouble();

    printf("Enter vehicle car number of seats: ");
    newVehicle->noSeats = getNumber();

    printf("Enter vehicle car daily price: ");
    newVehicle->dailyPrice = getDouble();

    newVehicle->nrOfRes = 0;

    for(compereVehicle=*head;compereVehicle!=NULL;compereVehicle=compereVehicle->link)
    {
        if(strcmp(compereVehicle->plateNum,newVehicle->plateNum)==0)
        {
            printf("This plate exist!\n"
                   "Please enter valid input!\n");
            return;
        }
    }

       if(*head==NULL)
       {
           *head = newVehicle;
           newVehicle->link = NULL;
           cntVehicle++;
       } else{
           for(currVehicle=*head;currVehicle->link!=NULL;currVehicle=currVehicle->link){

           }
           currVehicle->link=newVehicle;
           newVehicle->link=NULL;
           cntVehicle++;
       }


}




void modifyInfoVehicleUsingPlateNum(char plateNum[],struct vehicle **head)
{
    struct vehicle *newVehicle=NULL;
    for(newVehicle =*head;newVehicle!=NULL;newVehicle=newVehicle->link)
    {
        if(strcmp(plateNum,newVehicle->plateNum)==0)
        {
            break;
        }

    }
    if (newVehicle==NULL)
    {
        printf("The vehicle not found\n");
        printf("Please write the correct information!");
        return;
    }
    printf("\nPress 1 to modify vehicle year produced\n");
    printf("Press 2 to modify vehicle car model(s)\n");
    printf("Press 3 to modify vehicle fuel type(s)\n");
    printf("Press 4 to modify vehicle consumption\n");
    printf("Press 5 to modify vehicle number of seats\n");
    printf("Press 6 to modify vehicle daily price\n");
    printf("Press 7 to modify all vehicle information\n");
    printf("Enter the information you would like to modify\n");


    int operation = getNumber();
    switch (operation) {
        case 1:{
            printf("Enter the year the car is produced: ");
            newVehicle->yearProduced = getNumber();
        }
            break;
        case 2:{
            printf("Enter vehicle car model(s): ");
            scanf("%s",newVehicle->carModel);
        }
            break;
        case 3:{
            printf("Enter vehicle car fuel type(s): ");
            scanf("%s",newVehicle->fuelType);
        }
            break;
        case 4:
        {
            printf("Enter vehicle car consumption: ");
            newVehicle->consumption = getDouble();
        }
            break;
        case 5:
        {
            printf("Enter vehicle car number of seats: ");
            newVehicle->noSeats = getNumber();
        }
            break;
        case 6: {
            printf("Enter vehicle car daily price: ");
            newVehicle->dailyPrice = getDouble();
        }
            break;
        case 7:
        {
            printf("Enter the year the car is produced: ");
            newVehicle->yearProduced = getNumber();

            printf("Enter vehicle car model(s): ");
            scanf("%s",newVehicle->carModel);

            printf("Enter vehicle car fuel type(s): ");
            scanf("%s",newVehicle->fuelType);

            printf("Enter vehicle car consumption: ");
            newVehicle->consumption = getDouble();

            printf("Enter vehicle car number of seats: ");
            newVehicle->noSeats = getNumber();

            printf("Enter vehicle car daily price: ");
            newVehicle->dailyPrice = getDouble();
        }
        default:
        {
            printf("Invalid input!");
            return;
        }
    }

}

void displayAllReservationExceedingCost(struct reservation *head,double cost)
{
    FILE *file1 = NULL;
    file1 = fopen("C:\\Users\\User\\CLionProjects\\projectProgramming\\rezervationsExceedingXcost","w");
    if(file1==NULL)
    {
        printf("The file doesn't exist!");
        return;
    }
    int i=0;
    for (;head!=NULL;head=head->link)
    {
        if(head->totalPrice>cost)
        {
            fprintf(file1,"%d %d %s %d %.2lf\n",head->reservationID,head->reservationDateInt,
                    head->plateNum,head->clientId,head->totalPrice);
            i++;
        }
    }
    printf("There are %d reservations saved!",i);

}

void displayReservationsAfterXDays(struct reservation *head,int days)
{
    for(int i=1;head!=0;head=head->link)
    {
        if(head->daysPassedReservation>=days)
        {
            printf("\nReservation no: %d\n"
                   "Reservation ID: %d\n"
                   "Reservation Date: %d\n"
                   "Reservation number of days: %d \n"
                   "Reservation client ID: %d\n"
                   "Reservation total price: %.2lf\n\n",i,head->reservationID,head->reservationDate,
                   head->nrDays,head->clientId,head->totalPrice);

        }
        i++;
    }
}




void NumberOfReservationsAvailableAfterDays(struct reservation* head, int days) {
    time_t currTime = time(NULL);
    time_t totalTime = currTime + (days * 24 * 60 * 60);

    int count = 0;
    struct reservation *current = head;
    while (current != NULL) {
        if (current->reservationDate > totalTime) {
            count++;
            printf("\nReservation no: %d\n"
                   "Reservation ID: %d\n"
                   "Reservation number of days: %d \n"
                   "Reservation client ID: %d\n"
                   "Reservation total price: %.2lf\n\n",count,current->reservationID,current->reservationDateInt
                   ,current->clientId,current->totalPrice);
        }
        current = current->link;
    }
    printf("\nThere are %d reservations available after %d days\n",count,days);
}


void connectClientWithReservation(struct client **headClient,struct reservation **newReservation) {
    struct client *newClient = NULL, *prevClient = NULL;
    if (*headClient == NULL) {
        newClient = (struct client *) malloc(sizeof(struct client));
        printf("\nThere are no clients registered!\n");
        printf("Please do so!\n");
        printf("Enter client name: ");
        scanf("%s", newClient->clientName);
        printf("Enter client surname: ");
        scanf("%s", newClient->clientSurname);
        printf("Enter client passport ID: ");
        newClient->passportID = getNumber();
        printf("Enter client state: ");
        scanf("%s", newClient->state);
        printf("Enter client cel number: ");
        newClient->phoneNumber = getNumber();
        newClient->nrReservation = newClient->nrReservation + 1;
        newClient->clientID = (*newReservation)->clientId;
        newClient->nrReservation = 1;
        printf("A new client is added!");

        *headClient = newClient;
        newClient->link = NULL;

    } else {
        for (prevClient = *headClient; prevClient != NULL; prevClient = prevClient->link) {
            if (prevClient->clientID == (*newReservation)->clientId) {
                prevClient->nrReservation++;
                printf("A new reservation is added to the current client!");
                break;
            }
        }
        if (prevClient == NULL) {
            for (prevClient = *headClient; prevClient->link != NULL; prevClient = prevClient->link) {

            }


            newClient = (struct client *) malloc(sizeof(struct client));
            printf("\nThere are no clients registered!\n");
            printf("Please do so!\n");
            printf("Enter client name: ");
            scanf("%s", newClient->clientName);
            printf("Enter client surname: ");
            scanf("%s", newClient->clientSurname);
            printf("Enter client passport ID: ");
            newClient->passportID = getNumber();
            printf("Enter client state: ");
            scanf("%s", newClient->state);
            printf("Enter client cel number: ");
            newClient->phoneNumber = getNumber();
            newClient->nrReservation++;
            newClient->clientID = (*newReservation)->clientId;
            newClient->nrReservation = 1;
            printf("A new client is added!");

            prevClient->link = newClient;
            newClient->link = NULL;
            cntClient++;
        }


    }
}

void connectReservationWithVehicle(struct vehicle **headVehicle,struct reservation **newReservation)
{
    struct vehicle *newVehicle = NULL,*currVehicle=*headVehicle;
    if (*headVehicle == NULL) {
        newVehicle = (struct vehicle *) malloc(sizeof(struct vehicle));
        printf("Enter vehicle plate number: ");
        scanf("%s", newVehicle->plateNum);


        printf("Enter the year the car is produced: ");
        newVehicle->yearProduced = getNumber();

        printf("Enter vehicle car model(s): ");
        scanf("%s", newVehicle->carModel);

        printf("Enter vehicle car fuel type(s): ");
        scanf("%s", newVehicle->fuelType);

        printf("Enter vehicle car consumption: ");
        newVehicle->consumption = getDouble();

        printf("Enter vehicle car number of seats: ");
        newVehicle->noSeats = getNumber();

        printf("Enter vehicle car daily price: ");
        newVehicle->dailyPrice = getDouble();
        newVehicle->nrOfRes=1;

        *headVehicle = newVehicle;
        newVehicle->link = NULL;
        return;
    }
    for (; currVehicle != NULL; currVehicle = (currVehicle)->link) {
        if (strcmp(currVehicle->plateNum, (*newReservation)->plateNum) == 0) {
            printf("\nReservation added to vehicle!\n");
            currVehicle->nrOfRes=currVehicle->nrOfRes+1;
            return;
        }
    }
    printf("\nVehicle not found!\n"
           "Please give correct input!\n");
}



void addReservation(struct reservation **head,struct client **headClient,struct vehicle **headVehicle) {
    struct reservation *newReservation = NULL, *prevReservation = NULL,*compareReservation=NULL;
    newReservation = (struct reservation *) malloc(sizeof(struct reservation));


    newReservation->reservationID = rand()%100;
    printf("Enter reservation number of days: ");
    newReservation->reservationDateInt = getNumber();
    newReservation->reservationDate = time(NULL) + newReservation->reservationDateInt * 24 * 60 * 60;
    printf("Enter the client id: ");
    newReservation->clientId = getNumber();
    printf("Enter the number the plate of vehicle reserved: ");
    scanf("%s", newReservation->plateNum);
    newReservation->daysPassedReservation = newReservation->nrDays;
    printf("Enter the total price od the reservation: ");
    newReservation->totalPrice = getDouble();

    for(compareReservation=*head;compareReservation!=NULL;compareReservation=compareReservation->link)
    {
        if(compareReservation->reservationID==newReservation->reservationID)
        {
            printf("This is a current reservation\n"
                   "Please write valid input!\n");
            return;
        }
    }

    if (*head == NULL) {
        *head = newReservation;
        newReservation->link = NULL;
        cntReservation++;
        printf("The first reservation is added!");
        return;
    }
    for (prevReservation = *head; prevReservation->link != NULL; prevReservation = prevReservation->link) {

    }
    prevReservation->link = newReservation;
    newReservation->link = NULL;
    cntReservation++;
    printf("A new reservation is added!\n");

    connectClientWithReservation(headClient,&newReservation);
    connectReservationWithVehicle(headVehicle,&newReservation);



    }

    void displayClient(struct client *head)
    {
    for(;head!=NULL;head=head->link)
    {
        printf("Client name: %s\n",head->clientName);
        printf("Client surname: %s\n",head->clientSurname);
        printf("Client passport ID: %d\n",head->passportID);
        printf("Client state: %s\n",head->state);
        printf("Client cel number: %d\n",head->phoneNumber);
        printf("Client number of reservation: %d\n\n",head->nrReservation);

    }
    }

void displayAvailableVehiclesCurrently(struct vehicle *head,struct reservation *headReservation){
    if (head == NULL) {
        printf("No vehicles found.\n");
        return;
    }
    int i = 0;
    struct vehicle *newVehicle = head;
    printf("Available Vehicles:\n");
    while (newVehicle != NULL) {
        if(strcmp(newVehicle->plateNum,headReservation->plateNum)==0) {

        } else{
            i++;
            printf("Car %d\n"
                   "Vehicle plate number: %s\n"
                   "Vehicle year produced: %d\n"
                   "Vehicle car model: %s\n"
                   "Vehicle fuel type: %s\n"
                   "Vehicle consumption: %.2lf\n"
                   "Vehicle number of seats: %d\n"
                   "Vehicle number of reservations: %d\n"
                   "Vehicle daily price: %.2lf\n\n",i,newVehicle->plateNum ,
                   newVehicle -> yearProduced, newVehicle->carModel,newVehicle->fuelType,
                   newVehicle->consumption,newVehicle->noSeats ,newVehicle->nrOfRes, newVehicle->dailyPrice);
        }
        newVehicle = newVehicle->link;
        head=head->link;
    }
}
void displayClientsWithMoreThanThreeRentals(struct client *head){
    int check=0;
    if (head == NULL) {
        printf("No client in the list!\n");
    }else{
        while(head!=NULL){
            if(head->nrReservation>=3){
                printf("Name : %s\nSurname : %s\nClient ID : %d\n", head->clientName, head->clientSurname, head->clientID);
                printf("\n");
                check=1;
            }
            head=head->link;
        }
    }
    if(check==0){
        printf("No client have rented more than 3 cars!\n");
        printf("\n");
    }
}

void cancelReservation1(struct reservation **head) {
    struct reservation *current = NULL;
    struct reservation *previous = NULL;

    if (*head == NULL) {
        printf("There are no reservations\n");
        printf("\n");
        return;
    }

    int ID;
    int cnt = 0;
    printf("Enter the ID : ");

    while (cnt == 0) {

        scanf("%d", &ID);
        current = *head;

        while (1) {

            if (current->reservationID == ID) {
                (*head) = current->link;
                free(current);
                cnt++;
                break;
            } else {
                while ((current != NULL) && (current->reservationID != ID)) {

                    previous = current;
                    current = current->link;
                }

                if (current == NULL) {

                    printf("Invalid ID! Enter the correct ID : ");
                    break;
                } else if (current->reservationID == ID) {
                    previous->link = current->link;

                    free(current);
                    cnt++;
                    break;
                }

            }
        }
    }
    printf("\n");
    cntReservation--;
}
void displayList(struct vehicle *head){

    struct vehicle *newVehicle=NULL;
    if(head==NULL){
        printf("The list is empty!");
    }
    int i = 1;
    newVehicle=head;
    while (newVehicle!=NULL){

        printf("Car %d\n"
               "Vehicle plate number: %s\n"
               "Vehicle year produced: %d\n"
               "Vehicle car model: %s\n"
               "Vehicle fuel type: %s\n"
               "Vehicle consumption: %.2lf\n"
               "Vehicle number of seats: %d\n"
               "Vehicle number of reservations: %d\n"
               "Vehicle daily price: %.2lf\n\n",i,newVehicle->plateNum ,
               newVehicle -> yearProduced, newVehicle->carModel,newVehicle->fuelType,
               newVehicle->consumption,newVehicle->noSeats ,newVehicle->nrOfRes, newVehicle->dailyPrice);


        newVehicle=newVehicle->link;
        i++;
    }
}




