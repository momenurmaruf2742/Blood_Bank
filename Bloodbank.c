#include <windows.h>
#include<stdio.h>
#include<time.h>

void Password();
void mainmenu(void);
void adddonors(void);
void deletedonors(void);
void editrecords(void);
int  getdata();
int  checkid(int);
void returnfunc(void);
void searchdonor(void);
void viewalldonor(void);

COORD coord = {0, 0};
void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

char password[10]={"bloodbank"};
char catagories[][15]={"Male","Female"};
char finddonor;

FILE *fp,*ft;
int s;

struct donors
{
    int id;
    char dname[20];
    char bgroup[20];
    char Address[20];
    int mnumber;
    int age;
    int count;
    int rackno;
    char *cat;
};
struct donors a;


int main()

{
    system("cls");
    system("COLOR 72");
      Password();
      getch();
   return 0;

}
void mainmenu()
{
    system("cls");
    system("COLOR f4");
    int i;
    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Blood Bank Management System");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,5);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Add a new donor ");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Delete a Donor record");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Search for a donor");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 4. View all donor");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Edit a donor record");
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2 6. Close Application");
    gotoxy(20,17);
    printf("------------------------------------------");
    gotoxy(20,19);
    printf("Enter your choice:");
    switch(getch())
    {
        case '1':
        adddonors();
        break;
    case '2':
        deletedonors();
        break;
        case '3':
        searchdonor();
        break;
    case '4':
        viewalldonor();
        break;
        case '5':
        editrecords();
        break;
        case '6':
        {
        system("cls");
        gotoxy(16,3);
        printf("Thanks for using the Program..");
        gotoxy(10,7);
        exit(0);
        }
        default:
        {
        gotoxy(10,23);
        printf("\aWrong Entry!!Please re-entered correct option");
        if(getch())
        mainmenu();
        }

    }
}


void Password(void)
{

   system("cls");
   char ch,pass[10];
   int i=0;
   gotoxy(10,4);
   printf("****************** System Protected by password  ******************");
   gotoxy(15,7);
   printf("Enter Password:");

   while(ch!=13)
   {
	ch=getch();
	if(ch!=13 && ch!=8){
	putch('*');
	pass[i] = ch;
	i++;
	}
   }
   pass[i] = '\0';
   if(strcmp(pass,password)==0)
   {

	gotoxy(15,9);
	printf("Password match");
	gotoxy(17,10);
	printf("Press any key to countinue.....");
	getch();
	mainmenu();
   }
   else
   {
	 gotoxy(15,16);
	 printf("\aWarning!! Incorrect Password");
	 getch();
	 Password();
   }
}


void adddonors(void)    //funtion to add new donor
{
    system("cls");
    int i;
    gotoxy(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT GENDER ");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Male");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Female");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Back to main menu");
    gotoxy(20,13);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,15);
    printf("Enter your choice:");
    scanf("%d",&s);
    if(s==3)

    mainmenu() ;
    system("cls");
    fp=fopen("Donorinfo.dat","ab+");
    if(getdata()==1)
    {
    a.cat=catagories[s-1];
    fseek(fp,0,SEEK_END);
    fwrite(&a,sizeof(a),1,fp);
    fclose(fp);
    gotoxy(21,14);
    printf("The record is sucessfully saved");
    gotoxy(21,15);
    printf("Save any more?(Y / N):");
    if(getch()=='n')
        mainmenu();
    else
        system("cls");
        adddonors();
    }
}
int getdata()
{
    int t;
    gotoxy(20,3);
    printf("Donor Details Form");
    gotoxy(20,4);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,5);
    printf("\xB2");gotoxy(46,5);printf("\xB2");
    gotoxy(20,6);
    printf("\xB2");gotoxy(46,6);printf("\xB2");
    gotoxy(20,7);
    printf("\xB2");gotoxy(46,7);printf("\xB2");
    gotoxy(20,8);
    printf("\xB2");gotoxy(46,8);printf("\xB2");
    gotoxy(20,9);
    printf("\xB2");gotoxy(46,9);printf("\xB2");
    gotoxy(20,10);
    printf("\xB2");gotoxy(46,10);printf("\xB2");
    gotoxy(20,11);
    printf("\xB2");gotoxy(46,11);printf("\xB2");
    gotoxy(20,12);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(21,5);
    printf("Gender:");
    gotoxy(31,5);
    printf("%s",catagories[s-1]);
    gotoxy(21,6);
    printf("Donor ID:\t");
    gotoxy(30,6);
    scanf("%d",&t);
    if(checkid(t) == 0)
    {
        gotoxy(21,13);
        printf("\aThis ID has already a Donor\a");
        getch();
        mainmenu();
        return 0;
    }
    a.id=t;
    gotoxy(21,7);
    printf("Donor Name:");gotoxy(33,7);
    scanf("%s",a.dname);
    gotoxy(21,8);
    printf("Group:");gotoxy(30,8);
    scanf("%s",a.bgroup);
    gotoxy(21,9);
    printf("Address:");gotoxy(31,9);
    scanf("%s",&a.Address);
    gotoxy(21,10);
    printf("Age:");gotoxy(28,10);
    scanf("%d",&a.age);
    gotoxy(21,11);
    printf("Phone: ");gotoxy(30,11);
    scanf("%d",&a.rackno);
    return 1;
}
int checkid(int t)  //check whether the blood type available or not
{
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
    if(a.id==t)
    return 0;  //returns 0 if blood type found
    return 1; //return 1 if it not
}



