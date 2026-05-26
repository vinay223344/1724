/*
 ============================================================================
 Name        : 13_Strings.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. Write a C program to read a line of text from the user and reverse the words in place.
void reverse_string(char str[], int start, int end)
{
	while(start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
void reverse_words()
{
	char str[100]; int len;
	printf("Enter a sentence: ");
	scanf(" %[^\n]s", str);
	len = strlen(str);
	reverse_string(str, 0, len-1);
	int i=0, j=0;
	while(str[j]!='\0')
	{
		j++;
		if(str[j] == ' ')
		{
			reverse_string(str, i, j-1);
			i = j + 1;
		}
	}
	printf("%s \n", str);
}
/* Output: Enter a sentence: This is me
		   me is This */

/* 2. Find and print the longest word by considering the sentence entered by the user.
		Example:
		Input: "I love programming in C"
		Output: programming
*/
void longest_word()
{
    char str[100];
    char longest[100];
    char current[100];
    int i = 0, j = 0;
    int max_len = 0;
    printf("Enter a sentence: ");
    scanf(" %[^\n]", str);
    while (1)
    {
        if (str[i] != ' ' && str[i] != '\0')
        {
            current[j++] = str[i];
        }
        else
        {
            current[j] = '\0';
            if (j > max_len)
            {
                max_len = j;
                strcpy(longest, current);
            }
            j = 0;
        }
        if(str[i] == '\0') break;
        i++;
    }
    printf("Longest word: %s\n", longest);
}
/* Output: Enter a sentence: I love programming
		   Longest word: programming*/

// 3. Write a C program to compare two strings without using any string library functions.
void string_compare()
{
	char str1[100], str2[100];
	int l1, l2;
	printf("Enter string-1: ");
	scanf(" %[^\n]s", str1);
	printf("Enter string-2: ");
	scanf(" %[^\n]s", str2);
	l1 = strlen(str1);
	l2 = strlen(str2);
	int i=0, flag=0;
	if(l1 != l2) {printf("The two strings are not same.\n"); flag = 1;}
	else
	{
		while(i < l1)
		{
			if(str1[i] != str2[i]) {flag = 1; printf("The two strings are not same. (%d)\n", str1[i] - str2[i]); break;}
			i++;
		}
	}
	if(flag == 0)
	{
		printf("The two strings are same.\n");
	}
}
/* Output: Enter string-1: String
   Enter string-2: Strung
   The two strings are not equal. (-12)
   Enter string-1: String
   Enter string-2: String
   The two strings are same.
*/

