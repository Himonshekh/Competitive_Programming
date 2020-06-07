#include<stdio.h>
#include <math.h>
double d;
int t,cas=1;
int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%lf",&d);
		printf("Case %d: %.2lf\n",cas++,((d*2)*(d*2))-(2 * acos (0.0)*d*d) );
	}

    return 0;
}
