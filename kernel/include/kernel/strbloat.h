char * strbloat(char * input, unsigned int length){//Code haunted, TODO: Call the Ghostbusters
	unsigned int current=strlen(input);
	if(current>length){
		return input;
	}
	char * output=(char)0;
	char * temp=(char)1;
	current=length-current;
	printf("From strbloat: ");
	unsigned int i=0, c=0;
	while(i<current){
		output[i]='0';
		i++;
	}
	temp=itoa(i, temp, 10);
	printf(temp);
	printf("\nEnd of strbloat output\n");
	while(i<length){
		output[i]=input[c];
		c++;
		i++;
	}
	output[i]='\0';
	return output;
}
