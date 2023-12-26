#include<stdio.h>
#include "Car.h"
#include "conio2.h"
int main(){
        int choice;
        addAdmin();
        gotoxy(36,10);  // 36-->Column Number and  10 is Row Number
        textcolor(WHITE);
        printf("WELCOME TO CAR RENTAL SYSTEM");
        textcolor(GREEN);
        gotoxy(31,13);
        printf("* RENT A CAR AND GO WHEREVER YOU NEED *");
        getch();
        while(1){
                 clrscr();
                 textcolor(BROWN);
                 gotoxy(42,2);
                 printf("CAR RANTAL SYSTEM");
                 gotoxy(40,3);
                 printf("=====================");
                 gotoxy(1,8);
                 textcolor(DARKGRAY);
                 for(int i=0; i<102; i++)
                        printf("*");
                 gotoxy(1,18);
                 for(int i=0; i<102; i++)
                        printf("*");
                 gotoxy(42,10);
                 textcolor(YELLOW);
                 printf("1. Admin");
                 gotoxy(42,12);
                 printf("2. Employee");
                 gotoxy(42,14);
                 printf("3. Quit");
                 while(1){
                        gotoxy(42,16);
                        textcolor(WHITE);
                        printf("Enter your choice: ");
                        scanf("%d",&choice);
                        User  *ur;
                        int res ;
                        if(choice==1){
                                  base1:
                                  do{
                                        ur= getInput();
                                        if(ur==NULL)
                                                break;
                                        else
                                                res = checkUserExist(*ur,"admin");
                                  }while(res==0);
                                  if(res==-1)
                                                break;
                                  if(ur==NULL)
                                                break;
                                  if(res==1){
                                        clrscr();
                                        int temp;
                                        while(1){
                                                temp = adminMenu();
                                                if(temp==7)
                                                        goto base1;
                                                switch(temp){
                                                        case 1:
                                                                    clrscr();
                                                                    addEmployees();
                                                                    break;
                                                         case 2:
                                                                    clrscr();
                                                                    addCarDetails();
                                                                    break;
                                                          case 3:
                                                                     clrscr();
                                                                     viewEmployees();
                                                                     break;
                                                          case 4:
                                                                     clrscr();
                                                                     showCarDetails();
                                                                     break;
                                                          case 5:
                                                                      clrscr();
                                                                      int result=deleteEmp();
                                                                      gotoxy(16,12);
                                                                      if(result==0){
                                                                           textcolor(LIGHTRED);
                                                                           printf("Sorry no record of given employee found");
                                                                      }
                                                                      else if(result==1){
                                                                                textcolor(LIGHTGREEN);
                                                                                printf("Record successfully deleted");
                                                                      }
                                                                      else if(result==2 || result==-2){
                                                                                textcolor(LIGHTRED);
                                                                                printf("Name did not change of the file");
                                                                      }
                                                                      gotoxy(40,14);
                                                                      textcolor(LIGHTCYAN);
                                                                      printf("Press any key for go to main menu");
                                                                      getch();
                                                                      break;
                                                          case 6:
                                                                       clrscr();
                                                                       result=deleteCarModel();
                                                                       gotoxy(16,12);
                                                                       if(result==0){
                                                                           textcolor(LIGHTRED);
                                                                           printf("Sorry no record of given Car found");
                                                                       }
                                                                       else if(result==1){
                                                                                textcolor(LIGHTGREEN);
                                                                                printf("Record successfully deleted");
                                                                       }
                                                                       else if(result==2 || result==-2){
                                                                                textcolor(LIGHTRED);
                                                                                printf("Name did not change of the file");
                                                                       }
                                                                       gotoxy(40,14);
                                                                       textcolor(LIGHTCYAN);
                                                                       printf("Press any key for go to main menu");
                                                                       getch();
                                                                       break;
                                                          default:
                                                                        gotoxy(42,20);
                                                                        textcolor(RED);
                                                                        printf("Invalid Choice!");
                                                                        getch();
                                                }
                                        }
                                  }
                                   if(ur==NULL)
                                                break;
                        }
                        else if(choice==2){
                                     base2:
                                  do{
                                        ur= getInput();
                                        if(ur==NULL)
                                                break;
                                        else
                                                res = checkUserExist(*ur,"employee");
                                  }while(res==0);
                                  if(res==-1)
                                                break;
                                  if(ur==NULL)
                                                break;
                                  if(res==1){
                                        clrscr();
                                        int temp;
                                        while(1){
                                                temp = employeeMenu();
                                                if(temp==5)
                                                        goto base2;
                                                switch(temp){
                                                        case 1:

                                                           clrscr();
                                                           int rentresp;
                                                           rentresp=rentCar();
                                                           if(rentresp==-2)
                                                         {
                                                           gotoxy(35,9);
                                                          textcolor(LIGHTRED);
                                                          printf("Sorry! All cars booked. Try later");
                                                          getch();
                                                        }
                                            else if(rentresp==0)
                                            {
                                                gotoxy(27,18);
                                                textcolor(LIGHTRED);
                                                printf("You did not choose any car");
                                                getch();
                                            }


                                                break;
                                                case 2:
                                                        clrscr();
                                                       bookedCarDetails();
                                                        break;
                                                case 3:
                                                        clrscr();
                                                        availCarDetails();
                                                        break;
                                                case 4:
                                                        clrscr();
                                                        shoCarDetails();
                                                        break;
                                                        default:
                                                        gotoxy(42,20);
                                                        textcolor(RED);
                                                        printf("Invalid Choice!");
                                                        getch();
                                                }
                                        }
                                  }
                                   if(ur==NULL)
                                                break;
                        }
                        else if(choice==3){
                                clrscr();
                                gotoxy(42,12);
                                textcolor(GREEN);
                                printf("Thank you for using the App!!");
                                getch();
                                exit(0);
                        }
                        else{
                                gotoxy(42,21);
                                textcolor(RED);
                                printf("Invalid User Type");
                                getch();
                        }
                        gotoxy(42,21);
                        printf("\t\t\t\t");
                        gotoxy(61,16);
                        printf("\t\t\t\t\t\t\t");
                        gotoxy(61,16);
                 }
                 getch();
        }
        return 0;
}
