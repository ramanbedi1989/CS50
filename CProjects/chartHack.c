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
			double aa=(mf*20)/total;
			double bb=(fm*20)/total;
			double cc=(ff*20)/total;
			double dd=(mm*20)/total;
			int index;
			for(index=20;index>0;index--)
			{
				if(aa>=index)
				{
					printf("### ");
				}
				else
				{
					printf("    ");
				}
				if(bb>=index)
				{
					printf("### ");
				}
				else
				{
					printf("    ");
				}
				if(cc>=index)
				{
					printf("### ");
				}
				else
				{
					printf("    ");
				}
				if(dd>=index)
				{
					printf("### ");
				}
				else
				{
					printf("    ");
				}
				printf("\n");
			}
			printf("M4F F4M F4F M4M\n");
		
}