/* 4. Write a C program to read a string from the user and sort its characters using bubble sort algorithm.
	  Example:
	  Input: "dbca"
      Output: "abcd"
*/
void sort_string()
{
	char str[100]; int len; char temp;
	printf("Enter a sentence: ");
	scanf(" %[^\n]s", str);
	len = strlen(str);
	for(int i=0; i< len; i++)
	{
		for(int j=i+1; j<len; j++)
		{
			if(str[i] > str[j])
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
	printf("Sorted characters of string: %s\n", str);
}
/* Output: Enter a sentence: badc
           Sorted characters of string: abcd
*/

/* 5. Write a C program to read a sentence and replace lowercase characters with uppercase and vice versa.
		Example:
		Input: "Hello World"
		Output: "hELLO wORLD"
*/
void case_convert()
{
	char str[100]; int len; char temp;
	printf("Enter a sentence: ");
	scanf(" %[^\n]s", str);
	len = strlen(str);
	int i=0;
	while(str[i] != '\0')
	{
		if(str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
		else if(str[i] >= 'A' && str[i] <= 'Z') str[i]+=32;
		i++;
	}
	printf("Output: %s", str);
}

//  a = A ^ 32 ****************

/* Output: Enter a sentence: hEllO wORlD
           Output: HeLLo WorLd
*/

/* 6. Write a C program to remove characters from a string except alphabets.
		Example: Input: A3bc4de.com
		Output: Abcdecom
*/
void only_characters()
{
	char str[100]; int len;
	printf("Enter a sentence: ");
	scanf(" %[^\n]s", str);
	len = strlen(str);
	int i=0, j=0;
	char newstr[100];
	while(str[i] != '\0')
	{
		if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) newstr[j++] = str[i];
		i++;
	}
	printf("Output: %s\n", newstr);
}
/* Output: Enter a sentence: A3bc4de.com
		   Output: Abcdecom
*/

/* 7. Write a C program to ask the user to input a string and a substring. Count how many times the substring occurs (even overlapping).
		Example:
		String: "aaa"
		Substring: "aa"
		Output: 2
*/
void substring_count()
{
	char str[100], substr[100];
	int l1, l2;
	printf("Enter a string: ");
	scanf(" %[^\n]s", str);
	printf("Enter substring: ");
	scanf(" %[^\n]s", substr);
	l1 = strlen(str);
	l2 = strlen(substr);
	int i=0, j=0, count=0;
    for (i = 0; i <= l1 - l2; i++)
    	{
        for (j = 0; j < l2; j++)
        {
            if (str[i + j] != substr[j]) {
                break;
            }
        }
        if (j == l2)
        {
            count++;
        }
    }
    printf("Substring occurs %d times\n", count);
}
/* Output:  Enter a string: aaaaa
			Enter substring: aa
			Substring occurs 4 times
*/

/* 8. Write a C program to ask the user to enter a message and a shift value (key), and perform both:
		Encryption & Decryption.
		Example: Input: "abc", key: 2
		Output: Encrypted: "cde"
		Decrypted: "abc"
*/
void msg_encrypt() {
    char msg[100], encrypted[100], decrypted[100];
    int key, i;
    printf("Enter the message: ");
    scanf(" %[^\n]s", msg);
    printf("Enter the shift value (key): ");
    scanf("%d", &key);

    for (i = 0; msg[i] != '\0'; i++) {
        char ch = msg[i];
        if (ch >= 'a' && ch <= 'z') {
            encrypted[i] = ((ch - 'a' + key) % 26) + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z') {
            encrypted[i] = ((ch - 'A' + key) % 26) + 'A';
        }
        else {
            encrypted[i] = ch;
        }
    }
    encrypted[i] = '\0';

    for (i = 0; encrypted[i] != '\0'; i++) {
        char ch = encrypted[i];

        if (ch >= 'a' && ch <= 'z') {
            decrypted[i] = ((ch - 'a' - key + 26) % 26) + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z') {
            decrypted[i] = ((ch - 'A' - key + 26) % 26) + 'A';
        }
        else {
            decrypted[i] = ch;
        }
    }
    decrypted[i] = '\0';
    printf("Encrypted: %s\n", encrypted);
    printf("Decrypted: %s\n", decrypted);
}
/* Output:  Enter the message: abc
			Enter the shift value (key): 2
			Encrypted: cde
			Decrypted: abc
*/

/* 9. Write a C program to ask the user to enters an expression string. Check if an expression contains properly balanced and nested.
		Example: Input: "{[()()]}"
		Output: Balanced
*/
void balance_check() {
    char expr[100], stack[100];
    int top = -1, balanced = 1;

    printf("Enter the expression: ");
    scanf(" %[^\n]s", expr);

    for (int i = 0; expr[i] != '\0'; i++)
    {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack[++top] = ch;
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (top == -1)
            {
                balanced = 0;
                break;
            }
            char topChar = stack[top--];
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '['))
            {
                balanced = 0;
                break;
            }
        }
    }
    if (balanced)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
}
/* Output: Enter the expression: {[()()[]]}
		   Balanced
*/

