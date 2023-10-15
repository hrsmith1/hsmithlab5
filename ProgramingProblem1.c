#include <stdio.h>

const char* month_func(int i){
	char month[10];
	if(i == 0){
		return "January";
	}if (i == 1){
		return "Febuary";
	}if (i == 2){
		return "March";
	}if (i == 3){
		return "April";
	}if (i == 4){
		return "May";
	}if (i == 5){
		return "June";
	}if (i == 6){
		return "July";
	}if (i == 7){
		return "August";
	}if (i == 8){
		return "September";
	}if (i == 9){
		return "October";
	}if (i == 10){
		return "November";
	}if (i == 11){
		return "December";
	}
	return "Nothing";
	}
int printing(float sales[]){
		for(int i = 0; i<12; i++){
			printf("%s $%f\n", month_func(i), sales[i]);
		}
		return 0;}
int sales_summery (float sales[]){
	float min = sales[0];
	int min_num = 0;
	float max = 0;
	int max_num;
	float sum = 0;
	float avg;
	for (int i = 0; i<12; i++){
		if (sales[i] < min){
			min = sales[i];
			min_num = i;
		}
		if (sales[i] > max){
			max = sales[i];
			max_num = i;
		}
		sum += sales[i];
	}
	avg = sum/12;
	printf("Sales summary:\n");
	printf("Minimum sales: $%f (%s)\n", min, month_func(min_num));
	printf("Maximum sales: $%f (%s)\n", max, month_func(max_num));
	printf("Average Sales: $%f\n", avg);
	return 0;
}
float averages(float sales[], int month){
	float sum = 0;
	float avg;
	for(int i = month; i<month+6; i++){
		sum+=sales[i];
	}
	avg = sum/6;
	return avg;
}
int printing_averages(float sales[]){
	printf("Six Month Moving average Report\n");
	printf("January - June      $%f\n", averages(sales, 0));
	printf("Febuary - July      $%f\n", averages(sales, 1));
	printf("March   - August    $%f\n", averages(sales, 2));
	printf("April   - September $%f\n", averages(sales, 3));
	printf("June    - October   $%f\n", averages(sales, 4));
	printf("July    - November  $%f\n", averages(sales, 5));
	return 0;
}
int sort(float sales[]){
	int index = 0;
	while (index<12)
	{
		float max = 0;
		int max_num = 0;
		for(int i=0; i<12; i++){
			if (sales[i] > max){
				max = sales[i];
				max_num = i;
			}	
		}
		printf("%s, $%f\n", month_func(max_num), max);
		sales[max_num] = 0;
		index++;
	}
	return 0;
}

int main(){
	char filename[20];
	FILE* fptr;
	float sales_list[12];
	float* sales = sales_list;
	int index = 0;
	printf("What is the name of your input file:");
	scanf("%s", filename);
	fptr = fopen(filename, "r");
        if (fptr == NULL){
                printf("Your file was not found.");
                return 1;}
        else{
        	while (!feof(fptr)){
			fscanf(fptr, "%f", &sales[index]);
			index ++;
				}}
		printf("Monthly sales report for 2023:\n");
		printing(sales);
		sales_summery(sales);
		printing_averages(sales);
		sort(sales);

	return 0;}
