#include <stdio.h>
#include <stdlib.h>
#include "xlist.h"
#include <iostream>
using namespace std;

int main(){
	try{
		XList<double> list;
		list.addHead(0.345);
		list.addHead(0.543);
		list.addTail(1.283);
		list.addTail(0.42);
		int s = list.getSize();
		double a = list.getData(2);
		list.iterHead();
		list.iterTail();
		list.delHead();
		list.iterHead();
		list.delTail();
		list.iterHead();
		list.clean();
	}
	catch(char * str){
		cout << str;
	}
}



