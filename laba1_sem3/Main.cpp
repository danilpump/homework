#include "Tbitfield.h"
#include "tset.h"

int main()
{
	printf("\nobj1(12):\n");
	TSet obj1(12);
	obj1.print_array();

	printf("\nobj2(14):");
	TSet obj2(14);
	obj2.print_array();

	printf("\nobj3 = obj2 * obj1:");
	TSet obj3 = obj2 * obj1;
	obj3.print_array();

	printf("\nobj3 = obj2 + obj1:");
	obj3 = obj2 + obj1;
	obj3.print_array();

	printf("\nobj3 = ~obj3:");
	obj3 = ~obj3;
	obj3.print_array();

	//printf("\nobj3 == obj2:");
	//if (obj3 == obj2) printf("true\n");
	//else printf("false\n");

	//printf("\nobj3 == obj1:");
	//if (obj3 == obj1) printf("true\n");
	//else printf("false\n");
	
	return 0;
}
