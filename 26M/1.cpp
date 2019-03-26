// Fractional Knapsack

#include<iostream>
using namespace std;

int knapsack(int W, int weights[], int benefit[], int n, float flag[])
{
    int w = 0;
    float val = 0.0;
    for(int i = n; i >= 0; i--)
    {
        if(w + weights[i] <= W)
        {
            w += weights[i];
            val += benefit[i];
            flag[i] = 1;
        }
        else
            flag[i] = 0;
    }
    return val;
}

int main()
{
    cout<<"Enter number of inputs: ";
    int n;
    cin>>n;
    int benefit[n], weights[n], W;
    float flag[n];
    cout<<"Enter Weights\n";
    for(int i = 0; i < n; i++)
        cin>>weights[i];
    cout<<"Enter Benefits\n";
    for(int i = 0; i < n; i++)
        cin>>benefit[i];
    cout<<"Enter Weight Constraint: ";
    cin>>W;
    for(int i = 0; i < 0; i++)
        flag[i] = 0; 
    cout<<"Optimum benefit is: "<<knapsack(W, weights, benefit, n, flag)<<"\n";
    for(int i = 0; i < n; i++)
        cout<<flag[i]<<"\t";
    cout<<"\n";
    return 0;
}