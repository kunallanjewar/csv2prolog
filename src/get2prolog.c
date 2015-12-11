#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//     INPUT: 
//            string predicate, argument1, argument2, argument3
//     OUTPUT: 
//            predicate(argument1, argument2, argument3).
//

int main () {
  // 1. Parse command-line arguments, open input file
  FILE *input_file, *out_file;
  const char *mode = "r";
  char outFilename[] = "output.csv";
  char ch;
  //for customization we could make this an arg ([72]) so we could manually set this value at start
  char byLine[72];
  //char temp[72];
  
  input_file = fopen("input.csv", mode);
  
  if (input_file == NULL) {
    fprintf(stderr, "Can't open input file, input.csv!\n");
    exit(1);
  }
  
    // 2. Read file line-by-line, convert to Prolog facts
  out_file = fopen(outFilename, "w");
  
  if (out_file == NULL) {
    fprintf(stderr, "Can't open output file, output.csv %s!\n", outFilename);
    exit(1);
  }
  printf("Prolog format output of %s file are :\n", outFilename);
  
  //control variables and psuedo constants
  int commaCount = 0;
  char par = ')';
  char period = '.';
  char * paranPeriod = ").";
  char control = '\n';
  int carReturn = '\r';
  
  //beginning of the work in a loop to go through all lines of the file
  while (fgets(byLine,sizeof(byLine),input_file) != NULL){
	
	//iteration control for reading each character in a string
	char *ptr = byLine;
	//these create a values for each line read to be used with string copy
	int adjustedLength = strlen(byLine) + strlen(paranPeriod);
	int testLength = strlen(byLine);
	int insertLocation = testLength - 1;
	
	//does the work to place the first paran, may need some optimization. was also going to be used
	//for total comma count for other purposes. works so left it this way
	while (*ptr != '\0'){
		if (*ptr == ',' && commaCount == 0){
			*ptr = '(';
			commaCount++;
		}
		ptr++;
	}
	
	//temp string used to store string copy of final product to be output
	char* output = (char*)malloc(adjustedLength);
	
	strncpy(output, byLine, insertLocation);
	output[insertLocation] = '\0';
	strcat(output, paranPeriod);
	strcat(output, byLine + insertLocation);
	
	//write to screen and file
	printf("%s", output);
	fputs(output, out_file);
	
	//reset comma count for next line to make first paran
	commaCount = 0;
	//clearing the memory of the output string, since this is in a loop even more important
	free(output);
  }
  //covers end of file to add the paran and period
  //printf("%c",par);
  //printf("%c", period);
  //fputc(par, out_file);
  //fputc(period, out_file);

  /* close the file */
  fclose(input_file);
  fclose(out_file);
  return 0;
}
