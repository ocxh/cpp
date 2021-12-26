#include<iostream>
using namespace std;

class FruitSeller
{
	private:
		int APPLE_PRICE;
		int numOfApples;
		int myMoney;
	public:
		void InitMembers(int price, int num, int money)
		{
			APPLE_PRICE = price;
			numOfApples = num;
			myMoney = money;
		}
		int SaleApples(int money)
		{
			int num = money/APPLE_PRICE;
			numOfApples -= num;
			myMoney += money;
			return num;
		}
		void ShowSalesResult() const
		{
			cout<<"[��� �Ǹ���]"<<endl; 
			cout<<"�������: "<<numOfApples<<endl;
			cout<<"�Ǹż���: "<<myMoney<<endl;
		}
};

class FruitBuyer
{
	private:
		int myMoney;
		int numOfApples;
	public:
		void InitMembers(int money)
		{
			myMoney = money;
			numOfApples = 0;
		}
		bool BuyApples(FruitSeller &seller, int money)
		{
			if(money <=0)
			{
				return false;
			}
			numOfApples += seller.SaleApples(money);;
			myMoney -= money;
			return true;
		}
		void ShowBuyResult() const
		{	
			cout<<"[��� ������]"<<endl;
			cout<<"�����ܾ�: "<<myMoney<<endl;
			cout<<"�������: "<<numOfApples<<endl;
		}
};

int main(){
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;

	buyer.InitMembers(5000);
	
	if(!buyer.BuyApples(seller, 0)) //�޼��� ����(Message Passing) 
	{
		cout<<"money�� 0�� �̻�"<<endl; 
	}
	seller.ShowSalesResult();
	buyer.ShowBuyResult();
}
