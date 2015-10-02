/* String functions */
#ifndef STRINGLIB_H
#define STRINGLIB_H

/* checks that all fields are whitespace free (except immediately preceding
 *  a comma) and that no illegal punctuation is present */
int validate_string(const char *);

/* returns a string containing the next field in a string, then advances
 *  the pointer to the start of the subsequent field */
char * next_field(char **): 

/* return the number of fields in the string */
int field_count(const char *);

#endif
