#include<iostream>
#include<ncurses.h>
using namespace std;

int main(){
    char pass[13];
    char a;
    int i;
    cout<<"Enter the password";
    while(i=0){
        a=getch();
        pass[i]=a;
        cout<<"*";
    }

}
