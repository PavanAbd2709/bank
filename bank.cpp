#include <iostream>
#include <fstream>
#include <random>
#include<stdio.h>
#include <windows.h>
#include <conio.h>  
#include <direct.h>
#include <chrono>
#include <thread>
#include <ctime>

void gotoxy(int x, int y)
{
  static HANDLE h = nullptr;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
  SetConsoleCursorPosition(h,c);
}


void clrscr() {
    system("cls");  
}
void delay(unsigned int milliseconds) { 
    Sleep(milliseconds);
}
void setColor(int text, int background) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | background << 4);
}

class shape
{  public:
	    void line_hor(int, int, int, char);
	    void line_ver(int, int, int, char);
	    void box(int,int,int,int,char);
};

class control
{
  public:
	   void main_menu(void);
	   void help(void);
  private:
	   void edit_menu(void);
};


class initial
{
   public:
	    void add_to_file(int,char t_name[30],char t_address[60],float);
	    void display_list(void);
	    void delete_account(int);
	    void update_balance(int,float);
	    void modify(void);
	    int last_accno(void);
	    int found_account(int);
	    char* return_name(int t_accno);
	    char* return_address(int t_accno);
	    float give_balance(int);
	    int recordno(int);
	    void display(int);
   private:
	    void modify_account(int,char t_name[30],char t_address[60]);
	    void box_for_list(void);
 
	    int accno;
	    char name[30];
      char address[60];
	    float balance;
};
 
class account
{
  public:
	   void new_account(void);
	   void close_account(void);
	   void display_account(void);
	   void transaction(void);
	   void clear(int,int);
  private:
	   void add_to_file(int,int,int,int,char,char t_type[10],float,float,float);
	   void delete_account(int);
	   int no_of_days(int,int,int,int,int,int);
	   float calculate_interest(int,float);
	   void display(int);
	   void box_for_display(int);

	   int accno;
	   char type[10];  //Cheque or Cash
	   int dd,mm,yy;  //Date
	   char tran ;  // Deposit or withdrawl
	   float interest,amount,balance;
};


void shape::line_hor(int column1, int column2, int row, char c) {
    for (int col = column1; col <= column2; ++col) {
        gotoxy(col,row);
        std::cout << c;
    }
}


void shape::line_ver(int row1, int row2, int column, char c) {
    for (int row = row1; row <= row2; ++row) {
        gotoxy(column, row);
        std::cout << c;
    }
}


void shape::box(int column1, int row1, int column2, int row2, char c) {
    char ch = 218;
    char c1 = c, c2 = c, c3 = c, c4 = c;
    char l1 = c, l2 = c;

    if (c == ch) {
        c1 = 218;
        c2 = 191;
        c3 = 192;
        c4 = 217;
        l1 = 196;
        l2 = 179;
    }

    gotoxy(column1, row1);
    std::cout << c1;
    gotoxy(column2, row1);
    std::cout << c2;
    gotoxy(column1, row2);
    std::cout << c3;
    gotoxy(column2, row2);
    std::cout << c4;
    column1++;
    column2--;

    line_hor(column1, column2, row1, l1);
    line_hor(column1, column2, row2, l1);
    column1--;
    column2++;

    row1++;
    row2--;

    line_ver(row1, row2, column1, l2);
    line_ver(row1, row2, column2, l2);
}


void control::main_menu(void)
{
char ch;
while (1)
      {
	clrscr();
	shape s;
	s.box(10,5,71,21,219);
	s.box(9,4,72,22,218);
	setColor(11, 0); // Light cyan text on black background
	gotoxy(32,7);
	printf(" B A N K I N G ");
	gotoxy(35,9);
	printf(" OPTIONS ");
	setColor(9, 0); // Light blue text on black background
	gotoxy(30,11);
	std::cout<<"1: SEE ACCOUNT ";
	gotoxy(30,12);
	std::cout<<"2: LIST OF ACCOUNTS ";
	gotoxy(30,13);
	std::cout<<"3: TRANSACTIONS ";
	gotoxy(30,14);
	std::cout<<"4: OPEN NEW ACCOUNT ";
	gotoxy(30,15);
	std::cout<<"5: EDIT ACCOUNTS ";
	gotoxy(30,16);
	std::cout<<"6: HELP ";
	gotoxy(30,17);
	std::cout<<"0: QUIT ";
	gotoxy(30,19);
	std::cout<<" ENTER YOUR CHOICE:";
	ch=getche();
	if(ch==27)
	  break;
	else
	    if(ch=='1')
	      {
	      account a;
	      a.display_account();
	      }
	else
	    if(ch=='2')
	    {
	    initial ini;
	    ini.display_list();
	    }
	else
	    if(ch=='3')
	    {
	    account a ;
	    a.transaction();
	    }
	else
	    if(ch=='4')
	    {
	    account a;
	    a.new_account();
	    }
	else
	    if(ch=='5')
	    edit_menu();
	else
	    if(ch=='6')
	    help();
	else
	    if(ch=='0')
	    break;
      }
	for(int i=25;i>=1;i--)
	{
	delay(2000);
	gotoxy(1,i); 
    std::cout << "\033[2J\033[1;1H";
	}
}

