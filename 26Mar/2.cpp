// Fractional Knapsack

#include<iostream>
using namespace std;

int knapsack(int W, int weights[], int benefit[], int n)
{
    int w = 0;
    float val = 0.0;
    for(int i = 0; i < n; i++)
    {
        if(w + weights[i] <= W)
        {
            w += weights[i];
            val += benefit[i];
        }
        else
        {
            int frac = W - w;
            val += benefit[i] * ((float)frac / weights[i]);
            break;
        }
    }
    return val;
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