  void selectionsort(int size,int arr[]) 
  {
	   int smallest;
	   int tempdata;
	   int current;
	   int walk;
	   for (current = 0; current < size-1; ++current) {                   
	                                                             
	     smallest = current;  
	      for (walk = current+1; walk <= size - 1; ++walk) {                     
	                                                             
	         // compare adjacent elements and swap them if first 
	         // element is greater than second element           
	         if (arr[walk] > arr[smallest]) {                        
	            smallest = walk;                               
	         }                                       
	      }       
		  tempdata = arr[current];
		  arr[current] = arr[smallest];
		  arr[smallest] = tempdata;                            
	   }
	   
	   return;  
  }
  
 
