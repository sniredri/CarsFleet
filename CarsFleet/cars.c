#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct emploee
{
	long id;
	char *name;

}emploee_t, *pemploee;

typedef struct car
{
	long Num;
	char * brand;
	pemploee emp;

}car_t, *pcar;

int print_menue(char ** menu);
char * get_string();
pcar add_car();
pemploee add_emp();
int equal_id_lic(long CarNum, long num);
void changeindex(int car_index, int emp_index, pcar car_arr[], pemploee emp_arr[]);
void print_emp(pemploee emp_arr[], int size);
void print_car(pcar car_arr[], int size);

int main() {

	int choice, i, j;
	int id, lic,size_car,size_emp;
	long lic_i, id_j;
	int counter_emp = 0, counter_car = 0;
	

	char * menu[] = {
		" ***** menu*****",
		"press 1 :add_car",
		"press 2 :add_emploee",
		"press 3 :emploee_get_car",
		"press 4 :print_all_cars",
		"press 5 :print_emploee",/*if there is emploee belong to print him*/
		"press 6 :exit",
		NULL
	};
	pcar car_arr[100] = { 0 };
	pemploee emp_arr[100] = { 0 };
	while (1) {

		choice = print_menue(menu);
		switch (choice)
		{
		case 0:
			printf("call fun 0");
			break;
		case 1:
			for (i = 0; i < sizeof(car_arr) / sizeof(car_arr[0]); i++) {
				if (!car_arr[i])break;
			}
			if (i == sizeof(car_arr) / sizeof(car_arr[0])) {
				printf("no space\n");
				break;
			}
			car_arr[i] = add_car();
			printf("success\n");
			counter_car++;
			printf("%ld\n%s\n", car_arr[i]->Num, car_arr[i]->brand);
			break;
		case 2:
			for (i = 0; i < sizeof(emp_arr) / sizeof(emp_arr[0]); i++) {
				if (!emp_arr[i])break;
			}
			if (i == sizeof(emp_arr) / sizeof(emp_arr[0])) {
				printf("no space\n");
				break;
			}
			emp_arr[i] = add_emp();
			printf("success\n");
			counter_emp++;
			printf("%ld\n%s\n", emp_arr[i]->id, emp_arr[i]->name);
			break;
		case 3:
			printf("please enter licsense number:");
			scanf("%ld", &lic_i);
			for (i = 0; i < sizeof(car_arr) / sizeof(car_arr[0]); i++)
			{
				lic = equal_id_lic(car_arr[i]->Num, lic_i);
				if (lic == 1)//find the index
				{
					break;
				}
				break;
			}
			if (lic == 0)
			{
				break;
			}
			printf("please enter emp ID:");
			scanf("%ld", &id_j);
			for (j = 0; j < sizeof(emp_arr) / sizeof(emp_arr[0]); j++)
			{
				id = equal_id_lic(emp_arr[j]->id, id_j);
				if (id == 1)
				{
					break;
				}
				break;
			}
			if (id == 0)
			{
				break;
			}
			if (id&&lic)
			{
				changeindex(i, j, car_arr, emp_arr);
				printf("id:%ld\nname:%s\nwas have car with lic:%ld\nbrand:%s\n", car_arr[i]->emp->id, car_arr[i]->emp->name, car_arr[i]->Num, car_arr[i]->brand);
				system("pause");
			}
			break;
		case 4:
				print_car(car_arr,counter_car);
			system("pause");
			break;
		case 5:
				print_emp(emp_arr,counter_emp);

			system("pause");
			break;
		case 6:
			system("cls");
			printf("see you later baby\n");
			system("pause");
			return 0;
		}
		system("cls");
	}
	
	return 0;
}
int print_menue(char ** menu) {
	int select;

	while (*menu) {
		printf("%s\n", *menu++);
	}
	do {
		scanf("%d", &select);
	} while (select == '\n');
	return select;
}
char * get_string() {
	char temp[25], *newstring;
	int len;
	flushall();
	gets(temp);
	len = strlen(temp) + 1;
	newstring = (char*)malloc(sizeof(char)*len);
	if (!newstring)exit(1);
	strcpy(newstring, temp);
	return newstring;
}
pcar add_car() {
	char ch = 'n';
	printf("\n\n");
	pcar newcarpointer = (pcar)malloc(sizeof(car_t));
	if (!newcarpointer)exit(1);
	while (ch != 'y') {
		printf("Please enter car number:");
		scanf("%d", &newcarpointer->Num);
		printf("Please enter brand:");
		newcarpointer->brand = get_string();
		newcarpointer->emp = NULL;
		printf("Are you sure? y/n");
		scanf("%c", &ch);
		if (ch != 'y')free(newcarpointer->brand);
	}
	return newcarpointer;
}
pemploee add_emp()
{
	char ch = 'n';
	printf("\n\n");
	pemploee newEmpPointer = (pemploee)malloc(sizeof(emploee_t));
	if (!newEmpPointer)exit(1);
	while (ch != 'y') {
		printf("Please enter employee ID:");
		scanf("%d", &newEmpPointer->id);
		printf("Please enter employee name:");
		newEmpPointer->name = get_string();
		printf("Are you sure? y/n");
		scanf("%c", &ch);
		if (ch != 'y')free(newEmpPointer->name);
	}
	return newEmpPointer;
}
int equal_id_lic(long CarNum, long num)
{
	if (num == CarNum)
	{
		return 1;
	}
	printf("there are no car id like you insert\n");
	return 0;
}
void changeindex(int car_index, int emp_index, pcar car_arr[], pemploee emp_arr[])
{
	pemploee temp;

	temp = car_arr[car_index]->emp;
	car_arr[car_index]->emp = emp_arr[emp_index];
	emp_arr[emp_index] = temp;
}
void print_car(pcar car_arr[],int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%s\t%ld\n", car_arr[i]->brand, car_arr[i]->Num);
	}
}
void print_emp(pemploee emp_arr[],int size)
{
	int i;
	for ( i = 0; i < size; i++)
	{
		printf("%s\t%ld\n",emp_arr[i]->name,emp_arr[i]->id);
	}
}





