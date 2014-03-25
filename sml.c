#include <stdio.h>

int main()
{
    int zip, id, price, bed, bath, area;
    char address[100];
    FILE *homelistings;
    FILE *small;
    FILE *med;
    FILE *large;

    homelistings = fopen("homelistings.csv", "r");
    if (homelistings == NULL)
    {
	printf("Oh no!\n");
	return 1;
    }

    small = fopen("small.txt", "w");
    if (small == NULL)
    {
        printf("Oh no, two!\n");
        return 2;
    }   

    med = fopen("med.txt", "w");
    if (med == NULL)
    {
        printf("Oh no, three!\n");
        return 3;
    }   

    large = fopen("large.txt", "w");
    if (large == NULL)
    {
        printf("Oh no, three!\n");
        return 3;
    }   

    while(fscanf(homelistings, "%d, %d, %[^,], %d, %d, %d, %d ", &zip, &id, address, &price, &bed, &bath, &area) != EOF)
    {
	if (area < 1000)
	{
	    fprintf(small, "%s : %d\n", address, area);	    
	}
	else if (area <=2000)
	{
            fprintf(med, "%s : %d\n", address, area);
	}
	else 
	{
            fprintf(large, "%s : %d\n", address, area);
	}
    }
    fclose(homelistings);
    fclose(small);
    fclose(med);
    fclose(large);
    return 0;
}
