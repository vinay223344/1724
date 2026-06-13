/*
 ============================================================================
 Name        : Assignment14_structures.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
/*1. Create a structure to specify data on students given below:
Roll number, Name, Department, Course, Year of joining
Assume that there are not more than 450 students in the college.
(a) Write a function to print names of all students who joined in a particular year.
(b) Write a function to print the data of a student whose roll numbers are specified.*/
struct student{
	int roll_no;
	char name[40];
	char dept[20];
	char course[10];
	int year;
};
void q1() {
	int n = 10;

	struct student s[10] = {
	    {101, "Ravi",   "CSE", "BTech", 2022},
	    {102, "Priya",  "ECE", "BTech", 2021},
	    {103, "Kiran",  "EEE", "BTech", 2022},
	    {104, "Anjali", "CSE", "BTech", 2020},
	    {105, "Rahul",  "MECH","BTech", 2021},
	    {106, "Sneha",  "ECE", "BTech", 2022},
	    {107, "Arjun",  "CIVIL","BTech",2023},
	    {108, "Divya",  "CSE", "MTech", 2021},
	    {109, "Teja",   "ECE", "BTech", 2023},
	    {110, "Pooja",  "IT",  "BTech", 2022}
	};
	/*printf("enter number of students:\n");
			scanf("%d", &n);
			if(n>450){
				return;
			}
	struct student s[n];
	for (int i = 0; i < n; i++) {
		printf("enter the roll number of %d\n", i + 1);
		scanf("%d", &s[i].roll_no);
		printf("Enter Name: \n");
		scanf("%s", s[i].name);
		printf("Enter Department: \n");
		scanf("%s", s[i].dept);
		printf("Enter Course: \n");
		scanf("%s", s[i].course);
		printf("Enter Year of Joining: \n");
		scanf("%d", &s[i].year);
	}*/
	int yr;
	printf("enter the year of joining:\n");
	scanf("%d",&yr);
	int count;
	for (int i = 0; i < n; i++) {
		if(yr==s[i].year){
			printf("%s\n", s[i].name);
			count++;
		}
	}
	if(count==0) printf("not found\n");

	int rn;
	printf("enter the roll number:\n");
	scanf("%d",&rn);
int c=0;
	for (int i = 0; i < n; i++) {
		//printf("%d %d\n",rn,s[i].roll_no);
			if(rn==s[i].roll_no){
				printf("roll number= %d\t", s[i].roll_no);
				printf("name = %s\t", s[i].name);
				printf("department = %s\t", s[i].dept);
				printf("course = %s\t", s[i].course);
				printf("year_of_joining = %d\n", s[i].year);
				c++;
				break;
			}
		}
	if(c==0) printf("not found\n");

}
/*output:
enter the year of joining:
2022
Ravi
Kiran
Sneha
Pooja
enter the roll number:
222
not found*/
/*Create a structure to specify data of customers in a bank. The data to be stored is:
• Account number
• Name
• Balance in account.
Assume a maximum of 200 customers in the bank.
(a) Write a function to print the Account number and name of each customer with
balance below Rs. 100.
(b) For withdrawal/deposit requests (fields: Acct. no, amount, code → 1 for deposit,
0 for withdrawal),
write a program to update balance. If on withdrawal the balance falls below Rs.100,
display:
“The balance is insufficient for the specified withdrawal”.*/