void control::edit_menu(void)
{
char ch;
while (1)
      {
	clrscr();
	shape s;
	s.box(10,5,71,21,219);
	s.box(9,4,72,22,218);
	setColor(9, 0); // Light blue text on black background
	gotoxy(34,10);
	printf(" EDIT MENU");
	setColor(9, 0); // Light blue text on black background
	gotoxy(31,12);
	std::cout<<"1: MODIFY ACCOUNT :";
	gotoxy(31,13);
	std::cout<<"2: CLOSE ACCOUNT ";
	gotoxy(31,14);
	std::cout<<"0: QUIT ";
	gotoxy(31,16);
	std::cout<<"ENTER YOUR CHOICE: ";
	ch=getche();
	if(ch==27)
	  break;
	else
	if(ch=='1')
	{
	initial ini;
	ini.modify();
	break;
	}
	else
	if(ch=='2')
	{
	account a;
	a.close_account();
	break;
	}
	else
	if(ch=='0')
	break;
      }
}


 void control::help(void)
{
clrscr();
shape s;
s.box(2,1,79,25,218);
s.box(25,2,54,4,219);
setColor(11, 0); // Light cyan text on black background
gotoxy(27,3);
printf("WELCOME TO THE PROJECT BANKING ");
setColor(9, 0);
delay(1000);
gotoxy(10,6);
std::cout<<"IN THIS PROJECT YOU CAN KEEP RECORD OF DAILY BANKING ";
delay(1000);
gotoxy(10,7);
std::cout<<" TRANSACTIONS.		";
delay(1000);
gotoxy(10,9);
std::cout<<" THIS PROGRAMME IS CAPABLE OF HOLDING ANY NO. OF ACCOUNTS ";
delay(1000);
gotoxy(10,11);
std::cout<<" # IN FIRST OPTION YOU CAN SEE ACCOUNT OF A PARTICULAR ";
delay(1000);
gotoxy(10,12);
std::cout<<" PERSON BY GIVING SIMPLY ACCOUNT NO. OF THAT PERSON";
delay(1000);
gotoxy(10,14);
std::cout<<"# IN SECOND OPTION YOUN CAN SEE THE LIST OF ALL ACCOUNTS. ";
delay(1000);
gotoxy(10,16);
std::cout<<"# THROUGH THIRD OPTION YOU CAN DO BANKING TRANSACTIONS ";
delay(1000);
gotoxy(10,17);
std::cout<<" ( DEPOSIT / WITHDRAW )";
delay(1000);
gotoxy(10,19);
std::cout<<"# IN FOURTH OPTION YOU CAN OPEN NEW ACCOUNT. ";
delay(1000);
gotoxy(10,20);
std::cout<<" NOTE: OPENING AMOUNT SHOULD NOT LESS THAN Rs.500/-. ";
delay(1000);
gotoxy(10,22);
std::cout<<"# IN THE FIFTH OPTION YOU CAN MODIFY OR DELETE ANY ACCOUNT. ";
delay(1000);
gotoxy(10,24);
std::cout<<"# AND LAST OPTION IS QUIT (EXIT TO DOS).";
delay(1000);
setColor(11, 0); // Light cyan text on black background
gotoxy(26,25);
printf(" PRESS ANY KEY TO CONTINUE ");
setColor(9, 0); 
gotoxy(25,2);
getch();
for(int i=25;i>=1;i--)
   {
   delay(20);
   gotoxy(1,i);
   std::cout << "\033[2J\033[1;1H";
   }
}
 
 
int initial::last_accno(void)
{
    std::fstream file;
    file.open("INITIAL.DAT",std::ios::in);  // Opening file for reading

    if (!file) {
       std::cerr << "Error opening file!";
        return -1;  // Return an error value indicating failure
    }

    file.seekg(0, std::ios::beg);  // Seek to the beginning of the file

    int count = 0;
    while (file.read(reinterpret_cast<char*>(this), sizeof(initial))) {
        count = accno;  // Assuming accno is a member variable of initial
    }

    file.close();  // Close the file

    return count;  // Return the last accno read from the file
}

int initial::recordno(int t_accno)
{
    std::fstream file;
    file.open("INITIAL.DAT",std::ios::in);
    file.seekg(0,std::ios::beg);
    int count=0;
    while (file.read(reinterpret_cast<char*>(this), sizeof(initial)))
    {
    count++;
    if(t_accno==accno)
    {
           break;
    }
    }
    file.close();
    return count;
}


