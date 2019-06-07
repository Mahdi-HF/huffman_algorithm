//  be name khoda
//
//  huffman:
//  Created by mahdi.hf on 5/22/19.
//  Copyright © 2019 mahdi. All rights reserved.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef long long ll;
#define size 26
#define bufSize 100
#define fori(i,n) for(int i = 0; i < n; i++)

int count_a[size];
int count_A[size];
int spaces,enters;

char data[bufSize];

void showArr(string name,int* arr,int len)
{
    cout << name << " : " ;
    fori(i, len) { cout << arr[i] << " "; }
    cout << endl ;
}
void showInt(string name,int integer) { cout << name << " : " << integer << endl; }

int main(){
    // open a file in read mode.
    ifstream infile;
    infile.open("/Users/mahdi/Documents/Files/DS/huffman/Input.txt",ios::in);
    
    // check whether the file has opended or not.
    if (infile.is_open()) cout << "Reading from the file" << endl;
    else cout << "Unable to open the file" <<endl;

    int i=0;
    while (infile.eof() != 1)
    {
        data[i] = infile.get();
        i++;
    }
    data[i-1]='\0';
    
    // write the data at the screen.
    cout << "file data are : " << data << endl;
    
    // close the opened file.
    infile.close();
    
    
    
    
    
    
    
    
    
    
    /*
    int indices[bufSize] = {65,69,75,65,65,65,65,78,98,112,98,98,98,32,1,1,1,1,1};
    
    fori(i, bufSize)
    {
        int index = indices[i];
        if (index >= 65 and index <= 90) // A ... Z
        {
            index = index - 65;
            count_A[index] = count_A[index] + 1;
        }
        else if (index >= 97 and index <= 122) // a ... z
        {
            index = index - 97;
            count_a[index] = count_a[index] + 1;
        }
        else if (index == 32) // space
        {
            spaces++;
        }
        else if (index == 1) // enter ???
        {
            enters++;
        }
    }
     
     */
    
    // open a file in read mode.
    ofstream ofile;
    ofile.open("/Users/mahdi/Documents/Files/DS/huffman/Zip.txt",ios::out);

    // check whether the file has created or not.
    if (ofile.is_open()) cout << "writing to the file" << endl;
    else cout << "Unable to write to the file" <<endl;

    ofile << data ;
    
     
     // write the data at the screen.
//     cout << "editted file data are : " << data << endl;
    
     // close the opened file.
     infile.close();
    
    
//    showArr("count_A",count_A,size);
//    showArr("count_a",count_a,size);
//    showInt("spaces ",spaces);
//    showInt("enters ",enters);
    
    cout << "-------------------------------------------------------------" << endl << "** Bye **" << endl;
    return 0 ;
}
