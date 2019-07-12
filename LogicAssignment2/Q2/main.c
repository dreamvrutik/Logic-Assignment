#include<stdio.h>
#include "Andelimination.h"
#include "AndIntroduction.h"
#include "OrIntroduction.h"
#include "ImplicationElimination.h"
#include "ModusTollens.h"
int main(){
    /// Variables:
    int n;/**<Integer n represents total no of lines*/
    int k;/**<Integer k is a loop variable*/
    int i;/**<Integer i represents current line number*/
    int val_lines=0;/**<Integer val_lines represents total number lines which hold valid*/
    int tot_lines=0;/**<Integer tot_lines represents total line other than premises*/
    int flag=0;/**<Integer flag checks the presence of any premise after a proof rule line*/
printf("Enter no. of lines:");
scanf("%d",&n);
char a[n][100];///<String array a contains the complete proof
printf("Enter %d input lines:\n",n);
for(i=0;i<n;i++){
    printf("%d)",i+1);
    scanf("%s",&a[i]);
}///<Integer j represents the last index of <statement> part of a proof rule line
/// **************************************************************************************************************************
/** Method:*/
/**>Checking each line of code
*for validity by checking if
*any line having proof rule is correct and
*checking if total lines having proof rules
*equals total number of such lines
*/
for(i=0;i<n;i++){
        int j=0;
    while(a[i][j]!='/'){
        j++;
    }
    if(a[i][j+1]=='^'&&a[i][j+2]=='e'){///>checking if given proof for a line is And Elimination
        tot_lines++;///>tot_lines represent total number of lines having any of mentioned 5 rules
        if(AndElimination(i,j,a))val_lines++;///>checking if And Elimination rule satisfies by calling AndElimination() function
    }
    if(a[i][j+1]=='^'&&a[i][j+2]=='i'){///>checking if given proof for a line is And Introduction
        tot_lines++;
        if(AndIntroduction(i,j,a))val_lines++;///>checking if And Introduction rule satisfies by calling AndIntroduction() function
    }
    if(a[i][j+1]=='>'&&a[i][j+2]=='e'){///>checking if given proof for a line is Implication Elimination
        tot_lines++;
        if(ImplicationElimination(i,j,a))val_lines++;///>checking if Implication Elimination rule satisfies by calling ImplicationElimination() function
    }
    if(a[i][j+1]=='V'&&a[i][j+2]=='i'){///>checking if given proof for a line is Or Introduction
        tot_lines++;
        if(OrIntroduction(i,j,a))val_lines++;///>checking if Or Introduction rule satisfies by calling OrIntroduction() function
    }
    if(a[i][j+1]=='M'&&a[i][j+2]=='T'){///>checking if given proof for a line is Modus Tollens
        tot_lines++;
        if(ModusTollens(i,j,a))val_lines++;///>checking if Modus Tollens rule satisfies by calling ModusTollens() function
    }
   if(tot_lines>0){
    if(a[i][j+1]=='P'||a[i][j+1]=='p') flag=1;///>Introducing flag variable to check presence of all premises before 1st proof rule
   }/**>If a premise occurs after any proof rule then assign flag variable to 1
   *which makes given proof invalid
   */
}
/**>If all occurances of proof rules hold valid and
all premise occurs before 1st proof rule
then show proof is valid
*/
if(val_lines==tot_lines&&flag==0)
    {printf("Valid Proof");}
else
    {printf("Invalid proof");
}
}
/*! \mainpage Logic Assignment 2
 *
 *
 * \section Assumptions
 *
 * 1)The allowed proof rules include And Introduction,And Elimination,Or Introduction,Implication Elimination and Modus Tollens
 *
 * 2)Each line must be of the form <statement>/<rule>/<this_part_is_filled_up_based_upon_the_rule_used>
 *
 * 3)<statement>::=p|~p|~(statement)|(<statement> ^ <statement>)|(<statement> V <statement>)|(<statement> > <statement>) and all the statements must be well parenthesized
 *
 * 4)<rule>::=^i | ^e1/2 | Vi1/2 | >e | P(premise)
 *
 * 5)'~' can be succeeded by a literal or '(' only and '~' cannot be preceded by '('
 *
 * 6)Premise cannot follow after any line having proof rule
 *
 *
 *
 * \section Inputs
 *
 * 1)First line is an integer representing total number of lines in proof
 *
 * 2)For next n lines of proof format is::=<statement>/<rule>/<this_part_is_filled_up_based_upon_the_rule_used>
 *
 * 3)The n lines of proof is stored in an array of strings named 'a' and each line of 'a' is processed separately
 *
 * 4)A valid input must not violate any of the given assumptions
 *
 *
 *
 * \section Limitations
 *
 * 1)The total number of lines mentioned in line 1 must be entered otherwise no output will be generated
 *
 * 2)The input must be well parenthesized and must not violate any of the given assumptions otherwise code will generate unexpected output
 *
 * 3)The code can only check for the given 5 rules and other formats when applied will generate unexpected output
 *
 * \section Code_Testing
 *
 * <a href="Q2testcases.html">Click here</a>
 *
 * \section Made_by
 *
 *  Sarthak Gaur  : 2017A7PS0250H
 *
 *  Vrutik Halani : 2017A7PS1732H
 *
 *  Vivek Soni    : 2017A7PS0173H
 */
