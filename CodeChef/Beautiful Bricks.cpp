#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #define gc getchar
    #define pc putchar
#else
    #define gc getchar_unlocked
    #define pc putchar_unlocked
#endif

using namespace std;

#define vi vector<int>
#define si set<int>
#define vs vector<string>
#define pii pair<int,int>
#define vpi vector<pii>
#define pri priority_queue<int>
#define rev_pri priority_queue<int,vector<int>,greater<int> >
#define mpi map<int,int>
#define i64 long long int
#define endl '\n'
#define pi acos(-1)
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf INT_MAX/2
#define infll LLONG_MAX/3
#define For(i,n) for(int i=0;i<n;i++)
#define Fre(i,a,b) for(int i = a; i < b; i++)
#define sf(n) scanf("%d", &n)
#define sff(a,b) scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pfn(n) printf("%d\n", n)
#define pfs(n) printf("%d ", n)
#define eps 1e-8
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define READ freopen("in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)
#define sz size()
#define dbg(i) printf("yo %d\n", i)
#define foreach(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d: ",a)

//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};


//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}

//inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}

//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}

i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}

i64 modinverse(i64 num){return bigmod(num,mod-2)%mod;}

//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}

//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}


// bit manipulations

//bool checkbit(int mask,int bit){return mask & (1<<bit);}

//int setbit(int mask,int bit){ return mask  (1<<bit) ; }

//int clearbit(int mask,int bit){return mask & ~(1<<bit);}

//int togglebit(int mask,int bit){return mask ^ (1<<bit);}



i64 dp[3003][3003][4];

i64 f(int n,int k,int mask)
{
        if(k<0)
                return 0;
        if(!n)
        {

                if(!k)
                        return 1;
                return 0;
        }

        if(dp[n][k][mask]!=-1)
                return dp[n][k][mask];


        i64 ans = f(n-1,k,0);

        if(mask!=1)
                ans += f(n-1,k-1,1);

        if(mask!=2)
                ans += f(n-1,k-1,2);

        return dp[n][k][mask] = ans % mod;

}



i64 val[25];



i64 ff(int n,int k)
{
        i64 ans = 0;
        if( n < 3000)
                return f(n,k,0);

        Fre(i,k,2*k+5)
        {
                i64 tem = 1;
                Fre(j,k,2*k+5)
                        if(i!=j)
                        {

                                tem *= (n - j);
                                tem %= mod;
                                tem += mod;
                                tem %= mod;
                                tem *= modinverse(i - j + mod);
                                tem %= mod;
                        }
                assert(f(i,k,0)<mod);
                assert(tem>0 && tem<mod);
                ans += f(i,k,0) * tem;
//                cout << i << " " << f(i,k,0) << endl;
                ans %= mod;
        }

        return ans;
}

int main()
{
        int n,k;
//
//        while(cin >> n >> k)
//                cout << f(n,k,0) << endl;


        mem(dp,-1);

        int t;
        sf(t);
        while(t--)
        {
                sff(n,k);
//                cout << f(n,k,0) << endl;
                cout << ff(n,k) << endl;
        }


//        Fre(i,1,6)
//        {
//
//
//                Fre(j,1,10)
//                        printf("%5lld " , f(j,i,0) );
//                cout << endl;
//        }





        return 0;
}