typedef struct {
	long int acc_no;
	char name[40];
	long int bal;
} customer;
void below100(customer c[], int n)
{
    printf("\nCustomers with balance below 100:\n");

    for (int i = 0; i < n; i++)
    {
        if (c[i].bal < 100)
        {
            printf("Acc No: %ld\t Name: %s \tBalance: %ld\n",
                   c[i].acc_no, c[i].name, c[i].bal);
        }
    }
}
void deposit(customer c[], int n) {
	int acc_num, amount;
	printf("enter your account number");
	scanf("%d", &acc_num);
	printf("Enter the amount to deposit: \n");
	scanf("%d", &amount);
	for (int i = 0; i < n; i++) {
		if (c[i].acc_no == acc_num) {
			c[i].bal += amount;
			printf("your available balance = %ld\n thanks", c[i].bal);
		}
	}
}
void withdrawl(customer c[], int n){
	int acc_num, amount;
		printf("enter your account number");
		scanf("%d", &acc_num);
		printf("Enter the amount to withdrawl: \n");
		scanf("%d", &amount);
		for (int i = 0; i < n; i++) {
			if (c[i].acc_no == acc_num) {
				if(c[i].bal-amount <100){
					printf("The balance is insufficient for the specified withdrawal");
					return;
				}
				else{
					c[i].bal-=amount;
					printf("please collect the cash\n\n your available balance = %ld\n thanks", c[i].bal);
				}
			}
		}
}
void q2() {
	 customer c[] = {
	        {101, "Amit", 1200},
	        {102, "Ravi", 80},
	        {103, "Sneha", 950},
	        {104, "John", 5000},
	        {105, "Kiran", 50},
	        {106, "Meena", 300},
	        {107, "Vikas", 1500},
	        {108, "Anita", 20},
	        {109, "Suresh", 700},
	        {110, "Divya", 2000}};
	/*int n;
	printf("enter number of customers:\n");
	scanf("%d", &n);
	if (n > 200) {
		return;
	}
	customer c[n];

	for (int i = 0; i < n; i++) {
		printf("enter the account number of customer %d\n", i + 1);
		scanf("%d", &c[i].acc_no);
		printf("Enter Name: \n");
		scanf("%s", c[i].name);
		printf("Enter balance amount: \n");
		scanf("%d", &c[i].bal);
	}
*/

	 char select1;
	 printf("you want to know customers under balance 100(y/n)\n");
	 scanf(" %c", &select1);
	 if(select1 == 'y'){
		 below100(c,10);
	 }
	 else printf("thanks\n");
	 int select2;
	 printf("you want to withdrawl or deposit(0/1)\n");
	 scanf(" %d", &select2);
	 if(select2 == 1){
		 deposit(c,10);
	 }
	 else if(select2 == 0){
		 withdrawl(c, 10);
	 }
	 else printf("thanks\n");
}/*
output:
you want to know customers under balance 100(y/n)
y

Customers with balance below 100:
Acc No: 102	 Name: Ravi 	Balance: 80
Acc No: 105	 Name: Kiran 	Balance: 50
Acc No: 108	 Name: Anita 	Balance: 20
you want to withdrawl or deposit(0/1)
1
enter your account number108
Enter the amount to deposit:
100
your available balance = 120
 thanks*/

/*3. An automobile company has serial number for engine parts starting from AA0 to
FF9. The other characteristics of parts are year of manufacture, material and
quantity manufactured.
(a) Define a structure to store this information.
(b) Write a program to retrieve information on parts with serial numbers between
BB1 and CC6.*/
typedef struct{
	char serial[3];
	int year;
	char mat_name[100];
	int quan;
}material;
void retrive_data(material p[], int n) {
	for (int i = 0; i < n; i++) {
		if (strcmp(p[i].serial, "BB1") >= 0
				&& strcmp(p[i].serial, "CC6") <= 0) {
			printf(
					"serial number = %s\t year of manufacture=%d\tname = %s\t quantity=%d\n",
					p[i].serial, p[i].year, p[i].mat_name, p[i].quan);
		}
	}
}

