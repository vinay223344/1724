/*
 ============================================================================
 Name        : 14_Structures.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include<stdint.h>
#include<ctype.h>
#include<string.h>

/* 1. Create a structure to specify data on students given below:
   Roll number, Name, Department, Course, Year of joining
   Assume that there are not more than 450 students in the college.
  (a) Write a function to print names of all students who joined in a particular year.
  (b) Write a function to print the data of a student whose roll numbers are specified.
*/
#include <stdio.h>

void student_data()
{
    int year, roll;
    struct student
    {
        int roll_no;
        char name[20];
        char dept[20];
        char course[20];
        int yearofjoining;
    }s[5] = {0};
    s[0] = (struct student){220249, "Mokshagna", "EEE", "MCI", 2022};  /* Random data gnerate */
    s[1] = (struct student){220244, "Jamshetji", "ECE", "CMM", 1882};
    s[2] = (struct student){220210, "Dhirubhai", "ME", "FMM", 1922};
    s[3] = (struct student){220296, "Donald", "PLT", "Politics", 1963};
    s[4] = (struct student){220452, "Elon", "PLT", "Politics", 2022};
    printf("Enter a year to get student names: ");
    scanf("%d", &year);
    for (int i = 0; i < 5; i++)
    {
        if (s[i].yearofjoining == year)
        {
            printf("%s\n", s[i].name);
        }
    }
    printf("Specify a roll number to get student data: ");
    scanf("%d", &roll);
    for (int i = 0; i < 5; i++)
    {
        if (s[i].roll_no == roll)
        {
            printf("Name: %s\n", s[i].name);
            printf("Department: %s\n", s[i].dept);
            printf("Course: %s\n", s[i].course);
            printf("Year of Joining: %d\n", s[i].yearofjoining);
        }
    }
}



/* 2. Create a structure to specify data of customers in a bank. The data to be stored is:
	• Account number
	• Name
	• Balance in account.
	Assume a maximum of 200 customers in the bank.
	(a) Write a function to print the Account number and name of each customer with
	balance below Rs. 100.
	(b) For withdrawal/deposit requests (fields: Acct. no, amount, code → 1 for deposit,
	0 for withdrawal),
	write a program to update balance. If on withdrawal the balance falls below Rs.100,
	display: “The balance is insufficient for the specified withdrawal”.
*/
struct customer
{
	int account_number;
	char name[20];
	float balance;
}c[200] = {0};
void below_100(struct customer c[])
{
	for(int i=0; i<200; i++)
	{
		if(c[i].balance < 100)
		{
			printf("Account Number: %d\n", c[i].account_number);
			printf("Name: %s\n", c[i].name);
		}
	}
}
void transaction(struct customer c[])
{
	int account_no, amount, code, x;
	printf("Enter account number: ");
	scanf("%d", &account_no);
	printf("Enter amount: ");
	scanf("%d", &amount);
	printf("Enter code: 1 -> deposit, 0 -> withdrawal: ");
	scanf("%d", &code);
	if(code == 1)
	{
		for(int i=0; i<200; i++)
		{
			if(account_no == c[i].account_number)
			{
				c[i].balance += amount;
				x=i;
				break;
			}
		}
	}
	else
	{
		for(int i=0; i<200; i++)
		{
			if(account_no == c[i].account_number)
			{
				if((c[i].balance -= amount) < 100)
				{
					printf("The amount is insufficient for specified withdrawal. ");
				}
				else
				{
					c[i].balance -= amount;
					x=i;
					break;
				}
			}
		}
	}
	printf("Balance: %f\n", c[x]. balance);
}
void bank_customer()
{
	c[1] = (struct customer){22098, "Mokshagna", 10.500};
	c[32] = (struct customer){27598, "Dhirubhai", 10005.00};
	c[56] = (struct customer){42098, "Jamshetji", 1005.00};
	c[101] = (struct customer){22788, "Elon", 105.000};
	below_100(c);
	transaction(c);
}