/* 10. Write a C program to Remove all adjacent duplicate characters recursively from a string.
		Example: Input: "azxxzy”
		Step 1: "azzy" → Step 2: "ay"
		Output: "ay"
*/
void removeDuplicates(char str[])
{
	int i, j;
	int changed = 0;
	char temp[100];
	j = 0;
	int len = strlen(str);
	for (i = 0; i < len; i++)
	{
	    if (i < len - 1 && str[i] == str[i + 1])
	    {
	        changed = 1;
	        while (i < len - 1 && str[i] == str[i + 1])
	        {
	           i++;
	        }
	    }
	    else
	    {
	        temp[j++] = str[i];
	    }
	}
	temp[j] = '\0';
	strcpy(str, temp);
	if (changed)
	{
	    removeDuplicates(str);
	}
}
void remove_duplicates() {
    char str[100];
    printf("Enter the string: ");
    scanf(" %[^\n]s", str);
    removeDuplicates(str);
    printf("Output: %s\n", str);
}
/* Output: Enter the string: azxxzy
		   Output: ay
*/

/* 11. Write a C program to ask the user for a string. Return whether it can become a palindrome by removing at most one character.
		Example:
		Input: "abca"
		Output: Yes (remove 'b' or 'c')
*/
int isPalindrome(char str[], int left, int right)
{
    while (left < right)
    {
        if (str[left] != str[right])
            return 0;

        left++;
        right--;
    }
    return 1;
}
void palindrome_check()
{
	char str[100];
	printf("Enter a string: ");
	scanf(" %s", str);
    	int left = 0, right = strlen(str) - 1;
    	while (left < right)
    	{
        	if (str[left] != str[right])
        	{
            		if (isPalindrome(str, left + 1, right) && isPalindrome(str, left, right - 1))
            		{
                		printf("Yes (remove '%c' or '%c')",  str[left], str[right]);
            		}
            		else if (isPalindrome(str, left + 1, right))
            		{
                		printf("Yes (remove '%c')", str[left]);
            		}
            		else if (isPalindrome(str, left, right - 1))
            		{
                		printf("Yes (remove '%c')", str[right]);
            		}
            		else
            		{
                		printf("No");
            		}

            		return;
        		}

        		left++;
        		right--;
    		}
    	printf("Yes");
}
/* Output: Enter a string: abca
	   Yes (remove 'b' or 'c')
*/