void initial::display(int t_accno)
{
   shape s;
   s.box(8,7,73,11,219);
   std::fstream file;
   file.open("INITIAL.DAT",std::ios::in);
   file.seekg(0,std::ios::beg);
   while(file.read(reinterpret_cast<char*>(this),sizeof(initial)))
    {
      if(t_accno==accno)
      {
	gotoxy(8,5);
	std::cout<<"ACCOUNT NO.  :"<<accno;
	gotoxy(10,8);
	std::cout<<"NAME         :"<<name;
	gotoxy(10,9);
	std::cout<<"ADDRERSS     :"<<address;
	gotoxy(10,10);
	std::cout<<"BALANCE      :"<<balance;
	break;
      }
    }
    file.close();
}
 
char* initial::return_name(int t_accno) {
    std::fstream file;
    file.open("INITIAL.DAT", std::ios::in);
    file.seekg(0, std::ios::beg);
    char* t_name = nullptr; // Initialize pointer to null

    while (file.read(reinterpret_cast<char*>(this), sizeof(initial))) {
        if (accno == t_accno) {
            t_name = new char[30]; // Allocate memory on the heap
            strcpy(t_name, name);
            break;
        }
    }
    file.close();
    return t_name; // Return pointer to the allocated memory
}
 char* initial::return_address(int t_accno) {
    std::fstream file;
    file.open("INITIAL.DAT", std::ios::in);
    file.seekg(0, std::ios::beg);
    char* t_address = nullptr; // Initialize pointer to null

    while (file.read(reinterpret_cast<char*>(this), sizeof(initial))) {
        if (accno == t_accno) {
            t_address = new char[60]; // Allocate memory on the heap
            strcpy(t_address, address);
            break;
        }
    }
    file.close();
    return t_address; // Return pointer to the allocated memory
}
 
 float initial::give_balance(int t_accno)
{
  std::fstream file;
  file.open("INITIAL.DAT",std::ios::in);
  file.seekg(0,std::ios::beg);
  float t_balance;
  while(file.read(reinterpret_cast<char*>(this), sizeof(initial)))
      {
       if(accno==t_accno)
	 {
	 t_balance=balance;
	 break;
	 }
       }
  file.close();
  return t_balance;
}

int initial::found_account(int t_accno)
{
  std::fstream file;
  file.open("INITIAL.DAT",std::ios::in);
  file.seekg(0,std::ios::beg);
  int found=0;
  while(file.read(reinterpret_cast<char*>(this), sizeof(initial)))
      {
      if (accno==t_accno)
	 {
	 found=1;
	 break;
	 }
      }
  file.close();
  return found;
}

void initial::box_for_list()
{
  shape s;
  s.box(2,1,79,25,218);
  s.line_hor(3,78,3,196);
  s.line_hor(3,78,5,196);
  s.line_hor(3,78,23,196);
  setColor(11, 0);
  gotoxy(3,4);
  for(int i=1;i<=76;i++)
  printf("	");
  setColor(11, 0);
  gotoxy(4,4);
  printf("ACCOUNT NO.	       NAME OF PERSON	       BALANCE");
  setColor(11, 0);
  int d1,m1,y1;
    
     // Get current time as time_point
    auto now = std::chrono::system_clock::now();
    // Convert to time_t for std::tm
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    // Convert to local time
    std::tm local_tm = *std::localtime(&now_time_t);
    
    // Extract day, month, and year
    d1= local_tm.tm_mday;
    m1= local_tm.tm_mon + 1; // tm_mon is 0-based
    y1= local_tm.tm_year + 1900; // tm_year is years since 1900
  gotoxy(4,2);
  std::cout<<"DATE: "<<d1<<"/"<<m1<<"/"<<y1;
}

void initial::display_list(void)
{
  clrscr();
  box_for_list();
  int row=6,flag;
  std::fstream file;
  file.open("INITIAL.DAT", std::ios::in);
  while (file.read(reinterpret_cast<char*>(this), sizeof(initial)))
      {
      flag=0;
      delay(10);
      gotoxy(7,row);
      std::cout<<accno;
      gotoxy(25,row);
      std::cout<<name;
      gotoxy(57,row);
      std::cout<<balance;
      row++;
      if(row==23)
	{
	  flag=1;
	  row=6;
	  gotoxy(4,24);
	  std::cout<<"PRESS ANY KEY TO CONTINUE...";
	  getch();
	  clrscr();
	  box_for_list();
	}
      }
  file.close();
  (!flag);
  {
  gotoxy(4,24);
  std::cout<<"PRESS ANY KEY TO CONTINUE...";
  getch();
  }
}
 void initial::add_to_file(int t_accno,char t_name[30],char t_address[60], float t_balance)
{
  accno=t_accno;
  strcpy(name,t_name);
  strcpy(address,t_address);
  balance=t_balance;
  std::fstream file;
  file.open("INITIAL.DAT",std::ios::out | std::ios::app);
  file.write(reinterpret_cast<char*>(this), sizeof(initial));
  file.close();
}
 void initial::delete_account(int t_accno)
{
  std::fstream file;
  file.open("INITIAL.DAT",std::ios::in);
  std::fstream temp;
  temp.open("temp.dat",std::ios::out);
  file.seekg(0,std::ios::beg);
  while(!file.eof())
      {
	file.read(reinterpret_cast<char*>(this),sizeof(initial));
	if(file.eof())
	break;
	if(accno!=t_accno)
	temp.write(reinterpret_cast<char*>(this),sizeof(initial));
      }
  file.close();
  temp.close();
  file.open("INITIAL.DAT",std::ios::out);
  temp.open("temp.dat", std::ios::in);
  temp.seekg(0,std::ios::beg);
  while(!temp.eof() )
     {
       temp.read(reinterpret_cast<char*>(this),sizeof(initial));
       if(temp.eof())
	  break;
       file.write(reinterpret_cast<char*>(this),sizeof(initial));
     }
  file.close();
  temp.close();
}

