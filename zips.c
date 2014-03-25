#include <stdio.h>
#include <string.h>

int main()
{
    int id, price, bed, bath, area;
    char address[100];
    char zipcode[15];
    FILE *homelistings;

    homelistings = fopen("homelistings.csv", "r");
    if (homelistings == NULL)
    {
	printf("Oh no!\n");
	return 1;
    }

    while(fscanf(homelistings, "%[^,], %d, %[^,], %d, %d, %d, %d ", zipcode, &id, address, &price, &bed, &bath, &area) != EOF)
    {
	strcat(zipcode, ".txt");
        FILE *zipf = fopen(zipcode, "a");
	fprintf(zipf, "%s\n", address);
	fclose(zipf);  
    }	
    fclose(homelistings);
    return 0;
}

