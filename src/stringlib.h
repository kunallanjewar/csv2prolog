/* String functions */ 
2 #ifndef STRINGLIB_H 
3 #define STRINGLIB_H 
4 
 
5 /* checks that all fields are whitespace free (except immediately preceding 
6  *  a comma) and that no illegal punctuation is present 
7 	int validate_string(const char *);*/ 
8 	 
9 int validate_string(const char * input){ 
10 	 
11 	/* there is a fix needed, after further testing it seems a comma can be followed by no space in this code */ 
12     /* temp variable for checking each value in char array */ 
13 	char check; 
14 	/* check values, should be typedef boolean probably, 0 is good, any other value bad */ 
15 	int isGood = 1; 
16 	int isComma = 1; 
17 	int isSpace = 1; 
18 	/* return value, in this case assumed good until an error is found, 0 is good, any other bad. 
19 		in the case of bad values it returns a value that corresponds to error type */ 
20 	int badChar = 0; 
21 		 
22 	/* this could be called as field_count to set a value */	 
23 	while(*input != '\0'){ 
24 		 
25 		/* sets the temp to a value to check */ 
26 		char check = *input; 
27 		/* this line checks for all valid input with the default else declaring a bad character in array*/ 
28 		if (check >= 'a' && check <= 'z' || check >= 'A' && check <= 'Z'){ 
29 			isGood = 0; 
30 			isComma = 1; 
31 			isSpace = 1; 
32 		} 
33 		/* badChar = 1, this checks the comma value and alerts if there are two in a row */ 
34 		else if (check == ','){ 
35 			if (isGood == 0 && isComma == 1) 
36 				isComma = 0; 
37 			else{ 
38 				badChar = 1; 
39 			} 
40 		} 
41 		/* badChar = 2, this checks for a space and if it was proceeded by a comma */ 
42 		else if (check == ' '){ 
43 			if (isGood == 0 && isComma == 0) 
44 				isGood = 0; 
45 			else 
46 				badChar = 2; 
47 		} 
48 		/* badChar = 3, default value is only supposed to be choosen on error of not allowed char */ 
49 		else{ 
50 			badChar = 3; 
51 			printf("There was an error in input\n"); 
52 		} 
53 		 
54 		input++; 
55 		 
56 						 
57 	} 
58 	 
59 return badChar; 
60 	 
61 } 
62 
 
63 /* returns a string containing the next field in a string, then advances 
64  *  the pointer to the start of the subsequent field */ 
65 char * next_field(char **); 
66 
 
67 /* return the number of fields in the string 
68 	int field_count(const char *); */ 
69 
 
70 int field_count(const char * input){ 
71      
72 	/* this is the return value for counting the items in the array */ 
73 	int counter = 0; 
74 	 
75 	/* this lets us know the end of the char array */ 
76 	while(*input != '\0'){ 
77 		 
78 		/* this is to increment to the next location */ 
79 		input++; 
80 		counter++; 
81 		 
82 	} 
83 	 
84 return counter; 
85 	 
86 } 
87 	 
88 #endif 
