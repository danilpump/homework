#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxsize 20

struct contacts
{
	char name[20];
	char surname[20];
	char patronymic[20];
	char phone[15];
	char email[30];
	char organization[30];
	char position[25];
	int number;
};

void swap(char *a, char *b)
{
	char tmp[30];
	strcpy(tmp, a);
	strcpy(a, b);
	strcpy(b, tmp);
}

void sort(struct contacts *a, int r)
{
	for (int i = 1; i < r; i++)
	{
		for (int j = 0; j < r - i; j++)
		{
			if (strcmp(a[j].surname, a[j + 1].surname) > 0)
			{
				swap(a[j].name, a[j + 1].name);
				swap(a[j].surname, a[j + 1].surname);
				swap(a[j].patronymic, a[j + 1].patronymic);
				swap(a[j].email, a[j + 1].email);
				swap(a[j].phone, a[j + 1].phone);
				swap(a[j].organization, a[j + 1].organization);
				swap(a[j].position, a[j + 1].position);
			}
		}
	}

	for (int i = 0, k = 1; i < r; i++, k++)
	{
		a[i].number = k;
	}
}

void print(struct contacts *a, int r)
{
	printf("  Num  Surname             Name                Phone\n");
	for (int i = 0; i < r; i++)
	{
		printf("  %-5d%-20s%-20s%-15s\n", a[i].number, a[i].surname, a[i].name, a[i].phone);
	}
}

int add(struct contacts *a, int r)
{
	if (r==maxsize)
	{
		printf("You have reached contacts limit.\n");
		return r;
	}
	printf("Enter contact details. Items marked * are requied.\n");
	printf("For the program to work correctly, you need to enter the specified number of characters without spaces\n");
	printf("Enter the name*. No more than 20 characters:\n");
	scanf("%s", &a[r].name);
	printf("Enter the surname*. No more than 20 characters:\n");
	scanf("%s", &a[r].surname);
	printf("Enter the phone*. No more than 15 characters:\n");
	scanf("%s", &a[r].phone);
	printf("Enter the patronymic. No more than 20 characters (you can skip this field by writing -):\n");
	scanf("%s", &a[r].patronymic);
	if (a[r].patronymic[0] == '-')
		strcpy(a[r].patronymic, "");
	printf("Enter the email. No more than 30 characters (you can skip this field by writing -):\n");
	scanf("%s", &a[r].email);
	if (a[r].email[0] == '-')
		strcpy(a[r].email, "");
	printf("Enter the organization. No more than 30 characters (you can skip this field by writing -):\n");
	scanf("%s", &a[r].organization);
	if (a[r].organization[0] == '-')
		strcpy(a[r].organization, "");
	printf("Enter the position. No more than 25 characters (you can skip this field by writing -):\n");
	scanf("%s", &a[r].position);
	if (a[r].position[0] == '-')
		strcpy(a[r].position, "");
	r++;
	return r;
}

void edit(struct contacts* a, int i)
{
	int sw = -1;
	do
	{
		printf("1-Name:          %s\n", a[i].name);
		printf("2-Surname:       %s\n", a[i].surname);
		printf("3-Phone:         %s\n", a[i].phone);
		printf("4-Patronymic:    %s\n", a[i].patronymic);
		printf("5-Email:         %s\n", a[i].email);
		printf("6-Organization:  %s\n", a[i].organization);
		printf("7-Position:      %s\n", a[i].position);
		printf("8-Finish editing\n");
		printf("What do you want to edit?\n");
		scanf("%d", &sw);
		printf("For the program to work correctly, you need to enter the specified number of characters without spaces\n");
		switch (sw)
		{
		    case 1:
			{
				printf("Enter the name*. No more than 20 characters:\n");
				scanf("%20s", &a[i].name);
				break;
			}
		    case 2:
			{
				printf("Enter the surname*. No more than 20 characters:\n");
				scanf("%20s", &a[i].surname);
				break;
			}
		    case 3:
			{
				printf("Enter the phone*. No more than 15 characters:\n");
				scanf("%15s", &a[i].phone);
				break;
			}
		    case 4:
			{
				printf("Enter the patronymic. No more than 20 characters (you can delete this field by writing -):\n");
				scanf("%20s", &a[i].patronymic);
				if (a[i].patronymic[0] == '-')
					strcpy(a[i].patronymic, "");
				break;
			}
		    case 5:
			{
				printf("Enter the email. No more than 30 characters (you can delete this field by writing -):\n");
				scanf("%30s", &a[i].email);
				if (a[i].email[0] == '-')
					strcpy(a[i].email, "");
				break;
			}
		    case 6:
			{
				printf("Enter the organization. No more than 30 characters (you can delete this field by writing -):\n");
				scanf("%30s", &a[i].organization);
				if (a[i].organization[0] == '-')
					strcpy(a[i].organization, "");
				break;
			}
		    case 7:
			{
				printf("Enter the position. No more than 25 characters (you can delete this field by writing -):\n");
				scanf("%25s", &a[i].position);
				if (a[i].position[0] == '-')
					strcpy(a[i].position, "");
				break;
			}
			default: return;
		}
	} while (1);
}

