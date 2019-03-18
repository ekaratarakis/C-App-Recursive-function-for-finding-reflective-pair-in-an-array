#include <stdio.h>
#include <stdlib.h>

// declaration of recursive function for finding all the reflective pairs
int find_Reflective_Pair(int array[],int x,int numberOfElements);

////////////////////////////////////////
//////// MAIN OF THE PROGRAMM //////////
////////////////////////////////////////

int main()
{
    system("PAUSE");
    char choice='y';
    do // "do while" for iterative use of this app
    {
	    // the program asks from the user to enter the number of elements in the array
    	    int numberOfElements,number,i;    
    	    printf("Please, give me a number of inputs that you want: ");
    	    scanf("%d",&numberOfElements); // reading the user's choice
	
	    // dynamic memory allocation using malloc function
    	    int *matrix = malloc(numberOfElements*sizeof(int));
    
    	    // the user will be asked to enter the numbers he wants
    	    printf("\nPlease start entering %d numbers:\n",numberOfElements);
    
	    for(i=0;i<numberOfElements;i++) // inserting the elements that the user enters to the array
	    {
		    printf("\nPlease enter input number %d:",i+1);
	    	    scanf("%d",&number);    	
	    	    matrix[i]=number;
	    }
	
	    /********************************/
	    /*******PRINTING THE ARRAY*******/
	    /********************************/
	
	    printf("\nThe following list includes the integers that you entered\n[");
	    for(i=0;i<numberOfElements;i++)
	    {
		    if(i!=(numberOfElements-1))
		    {
			    printf("%d ",matrix[i]);
		    }
		    else
		    {
			    printf("%d",matrix[i]);
		    }
            }
	    printf("]\n");
	    system("\nPAUSE");
	
	    /***********************************************
	    CALLING RECURSIVE FUNCTION INSIDE MAIN & 
	    PRINTING THE 1ST ELEMENT OF THE REFLECTIVE 
	    PAIR
	    ************************************************/
		
	    printf("\nPosition of first element of reflective pair with ideal sum is = %d\n",find_Reflective_Pair(matrix,0,numberOfElements)); 
	    system("\nPAUSE");
	    printf("\nDo you want to re-run the program?\nPress y/Y for yes, or anything else to terminate.\n"); // asking the user for relaunching the program
	    choice=getch(); // reading the user's answer
	    if (choice=='y' || choice=='Y')
	    {
	        free(matrix); // free allocated memory 
	    	system("cls");
	    }
	}while (choice=='Y' || choice=='y');
	return 0;   	
}
/////////////////////////////
////////END OF MAIN//////////
/////////////////////////////

int find_Reflective_Pair(int array[],int x,int numberOfElements) // recursive function find_Reflective_Pair
{
	int a = (numberOfElements/2);
	if(x <= a)
	{
		/*************************************************************
		CHECKING IF THE NUMBERS IN SYMMETRIC POSITIONS HAVE SUM EQUAL 
		TO THE 1ST ELEMENT OF THE ARRAY :)
		**************************************************************/
		if((array[x]+array[numberOfElements-x-1])==array[0])
		{ // Case 1 : Reflective pair found
			printf("A reflective pair was found with values %d and %d\n",array[x],array[numberOfElements-x-1]);
			return x;
		}
		else
		{ // Case 2 : Reflective pair didn't found
            return find_Reflective_Pair(array,x+1,numberOfElements);
		}
	}
	else
	{     // Case 3 : There was no reflective pair in the array
            printf("No ideal reflective pair was found. Sorry!!!\n");
	     	return -1;	
	}
} /////END OF find_Reflective_Pair/////	
