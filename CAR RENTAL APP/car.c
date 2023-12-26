#include<stdio.h>
#include "Car.h"
#include "conio2.h"
#include<string.h>
#include<stdlib.h>
struct carID{
                int id;
                struct carID *next;
};
void addID(struct carID **ptr,int value)
{
	struct carID *p, *temp;
	temp=(struct carID*)malloc(sizeof(struct carID));
	if(temp==NULL)
        {
                printf("Block not created");
                return 0;
        }
	temp->id=value;
	temp->next=NULL;
	if(*ptr==NULL)
        {
                *ptr=temp;
                 return;
        }
        p=*ptr;
        while(p->next != NULL)
                p=p->next;
        p->next=temp;
}
int search(struct carID *ptr,int x)
{
    while(ptr!=NULL)
    {
        if(ptr->id==x)
                return 1;
        ptr=ptr->next;
    }
    return 0;
}
void addAdmin()
{
        FILE *fp;
        fp = fopen("admin.bin","rb");
        if(fp==NULL)
        {
            fp=fopen("admin.bin","wb");
            User u[2]={{"admin","abc","aditya"},{"sanjay","1234","sachin"}};
            fwrite(u,sizeof(u),1,fp);
            getch();
        }
        else
        {
          fclose(fp);
        }

}

User * getInput(){
        clrscr();
        gotoxy(45,1);
        textcolor(YELLOW);
        printf("CAR RENTAL SYSTEM\n");
        textcolor(LIGHTCYAN);
        for(int i=0; i<102; i++){
                printf("%c",247);
        }
        gotoxy(45,5);
        printf("* LOGIN PANNEL *");
        gotoxy(1,7);
        for(int i=0; i<102; i++){
                printf("%c",247);
        }
        gotoxy(1,17);
        for(int i=0; i<102; i++){
                printf("%c",247);
        }
        textcolor(WHITE);
        gotoxy(82,8);
        printf("Press 0 to exit");
        gotoxy(40,9);
        textcolor(LIGHTGRAY);
        printf("Enter user ID: ");
        static User u;
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.name,20,stdin);
        char *pos;
        pos= strchr(u.name, '\n');
        if(pos!=NULL)
           *pos='\0';
        if(strcmp(u.name,"0")==0)
        {
                gotoxy(43,19);
                textcolor(RED);
                printf("Login Cancelled");
                textcolor(YELLOW);
                return NULL;
        }
        textcolor(WHITE);
        gotoxy(40,10);
        printf("Enter Password: ");
        fflush(stdin);
        int i=0;
        while(1){
                u.pwd[i]=getch();  // declaration in line no 54
                if(u.pwd[i]==13)
                        break;
                if(u.pwd[i]==8){  // backspace
                        printf("\b \b");
                        --i;
                        continue;
                }
                printf("*");
                ++i;
        }
        u.pwd[i]='\0';
        return &u;
        getch();
}

int checkUserExist(User user, char *type){
        if(strlen(user.name)==0 || strlen(user.pwd)==0){
                gotoxy(38,19);
                textcolor(RED);
                printf("Both field are mendatory, try again\n");
                printf("%d %d",strlen(user.name),strlen(user.pwd));
                getch();
                return 0;
        }
        FILE *fp;
        User com;
        int found=0;
        if(strcmp(type,"admin")==0){
                fp=fopen("admin.bin","rb");
                while(fread(&com,sizeof(User),1,fp)==1 && fp!=NULL)
                        if(strcmp(com.name , user.name)==0 && strcmp(com.pwd , user.pwd)==0){
                               found=1;
                               break;
                        }
                 if(found==0){
                         gotoxy(38,19);
                         textcolor(RED);
                         printf("Invalid username or password");
                         getch();
                         return 0;
                 }
        }
        else{
                fp=fopen("employee.bin","rb");
                while(fread(&com,sizeof(User),1,fp)==1 && fp!=NULL)
                        if(strcmp(com.name , user.name)==0 && strcmp(com.pwd , user.pwd)==0){
                               found=1;
                               break;
                        }
                 if(found==0){
                         gotoxy(38,19);
                         textcolor(RED);
                         printf("Invalid username or password");
                         getch();
                         return 0;
                 }
        }
        if(fp==NULL){
                gotoxy(38,19);
                textcolor(RED);
                printf("sorry can't open the file");
                getch();
                return -1;
        }
        else{
                 gotoxy(40,19);
                 textcolor(GREEN);
                 printf("Login Successful !");
                 getch();
                 return 1;
        }
}

