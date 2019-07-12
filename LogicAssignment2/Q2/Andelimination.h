/**Method:
*
*1)Store index of line having two statements/literals joined by conjunction in variable b and subscript of ^e in variable c
*
*2)Depending upon value of c check by comparing the string in proof line and substring in line number b character by character
*
3)Also check occurrence of '^' symbol before or after the last character checked in step 2 depending upon the value of c
*
4)If all above conditions satisfy then mark the line as valid by returning 1(ie.true) and incrementing the number of valid lines
*/

int AndElimination(int z/**@param Integer representing line number currently being worked at*/,int x/**@param Integer representing index of last character in given line*/,char a[100][100]/**@param String array having proof*/){
int i=z;/**<Integer i represents line number*/
int j=x;/**<Integer j represents index of last character of <statement> part of ith line*/
int k;/**<Integer k is a loop variable*/
int b=a[i][j+5]-48;/**<Integer b stores index of line having two statements/literals joined by conjunction */
int c=a[i][j+3]-48;/**<Integer c stores the subscript of '^e' given in ith line*/
int count1=0;/**<Integer count1 is the character match variable if c=1*/
int count2=0;/**<Integer count1 is the character match variable if c=2*/
           if(c==1){
                for(k=0;k<j;k++){
                    if(a[b-1][k+1]==a[i][k])count1++;
                }
                if(a[b-1][j+1]!='^')count1=-1;
           }
    int ln=0;///<Integer ln represents the length of <statement> in ith line if c=2
    if(c==2){
            for(k=0;k<100;k++){
                if(a[b-1][k]=='/')break;
                ln++;
            }
            for(k=j-1;k>=0;k--){
                if(a[b-1][ln-2]==a[i][k])count2++;
                ln--;
            }
            if(a[b-1][ln-2]!='^')count2=-1;
    }
 if(count1==j||count2==j)return 1;
 else return 0;
}