void material_func(){
	int n =10;
	 material p[] =
	    {
	        {"AA0", 2020, "Steel", 500},
	        {"BB1", 2021, "Iron", 300},
	        {"BB5", 2022, "Aluminium", 450},
	        {"BC3", 2021, "Steel", 600},
	        {"CC0", 2023, "Copper", 250},
	        {"CC6", 2022, "Iron", 700},
	        {"DD2", 2024, "Steel", 400},
	        {"EE8", 2023, "Aluminium", 350},
	        {"FF9", 2025, "Titanium", 150},
	        {"CD4", 2022, "Copper", 500}
	    };
/*	int n;

printf("Enter number of materials:\n");
scanf("%d", &n);

if (n > 60)
{
    return;
}

struct material p[n];

for (int i = 0; i < n; i++)
{
    printf("Enter part number of %d:\n", i + 1);
    scanf("%3s", p[i].serial);

    printf("Enter year:\n");
    scanf("%d", &p[i].year);

    printf("Enter material name:\n");
    scanf("%19s", p[i].mat_name);

    printf("Enter quantity:\n");
    scanf("%d", &p[i].quan);
}*/
	 char option;
	 printf("you have retrive data(y/n)\n");
		 scanf(" %c", &option);
	 if(option == 'y'){
		 retrive_data(p,n);
	 }
	 else printf("thanks\n");
}
/*
output:
you have retrive data(y/n)
y
serial number = BB1	 year of manufacture=2021	name = Iron	 quantity=300
serial number = BB5	 year of manufacture=2022	name = Aluminium	 quantity=450
serial number = BC3	 year of manufacture=2021	name = Steel	 quantity=600
serial number = CC0	 year of manufacture=2023	name = Copper	 quantity=250
serial number = CC6	 year of manufacture=2022	name = Iron	 quantity=700
*/


/*4. A record contains name of cricketer, his age, number of test matches that he has
played and the average runs that he has scored in each test match. Create an array
of structures to hold records of 20 such cricketers and then write a program to read
and arrange records in ascending order by average runs.*/


typedef struct
{
    char name[50];
    int age;
    int matches;
    float avg;
} cric;

void cricket()
{
/*	 cric c[20], temp;
	    int n, i, j;

	    printf("Enter number of cricketers (max 20): ");
	    scanf("%d", &n);

	    for(i = 0; i < n; i++)
	    {
	        printf("\nEnter details of Cricketer %d\n", i + 1);

	        printf("Name: ");
	        scanf(" %s", c[i].name);

	        printf("Age: ");
	        scanf("%d", &c[i].age);

	        printf("Matches: ");
	        scanf("%d", &c[i].matches);

	        printf("Average Runs: ");
	        scanf("%f", &c[i].avg);
	    }*/
    cric temp;
    int i, j;

    cric c[] = {
        {"Virat Kohli", 36, 123, 48.70},
        {"Rohit Sharma", 38, 67, 45.20},
        {"Joe Root", 35, 152, 50.80},
        {"Steve Smith", 37, 110, 58.10},
        {"Kane Williamson", 35, 102, 54.30},
        {"Babar Azam", 31, 58, 43.90},
        {"Ben Stokes", 35, 108, 36.70},
        {"David Warner", 39, 112, 44.50},
        {"Marnus Labuschagne", 32, 60, 53.20},
        {"Travis Head", 33, 55, 42.40},
        {"Shubman Gill", 27, 35, 39.60},
        {"KL Rahul", 34, 58, 34.80},
        {"Cheteshwar Pujara", 38, 103, 43.60},
        {"Ajinkya Rahane", 38, 85, 38.50},
        {"Ravindra Jadeja", 37, 78, 35.20},
        {"Rishabh Pant", 29, 40, 44.10},
        {"Yashasvi Jaiswal", 24, 15, 52.70},
        {"Sarfaraz Khan", 28, 8, 48.90},
        {"Harry Brook", 27, 22, 57.40},
        {"Usman Khawaja", 40, 78, 46.30}
    };

    int n = sizeof(c) / sizeof(c[0]);

    /* Sort in ascending order of average runs */
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(c[i].avg > c[j].avg)
            {
                temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }

    printf("%s\t \t%s \t%s \t%s\n",
           "Name", "Age", "Matches", "Avg");

    for(i = 0; i < n; i++)
    {
        printf("%s \t%d \t%d \t%f\n",
               c[i].name,
               c[i].age,
               c[i].matches,
               c[i].avg);
    }
}

/*output:
Name	 Age 	Matches 	Avg
KL Rahul 	34 	58 	34.799999
Ravindra Jadeja 	37 	78 	35.200001
Ben Stokes 	35 	108 	36.700001
Ajinkya Rahane 	38 	85 	38.500000*/


