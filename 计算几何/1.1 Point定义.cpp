//1.1 Point���� 
const double eps=1e-8; 
const double PI=acos(-1.0); 
int sgn(double x) 
{
	if(fabs(x)<eps)return 0;
	if(x<0)return -1;
	else return 1;
}
struct Point
{
	double x,y;
	Point(){}
	Point(double _x,double _y)
	{
		x=_x;y=_y;
	}
	Point operator - (const Point &b)const
	{
		return Point(x-b.x,y-b.y); 
	}
	double operator ^ (const Point &b)const//���
	{
		return x*b.y-y*b.x;
	}
	double operator * (const Point &b)const//���
	{
		return x*b.x+y*b.y;
	}
	void transXY(double B)//��ԭ����ת�Ƕ�B������ֵ������x,y�ı仯 
	{
		double tx=x,ty=y;
		x=tx*cos(B)-ty*sin(B);
		y=tx*sin(B)+ty*cos(B);
	}
};
