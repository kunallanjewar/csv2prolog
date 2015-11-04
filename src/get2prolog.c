#include<stdio.h>
#include <stdlib.h>

int main () {
  // 1. Parse command-line arguments, open input file
FILE *input_file, *out_file;
char *mode = "r";
char outFilename[] = "output.csv";

input_file = fopen("input.csv", mode);

if (input_file == NULL) {
  fprintf(stderr, "Can't open input file, input.csv!\n");
  exit(1);
}

out_file = fopen(outFilename, "w");

if (out_file == NULL) {
  fprintf(stderr, "Can't open output file, output.csv %s!\n", outFilename);
  exit(1);
}
  // 2. Read file line-by-line, convert to Prolog facts
printf("Prolog format output of %s file are :\n", file_name);
   while( ( ch = fgetc(input_file) ) != EOF )
      printf("%c",ch);
  
  /* close the file */
  fclose(input_file);
  // 3. Verify Prolog format, write to output file
  return 0;
}