void deletedonors(void)    //funtion that add books
{
    system("cls");
    int d;
    char another='y';
    while(another=='y')  //infinite loop
    {
    system("cls");
    gotoxy(10,5);
    printf("Enter the Donor ID to delete a record:");
    scanf("%d",&d);
    fp=fopen("Donorinfo.dat","rb+");
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        if(a.id==d)
        {

        gotoxy(10,7);
        printf("The donor record is available");
        gotoxy(10,8);
        printf("Donor name is %s",a.dname);
        gotoxy(10,9);
        printf("Blood Type is %s",a.bgroup);
        finddonor='t';
        }
    }
    if(finddonor!='t')
    {
        gotoxy(10,10);
        printf("No record is found modify the search");
        if(getch())
        mainmenu();
    }
    if(finddonor=='t' )
    {
        gotoxy(10,9);
        printf("Do you want to delete it?(Y/N):");
        if(getch()=='y')
        {
        ft=fopen("test.dat","wb+");  //temporary file for delete
        rewind(fp);
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(a.id!=d)
            {
            fseek(ft,0,SEEK_CUR);
            fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
            }                              //we want to delete
        }
        fclose(ft);
        fclose(fp);
        remove("Donorinfo.dat");
        rename("test.dat","Donorinfo.dat"); //copy all item from temporary file to fp except that
        fp=fopen("Donorinfo.dat","rb+");    //we want to delete
        if(finddonor=='t')
        {
            gotoxy(10,10);
            printf("The record is sucessfully deleted");
            gotoxy(10,11);
            printf("Delete another record?(Y/N)");
        }
        }
    else
    mainmenu();
    fflush(stdin);
    another=getch();
    }
    }
    gotoxy(10,15);
    mainmenu();
}



void editrecords(void)    //funtion to edit a saved record
{

    system("cls");
    int c=0;
    int d,e;
    gotoxy(20,4);
    printf("****Records Editing Section****");
    char another='y';
    while(another=='y')
    {
        system("cls");
        gotoxy(15,6);
        printf("Enter Donor Id to be edited:");
        scanf("%d",&d);
        fp=fopen("Donorinfo.dat","rb+");
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(checkid(d)==0)
            {
                gotoxy(15,7);
                printf("The Donor is availble");
                gotoxy(15,8);
                printf("The Donor ID:%d",a.id);
                gotoxy(15,9);
                printf("Enter new name:");scanf("%s",a.dname);
                gotoxy(15,10);
                printf("Enter new Blood Type:");scanf("%s",a.bgroup);
                gotoxy(15,11);
                printf("Enter new Age:");scanf("%d",&a.age);
                gotoxy(15,12);
                printf("New Mobile Number:");scanf("%d",&a.mnumber);
                gotoxy(15,13);
                printf("Enter new Address:");scanf("%s",&a.Address);
                gotoxy(15,14);
                printf("The record is modified");
                fseek(fp,ftell(fp)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,fp);
                fclose(fp);
                c=1;
            }
            if(c==0)
            {
                gotoxy(15,9);
                printf("No record found");
            }
        }
        gotoxy(15,16);
        printf("Modify another Record?(Y/N)\n");
        fflush(stdin);
        another=getch() ;
    }
        returnfunc();
}



