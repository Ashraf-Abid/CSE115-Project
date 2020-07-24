//Ashraful Kalam Abid_1721464642
//Parvez Ahmmed_1721562042
#include<stdio.h>
#include <windows.h>
#include<stdlib.h>
#include<unistd.h>
void filewrite();
void fileprint();
void cgpa();
void cgpas();
void info();
void filesort();
int start();
void admin();
int unp();
void cgpainfo();
void attendence();
void showatd();
void rstrfactory();
int exists(char *fname);


int main()
{
    FILE *Fp;
    FILE *P;
    FILE *Q;
    FILE *O;
    Fp = fopen("student.txt","a");
    fclose(Fp);
    Q=fopen("attendence.txt","a");
    fclose(Q);
    O=fopen("cgpa.txt","a");
    fclose(O);
    admin();
    system("cls");
    char pass[100],uname[100];
    system("COLOR ");
    //system("COLOR 47");
    FILE *p;
    p=fopen("password.txt","r");
    fscanf(p,"%s%s",uname,pass);
    fclose(p);
    char a[100],b[100];
    int i;
    printf("**************Welcome to NSUSMS****************\n\n");
    for(i=1; i<=47; i++)
    {
        printf("-");
        Sleep(50);
    }
    for (i=0;; i++)
    {

        printf("\n\nEnter Your UserName:");
        scanf("%s",a);
        if (strcmp(a,uname)==0)
        {
            printf("Enter Your Password:");
            scanf("%s",b);
            if (strcmp(b,pass)==0)
            {
                system("cls");
                printf("\nSUCCESFULLY LOGIN\n\n");
                printf("Hi Admin %c",1);
                break;
            }
            else
            {
                printf("\nWRONG PASSWORD...TRY AGAIN\n");
            }
        }
        else printf("\nINVALID TRY AGAIN\n");
    }
    printf("\n\n");
    start();
    return 0;
}
void admin()
{
    system("cls");
    system("COLOR 71");
    int p;
    printf("Installing");
    for (p=0; p<3; p++)
    {
        printf(".");
        Sleep( 1000 );
    }
    printf("\n");
    FILE *q;
    char a[100],b[100];
    int i=0,m=0,n=0,o=0,c;
    if(exists("password.txt")==0)
    {
        printf("**************Welcome to NSUSMS****************\n\n");
        for(i=1; i<=47; i++)
        {
            printf("-");
            Sleep(50);
        }
        printf("\n\nPlease Register\n\n");
        c=1;
    }
    else
    {
        c=2;
    }
    if (c==1)
    {
        printf("First you have to use unique user name and a password which you will always use to access the management\n\n");
        printf("Enter a User Name:");
        scanf("%s",a);
        printf("Enter a Password(might be atleast 1 upper case & 1 lowercase & 1 number):\n");
        for (i=0;; i++)
        {
            scanf("%s",b);
            for(i=0; b[i]; i++)
            {
                if ((b[i]>='A') && (b[i]<='Z'))
                {
                    m++;
                }
                else if ((b[i]>='a') && (b[i]<='z'))
                {
                    n++;
                }
                else if ((b[i]>='0') && (b[i]<='9'))
                {
                    o++;
                }
            }
            {
                if ((m>=1) && (n>=1) && (o>=1))
                {
                    q=fopen("password.txt","a");
                    fprintf(q,"%s %s\n",a,b);
                    fclose(q);
                    printf("Please wait");
                    for (i=0; i<3; i++)
                    {
                        printf(".");
                        Sleep(2000);
                    }
                    system("cls");
                    printf("---------------------\nSuccessfully Registered\n\n\n");
                    Sleep(2000);

                    break;
                }
                else
                {
                    printf("Weak password (might b atleast 1 upper case & 1 lowercase & 1 number)\n");
                    printf("TRY AGAIN\n");
                }
            }
        }
    }
}
int start()
{
    //system("cls");
    system("COLOR 17");
    int marks[100],rollno[100],x[100],n,i,j,roll,c,mark,roll1;
    char name[100][10],nam[50];
    printf("GIVE  A CHOICE--\n");
    printf("   1 TO ENTER STUDENT INFO.\n");
    printf("   2 TO SEE ALL STUDENTs.TXT FILE\n");
    printf("   3 TO KNOW POSITION ON BASIS OF MARKS\n");
    printf("   4 TO FIND SPECIFIC STUDENT INFO\n");
    printf("   5 TO FIND PRESENT GPA\n");
    printf("   6 TO STORE ALL STUDENT SEMISTER WISE GPA\n");
    printf("   7 TO SHOW PER SEMISTER RESULT\n");
    printf("   8 TO STORE THE ATTENDENCE OF THE DAY\n");
    printf("   9 TO SHOW THE ATTENDENCE FILE\n");
    printf("   10 TO CHANGE USER NAME & PASSWORD\n");
    printf("   11 TO DELETE ALL STUDENT DATA FROM FILE\n");
    printf("   12 TO EXIT.....\n");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        filewrite();
        break;
    case 2:
        fileprint();
        break;
    case 3:
        filesort();
        break;
    case 4:
        info();
        break;
    case 5:
        cgpa();
        break;
    case 6:
        cgpas();
        break;
    case 7:
        cgpainfo();
        break;
    case 8:
        attendence();
        break;
    case 9:
        showatd();
        break;
    case 10:
        unp();
        break;
    case 11:
        rstrfactory();
        break;
    case 12:
        printf("\n\n*****BYE*****\n\n");
        return 0;
    default:
        return 0;
    }
}
void filewrite()
{
    system("cls");
    int roll,ch,mark;
    char nam[50],ad[100],bld[100];
    FILE *fp;
    fp = fopen("student.txt","a");
    printf("ENTER ROLL NUMBER, NAME , MARKS ,ADDRESS,and blood group \n");
    ch =1;
    while(ch)
    {
        printf("ENTER ROLL NUMBER:");
        scanf("%d",&roll);
        printf("ENTER NAME:");
        scanf("%s",nam);
        printf("ENTER  CURRENT SEMESTER  AVERAGE MARKS:");
        scanf("%d",&mark);
        printf("ENTER ADDRESS:");
        scanf("%s",ad);
        printf("ENTER BLODD GROUP:");
        scanf("%s",bld);
        fprintf(fp,"%d %s %d %s %s\n",roll,nam,mark,ad,bld);
        printf("\n\n press 1 to continue add more data,0 to stop ");
        scanf("%d",&ch);
        system("cls");

    }
    fclose(fp);
    printf("\n\n");
    start();
}
void fileprint()
{
    system("cls");
    int marks[100],rollno[100],x[100],i;
    char name[100][50],ad[100][100],bld[100][100];
    FILE *fp;
    fp = fopen("student.txt","r");
    i=0;
    printf("ROLLNO       NAME        MARK       ADDRESS     BLOOD\n");
    while(!feof(fp))
    {
        fscanf(fp,"%d %s %d %s %s\n",&rollno[i],name[i],&marks[i],ad[i],bld[i]);
        printf("%d          %s          %d        %s       %s\n",rollno[i],name[i],marks[i],ad[i],bld[i]);
        i=i+1;
    }
    fclose(fp);
    printf("\n\n");
    start();
}
void cgpa()
{
    system("cls");
    int marks[100],rollno[100];
    char name[100][100],ad[100][100],bld[100][100];
    int i=0;
    FILE *fp;
    fp = fopen("student.txt","r");
    while (!feof(fp))
    {
        ++i;
        fscanf(fp,"%d%s%d%s%s",&rollno[i],name[i],&marks[i],ad[i],bld[i]);
        //printf("%d",marks[i]);
        if (marks[i]>92) printf("name %s(id-%d)   cgpa=4\n",name[i],rollno[i]);
        else if ((marks[i]<=92) && (marks[i]>91)) printf("name %s(id-%d)    cgpa=3.7\n",name[i],rollno[i]);
        else if ((marks[i]<=91) && (marks[i]>86)) printf("name %s(id-%d)    cgpa=3.3\n",name[i],rollno[i]);
        else if ((marks[i]<=86) && (marks[i]>80)) printf("name %s(id-%d)    cgpa=2.7\n",name[i],rollno[i]);
        else if ((marks[i]<=80) && (marks[i]>77)) printf("name %s(id-%d)    cgpa=2.3\n",name[i],rollno[i]);
        else if ((marks[i]<=77) && (marks[i]>73)) printf("name %s(id-%d)    cgpa=2.0\n",name[i],rollno[i]);
        else if ((marks[i]<=73) && (marks[i]>69)) printf("name %s(id-%d)    cgpa=1.7\n",name[i],rollno[i]);
        else if ((marks[i]<=69) && (marks[i]>66)) printf("name %s(id-%d)    cgpa=1.3\n",name[i],rollno[i]);
        else if ((marks[i]<=66) && (marks[i]>59)) printf("name %s(id-%d)    cgpa=1.0\n",name[i],rollno[i]);
        else printf("name %s(id-%d)    failure\n",name[i],rollno[i]);
    }
    fclose(fp);
    printf("\n\n");
    start();
}
void info()
{
    system("cls");
    int marks[100],rollno[100];
    char name[100][100],ad[100][100],bld[100][100];
    int roll,i=0;
    FILE *p;
    p=fopen("student.txt","r");
    printf("Enter a roll number:");
    scanf("%d",&roll);
    while (!feof(p))
    {
        fscanf(p,"%d%s%d%s%s",&rollno[i],name[i],&marks[i],ad[i],bld[i]);
        ++i;
    }
    for (i=0;; i++)
    {
        if (rollno[i]==roll)
        {
            printf("ROLLNO       NAME      ADDRESS      BLOOD GROUP\n");
            printf(" %d          %s       %s       %s\n",rollno[i],name[i],ad[i],bld[i]);
            break;
        }
    }
    printf("\n\n");
    fclose(p);
    start();
}
void filesort()
{
    system("cls");
    int marks[100],rollno[100],x[100],i,j,k,c,d;
    char name[100][50],ad[100][100],bld[100][100];
    FILE *fp;
    fp = fopen("student.txt","r");
    i=0;
    while(!feof(fp))
    {
        fscanf(fp,"%d %s %d %s %s\n",&rollno[i],name[i],&marks[i],ad[i],bld[i]);
        //printf(" %d          %s          %d        %s\n",rollno[i],name[i],marks[i],ad[i]);
        i=i+1;
    }
    for (j=0; j<i; j++)
    {
        k=j+1;
        for (k; k<i; k++)
        {
            if(marks[k]>marks[j])
            {
                d=rollno[j];
                c=marks[j];
                marks[j]=marks[k];
                rollno[j]=rollno[k];
                marks[k]=c;
                rollno[k]=d;
            }
        }
    }
    for (j=0; j<i; j++) printf("ID %d -> Obtain %d Position By Getting %d Marks\n",rollno[j],(j+1),marks[j]);
    printf("\n\n");
    fclose(fp);
    start();
}
int unp()
{
    system("cls");
    system("COLOR 71");
    int I=0;
    FILE *p,*q;
    char A[100],B[100],Q[100],W[100];
    p=fopen("password.txt","r");
    fscanf(p,"%s%s",A,B);
    fclose(p);
    printf(" To Change Your Password,Enter Previous Username and Password\n");
    for (I=0;; I++)
    {
        printf("Enter Your Previous username:");
        scanf("%s",Q);
        printf("Enter Your Previous Password:");
        scanf("%s",W);
        if ((strcmp(A,Q)==0) && (strcmp(B,W)==0))
        {
            remove("password.txt");
            system("cls");
            printf("\n\nYOUR PREVIOUS PASSWORD & USER NAME IS DELETED SUCCESSFULLY\n\n");
            break;
        }
        else
        {
            printf("----------------INCORRECT USERNAME OR PASSWORD\n");
            printf("----------------TRY AGAIN\n");
        }
    }
    char a[100],b[100];
    int i=0,m=0,n=0,o=0,c,N;
    printf("**************Admin mood running****************\n");
    printf("\nVERY GOOD CHOICE TO CHANGE PASSWORD OR USERNAME,IF YOU FEEL INSECURE\n\n");
    printf("To change password.First you have use unique username,and a password which you will always use to access the management\n\n\n\n");
    printf("ENTER A USERNAME:");
    scanf("%s",a);
    printf("ENTER A PASSWORD(might b atleast 1 upper case & 1 lowercase & 1 number):\n");
    for (i=0;; i++)
    {
        scanf("%s",b);
        for(i=0; b[i]; i++)
        {
            if ((b[i]>='A') && (b[i]<='Z'))
            {
                m++;
            }
            else if ((b[i]>='a') && (b[i]<='z'))
            {
                n++;
            }
            else if ((b[i]>='0') && (b[i]<='9'))
            {
                o++;
            }
        }
        {
            if ((m>=1) && (n>=1) && (o>=1))
            {
                q=fopen("password.txt","a");
                fprintf(q,"%s %s",a,b);
                fclose(q);
                system("cls");
                printf("\n------------------------------------------------------------------\nSuccessfully changed\n\n\n\nPlease Enter with your new username and password after installing system to enter the managment again.\n\n");
                printf("Want to restart your managment?\n If yes press 1,other wise 2\n");
                scanf("%d",&N);
                if (N==2)
                {
                    system("cls");
                    start();
                    return 0;
                }
                else if (N==1)
                {
                    printf("Restarting");
                    for (p=0; p<3; p++)
                    {
                        printf(".");
                        Sleep( 1000 );
                    }
                    main();
                    return 0;
                }
            }
            else
            {
                printf("Weak password (might b atleast 1 upper case & 1 lowercase & 1 number)\n");
                printf("TRY AGAIN\n");
            }
        }
    }
}
void cgpas()
{
    system("cls");
    float a,b,c;
    char nam[100];
    int roll,ch;
    //int marks[100],rollno[100],x[100],i,j;
    //char name[100][50],ad[100][100],bld[100][100];
    //FILE *fp;
    FILE *p;
    //fp = fopen("student.txt","r");
    p=fopen("cgpa.txt","a");
    ch =1;
    while(ch)
    {
        printf("ENTER ROLL NUMBER:");
        scanf("%d",&roll);
        printf("ENTER NAME:");
        scanf("%s",nam);
        printf("ENTER SPRING SEMESTER RESULT:");
        scanf("%f",&a);
        printf("ENTER SUMMER SEMESTER RESULT:");
        scanf("%f",&b);
        printf("ENTER FALL SEMESTER RESULT:");
        scanf("%f",&c);
        fprintf(p,"%d %s %f %f %f\n",roll,nam,a,b,c);
        printf("\n\n press 1 to continue to add more data,0 to stop ");
        scanf("%d",&ch);
    }
    fclose(p);
    start();
}
void cgpainfo()
{
    system("cls");
    float spring[100],summer[100],fall[100];
    int rollno[100],roll,i=0,j;
    char nam[100][100];
    FILE *p;
    p=fopen("cgpa.txt","r");
    if (p==NULL) printf("N");
    while (!feof(p))
    {
        fscanf(p,"%d%s%f%f%f\n",&rollno[i],nam[i],&spring[i],&summer[i],&fall[i]);
        ++i;
    }
    printf("ENTER ROLL NUMBER:");
    scanf("%d",&roll);
    for (j=0; j<2; j++)
    {
        if (rollno[j]==roll)
        {
            printf("     Spring      Summer     Fall\n");
            printf("%s %f   %f   %f",nam[j],spring[j],summer[j],fall[j]);
            break;

        }
    }
    fclose(p);
    printf("\n\n");
    start();
}
void attendence()
{
    system("cls");
    int day,month,i,n,year;
    printf("BY THIS FEATURE ADMIN CAN STORE THE ATTENDENCE OF 30 STUDENT(a ideal section)\n");
    FILE *p;
    p=fopen("attendence.txt","a");
    if (p==NULL) printf("not");
    printf("ENTER DAY\n");
    scanf("%d",&day);
    printf("ENTER MONTH\n");
    scanf("%d",&month);
    printf("ENTER YEAR\n");
    scanf("%d",&year);
    printf("IF PRESENT ENTER 1\nELSE,NOT PRESENT ENTER 0\n");
    for (i=1; i<=5; i++)
    {
        printf("SERIAL NUMBER -> %d:",i);
        scanf("%d",&n);
        fprintf(p,"%d %d %d %d %d\n",day,month,year,i,n);
    }
    fclose(p);
    printf("\n\n");
    start();
}
void showatd()
{
    system("cls");
    int day,year,month,i=0,n;
    FILE *p;
    p=fopen("attendence.txt","r");
    while(!feof(p))
    {
        fscanf(p,"%d %d %d %d %d\n",&day,&month,&year,&i,&n);
        if (n==1) printf("%d/%d/%d serial number %d was present\n",day,month,year,i);
        else printf("%d/%d/%d serial number %d was not present\n",day,month,year,i);
    }
    fclose(p);
    printf("\n\n");
    start();
}
void rstrfactory()
{
    int p;
    system("cls");
    remove("attendence.txt");
    remove("student.txt");
    remove("cgpa.txt");
    printf("Deleting");
    for (p=0; p<3; p++)
    {
        printf(".");
        Sleep( 1000 );
    }
    printf("\n");
    system("cls");
    printf("All data are deleted from managment\n");
    Sleep( 2000 );
    printf("Enter with your previous password & user name\n");
    printf("Restarting");
    for (p=0; p<3; p++)
    {
        printf(".");
        Sleep( 1000 );
    }
    main();
}
int exists(char *fname)
{
    FILE *file;
    if( access( fname, F_OK ) != -1 )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