/* 12. Write a C program to find and print the indexes of all vowels and how many times each vowel appears by entering a sentence from the user.
		Example:
		Input: "education"
		Output:
		Vowels: e(0), u(1), a(4), i(6), o(7)
		Counts: a=1, e=1, i=1, o=1, u=1
*/
void vowel_index_count()
{
	char str[100];
	int len;
	printf("Enter a string: ");
	scanf(" %[^\n]s", str);
	len = strlen(str);
	int arr[5] ={0};
	printf("Vowels: ");
	for(int i=0; i<=len; i++)
	{
		switch(str[i])
		{
		case 'a': printf("%c(%d) ", str[i], i); arr[0]++; break;
		case 'A': printf("%c(%d) ", str[i], i); arr[0]++; break;
		case 'e': printf("%c(%d) ", str[i], i); arr[1]++; break;
		case 'E': printf("%c(%d) ", str[i], i); arr[1]++; break;
		case 'i': printf("%c(%d) ", str[i], i); arr[2]++; break;
		case 'I': printf("%c(%d) ", str[i], i); arr[2]++; break;
		case 'o': printf("%c(%d) ", str[i], i); arr[3]++; break;
		case 'O': printf("%c(%d) ", str[i], i); arr[3]++; break;
		case 'u': printf("%c(%d) ", str[i], i); arr[4]++; break;
		case 'U': printf("%c(%d) ", str[i], i); arr[4]++; break;
		}
	}
	printf("\nCounts: a=%d, e=%d, i=%d, o=%d, u=%d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
}
/* Output: Enter a string: EducAtion
			Vowels: E(0) u(2) A(4) i(6) o(7)
			Counts: a=1, e=1, i=1, o=1, u=1
*/

// 13.
void q13()
{
	char str[5];
	strcpy(str, "Hello");
	printf("%s\n", str);
}
/* Output: Hello */
/* Bug: warning: ‘__builtin_memcpy’ writing 6 bytes into a region of size 5 overflows the destination*/

// 14.
void q14()
{
	char *str = "Hello";
	str[0] = 'h';
	printf("%s\n", str);
}
/* Explanation: String is a constant and individual characters in it are immutable. */

// 15.
void q15()
{
	char str1[] = "abc";
	char str2[] = "abc";
	//if (strcmp(str1, str2) = 0) // Assignment operator is used instead of relational
	if (strcmp(str1, str2) == 0) // Outputs 'Equal'
	printf("Equal\n");
}

/* 16. Write a function to replace characters in a string based on a lookup table (mapping old characters to new) */
void replace_characters()
{
	char array1[]= {'A','E','I','O','U','\0'};
	char arr2[] = {'#','-','*','1','h','\0'};
	char str[100];
	int len,length1;
	printf("Enter a string: ");
	scanf(" %[^\n]", str);
	len = strlen(str);
	length1 = strlen(array1);
	for(int i=0; i<=len; i++)
	{
		for(int j=0; j<=length1; j++)
		{
			if(str[i] == array1[j])
			{
				str[i] = arr2[j];
			}
		}
	}
	printf("%s\n", str);
}
/* Output: Enter a string: EDUCATION
		   -DhC#T*1N
*/

/* 17. Write a C program to encode a given string in Base64 format. */
void base64_format()
{
    char str[100];
    char base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int len, i, k;
    unsigned char arr3[3];
    unsigned char arr4[4];
    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);
    printf("Output: ");
    for (i = 0; i < len;)
    {
        int count = 0;
        for (k = 0; k < 3; k++)
        {
            if (i < len)
            {
                arr3[k] = str[i++];
                count++;
            }
            else
            {
                arr3[k] = 0;
            }
        }
        arr4[0] = (arr3[0] & 0xfc) >> 2;
        arr4[1] = ((arr3[0] & 0x03) << 4) + ((arr3[1] & 0xf0) >> 4);
        arr4[2] = ((arr3[1] & 0x0f) << 2) + ((arr3[2] & 0xc0) >> 6);
        arr4[3] = arr3[2] & 0x3f;
        for (k = 0; k < count + 1; k++)
        {
            printf("%c", base64[arr4[k]]);
        }
        while (count++ < 3)
        {
            printf("=");
        }
    }
}
/* Output: Enter a string: Man
	   Output: TWFu
*/

