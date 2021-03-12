#include <stdio.h>
#include <stdlib.h>

// 2B NIN SON HALÝDÝR BU ÝLK ÖNCE BAÞTAN AÞÞA ÇANTALARI KOYAR , SONRA TERS SIRADA KOYAR. HANGÝSÝNÝN SON DEÐERÝ BÜYÜK GELÝRSE ONU BASAR.
int size;
int bagNumber;
int main(){

    FILE *myFile,*outp;
    myFile = fopen("test2e.txt", "r");


 fscanf(myFile, "%d,", &size );
fscanf(myFile, "%d,", &bagNumber );

        printf("size is :%d bagnumber is: %d\n",size,bagNumber);





int bagCapacity[bagNumber]={0};
int bagWeight[bagNumber]={0};
int doutput[bagNumber][size]={0};
int orderOutput[bagNumber][size]={0};
int ms; int is;
for(is=0;is<size;is++){
		for(ms=0; ms<bagNumber;ms++){
			doutput[ms][is]=0;
		}
}

for(is=0;is<size;is++){
		for(ms=0; ms<bagNumber;ms++){
			orderOutput[ms][is]=0;
		}
}

int b;
for(b=0; b<bagNumber;b++){
fscanf(myFile, "%d,", &bagCapacity[b]);	
printf("bagcapacity%d is : %d\n",b,bagCapacity[b]);
}	



    //read file into array
     int number[size][2]={0};
    double ratio[size]={0,0,0,0};
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
    //    printf("Number[%d][%d] is: %d\n",i,k, number[i][k]);
        k=1;
      //    printf("Number[%d][%d] is: %d\n",i,k, number[i][k]);
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
int orderValue=0;
for(i=0;i<size;i++){
	
	while(sortRatio[i]!=ratio[k]){
		k++;
	}
// printf("number[%d][1]=%d\n",k,number[k][1]);	
for(int m=0; m<bagNumber;m++){
	
	if(number[k][1]+bagWeight[m]<=bagCapacity[m]){
		bagWeight[m]+=number[k][1];
		orderValue+=number[k][0];
		orderOutput[m][k]=1;
		printf("output[%d][%d]=%d\n",m,k,orderOutput[m][k]);
		break;
	}
			
}

	k=0;
}

	printf("B part order value is %d\n",orderValue);
	
	
for(int ka=0;ka<bagNumber;ka++){            // we full zero in weþght array
		bagWeight[ka]=0;
}	
	

k=0; 
weg=0;
int dValue=0;
for(i=0;i<size;i++){
	
	while(sortRatio[i]!=ratio[k]){
		k++;
	}
// printf("number[%d][1]=%d\n",k,number[k][1]);	
for(int m=bagNumber-1 ; 0<=m;m--){
	
	if(number[k][1]+bagWeight[m]<=bagCapacity[m]){
		bagWeight[m]+=number[k][1];
		dValue+=number[k][0];
		doutput[m][k]=1;
		break;
	}
			
}

	k=0;
}

	printf("B part xxxxvalue is %d\n",dValue);
	
	
	

	
	
	
	
if(dValue>orderValue){
	
	
	
	int m;
    outp=fopen("test2d.dat", "w");//printing output.txt
   	fprintf(outp,"%d\n",dValue);
	for(i=0;i<size;i++){
		for(m=0; m<bagNumber;m++){
				fprintf(outp,"%d ",doutput[m][i]);
		}
		 fprintf(outp,"\n");
	}
	
	
	
	
	
	
	
	
	
}else{
	
	    int m;
    outp=fopen("test2e.dat", "w");//printing output.txt
   	fprintf(outp,"%d\n",orderValue);
	for(i=0;i<size;i++){
		for(m=0; m<bagNumber;m++){
				fprintf(outp,"%d ",orderOutput[m][i]);
		}
		 fprintf(outp,"\n");
	}
}



int m;
for(i=0;i<size;i++){
		for(m=0; m<bagNumber;m++){
			//	printf("output[%d][%d]=%d \n",m,i,orderOutput[m][i]);
		}
}


    fclose(myFile);  
	 fclose(outp);
    return 0;
}
