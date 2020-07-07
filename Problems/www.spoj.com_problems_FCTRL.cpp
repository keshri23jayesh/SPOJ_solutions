#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll trailingZeroes(ll A) {
    ll ans=1,c = 0;
    ll i = 1;
    while(A/pow(5,i)!=0)
    {
        c += A/pow(5,i);
        i++;
    }
    return c;
}


int main() {
    ll T,N;
    cin>>T;
    while(T--){
        cin>>N;
        cout<<trailingZeroes(N)<<endl;
    }
	return 0;
}