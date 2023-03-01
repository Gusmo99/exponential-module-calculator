#include <stdio.h>
#include <stdlib.h>

int euclide(int base,int module){//extended euclide to calculate a^-1(mod b)
	int q[10],r[10],n,i;
	r[0]=base;
	q[1]=module/base;
	r[1]=module%base;
	for(i=1;r[i]!=0;i++){
		q[i+1]=r[i-1]/r[i];
		r[i+1]=r[i-1]%r[i];
	}
	n=i;
	int x[10];
	x[0]=0;
	x[1]=1;
	for(i=2;i<=n;i++){
		x[i]=-(q[i-1]*x[i-1])+x[i-2];
	}
	if(x[n]<0){
		x[n]=x[n]+module;
	}
	return x[n];
}

int main(int argc, char *argv[]) {
	int a,b,p;
	printf("insert number: ");
	scanf("%d",&a);
	printf("insert power: ");
	scanf("%d",&p);
	printf("insert module: ");
	scanf("%d",&b);
	int temp_a;//used to adjust a in case of negative value or power
	int temp_p;//used to adjust p in case of negative power
	if(a<0){//a negative, calculate the equivalent positive
		temp_a=b+a;
		printf("%d^%d ()")
	}else{
		temp_a=a;
	}
	if(p<0){//negative power, calculate a^-1 (mod b)
		temp_a=euclide(temp_a,b);
		temp_p=-p;
	}else{
		temp_a=temp_a;
		temp_p=p;
	}
	unsigned long long int temp=pow(temp_a,temp_p);//calculate directly the exponential
	int remainder;
	if((int) temp==0){//if the exponential it's not possible to be calculated direclty (result 0)
		remainder=temp_a;
		int i;
		for(i=1;i<p;i++){//execute p time moltiplication with a
			remainder=(remainder*temp_a)%b;
		}
    }else{//exponential not to high, calculated direclty the remainder
	    remainder=temp%b;
	}
	printf("%d^%d=%d (mod %d)",a,p,remainder,b);//print with the original values
	return 0;
}
