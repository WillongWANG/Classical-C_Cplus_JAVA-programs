#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 void bubblesort(int size,char arr[][30]) ;
 void printnmlst(char nl[][30],int row);

int main()
{
    char  namelist[20][30]={"Gilbert","Greg","Hyman",{"Ira"},{"Archer"},{"Avery"},{"Bancroft"},{"Bernie"},{"Lynn"},{"Magee"} \
	,{"Nat"},{"Bob"},{"Walsh"},{"Izze"},{"Mike"},{"April"},{"Grey"},{"Alex"},{"Hunt"},{"Bely"}};

	printnmlst(namelist,20);
	bubblesort(20,namelist);
	printf(">>>>>>>>>>>>>>>\n");
	printnmlst(namelist,20);

    return 0;
}

  void bubblesort(int size,char arr[][30])
  {
	   unsigned int pass;
	   unsigned int i;
	   char hold[30];
	   for (pass = 1; pass < size; ++pass) {
	        for (i = 0; i < size - pass; ++i) {
	         if (strcmp(arr[i],arr[i + 1])>0) {
	           strcpy(hold,arr[i]);
	            strcpy(arr[i], arr[i + 1]);
	            strcpy(arr[i + 1], hold);
	         }
	      }
	   }
  }

  void printnmlst(char nl[][30],int row)
  {
      int i;
      for(i=0;i<row;i++)
      {
         puts(nl[i]);
         //puts("\n");
      }
  }
