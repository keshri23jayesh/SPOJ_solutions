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
#define fo_d(i,Q) for(int i=Q;i>=0;i--)
#define fo1(j,N) for(int j=1;j<=N;j++)
#define fo2(no1,no2) for(int j=no1;j<=no2;j++)

typedef long long int ll;
typedef vector<int> vec;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef set<int> s;


vector<int> multiply(vec store, int no) {
    
    ll N = store.size(),i,temp=0,x;
    vec returnvec;
    
    fo(i,N){
        x = store[i]*no + temp;
        returnvec.push_back(x%10);
        temp = x/10;
    }
    while(temp!=0){
        returnvec.push_back(temp%10);
        temp /= 10;
    }
    return returnvec;
}



int main() {
    ll i=0, T, N, copy_n, val, new_mul;
    cin>>T;
    while(T--) {
        cin>>N;
        copy_n = N;
        vec number;
        if(N <= 2)
        cout<<copy_n<<endl;
        else{
            copy_n = N;
            while(N>0) {
            val = N%10;
            number.push_back(val);
            N = N/10;
            }
            for(i=2;i<=copy_n-1;i++)
            number = multiply(number,i);   
            fo(i,number.size())cout<<number[number.size()-i-1];
            cout<<endl;
        }
    }
	return 0;
}
