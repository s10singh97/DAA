// 0-1 Knapsack

#include<iostream>
using namespace std;

int knapsack(int W, int weights[], int benefits[], int n)
{
    if(W == 0 || n == 0)
        return 0;
    if(weights[n-1] > W)
        return knapsack(W, weights, benefits, n-1);
    else
    {
        int a = benefits[n-1] + knapsack(W-weights[n-1], weights, benefits, n-1);
        int b = knapsack(W, weights, benefits, n-1);
        return (a > b)? a : b;
    }
}

int main()
{
    cout<<"Enter number of inputs: ";
    int n;
    cin>>n;
    int benefit[n], weights[n], W;
    cout<<"Enter Weights\n";
    for(int i = 0; i < n; i++)
        cin>>weights[i];
    cout<<"Enter Benefits\n";
    for(int i = 0; i < n; i++)
        cin>>benefit[i];
    cout<<"Enter Weight Constraint: ";
    cin>>W;
    cout<<"Optimum benefit is: "<<knapsack(W, weights, benefit, n)<<"\n";
    return 0;
}