void searchdonor(void)    //funtion to perform a search for donor
{
    system("cls");
    int d;
    printf("*****************************Search a Donor*********************************");
    gotoxy(20,10);
    printf("\xDB\xDB\xDB\xB2 1. Search By ID");
    gotoxy(20,14);
    printf("\xDB\xDB\xDB\xB2 2. Search By Group");
    gotoxy( 15,20);
    printf("Enter Your Choice: ");
    fp=fopen("Donorinfo.dat","rb+"); //open file for reading purpose
    rewind(fp);   //move pointer at the begining of file
    switch(getch())
    {
      case '1':
    {
        system("cls");
        gotoxy(25,4);
        printf("****Search Donors By Id****");
        gotoxy(20,5);
        printf("Enter the Donor id:");
        scanf("%d",&d);
        gotoxy(20,7);
        printf("Searching........");
        while(fread(&a,sizeof(a),1,fp)==1)
        {
        if(a.id==d)
        {
            gotoxy(20,7);
            printf("The Donor is available");
            gotoxy(20,8);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20,9);
            printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2");
            gotoxy(20,10);
            printf("\xB2 Name:%s",a.dname);gotoxy(47,10);printf("\xB2");
            gotoxy(20,11);
            printf("\xB2 Group:%s ",a.bgroup);gotoxy(47,11);printf("\xB2");
            gotoxy(20,12);
            printf("\xB2 Age:%d ",a.age);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
            gotoxy(20,13);
            printf("\xB2 Phone:%d",a.mnumber);gotoxy(47,13);printf("\xB2");
            gotoxy(20,14);
            printf("\xB2 Address:%s ",a.Address);gotoxy(47,14);printf("\xB2");
            gotoxy(20,15);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            finddonor='t';
        }

        }
        if(finddonor!='t')  //checks whether conditiion enters inside loop or not
        {
        gotoxy(20,8);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
        gotoxy(20,10);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(22,9);printf("\aNo Record Found");
        }
        gotoxy(20,17);
        printf("Try another search?(Y/N)");
        if(getch()=='y')
        searchdonor();
        else
        mainmenu();
        break;
    }
    case '2':
    {
        char s[15];
        system("cls");
        gotoxy(25,4);
        printf("****Search Donor By Group****");
        gotoxy(20,5);
        printf("Enter Blood Type:");
        scanf("%s",&s);
        int d=0;
        while(fread(&a,sizeof(a),1,fp)==1)
        {
        if(strcmp(a.bgroup,(s))==0) //checks whether a.bgroup is equal to s or not
        {
            gotoxy(20,7);
            printf("The Group is available");
            gotoxy(20,8);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20,9);
            printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2");
            gotoxy(20,10);
            printf("\xB2 Name:%s",a.dname);gotoxy(47,10);printf("\xB2");
            gotoxy(20,11);
            printf("\xB2 Group:%s",a.bgroup);gotoxy(47,11);printf("\xB2");
            gotoxy(20,12);
            printf("\xB2 Age:%d",a.age);gotoxy(47,12);printf("\xB2");
            gotoxy(20,13);
            printf("\xB2 Phone:%d",a.mnumber);gotoxy(47,13);printf("\xB2");
            gotoxy(20,14);
            printf("\xB2 Address:%s",a.Address);gotoxy(47,14);printf("\xB2");
            gotoxy(20,15);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            d++;
        }

        }
        if(d==0)
        {
        gotoxy(20,8);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
        gotoxy(20,10);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(22,9);printf("\aNo Record Found");
        }
        gotoxy(20,17);
        printf("Try another search?(Y/N)");
        if(getch()=='y')
        searchdonor();
        else
        mainmenu();
        break;
    }
    default :
    getch();
    searchdonor();
    }
    fclose(fp);
}


void viewalldonor(void)    //funtion that add books
{
   int i=0,j;
    system("cls");
    gotoxy(1,1);
    printf("*********************************DONOR LIST*****************************");
    gotoxy(2,2);
    printf(" GENDER     ID    DONOR NAME     BlOOD TYPYE       AGE     PHONE     ADDRESS ");
    j=4;
    fp=fopen("Donorinfo.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
    gotoxy(3,j);
    printf("%s",a.cat);
    gotoxy(16,j);
    printf("%d",a.id);
    gotoxy(22,j);
    printf("%s",a.dname);
    gotoxy(36,j);
    printf("%s",a.bgroup);
    gotoxy(50,j);
    printf("%d",a.age);
    gotoxy(57,j);
    printf("%d",a.mnumber);
    gotoxy(69,j);
    printf("%s",a.Address);
    printf("\n\n");
    j++;
    i=i+a.id;
      }
      gotoxy(3,25);
      printf("Total Donors =%d",i);
      fclose(fp);
      gotoxy(35,25);
      returnfunc();
}
void returnfunc(void)
{
    {
    printf(" Press ENTER to return to main menu");
    }
    a:
    if(getch()==13) //allow only use of enter
    mainmenu();
    else
    goto a;
}