/* 18. Write a program to implement strcmp. Use your string comparison function to verify the string is palindrome or not. */
int mystrcmp(char str1[], char str2[])
{
	int i=0;
	while(str1[i] != '\0' && str2[i] != '\0')
	{
		if(str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (str1[i] - str2[i]);
}
void strcmp_palindrome()
{
	char str[100], rev[100];
	int len;
	printf("Enter a string: ");
	scanf(" %[^\n]s", str);
	len = strlen(str);
	int i=0;
	for(i=0; i<len; i++)
	{
		rev[i] = str[len-i-1];
	}
	rev[i] = '\0';
	if(mystrcmp(str,rev) == 0)
	{
		printf("Given string is a palindrome\n");
	}
	else
	{
		printf("Given string is not a palindrome\n");
	}
}
/* Output: Enter a string: radar
           Given string is a palindrome
*/

/* 19. Write a user-defined function to implement strrchr, which returns the last occurrence of a character in a string. NOTE: use one loop only. */
void mystrchr()
{
	char str[100];
	char c;
	int len;
	printf("Enter a string: ");
	scanf(" %[^\n]s", str);
	printf("Enter a character: ");
	scanf(" %c", &c);
	len = strlen(str);
	int last;
	for(int i=0; i<=len; i++)
	{
		if(str[i] == c)
		{
			last = i;
		}
	}
	printf("Last occurrence of the given character is at index %d\n", last);
}
/* Output: Enter a string: Occurrence
		   Enter a character: e
		   Last occurrence of the given character is at index 9
*/

/* 20. Create user-defined strstr, strchr, atoi(ascii to int), itoa(integer to ascii), strcat. */
void mystrstr()
{
    char s1[100], s2[100];
    int i, j, found = 0;
    printf("Enter a string: ");
    scanf(" %[^\n]", s1);
    printf("Enter a substring: ");
    scanf(" %[^\n]", s2);
    for(i = 0; s1[i] != '\0'; i++)
    {
        for(j = 0; s2[j] != '\0'; j++)
        {
            if(s1[i + j] != s2[j])
                break;
        }
        if(s2[j] == '\0')
        {
            found = 1;
            printf("Substring found at index %d\n", i);
            break;
        }
    }
    if(found == 0)
        printf("Substring not found\n");
}
void myatoi()
{
    char str[100];
    int i = 0, num = 0;
    printf("Enter numeric string: ");
    scanf("%s", str);
    while(str[i] != '\0')
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    printf("Integer value = %d\n", num);
}
void myitoa()
{
    int num, i = 0, j;
    char str[100], temp;
    printf("Enter integer: ");
    scanf("%d", &num);
    if(num == 0)
    {
        str[i++] = '0';
    }
    while(num > 0)
    {
        str[i++] = (num % 10) + '0';
        num /= 10;
    }
    str[i] = '\0';
    for(j = 0; j < i / 2; j++)
    {
        temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
    printf("String = %s\n", str);
}
void mystrcat()
{
    char s1[200], s2[100];
    int i, j;
    printf("Enter first string: ");
    scanf(" %[^\n]", s1);
    printf("Enter second string: ");
    scanf(" %[^\n]", s2);
    i = strlen(s1);
    for(j = 0; s2[j] != '\0'; j++)
    {
        s1[i] = s2[j];
        i++;
    }
    s1[i] = '\0';
    printf("Concatenated string = %s\n", s1);
}
void user_defined()
{
	int option;
	while(1)
	{
		printf("Select an option from the list: \n"
				"1. strstr\n"
				"2. strchr\n"
				"3. atoi(ascii to int)\n"
				"4. itoa(int to ascii)\n"
				"5. strcat\n");
		scanf("%d",&option);
		switch(option)
		{
		case 1: mystrstr(); break;
		case 2: mystrchr(); break;
		case 3: myatoi(); break;
		case 4: myitoa(); break;
		case 5: mystrcat(); break;
		default: printf("Invalid option\n");
		}
	}
}
/* Output:
   Select an option from the list:
	1. strstr
	2. strchr
	3. atoi(ascii to int)
	4. itoa(int to ascii)
	5. strcat
	1
	Enter a string: This is me doing programming
	Enter a substring: doing
	Substring found at index 11
	Select an option from the list:
	1. strstr
	2. strchr
	3. atoi(ascii to int)
	4. itoa(int to ascii)
	5. strcat
	2
	Enter a string: This is program
	Enter a character: i
	Last occurrence of the given character is at index 5
	Select an option from the list:
	1. strstr
	2. strchr
	3. atoi(ascii to int)
	4. itoa(int to ascii)
	5. strcat
	3
	Enter numeric string: 1234
	Integer value = 1234
	Select an option from the list:
	1. strstr
	2. strchr
	3. atoi(ascii to int)
	4. itoa(int to ascii)
	5. strcat
	4
	Enter integer: 1234
	String = 1234
	Select an option from the list:
	1. strstr
	2. strchr
	3. atoi(ascii to int)
	4. itoa(int to ascii)
	5. strcat
	5
	Enter first string: abc
	Enter second string: def
	Concatenated string = abcdef
*/

/* 22. Remove all occurrences of s2 in s1 */
void removeSubstring()
{
    char s1[200], s2[100];
    printf("Enter main string: ");
    scanf(" %[^\n]s", s1);
    printf("Enter substring: ");
    scanf(" %[^\n]s", s2);
    char result[200];
    int i = 0, j = 0, k, match;
    while (s1[i] != '\0')
    {
        match = 1;
        for (k = 0; s2[k] != '\0'; k++)
        {
            if (s1[i + k] != s2[k])
            {
                match = 0;
                break;
            }
        }
        if (match)
        {
            i += k;
        }
        else
        {
            result[j++] = s1[i++];
        }
    }
    result[j] = '\0';
    printf("Output: %s", result);
}

/* 23. Hide all occurrences of s2 in s1 */
void hideSubstring()
{
    char s1[200], s2[100];
    printf("Enter main string: ");
    scanf(" %[^\n]s", s1);
    printf("Enter substring: ");
    scanf(" %[^\n]s", s2);
    int i, j, match;
    for (i = 0; s1[i] != '\0'; i++)
    {
        match = 1;
        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i + j] != s2[j])
            {
                match = 0;
                break;
            }
        }
        if (match)
        {
            for (j = 0; s2[j] != '\0'; j++)
            {
                s1[i + j] = '*';
            }
        }
    }
    printf("Output: %s", s1);
}
/* Output: Enter main string: abcxyzabcxyz
	   Enter substring: xyz
	   Output: abc***abc*** 
*/