/*5. Define a structure Employee containing:
• Employee code
• Name
• Date of joining
Write a program to enter data into an array of employees. Ask user to input current
date, then display names of employees whose tenure is ≥ 3 years.*/
typedef struct {
	int day;
	int month;
	int year;
} date;
typedef struct {
	int emp_id;
	char name[100];
	date doj;
} emp;
void employee() {
	emp e[10] = { { 101, "Amit Kumar", { 12, 5, 2025 } }, { 102, "Priya Sharma",
			{ 18, 8, 2024 } }, { 103, "Rahul Verma", { 25, 1, 2025 } }, { 104,
			"Sneha Reddy", { 10, 11, 2018 } }, { 105, "Vikram Singh", { 5, 3,
			2023 } }, { 106, "Anjali Gupta", { 14, 7, 2025 } }, { 107,
			"Kiran Patel", { 22, 9, 2024 } }, { 108, "Neha Joshi", { 30, 12,
			2022 } }, { 109, "Arjun Mehta", { 8, 4, 2024 } }, { 110,
			"Pooja Nair", { 16, 6, 2024 } } };
//	emp e[10];
	int n = 10;

	/*printf("Enter number of employees (max 10): ");
	 scanf("%d", &n);
	 if (n > 10) {
	 return;
	 }
	 for (int i = 0; i < n; i++) {
	 printf("\nEnter details of employee %d\n", i + 1);
	 printf("code: ");
	 scanf("%d", &e[i].emp_id);
	 printf("Name: \n");
	 scanf(" %s", e[i].name);
	 printf("enter date of joining dd mm yyyy format\n: ");
	 scanf("%d %d %d", &e[i].doj.day, &e[i].doj.month, &e[i].doj.year);
	 }
	 for (int i = 0; i < n; i++) {
	 printf("%d", e[i].emp_id);
	 printf("\t%s", e[i].name);
	 printf("\t%d %d %d", e[i].doj.day, e[i].doj.month, e[i].doj.year);
	 }*/

	date curr1;
	date diff;
	printf("enter date of current day dd mm yyyy format:\n ");
	scanf("%d %d %d", &curr1.day, &curr1.month, &curr1.year);
	for (int i = 0; i < n; i++) {
		date curr = curr1;
		if (curr.day >= e[i].doj.day) {
			diff.day = curr.day - e[i].doj.day;
		} else {
			diff.day = (30 + curr.day) - e[i].doj.day;
			curr.month -= 1;
		}
		if (curr.month >= e[i].doj.month) {
			diff.month = curr.month - e[i].doj.month;
		} else {
			diff.month = (12 + curr.month) - e[i].doj.month;
			curr.year -= 1;
		}
		diff.year = curr.year - e[i].doj.year;
		if (diff.year >= 3) {
			printf("%s\n", e[i].name);
		}
	}
}
/*output:
enter date of current day dd mm yyyy format:
 11 06 2026
Sneha Reddy
Vikram Singh
Neha Joshi*/
/*
6. Create a structure Library to hold:
• Accession number
• Title of the book
• Author name
• Price
• Flag (issued or not)
Write a menu-driven program with options:
a.Add book information
b.Display book information
c.List all books of a given author
d.List title of a specified book
e.Count books in the library
f.List books in order of accession number
g.Exit*/
typedef struct  {
    int access_num;
    char title[50];
    char author[50];
    float price;
    int issued;
}library;
//int count = 0;

library temp;
void accession_number_order(library books[], int count) {
	for (int i = 0; i < count; i++) {
		for (int j = i + 1; j < count; j++) {
			if (books[i].access_num > books[j].access_num) {
				temp = books[i];
				books[i] = books[j];
				books[j] = temp;
			}
		}
	}
	for (int i = 0; i < count; i++) {
			printf("\nAccession Number: %d", books[i].access_num);
			printf("\tTitle: %s", books[i].title);
			printf("\tAuthor: %s", books[i].author);
			printf("\tPrice: %f", books[i].price);
			printf("\tStatus: %s\n", books[i].issued ? "Issued" : "Not Issued\n");
		}
}
void count_books(int count){
    printf("Total Books = %d\n", count);
}
void list_title_number(library books[], int count) {
	int id, found = 0;
	printf("Enter Accession Number: \n");
	scanf("%d", &id);
	for (int i = 0; i < count; i++) {
		if (books[i].access_num == id) {
			printf("Book Title: %s\n", books[i].title);
			found = 1;
			break;
		}
	}
	if (found==0)
		printf("Book not found.\n");
}


