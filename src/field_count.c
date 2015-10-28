int field_count(const char *str) {
	int count = 0;
	
	while(str[i] != "/0") {
		if(*str == ",") { //add one for every comma
		   count++;
		}
		str++; //Add on to pointer - Next charater
	}

	return count++;//Return count +1 because there's no comma after the last element
}

