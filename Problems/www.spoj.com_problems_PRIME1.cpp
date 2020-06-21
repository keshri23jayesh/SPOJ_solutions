#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, '0', sizeof(x))
#define sortall(x) sort(all(x))
#define fo(i,Q) for(int i=3;i<Q;i+=2)
#define fo1(j,N) for(int j=1;j<=N;j++)
#define fo2(no1,no2) for(int j=no1;j<=no2;j++)

typedef long long int ll;
typedef vector<int> vec;
typedef pair<int, int>	pi;
typedef pair<ll, ll>	pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef set<int> s;

/*
The idea behind, take the largest no of the given problem, in this case its 1,000,000,000
the sqrt(1,000,000,000) is almost, 32,000. so what we can calulate all prime lies inside this.

now for any given range we can look at this array and check for the factors lying inside,


*/

int main()
{
    ll T,N,no1,no2,counter=0,i;
    cin>>T;
    vec prime;
    prime.push_back(2);

    for(int i=3;i <= 32000;i+=2) {
        bool isprime = true;
        ll cap = sqrt(i) + 1;

        vector<int>::iterator j;
        for(j = prime.begin() ; j < prime.end() ; j++) {
            if (*j >= cap) break;
            if (i% *j == 0) {
                isprime = false;
                break;
            }
        }
        if (isprime) prime.push_back(i);
    }

	while(T--)
	{
                cin>>no1>>no2;
                if (no1<2) no1=2;
                int cap = sqrt(no2) + 1;
                s notprime;
                int start;
                vector<int>::iterator k;
                for(k=prime.begin(); k != prime.end(); k++) {
                    if (*k >= cap) break;
                    if (*k >= no1) start = (*k) * 2;
                    else start = no1 + ((*k - no1 % *k) % *k);
                    for (int l=start; l<=no2; l+= *k) {
                        notprime.insert(l);
                    }
                }

                for(int it=no1; it<=no2; it++) {
                    if(notprime.count(it) == 0)
                    cout<< it << endl;
                }

	}
	return 0;
}
