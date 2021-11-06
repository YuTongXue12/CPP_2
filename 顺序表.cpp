#include<iostream>
using namespace std;
const int Maxsize=100;
template<typename DataType>
class Seqlist
{
	public:
		Seqlist();                               //����һ���ձ�
		Seqlist(DataType a[],int n);             //��������Ϊn��˳���
		//~Seqlist();	                         //��������
		int Length();                            //�����Ա�ĳ���
		DataType Get(int i);	                 //��λ���ң����ҵ�i��Ԫ�ص�ֵ
		int Locate(DataType x);                  //��ֵ���ң�����ֵΪx��Ԫ�����
		void Insert(int i,DataType x);           //����������ڵ�i��λ�ò���ֵΪx��Ԫ��
		DataType Delete(int i);                  //ɾ��������ɾ����i��Ԫ��
		int Empty();                             //�ж����Ա��Ƿ�Ϊ��
		void Printlist();                        //������������������������Ԫ��
	private:
		DataType data[Maxsize];
		int length;
};
template<typename DataType>                      //����һ���ձ�
Seqlist<DataType>::Seqlist()
{
	Length=0;
}
template<typename DataType>                      //��������Ϊn��˳���
Seqlist<DataType>::Seqlist(DataType a[],int n)
{
	if(n>Maxsize) throw"�����Ƿ�";
	for(int i=0;i<n;i++)
		data[i]=a[i];
	length=n;
}
template<typename DataType>                      //�����Ա�ĳ���
int Seqlist<DataType>::Length()
{
	return length;
}
template<typename DataType>                      //��λ���ң����ҵ�i��Ԫ�ص�ֵ
DataType Seqlist<DataType>::Get(int i)
{
	if(i<1&&i>length) throw "����λ�÷Ƿ�";
	else return data[i-1];
}
template<typename DataType>                      //��ֵ���ң�����ֵΪx��Ԫ�����
int Seqlist<DataType>::Locate(DataType x)
{
	for(int i=0;i<length;i++)
		if(data[i]==x) return i+1;
	return 0;
}
template<typename DataType>                      //����������ڵ�i��λ�ò���ֵΪx��Ԫ��
void Seqlist<DataType>::Insert(int i,DataType x)
{
	if(length==Maxsize) throw"����";
	if(i<1||i>length+1) throw"����λ�ô���";
	for(int j=length;j>=i;j--)
		data[j]=data[j-1];
	data[i-1]=x;
	length++;
}
template<typename DataType>                     //ɾ��������ɾ����i��Ԫ��
DataType Seqlist<DataType>::Delete(int i)
{
	DataType x;
	if(length==0) throw"����";
	if(i<1||i>length) throw"ɾ��λ�ô���";
	x=data[i-1];
	for(int j=i;j<length;j++)
		data[j-1]=data[j];
	length--;
	return x;
}
template<typename DataType>                      //�ж����Ա��Ƿ�Ϊ��
int Seqlist<DataType>::Empty()
{
	if(length==0)return 1;
	else return 0;
}
template<typename DataType>                      //������������������������Ԫ��
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
	cout<<"��ǰ���Ա������Ϊ:";
	L.Printlist();
	try
	{
		L.Insert(2,8);
		cout<<"ִ�в������������Ϊ:";
		L.Printlist();
	}catch(char *str) {cout<<str<<endl;}
	cout<<"��ǰ���Ա�ĳ���Ϊ:"<<L.Length()<<endl;
	cout<<"��������ҵ�Ԫ��ֵ:";
	cin>>x;
	i=L.Locate(x);
	if(0==i) cout<<"����ʧ��"<<endl;
	else cout<<"Ԫ��"<<x<<"��λ��Ϊ:"<<i<<endl;
	try
	{
		cout<<"��������ҵĵڼ���Ԫ��:";
		cin>>i;
		cout<<"��"<<i<<"��Ԫ��ֵ��:"<<L.Get(i)<<endl;
	}catch(char *str) {cout<<str<<endl;}
	try
	{
		cout<<"������Ҫɾ���ڼ���Ԫ��:";
		cin>>i;
		x=L.Delete(i);
		cout<<"ɾ����Ԫ����"<<x<<",ɾ���������Ϊ:";
		L.Printlist();
	}catch(char *str) {cout<<str<<endl;}
	return 0;
}