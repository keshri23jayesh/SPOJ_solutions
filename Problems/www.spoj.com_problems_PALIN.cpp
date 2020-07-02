#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, '0', sizeof(x))
#define sortall(x) sort(all(x))
#define fo(i,Q) for(i=0;i<Q;i++)
#define fo1(j,N) for(int j=1;j<=N;j++)
#define fo2(no1,no2) for(int j=no1;j<=no2;j++)

typedef long long int ll;
typedef vector<int> vec;
typedef pair<int, int>  pi;
typedef pair<ll, ll>    pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef set<int> s;

/* Problem can be modifed in mutiple cases.
        case-1 : when all inputs are 9.
        case-2 : when all its not pallindorem.
        case-3 : when its pallindoeme and no all 9.
*/


/* functionfor palindrome check */

bool palindrome(vector<int> digits) 
{
    bool flag = true;
    vec copy_vec = digits;
    reverse(copy_vec.begin(), copy_vec.end());
    
    int i = 0;
    int N = digits.size();
    
    fo(i, N) 
        if (copy_vec[i] != digits[i]) { 
            flag = false;
            return flag; 
        }
    return flag;
}

/* funtion for calculate next pallindrome pf pallindrome number. */
vector<int> nextpallindrome(vector<int> digits)
{
        vec copy_vec = digits;
        int N = digits.size(), check_index;
        int copy_N = digits.size();
        int i;
        if (N%2 == 0) check_index = N/2-1;
        else check_index = N/2;
        digits[check_index] += 1;
        
        for(i=check_index; i>=1; i--){
            if(digits[check_index] > 10){
               digits[check_index] = digits[check_index]%10;
               digits[check_index-1] += 1;
            } else break;
        }
        
        
        for(i=0;i<=check_index;i++)
                digits[copy_N-i-1] = digits[i];
        return digits;
}

/* funtion for calculate next pallindrome of non pallindrome number. */
vector<int> nextpallindrome_of_non_palin(vector<int> digits)
{
        vec copy_vec = digits;
        reverse(copy_vec.begin(), copy_vec.end());
        int N = copy_vec.size(), check_index, copy_N = copy_vec.size(), i;
        if (N%2 == 0) check_index = N/2-1;
        else check_index = N/2;
        bool flag = true;
        for(i=check_index; i>=0; i--){
                if(copy_vec[i] > copy_vec[N-i-1]){
                        flag = false;
                        break;
                }
        }
        if (flag == true)
                return nextpallindrome(copy_vec);
        
        else
        for(i=0;i<=check_index;i++)
                copy_vec[copy_N-i-1] = copy_vec[i];
        return copy_vec;
}



int digits_to_no(vector<int> digits){
        int ans = 0,i=0;
        fo(i,digits.size())
              ans = ans*10 + digits[i];
        return ans;
}


int main()
{
    ll T,N,copyOfN,no2,counter=0,i;
    bool check_for_9, PALIN;
    cin>>T;
        while(T--)
        {
                check_for_9 = true;
                cin>>N;
                copyOfN = N;
                int digit;
                vec digits;
                while(N!=0) {
                    digit = N%10;
                    if (digit != 9) check_for_9 = false;
                    digits.push_back(digit);
                    N = N/10;
                }
                
                
                /* handling case for 9 */
                if (copyOfN==0)
                cout<<N+1<<endl;
                else if (check_for_9)
                cout<<copyOfN+2<<endl;
                else {
                        /* all other cases */
                        
                        if (palindrome(digits))
                        {
                        cout<<digits_to_no(nextpallindrome(digits))<<endl;
                        }
                        else 
                        cout<<digits_to_no(nextpallindrome_of_non_palin(digits))<<endl;
                        
                }
        }
    return 0;
}
