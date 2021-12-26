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
			cout<<"[사과 판매자]"<<endl; 
			cout<<"남은사과: "<<numOfApples<<endl;
			cout<<"판매수익: "<<myMoney<<endl;
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
			cout<<"[사과 구매자]"<<endl;
			cout<<"현재잔액: "<<myMoney<<endl;
			cout<<"보유사과: "<<numOfApples<<endl;
		}
};

int main(){
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;

	buyer.InitMembers(5000);
	
	if(!buyer.BuyApples(seller, 0)) //메세지 전달(Message Passing) 
	{
		cout<<"money는 0개 이상"<<endl; 
	}
	seller.ShowSalesResult();
	buyer.ShowBuyResult();
}
