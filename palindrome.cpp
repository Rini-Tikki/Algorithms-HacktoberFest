#include<iostream.h>
void main()
{


int n;
cin>>n;
int p=n;
int d,rev;
while(n>0)
      {
      d=n%10;
            n=n/10;
            rev=rev*10+d;

      }
if(rev==p)
cout<<"palindrome";
else
    cout<<"not one";