void initial::update_balance(int t_accno, float t_balance)
{
  int recno;
  recno=recordno(t_accno);
  std::fstream file;
  file.open("INITIAL.DAT",std::ios::out | std::ios::ate);
  balance=t_balance;
  int location;
  location=(recno-1) * sizeof(initial);
  file.seekp(location);
  file.write(reinterpret_cast<char*>(this), sizeof(initial));
  file.close();
}

void initial::modify_account(int t_accno,char t_name[30],char t_address[60])
{
  int recno;
  recno=recordno(t_accno);
  std::fstream file;
  file.open("INITIAL.DAT", std::ios::out | std::ios::ate);
  strcpy(name, t_name);
  strcpy(address,t_address);
  int location;
  location=(recno-1) * sizeof(initial);
  file.seekp(location);
  file.write(reinterpret_cast<char*>(this), sizeof(initial));
  file.close();
}
 
void initial::modify(void)
{
   clrscr();
   char t_acc[10];
   int t, t_accno;
   gotoxy(71,1);
   std::cout<<"&lt;0>=EXIT";
   gotoxy(5,5);
   std::cout<<"ENTER THE ACCOUNT NO.";
   gets(t_acc);
   t=atoi(t_acc);
   t_accno=t;
   if(t_accno==0)
       return;
   clrscr();
   if(!found_account(t_accno))
   {
     gotoxy(5,5);
     std::cout<<"\7ACCOUNT NOT FOUND";
     getch();
     return;
   }
   shape s;
   s.box(2,2,79,24,218);
   s.line_hor(3,78,4,196);
   s.line_hor(3,78,22,196);
   gotoxy(71,1);
   std::cout<<"&lt;0>=EXIT";
   setColor(11, 0);
   gotoxy(3,3);
   for(int i=1;i<=76;i++) {
   printf("	");
   }
   setColor(11, 0);
   setColor(9, 0);
   setColor(11, 0);
   gotoxy(30,3);
   printf("MODIFY ACCOUNT SCREEN");
   setColor(9, 0);
   int d1,m1,y1;
    
     // Get current time as time_point
    auto now = std::chrono::system_clock::now();
    // Convert to time_t for std::tm
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    // Convert to local time
    std::tm local_tm = *std::localtime(&now_time_t);
    
    // Extract day, month, and year
    d1 = local_tm.tm_mday;
    m1 = local_tm.tm_mon + 1; // tm_mon is 0-based
    y1 = local_tm.tm_year + 1900; // tm_year is years since 1900
   gotoxy(62,5);
   std::cout<<"DATE:"<<d1<<"/"<<m1<<"/"<<y1;
   char ch;
   display(t_accno);
   account a;
   do
   {
     a.clear(5,13);
     gotoxy(5,13);
     std::cout<<"MODIFY THIS ACCOUNT(Y/N):";
     ch=getche();
     if(ch=='0')
	   return;
     ch=toupper(ch);
   }while(ch!='N' && ch!='Y');
   if(ch=='N')
      return;
   int modified=0,valid;
   char t_name[30], t_address[60];
   gotoxy(5,15);
   std::cout<<"NAME   :";
   gotoxy(5,16);
   std::cout<<"ADDRESS  :";
   do
   {
     a.clear(15,15);
     a.clear(5,23);
     gotoxy(5,23);
     std::cout<<"ENTER NAME OR PRESS <ENTER> FOR NO CHANGE";
     valid=1;
     gotoxy(15,15);
     gets(t_name);
     strupr(t_name);
     if(t_name[0]=='0')
	  return;
     if(strlen(t_name)>25)
     {
	valid=0;
	gotoxy(5,23);
	printf("\7NAME SHOULD NOT GREATER THAN 25");
	getch();
     }
   }while(!valid);
   if(strlen(t_name)>0)
       modified=1;
   do
   {
      a.clear(15,16);
      a.clear(5,23);
      gotoxy(5,23);
      std::cout<<"ENTER ADDRESS OR PRESS <ENTER> FOR NO CHANGE";
      valid=1;
      gotoxy(15,16);
      gets(t_address);
      strupr(t_address);
      if(t_address[0]=='0')
	   return;
      if(strlen(t_address)>55)
      {
	valid=0;
	gotoxy(5,23);
	printf("\7SHOULD NOT BLANK OR GREATER THAN 55");
	getch();
      }
   }while(!valid);
   if(strlen(t_address)>0)
      modified=1;
   if(!modified)
       return;
   a.clear(5,23);
   do
   {
     a.clear(5,18);
     gotoxy(5,18);
     std::cout<<"DO YOU WANT TO SAVE CHANGES  (Y/N):";
     ch=getche();
     if(ch=='0')
	return;
     ch=toupper(ch);
   }while(ch!='N' && ch!='Y');
   if(ch=='N')
     return;
   modify_account(t_accno,t_name,t_address);
   gotoxy(5,21);
   std::cout<<"\7RECORD MODIFIED";
   gotoxy(5,23);
   std::cout<<"PRESS ANY KEY TO CONTINUE...";
   getch();
}
void account::clear(int col, int row)
{
   for(int i=col;i<=78;i++)
      {
	gotoxy(i,row);
	std::cout<<"	      ";
      }
}

