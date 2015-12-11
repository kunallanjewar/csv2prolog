#include<stdio.h>
#include <stdlib.h>

//     INPUT: 
//            string predicate, argument1, argument2, argument3
//     OUTPUT: 
//            predicate(argument1, argument2, argument3).
//

int main () {
  // 1. Parse command-line arguments, open input file
  FILE *input_file, *out_file;
  const char *mode = "r";
  char outFilename[] = "output.pl";
  char ch;
  
  input_file = fopen("input.csv", mode);
  
  if (input_file == NULL) {
    fprintf(stderr, "Can't open input file, input.csv!\n");
    exit(1);
  }
  
    // 2. Read file line-by-line, convert to Prolog facts
  out_file = fopen(outFilename, "w");
  
  if (out_file == NULL) {
    fprintf(stderr, "Can't open output file, output.pl %s!\n", outFilename);
    exit(1);
  }
  printf("Prolog format output of %s file are :\n", outFilename);
   //control variables for while loop and char swap/insert
  int commaCount = 0;
  char par = ')';
  char period = '.';
  int commasPerLine = 0;
  
  //loop print out format and writes to file
  while( ( ch = fgetc(input_file) ) != EOF ){
		
		//test for first comma, its understood file supplied is line by line and has been confirmed
		if (ch == ',' && commaCount == 0 ){
			ch = '(';
			commaCount++;
		}
		//counts to keep track of commas in a line
		else{
			if(ch == ',' && commaCount > 0)
				commaCount++;
		}
							
		//information on what file will look like
		if(ch == '\n'){
			printf("%c",par);
			printf("%c",period);
		}
		printf("%c",ch);
		
		//writing the new prolog file
		if(ch == '\n'){
			fputc(par, out_file);
			fputc(period, out_file);
			//resets for comma control, placing first paran
			commaCount = 0;
		}
		fputc(ch, out_file);
		
		
  }
/*
  //finishes the last display character since it is not read
  printf("%c",par);
  printf("%c", period);
  //writes the last character since it is not read
  fputc(par, out_file);
  fputc(period, out_file);
*/
  /* close the file */
  fclose(input_file);
  fclose(out_file);
  return 0;
}
