/*
 * @Description: 
 * @Author: you-know-who-2017
 * @Github: https://github.com/you-know-who-2017
 * @Date: 2019-12-28 00:57:26
 * @LastEditors: you-know-who-2017
 * @LastEditTime: 2019-12-28 00:57:26
 */
template < typename T , int MaxSize>
class SeqSet {
	T data [ MaxSize ];
	int length; //集合中元素的个数
	int Locate(T item); //按值查找，求集合中值为item的元素序号
	void Insert(int i, T item); //在集合第i个位置插入值为item的元素
	T Delete(int i); //删除集合的第i个元素
	public:
		SeqSet( ); //无参构造函数
		SeqSet(T a[], int n); //有参构造函数
		void PrintSeqSet(); //遍历集合，按序号依次输出各元素
		void Union(SeqSet &set); //求并集
		void Intersection(SeqSet &set); //求交集
		void Difference(SeqSet &set); //求差集
};

template <typename T , int MaxSize>
int SeqSet<T>::Locate(T item){
	for (int i=0; i<=this.length; i++)
		if(item == this.data[i])
			return i;
	return -1;
}

template <typename T, int MaxSize>
void SeqSet<T>::Insert(int i, T item){
	if (i<0 || i>this.length){
		cout << "error" << endl; 
	} else {
		for( ; i<this.length; i++) 
			this.data[i+1]=this.data[i];
		this.data[i]=item;
		this.length+=1;
	}
}

template < typename T, int MaxSize>
void SeqSet<T>::Union(SeqSet &set){
	int flag=0;
	for (int i=0; i<this.length; i++){
		if((flag=this.Locate(set.data[i]))!=-1)
			continue;
		this.Insert(this.length,set.data[i]);		
	}
}

int main(){
	int a[10],i;
	for (i=0; i<10; i++)
		cin>>a[i];
	int b[10];
	for (i=0; i<10; i++)
		cin>>b[i];
	SeqSet < int,100 > s1(a,10),s2(b,10);
	s1.Union(s2);
	s1.PrintSeqSet();
	SeqSet < int,100> s3(a,10),s4(b,10);
	
	s3.Intersection(s4);
	s3.PrintSeqSet();
	SeqSet < int,100 > s5(a,10),s6(b,10);
	s5.Difference(s6);
	s5.PrintSeqSet();
	return 0;
}