#include <stdio.h>
#include <stdlib.h>
int size;
int capacity;
int main(){
size=5;
capacity=20;
    FILE *myFile,*outp;
    myFile = fopen("test1b.txt", "r");


 fscanf(myFile, "%d,", &size );
fscanf(myFile, "%d,", &capacity );


    //read file into array
    int output[size]={0};
    int number[size][2]={0};
    double ratio[size]={0};
    double sortRatio[size]={0};
    int i;
    int k;
    if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
    }

    for (i = 0; i < size; i++){
    	k=0;
        fscanf(myFile, "%d,", &number[i][k] );
        k=1;
        fscanf(myFile, "%d,", &number[i][k] );
    }

    for (i = 0; i < size; i++){
    	k=0;
  //      printf("Number[%d][%d] is: %d\n",i,k, number[i][k]);
        k=1;
     //     printf("Number[%d][%d] is: %d\n",i,k, number[i][k]);
    }

for(i=0;i<size;i++){
	double weight=number[i][1];
	double value=number[i][0];
	ratio[i]=value/weight;
//	ratio[i]=(double)weight/(double)value;
	printf("Ratio is %f\n",ratio[i]);
}
 
for(i=0;i<size;i++){                          //copy array from ratio to sortRatio
	sortRatio[i]=ratio[i];
}

double temp;
int j;
for(i=0; i<size;i++){
for(j=i+1;j<size;j++){
   if(sortRatio[i]<sortRatio[j]){
   	temp=sortRatio[j];
   	sortRatio[j]=sortRatio[i];
   	sortRatio[i]=temp;
}
   }		
}
 
for(i=0;i<size;i++){
//	printf("SortedRatio %d and value %f \n",i,sortRatio[i]);
}

k=0; 
int weg=0;
int totalValue=0;
for(i=0;i<size;i++){
	
	while(sortRatio[i]!=ratio[k]){
		k++;
		
	}
	ratio[k]=-1;
//printf("number[%d][1]=%d\n",k,number[k][1]);	
	if(number[k][1]+weg<=capacity){
		weg+=number[k][1];
		output[k]=1;
		totalValue+=number[k][0];
	}
	
	k=0;
}

	printf("weight %d and value %d\n",weg,totalValue);

for(i=0;i<size;i++){
//	printf("SortedRatio %d and value %d \n",i,output[i]);
}


    fclose(myFile);
    return 0;
}
