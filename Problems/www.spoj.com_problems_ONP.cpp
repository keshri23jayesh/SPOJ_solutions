#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, '0', sizeof(x))
#define sortall(x) sort(all(x))
#define fo(i,Q) for(int i=0;i<Q;i++)
#define fo1(j,N) for(j=1;j<=N;j++)
#define fo2(no1,no2) for(ll j=no1;j<=no2;j++)

typedef long long int ll;
typedef string str;
typedef vector<int> vec;
typedef stack<string> stk;
typedef pair<int, int>	pi;
typedef pair<ll, ll>	pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef set<ll> s;

/*
The idea behind, take the largest no of the given problem, in this case its 1,000,000,000
the sqrt(1,000,000,000) is almost, 32,000. so what we can calulate all prime lies inside this.

now for any given range we can look at this array and check for the factors lying inside,


*/

int main()
{
    ll T;
    cin>>T;

	while(T--)
	{
        stk expression_stack;
        str expression;
        cin>>expression;
        ll len_str = expression.size();
        fo(i, len_str) {
            if(expression[i] == ")") {
                str concat = "";
                do {
                    concat += expression_stack.top();
                    expression_stack.pop();
                }
                while (expression[i] != "(");

                if(expression[i] != "(") {
                    expression_stack.pop();
                }
                expression_stack.push(concat);
                concat = "";
            } else {
                expression_stack.push(expression[i]);
            }
        }
        cout<<expression_stack.top()<<endl;
        expression_stack.pop();
	}
	return 0;
}