/* 24. Replace all occurrences of s2 with reverse equivalent */
void replaceReverse()
{
    char s1[200], s2[100];
    printf("Enter main string: ");
    scanf("%s", s1);
    printf("Enter substring: ");
    scanf("%s", s2);
    char rev[100];
    int i, j, len = 0, match;
    while (s2[len] != '\0')
        len++;
    for (i = 0; i < len; i++)
        rev[i] = s2[len - 1 - i];
    rev[len] = '\0';
    for (i = 0; s1[i] != '\0'; i++)
    {
        match = 1;
        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i + j] != s2[j])
            {
                match = 0;
                break;
            }
        }
        if (match)
        {
            for (j = 0; j < len; j++)
            {
                s1[i + j] = rev[j];
            }
        }
    }
    printf("Output: %s", s1);
}
/* Outptut: Enter main string: abcxyzabcxyz
            Enter substring: xyz
	    Output: abczyxabczyx
*/

/* 25. Explain the use of const type-qualifier. */
/* The const type-qualifier in C is used to make a variable read-only. Once a const variable is initialized, its value cannot be changed directly.
   Uses: 1. Prevent accidental modification of variables.
	 2. Improve program safety and readability.
	 3. Useful for constants like PI etc.
*/
void q25()
{
    const int x = 10;
    // x = 20;   // error: assignment of read-only variable ‘x’
    printf("%d", x);
}


/* 26. Justify the modification (writing) on const-qualified variable */
/* Direct modification of a const variable is not allowed because the compiler treats it as read-only. However, modification may be attempted using pointers and type casting, but it leads to undefined behavior. */
void q26()
{
    const int x = 10;
    int *p = (int *)&x;
    *p = 20;
    printf("%d", x);
}
/* Output: 20 */

/* 27. Can a global const-qualified variable be modified through pointer? Why? */
/* No, generally a global const-qualified variable cannot be safely modified through a pointer.
   Global const variables are usually stored in the read-only memory section of the program.
   Attempting to modify them may cause: Runtime error or Undefined behavior
*/
const int x = 10;
void q27()
{
    int *p = (int *)&x;
    *p = 50;   // Unsafe
    printf("%d", x);
}
/* Output: (blank) */

/* 28. If above answer is no, then what should we do to allow the modification? */
/* To allow modification, do not declare the variable as const.  
   Volatile can be used when occasional modification is required. */

/* 29. Count the number of words in each string */
void word_count()
{
	char str[100];
	int len, count=1, i=0;
	printf("Enter a string: ");
	scanf(" %[^\n]s", str);
	len = strlen(str);
	for(i=0; i<=len; i++)
	{
		if(str[i] == ' ' || str[i] == '\t')
		{
			count++;
		}
	}
	printf("Number of words in the given string: %d\n", count);
}
/* Output: Enter a string: This is me
		   Number of words in the given string: 3
*/

