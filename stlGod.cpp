#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>
#include <map>

using namespace std;

bool compare(int x, int y)
{
    return x > y;
}

void vectDemo()
{
    //C++ STL
    vector<int> A = {11, 2, 4, 23, 1};

    cout << A[1] << endl;

    sort(A.begin(), A.end()); //O(NlogN)

    cout << "\n Sortedd element: "
         << A[0] << endl;
    // 1, 2, 4, 11, 23

    //O(logN)
    bool present = binary_search(A.begin(), A.end(), 23); // true

    cout << "\nResult after binary search1: "
         << present << endl;

    present = binary_search(A.begin(), A.end(), 6); //false

    cout << "\nResult after binary search2: "
         << present << endl;

    A.push_back(100);                                 // 1, 2, 4, 11, 23, 100
    present = binary_search(A.begin(), A.end(), 100); //true

    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(123);
    // 1, 2, 4, 11, 23, 100, 100, 100, 100, 100, 123

    //auto is like auto detect
    //here the actual type instead of auto is vector<int>::iterator
    auto it = lower_bound(A.begin(), A.end(), 100);                   // first element >= 100 O(logN)
    vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 100); // first element > 100

    cout << *it << " " << *it2 << endl;
    cout << it2 - it << endl; //5 O(1)

    sort(A.begin(), A.end(), compare);
    /*
    vector<int>::iterator it3;
    

    for (it3 = A.begin(); it3 != A.end(); it3++)
    {
        cout << *it3 << " ";
    }
    cout << endl;

    */
    // THis section can be rewritten as the second for loop
    for (int &x : A)
    {
        cout << x++ << " ";
    }
    cout << endl;

    for (int x : A)
    {
        cout << x << " ";
    }
    cout << endl;
}

void setDemo()
{
    set<int> S;
    //Insert operation is O(logN) time
    S.insert(1);
    S.insert(2);
    S.insert(-10);
    S.insert(-1);

    for (int x : S)
    {
        cout << x << " ";
    }
    cout << endl;
    //-10, -1, 1, 2

    auto it = S.find(-1);
    if (it == S.end())
    {
        cout << "Not present \n"
             << endl;
    }
    else
    {
        cout << "Present \n";
        cout << *it << endl;
    }

    auto it2 = S.lower_bound(-1); //give the first iterator to >= -1
    auto it3 = S.upper_bound(0);  //give the first iterator > 0
    auto it4 = S.upper_bound(2);  //Not present

    if (it4 == S.end())
    {
        cout << "Not present \n"
             << endl;
    }
    else
    {
        cout << "Present \n";
        cout << *it4 << endl;
    }

    //TO delete a number from existing set S.erase(1)
    //element removed in O(logN) time

    S.erase(1);
    for (int x : S)
    {
        cout << x << " ";
    }
    cout << endl;
}

void mapDemo()
{
    map<int, int> A;
    A[1] = 100;
    A[2] = -1;
    A[100034] = 1;
    A[3] = 100;

    map<char, int> cnt;
    string x = "anirudh Kulkarni";

    for (char c : x)
    {
        cnt[c]++;
    }

    cout << cnt['a'] << " " << cnt['z'] << endl;

    //Other options with maps O(logN)
    //Delete a key  A.erase(key)
    //Find a key A.find(key)
    cnt.erase('a');
    cout << cnt['a'] << endl; // 0 as at key 'a' the count value is removed
    cnt.find('i');
    cout << cnt['i'] << endl;
}

void powerOfSTL()
{
    /*add[2,3],
    add[10, 20],
    add[30, 400],
    add[401, 450]
    give the interval with say 401 */
    set<pair<int, int>> S;

    S.insert({10, 20});
    S.insert({30, 400});
    S.insert({401, 450});
    S.insert({2, 3});

    //2,3
    //10,20
    //30,400
    //401,450

    /* Comparison in case of pairs 
    say (a, b)  and (c, d)
    if (a<c) then (a,b) comes first
    if(a==c) then (b<c) then a,b comes first
    Also in both the cases a<b or a==b and similarly with c and d */

    int target = 11;
    auto it = S.upper_bound({target, INT_MAX});
    it--;

    if (it == S.begin())
    {
        cout << "No, the point is not present in the interval" << endl;
        return;
    }

    pair<int, int> current = *it;

    if (current.first <= target && target <= current.second)
    {
        cout << "Yes, it is present in interval " << current.first << " " << current.second << endl;
    }
    else
    {
        cout << "No, the point is not present in the interval" << endl;
    }
}

int main()
{

    //Call whichever function to run the respective demos
    cout << "Hello World" << endl;

    return 0;
}
