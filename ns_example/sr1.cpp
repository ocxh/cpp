#include"head.h"
void BestComImpl::SimpleFunc(void)
{
	std::cout<<"BestCom�� ������ �Լ�"<<std::endl;
	PrettyFunc();
	ProgComImpl::SimpleFunc();
}

void BestComImpl::PrettyFunc(void)
{
	std::cout<<"So Pretty!!"<<std::endl;
}

void ProgComImpl::SimpleFunc(void)
{
	std::cout<<"ProgCom�� ������ �Լ�"<<std::endl;
}