void account::add_to_file(int t_accno,int d1,int m1, int y1,
			  char t_tran,char t_type[10],float t_interest,
			  float t_amount, float t_balance)
{
   std::fstream file;
   file.open("BANKING.DAT",std::ios::app);
   accno=t_accno;
   dd=d1;
   mm=m1;
   yy=y1;
   tran=t_tran;
   strcpy(type,t_type);
   interest=t_interest;
   amount=t_amount;
   balance=t_balance;
   file.write(reinterpret_cast<char*>(this),sizeof(account));
   file.close();
}

 
void account::delete_account(int t_accno)
{
    std::fstream file;
    file.open("BANKING.DAT", std::ios::in);
    std::fstream temp;
    temp.open("temp.dat",std::ios::out);
    file.seekg(0,std::ios::beg);
    while(!file.eof() )
    {
      file.read(reinterpret_cast<char*>(this),sizeof(account));
      if(file.eof())
	  break;
      if(accno!= t_accno)
	   temp.write(reinterpret_cast<char*>(this),sizeof(account));
    }
    file.close();
    temp.close();
    file.open("BANKING.DAT",std::ios::out);
    temp.open("temp.dat",std::ios::in);
    temp.seekg(0,std::ios::beg);
    while(!temp.eof())
    {
      temp.read(reinterpret_cast<char*>(this),sizeof(account));
      if(temp.eof())
	  break;
      file.write(reinterpret_cast<char*>(this), sizeof(account));
    }
    file.close();
    temp.close();
}
void account::new_account(void)
{
   char ch;
   int i,valid;
   clrscr();
   initial ini;
   shape s;
   s.box(2,2,79,24,218);
   s.line_hor(3,78,4,196);
   s.line_hor(3,78,22,196);
   gotoxy(71,1);
   std::cout<<"&lt;0>=EXIT";
   setColor(9, 0);
   gotoxy(3,3);
   for(i=1;i<=76;i++){
   printf("  ");
   }
   setColor(11, 0);
   setColor(9, 0); 
   setColor(11, 0);
   gotoxy(32,3);
   printf("OPEN NEW ACCOUNT");
   setColor(11, 0);
   setColor(9, 0);
   int d1,m1,y1;
    
     // Get current time as time_point
    auto now = std::chrono::system_clock::now();
    // Convert to time_t for std::tm
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    // Convert to local time
    std::tm local_tm = *std::localtime(&now_time_t);
    
    // Extract day, month, and year
     d1 = local_tm.tm_mday;
     m1 = local_tm.tm_mon + 1; // tm_mon is 0-based
     y1 = local_tm.tm_year + 1900; // tm_year is years since 1900
   int t_accno;
   t_accno=ini.last_accno();
   t_accno++;
   if(t_accno==1)
   {
      ini.add_to_file(t_accno,"abc","xyz",1.1);
      ini.delete_account(t_accno);
      add_to_file(t_accno,1,1,1997,'D',"INITIAL",1.1,1.1,1.1);
      delete_account(t_accno);
   }
   char t_name[30],t[10],t_address[60];
   float t_bal=0.0, t_balance=0.0;
   gotoxy(5,6);
   std::cout<<"DATE:"<<d1<<"/"<<m1<<"/"<<y1;
   gotoxy(5,8);
   std::cout<<"ACCOUNT NO. # :"<<t_accno;
   gotoxy(5,10);
   std::cout<<"NAME   :";
   gotoxy(8,11);
   std::cout<<"ADDRESS  :";
   gotoxy(8,12);
   std::cout<<"NAME OF VARIFYING PERSON:";
   gotoxy(5,14);
   std::cout<<"INITIAL DEPOSIT";
   do
   {
      clear(15,10);
      clear(5,23);
      gotoxy(5,23);
      std::cout<<"ENTER NAME OF THE PERSON";
      valid=1;
      gotoxy(15,10);
      gets(t_name);
      strupr(t_name);
      if(t_name[0]=='0')
	  return;
      if(strlen(t_name)==0||strlen(t_name)>25)
      {
	 valid=0;
	 gotoxy(5,23);
	 printf("\7NAME SHOULD NOT BLANK OR GREATER THAN 25");
	 getch();
      }
   }while(!valid);
   do
   {
      clear(15,11);
      clear(5,23);
      gotoxy(5,23);
      std::cout<<"ENTER ADDRESS OF THE PERSON";
      valid=1;
      gotoxy(23,11);
      gets(t_address);
      strupr(t_address);
      if(t_address[0]=='0')
	   return;
      if(strlen(t_address)==0|| strlen(t_address)>55)
      {
	valid =0;
	gotoxy(5,23);
	printf("\7SHOULD NOT BLANK OR GREATER THAN 55");
	getch();
      }
   }while(!valid);
   do
   {
      char vari[30];
      clear(5,23);
      gotoxy(5,23);
      std::cout<<"ENTER NAME OF THE VARIFYING PERSON";
      valid=1;
      gotoxy(35,12);
      gets(vari);
      strupr(vari);
      if(vari[0]=='0')
	  return;
      if(strlen(vari)==0 || strlen(vari)>25)
      {
	valid=0;
	gotoxy(5,23);
	printf("\7SHOULD NOT BLANK OR GREATER THAN 25");
	getch();
      }
   }while(!valid);
   do
   {
      clear(5,23);
      clear(5,23);
      gotoxy(5,23);
      std::cout<<"ENTER INITIAL AMOUNT TO BE DEPOSIT";
      valid=1;
      gotoxy(23,14);
      gets(t);
      t_bal=atof(t);
      t_balance=t_bal;
      if(t[0]=='0')
	  return;
      if (t_balance < 500)
      {
	valid=0;
	gotoxy(5,23);
	printf("\7SHOULD NOT LESS THAN 500    ");
	getch();
      }
   }while(!valid);
   clear(5,23);
   do
   {
     clear(5,17);
     valid=1;
     gotoxy(7,21);
     std::cout<<"DO YOU WANT TO SAVE THE RECORD (Y/N)";
     ch=getche();
     if(ch=='0')
	 return;
     ch=toupper(ch);
   }while(ch!='N' && ch!='Y');
   if(ch=='N')
      return;
   float t_amount,t_interest;
   t_amount=t_balance;
   t_interest=0.0;
   char t_tran,t_type[10];
   t_tran='D';
   strcpy(t_type,"INITIAL");
   ini.add_to_file(t_accno,t_name,t_address,t_balance);
   add_to_file(t_accno,d1,m1,y1,t_tran,t_type,t_interest,t_amount,t_balance);
}