/* 30. Remove the n-th word in each string. */
void remove_nth_word()
{
	char str[200], result[200];
    	int n, word = 1, i = 0, j;
    	printf("Enter a string: ");
    	scanf(" %[^\n]s", str);
    	printf("Enter word number to remove: ");
    	scanf("%d", &n);
    	while (str[i] != '\0' && str[i] != '\n')
    	{
        	while (str[i] == ' ')
        	{
            		strcat(result, " ");
            		i++;
        	}
        	j = i;
        	while (str[j] != ' ' && str[j] != '\0' && str[j] != '\n')
            		j++;
        	if (word != n)
        	{
            		int k, len = strlen(result);
            		for (k = i; k < j; k++)
            		{
            			result[len++] = str[k];
            		}
            		result[len] = '\0';
        	}
        	i = j;  
        	word++;
    	}
    	printf("%s", result);
}
/* Output: Enter a string: This is me doing C
	   Enter word number to remove: 3
	   This is  doing C
*/

/* 31. Count and print the words having consecutive vowels. */
void consecutive_vowels()
{
    char str[200], word[50];
    int i = 0, j = 0, count = 0, found;
    printf("Enter a string: ");
    scanf(" %[^\n]s", str);
    printf("Words with consecutive vowels:\n");
    while (1)
    {
        if (str[i] != ' ' && str[i] != '\0' && str[i] != '\n')
        {
            word[j++] = str[i];
        }
        else
        {
            word[j] = '\0';
            found = 0;
            for (int k = 0; word[k + 1] != '\0'; k++)
            {
                char ch1 = tolower(word[k]);
                char ch2 = tolower(word[k + 1]);

                if ((ch1 == 'a' || ch1 == 'e' || ch1 == 'i' || ch1 == 'o' || ch1 == 'u') &&
                    (ch2 == 'a' || ch2 == 'e' || ch2 == 'i' || ch2 == 'o' || ch2 == 'u'))
                {
                    found = 1;
                    break;
                }
            }
            if (found)
            {
                printf("%s\n", word);
                count++;
            }
            j = 0;
            if (str[i] == '\0')
                break;
        }
        i++;
    }
    printf("Count: %d", count);
}
/* Output: Enter a string:  Moon is beautiful
	   Words with consecutive vowels:
	   Moon
 	   beautiful
	   Count: 2
*/

/* 32. Supply two strings. Verify, if the 1st string, is a circular permutation of another string. */
void circular_permutation()
{
    char str1[100], str2[100];
    int match, found = 0;
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    if (l1 != l2)
    {
        printf("No");
    }
    for (int i = 0; i < l1; i++)
    {
        match = 1;
        for (int j = 0; j < l1; j++)
        {
            if (str1[(j + i) % l1] != str2[j])
            {
                match = 0;
                break;
            }
        }
        if (match)
        {
            found = 1;
            break;
        }
    }
    if (found)
        printf("Yes");
    else
        printf("No");
}

int main() {
	int n;
	while(1)
	{
		printf("Enter the question number (1-32): ");
		scanf("%d", &n);
		switch(n)
		{
		case 1: reverse_words(); break;
		case 2: longest_word(); break;
		case 3: string_compare(); break;
		case 4: sort_string(); break;
		case 5: case_convert(); break;
		case 6: only_characters(); break;
		case 7: substring_count(); break;
		case 8: msg_encrypt(); break;
		case 9: balance_check(); break;
		case 10: remove_duplicates(); break;
		case 11: palindrome_check(); break;
		case 12: vowel_index_count(); break;
		case 13: q13(); break;
		case 14: q14(); break;
		case 15: q15(); break;
		case 16: replace_characters(); break;
		case 17: base64_format(); break;
		case 18: strcmp_palindrome(); break;
		case 19: mystrchr(); break;
		case 20: user_defined(); break;
		case 22: removeSubstring(); break;
		case 23: hideSubstring(); break;
		case 24: replaceReverse(); break;
		case 25: q25(); break;
		case 26: q26(); break;
		case 27: q27(); break;
		case 29: word_count(); break;
		case 30: remove_nth_word(); break;
		case 31: consecutive_vowels(); break;
		case 32: circular_permutation(); break;
		default: printf("Invalid Choice");
		}
	}
}
