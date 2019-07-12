/**Methods:
*
*1)Store index of line having two statements/literals separated by '>' symbol in variable b and line which leads to proof rule conclusion in variable c
*
*2)Check the presence of strings in line with proof rule and line number c in substrings of line number b without including the first negation symbol in both strings
*
*3)If either or both the Substrings in line number b start with '~' then start matching the corresponding string from third expression after '~' and '(' character
*
*4)Check existence of symbol '>' between the two statements/literals on line number b
*
*5)If all above conditions satisfy then proof rule line holds valid then return 1(ie. true) and increment number of valid lines
*/
int ModusTollens(int z/**@param Integer representing line number currently being worked at*/,int x/**@param Integer representing index of last character in given line*/,char a[100][100]/**@param String array having proof*/){
int i=z;/**<Integer i represents line number*/
int j=x;/**<Integer j represents index of last character of <statement> part of ith line*/
int k;/**<Integer k is a loop variable*/
int q=0;
    int count1=0,count2=0;
    int b=a[i][j+4]-48;/**<Integer b stores index of line having two statements/literals separated by '>'*/
    int c=a[i][j+6]-48;/**<Integer c stores the line number which leads to Modus Tollens rule*/
     int ln=0;///<Integer ln stores the length of <statement> part in line number b
     int ln1=0;///<Integer ln1 stores the length of <statement part in line number c excluding '~'/'~('
    if(a[i][0]!='~'||a[c-1][0]!='~')return 0;
    for(k=0;k<100;k++){
    if(a[b-1][k]=='/')break;
    ln++;
   }
   for(k=0;k<100;k++){
    if(a[c-1][k]=='/')break;
    ln1++;
   }
   if(a[i][0]=='~'&&a[i][2]=='~'){
    for(k=1;k<j-1;k++){
        if(a[i][k]==a[b-1][k-1])count1++;
    }
    if(a[b-1][j-2]!='>')count1=-1;
   }
   else{
   for(k=1;k<j;k++){
    if(a[i][k]==a[b-1][k])count1++;
   }

   if(a[b-1][j]!='>')count1=-1;
   }
   if(a[c-1][0]=='~'&&a[c-1][2]=='~'){
    for(k=ln1-1;k>1;k--){
        if(a[b-1][ln-1]==a[c-1][k])count2++;
        ln--;
    }
    if(a[b-1][ln-1]!='>')count2=-1;
   }
   else{
   for(k=ln1-1;k>0;k--){
    if(a[b-1][ln-2]==a[c-1][k])count2++;
    ln--;
   }
   if(a[b-1][ln-2]!='>')count2=-1;
   }
   if(a[i][0]=='~'&&a[i][2]=='~'){
        if(a[c-1][0]=='~'&&a[c-1][2]=='~'){
            if(count1==j-2&&count2==ln1-2)return 1;
        }
        else{
            if(count1==j-2&&count2==ln1-1)return 1;
        }
   }
   else if(a[c-1][0]=='~'&&a[c-1][2]=='~'){
    if(a[i][0]=='~'&&a[i][2]=='~'){
     if(count1==j-2&&count2==ln1-2)return 1;
    }
    else{
       if(count1==j-1&&count2==ln1-2)return 1;
    }
   }
   else if(count1==j-1&&count2==ln1-1)return 1;
   else return 0;
}
