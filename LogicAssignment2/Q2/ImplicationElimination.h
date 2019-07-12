/**Method:
*
*1)Store index of line having two statements/literals separated by '>' symbol in variable b and line which leads to proof rule conclusion in variable c
*
*2)Check the presence of strings in line with proof rule and line number c in substrings of line number b
*
*3)Check existence of symbol '>' between the two statements/literals on line number b
*
*4)If all above conditions satisfy then proof rule line holds valid then return 1(ie. true) and increment number of valid lines
*/
int ImplicationElimination(int z/**@param Integer representing line number currently being worked at*/,int x/**@param Integer representing index of last character in given line*/,char a[100][100]/**@param String array having proof*/){
int i=z;/**<Integer i represents line number*/
int j=x;/**<Integer j represents index of last character of <statement> part of ith line*/
int k;/**<Integer k is a loop variable*/
int b=a[i][j+4]-48;/**<Integer b stores index of line having two statements/literals separated by '>'*/
int c=a[i][j+6]-48;/**<Integer c stores the line number which leads to Implication Elimination rule*/
int ln=0;///<Integer ln stores the length of <statement> part in line number b
int ln1=0;///<Integer ln1 stores the length of <statement> part in line number c
int count1=0;///<Integer count1 is the character match variable for line number c
int count2=0;///<Integer count2 is the character match variable for line number i
    for(k=0;k<100;k++){
                if(a[c-1][k]=='/')break;
                ln1++;
            }

    for(k=0;k<100;k++){
                if(a[b-1][k]=='/')break;
                ln++;
            }
            for(k=j-1;k>=0;k--){
                if(a[b-1][ln-2]==a[i][k])count2++;
                ln--;
            }
            if(a[b-1][ln-2]!='>')count2=-1;
            for(k=0;k<ln1;k++){
                if(a[b-1][k+1]==a[c-1][k])count1++;
            }
            if(a[b-1][ln1+1]!='>')count1=-1;
    if(count1==ln1&&count2==j)return 1;
    else return 0;
}
