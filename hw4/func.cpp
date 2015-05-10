#include <fstream>
#include <cmath>
#include "func.h"
#include "struture.h"
#include "exampleClass.h"
double confusion(double a, double b)
{
	if(a == 0 && b == 0)
		return 99999;
	else
	{
		double tmp1 = (a / (a+b)) * (a / (a+b));
		double tmp2 = (b / (a+b)) * (b / (a+b));
		return 1 - tmp1 - tmp2;
	}
}

double totalConfusion(double a, double b, double c, double d)
{
	double tmp1 = (a+b)/ (a+b+c+d);
	double tmp2 = (c+d)/ (a+b+c+d);

	if(a==0 && b==0)
	{
		return ( 99999 + tmp2*confusion(c,d) );
	}
	else if (c==0 && d==0)
	{
		return ( tmp1*confusion(a,b) + 99999  );
	}
	else
	{
		return ( tmp1*confusion(a,b) + tmp2*confusion(c, d) );
	}
}


double calCon(int i, int j, newVec& tree)
{
	int leftYN[2]  = {0,0};  //前面為no, 後為yes
	int rightYN[2] = {0,0};  //前面為no, 後為yes

	//統計當基準為tree[j].features[i]時，左右兩邊的Y/N共多少
	for(newVec::iterator q = tree.begin(); q!=tree.end(); q++)
	{
		double = 0.000001;
		if(*q.features[i] < tree[j].features[i] || fabs(*q.features[i] - tree[j].features[i])< e  )  //左邊有多少Y/N
		{
			if(*q.result==1)
				leftYN[1]++;
			else
				leftYN[0]++;
		}
		else //右邊有多少Y/N
		{
			if(*q.result==1)
				rightYN[1]++;
			else
				rightYN[0]++;			
		}
	}

	//開始計算總共的confusion
	double total_con = totalConfusion(leftYN[0], leftYN[1], rightYN[0], rightYN[1]);
	tree[j].confusion[i] = total_con;

	return tree[j].confusion[i];
}


void make_decision(int number_of_recur, newVec & tree, ofstream & outputfile)
{
	//跑第一次，要印出function函數名字與argument
	if(number_of_recur ==1)
		outputfile << "int tree_predict(double *attr){\n";

	int i, j; //i for every example, j for every features
	int number_of_example = tree.size();

	//統計目前yes / no數量
	int number_of_yes=0, number_of_no=0;
	for(int s=0; s<number_of_example; s++)
	{
		if(tree[s].result==1)
			number_of_yes++;
		else
			number_of_no++;
	}

	//已經沒得切哩~~
	if(number_of_yes!=0 || number_of_no==0)
	{
		//indentation(number_of_recur);
		outputfile << "reture 1;\n"; 
	}
	if(number_of_yes==0 || number_of_yes!=0)
	{
		//indentation(number_of_recur);
		outputfile << "reture 0;\n";
	}

	//confusion < epsilon的狀況
	//還沒做

	//whereIsMinCon tmp;  裡面包含 index for example, index for features, double for confusion
	//tmp.confusion =1;

	//找到切哪一刀，將tree劃分為二
	for(i=0; i<maxfeatures; i++)
	{
		for(j=0; j<number_of_example; j++)
		{
			double confusion = calCon(i, j, number_of_example, tree);
			findCon(i, j, tree, tmp);  //function還沒寫
		}
	}
}