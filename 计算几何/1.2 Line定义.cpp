//1.2 Line���� 
struct Line
{
	Point s,e;
	Line(){}
	Line(Point _s,Point _e)
	{
		s = _s;e = _e;
	}
	//��ֱ���ཻ�󽻵� 
	//��һ��ֵΪ0��ʾֱ���غϣ�Ϊ1��ʾƽ��, Ϊ2���ཻ 
	//ֻ�е�һ��ֵΪ2ʱ������������� 
    pair<int,Point> operator &(const Line &b)const 
    { 
        Point res=s; 
        if(sgn((s-e)^(b.s-b.e)) == 0) 
        { 
            if(sgn((s-b.e)^(b.s-b.e)) == 0) 
                return make_pair(0,res);//�غ� 
            else return make_pair(1,res);//ƽ�� 
        } 
        double t=((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e)); 
        res.x+=(e.x-s.x)*t; 
        res.y+=(e.y-s.y)*t; 
        return make_pair(2,res); 
    } 
};
