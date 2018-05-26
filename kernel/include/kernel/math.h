double log2 (double x){
	asm("fld1 ; fxch ; fyl2x" : "+t"(x): :"st(1)");
	return x;
}
double floor(double x){
	asm("finit ; fxch ; fyl2x" : "+t"(x));
	return x;
}
