/*
״̬ת�Ʒ��̵ĺ����ǣ��ȸ������г���ΪF[i,0]��1��Ԫ�أ�Ȼ��ͨ��2��1��Ԫ�ص���ֵ��
������г���ΪF[i,1]��2��Ԫ�ص���ֵ��Ȼ����ͨ��2��2��Ԫ�ص���ֵ��������г���Ϊ
F[i,2]��4��Ԫ�ص���ֵ���Դ����Ƹ������г��ȵ���ֵ��
Ȼ���ǲ�ѯ��
����������Ҫ��ѯ������Ϊ(i,j)����ô������Ҫ�ҵ��������������(��߽�ȡi���ұ߽�ȡj)����С�ݣ������ظ��������ѯ5��6��7��8��9�����ǿ��Բ�ѯ5678��6789����
��Ϊ�������ĳ���Ϊj - i + 1,�������ǿ���ȡk=log2( j - i + 1)�����У�RMQ(A, i, j)=max{F[i , k], F[ j - 2 ^ k + 1, k]}��
����˵����Ҫ������[2��8]�����ֵ��k = log2��8 - 2 + 1��= 2������max(F[2, 2]��F[8 - 2 ^ 2 + 1, 2]) = max(F[2, 2]��F[5, 2])��
*/ 
const int MAXN=1e5+5;
template<typename Tp>
struct RMQ
{
    int n;
    int len[MAXN];
    Tp mx[MAXN][21];
    Tp mi[MAXN][21];
    void build_rmq()
    {
        for(int j=1;(1<<j)<=n;j++)
            for(int i=1;i+(1<<j)-1<=n;i++)
            {
                mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
                mi[i][j]=min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
            }
    }
    int QueryMax(int L,int R)
    {
        int k=len[R-L+1];
        return max(mx[L][k],mx[R-(1<<k)+1][k]);
    }
    int QueryMin(int L,int R)
    {
        int k=len[R-L+1];
        return min(mi[L][k],mi[R-(1<<k)+1][k]);
    }
    void init(Tp *a,int sz)
    {
        n=sz;
        for(int i=1;i<=n;i++) 
            mx[i][0]=mi[i][0]=a[i];
        build_rmq();
        for(int i=0;i<=n;i++)
            len[i]=(i==0?-1:len[i>>1]+1);
    }
};
