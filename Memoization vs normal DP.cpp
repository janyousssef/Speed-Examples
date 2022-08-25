#include <iostream>
#include<cmath>
#include<map>
#include<windows.h>
#include <algorithm>
using namespace std;
#define ll long long


//map to store values already computed once so we don't compute them again
map<pair<ll,ll>,ll> mp;

//global vars to store number of function calls made
ll simple_calls=0,complex_calls=0;


ll dp_WithMemoization(ll last_element,ll pos, ll N,ll arr[])
{
    if(pos==N-1) return (arr[pos]>=last_element);

    //if value found in map, simply return it
    if(mp.find({pos,last_element})!=mp.end())
    {
        //simple call was made
        simple_calls++;
        return mp[ {pos,last_element}];
    }


    //otherwise compute it, store in the map, and return it
    if(arr[pos]>=last_element )
        mp[ {pos,last_element}]=max(1+dp_WithMemoization(arr[pos],pos+1,N,arr),dp_WithMemoization(last_element,pos+1,N,arr));
    else
        mp[ {pos,last_element}]=(dp_WithMemoization(last_element,pos+1,N,arr));

    //this was a complex call
    complex_calls++;

    return mp[ {pos,last_element}];

}
ll dp_NoMemoization(ll last_element,ll pos, ll N,ll arr[])
{
    if(pos==N-1) return (arr[pos]>=last_element);
    //in this function we don't make actual use of the map,
    //it is just used to hold the values (could be replaced with a temporary variable)

    //compute the value, store in the map, and return it
    if(arr[pos]>=last_element )
        mp[ {pos,last_element}]=max(1+dp_NoMemoization(arr[pos],pos+1,N,arr),dp_NoMemoization(last_element,pos+1,N,arr));
    else
        mp[ {pos,last_element}]=(dp_NoMemoization(last_element,pos+1,N,arr));

    //this was a complex call
    complex_calls++;

    return mp[ {pos,last_element}];

}
int main()

{
    cout<<"Here we have 2 functions!\nboth solving the same problem, with dynamic programming, using the same input\nBut one function uses Memoization(time saving technique), while the other doesn't."<<endl;
    //Init();
    ll arr[1000];

    ll N;
    cout<<"\nInput: ";
    cin>>N;
    for(ll i=0; i<N; i++)cin>>arr[i];

    cout<<"\nFunction 1(Memoization):\nAnswer: "<<dp_WithMemoization(INT_MIN,0,N,arr)<<endl<<
        "A total of "<<simple_calls+complex_calls<<" function calls were made, "<<simple_calls<<" of which were simple retrievals of a value stored in a Map"<<endl;

    complex_calls=0,simple_calls=0;
    cout<<"\nFunction 2(No Memoization):\nAnswer: "<<dp_NoMemoization(INT_MIN,0,N,arr)<<endl<<
        "A total of "<<simple_calls+complex_calls<<" function calls were made, "<<simple_calls<<" of which were simple retrievals of a value stored in a Map"<<endl;
    cout<<"\nSee the difference? it's huge XD"<<endl;
    complex_calls=0,simple_calls=0;

    ll Nn,arr2[1000];

    mp.clear();
    Sleep(2500);
    system("cls");
    cout<<"Let's try with a larger input!\nBig Input: ";
    cin>>Nn;
    for(ll i=0; i<Nn; i++)cin>>arr2[i];

    cout<<"\nFunction 1(Memoization):\nAnswer: "<<dp_WithMemoization(INT_MIN,0,Nn,arr2)<<endl<<
        "A total of "<<simple_calls+complex_calls<<" function calls were made, "<<simple_calls<<" of which were simple retrievals of a value stored in a Map"<<endl;

    complex_calls=0,simple_calls=0;
    cout<<"\nFunction 2(No Memoization):\nAnswer: "<<dp_NoMemoization(INT_MIN,0,Nn,arr2)<<endl<<
        "A total of "<<simple_calls+complex_calls<<" function calls were made, "<<simple_calls<<" of which were simple retrievals of a value stored in a Map"<<endl;

    return 0;

}