void list_by_author(library books[], int count) {
    char author[100];
    int i, found = 0;

    printf("Enter Author Name:\n ");
    scanf(" %s", author);

    for (i = 0; i < count; i++) {
        if (strcmp(books[i].author, author) == 0) {
            printf("%s\n", books[i].title);
            found = 1;
        }
    }

    if (found==0)
        printf("No books found.\n");
}
int add_book(library books[], int count) {
	    printf("\nEnter Accession Number: ");
	    scanf("%d", &books[count].access_num);
	    printf("Enter Title: ");
	    scanf(" %s", books[count].title);
	    printf("Enter Author Name: ");
	    scanf(" %s", books[count].author);
	    printf("Enter Price: ");
	    scanf("%f", &books[count].price);
	    printf("Issued? (1 = Yes, 0 = No): ");
	    scanf("%d", &books[count].issued);
	    count++;
	    printf("Book added successfully \n");
	    return count;
}
void book_info(library books[], int count) {
	int i;
	if (count == 0) {
		printf("No books available.\n");
		return;
	}
	printf("\nLibrary Books:\n");
	for (i = 0; i < count; i++) {
		printf("\Accession Number: %d", books[i].access_num);
		printf("\tTitle: %s", books[i].title);
		printf("\tAuthor: %s", books[i].author);
		printf("\tPrice: %f", books[i].price);
		printf("\tStatus: %s\n", books[i].issued ? "Issued" : "Not Issued");
	}
}
void lib() {
	int ch;
	int n = 100;//int count =0;
	//library books[n];

	library books[] =
	{
	    {101, "C Programming", "Dennis Ritchie", 450.00, 0},
	    {102, "Data Structures", "Seymour Lipschutz", 550.00, 1},
	    {103, "Operating Systems", "Galvin", 650.00, 0},
	    {104, "Computer Networks", "Andrew Tanenbaum", 700.00, 1},
	    {105, "Database Systems", "Korth", 600.00, 0}
	};int count = sizeof(books) / sizeof(books[0]);
	while (1) {
		printf("1. Add Book Information\n");
		printf("2. Display Books Information\n");
		printf("3. List Books by Author\n");
		printf("4. Search by Title number\n");
		printf("5. Count Books\n");
		printf("6. order Books by Accession Number\n");
		printf("7. Exit\n");
		printf("Enter choice:\n ");
		scanf("%d", &ch);
		switch (ch) {
		case 1:
		    count = add_book(books, count);
		    break;
		case 2:
			book_info(books, count);
			break;
		case 3:
			list_by_author(books, count);
			break;
		case 4:
			list_title_number(books, count);
			break;
		case 5:
			count_books(count);
			break;
		case 6:
			accession_number_order(books, count);
			break;
		default:
			printf("Exiting\n");
			return;
		}
	}
}
/*output:
1. Add Book Information
2. Display Books Information
3. List Books by Author
4. Search by Title number
5. Count Books
6. order Books by Accession Number
7. Exit
Enter choice:
 4
Enter Accession Number:
102
Book Title: Data Structures*/

/*7. Write a c program to Create an array of four function pointers where each pointer
should point to a different function. Each function should take two integers and
return a float. Using a loop, call function using the addresses present in the array.*/
float add(int a, int b) {
    return (float)(a + b);
}

float sub(int a, int b) {
    return (float)(a - b);
}

float mul(int a, int b) {
    return (float)(a * b);
}

float div1(int a, int b) {
    if (b == 0)
        return 0.0;
    return (float)a / b;
}