/* 3. An automobile company has serial number for engine parts starting from AA0 to
	FF9. The other characteristics of parts are year of manufacture, material and
	quantity manufactured.
	(a) Define a structure to store this information.
	(b) Write a program to retrieve information on parts with serial numbers between
	BB1 and CC6.
*/
struct automobile
{
	int serial_number;
	int year_of_manufacture;
	char material[20];
	int quantity;
}a[50];
void automobile_engine()
{
	a[0] = (struct automobile){0XAA1, 2020, "Iron", 20};
	a[1] = (struct automobile){0XBB8, 2026, "Aluminum", 28};
	a[2] = (struct automobile){0XCC0, 2023, "Copper", 21};
	for(int i=0; i<3; i++)
	{
		if(a[i].serial_number >= 0XBB1 && a[i].serial_number <= 0XCC6)
		{
			printf("Serial Number: %X\n", a[i].serial_number);
			printf("Year of manufacture: %d\n", a[i].year_of_manufacture);
			printf("Material: %s\n", a[i].material);
			printf("Quantity manufactures: %d\n", a[i].quantity);
			printf("----------------------------------\n");
		}
	}
}

/* 4. A record contains name of cricketer, his age, number of test matches that he has
	played and the average runs that he has scored in each test match. Create an array
	of structures to hold records of 20 such cricketers and then write a program to read
	and arrange records in ascending order by average runs.
*/
struct cricketer
{
	char name[20];
	int age;
	int number_of_tests;
	int average_score;
}k[4];
void cricketer_score()
{
	k[0] = (struct cricketer) {"Kohli", 37, 50, 70};
	k[1] = (struct cricketer) {"Dhoni", 46, 70, 40};
	k[2] = (struct cricketer) {"Gambhir", 57, 60, 68};
	k[3] = (struct cricketer) {"Sunil", 87, 89, 12};
	for(int i=0; i<4; i++)
	{
		for(int j=i+1; j<4; j++)
		{
			if(k[i].average_score > k[j].average_score)
			{
				int temp = k[i].average_score;
				k[i].average_score= k[j].average_score;
				k[j].average_score= temp;
			}
		}
	}
	printf("Sorted Records: \n");
	for(int i=0; i<4; i++)
	{
		printf("Name: %s\n", k[i].name);
		printf("Age: %d\n", k[i].age);
		printf("Number of test matches: %d\n", k[i].number_of_tests);
		printf("Average runs scored: %d\n", k[i].average_score);
		printf("------------------------------\n");
	}
}


/* 5. Define a structure Employee containing:
	• Employee code
	• Name
	• Date of joining
	Write a program to enter data into an array of employees. Ask user to input current
	date, then display names of employees whose tenure is ≥ 3 years.
*/
#include <stdio.h>
int isLeap(int year)
{
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}
struct date
{
    int day;
    int month;
    int year;
};
struct employee
{
    int employee_code;
    char name[20];
    struct date doj;
}emp[20];
void employee_details()
{
	emp[0] = (struct employee){1234, "Mokshagna", {15,12,2022}};
	emp[1] = (struct employee){1256, "KVR", {10,6,2024}};
	emp[2] = (struct employee){1458, "Pakshi", {25,9,2025}};
	emp[3] = (struct employee){2584, "VRD", {26,9,2019}};
    struct date current;
    int days, months, years;
    int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printf("Enter Current Date (dd mm yyyy): ");
    scanf("%d %d %d", &current.day, &current.month, &current.year);
    printf("Employees with tenure >= 3 years:\n");
    for(int i = 0; i < 4; i++)
    {
        int years = current.year - emp[i].doj.year;
        for(int i = 0; i < 4; i++)
        {
            /*if (emp[i].doj.year > current.year || (emp[i].doj.year == current.year && emp[i].doj.month > current.month) || (emp[i].doj.year == current.year && emp[i].doj.month == current.month && emp[i].doj.day > current.day))
           	{
           	    int t;
           	    t = emp[i].doj.day; emp[i].doj.day = current.day; current.day = t;
           	    t = emp[i].doj.month; emp[i].doj.month = current.month; current.month = t;
           		t = emp[i].doj.year; emp[i].doj.year = current.year; current.year = t;
           	}*/
           	// Calculating dates
           	if (current.day < emp[i].doj.day)
           	{
           	    current.month--;
           	    if (current.month == 2 && isLeap(current.year))
           		days = current.day + 29 - emp[i].doj.day;
           	    else
           		days = current.day + mon[current.month - 1] - emp[i].doj.day;
           	}
           	else
           	{
           	    days = current.day - emp[i].doj.day;
           	}
           	//Calculating months
           	if (emp[i].doj.month < current.month)
           	{
           		current.year--;
           		months = current.month + 12 - emp[i].doj.month;
           	}
          	else
           	{
           	    months = current.month - emp[i].doj.month;
           	}
          	years = current.year - emp[i].doj.year;
        }
        if(years >= 3)
        {
            printf("%s\n", emp[i].name);
        }
    }
}

