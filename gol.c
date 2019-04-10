#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int x=10,c=clock();
	int rr=0;
	char a[]=
	{
	"          "
	"          "
	"          "
	"*  *      "
	"    *     "
	"*   *     "
	" ****     "
	"          "
	"          "
	"          "
	};
	for(int i=0;i<x*x;i++)a[i]-=32;
	
	while(1)
	{
		if(clock()-c>CLOCKS_PER_SEC)
		{
			char chs[x*x];
			printf("_________\n");
			for(int i=0;i<x*x;i++)
			{
				//1.neighbors<2  die
				//2.neighbors>3  die
				//3.neighbors==3 alive
				int ix=i%x,iy=i/x;
				int ch=0;
				// fprintf(stderr,"%i,%i ",ix,iy);
				
				//count neighbors
				ch+=iy==0||ix==0?0:a[(iy-1)*x+ix-1]>0;
				ch+=ix==0?0:a[iy*x+ix-1]>0;
				ch+=iy==x-1||ix==0?0:a[(iy+1)*x+ix-1]>0;
				
				ch+=iy==0||ix==x-1?0:a[(iy-1)*x+ix+1]>0;
				ch+=ix==x-1?0:a[iy*x+ix+1]>0;
				ch+=iy==x-1||ix==x-1?0:a[(iy+1)*x+ix+1]>0;
				
				ch+=iy==0?0:a[(iy-1)*x+ix]>0;
				// ch+=1;//iy==0?0:a[(iy)*x+ix]>0;
				ch+=iy==x-1?0:a[(iy+1)*x+ix]>0;
				
				// // fprintf(stderr,"(%i)\n",ch);
				chs[i]=ch;
			}
			for(int i=0;i<x*x;i++)
			{
				if(rr&&(chs[i]>3||chs[i]<2))a[i]=0;
				if(rr&&chs[i]==3)a[i]=1;
				
				putc(a[i]?'*':32,stdout);
				// putc(a[i]?(char)chs[i]+48:(char)chs[i]+97,stdout);
				if(i%x==x-1)putc('\n',stdout);
			}
			c=clock();rr=1;
		}
	}
}