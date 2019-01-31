#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define tol 1e-9
#define MAXN 100001
#define M 12
#define oo (1LL<<62)
typedef long long i64;

int m,n;
i64 V,h[M],r[M],min_so_far,R[M];

i64 min( i64 x, i64 y ) { return x<y?x:y; }

i64 SQUARE( i64 k ) {
	if ( k < 0 ) return 0;
	return (k*(k+1)*(2*k+1))/6;
}

i64 SUM( i64 k ) {
	if ( k < 0 ) return 0;
	return k*(k+1)/2;
}

i64 CUBE( i64 k ) {
	i64 x = SUM(k);
	return x*x;
}

i64 maxvol( int k ) {
	i64 hh,rr,res = 0,i;
	for ( hh = h[k-1]-1, rr = r[k-1]-1, i = k; i < m; ++i )
		res += hh*rr*rr, --hh, --rr;
	return res;
}

void rec( i64 v, i64 s, int k ) {
	i64 maxr, minr, maxh, minh;
	if ( k == m ) {
		if ( v == V && R[0]+s < min_so_far ) 
			min_so_far = R[0]+s;
		return ;
	}
	assert( k < m );

	if ( CUBE(m-k)+v > V ) return ;
	if ( 2*SQUARE(m-k)+s+R[0] >= min_so_far ) return ;

	if ( k ) {
		maxr = min(r[k-1]-1,(i64)sqrt((V-v-CUBE(m-k-1)+tol)/(m-k))+2);
		minr = m-k;
	}
	else {
		maxr = (i64)sqrt((V-v-CUBE(m-k-1)+tol)/(m-k))+2;
		minr = m-k;
	}
	if ( min_so_far < +oo )
		maxr = min(maxr,(i64)((min_so_far-1-R[0]-2*SQUARE(m-k-1)-s+tol)/(2*(m-k)))+2);
	
	for ( r[k] = maxr; r[k] >= minr && (R[k]=r[k]*r[k]); --r[k] ) {
		if ( 2*(V-v)/r[k]+s+R[0] >= min_so_far ) return ;
		maxh = k?min(h[k-1]-1,(i64)((V-v-CUBE(m-k-1)+tol)/R[k])+2):(i64)((V-v-CUBE(m-k-1)+tol)/R[k])+2;
		minh = m-k;
		if ( min_so_far < +oo )
			maxh = min(maxh,(i64)((min_so_far-1-R[0]-2*SQUARE(m-k-1)-s+tol)/(2*r[k]))+2);
		for ( h[k] = maxh; h[k] >= minh; --h[k] ) {
			if ( h[k]*R[k]+maxvol(k+1)+v < V ) break ;
			rec(v+R[k]*h[k],s+2*r[k]*h[k],k+1);
		}
	}
}

int main() {
	int i,j,k,cs = 0;
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	for ( ;2 == scanf("%lld %d",&V,&m) && printf("Case %d: ",++cs); printf("%lld\n",min_so_far<+oo?min_so_far:0LL) ) 
		min_so_far = +oo, rec(0,0,0);
	return 0;
}