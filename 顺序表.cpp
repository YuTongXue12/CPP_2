#include<iostream>
using namespace std;
const int Maxsize=100;
template<typename DataType>
class Seqlist
{
	public:
		Seqlist();                               //建立一个空表
		Seqlist(DataType a[],int n);             //建立长度为n的顺序表
		//~Seqlist();	                         //析构函数
		int Length();                            //求线性表的长度
		DataType Get(int i);	                 //按位查找，查找第i个元素的值
		int Locate(DataType x);                  //按值查找，查找值为x的元素序号
		void Insert(int i,DataType x);           //插入操作，在第i个位置插入值为x的元素
		DataType Delete(int i);                  //删除操作，删除第i个元素
		int Empty();                             //判断线性表是否为空
		void Printlist();                        //遍历操作，按序号依次输出个元素
	private:
		DataType data[Maxsize];
		int length;
};
template<typename DataType>                      //建立一个空表
Seqlist<DataType>::Seqlist()
{
	Length=0;
}
template<typename DataType>                      //建立长度为n的顺序表
Seqlist<DataType>::Seqlist(DataType a[],int n)
{
	if(n>Maxsize) throw"参数非法";
	for(int i=0;i<n;i++)
		data[i]=a[i];
	length=n;
}
template<typename DataType>                      //求线性表的长度
int Seqlist<DataType>::Length()
{
	return length;
}
template<typename DataType>                      //按位查找，查找第i个元素的值
DataType Seqlist<DataType>::Get(int i)
{
	if(i<1&&i>length) throw "查找位置非法";
	else return data[i-1];
}
template<typename DataType>                      //按值查找，查找值为x的元素序号
int Seqlist<DataType>::Locate(DataType x)
{
	for(int i=0;i<length;i++)
		if(data[i]==x) return i+1;
	return 0;
}
template<typename DataType>                      //插入操作，在第i个位置插入值为x的元素
void Seqlist<DataType>::Insert(int i,DataType x)
{
	if(length==Maxsize) throw"上溢";
	if(i<1||i>length+1) throw"插入位置错误";
	for(int j=length;j>=i;j--)
		data[j]=data[j-1];
	data[i-1]=x;
	length++;
}
template<typename DataType>                     //删除操作，删除第i个元素
DataType Seqlist<DataType>::Delete(int i)
{
	DataType x;
	if(length==0) throw"下溢";
	if(i<1||i>length) throw"删除位置错误";
	x=data[i-1];
	for(int j=i;j<length;j++)
		data[j-1]=data[j];
	length--;
	return x;
}
template<typename DataType>                      //判断线性表是否为空
int Seqlist<DataType>::Empty()
{
	if(length==0)return 1;
	else return 0;
}
template<typename DataType>                      //遍历操作，按序号依次输出个元素
void Seqlist<DataType>::Printlist()
{
	for(int i=0;i<length;i++)
		cout<<data[i]<<"\t";
	cout<<endl;
}
int main()
{
	int r[5]={1,2,3,4,5},i,x;
	Seqlist<int>L(r,5);
	cout<<"当前线性表的数据为:";
	L.Printlist();
	try
	{
		L.Insert(2,8);
		cout<<"执行插入操作后数据为:";
		L.Printlist();
	}catch(char *str) {cout<<str<<endl;}
	cout<<"当前线性表的长度为:"<<L.Length()<<endl;
	cout<<"请输入查找的元素值:";
	cin>>x;
	i=L.Locate(x);
	if(0==i) cout<<"查找失败"<<endl;
	else cout<<"元素"<<x<<"的位置为:"<<i<<endl;
	try
	{
		cout<<"请输入查找的第几个元素:";
		cin>>i;
		cout<<"第"<<i<<"个元素值是:"<<L.Get(i)<<endl;
	}catch(char *str) {cout<<str<<endl;}
	try
	{
		cout<<"请输入要删除第几个元素:";
		cin>>i;
		x=L.Delete(i);
		cout<<"删除的元素是"<<x<<",删除后的数据为:";
		L.Printlist();
	}catch(char *str) {cout<<str<<endl;}
	return 0;
}