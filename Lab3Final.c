//Camille Kulanda
//Lab 3(last one)
//B.Gupta
//4.16.2020
//Create a distance counter for vector routing->research Bellman Ford from book
#include<stdio.h>
struct node
{
    unsigned distance[20];
    unsigned distanceFrom[20];
}
nodeSelect[10];
int main()
{
	//Define Variables
	int nodeCount;
	int a;
	int b;
	int k;
	int count=0;
    int Matrix[10][10];
    
	//prompt user to enter in number of nodes, and a cost matrix 
    printf("\nEnter the number of nodes : ");
    scanf("%d",&nodeCount);
	//have user enter in matrix for node counting
	printf("\nEnter in Matrix like style, spacing each number with a space and pressing enter after each row\n");
    printf("\nEnter in cost per node hop :\n");
    for(a=0;a<nodeCount;a++)
    {
        for(b=0;b<nodeCount;b++)
        {
			//take users entered matrix and assign distances based off node length
            scanf("%d",&Matrix[a][b]);
            Matrix[a][a]=0;
            nodeSelect[a].distance[b]=Matrix[a][b];
            nodeSelect[a].distanceFrom[b]=b;
        }
    }
        do
        {
			//create the matrix's of distances based upon matrix, and entered matrix
            count=0;
            for(a=0;a<nodeCount;a++)
			{
				for(b=0;b<nodeCount;b++)
				{
					for(k=0;k<nodeCount;k++)
					{
					if(nodeSelect[a].distance[b]>Matrix[a][k]+nodeSelect[k].distance[b])
					{
                    nodeSelect[a].distance[b]=nodeSelect[a].distance[k]+nodeSelect[k].distance[b];
                    nodeSelect[a].distanceFrom[b]=k;
                    count++;
					}
        }
		}
		}
		}
		while(count!=0);
		//print out the users routing tables for each selection 1, 2, 3, 4 etc based upon number of nodes
        for(a=0;a<nodeCount;a++)
        {
            printf("\n\n Router table for %d\n",a+1);
            for(b=0;b<nodeCount;b++)
            {
                printf("\nnode %d going to %d Distance %d ",b+1,nodeSelect[a].distanceFrom[b]+1,nodeSelect[a].distance[b]);
            }
        } 
}