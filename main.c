#include <stdio.h>
#include"Functions.h"



int main() {
    system("color 3F");
FILE *file1 = fopen("C:\\Users\\User\\CLionProjects\\projectProgramming\\input3.txt","a");
if(file1==NULL){
    printf("Cannot open file!");
    return 1;
}

struct vehicle *head=NULL;
struct reservation *head1=NULL;
struct client *headClient = NULL;
    getDataFileVehicle(&head);
    getDataReservation(&head1);
    getDataFileClient(&headClient);

int option;
    time_t currentTime = time(NULL);
    printf("                        Current time: %s", ctime(&currentTime));

    for (;;) {
        printf("\nEnter 1 to add a new Vehicle \n");
        printf("Enter 2 to display all vehicle info\n");
        printf("Pres 3 to display all vehicles available now\n");
        printf("Enter 4 to remove a vehicle\n");
        printf("Enter 5 to modify vehicle info\n");
        printf("Enter 6 to add a reservation\n");
        printf("Enter 7 to cancel a reservation\n");
        printf("Enter 8 to display all reservations\n");
        printf("Print 9 to save all the reservations exceeding X cost\n");
        printf("Press 10 to display all reservation available after X days\n");
        printf("Press 11 to display 3 most reserved reservations\n");
        printf("Press 12 to display sorted list based on daily price\n");
        printf("Press 13 to display clients with 3 or more reservations\n");
        printf("Press 14 to search by plate number a vehicle\n"
               "Press 15 to display all clients\n");
        printf("Enter the operation you want to do: ");

        option = getNumber();
        switch (option) {
            case 1:insertVehicle(&head);
                break;
            case 2: displayList(head);
                break;
            case 3:
            {
                displayAvailableVehiclesCurrently(head,head1);
            }
                break;
            case 4:
            {
                printf("Enter the plate of the vehicle you want to delete :");
                char plateNumber[20];
                scanf("%s",plateNumber);
                removeVehicleByPlate(&head,plateNumber);
            }
                break;
            case 5:
            {
                printf("Enter the plate number: ");
                char plateNum[20];
                scanf("%s",plateNum);
                modifyInfoVehicleUsingPlateNum(plateNum,&head);
            }
                break;
            case 6:
            {
                addReservation(&head1,&headClient,&head);
            }
                break;
            case 7:{
                cancelReservation1(&head1);
            }
                break;
            case 8:
            {
                displayReservation(head1);
            }
                break;
            case 9:
            {
                printf("Enter the cost you want to display reservations: ");
                double cost = getDouble();
                displayAllReservationExceedingCost(head1,cost);
            }
                break;
            case 10:
            {
                printf("Enter the number of days you want the reservation to be showed: ");
                int daysReservations = getNumber();
               // displayReservationsAfterXDays(head1,daysReservations);
                NumberOfReservationsAvailableAfterDays(head1,daysReservations);
            }
                break;
            case 11:
            {
                sortDisplay(&head);
            }
                break;
            case 12:
            {
                sortDisplayPrice(&head);
            }
                break;
            case 13:
            {
                displayClientsWithMoreThanThreeRentals(headClient);
            }
                break;
            case 14:
            {
                searchByPlate(head);
            }
                break;
            case 15:
                displayClient(headClient);
                break;
            default: {
                printDataFileVehicle(head);
                printf("\n");
               // printDataFileReservation(head1);
                printDataFileAllReservations(head1);
                printDataFileClient(headClient);
                return 1;
            }
            }
        }
    }