int adminMenu(){
        clrscr();
        gotoxy(42,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL SYSTEM");
        gotoxy(40,3);
        printf("=====================");
        gotoxy(44,6);
        textcolor(GREEN);
        printf("ADMIN MENU");
        gotoxy(1,7);
        textcolor(LIGHTGREEN);
        for(int i=0; i<102; i++)
              printf("*");
        gotoxy(42,8);
        textcolor(YELLOW);
        printf("1. Add Employee");
        gotoxy(42,9);
        printf("2. Add Car Details");
        gotoxy(42,10);
        printf("3. Show Employee");
        gotoxy(42,11);
        printf("4. Show Car Details");
        gotoxy(42,12);
        printf("5. Delete Employee");
        gotoxy(42,13);
        printf("6. Delete Car Details");
        gotoxy(42,14);
        printf("7. Exit");
        gotoxy(42,16);
        printf("Enter your choice: ");
        int choice;
        scanf("%d",&choice);
        return choice;
}

void addEmployees(){
        FILE *fp ;
        char *pos;
        User newEmp;
        char temp[20];
        char choice;
        fp = fopen("employee.bin","ab+");
        if(fp==NULL){
                gotoxy(47,15);
                textcolor(RED);
                printf("Insufficient memory");
                return;
        }
        fseek(fp,0,SEEK_END);
        int total_emp = ftell(fp)/sizeof(User);
        if(total_emp!=0){
                fseek(fp,-60,SEEK_END);
                fread(temp,sizeof(temp),1,fp);
                pos = strchr(temp,'-');
                total_emp=atoi(pos+1);
        }
        fseek(fp,0,SEEK_END);
        ++total_emp;
        sprintf(newEmp.User,"EMP-%d",total_emp);
        do{
                clrscr();
                gotoxy(42,2);
                textcolor(LIGHTMAGENTA);
                printf("CAR RENTAL APP");
                gotoxy(40,3);
                textcolor(LIGHTCYAN);
                printf("==================");
                gotoxy(1,5);
                textcolor(LIGHTBLUE);
                for(int i=0; i<102; ++i)
                      printf("~");
                gotoxy(38,7);
                textcolor(WHITE);
                printf("*** Add Employee Details ***\n\n");
                textcolor(LIGHTGRAY);
                printf("Employee ID Is: ");
                textcolor(WHITE);
                printf("%s\n",newEmp.User);
                textcolor(LIGHTGRAY);
                printf("Enter Employee Name: ");
                fflush(stdin);
                textcolor(WHITE);
                fgets(newEmp.name,20,stdin);
                pos= strchr(newEmp.name, '\n');
                if(pos!=NULL)
                *pos='\0';
                textcolor(LIGHTGRAY);
                printf("Enter Employee Password: ");
                fflush(stdin);
                int i=0;
                while(1){
                        newEmp.pwd[i]=getch();  // declaration in line no 54
                        if(newEmp.pwd[i]==13)
                                break;
                        if(newEmp.pwd[i]==8){  // backspace
                                printf("\b \b");
                                --i;
                                continue;
                        }
                        printf("*");
                         ++i;
                }
                 newEmp.pwd[i]='\0';
                 if(fwrite(&newEmp,sizeof(newEmp),1,fp)==1){
                        gotoxy(35,14);
                        textcolor(GREEN);
                        printf("Employee Successfully Added");
                 }
                 else{
                        gotoxy(35,14);
                        textcolor(RED);
                        printf("Record not added");
                 }
                 getch();
                 textcolor(YELLOW);
                 printf("\n\nDo you want to add new Employee(Y/N): ");
                 scanf(" %c",&choice);
                 ++total_emp;
                 sprintf(newEmp.User,"EMP-%d",total_emp);
        }while(choice=='Y' || choice=='y');
        fclose(fp);
}

void addCarDetails(){
        FILE *fp ;
        Car newCar;
        char choice;
        fp = fopen("car.bin","ab+");
        if(fp==NULL){
                gotoxy(47,15);
                textcolor(RED);
                printf("Insufficient memory");
                return;
        }
        fseek(fp,0,SEEK_END);
        int total_car= ftell(fp)/sizeof(Car);
        if(total_car!=0){
                fseek(fp,-68,SEEK_END);
                fread(&total_car,sizeof(int),1,fp);
        }
        fseek(fp,0,SEEK_END);
        total_car++;
        do{
                newCar.car_id=total_car;
                clrscr();
                gotoxy(42,2);
                textcolor(LIGHTRED);
                printf("CAR RENTAL APP");
                gotoxy(40,3);
                textcolor(LIGHTCYAN);
                printf("==================");
                gotoxy(1,5);
                textcolor(LIGHTBLUE);
                for(int i=0; i<102; ++i)
                      printf("~");
                gotoxy(38,7);
                textcolor(YELLOW);
                printf("*** Add Car Details ***\n\n");
                textcolor(LIGHTGRAY);
                printf("Car ID IS: ");
                textcolor(WHITE);
                printf("%d\n",newCar.car_id);
                textcolor(LIGHTGRAY);
                printf("Enter Car Model: ");
                fflush(stdin);
                textcolor(WHITE);
                fgets(newCar.car_name,50,stdin);
                char *pos;
                pos= strchr(newCar.car_name, '\n');
                if(pos!=NULL)
                *pos='\0';
                textcolor(LIGHTGRAY);
                printf("Enter Car Capacity: ");
                textcolor(WHITE);
                scanf("%d",&newCar.capacity);
                textcolor(LIGHTGRAY);
                printf("Enter Car Count: ");
                textcolor(WHITE);
                scanf("%d",&newCar.car_count);
                textcolor(LIGHTGRAY);
                printf("Enter Car Price For Per Day: ");
                scanf("%d",&newCar.price);
                fwrite(&newCar,sizeof(newCar),1,fp);
                gotoxy(35,14);
                textcolor(GREEN);
                printf("Car Details Successfully Added\n\n");
                 printf("Do you want to add new Car(Y/N): ");
                 scanf(" %c",&choice);
                 ++total_car;
        }while(choice=='Y' || choice=='y');
        fclose(fp);
}

 void viewEmployees(){
        FILE *fp ;
        User allEmp;
        fp = fopen("employee.bin","rb");
        gotoxy(42,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL APP");
        gotoxy(40,3);
        textcolor(LIGHTCYAN);
        printf("==================");
        gotoxy(37,5);
        textcolor(YELLOW);
        printf("* All Employees Details *\n\n");
        gotoxy(1,6);
        textcolor(LIGHTBLUE);
        for(int i=0; i<102; ++i)
                printf("-");
         if(fp==NULL){
                gotoxy(47,15);
                textcolor(RED);
                printf("Sorry! no Employee added yet");
                getch();
                return;
        }
        gotoxy(1,8);
        for(int i=0; i<102; ++i)
                printf("-");
        gotoxy(2,7);
        textcolor(LIGHTCYAN);
        printf("Employee ID");
        gotoxy(43,7);
        printf("Name");
        gotoxy(80,7);
        printf("Employee Password");
        int i=10;
        while(fread(&allEmp,sizeof(User),1,fp)==1){
                 gotoxy(2,i);
                 textcolor(LIGHTCYAN);
                 printf("%s",allEmp.User);
                 gotoxy(43,i);
                 printf("%s",allEmp.name);
                 gotoxy(83,i);
                 printf("%s",allEmp.pwd);
                 ++i;
        }
        getch();
        fclose(fp);
 }

void showCarDetails(){
        FILE *fp ;
        Car allCar;
        fp = fopen("car.bin","rb");
        gotoxy(42,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL APP");
        gotoxy(40,3);
        textcolor(LIGHTCYAN);
        printf("==================");
        gotoxy(39,5);
        textcolor(YELLOW);
        printf("* ALL CAR DETAILS *\n\n");
        gotoxy(1,6);
        textcolor(LIGHTBLUE);
        for(int i=0; i<102; ++i)
                printf("-");
         if(fp==NULL){
                gotoxy(47,15);
                textcolor(RED);
                printf("Sorry! no Car added yet");
                getch();
                return;
        }
        gotoxy(1,8);
        for(int i=0; i<102; ++i)
                printf("-");
        gotoxy(2,7);
        textcolor(LIGHTCYAN);
        printf("Car ID");
        gotoxy(22,7);
        printf("Car Model");
        gotoxy(44,7);
        printf("Capacity");
        gotoxy(66,7);
        printf("Availlable");
        gotoxy(88,7);
        printf("Price");
        int i=10;
        while(fread(&allCar,sizeof(Car),1,fp)==1){
                 gotoxy(2,i);
                 textcolor(LIGHTCYAN);
                 printf("%d",allCar.car_id);
                 gotoxy(24,i);
                 printf("%s",allCar.car_name);
                 gotoxy(44,i);
                 printf("%d",allCar.capacity);
                 gotoxy(68,i);
                 printf("%d",allCar.car_count);
                 gotoxy(90,i);
                 printf("%d",allCar.price);
                 ++i;
        }
        getch();
        fclose(fp);
 }

 int deleteEmp(){
        FILE *fp1= fopen("employee.bin","rb");
        char empId[10];
        gotoxy(40,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL APP");
        gotoxy(40,3);
        textcolor(LIGHTCYAN);
        printf("==================");
        gotoxy(36,5);
        textcolor(YELLOW);
        printf("* Delete Employee Record *\n\n");
        gotoxy(1,6);
        textcolor(LIGHTBLUE);
        for(int i=0; i<102; ++i)
                printf("%c",247);
         if(fp1==NULL){
                gotoxy(40,8);
                textcolor(LIGHTRED);
                printf("File does not exist");
                return -1;
         }
         FILE *fp2= fopen("temp.bin","wb");
          if(fp2==NULL){
                gotoxy(40,8);
                textcolor(LIGHTRED);
                printf("Sorry! can't create temp file");
                return -1;
         }
         textcolor(LIGHTCYAN);
         printf("\n\n\t\tEnter Employee Id do you want to delete: ");
         textcolor(WHITE);
         scanf(" %s",&empId);
         User user;
         int found=0;
         while(fread(&user,sizeof(User),1,fp1)==1){
                if(strcmp(user.User,empId)!=0)
                        fwrite(&user,sizeof(User),1,fp2);
                else
                        found=1;
         }
         fclose(fp1);
         fclose(fp2);
         if(found==0){
                remove("temp.bin");
         }
         else{
                int result = remove("employee.bin");
                if(result!=0)
                        return -2;
                result = rename("temp.bin","employee.bin");
                if(result!=0)
                        return 2;
         }

         return found;
 }

 int deleteCarModel(){
        FILE *fp1= fopen("car.bin","rb");
        int temp;
        gotoxy(40,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL APP");
        gotoxy(40,3);
        textcolor(LIGHTCYAN);
        printf("==================");
        gotoxy(36,5);
        textcolor(YELLOW);
        printf("* Delete Car Record *\n\n");
        gotoxy(1,6);
        textcolor(LIGHTBLUE);
        for(int i=0; i<102; ++i)
                printf("%c",247);
         if(fp1==NULL){
                gotoxy(40,8);
                textcolor(LIGHTRED);
                printf("File does not exist");
                return -1;
         }
         FILE *fp2= fopen("temp.bin","wb");
          if(fp2==NULL){
                gotoxy(40,8);
                textcolor(LIGHTRED);
                printf("Sorry! can't create temp file");
                return -1;
         }
         textcolor(LIGHTCYAN);
         printf("\n\n\t\tEnter Car Id do you want to delete: ");
         textcolor(WHITE);
         scanf("%d",&temp);
         Car car;
         int found=0;
         while(fread(&car,sizeof(car),1,fp1)==1){
                if(car.car_id!=temp){
                        fwrite(&car,sizeof(car),1,fp2);
                }
                else
                        found=1;
         }
         fclose(fp1);
         fclose(fp2);
         if(found==0){
                remove("temp.bin");
         }
         else{
                int result = remove("car.bin");
                if(result!=0)
                        return -2;
                result = rename("temp.bin","car.bin");
                if(result!=0)
                        return 2;
         }

         return found;
 }
 int employeeMenu(){
        clrscr();
        gotoxy(42,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL SYSTEM");
        gotoxy(40,3);
        printf("=====================");
        gotoxy(44,6);
        textcolor(GREEN);
        printf("Employee MENU");
        gotoxy(1,7);
        textcolor(LIGHTGREEN);
        for(int i=0; i<102; i++)
              printf("*");
        gotoxy(42,8);
        textcolor(YELLOW);
        printf("1. Rent a Car");
        gotoxy(42,9);
        printf("2. Booking Details");
        gotoxy(42,10);
        printf("3. Available Car  Details");
        gotoxy(42,11);
        printf("4. Show All Car Details");
        gotoxy(42,12);
        printf("5. Exit");
        gotoxy(42,14);
        textcolor(LIGHTCYAN);
        printf("Enter your choice: ");
        int choice;
        textcolor(WHITE);
        scanf("%d",&choice);
        return choice;
}


int rentCar()
{
    Customer_Car_Details CC;
    int c,i;
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);

    gotoxy(35,6);
    printf("EMPLOYEE MENU\n");
    for(i=0; i<102; i++)
    {
        printf("*");
    }

    textcolor(YELLOW);
    gotoxy(32,8);
    c=selectCarModel();
    if(c==0||c==-2)
        return c;
    CC.car_id=c;
    clrscr();

    textcolor(LIGHTCYAN);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGRAY);

    gotoxy(35,6);
    printf("EMPLOYEE MENU\n");
    for(i=0; i<102; i++)
    {
        printf("*");
    }
    gotoxy(1,17);
    for(i=0; i<102; i++)
    {
        printf("*");
    }
    textcolor(YELLOW);
    gotoxy(27,9);
    printf("Enter Customer Name:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(CC.cust_name,30,stdin);
    char *pos;
    pos=strchr(CC.cust_name,'\n');
    *pos='\0';
    gotoxy(27,10);
    textcolor(YELLOW);
    printf("Enter Pickup Point:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(CC.pick,30,stdin);
    pos=strchr(CC.pick,'\n');
    *pos='\0';
    gotoxy(27,11);
    textcolor(YELLOW);
    printf("Enter Drop Point:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(CC.drop,30,stdin);
    pos=strchr(CC.drop,'\n');
    *pos='\0';
    gotoxy(27,12);
    textcolor(YELLOW);
    printf("Enter start date (dd/m/yyyy):");
    textcolor(WHITE);
    do
    {
        scanf("%d/%d/%d",&CC.sd.tm_mday,&CC.sd.tm_mon,&CC.sd.tm_year);
        int datevalid=isValidDate(CC.sd);
        if(datevalid==0)
        {
            gotoxy(27,18);
            textcolor(LIGHTRED);
            printf("Wrong Date");
            _getch();
            gotoxy(27,18);
            printf("\t\t");
            gotoxy(56,12);
            printf("\t\t\t");
            gotoxy(56,12);
            textcolor(WHITE);
        }
        else
            break;
    }while(1);
    gotoxy(27,13);
    textcolor(YELLOW);
    printf("Enter end date (dd/m/yyyy):");
    textcolor(WHITE);

    do
    {
        scanf("%d/%d/%d",&CC.ed.tm_mday,&CC.ed.tm_mon,&CC.ed.tm_year);
        int datevalid=isValidDate(CC.ed);
        if(datevalid==0)
        {
            gotoxy(27,18);
            textcolor(LIGHTRED);
            printf("Wrong Date");
            _getch();
            gotoxy(27,18);
            printf("\t\t");
            gotoxy(54,13);
            printf("\t\t\t");
            gotoxy(54,13);
            textcolor(WHITE);
        }
        else
            break;
    }while(1);

    FILE *fp;
    fp=fopen("customer.bin","ab");
    if(fp==NULL)
    {
        gotoxy(27,18);
        textcolor(LIGHTRED);
        printf("Sorry ! File cannot be opened");
        getch();
        gotoxy(27,18);
        printf("\t\t");
        return -1;
    }
    fwrite(&CC,sizeof(Customer_Car_Details),1,fp);
    printf("Booking Done:%d",CC.car_id);
    printf("\nPress any key to continue...");
    getch();
    fclose(fp);
    updateCarCount(c);
    bookedCarDetails();
    return 1;
}



int selectCarModel()
{
    int flag,carcount=0;
    FILE *fp=fopen("car.bin","rb");
    Car C;
    int choice,x=9;

    gotoxy(34,x);
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        if(C.car_count>0)
        {
            printf("%d . %s",C.car_id,C.car_name);
            gotoxy(34,++x);
            ++carcount;
        }
    }
    if(carcount==0)
    {
        return -2;
    }
    gotoxy(34,x+2);
    printf("Enter your choice:");
    while(1)
    {
        flag=0;
        scanf("%d",&choice);
        if(choice==0)
        {
            fclose(fp);
            return 0;
        }
        rewind(fp);
        while(fread(&C,sizeof(C),1,fp)==1)
        {
            if(C.car_id==choice&& C.car_count>0)
            {
                flag=1;
                break;

            }
        }
        if(flag==1)
        {
            fclose(fp);
            return choice;
        }
        else
        {
            gotoxy(37,x+4);
            textcolor(LIGHTRED);
            printf("Wrong Input");
            _getch();
            gotoxy(35,x+4);
            printf("\t\t");
            gotoxy(52,x+2);
            printf("\t");
            gotoxy(52,x+2);
            textcolor(WHITE);

        }
    }

}

int isValidDate(struct tm dt)
{
    if(dt.tm_year>=2021&& dt.tm_year<=2022)
    {
        //check month
        if(dt.tm_mon>=1 && dt.tm_mon<=12)
        {
//check days
            if((dt.tm_mday>=1 && dt.tm_mday<=31) && (dt.tm_mon==1 || dt.tm_mon==3 || dt.tm_mon==5 || dt.tm_mon==7 || dt.tm_mon==8 || dt.tm_mon==10 || dt.tm_mon==12))
               return 1;
            else if((dt.tm_mday>=1 && dt.tm_mday<=30) && (dt.tm_mon==4 || dt.tm_mon==6 || dt.tm_mon==9 || dt.tm_mon==11))
               return 1;
            else if((dt.tm_mday>=1 && dt.tm_mday<=28) && (dt.tm_mon==2))
                return 1;
            else if(dt.tm_mday==29 && dt.tm_mon==2 && (dt.tm_year%400==0 ||(dt.tm_year%4==0 && dt.tm_year%100!=0)))
               return 1;
            else
               return 0;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }

}

void updateCarCount(int c)
{

    FILE *fp=fopen("car.bin","rb+");
    Car C;
    while(fread(&C,sizeof(Car),1,fp)==1)
    {

        if(C.car_id==c)
        {
            fseek(fp,-8,SEEK_CUR);

            int cc_new=C.car_count-1;
            fwrite(&cc_new,sizeof(cc_new),1,fp);
            fseek(fp,-4,SEEK_CUR);
            _getch();
       }

    }
    fclose(fp);
}


void bookedCarDetails()
{
    clrscr();
    FILE *fp=fopen("customer.bin","rb");
    Customer_Car_Details CC;
    int i;
    textcolor(YELLOW);
    gotoxy(44
           ,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1; i<=102; i++)
        printf("%c",247);
    gotoxy(43,5);
    textcolor(YELLOW);
    printf("* BOOKED CAR DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1; i<102; i++)
        printf("%c",247);
    gotoxy(1,8);
    printf("Model\t\t    Cust Name\t\t  Pick Up\t\t   Drop\t\t S_Date\t   E_Date");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    for(i=1; i<102; i++)
        printf("%c",247);
    int x=10;
    textcolor(YELLOW);

    while(fread(&CC,sizeof(Customer_Car_Details),1,fp)==1)
    {
        gotoxy(1,x);
        printf("%s",getCarName(CC.car_id));
        gotoxy(19,x);
        printf("%s",CC.cust_name);
        gotoxy(38,x);
        printf("%s",CC.pick);
        gotoxy(62,x);
        printf("%s",CC.drop);
        gotoxy(78,x);
        printf("%d-%d-%d",CC.sd.tm_mday,CC.sd.tm_mon,CC.sd.tm_year);
        gotoxy(92,x);
        printf("%d-%d-%d",CC.ed.tm_mday,CC.ed.tm_mon,CC.ed.tm_year);
        x++;


    }
    fclose(fp);
    _getch();

}

char * getCarName(int car_id)
{
    FILE *fp=fopen("car.bin","rb");
    static Car C;
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        if(C.car_id==car_id)
        {
             break;
        }
    }
    fclose(fp);
    return C.car_name;

}
void availCarDetails()
{
    FILE *fp=fopen("car.bin","rb");
    Car c;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("* CAR RENTAL SYSTEM *\n");
    for( i=1; i<=102; i++)
    {
        printf("%c",247);
    }

    gotoxy(32,5);
    printf("*** AVAILABLE CAR DETAILS ***");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
     for( i=1; i<=102; i++)
    {
        printf("%c",247);
    }

    if(fp==NULL)
    {
        gotoxy(32,8);
        textcolor(RED);
        printf("sorry! file cannot opened");
        getch();
        return;
    }

    gotoxy(1,8);
    textcolor(LIGHTCYAN);
    printf("Car Id \t\t Model\t\t Capacity \t\t Available \t\t Price/Day");
    gotoxy(1,9);
     for(i=1; i<=102; i++)
    {
        printf("%c",247);
    }

    textcolor(WHITE);
    while(fread(&c,sizeof(c),1,fp)==1)
    {
        if(c.car_count>0)
        {
            gotoxy(2,10);
            printf("%d",c.car_id);
            gotoxy(18,10);
            printf("%s",c.car_name);
            gotoxy(35,10);
            printf("%d",c.capacity);
            gotoxy(62,10);
            printf("%d",c.car_count);
            gotoxy(82,10);
            printf("%d",c.price);
            getch();

        }
    }

    fclose(fp);
}

void shoCarDetails(){
        FILE *fp ;
        Car allCar;
        fp = fopen("car.bin","rb");
        gotoxy(42,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL APP");
        gotoxy(40,3);
        textcolor(LIGHTCYAN);
        printf("==================");
        gotoxy(39,5);
        textcolor(YELLOW);
        printf("* ALL CAR DETAILS *\n\n");
        gotoxy(1,6);
        textcolor(LIGHTBLUE);
        for(int i=0; i<102; ++i)
                printf("-");
         if(fp==NULL){
                gotoxy(47,15);
                textcolor(RED);
                printf("Sorry! no Car added yet");
                getch();
                return;
        }
        gotoxy(1,8);
        for(int i=0; i<102; ++i)
                printf("-");
        gotoxy(2,7);
        textcolor(LIGHTCYAN);
        printf("Car ID");
        gotoxy(22,7);
        printf("Car Model");
        gotoxy(44,7);
        printf("Capacity");
        gotoxy(66,7);
        printf("Availlable");
        gotoxy(88,7);
        printf("Price");
        int i=10;
        while(fread(&allCar,sizeof(Car),1,fp)==1)
            {
                 gotoxy(2,i);
                 textcolor(LIGHTCYAN);
                 printf("%d",allCar.car_id);
                 gotoxy(24,i);
                 printf("%s",allCar.car_name);
                 gotoxy(44,i);
                 printf("%d",allCar.capacity);
                 gotoxy(68,i);
                 printf("%d",allCar.car_count);
                 gotoxy(90,i);
                 printf("%d",allCar.price);
                 ++i;
        }
        getch();
        fclose(fp);
 }














