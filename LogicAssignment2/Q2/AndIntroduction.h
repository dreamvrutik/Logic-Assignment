/**Method:
*
*1)Store index of lines which lead to conclusion of And Introduction in variables b representing 1st line and variable c representing 2nd line
*
*2)Check for the presence of Strings in line number b and c in substrings of line having And Introduction proof rule separated by conjunction
*
3)Make comparison between strings and substrings character by character
*
4)Check the existence of '^' symbol between two conjuncts present in line having proof rule
*
5)If all above conditions satisfy then proof rule line holds valid then return 1(ie.true) and increment number of valid lines
*/
int AndIntroduction(int z/**@param Integer representing line number currently being worked at*/,int x/**@param Integer representing index of last character in given line*/,char a[100][100]/**@param String array having proof*/){
int i=z;/**<Integer i represents line number*/
int j=x;/**<Integer j represents index of last character of <statement> part of ith line*/
int k;/**<Integer k is a loop variable*/
    int b=a[i][j+4]-48;/**<Integer b stores the line number of first line which leads to And Introduction conclusion*/
    int c=a[i][j+6]-48;/**<Integer c stores the line number of second line which leads to And Introduction conclusion*/
    int ln1=0;/**<Integer ln1 represents length of <statement> part in line number b*/
    int ln2=0;/**<Integer ln2 represents length of <statement> part in line number c*/
    int count1=0;/**<Integer count1 is the character match variable for line number b*/
    int count2=0;/**<Integer count2 is the character match variable for line number c*/
    for(k=0;k<100;k++){
        if(a[b-1][k]=='/')break;
        ln1++;
    }

    for(k=0;k<100;k++){
        if(a[c-1][k]=='/')break;
        ln2++;
    }
    for(k=0;k<ln1;k++){
    if(a[i][k+1]==a[b-1][k])count1++;
}
if(a[i][ln1+1]!='^')count1=-1;
int temp=j;
for(k=ln2-1;k>=0;k--){
    if(a[i][temp-2]==a[c-1][k])count2++;
    temp--;
}
if(a[i][temp-2]!='^')count2=-1;
if(count1==ln1&&count2==ln2)return 1;
else return 0;
}