/* 6. Create a structure Library to hold:
	• Accession number
	• Title of the book
	• Author name
	• Price
	• Flag (issued or not)
	Write a menu-driven program with options:
	a. Add book information
	b. Display book information
	c. List all books of a given author
	d. List title of a specified book
	e. Count books in the library
	f. List books in order of accession number
	g. Exit
*/
int i = 0;
struct library
{
	int accession_number;
	char title[20];
	char author[20];
	float price;
	char flag; // 0-not issued, 1-issued
}l[10];
void add_book(int i)
{
	printf("Enter accession number: ");
	scanf("%d", &l[i].accession_number);

	printf("Enter title of the book: ");
	scanf("%s", l[i].title);

	printf("Enter name of the author: ");
	scanf("%s", l[i].author);

	printf("Enter price of the book: ");
	scanf("%.2f", l[i].price);

	printf("Enter status of book(1->issued, 0->not issued): ");
	scanf("%d", l[i].flag);
}
void display()
{
	int number;
	printf("Enter accession number: ");
	scanf("%d", &number);
	int found=0;
	for(int j=0; j<=i; i++)
	{
		if(number == l[j].accession_number)
		{
			found = 1;
			printf("Accession Number: %d\n", l[j].accession_number);
			printf("Title of the book: %s\n", l[j].title);
			printf("Name of the author: %s\n", l[j].author);
			printf("Price of the book: %.2f\n", l[j].price);
			printf("Issue status: %d\n", l[j].flag);
		}
	}
	if(found == 0)
	{
		printf("Invalid number");
	}
}
void list_books()
{
	char author[20];
	printf("Enter name of the author: ");
	scanf("%s", author);
	int found=0;
	for(int j=0; j<=i; i++)
	{
		if(author == l[j].author)
		{
			found = 1;
			printf("%s\n", l[j].title);
		}
	}
	if(found == 0)
	{
		printf("Invalid number");
	}
}
void list_title()
{
	int number;
	printf("Enter accession number: ");
	scanf("%s", &number);
	int found=0;
	for(int j=0; j<=i; i++)
	{
		if(number == l[j].accession_number)
		{
			found = 1;
			printf("%s\n", l[j].title);
		}
	}
	if(found == 0)
	{
		printf("Invalid number");
	}
}
void count_books()
{
	printf("No. of books: %d", i);
}
void sort_books()
{
	for(int j=0; j<=i; j++)
	{
		for(int k=i; k<=j; k++)
		{
			int temp = l[k].accession_number;
			l[k].accession_number=l[i].accession_number;
			l[i].accession_number=temp;
		}
	}
}
void library()
{
	int choice;
	l[i] = (struct library){123,"Let us C", "Yashwanth Kanetkar", 220, 0};
	l[i+1] = (struct library){345,"C in Depth", "Srivastav", 400, 1};
	l[i+2] = (struct library){780,"Let us C++", "Yashwanth", 120, 0};
	l[i+3] = (struct library){190,"Vemana Shathakam", "Vemana",900, 0};
	printf("1. Add book information\n"
			"2. Display book information\n"
			"3. List all books of a given number\n"
			"4. List title of a specified book\n"
			"5. Count books in the library\n"
			"6. List books in order of accession number\n"
			"7. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	switch(choice)
	{
	case 1: add_book(i); break;
	case 2: display(); break;
	case 3: list_books(); break;
	case 4: list_title(); break;
	case 5: count_books(); break;
	case 6: sort_books(); break;
	case 7: exit(0);
	}
}

/* 7. Write a c program to Create an array of four function pointers where each pointer
	should point to a different function. Each function should take two integers and
	return a float. Using a loop, call function using the addresses present in the array.
*/
float add(int a, int b)
{
	return a+b;
}
float sub(int a, int b)
{
	return a-b;
}
float mul(int a, int b)
{
	return a*b;
}
float div(int a, int b)
{
	return (float)a/b;
}
void function_pointers()
{
	int a=10, b=5;
	float (*func[4])(int,int) = {add, sub, mul, div};
	printf("Addition: %.2f\n", func[0](a,b));
	printf("Subtraction: %f\n", func[1](a,b));
	printf("Multiplication: %f\n", func[2](a,b));
	printf("Division: %f\n", func[3](a,b));
}

/* 9. Define a structure Date with members stored as bit fields:
• Day → 5 bits
• Month → 4 bits
• Year → 12 bits
Write a program to read date of joining of 10 employees and display them in
ascending order of year.
*/
struct emp
{
	uint32_t day: 5;
	uint16_t month: 4;
	int year: 12;
}e[10];
void read_print()
{
	for(int i=0;i<3;i++)
	{
		for(int j=i+1;j<4;j++)
		{
			if(e[i].year > e[j].year)
			{
				int temp = e[i].year;
				e[i].year = e[j].year;
				e[j].year = temp;
			}
		}
	}
	for(int i=0;i<4;i++)
	{
		printf("Day: %d\n", e[i].day);
		printf("Month: %d\n", e[i].month);
		printf("Year: %d\n", e[i].year);
		printf("---------------\n");
	}
}
void employee_bitfields()
{
	e[0] = (struct emp){15,12,2025};
	e[1] = (struct emp){10,6,2024};
	e[2] = (struct emp){25,9,2025};
	e[3] = (struct emp){26,9,2019};
	read_print();
}

/* 10. Write a program to read and store information about insurance policy holder. The
	information contains details like gender, whether the holder is minor/major, policy
	name and duration of the policy. Make use of bit-fields to store this information.
*/
struct insurance_holder
{
	int gender: 1;  //0->Male, 1-> Female
	int type: 1; //0->Minor, 1->Major
	char name[20];
	int duration: 8;
}ih[10];
void insurance_policy()
{
	ih[0] = (struct insurance_holder){0, 0, "Mokshagna", 38};
	ih[1] = (struct insurance_holder){0, 1, "KVR", 10};
	ih[2] = (struct insurance_holder){1, 1, "Pakshi", 20};
	ih[3] = (struct insurance_holder){0, 1, "VRD", 100};
	for(int i=0;i<4;i++)
	{
		printf("Name: %s\n", ih[i].name);
		printf("Gender: %s\n", ih[i].gender ? "Female" : "Male");
		printf("Category: %s\n", ih[i].type ? "Major" : "Minor");
		printf("Duration: %d\n", ih[i].duration);
		printf("---------------------\n");
	}
}

/* 11. Declare a structure Student containing:
	• Name
	• Age
	• Address
	Create and initialize 3 structure variables.
	Define a function that converts all names to uppercase. Print updated records.
*/
struct stu
{
	char name[20];
	int age;
	char address[30];
}st[20];
void student_uppercase()
{
	st[0] = (struct stu){"Mokshagna", 22, "Malkajgiri"};
	st[1] = (struct stu){"Revanth", 47, "Panjagutta"};
	st[2] = (struct stu){"Narendra", 78, "Delhi"};
	st[3] = (struct stu){"Didi", 80, "Koklata"};
	for(int i=0; i<4; i++)
	{
		for(int j=0; st[i].name[j]; j++)
		{
			if(st[i].name[j]>='a' && st[i].name[j]<='z')
			{
				st[i].name[j] = st[i].name[j] - 32;
			}
		}
		printf("Name: %s\n", st[i].name);
		printf("Age: %d\n", st[i].age);
		printf("Address: %s\n", st[i].address);
		printf("--------------------\n");
	}
}
/* Output:
		Name: MOKSHAGNA
		Age: 22
		Address: Malkajgiri
		--------------------
		Name: REVANTH
		Age: 47
		Address: Panjagutta
		--------------------
		Name: NARENDRA
		Age: 78
		Address: Delhi
		--------------------
		Name: DIDI
		Age: 80
		Address: Koklata
		--------------------
*/

/* 12. Write a C program to use an enum for traffic light states (RED, YELLOW, GREEN) and
	simulate a traffic signal system using switch-case and transition every N seconds.
*/
#include<unistd.h>
enum traffic
{
	red, yellow, green
};
void traffic_light()
{
	enum traffic light = red;
	while(1)
	{
		switch(light)
		{
		case red: printf("STOP\n"); sleep(2);light=green; break;
		case yellow: printf("SLOW DOWN\n");  sleep(2);light=red;break;
		case green: printf("GO\n"); sleep(2);light=yellow; break;
		}
	}
}

/* 13. Create an enum Permission { READ=1, WRITE=2, EXEC=4 };
	Write a program to combine permissions using | (bitwise OR), and check
	permissions using &.
*/
enum permission { READ =1, WRITE =2, EXEC =4};
void permissions()
{
	int permission = (READ | WRITE) ;
	if(permission & READ) { printf("Read permssion is there"); }
	else if(permission & WRITE) { printf("Write permission is there");
	}
}

//#pragma pack(1)
/* 15. Define a struct and a union with same members (int, float, char).
	   Write a program to print their sizes and explain difference in memory allocation.
*/
void struct_union()
{
	struct
	{
		char c;
		int a;
		float b;
		//char c;
	}structure;
	union
	{
		int x;
		float y;
		char z;
	}union_;
	printf("Size of structure: %ld\n", sizeof(structure));
	printf("Size of union: %ld\n", sizeof(union_));
}

/* 16 */
struct student { int r; float m; };
void q16()
{
	struct student v;
	printf("%d\n", sizeof(v));
	printf("%d\n", sizeof(struct student));
}

/* 17 */
struct A { int x; int y; };
void q17()
{
	struct A v = {10,20};
	struct A *p = &v;
	printf("%d %d\n", p->x, p->y);
}

/* 18 */
struct B { int x; int y; int *p; };
void q18() {
	struct B m= {10,20};
	m.p = &m.x;
	*(m.p) = 100;
	m.p = &m.y;
	*(m.p) = 200;
	printf("%d %d\n", m.x, m.y);
}

/* 19 */
/*
struct C { int x = 10; int y = 20; } mchip;
void q19()
{
	printf("%d %d\n", mchip.x, mchip.y);
}
*/
// Strucutre members can't be initialized inside structure definition

struct st { int a:5; char b:3; int c:2; };
void q20()
{
	struct st mchip;
	printf("%d\n", sizeof(mchip));
	/*printf("%u\n", & mchip.a);
	printf("%u\n", & mchip.b);
	printf("%u\n", & mchip.c);*/
}
// Bit field address cannot be accessed or printed (since they are individual bits and address exists for bytes)

int main() {
	int n;
	while(1)
	{
		printf("Enter the question number (1-20): ");
		scanf("%d", &n);
		switch(n)
		{
		case 1: student_data(); break;
		case 2: bank_customer(); break;
		case 3: automobile_engine(); break;
		case 4: cricketer_score(); break;
		case 5: employee_details(); break;
		case 6: library(); break;
		case 7: function_pointers(); break;
		//case 8: msg_encrypt(); break;
		case 9: employee_bitfields(); break;
		case 10: insurance_policy(); break;
		case 11: student_uppercase(); break;
		case 12: traffic_light(); break;
		//case 13: q13(); break;
		//case 14: q14(); break;
		case 15: struct_union(); break;
		case 16: q16(); break;
		case 17: q17(); break;
		case 18: q18(); break;
		//case 19: q19(); break;
		case 20: q20(); break;
		/*case 27: q27(); break;*/
		}
	}
}