int question7() {
    float (*fp[4])(int, int) = {add, sub, mul, div1};

    int x = 5, y = 10;

    for (int i = 0; i < 4; i++) {
        float result = fp[i](x, y);
        printf("function %f result = %.2f\n", i + 1, result);
    }

    return 0;
}/*
output:
function 15.000000 result = 0.00
function -5.000000 result = 0.00
function 50.000000 result = 0.00
function 0.500000 result = 0.00
*/
#include <stdarg.h>
/*8. Write a function that receives variable number of arguments, where arguments are
coordinates of points. Based on number of arguments, display shape type (point,
line, triangle, etc.).*/
void shapeType(int start, ...)
{
    va_list args;
    va_start(args, start);
	int x, y;
	int count =0;
	while (1) {
		if ((x == -1) && (y == -1)) {
			break;
		}
		x = va_arg(args, int);
		y = va_arg(args, int);
		//printf("(%d,%d) ", x, y);
		count++;
	}
    printf("\nShape: ");
    switch(count-1)
    {
        case 1: printf("Point\n"); break;
        case 2: printf("Line\n"); break;
        case 3: printf("Triangle\n"); break;
        case 4: printf("Quadrilateral\n"); break;
        case 5: printf("Pentagon\n"); break;
        case 6: printf("hexagon\n"); break;
        case 8: printf("octagon\n"); break;
        default: printf("%d-side Polygon\n", count-1);
    }
    va_end(args);
}

void question8()
{
    shapeType(0, 2, 3,-1,-1);
    shapeType(0, 1, 2, 3, 4,-1,-1);
    shapeType(0, 0, 0, 2, 0, 1, 3,0, 0, 2, 0, 1, 3,-1,-1);
}
/*output:

Shape: Point

Shape: Line

Shape: hexagon*/
/*9. Define a structure Date with members stored as bit fields:
• Day → 5 bits
• Month → 4 bits
• Year → 12 bits
Write a program to read date of joining of 10 employees and display them in
ascending order of year.*/
struct Date
{
	unsigned int day : 5;
	unsigned int month : 4;
	unsigned int year : 12;
};

void question9()
{
  /*  struct Date emp[10], temp;
int d,m,y;
    printf("Enter joining dates of 10 employees (dd mm yyyy):\n");

    for(int i = 0; i < 10; i++)
    {
        scanf("%u %u %u",&d,&m,&y);
              &emp[i].day,
              &emp[i].month,
              &emp[i].year);
        emp[i].day = d;
        emp[i].month=m;
                      emp[i].year=y;    }*/
	struct Date temp;
    struct Date emp[10] = {
            {12, 5, 2021},
            {3, 1, 2019},
            {25, 12, 2019},
            {1, 7, 2018},
            {15, 8, 2022},
            {9, 3, 2017},
            {30, 11, 2023},
            {6, 6, 2016},
            {18, 10, 2024},
            {22, 2, 2015}
        };
    for(int i = 0; i < 9; i++)
    {
        for(int j = i + 1; j < 10; j++)
        {
			if ((emp[i].year > emp[j].year)
					|| ((emp[i].year == emp[j].year)
							&& (emp[i].month > emp[j].month))
					|| ((((emp[i].year == emp[j].year)
							&& (emp[i].month > emp[j].month)))
							&& (emp[i].day > emp[j].day))) {
				temp = emp[i];
				emp[i] = emp[j];
				emp[j] = temp;
			}
		}
	}

    printf("\n\n");

    for(int i = 0; i < 10; i++)
    {
        printf("%u/%u/%u\n",
               emp[i].day,
               emp[i].month,
               emp[i].year);
    }
}
/*
output:
22/2/2015
6/6/2016
9/3/2017
1/7/2018
3/1/2019
25/12/2019
12/5/2021
15/8/2022
30/11/2023
18/10/2024
*/

/*10. Write a program to read and store information about insurance policy holder. The
information contains details like gender, whether the holder is minor/major, policy
name and duration of the policy. Make use of bit-fields to store this information.*/
struct policyholder
{
    unsigned int gender : 1;   // 0-Female,1-Male
    unsigned int major : 1;    // 0-Minor,1-Major
    char policyname[30];
    unsigned int duration : 6;
};
void question10()
{
    struct policyholder p;
    unsigned int g, m,  d;
  //  char pn[];
    printf("Enter Gender (1-Male,0-Female): ");
    scanf("%u", &g);
    p.gender=g;
    printf("Enter Status (1-Major,0-Minor): ");
    scanf("%u", &m);
    p.major=m;
    printf("Enter Policy Name: ");
    scanf("%s", p.policyname);
   // p.policyname= pn;
    printf("Enter Duration (Years): ");
    scanf("%u", &d);
    p.duration=d;
    printf("\nPolicy Holder Details\n");
    printf("Gender: %s\n", p.gender ? "Male" : "Female");
    printf("Status: %s\n", p.major ? "Major" : "Minor");
    printf("Policy Name: %s\n", p.policyname);
    printf("Duration: %u Years\n", p.duration);
}
/*output:
Enter Gender (1-Male,0-Female): 1
Enter Status (1-Major,0-Minor): 1
Enter Policy Name: shesh'
Enter Duration (Years): 10

Policy Holder Details
Gender: Male
Status: Major
Policy Name: shesh'
Duration: 10 Years*/