void account::box_for_display(int t_accno)
{
   shape s;
   s.box(2,1,79,25,218);
   s.line_hor(3,78,4,196);
   s.line_hor(3,78,6,196);
   s.line_hor(3,78,23,196);
   setColor(11, 0);
   gotoxy(3,5);
   for(int i=1;i<=76;i++) printf(" ");
   setColor(11, 0);
   setColor(9, 0);
   gotoxy(4,5);
   printf("DATE	PARTICULAR	DEPOSIT		WITHDRAW	INTEREST	BALANCE");
   setColor(11, 0);
   setColor(9, 0);
   int d1,m1,y1;
    
     // Get current time as time_point
    auto now = std::chrono::system_clock::now();
    // Convert to time_t for std::tm
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    // Convert to local time
    std::tm local_tm = *std::localtime(&now_time_t);
    
    // Extract day, month, and year
    d1 = local_tm.tm_mday;
    m1 = local_tm.tm_mon + 1; // tm_mon is 0-based
    y1 = local_tm.tm_year + 1900; // tm_year is years since 1900
   gotoxy(63,2);
   std::cout<<"DATE:  "<<d1<<"/"<<m1<<"/"<<y1;
   gotoxy(4,2);
   std::cout<<"ACCOUNT NO.  "<<t_accno;
   initial ini;
   char t_name[30];
   strcpy(t_name,ini.return_name(t_accno));
   char t_address[60];
   strcpy(t_address,ini.return_address(t_accno));
   gotoxy(25,2);
   std::cout<<t_name;
   gotoxy(25,3);
   std::cout<<t_address;
}
 
 void account::display_account(void)
{
   clrscr();
   char t_acc[10];
   int t,t_accno;
   gotoxy(71,1);
   std::cout<<"&lt;0>=EXIT";
   gotoxy(5,5);
   std::cout<<"ENTER THE ACCOUNT NO.";
   gets(t_acc);
   t=atoi(t_acc);
   t_accno=t;
   if(t_accno==0)
       return;
   clrscr();
   initial ini;
   if(!ini.found_account(t_accno))
   {
     gotoxy(5,5);
     std::cout<<"\7ACCOUNT NOT FOUND";
     getch();
     return;
   }
   box_for_display(t_accno);
   int row=7,flag;
   std::fstream file;
   file.open("BANKING.DAT",std::ios::in);
   while(file.read(reinterpret_cast<char*>(this),sizeof(account)))
      {
	 if(accno==t_accno)
	   {
	     flag=0;
	     delay(10);
	     gotoxy(4,row);
	     std::cout<<dd  <<"/"<<mm  <<"/" <<yy;
	     gotoxy(16,row);
	     std::cout<<type;
	     if(tran=='D')
		gotoxy(30,row);
	     else
	       gotoxy(42,row);
	     std::cout<<amount;
	     gotoxy(56,row);
	     std::cout<<interest;
	     gotoxy(66,row);
	     std::cout<<balance;
	     row++;
	     if(row==23)
	     {
		flag=1;
		row=7;
		gotoxy(4,24);
		std::cout<<" PRESS ANY KEY TO CONTINUE.... ";
		getch();
		clrscr();
		box_for_display(t_accno);
	     }
	   }
      }
      file.close();
      if(!flag)
      {
	gotoxy(4,24);
	std::cout<<"PRESS ANY KEY TO CONTINUE.....";
	getch();
      }
}

