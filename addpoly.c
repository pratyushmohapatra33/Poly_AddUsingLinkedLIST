struct poly
{
	int cof;
	int exp;
	struct poly *link;
};
struct poly * create_poly();
struct poly * add_poly();
void traverse(struct poly *);
main()
{
	struct poly *base1,*base2,*base3;
	base1=create_poly();
		traverse(base1);
	base2=create_poly();
		traverse(base2);
	base3=add_poly(base1,base2);
		traverse(base3);

}
struct poly * add_poly(struct poly *p,struct poly *q)
{
	struct poly *a=0,*b,*temp;
	while(p!=0 && q!=0)
	{
		if(p->exp==q->exp)
		{
			if(a==0)
			{
				a=malloc(sizeof(struct poly));
				a->cof=p->cof+q->cof;
				a->exp=p->exp;
				a->link=0;
				temp=a;
			}
			else
			{
				b=malloc(sizeof(struct poly));
				a->link=b;
				a=b;
				a->cof=p->cof+q->cof;
				a->exp=p->exp;
			}
			a->link=0;
			p=p->link;
			q=q->link;
		}
		else
		if(p->exp>q->exp)
		{
			if(a==0)
			{
				 a=malloc(sizeof(struct poly));
                                a->cof=p->cof;
                                a->exp=p->exp;
                                a->link=0;
                                temp=a;
	
			}
			else
			{
				 b=malloc(sizeof(struct poly));
                                a->link=b;
                                a=b;
                                a->cof=p->cof;
                                a->exp=p->exp;
				a->link=0;
			}
			p=p->link;
		}
		else
		if(p->exp<q->exp)
		{
			if(a==0)
			{
				 a=malloc(sizeof(struct poly));
                                a->cof=q->cof;
                                a->exp=q->exp;
                                a->link=0;
                                temp=a;
			}
			else
			{
				 b=malloc(sizeof(struct poly));
                                a->link=b;
                                a=b;
                                a->cof=q->cof;
                                a->exp=q->exp;
				a->link=0;
			}
			q=q->link;
		}
	}//while
	//rest node loop
	while(p!=0)
	{
		 b=malloc(sizeof(struct poly));
                                a->link=b;
                                a=b;
                                a->cof=p->cof;
                                a->exp=p->exp;
                                a->link=0;
				p=p->link;
	}
	//rest node from q 
	while(q!=0)
	{
		 b=malloc(sizeof(struct poly));
                                a->link=b;
                                a=b;
                                a->cof=q->cof;
                                a->exp=q->exp;
                                a->link=0;
				q=q->link;	
	}
	a->link=0;
	return temp;
}	
void traverse(struct poly *p)
{
	while(p->link!=0)
	{
		printf("%dX%d + ",p->cof,p->exp);
		p=p->link;
	}
	printf("%dX%d\n",p->cof,p->exp);
}
struct poly * create_poly()
{
	struct poly *p,*q,*temp;
	char x[5];
	p=malloc(sizeof(struct poly));
	printf("Enter coefficient and exponent");
	scanf("%d%d",&p->cof,&p->exp);
	temp=p;
	while(1)
	{
		printf("Do you want to continue yes/no");
		scanf("%s",x);
		if(strcmp(x,"no")==0)
			break;
		q=malloc(sizeof(struct poly));
		p->link=q;
		p=q;
		printf("Enter coefficient and exponent:");
		scanf("%d%d",&p->cof,&p->exp);		
	}
	p->link=0;
	return temp;
}




























