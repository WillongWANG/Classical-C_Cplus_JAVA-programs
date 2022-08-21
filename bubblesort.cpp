  void bubblesort(int size,int stu[]) 
  {
	   unsigned int pass;
	   unsigned int i;
	   for (pass = 1; pass < size; ++pass) {                   
	                                                             
	      // loop to control number of comparisons per pass   
	      //for (i = 0; i < size - 1; ++i) {                     
	        for (i = 0; i < size - pass; ++i) {                                                     
	         // compare adjacent elements and swap them if first 
	         // element is greater than second element           
	         if (stu[i] > stu[i + 1]) {                        
	            int hold = stu[i];                                   
	            stu[i] = stu[i + 1];                             
	            stu[i + 1] = hold;                               
	         }                                       
	      }                                   
	   }
  }
  

