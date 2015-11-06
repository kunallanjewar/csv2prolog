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
  char outFilename[] = "output.csv";
  char ch;
  
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
  while( ( ch = fgetc(input_file) ) != EOF )
     printf("%c",ch);
  
  // 3. Verify Prolog format, write to output file
 

  /* close the file */
  fclose(input_file);
  fclose(out_file);
  return 0;
}