int delete(struct contacts* a, int r, int i)
{
	if (r == 0)
	{
		printf("You already deleted all contacts\n");
		return r;
	}
	strcpy(a[i].name, a[r - 1].name);
	strcpy(a[i].surname, a[r - 1].surname);
	strcpy(a[i].patronymic, a[r - 1].patronymic);
	strcpy(a[i].email, a[r - 1].email);
	strcpy(a[i].phone, a[r - 1].phone);
	strcpy(a[i].organization, a[r - 1].organization);
	strcpy(a[i].position, a[r - 1].position);
	r--;
	printf("%d\n", r);
	return r;
}

int view(struct contacts *a, int r)
{
	int tmp;
	int sw = -1;
	printf("Enter the number of contact\n");
	scanf("%d", &tmp);
	for (int i = 0; i < r; i++)
	{
		if (a[i].number == tmp)
		{
			do
			{
				printf("Name:          %s\n", a[i].name);
				printf("Surname:       %s\n", a[i].surname);
				printf("Phone:         %s\n", a[i].phone);
				printf("Patronymic:    %s\n", a[i].patronymic);
				printf("Email:         %s\n", a[i].email);
				printf("Organization:  %s\n", a[i].organization);
				printf("Position:      %s\n", a[i].position);
				printf("What do you want to do?\n1-Edit contact\n2-Delete contact\n3-Return\n");
				scanf("%d", &sw);
				switch (sw)
				{
				    case 1: edit(a, i); break;
				    case 2: r = delete(a, r, i); return r; break;
					default: return;
				}
			} while (1);
		}
	}
	return r;
}

void search_sn(struct contacts *a, int r)
{
	char tmp[20];
	printf("Enter the surname or part of it. No more than 20 characters:\n");
	scanf("%20s", &tmp);

	printf("  Num  Surname             Name                Phone\n");
	for (int i = 0; i < r; i++)
	{
		if (strstr(a[i].surname, tmp) != NULL)
			printf("  %-5d%-20s%-20s%-15s\n", a[i].number, a[i].surname, a[i].name, a[i].phone);
	}
}

void search_n(struct contacts *a, int r)
{
	char tmp[20];
	printf("Enter the name or part of it. No more than 20 characters:\n");
	scanf("%20s", &tmp);

	printf("  Num  Surname             Name                Phone\n");
	for (int i = 0; i < r; i++)
	{
		if (strstr(a[i].name, tmp) != NULL)
			printf("  %-5d%-20s%-20s%-15s\n", a[i].number, a[i].surname, a[i].name, a[i].phone);
	}
}

void search_ph(struct contacts* a, int r)
{
	char tmp[15];
	printf("Enter the phone or part of it. No more than 15 characters:\n");
	scanf("%15s", &tmp);

	printf("  Num  Surname             Name                Phone\n");
	for (int i = 0; i < r; i++)
	{
		if (strstr(a[i].phone, tmp) != NULL)
			printf("  %-5d%-20s%-20s%-15s\n", a[i].number, a[i].surname, a[i].name, a[i].phone);
	}
}

void base(struct contacts *a)
{
	strcpy(a[0].name, "Vladimir");
	strcpy(a[0].surname, "Putin");
	strcpy(a[0].patronymic, "Vladimirovich");
	strcpy(a[0].phone, "89123456789");
	strcpy(a[0].email, "putinvladim@mail.ru");
	strcpy(a[0].organization, "RusFeder");
	strcpy(a[0].position, "President");
	a[0].number = 1;

	strcpy(a[1].name, "Michail");
	strcpy(a[1].surname, "Putsepov");
	strcpy(a[1].patronymic, "");
	strcpy(a[1].phone, "89321565555");
	strcpy(a[1].email, "misha2004@mail.ru");
	strcpy(a[1].organization, "");
	strcpy(a[1].position, "");
	a[1].number = 2;

	strcpy(a[2].name, "Danil");
	strcpy(a[2].surname, "Makarov");
	strcpy(a[2].patronymic, "Andreevich");
	strcpy(a[2].phone, "89367856789");
	strcpy(a[2].email, "danilm@mail.ru");
	strcpy(a[2].organization, "");
	strcpy(a[2].position, "");
	a[2].number = 3;

	strcpy(a[3].name, "Danil");
	strcpy(a[3].surname, "Egorov");
	strcpy(a[3].patronymic, "Vladimirovich");
	strcpy(a[3].phone, "89367890789");
	strcpy(a[3].email, "tyuion@mail.ru");
	strcpy(a[3].organization, "");
	strcpy(a[3].position, "");
	a[3].number = 4;

	strcpy(a[4].name, "Artem");
	strcpy(a[4].surname, "Mavrin");
	strcpy(a[4].patronymic, "Alexeevich");
	strcpy(a[4].phone, "89007856789");
	strcpy(a[4].email, "qqqn@mail.ru");
	strcpy(a[4].organization, "");
	strcpy(a[4].position, "");
	a[4].number = 5;
}

void main()
{
	struct contacts a[maxsize];
	int sw = -1;
	int r = 5;
	base(a);
	sort(a, r);

	while (1)
	{
		printf("\nChoose what you want to do:\n1-Print all contacts\n2-Find contacts by phone number\n");
		printf("3-Find contacts by surname\n4-Find contacts by name\n5-Add contact\n");
		printf("6-View additional information for a selected contact\n7-Close the program\n");
		scanf("%d", &sw);
		switch (sw)
		{
			case 1: print(a, r); break;
			case 2: search_ph(a, r); break;
			case 3: search_sn(a, r); break;
			case 4: search_n(a, r); break;
			case 5: r = add(a, r); sort(a, r); break;
			case 6: r = view(a, r); sort(a, r); break;
			default: return;
		}
	}
}