#include <ctype.h>

typedef struct  {
    char name[50];
    int age;
    char address[100];
}student;

void touppercase(char str[]) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

void question11() {
    student s1 = {"Ravi", 20, "Hyderabad"};
    student s2 = {"Priya", 21, "Vijayawada"};
    student s3 = {"Arun", 19, "Visakhapatnam"};

    touppercase(s1.name);
    touppercase(s2.name);
    touppercase(s3.name);
    printf("Name: %s\tAge: %d\tAddress: %s\n\n",
           s1.name, s1.age, s1.address);
    printf("Name: %s\tAge: %d\tAddress: %s\n\n",
           s2.name, s2.age, s2.address);
    printf("Name: %s\tAge: %d\tAddress: %s\n\n",
           s3.name, s3.age, s3.address);
}

/*output:
Name: RAVI	Age: 20	Address: Hyderabad

Name: PRIYA	Age: 21	Address: Vijayawada

Name: ARUN	Age: 19	Address: Visakhapatnam*/

/*12. Write a C program to use an enum for traffic light states (RED, YELLOW, GREEN) and
simulate a traffic signal system using switch-case and transition every N seconds.*/


enum traffic {
    RED,
    YELLOW,
    GREEN
}signal;

void q12() {
	signal  = RED;
//	int signal =0;
    int n, cycles, i;

    printf("Enter transition time (in seconds): ");
    scanf("%d", &n);

    printf("Enter number of cycles to simulate: ");
    scanf("%d", &cycles);

    for (i = 0; i < cycles; i++) {
        switch (signal) {
            case RED:
                printf("traffic Light: RED - Stop\n");
                signal = YELLOW;   // Next state
                break;

            case GREEN:
                printf("traffic Light: GREEN - Go\n");
                signal = RED;  // Next state
                break;

            case YELLOW:
                printf("traffic Light: YELLOW - Wait\n");
                signal = GREEN;     // Next state
                break;

            default:
                printf("Invalid State\n");
                return;
        }

           sleep(n);
    }

    return ;
}
/*output:
Enter transition time (in seconds): 1
Enter number of cycles to simulate: 6
traffic Light: RED - Stop
traffic Light: YELLOW - Wait
traffic Light: GREEN - Go
traffic Light: RED - Stop
traffic Light: YELLOW - Wait
traffic Light: GREEN - Go*/
/*
13. Create an enum Permission { READ=1, WRITE=2, EXEC=4 };
Write a program to combine permissions using | (bitwise OR), and check
permissions using &.*/
enum permission
{
	read = 1,
	write = 2,
	exec = 4
};

void question13()
{
    int permission = read | write;

    printf("Combined Permission Value = %d\n", permission);

    if(permission & read)
        printf("read Permission Granted\n");

    if(permission & write)
        printf("write Permission Granted\n");

    if(permission & exec)
        printf("exec Permission Granted\n");
    else
        printf("exec Permission Not Granted\n");
/*    int permission = read | exec;

        printf("combined permission value = %d\n", permission);

        if(permission & read)
            printf("read permission granted\n");

        if(permission & exec)
            printf("exec permission granted\n");

        if(permission & write)
            printf("write permission granted\n");
        else
            printf("write permission not granted\n");*/
}
/*output:
Combined Permission Value = 3
read Permission Granted
write Permission Granted
exec Permission Not Granted*/
/*
14. Define an enum for { ADD, SUB, MUL, DIV, EXIT }and Write a calculator program
where menu selection maps to the enum and corresponding function.
*/enum operation
{
    ADD = 1,
    SUB,
    MUL,
    DIV,
    EXIT
};

