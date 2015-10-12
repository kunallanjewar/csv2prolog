/* String functions */
#ifndef STRINGLIB_H
#define STRINGLIB_H

/* checks that all fields are whitespace free (except immediately preceding
 *  a comma) and that no illegal punctuation is present
	int validate_string(const char *);*/
	
int validate_string(const char * input){
	
	/* there is a fix needed, after further testing it seems a comma can be followed by no space in this code */
    /* temp variable for checking each value in char array */
	char check;
	/* check values, should be typedef boolean probably, 0 is good, any other value bad */
	int isGood = 1;
	int isComma = 1;
	int isSpace = 1;
	/* return value, in this case assumed good until an error is found, 0 is good, any other bad.
		in the case of bad values it returns a value that corresponds to error type */
	int badChar = 0;
		
	/* this could be called as field_count to set a value */	
	while(*input != '\0'){
		
		/* sets the temp to a value to check */
		char check = *input;
		/* this line checks for all valid input with the default else declaring a bad character in array*/
		if (check >= 'a' && check <= 'z' || check >= 'A' && check <= 'Z'){
			isGood = 0;
			isComma = 1;
			isSpace = 1;
		}
		/* badChar = 1, this checks the comma value and alerts if there are two in a row */
		else if (check == ','){
			if (isGood == 0 && isComma == 1)
				isComma = 0;
			else{
				badChar = 1;
			}
		}
		/* badChar = 2, this checks for a space and if it was proceeded by a comma */
		else if (check == ' '){
			if (isGood == 0 && isComma == 0)
				isGood = 0;
			else
				badChar = 2;
		}
		/* badChar = 3, default value is only supposed to be choosen on error of not allowed char */
		else{
			badChar = 3;
			printf("There was an error in input\n");
		}
		
		input++;
		
						
	}
	
return badChar;
	
}

/* returns a string containing the next field in a string, then advances
 *  the pointer to the start of the subsequent field */
char * next_field(char **);

/* return the number of fields in the string
	int field_count(const char *); */

int field_count(const char * input){
    
	/* this is the return value for counting the items in the array */
	int counter = 0;
	
	/* this lets us know the end of the char array */
	while(*input != '\0'){
		
		/* this is to increment to the next location */
		input++;
		counter++;
		
	}
	
return counter;
	
}
	
#endif
