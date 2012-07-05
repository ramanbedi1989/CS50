#include<stdio.h>
void main(void)
	{
		
		int mf,fm,ff,mm;
		printf("M Spotting F :");
		scanf("%d",&mf);
		printf("F Spotting M :");
		scanf("%d",&fm);
		printf("F Spotting F :");
		scanf("%d",&ff);
		printf("M Spotting M :");
		scanf("%d",&mm);
		
		int total=mf+fm+ff+mm;
			double aa=(mf*80)/total;
			double bb=(fm*80)/total;
			double cc=(ff*80)/total;
			double dd=(mm*80)/total;
			int index;
			printf("M Spotting F :\n");
			for(index=0;index<(int)aa;index++)
			{
				printf("#");
			}
			printf("\nF Spotting M :\n");
			for(index=0;index<(int)bb;index++)
			{
				printf("#");
			}
			printf("\nF Spotting F :\n");
			for(index=0;index<(int)cc;index++)
			{
				printf("#");
			}
			printf("\nM Spotting M :\n");
			for(index=0;index<(int)dd;index++)
			{
				printf("#");
			}printf("\n");
		
	}