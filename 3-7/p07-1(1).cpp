#include<iostream>
using namespace std;

class Car
{
	private:
		int gasolinGauge;
	public:
		Car(int gasolin): gasolinGauge(gasolin)
		{}
		int GetGasGauge()
		{
			return gasolinGauge;
		}
};

class HybridCar : public Car
{
	private:
		int electricGauge;
	public:
		HybridCar(int gasolin, int electric): Car(gasolin), electricGauge(electric)
		{}
		int GetElecGauge()
		{
			return electricGauge;
		}
};

class HybridWaterCar : public HybridCar
{
	private:
		int waterGauge;
	public:
		HybridWaterCar(int gasolin, int electric, int water): HybridCar(gasolin, electric), 
		waterGauge(water){}
		void ShowCurrentGauge()
		{
			cout<<"ÀÜ¿© °¡¼Ö¸°: "<<GetGasGauge()<<endl;
			cout<<"ÀÜ¿© Àü±â·®: "<<GetElecGauge()<<endl;
			cout<<"ÀÜ¿© ¿öÅÍ·®: "<<waterGauge<<endl;
		}
};

int main()
{
	HybridWaterCar car1(3,4,5);
	car1.ShowCurrentGauge();
}