void question14()
{
    int choice;
    float a, b;
/*    printf("enter the choice:\n");
    scanf("%d", &choice);*/
    while(choice == 0||choice>=6)
    {
        printf("\n1.add\n2.sub\n3.mul\n4.del\n5.exit\n");
        printf("enter choice: ");
        scanf("%d", &choice);

        if(choice == 0||choice>=6)
            break;

        printf("enter two numbers: ");
        scanf("%f %f", &a, &b);

        switch(choice)
        {
            case ADD:
                printf("result = %f\n", a + b);
                break;

            case SUB:
                printf("result = %f\n", a - b);
                break;

            case MUL:
                printf("result = %f\n", a * b);
                break;

            case DIV:
                if(b != 0)
                    printf("result = %.2f\n", a / b);
                else
                    printf("division by zero error\n");
                break;

            default:
                printf("invalid choice\n");
        }

    }
}/*
output:

1.add
2.sub
3.mul
4.del
5.exit
enter choice: 2
enter two numbers: 2 2
result = 0.000000*/
//15. Define a struct and a union with same members (int, float, char).
//Write a program to print their sizes and explain difference in memory allocation.
struct samplestruct
{
    int i;
    float f;
    char c;
};

union sampleunion
{
    int i;
    float f;
    char c;
};

void q15()
{
    printf("Size of Structure = %lu bytes\n",sizeof(struct samplestruct));

    printf("Size of Union = %lu bytes\n",sizeof(union sampleunion));

    printf("Structure allocates memory for all members separately.\n");
    printf("Union shares the same (large) memory among all members.\n");
    printf(" union size equals largest member size.\n");
}


/*output:
Size of Structure = 12 bytes
Size of Union = 4 bytes*/


struct student1 {
	int r;
	float m;
	char c;
};
void q16() {
	struct student1 v;
	printf("%d\n", sizeof(v));
	printf("%d\n", sizeof(struct student1));
}
/*
output:
8
8*/
struct A1 {
	int x;
	int y;
};
void q17() {
	struct A1 v = { 10, 20 };
	struct A1 *p = &v;
	printf("%d %d\n", (*p).x, p->y);
}
/*output:
10 20*/
struct A2 {
	int x;
	int y;
	int *p;
};
void q18() {
	struct A2 m = { 10, 20 };
	m.p = &m.x;
	*(m.p) = 100;
	m.p = &m.y;
	*(m.p) = 200;
	printf("%d %d\n", m.x, m.y);
}
/*
output:
100 200
*/

/*struct A3 {
	int x = 10;
	int y = 20;
} mchip;
void q19() {
	printf("%d %d\n", mchip.x, mchip.y);
}*/
/*output:
 * We cannot initialize members while defining the structure
initialization is not possible*/

struct st {
	char a :5;
	char b :3;
	char c :2;
};
struct  {
	int a :28;
	char b :3;
	int c :2;
}st1;
void q20() {
	struct st mchip;

	printf("%d\n", sizeof(mchip));
	printf("%d\n", sizeof(st1));

//	printf("%u\n", &mchip.a);
//	printf("%u\n", &mchip.b);
//	printf("%u\n", &mchip.c);
}
/*
output:
we cant apply address operators to bit fields, so we can't use scanf
*/
int main(void) {
	//puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	int n;
	while (1) {

		printf("\n enter the question number:\n");
		scanf("%d", &n);
		if (n == 0) {
			return 0;
		}
		switch (n) {
		case 1:q1();break;
		case 2:q2();break;
		case 3:material_func();break;
		case 4:cricket();break;
		case 5:employee();break;
		case 6:lib();break;
		case 8:	question8();break;
		case 9:	question9();break;
		case 7:	question7();break;
		case 16:	q16();break;
		case 15:	q15();break;
		case 10:	question10();break;
		case 13:	question13();break;
		case 11:	question11();break;
		case 12:	q12();break;
		case 14:	question14();break;
		case 17:	q17();break;
		case 18:	q18();break;
	//	case 19:	q19();break;
		case 20:	q20();break;

			return EXIT_SUCCESS;
		}
	}
}

