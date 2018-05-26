char *  itoa ( int value, char * str, int base ){
	const char table[36]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char returningr[16];//16 is the max even at binary
	int i=0;
	while(value!=0){
		if(value>=base){
			returningr[i]=table[value%base];
			value=value/base;
		}
		else{
			returningr[i]=table[value];
			value=0;
		}
		i++;
	}
	returningr[i]='\0';
	char returning[16]={'0'};
	int x=0;
	while(i>=0){
		returning[x]=returningr[i];
		i--;
		x++;
	}
	i=1;
	while(x>0){
		str[i-1]=returning[i];
		i++;
		x--;
	}
	str[i-1]='\0';
	return str;
}

/*char *  itoams ( int value, int base ){//Memory-safe version modified version TODO: Make this happen
	const char table[36]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char returningr[16];//16 is the max even at binary
	int i=0;
	while(value!=0){
		if(value>=base){
			returningr[i]=table[value%base];
			value=value/base;
		}
		else{
			returningr[i]=table[value];
			value=0;
		}
		i++;
	}
	returningr[i]='\0';
	char returning[16]={'0'};
	int x=0;
	while(i>=0){
		returning[x]=returningr[i];
		i--;
		x++;
	}
	i=1;
	while(x>0){
		str[i-1]=returning[i];
		i++;
		x--;
	}
	str[i-1]='\0';
	return str;
}*/
