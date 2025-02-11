# Bank Management System

This is a C++ console-based bank management system that allows users to manage bank accounts, perform transactions, and display account information. The project uses various C++ standard libraries and some specific libraries for Windows to control the console.

## Table of Contents

1. [Libraries Used](#libraries-used)
2. [Functions](#functions)
   - [gotoxy](#gotoxy)
   - [clrscr](#clrscr)
   - [delay](#delay)
   - [setColor](#setcolor)
3. [Classes](#classes)
   - [Shape](#shape)
   - [Control](#control)
   - [Initial](#initial)
   - [Account](#account)
4. [Main Menu](#main-menu)
5. [Compilation](#compilation)

## Libraries Used

- `#include <stdio.h>`
- `#include <windows.h>`
- `#include <conio.h>`
- `#include <direct.h>`
- `#include <fstream>`
- `#include <iostream>`
- `#include <chrono>`
- `#include <ctime>`

## Functions

### gotoxy

Moves the cursor to a specified position on the console screen.

```cpp
void gotoxy(int x, int y) {
    static HANDLE h = nullptr;
    if (!h) h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(h, c);
}
```

### clrscr

Clears the console screen.

```cpp
void clrscr() {
    system("cls");
}
```

### delay

Pauses the execution for a specified number of milliseconds.

```cpp
void delay(unsigned int milliseconds) {
    Sleep(milliseconds);
}
```

### setColor

Sets the text and background color of the console.

```cpp
void setColor(int text, int background) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | background << 4);
}
```

## Classes

### Shape

Contains methods to draw shapes on the console screen.

#### Methods

- `line_hor`: Draws a horizontal line.
- `line_ver`: Draws a vertical line.
- `box`: Draws a box.

```cpp
class shape {
public:
    void line_hor(int, int, int, char);
    void line_ver(int, int, int, char);
    void box(int, int, int, int, char);
};
```

### Control

Manages the main menu and help functionality.

#### Methods

- `main_menu`: Displays the main menu.
- `help`: Displays the help screen.
- `edit_menu`: Displays the edit menu.

```cpp
class control {
public:
    void main_menu(void);
    void help(void);

private:
    void edit_menu(void);
};
```

### Initial

Handles account-related operations.

#### Methods

- `add_to_file`
- `display_list`
- `delete_account`
- `update_balance`
- `modify`
- `last_accno`
- `found_account`
- `return_name`
- `return_address`
- `give_balance`
- `recordno`
- `display`

```cpp
class initial {
public:
    void add_to_file(int, char t_name[30], char t_address[60], float);
    void display_list(void);
    void delete_account(int);
    void update_balance(int, float);
    void modify(void);
    int last_accno(void);
    int found_account(int);
    char* return_name(int t_accno);
    char* return_address(int t_accno);
    float give_balance(int);
    int recordno(int);
    void display(int);

private:
    void modify_account(int, char t_name[30], char t_address[60]);
    void box_for_list(void);

    int accno;
    char name[30];
    char address[60];
    float balance;
};
```

### Account

Handles account transactions and displays.

#### Methods

- `new_account`
- `close_account`
- `display_account`
- `transaction`
- `clear`
- `add_to_file`
- `delete_account`
- `no_of_days`
- `calculate_interest`
- `display`
- `box_for_display`

```cpp
class account {
public:
    void new_account(void);
    void close_account(void);
    void display_account(void);
    void transaction(void);
    void clear(int, int);

private:
    void add_to_file(int, int, int, int, char, char t_type[10], float, float, float);
    void delete_account(int);
    int no_of_days(int, int, int, int, int, int);
    float calculate_interest(int, float);
    void display(int);
    void box_for_display(int);

    int accno;
    char type[10];  // Cheque or Cash
    int dd, mm, yy;  // Date
    char tran;  // Deposit or withdrawal
    float interest, amount, balance;
};
```

## Main Menu

The `main_menu` function of the `Control` class displays the main menu of the application and handles user input for various options.

```cpp
void control::main_menu(void) {
    char ch;
    while (1) {
        clrscr();
        shape s;
        s.box(10, 5, 71, 21, 219);
        s.box(9, 4, 72, 22, 218);
        setColor(11, 0); // Light cyan text on black background
        gotoxy(32, 7);
        printf(" B A N K I N G ");
        gotoxy(35, 9);
        printf(" OPTIONS ");
        setColor(9, 0); // Light blue text on black background
        gotoxy(30, 11);
        std::cout << "1: SEE ACCOUNT ";
        gotoxy(30, 12);
        std::cout << "2: LIST OF ACCOUNTS ";
        gotoxy(30, 13);
        std::cout << "3: TRANSACTIONS ";
        gotoxy(30, 14);
        std::cout << "4: OPEN NEW ACCOUNT ";
        gotoxy(30, 15);
        std::cout << "5: EDIT ACCOUNTS ";
        gotoxy(30, 16);
        std::cout << "6: HELP ";
        gotoxy(30, 17);
        std::cout << "0: QUIT ";
        gotoxy(30, 19);
        std::cout << " ENTER YOUR CHOICE:";
        ch = getche();
        if (ch == 27) break;
        else if (ch == '1') {
            account a;
            a.display_account();
        } else if (ch == '2') {
            initial ini;
            ini.display_list();
        } else if (ch == '3') {
            account a;
            a.transaction();
        } else if (ch == '4') {
            account a;
            a.new_account();
        } else if (ch == '5') edit_menu();
        else if (ch == '6') help();
        else if (ch == '0') break;
    }
    for (int i = 25; i >= 1; i--) {
        delay(2000);
        gotoxy(1, i);
        std::cout << "\033[2J\033[1;1H";
    }
}
```

## Compilation

To compile and run this project, you need a C++ compiler and a Windows environment. Use the following command to compile:

```bash
g++ -o banking banking.cpp -lconio
```

Then run the executable:

```bash
./banking
```

This README provides an overview of the project structure and essential functionalities. For more details, refer to the comments and function implementations in the code.
