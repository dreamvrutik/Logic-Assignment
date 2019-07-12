/**Method:
*1)Store index of lines leading to conclusion of Or Introduction in variables b&c respectively based on their occurrence in proof rule line
*
*2)Check presence of Strings in line number b&c in Substrings in line having proof rule
*
*3)Check if 'V' symbol exists between two substring in line having proof rule
*
*4)If all above conditions satisfy then proof rule line holds valid then return 1(ie. true) and increment number of valid lines
*/
int OrIntroduction(int z/**@param Integer representing line number currently being worked at*/,int x/**@param Integer representing index of last character in given line*/,char a[100][100]/**@param String array having proof*/){
int i=z;/**<Integer i represents line number*/
int j=x;/**<Integer j represents index of last character of <statement> part of ith line*/
int k;/**<Integer k is a loop variable*/
int b=a[i][j+3]-48;/**<Integer b stores the subscript of 'Vi' in ith line*/
int c=a[i][j+5]-48;/**<Integer c stores the line number leading to Or Introduction conclusion*/
    int ln=0;///<Integer ln represents the length of <statement> in ith line if b=2
    int count1=0;///<Integer count1 represents character match variable for line number c
    int count2=0;///<Integer count2 represents character match variable for the <statement> part occuring after 'V'
    for(k=0;k<100;k++){
        if(a[c-1][k]=='/')break;
        ln++;
    }
    if(b==1){
        for(k=0;k<ln;k++){
            if(a[i][k+1]==a[c-1][k])count1++;
        }
        if(a[i][ln+1]!='V')count1=-1;
    }
    int ln2=j;///<Integer ln2 acts as temporary storage for the length of <statement> part in ith line
    if(b==2){
        for(k=ln-1;k>=0;k--){
            if(a[c-1][k]==a[i][ln2-2])count2++;
            ln2--;
        }
        if(a[i][ln2-2]!='V')count2=-1;
    }
    if(count1==ln||count2==ln)return 1;
    else return 0;
}
