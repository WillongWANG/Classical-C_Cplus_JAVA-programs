#include <stdio.h>

//ººÅµËþµÝ¹é½â·¨
#include <stdio.h>

/* function prototype */
void tower(int c, int start, int end, int temp);

int main()
{
    int n; /* number of disks */

    printf("Enter the starting number of disks: ");
    scanf_s("%d", &n);

    /* print instructions for moving ±àºÅ1~n disks from
       peg 1 to peg 3 using peg 2 for temporary storage */
    tower(n, 1, 3, 2);

    return 0; /* indicate successful termination */
} /* end main */

/* tower recursively prints instructions for moving disks
   from start peg to end peg using temp peg for temporary storage */
void tower(int c, int start, int end, int temp)
{

    /* base case */
    if (c == 1) {
        printf("%d --> %d\n", start, end);
        return;
    } /* end if */

    /* move c - 1 disks from start to temp */
    tower(c - 1, start, temp, end);

    /* move last disk from start to end    */
    printf("%d --> %d\n", start, end);

    /* move c - 1 disks from temp to end   */
    tower(c - 1, temp, end, start);
} /* end function tower */