int account::no_of_days(int d1,int m1,int y1,int d2,int m2,int y2)
{
   static int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
   int days=0;
   while(d1!=d2 || m1!=m2 || y1!=y2)
	{
	  days++;
	  d1++;
	  if(d1>month[m1-1])
	    {
	      d1=1;
	      m1++;
	    }
	  if(m1>12)
	    {
	      m1=1;
	      y1++;
	    }
	}
   return days;
}

float account::calculate_interest(int t_accno,float t_balance)
{
   std::fstream file;
   file.open("BANKING.DAT",std::ios::in);
   file.seekg(0,std::ios::beg);
   int d1,m1,y1,days;
   while(file.read(reinterpret_cast<char*>(this), sizeof(account)))
	{
	   if(accno==t_accno)
	     {
	       d1=dd;
	       m1=mm;
	       y1=yy;
	       break;
	     }
	}
   int d2,m2,y2;
    
     // Get current time as time_point
    auto now = std::chrono::system_clock::now();
    // Convert to time_t for std::tm
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    // Convert to local time
    std::tm local_tm = *std::localtime(&now_time_t);
    
    // Extract day, month, and year
    d2 = local_tm.tm_mday;
    m2 = local_tm.tm_mon + 1; // tm_mon is 0-based
    y2 = local_tm.tm_year + 1900; // tm_year is years since 1900
   float t_interest=0.0;
   if((y2<y1 )||(y2==y1 && m2<m1)||(y2==y1&&m2==m1&&d2<d1))
       return t_interest;
   days=no_of_days(d1,m1,y1,d2,m2,y2);
   int months=0;
   if(days>=30)
     {
       months=days/30;
       t_interest=((t_balance*2)/100*months);
     }
   file.close();
   return t_interest;
}
 
 void account::transaction(void)
{
  clrscr();
  char t_acc[10];
  int t,t_accno,valid;
  gotoxy(71,1);
  std::cout<<"&lt;0>=EXIT";
  gotoxy(5,5);
  std::cout<<"ENTER THE ACCOUNT NO.";
  gets(t_acc);
  t=atoi(t_acc);
  t_accno=t;
  if(t_accno==0)
     return;
  clrscr();
  initial ini;
  if(!ini.found_account(t_accno))
    {
      gotoxy(5,5);
      std::cout<<"\7ACCOUNT NOT FOUND";
      getch();
      return;
    }
  shape s;
  s.box(2,2,79,24,218);
  s.line_hor(3,78,4,196);
  s.line_hor(3,78,22,196);
  gotoxy(71,1);
  std::cout<<"&lt;0>=EXIT";
  setColor(11, 0);
  gotoxy(3,3);
  for(int i=1;i<=76;i++) printf(" ");
  setColor(11, 0);
  setColor(9, 0);
  gotoxy(29,3);
  printf("TRANSACTION IN ACCOUNT");
  setColor(11, 0);
   setColor(9, 0);
  int d1,m1,y1;
    
     // Get current time as time_point
    auto now = std::chrono::system_clock::now();
    // Convert to time_t for std::tm
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    // Convert to local time
    std::tm local_tm = *std::localtime(&now_time_t);
    
    // Extract day, month, and year
    d1 = local_tm.tm_mday;
    m1 = local_tm.tm_mon + 1; // tm_mon is 0-based
    y1 = local_tm.tm_year + 1900; // tm_year is years since 1900
  gotoxy(5,6);
  std::cout<<"DATE: "<<d1<<"/"<<m1<<"/"<<y1;
  gotoxy(5,8);
  std::cout<<"ACCOUNT NO. #"<<t_accno;
  char t_name[30];
  char t_address[60];
  float t_balance;
  strcpy(t_name,ini.return_name(t_accno));
  strcpy(t_address,ini.return_address(t_accno));
  t_balance=ini.give_balance(t_accno);
  s.box(25,10,75,13,218);
  gotoxy(27,11);
  std::cout<<"NAME  :"<<t_name;
  gotoxy(27,12);
  std::cout<<"ADDRESS:  "<<t_address;
  gotoxy(5,15);
  std::cout<<"LAST BALANCE  : RS."<<t_balance;
  char t_tran,t_type[10],tm[10];
  float t_amount,t_amt;
  do
  {
     clear(5,18);
     valid=1;
     gotoxy(5,18);
     std::cout<<"DEPOSIT OR WITHDRAW (D/W) :";
     t_tran=getche();
     if(t_tran=='0')
	 return;
     t_tran=toupper(t_tran);
  }while(t_tran!='D' && t_tran!='W');
  do
  {
      clear(5,19);
      clear(5,23);
      gotoxy(5,23);
      std::cout<<"ENTER TRANSACTIONS BY CASH OR CHEQUE";
      valid=1;
      gotoxy(5,19);
      std::cout<<"(CASH/CHEQUE):";
      gets(t_type);
      strupr(t_type);
      if(t_type[0]=='0')
	  return;
      if(strcmp(t_type,"CASH") && strcmp(t_type,"CHEQUE"))
      {
	valid=0;
	gotoxy(5,23);
	printf("\7ENTER CORRECTLY               ");
	getch();
      }
  }while(!valid);
  do
  {
    clear(5,21);
    clear(5,23);
    gotoxy(5,23);
    std::cout<<"ENTER AMOUNT FOR TRANSACTION";
    valid=1;
    gotoxy(5,21);
    std::cout<<"AMOUNT :RS.";
    gets(tm);
    t_amt=atof(tm);
    t_amount=t_amt;
    if(tm[0]=='0')
	 return;
    if((t_tran=='W' && t_amount>t_balance)||(t_amount<1))
    {
       valid=0;
       gotoxy(5,23);
       printf("\7INVALID DATA ENTERED             ");
       getch();
    }
  }while(!valid);
  char ch;
  clear(5,23);
  do
  {
     clear(40,20);
     valid=1;
     gotoxy(40,20);
     std::cout<<"SAVE TRANSACTION (Y/N):  ";
     ch=getche();
     if(ch=='0')
	 return;
     ch=toupper(ch);
  }while(ch!='N' && ch!='Y');
  if(ch=='N')
      return;
  float t_interest;
  t_interest=calculate_interest(t_accno,t_balance);
  if(t_tran=='D')
    t_balance=t_balance+t_amount+t_interest;
  else
    t_balance=(t_balance-t_amount)+t_interest;
  ini.update_balance(t_accno,t_balance);
  add_to_file(t_accno,d1,m1,y1,t_tran,t_type,t_interest,t_amount,t_balance);
}
 
 void account::close_account(void)
{
   clrscr();
   char t_acc[10];
   int t,t_accno;
   gotoxy(71,1);
   std::cout<<"&lt;0>=EXIT";
   gotoxy(5,5);
   std::cout<<"ENTER THE ACCOUNT NO.";
   gets(t_acc);
   t=atoi(t_acc);
   t_accno=t;
   if(t_accno==0)
      return;
   clrscr();
   initial ini;
   if(!ini.found_account(t_accno))
     {
       gotoxy(5,5);
       std::cout<<"\7ACCOUNT NOT FOUND";
       getch();
       return;
     }
   shape s;
   s.box(2,2,79,24,218);
   s.line_hor(3,78,4,196);
   s.line_hor(3,78,22,196);
   gotoxy(71,1);
   std::cout<<"&lt;0>=EXIT";
   setColor(11, 0);
   setColor(9, 0);
   gotoxy(3,3);
   for(int i=1;i<=76;i++) printf("  ");
   setColor(11, 0);
   setColor(9, 0);
   gotoxy(30,3);
   printf("CLOSE ACCOUNT SCREEN");
   setColor(11, 0);
   setColor(9, 0);
   int d1,m1,y1;
    
     // Get current time as time_point
    auto now = std::chrono::system_clock::now();
    // Convert to time_t for std::tm
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    // Convert to local time
    std::tm local_tm = *std::localtime(&now_time_t);
    
    // Extract day, month, and year
    d1 = local_tm.tm_mday;
    m1 = local_tm.tm_mon + 1; // tm_mon is 0-based
    y1 = local_tm.tm_year + 1900; // tm_year is years since 1900
   gotoxy(62,5);
   std::cout<<"DATE:  "<<d1<<"/"<<m1<<"/"<<y1;
   char ch;
   ini.display(t_accno);
   do
   {
     clear(5,15);
     gotoxy(5,15);
     std::cout<<"CLOSE THIS ACCOUNT(Y/N):";
     ch=getche();
     if(ch=='0')
       return;
     ch=toupper(ch);
   }while(ch!='N' && ch!='Y');
   if(ch=='N')
      return;
   ini.delete_account(t_accno);
   delete_account(t_accno);
   gotoxy(5,20);
   std::cout<<"\7RECORD DELETED";
   gotoxy(5,23);
   std::cout<<"PRESS ANY KEY TO CONTINUE...";
   getch();
}
 

int main(void)
{
  control c;
  c.help();
  c.main_menu();

  return 0;
}
