#include <stdio.h>
#include <stdlib.h>
#include <math.h>      // A PARTININ SON HALÝDÝR. BÝTMÝÞTÝR. 
int size;
int sizelog;
int capacity;
int main(){
size=5;

capacity=20;
    FILE *myFile,*outp;
    myFile = fopen("test1d.txt", "r");


 fscanf(myFile, "%d,", &size );
fscanf(myFile, "%d,", &capacity );

sizelog=log2(size);
printf("size : %d and sizelog : %d",size,sizelog);
    //read file into array
    int output[size]={0};
    int storeItem[size]={0};
    int number[size][2]={0};
    double ratio[size]={0};
    double copyRatio[size]={0};
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
   //     printf("Number[%d][%d] is: %d\n",i,k, number[i][k]);
        k=1;
     //     printf("Number[%d][%d] is: %d\n",i,k, number[i][k]);
    }

for(i=0;i<size;i++){
	double weight=number[i][1];
	double value=number[i][0];
	ratio[i]=value/weight;
//	ratio[i]=(double)weight/(double)value;
//	printf("Ratio is %f\n",ratio[i]);
}
 
for(i=0;i<size;i++){                          //copy array from ratio to sortRatio
	sortRatio[i]=ratio[i];
}
for(i=0;i<size;i++){                          //copy array from ratio to copyRatio
	copyRatio[i]=ratio[i];
}
double temp;
int j;
for(i=0; i<size;i++){
for(j=i+1;j<size;j++){
   if(sortRatio[i]<sortRatio[j]){                    // sort Ratio array
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
int storeItemCounter=0;
for(i=0;i<size;i++){
	
	while(sortRatio[i]!=copyRatio[k]){
		k++;
	}
	copyRatio[k]=-1;
//printf("number[%d][1]=%d\n",k,number[k][1]);	
	if(number[k][1]+weg<=capacity){
		weg+=number[k][1];
		output[k]=1;
		totalValue+=number[k][0];
		storeItem[storeItemCounter]=i;
		storeItemCounter++;
//		printf("i is %d\n",i);
	}
	
	k=0;
}

	printf("weight %d and value %d\n",weg,totalValue);
// ************************************************************************ geliþtirme yeri baþlangýcý

for(i=0;i<size;i++){                          //copy array from ratio to copyRatio ,we made some of idex -1, therefore copy paste again
	copyRatio[i]=ratio[i];
}

for(i=0;i<size;i++){
//	printf("Store item %d and value %d \n",i,storeItem[i]);
	if(storeItem[i]==0 && i!=0)
	break;
}




int holdingX=-1;
int x;
int lastValue=totalValue;
int optValue=0;
int a=1;
int kalembu=storeItemCounter-sizelog;
		printf("size log is %d\n",kalembu);

for(int x=size ;x<size ;x++){      //mod_!(kesin sonuca yakýn , sýfýrdan baþlat) , mod_2(yarýsýndan baþlar çantaya konan nesnenin , storeItemCounter/2 ) ,mod_3(quickmode,storeItemCounter-sizelog*3)                             // karar yeri              ******************
	

	for(a=0;a<size;a++){
	
		while(sortRatio[a]!=copyRatio[k]){
		k++;
		}
			copyRatio[k]=-1;
		
		if(number[k][1]+weg<=capacity){
		weg+=number[k][1];
		optValue+=number[k][0];
	//	printf("a is %d\n",a);
	}
printf("ilk fordan sonra Last value is %d \n",lastValue);
		
	if(a==storeItem[x]-1)	
		a++;
				
	k=0;	
	}                                          // ilk for bitti
//printf("ilk fordan sonra Last value is %d \n",lastValue);

	if(optValue>lastValue){
		lastValue=optValue;
		holdingX=x;
	}
		weg=0;
	k=0;
	optValue=0;

	
if(storeItem[x+1]==0){
	break;
}
for(i=0;i<size;i++){                          //copy array from ratio to copyRatio ,we made some of idex -1, therefore copy paste again
	copyRatio[i]=ratio[i];
}
	
}

	printf("Last value is %d and holdingX %d \n",lastValue,holdingX);
// ************************************************************************ geliþtirme yeri bitiþi


// Last phase , we taken chosen X


for(i=0;i<size;i++){                          //copy array from ratio to copyRatio ,we made some of idex -1, therefore copy paste again
	copyRatio[i]=ratio[i];
}

k=0; 
int lastWeg=0;
int lastTotalValue=0;
int lastStoreItemCounter=0;
for(i=0;i<size;i++){
	
	while(sortRatio[i]!=copyRatio[k]){
		k++;
	}
	copyRatio[k]=-1;
//printf("number[%d][1]=%d\n",k,number[k][1]);	
	if(number[k][1]+lastWeg<=capacity){
		lastWeg+=number[k][1];
		output[k]=1;
		lastTotalValue+=number[k][0];
		
	}
	if(i==holdingX-1)	
		i++;
	k=0;
}

	printf("Lastweight %d and Lastvalue %d\n",lastWeg,lastTotalValue);

for(i=0;i<size;i++){
//	printf("SortedRatio %d and value %d \n",i,output[i]);
}


///////////////////////////////////////OUTPUT
    
    outp=fopen("test1d.dat", "w");//printing output.txt
   	fprintf(outp,"%d\n",lastTotalValue);
	for(i=0;i<size;i++){
		fprintf(outp,"%d\n",output[i]);
	}
   
    fclose(outp);
    ////////////////////////////////////////////
    fclose(myFile);
    return 0;
}
