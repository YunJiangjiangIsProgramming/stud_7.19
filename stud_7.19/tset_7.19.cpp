#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include "BSTree.h"

using namespace std;

void test_1()
{
    string str;

    cout << "Enter a string (up to 14 characters): ";
    getline(cin, str);


    if (str.length() >= 14)
    {
        cout << "Input is too long!" << std::endl;

    }
    else
    {
        cout << "You entered: " << str << std::endl;
    }
}
void test_tree()
{

    int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
    BSTree<int> t1;

    for (auto e : a)
    {
        t1.Insert(e);
        cout << e << " ";
    }
    cout << endl;
    t1.InOrder();
}
void test_tree2()
{
    int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
    BSTree<int> t1;

    for (auto e : a)
    {
        t1.Insert(e);
    }

    //t1.InOrder(t1.GetRoot());
    t1.InOrder();

    t1.Erase(4);
    t1.InOrder();

    t1.Erase(14);
    t1.InOrder();

    t1.Erase(3);
    t1.InOrder();

    t1.Erase(8);
    t1.InOrder();




    t1.InOrder();
}
int main() 
{
    test_tree();
    test_tree2();

    return 0;
}


