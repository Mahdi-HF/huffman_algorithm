//  be name khoda
//
//  huffman:
//  Created by mahdi.hf on 5/22/19.
//  Copyright © 2019 mahdi. All rights reserved.

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

typedef long long ll;
#define MAX_TREE_HT 100
#define bufSize 500
#define fori(i,n) for(int i = 0; i < n; i++)

ofstream oufile;

char data[bufSize];
char dataH[bufSize];
char arr[bufSize];
int freq[bufSize];

void showArr(int* arr,int len)
{
//    cout << name << " : " ;
    fori(i, len) { cout << arr[i] << " "; }
    cout << endl ;
}
//void showInt(string name,int integer) { cout << name << " : " << integer << endl; }

struct MinHeapNode
{
    char character;
    int freq;
    MinHeapNode *left, *right;
};

struct MinHeap
{
    int size;
    int capacity;
    MinHeapNode** array;
};

MinHeapNode* newNode(char character, int freq)
{
    MinHeapNode* temp = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    
    temp->left = temp->right = NULL;
    temp->character = character;
    temp->freq = freq;
    
    return temp;
}

MinHeap* createMinHeap(int capacity)
{
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    
    minHeap->size = 0;
    minHeap->capacity = capacity;
    
    minHeap->array = (MinHeapNode**)malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b)
{
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap* minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    
    if (left < minHeap->size and minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    
    if (right < minHeap->size and minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    
    if (smallest != idx)
    {
        swapMinHeapNode(&minHeap->array[smallest],&minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(MinHeap* minHeap) {return (minHeap->size == 1);}

MinHeapNode* extractMin(MinHeap* minHeap)
{
    MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    
    --minHeap->size;
    minHeapify(minHeap, 0);
    
    return temp;
}

void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(MinHeap* minHeap)
{
    int n = minHeap->size - 1;
    int i;
    
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

int isLeaf(MinHeapNode* root) { return !(root->left) and !(root->right); }

MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)
{
    MinHeap* minHeap = createMinHeap(size);
    
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    
    minHeap->size = size;
    buildMinHeap(minHeap);
    
    return minHeap;
}

MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)
{
    MinHeapNode *left, *right, *top;

    MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        
        top = newNode('$', left->freq + right->freq);
        
        top->left = left;
        top->right = right;
        
        insertMinHeap(minHeap, top);
    }
    
    return extractMin(minHeap);
}

void printCodes(MinHeapNode* root, int arr2[], int top)
{
    if (root->left) {
        arr2[top] = 0;
        printCodes(root->left, arr2, top + 1);
    }
    
    if (root->right) {
        arr2[top] = 1;
        printCodes(root->right, arr2, top + 1);
    }

    if (isLeaf(root)) {
//        cout<< root->character <<": ";
//        showArr(arr2, top);
        oufile << root->character;
        oufile << '\t';
        oufile <<  top;
        oufile <<  '\t';
        fori(ii, top)
        {
            oufile << arr2[ii];
        }
        oufile <<  '\n';
    }
}

void HuffmanCodes(char data[], int freq[], int size)
{
    MinHeapNode* root = buildHuffmanTree(data, freq, size);
    
    int arr2[MAX_TREE_HT], top = 0;
    
    printCodes(root, arr2, top);
}


int main(){
    // open a file in read mode.
    ifstream infile;
    infile.open("/Users/mahdi/Documents/Files/DS/huffman/Input.txt",ios::in);
    
    // check whether the file has opended or not.
    if (infile.is_open()) cout << "Reading from the file" << endl;
    else cout << "Unable to open the file" <<endl;

    int i=0; // size of data
    while (infile.eof() != 1)
    {
        data[i++] = infile.get();
    }
    data[i - 1] = '\0';
    
//    cout << "file data are : " << data << endl;
    
    // close the opened file.
    infile.close();
    
    
    // open a file in read mode.
    oufile.open("/Users/mahdi/Documents/Files/DS/huffman/Huffman.txt",ios::out);
    
    // check whether the file has been created or not.
    if (oufile.is_open()) cout << "writing to the file2" << endl;
    else cout << "Unable to write to the file2" <<endl;
    
    oufile << dataH ;
    
    int j = 0; // size of arr & freq
    fori(m, i)
    {
        char* p = find(arr, arr+j, data[m]);
        if (p != (arr+j) and (*p)!=arr[j] ) //Element found
        {
            int ind = (int)(p - arr);
//            cout<<"ind:"<<ind<<' ';
            freq[ind] = freq[ind]+1;
        }
        else //Element not found
        {
            arr[j] = data[m];
            freq[j] = 1;
            j++;
        }
    }
    
    
//    cout<<endl;
//    fori(iii, j)
//    {
//        cout<<arr[iii]<<' ';
//        cout<<freq[iii]<<' ';
//        cout<<endl;
//    }
    
    int size = j-1;
    HuffmanCodes(arr, freq, size);
    
    
    // open a file in read mode.
    ofstream ofile;
    ofile.open("/Users/mahdi/Documents/Files/DS/huffman/Zip.txt",ios::out);

    // check whether the file has been created or not.
    if (ofile.is_open()) cout << "writing to the file" << endl;
    else cout << "Unable to write to the file" <<endl;

    ofile << data ;
    
     
     // write the data at the screen.
//     cout << "editted file data are : " << data << endl;
    
     // close the opened file.
     infile.close();
    
    cout << "---------------------------------------" << endl << "** Bye **" << endl;
    return 0 ;
}
